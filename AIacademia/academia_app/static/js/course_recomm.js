document.addEventListener('DOMContentLoaded', function() {
    const chatAvatar = document.getElementById('chatAvatar');
    const chatWidget = document.getElementById('chatWidget');
    const chatClose = document.getElementById('chatClose');
    const chatSend = document.getElementById('chatSend');
    const chatInput = document.getElementById('chatInput');
    const chatBody = document.getElementById('chatBody');

    // Generate a unique conversation ID and store it in sessionStorage
    if (!sessionStorage.getItem('conversation_id')) {
        sessionStorage.setItem('conversation_id', 'user-' + new Date().getTime());
    }
    const conversationId = sessionStorage.getItem('conversation_id');

    chatAvatar.addEventListener('click', function() {
        chatWidget.style.display = 'flex';
    });

    chatClose.addEventListener('click', function() {
        chatWidget.style.display = 'none';
    });

    chatSend.addEventListener('click', function() {
        sendMessage();
    });

    chatInput.addEventListener('keypress', function(event) {
        if (event.key === 'Enter') {
            event.preventDefault();
            sendMessage();
        }
    });

    function sendMessage() {
        const message = chatInput.value.trim();
        if (message) {
            var li = document.createElement('div');
            li.classList.add('chat-message', 'user-message');
            var userAvatar = document.createElement('div');
            userAvatar.classList.add('chat-avatar-small');
            var messageDiv = document.createElement('div');
            messageDiv.textContent = message;
            var timestamp = document.createElement('div');
            timestamp.className = 'chat-timestamp';
            timestamp.textContent = new Date().toLocaleTimeString();
            li.appendChild(messageDiv);
            li.appendChild(timestamp);
            chatBody.appendChild(li);
            chatInput.value = '';

            // Send message to the Rasa server
            fetch('http://localhost:5005/webhooks/rest/webhook', {
                method: 'POST',
                headers: {
                    'Content-Type': 'application/json',
                },
                body: JSON.stringify({ sender: conversationId, message: message })
            }).then(response => {
                if (response.ok) {
                    return response.json();
                } else {
                    throw new Error('Failed to fetch: ' + response.statusText);
                }
            }).then(data => {
                console.log("Received data:", data);  // Log the data received
                data.forEach(msg => {
                    var li = document.createElement('div');
                    var botAvatar = document.createElement('div');
                    botAvatar.classList.add('chat-avatar-small');
                    var messageDiv = document.createElement('div');
                    messageDiv.textContent = msg.text;
                    var timestamp = document.createElement('div');
                    timestamp.className = 'chat-timestamp';
                    timestamp.textContent = new Date().toLocaleTimeString();
                    li.classList.add('chat-message', 'bot-message');
                    li.appendChild(botAvatar);
                    li.appendChild(messageDiv);
                    li.appendChild(timestamp);
                    chatBody.appendChild(li);
                    chatBody.scrollTop = chatBody.scrollHeight;  // Scroll to bottom
                });
            }).catch(error => {
                console.error('Error:', error);
            });

            chatBody.scrollTop = chatBody.scrollHeight;  // Scroll to bottom
        }
    }

    // Reset session expiration on user activity
    document.addEventListener('mousemove', () => {
        sessionStorage.setItem('last_interaction', new Date().getTime());
    });
    document.addEventListener('keypress', () => {
        sessionStorage.setItem('last_interaction', new Date().getTime());
    });

    // Check if the session should be renewed
    setInterval(() => {
        const lastInteraction = sessionStorage.getItem('last_interaction');
        const now = new Date().getTime();
        const tenMinutes = 10 * 60 * 1000;

        if (now - lastInteraction > tenMinutes) {
            sendMessage('/keep_alive');
        }
    }, 60000); // Check every minute







    
    const form = document.getElementById('course-recommendation-form');
    const steps = document.querySelectorAll('.form-step');
    const nextButtons = document.querySelectorAll('.next-btn');
    const backButtons = document.querySelectorAll('.back-btn');
    const interestButtons = document.querySelectorAll('.interest-button');
    const subjectButtons = document.querySelectorAll('.subject-button');
    const recommendationsArea = document.getElementById('recommendations-area');
    const loginButton = document.getElementById('loginButton');
    const backButton = document.querySelector('.back-last-btn');
    const url = form.getAttribute('data-url');
    let currentStepIndex = 0;

    // Show or hide steps
    function showCurrentStep() {
        steps.forEach((step, index) => {
            step.style.display = index === currentStepIndex ? 'block' : 'none';
        });
    }

    // Move to the next or previous step
    nextButtons.forEach((btn) => {
        btn.addEventListener('click', () => {
            if (currentStepIndex < steps.length - 1) {
                currentStepIndex++;
                showCurrentStep();
            }
        });
    });

    backButtons.forEach((btn) => {
        btn.addEventListener('click', () => {
            if (currentStepIndex > 0) {
                currentStepIndex--;
                showCurrentStep();
            }
        });
    });

    // Toggle aria-pressed and active class for interest buttons
    interestButtons.forEach(button => {
        button.addEventListener('click', function() {
            toggleButtonState(this, 'interest');
        });
    });

    subjectButtons.forEach(button => {
        button.addEventListener('click', function() {
            toggleButtonState(this, 'subject');
        });
    });


    function toggleButtonState(button, buttonType) {
        const isPressed = button.getAttribute('aria-pressed') === 'true';
        button.setAttribute('aria-pressed', String(!isPressed));
        button.classList.toggle('active');
    
        // Update the hidden input for this button
        const hiddenInput = document.getElementById(`input_${buttonType}_${button.getAttribute('data-value')}`);
        hiddenInput.value = isPressed ? '' : button.textContent.trim(); // Set value when active, clear when not
        
    }
    
    // Handle form submission to fetch recommendations asynchronously
    form.addEventListener('submit', function(e) {
        e.preventDefault(); // Prevent the form from submitting the traditional way
        
        interestButtons.forEach(button => {
            const isPressed = button.getAttribute('aria-pressed') === 'true'; // Move this inside the loop
            const hiddenInput = document.getElementById('interest_' + button.getAttribute('data-value'));
            if (hiddenInput) {
                hiddenInput.value = isPressed ? button.textContent.trim() : '';
            } else {
                console.error('Element not found for ID:', 'interest_' + button.getAttribute('data-value'));
            }

            hiddenInput.value = isPressed ? button.textContent.trim() : '' ; // Use the text content of the button 
            console.log('Trying to access hidden input with ID:', 'interest_' + button.getAttribute('data-value'));

        });

        subjectButtons.forEach(button => {
            const isPressed = button.getAttribute('aria-pressed') === 'true';
            const hiddenInput = document.getElementById('input_subject_' + button.getAttribute('data-value'));
            if (hiddenInput) {
                hiddenInput.value = isPressed ? button.textContent.trim() : '';
            } else {
                console.error('Element not found for ID:', 'interest_' + button.getAttribute('data-value'));
            }

            console.log('Trying to access hidden input with ID:', 'interest_' + button.getAttribute('data-value'));

        });

        
        var formData = new FormData(this);

        const csrfToken = document.querySelector('[name=csrfmiddlewaretoken]').value;

        fetch(url, {
            method: 'POST',
            body: formData,
            headers: {
                'X-CSRFToken': csrfToken // Ensure CSRF token is included if CSRF protection is enabled
            }
        })
        .then(response => {
            if (!response.ok) {
                throw new Error('Network response was not ok.');
            }
            return response.json();
        })

        .then(data => {
            console.log(data);  // See the exact structure of the response
            // Assuming 'data.recommendations' is an array of course titles or objects
            updateRecommendations(data.recommendations);
        })
        .catch(error => console.error('Error:', error));
    });

    // Initialize the form with the first step visible
    showCurrentStep();

    function updateRecommendations(recommendations) {
        const recommendationsList = document.querySelector('.courses-list');
        
        recommendationsList.innerHTML = ''; // Clear current recommendations
    
        recommendations.forEach(course => {
            const listItem = document.createElement('li');
            listItem.className = 'course-item';
            listItem.innerHTML = `<a href="#"><h4>${course}</h4></a>`;
            recommendationsList.appendChild(listItem);
        });
        recommendationsArea.style.display = 'block';
    }    

    // Function to navigate to the login page
    loginButton.addEventListener('click', function() {
        const loginButton = document.getElementById('loginButton');
        loginButton.addEventListener('click', function() {
        const loginUrl = this.getAttribute('data-url');
        window.location.href = loginUrl;
    });

     // Function to handle the back button functionality
     backButton.addEventListener('click', function() {
        recommendationsArea.style.display = 'none'; // Hide recommendations
        steps[steps.length - 1].style.display = 'block'; // Show the last form step or adjust accordingly
    });

});
})
