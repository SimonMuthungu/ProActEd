document.addEventListener('DOMContentLoaded', function() {


    // the avatar
    let scene, camera, renderer, avatar; // Global variable to hold the 3D model

    function init() {
        // Create the scene
        scene = new THREE.Scene();
        
        // Set up the camera
        camera = new THREE.PerspectiveCamera(75, window.innerWidth / window.innerHeight, 0.1, 1000);
        camera.position.z = 5;

        // Set up the renderer
        renderer = new THREE.WebGLRenderer({ antialias: true });
        renderer.setSize(window.innerWidth, window.innerHeight);
        renderer.setSize(950, 600);
        document.getElementById('3d-avatar').appendChild(renderer.domElement);

        // Add lighting
        const light = new THREE.AmbientLight(0xffffff); // Soft white light
        scene.add(light);

        // Load a GLB model
        const loader = new THREE.GLTFLoader();
        loader.load('/static/avatars/6678727b5b9b62b38a2bcae8.glb', function(gltf) {

            avatar = gltf.scene; // Assign the loaded model to the avatar variable
            scene.add(avatar);  // Add the avatar to the scene
            // Initial position or rotation adjustments
            avatar.rotation.y = Math.PI / 10; 

        }, undefined, function(error) {
            console.error(error);
        });

        // Start the animation loop
        animate();
        

    }

    function animate() {
        requestAnimationFrame(animate);

        // Optional: Rotate the model
        if (scene.children.length > 0) {
            scene.children[0].rotation.y += 0.01;
        }

        renderer.render(scene, camera);
    }

    init(); // Initialize the scene



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
    const messageDisplay = document.getElementById('avatar-message');  // Assume this is a DOM element for messages
    let currentStepIndex = 0;

    function showMessage(message) {
        messageDisplay.textContent = message;  // Update text content of the message display
    }

    // first message
    showMessage("Welcome, let me help find courses for you, this is Maseno University Proacted. Please select your interests from this catalogue.");


    // Show or hide steps
    function showCurrentStep() {
        steps.forEach((step, index) => {
            step.style.display = index === currentStepIndex ? 'block' : 'none';
        });
    }

    // Move to the next or previous step
    nextButtons.forEach((btn) => {
        btn.addEventListener('click', () => {
            if (currentStepIndex === 0) {
                showMessage("Now describe yourself.");
            } else if (currentStepIndex === 1) {
                showMessage("Finally, tell us the subjects you excelled at.");
            }
            if (currentStepIndex < steps.length - 1) {
                currentStepIndex++;
                showCurrentStep();
            }
        });
    });

    backButtons.forEach((btn) => {
        btn.addEventListener('click', () => {
            showMessage("Did you forget something? Would you like to speak to me?");
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
        showMessage("Here are the courses I found best for you.");
        
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



    // const canvas = document.querySelector('#3d-avatar canvas');
    // const maxWidth = 250; // Maximum canvas width
    // const maxHeight = 250; // Maximum canvas height

    // function resizeCanvas() {
    //     canvas.style.width = `${maxWidth}px`;
    //     canvas.style.height = `${maxHeight}px`;
    //     console.log('Resizing canvas thru js');
    // }
    // resizeCanvas();

    // Call resizeCanvas when the window resizes or on other relevant events
    // window.addEventListener('resize', resizeCanvas);
    // Initialize canvas size

    function nod() {
        // Simple nod simulation: rotate the head slightly back and forth
        if (avatar && avatar.head) {
            avatar.head.rotation.x += 0.1;  // Rotate down
            setTimeout(() => {
                avatar.head.rotation.x -= 0.1;  // Rotate back up
            }, 500);  // Return after 500ms
        }
    }

    function wave() {
        // Simple wave simulation: rotate the arm
        if (avatar && avatar.rightArm) {
            avatar.rightArm.rotation.z += 0.3;  // Rotate arm
            setTimeout(() => {
                avatar.rightArm.rotation.z -= 0.3;  // Rotate arm back
            }, 500);
        }
    }


})