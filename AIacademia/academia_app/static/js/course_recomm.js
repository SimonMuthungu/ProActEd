document.addEventListener('DOMContentLoaded', function() {
    const form = document.getElementById('course-recommendation-form');
    const steps = document.querySelectorAll('.form-step');
    const nextButtons = document.querySelectorAll('.next-btn');
    const backButtons = document.querySelectorAll('.back-btn');
    const interestButtons = document.querySelectorAll('.interest-button');
    const subjectButtons = document.querySelectorAll('.subject-button');
    const recommendationsArea = document.getElementById('recommendations-area');
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
        hiddenInput.value = isPressed ? '' : button.getAttribute('data-value');
    }
    
    // Handle form submission to fetch recommendations asynchronously
    form.addEventListener('submit', function(e) {
        e.preventDefault(); // Prevent the form from submitting the traditional way
        
        interestButtons.forEach(button => {
            const hiddenInput = document.getElementById(`input_interest_${button.getAttribute('data-value')}`);
            hiddenInput.value = button.getAttribute('aria-pressed') === 'true' ? button.getAttribute('data-value') : '';
        });

        subjectButtons.forEach(button => {
            const hiddenInput = document.getElementById(`input_subject_${button.getAttribute('data-value')}`);
            hiddenInput.value = button.getAttribute('aria-pressed') === 'true' ? button.getAttribute('data-value') : '';
        });

        
        var formData = new FormData(this);

        fetch(url, {
            method: 'POST',
            body: formData,
            headers: {
                'X-CSRFToken': '{{ csrf_token }}' // Ensure CSRF token is included if CSRF protection is enabled
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
    
});


