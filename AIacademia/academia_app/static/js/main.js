// console.log('hello world')
var socket = new WebSocket('ws://localhost:8000/ws/academia_app/');

socket.onmessage = function (e){
    var djangoData = JSON.parse(e.data);
    console.log(djangoData);

    document.querySelector('#app').innerText = djangoData.value;
}

// main.js

document.addEventListener('DOMContentLoaded', function() {
    // Code to check for new messages and show notification dot
    checkNewMessages();
});

function checkNewMessages() {
    // Make an AJAX request to check for new messages
    fetch('/check_new_messages/')
        .then(response => response.json())
        .then(data => {
            if (data.has_new_messages) {
                document.getElementById('inbox-notification').style.display = 'block';
            }
        })
        .catch(error => console.error('Error checking for new messages:', error));
}
