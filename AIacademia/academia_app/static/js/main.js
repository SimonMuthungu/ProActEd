// console.log('hello world')
var socket = new WebSocket('ws://localhost:8000/ws/academia_app/');

socket.onmessage = function (e){
    var djangoData = JSON.parse(e.data);
    console.log(djangoData);

    document.querySelector('#app').innerText = djangoData.value;
}


document.addEventListener('DOMContentLoaded', function() {
    checkNewMessages();
});

function checkNewMessages() {
    fetch('/check_new_messages/')
        .then(response => response.json())
        .then(data => {
            if (data.has_new_messages) {
                document.getElementById('inbox-notification').style.display = 'block';
            }
        })
        .catch(error => console.error('Error checking for new messages:', error));
}

