let gameSeq = []
let userSeq = []
let level = 0;
let started = false;

let message = document.querySelector("h2")
document.addEventListener("keypress", function () {
    if(!started){
        console.log("Game is started")
        started = true
        levelUp();
    }
})

function levelUp(){
    level++;
    message.innerText = `Level ${level}`;
}