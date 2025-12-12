const toggle = document.querySelector('.menu-toggle');
const menu = document.querySelector('.menu');

toggle.addEventListener('click', () => {
    menu.classList.toggle('open');
});

document.addEventListener('click', function(event) {
    if (!event.target.closest('.navigation') && menu.classList.contains('open')) {
        menu.classList.remove('open');
        toggle.classList.remove('open');
    }
});
