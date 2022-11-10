window.addEventListener('load', OnLoad);

function OnLoad() { 
    initWebSocket();
    button_Click();
    get_esp_info_data();
    get_github_list_releases();
    get_github_latest_release();
};