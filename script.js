function loginAsStudent() {
            // Hide the login box
            document.querySelector('.login-box').style.display = 'none';
            
            // Show the student page content
            document.getElementById('student-page').style.display = 'block';
        }
function loginAsAdmin() {
    // You can add your login logic for admins here
    alert("Logging in as Admin");
    document.querySelector('.login-box').style.display = 'none';

    document.getElementById('admin-page').style.display = 'block';

}
function logout() {
    // Redirect to the login page when logout is clicked
    window.location.href = "index.html";
}
