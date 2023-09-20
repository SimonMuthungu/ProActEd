// // static/script.js
// async function updateCourses() {
//     const departmentId = document.getElementById('department').value;
//     const coursesDropdown = document.getElementById('courses');

//     // Clear previous courses
//     coursesDropdown.innerHTML = '';

//     if (departmentId === 'select') {
//         coursesDropdown.style.display = 'none';
//         return;
//     }

//     try {
//         const response = await fetch(`/fetch_courses/${departmentId}/`);
//         const courses = await response.json();

//         courses.forEach(course => {
//             let option = document.createElement('option');
//             option.value = course.id;
//             option.textContent = course.name;
//             coursesDropdown.appendChild(option);
//         });

//         coursesDropdown.style.display = 'block'; // Show courses dropdown
//     } catch (error) {
//         console.error('Error fetching courses:', error);
//     }
// }

const departmentSelects = document.querySelectorAll('.department-select');
    
departmentSelects.forEach(select => {
    select.addEventListener('change', function() {
        const courseSelect = this.parentElement.querySelector('.course-select');
        if (this.value === 'Select Department') {
            courseSelect.style.display = 'none';
        } else {
            // You can use AJAX to fetch courses based on the selected department here
            // Once you have the courses, populate the courseSelect and make it visible
            courseSelect.style.display = 'block';
        }
    });
});