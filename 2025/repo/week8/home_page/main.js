document.addEventListener("DOMContentLoaded", function () {
    const form = document.getElementById("nav_search_form");
    const input = form.querySelector("input[name='search-input']");

    form.addEventListener("submit", function (e) {
        e.preventDefault(); // يمنع إعادة تحميل الصفحة

        const searchTerm = input.value.toLowerCase();
        const content = document.querySelectorAll("dd");

        content.forEach(dd => {
            dd.style.backgroundColor = "transparent"; // رجّع كل الخلفيات
            if (dd.textContent.toLowerCase().includes(searchTerm)) {
                dd.style.backgroundColor = "yellow"; // ظلل النتيجة
            }
        });
    });
});
