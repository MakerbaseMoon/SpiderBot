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




