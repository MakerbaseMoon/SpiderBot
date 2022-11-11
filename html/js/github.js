let github_owner = "MakerbaseMoon";
let github_repo = "SpiderBot";

let github_list = [];

let url = "";

function get_github_list_releases() {
    try {
        let request = new XMLHttpRequest();
        request.open("GET", `https://api.github.com/repos/${github_owner}/${github_repo}/releases`, true);
        request.setRequestHeader("Accept", "application/vnd.github+json");
        // request.setRequestHeader("Authorization", `Bearer ${token}`);
        request.send();
        request.addEventListener("load", () => {
            let data = JSON.parse(request.responseText);
            for(let i = 0; i < data.length; i++) {
                // console.log(data[i])
                // github_list[i]['tag_name']  = data[i].tag_name;
                // github_list[i]['body']      = data[i].body;
                // console.log(data[i].tag_name);
                // console.log(data[i].body);
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
            version_tag.innerText  = data.tag_name;
            version_body.innerHTML = data.body;
            version_tag.innerText  = "GitHub NOW Version: " + data.tag_name;
            // https://github.com/MakerbaseMoon/SpiderBot/releases/download/v0.1.0/firmware.bin
            url = `https://github.com/${github_owner}/${github_repo}/releases/download/${data.tag_name}/firmware.bin`;
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
        if(esp_version_tag != version_tag) {
            esp_version_tag.style.color = 'red';
            version_tag.style.color = 'blue';
        } else {
            esp_version_tag.style.color = 'black';
            version_tag.style.color = 'gray';
        }
    });
}

ota_update_btn.addEventListener('click', () => {
    if(url != "") {
        get_github_ota(url);
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
