let github_owner = "MakerbaseMoon";
let github_repo = "SpiderBot";

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
                console.log(data[i].tag_name);
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
            console.log(data.body);
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
            upgrade_form.style.display = "none"
        } else {
            setting_form.style.display = "none";
            upgrade_form.style.display = "none"
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
