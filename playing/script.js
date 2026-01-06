document.addEventListener('DOMContentLoaded', function() {
    const leftArrow = document.getElementById('left-arrow');
    const rightArrow = document.getElementById('right-arrow');
    const buttonA = document.getElementById('button-a');
    const buttonB = document.getElementById('button-b');
    
    leftArrow.addEventListener('click', function() {
        buttonA.classList.remove('button-highlight');
        void buttonA.offsetWidth; // Force reflow
        buttonA.classList.add('button-highlight');

        setTimeout(() => {
            buttonA.classList.remove('button-highlight');
        }, 500);
    });
    
    rightArrow.addEventListener('click', function() {
        buttonB.classList.remove('button-highlight');
        void buttonB.offsetWidth; // Force reflow
        buttonB.classList.add('button-highlight');

        setTimeout(() => {
            buttonB.classList.remove('button-highlight');
        }, 500);
    });
});
