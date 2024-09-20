    document.addEventListener('DOMContentLoaded', function () {
        const dashboardContent = document.getElementById('dashboard-content');
        const mainContent = document.getElementById('main-content');

        // Function to toggle dashboard content visibility
        function toggleDashboardContent() {
            if (window.location.pathname !== '/' && window.location.pathname !== '/admin/') {
                dashboardContent.style.display = 'none';
                mainContent.style.marginTop = '0'; // Adjust this value as needed
            } else {
                dashboardContent.style.display = 'block';
                mainContent.style.marginTop = ''; // Reset margin
            }
        }

        // Run the function on page load
        toggleDashboardContent();

        // Optional: Add event listener for navigation (if using client-side routing)
        window.addEventListener('popstate', toggleDashboardContent);
    });