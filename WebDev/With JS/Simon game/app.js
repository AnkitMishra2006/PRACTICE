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

function checkans(idx)
{
    if(userSeq[idx] == gameSeq[idx])
    {
        if(userSeq.length == gameSeq.length) setTimeout(levelUp, 1000);
    }else{
        message.innerText = `GAME OVER! Your Score: ${level} \nPress any key to start again`;
        document.querySelector("body").style.backgroundColor = "red";
        setTimeout(() => {
            document.querySelector("body").style.backgroundColor = "white";
        }, 150);
        reset();
    }
}
function levelUp(){
    userSeq = [];
    level++;

    message.innerText = `Level ${level}`;
    let randIndx = Math.floor(Math.random() * 4);
    let randColor = btns[randIndx];
    randBtn = document.querySelector(`.${randColor}`)
    gameSeq.push(randColor);
    console.log(gameSeq);
    flash(randBtn);
    
}

function btnPress()
{
    let btn = this;
    flash(btn);

    userColor = btn.getAttribute("id");
    userSeq.push(userColor);
    checkans(userSeq.length - 1);
}
let allBtns = document.querySelectorAll(".btn");
for(btn of allBtns)
{
    btn.addEventListener("click", btnPress);
}

function reset()
{
    userSeq = [];
    gameSeq = [];
    level = 0;
    started = false;
}