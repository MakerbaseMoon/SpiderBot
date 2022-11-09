function initWebSocket() { 
    console.log("WebSocket connection...");
    websocket           = new WebSocket(`ws://${window.location.hostname}/ws`);
    websocket.onopen    = onOpen;
    websocket.onclose   = onClose;
    websocket.onmessage = onMessages;
}

function onOpen() { 
    console.log('Connection opened');
}

function onClose() { 
    console.log('Connection closed');
    setTimeout(initWebSocket, 2000);
}

function onMessages(event) { 
    console.log(event.data);
}

function button_Click() { 
    mode_Auto.addEventListener('click', ()=> { 
        mode_Text.innerText = "Auto Mode";
        websocket.send("Auto");
        car_Stop.disabled = true;
        forward.disabled = true;
        back.disabled = true;
        left.disabled = true;
        right.disabled = true;
        
    });
    
    mode_Control.addEventListener('click', ()=> { 
        mode_Text.innerText = "Control Mode";
        websocket.send("Control");
        car_Stop.disabled = false;
        forward.disabled = false;
        back.disabled = false;
        left.disabled = false;
        right.disabled = false;
    });

    switch_Mode.addEventListener('click', ()=> { 
        if(mode_Text.innerText ==  "Control Mode") { 
            mode_Text.innerText = "Auto Mode";
            websocket.send("Auto");
            car_Stop.disabled = true;
            forward.disabled = true;
            back.disabled = true;
            left.disabled = true;
            right.disabled = true;
            
        } else if (mode_Text.innerText == "Auto Mode") { 
            mode_Text.innerText = "Control Mode";
            websocket.send("Control");
            car_Stop.disabled = false;
            forward.disabled = false;
            back.disabled = false;
            left.disabled = false;
            right.disabled = false;
        }
    });

    car_Stop.addEventListener('click', ()=> { 
        console.log("car stop");
        websocket.send("0");
    });

    forward.addEventListener('click',  ()=> { 
        console.log("car forward");
        websocket.send("1");
    });

    back.addEventListener('click',     ()=> { 
        console.log("car back");
        websocket.send("2");
    });

    left.addEventListener('click',     ()=> { 
        console.log("car left");
        websocket.send("3");
    });

    right.addEventListener('click',    ()=> { 
        console.log("car right");
        websocket.send("4");
    });
    
}




