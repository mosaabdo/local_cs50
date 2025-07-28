document.addEventListener("DOMContentLoaded", function () {
    const buttons = document.querySelectorAll(".answer");
    buttons.forEach(button => {
        button.addEventListener("click", function () {
            if (button.textContent === "1 person per 6 sheep") {
                button.style.backgroundColor = "green";
            } else {
                button.style.backgroundColor = "red";
            }
        });
    });
});
document.addEventListener("DOMContentLoaded", function () {
    document.querySelector("#check-answer").addEventListener("click", function () {

        let input = document.querySelector("#free-input");
        let answer = input.value.trim().toLowerCase();
        let feedback = input.parentElement.querySelector(".feedback");

        if (answer === "tokyo") {
            input.style.backgroundColor = "green";
            feedback.textContent = "Correct!";
        } else {
            input.style.backgroundColor = "red";
            feedback.textContent = "Incorrect";
        }

    });

});