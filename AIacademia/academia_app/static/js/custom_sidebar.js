document.addEventListener("DOMContentLoaded", function() {
    console.log("Script loaded and DOM fully loaded");
    var collapsibleHeaders = document.querySelectorAll(".collapsible");
    var collapsibleItems = document.querySelectorAll(".collapsible-item");

    collapsibleHeaders.forEach(function(header) {
        console.log("Collapsible headers");
        header.addEventListener("click", function() {
            var content = this.nextElementSibling;

            if (content && content.classList.contains('side_bar_content')) {
                content.style.display = content.style.display === 'block' ? 'none' : 'block';
            }
        });
    });

    collapsibleItems.forEach(function(item) {
        console.log("Collapsible-items");
        item.addEventListener("click", function() {
            var content = this.nextElementSibling;

            if (content && content.classList.contains('sub-content')) {
                content.style.display = content.style.display === 'block' ? 'none' : 'block';
            }
        });
    });
});
