document.addEventListener("DOMContentLoaded", function() {
    var coll = document.querySelectorAll(".collapsible, .collapsible-item");

    coll.forEach(function(el) {
        el.addEventListener("click", function() {
            this.classList.toggle("active");
            var content = this.nextElementSibling;
            if (content.style.display === "block") {
                content.style.display = "none";
            } else {
                content.style.display = "block";
            }
        });
    });
});
