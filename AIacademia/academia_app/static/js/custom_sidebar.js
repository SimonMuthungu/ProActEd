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
});
