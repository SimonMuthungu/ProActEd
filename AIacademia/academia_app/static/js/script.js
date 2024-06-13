document.addEventListener("DOMContentLoaded", function() {
    console.log("this is script.js");

    // Fetch chart data from the context variables
    var totalStudents = parseInt(document.getElementById('totalStudents').innerText);
    var totalStaff = parseInt(document.getElementById('totalStaff').innerText);
    var totalAdmins = parseInt(document.getElementById('totalAdmins').innerText);
    var totalSchools = parseInt(document.getElementById('totalSchools').innerText);
    var totalCourses = parseInt(document.getElementById('totalCourses').innerText);

    // Initialize the Chart.js chart
    var ctx = document.getElementById('studentsChart').getContext('2d');
    var studentsChart = new Chart(ctx, {
        type: 'bar',
        data: {
            labels: ['Total Students', 'Total Staff', 'Total Admins', 'Total Schools', 'Total Courses'],
            datasets: [{
                label: 'Counts',
                data: [totalStudents, totalStaff, totalAdmins, totalSchools, totalCourses],
                backgroundColor: [
                    'rgba(75, 192, 192, 0.2)',
                    'rgba(54, 162, 235, 0.2)',
                    'rgba(255, 206, 86, 0.2)',
                    'rgba(75, 192, 192, 0.2)',
                    'rgba(153, 102, 255, 0.2)'
                ],
                borderColor: [
                    'rgba(75, 192, 192, 1)',
                    'rgba(54, 162, 235, 1)',
                    'rgba(255, 206, 86, 1)',
                    'rgba(75, 192, 192, 1)',
                    'rgba(153, 102, 255, 1)'
                ],
                borderWidth: 1
            }]
        },
        options: {
            scales: {
                y: {
                    beginAtZero: true
                }
            }
        }
    });

    // Select all collapsible headers and items
    var collapsibleHeaders = document.querySelectorAll(".collapsible");
    var collapsibleItems = document.querySelectorAll(".collapsible-item");

    // Function to toggle visibility of the content
    function toggleContent(element) {
        var content = element.nextElementSibling;
        if (content.style.display === "block") {
            content.style.display = "none";
        } else {
            content.style.display = "block";
        }
    }

    // Attach click event listener to each collapsible header
    collapsibleHeaders.forEach(function(header) {
        console.log("Collapsible header found");
        header.addEventListener("click", function() {
            toggleContent(header);
        });
    });

    // Attach click event listener to each collapsible item
    collapsibleItems.forEach(function(item) {
        console.log("Collapsible item found");
        item.addEventListener("click", function() {
            toggleContent(item);
        });
    });

    // Set initial state of collapsible content
    collapsibleHeaders.forEach(function(header) {
        var content = header.nextElementSibling;
        if (content && (content.classList.contains('side_bar_content') || content.classList.contains('settings'))) {
            content.style.display = "none";
        }
    });

    collapsibleItems.forEach(function(item) {
        var content = item.nextElementSibling;
        if (content && content.classList.contains('sub-content')) {
            content.style.display = "none";
        }
    });

    // Fetch schools and courses for dropdowns
    document.getElementById('schoolDropdown').addEventListener('mouseover', function() {
        fetch('/api/get_schools/')
            .then(response => response.json())
            .then(data => {
                let dropdownContent = document.getElementById('schoolDropdownContent');
                dropdownContent.innerHTML = '';
                data.forEach(school => {
                    let link = document.createElement('a');
                    link.href = `/school_detail/${school.id}/`;
                    link.textContent = school.name;
                    dropdownContent.appendChild(link);
                });
                dropdownContent.style.display = 'block';
            });
    });

    document.getElementById('courseDropdown').addEventListener('mouseover', function() {
        fetch('/api/get_courses/')
            .then(response => response.json())
            .then(data => {
                let dropdownContent = document.getElementById('courseDropdownContent');
                dropdownContent.innerHTML = '';
                data.forEach(course => {
                    let link = document.createElement('a');
                    link.href = `/course_detail/${course.id}/`;
                    link.textContent = course.name;
                    dropdownContent.appendChild(link);
                });
                dropdownContent.style.display = 'block';
            });
    });
});
