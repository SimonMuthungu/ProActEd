// Function to update the courses dropdown based on the selected department
function updateCourses(selectElement) {
    // Get the selected department ID from the data attribute
    const departmentId = selectElement.value;
    
    // Find the corresponding courses select element
    const coursesSelect = selectElement.nextElementSibling;

    // Clear the existing options in the courses select
    coursesSelect.innerHTML = '';

    // If the selected option is "select" or no department is selected, hide the courses select
    if (departmentId === 'select') {
        coursesSelect.style.display = 'none';
        return;
    }

    // Send an AJAX request to fetch courses for the selected department
    fetch(`/api/get_courses/${departmentId}/`)
        .then(response => response.json())
        .then(data => {
            // Populate the courses select with the fetched data
            data.forEach(course => {
                const option = document.createElement('option');
                option.value = course.id;
                option.textContent = course.name;
                coursesSelect.appendChild(option);
            });
            // Display the courses select
            coursesSelect.style.display = 'block';
        })
        .catch(error => {
            console.error('Error fetching courses:', error);
        });
}

// Add any additional JavaScript functionality as needed

// const button = document.querySelectorAll('.button');
// button.forEach(button => {
//     button.addEventListener('click', (event)=> {
//     event.preventDefault();
//     button.style.backgroundColor='#5e0361';
//     button.style.boxShadow= '0 0 40px pink ';
//     button.style.transition = '.2s ease';
//     });
// });
const buttons = document.querySelectorAll('.button');
buttons.forEach(button => {
    button.addEventListener('click', (event) => {
        event.preventDefault();
        
        // Check if the button is already selected
        if (button.classList.contains('selected')) {
            // Button is selected, revert to original style
            button.style.backgroundColor = ''; // Revert to the original background color
            button.style.boxShadow = ''; // Revert to the original box shadow
            button.classList.remove('selected'); // Remove the 'selected' class
        } else {
            // Button is not selected, apply the new style
            button.style.backgroundColor = '#5e0361';
            button.style.boxShadow = '0 0 40px pink';
            button.classList.add('selected'); // Add the 'selected' class to indicate the button is selected
        }

        button.style.transition = '.2s ease';
    });
});
