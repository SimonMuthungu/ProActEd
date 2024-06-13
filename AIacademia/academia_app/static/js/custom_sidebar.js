document.addEventListener("DOMContentLoaded", function() {
    console.log("Script loaded and DOM fully loaded");

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

    // Fetch schools for dropdowns
    document.getElementById('schoolDropdown').addEventListener('mouseenter', function() {
        fetch('/api/get_schools/')
            .then(response => response.json())
            .then(data => {
                let dropdownContent = document.getElementById('schoolDropdownContent');
                dropdownContent.innerHTML = '';
                data.forEach(school => {
                    let link = document.createElement('a');
                    link.href = '#';
                    link.textContent = school.name;
                    link.addEventListener('click', function(event) {
                        event.preventDefault();
                        loadDetails(`/school_detail/${school.id}/`, 'school_content');
                    });
                    dropdownContent.appendChild(link);
                });
                dropdownContent.style.display = 'block';
            });
    });

    // Fetch courses for dropdowns
    document.getElementById('courseDropdown').addEventListener('mouseenter', function() {
        fetch('/api/get_courses/')
            .then(response => response.json())
            .then(data => {
                let dropdownContent = document.getElementById('courseDropdownContent');
                dropdownContent.innerHTML = '';
                data.forEach(course => {
                    let link = document.createElement('a');
                    link.href = '#';
                    link.textContent = course.name;
                    link.addEventListener('click', function(event) {
                        event.preventDefault();
                        loadDetails(`/course_detail/${course.id}/`, 'course_detail');
                    });
                    dropdownContent.appendChild(link);
                });
                dropdownContent.style.display = 'block';
            });
    });

    function loadDetails(url, contentId) {
        fetch(url)
            .then(response => response.text())
            .then(html => {
                document.getElementById('main-content').innerHTML = html;
                document.getElementById('school_content').style.display = 'none';
                document.getElementById('course_detail').style.display = 'none';
                document.getElementById(contentId).style.display = 'block';
            })
            .catch(error => console.error('Error loading details:', error));
    }

    // Event listener for Dashboard link
    document.getElementById('dashboard-link').addEventListener('click', function(event) {
        event.preventDefault();
        loadDashboard();
    });

    function loadDashboard() {
        fetch('/admin_dashboard/')
            .then(response => response.text())
            .then(html => {
                document.getElementById('main-content').innerHTML = html;
                document.getElementById('school_content').style.display = 'none';
                document.getElementById('course_detail').style.display = 'none';
                document.getElementById('dashboard-content').style.display = 'block';
            })
            .catch(error => console.error('Error loading dashboard:', error));
    }
    // Event listener for Dashboard link
    document.getElementById('dashboard-link').addEventListener('click', function(event) {
        event.preventDefault();
        window.location.href = '/admin/';
    });
});
