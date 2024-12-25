let gameSeq = [];
let userSeq = [];
let level = 0;
let btns = ["red", "green", "blue", "yellow"];
let started = false;

let message = document.querySelector("h2")
document.addEventListener("keypress", function () {
    if(!started){
        console.log("Game is started");
        started = true;
        levelUp();
    }
})
function flash(btn)
{
    btn.classList.add("flash");
    setTimeout(function ()
    {
        btn.classList.remove("flash");
    }, 300);
}
function levelUp(){
    level++;
    message.innerText = `Level ${level}`;
    let randIndx = Math.floor(Math.random() * 3);
    let randColor = btns[randIndx];
    randBtn = document.querySelector(`.${randColor}`)
    flash(randBtn);
    gameSeq.push(randBtn);
}

function btnPress()
{
    let btn = this;
    flash(btn);

    userColor = btn.getAttribute("id");
    userSeq.push(userColor);
}
let allBtns = document.querySelectorAll(".btn");
for(btn of allBtns)
{
    btn.addEventListener("click", btnPress);
}