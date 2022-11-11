let github_owner = "MakerbaseMoon";
let github_repo = "SpiderBot";

let github_list = [];

let github_latest_version = null;

let ota_data = {
    url: "",
    tag_name: null,
    body: null
};

function get_github_list_releases() {
    try {
        let request = new XMLHttpRequest();
        request.open("GET", `https://api.github.com/repos/${github_owner}/${github_repo}/releases`, true);
        request.setRequestHeader("Accept", "application/vnd.github+json");
        // request.setRequestHeader("Authorization", `Bearer ${token}`);
        request.send();
        request.addEventListener("load", () => {
            github_list = []
            let data = JSON.parse(request.responseText);
            try {
                for(let i = 0; i < data.length; i++) {
                    let _data = {
                        tag_name: data[i].tag_name,
                        body: data[i].body
                    }
                    github_list.push(_data);

                    let _my_li = document.createElement('li');
                    let _my_a  = document.createElement('a');

                    _my_a.classList.add("dropdown-item");
                    _my_a.innerText = _data.tag_name;
                    _my_li.addEventListener('click', () => {
                        ota_data.tag_name = _data.tag_name;
                        ota_data.body = _data.body;

                        // https://github.com/MakerbaseMoon/SpiderBot/releases/download/v0.1.0/firmware.bin
                        ota_data.url = `https://github.com/${github_owner}/${github_repo}/releases/download/${ota_data.tag_name}/firmware.bin`;

                        show_ota_data();
                    });

                    _my_li.appendChild(_my_a);
                    github_list_ul.appendChild(_my_li);
                }
                console.log(github_list);
            } catch(e) { 
                console.log(e);
            }
        });
    } catch(e) {

    }
}

function get_github_latest_release() {
    try {
        let request = new XMLHttpRequest();
        request.open("GET", `https://api.github.com/repos/${github_owner}/${github_repo}/releases/latest`, true);
        request.setRequestHeader("Accept", "application/vnd.github+json");
        // request.setRequestHeader("Authorization", `Bearer ${token}`);
        request.send();
        request.addEventListener("load", () => {
            let data = JSON.parse(request.responseText);
            console.log(data);
            github_latest_version = data.tag_name;
            ota_data.tag_name = data.tag_name;
            ota_data.body = data.body;

            // https://github.com/MakerbaseMoon/SpiderBot/releases/download/v0.1.0/firmware.bin
            ota_data.url = `https://github.com/${github_owner}/${github_repo}/releases/download/${ota_data.tag_name}/firmware.bin`;

            while(!my_esp_data.isOK);
            show_ota_data();

            if(my_esp_data.version > github_latest_version) {
                upgrade.style.color = 'red';
            } else if(my_esp_data.version < github_latest_version){
                upgrade.style.color = 'purple';
            }
        });
    } catch(e) {

    }
}

function get_github_release_by_id({release_id}) {
    try {
        let request = new XMLHttpRequest();
        request.open("GET", `https://api.github.com/repos/${github_owner}/${github_repo}/releases/${{release_id}}`, true);
        request.setRequestHeader("Accept", "application/vnd.github+json");
        // request.setRequestHeader("Authorization", `Bearer ${token}`);
        request.send();
        request.addEventListener("load", () => {
            let data = JSON.parse(request.responseText);
            console.log(data);
            ota_data.tag_name   = data.tag_name;
            ota_data.body       = data.body;

            // https://github.com/MakerbaseMoon/SpiderBot/releases/download/v0.1.0/firmware.bin
            ota_data.url = `https://github.com/${github_owner}/${github_repo}/releases/download/${ota_data.tag_name}/firmware.bin`;
            show_ota_data();
        });
    } catch(e) {

    }
}

function get_github_release_by_tag_name(tag) {
    try {
        let request = new XMLHttpRequest();
        request.open("GET", `https://api.github.com/repos/${github_owner}/${github_repo}/releases/tags/${tag}`, true);
        request.setRequestHeader("Accept", "application/vnd.github+json");
        // request.setRequestHeader("Authorization", `Bearer ${token}`);
        request.send();
        request.addEventListener("load", () => {
            let data = JSON.parse(request.responseText);
            console.log(data);
            ota_data.tag_name   = data.tag_name;
            ota_data.body       = data.body;

            // https://github.com/MakerbaseMoon/SpiderBot/releases/download/v0.1.0/firmware.bin
            ota_data.url = `https://github.com/${github_owner}/${github_repo}/releases/download/${ota_data.tag_name}/firmware.bin`;
            show_ota_data();
        });
    } catch(e) {

    }
}

function icon_click() { 
    setting.addEventListener('click', ()=> { 
        if(setting_form.style.display === "none") { 
            setting_form.style.display = "block";
            upgrade_form.style.display = "none";
        } else {
            setting_form.style.display = "none";
            upgrade_form.style.display = "none";
        }
    }); 

    upgrade.addEventListener('click', ()=> { 
        if (upgrade_form.style.display === "none") {
            upgrade_form.style.display = "block";
            setting_form.style.display = "none";
        } else {
            upgrade_form.style.display = "none";
            setting_form.style.display = "none";
        }
    });
}

ota_update_btn.addEventListener('click', () => {
    if(ota_data.url != "") {
        get_github_ota(ota_data.url);
        ota_update_btn.disabled = true;
    }
});

function get_github_ota(_url) {
    try {
        let request = new XMLHttpRequest();
        request.open("POST", `${window.location.origin}/ota/update`, true);
        request.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
        request.send(`url=${_url}`);
        request.addEventListener("load", () => {
            console.log(request.responseText);
        });
    } catch(e) {

    }
}

function show_ota_data() {
    ota_update_btn.classList = [];
    ota_update_btn.classList.add("btn");

    if(my_esp_data.version != ota_data.tag_name) {
        ota_update_btn.disabled = false;
        if(my_esp_data.version > ota_data.tag_name) {
            esp_version_tag.style.color = 'purple';
            version_tag.style.color = 'orange';
            ota_update_btn.classList.add("btn-outline-warning");
            ota_update_btn.innerText = `Downgrade ${ota_data.tag_name} (更新舊版本 ${ota_data.tag_name})`;
        } else {
            esp_version_tag.style.color = 'red';
            version_tag.style.color = 'blue';
            ota_update_btn.classList.add("btn-outline-danger");
            ota_update_btn.innerText = `Update ${ota_data.tag_name} (更新版本 ${ota_data.tag_name})`;
        }
    } else {
        esp_version_tag.style.color = 'black';
        version_tag.style.color = 'gray';
        ota_update_btn.disabled = true;
        ota_update_btn.classList.add("btn-outline-secondary");
        ota_update_btn.innerText = `NO Update (相同版本)`;
    }

    version_tag.innerText  = "GitHub Version: " + ota_data.tag_name;
    version_body.innerHTML = ota_data.body;

    if(github_latest_version = ota_data.tag_name) {
        version_tag.innerText = `GitHub Version: ${ota_data.tag_name} (latest)`;
    }    
}
