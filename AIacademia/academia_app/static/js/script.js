document.addEventListener("DOMContentLoaded", function() {
    console.log("Script loaded and DOM fully loaded");

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
});
