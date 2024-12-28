let currentValue = '';
let display = document.querySelector('#display');
document.querySelector('.delete').addEventListener('click', () => {
    currentValue = currentValue.slice(0,-1);
    display.value = currentValue;

})
document.querySelector('.clear').addEventListener('click', () => {
    currentValue = '';
    display.value = currentValue;
})
function addCurrentValue()
{
    currentValue += this.innerText;
    display.value = currentValue;
}

let btns = document.querySelectorAll('.on-display');

for(let i = 0; i<btns.length; i++)
{
    btns[i].addEventListener('click', addCurrentValue);
}

document.querySelector('.evaluate').addEventListener('click', () => {
    currentValue = eval(currentValue);
    display.value = currentValue;
})
