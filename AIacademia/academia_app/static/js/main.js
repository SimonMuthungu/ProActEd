// console.log('hello world')
var socket = new WebSocket('ws://localhost:8000/ws/academia_app/');

socket.onmessage = function (e){
    var djangoData = JSON.parse(e.data);
    console.log(djangoData);

    document.querySelector('#app').innerText = djangoData.value;
}
