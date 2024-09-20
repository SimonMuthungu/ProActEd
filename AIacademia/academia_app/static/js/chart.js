document.addEventListener("DOMContentLoaded", function() {
    const chatForm = document.getElementById('chat-form');
    const chatBox = document.getElementById('chat-box');
    
    chatForm.addEventListener('submit', function(event) {
        event.preventDefault();
        
        const formData = new FormData(chatForm);
        
        fetch("{% url 'send_message' %}", {
            method: 'POST',
            body: formData,
            headers: {
                'X-CSRFToken': formData.get('csrfmiddlewaretoken')
            }
        })
        .then(response => response.json())
        .then(data => {
            if (data.error) {
                console.error(data.error);
            } else {
                const messageDiv = document.createElement('div');
                messageDiv.classList.add('message', 'sent');
                messageDiv.innerHTML = `<p>${data.content}</p><span>${data.timestamp}</span>`;
                chatBox.appendChild(messageDiv);
                chatBox.scrollTop = chatBox.scrollHeight;
                chatForm.reset();
            }
        })
        .catch(error => console.error('Error:', error));
    });
});
