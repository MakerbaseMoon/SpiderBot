let github_owner = "MakerbaseMoon";
let github_repo = "SpiderBot";

let github_list = [];

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
                github_list[i]['tag_name']  = data[i].tag_name;
                github_list[i]['body']      = data[i].body;
                console.log(data[i].tag_name);
                console.log(data[i].body);
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

function get_github_ota(url) {
    try {
        let request = new XMLHttpRequest();
        request.open("POST", `${window.location.origin}/ota/update`, true);
        request.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
        request.send(`url=${url}`);
        request.addEventListener("load", () => {
            console.log(data);
        });
    } catch(e) {

    }
}
