function getRandomColor(){
    let red = Math.floor(Math.random()*255);
    let green = Math.floor(Math.random()*255);
    let blue = Math.floor(Math.random()*255);
    let color = `rgb(${red}, ${green}, ${blue})`;
    return color;
}
let btn = document.querySelector("button")
btn.addEventListener("click", () => {
    let h3 = document.querySelector("h3");
    let div = document.querySelector("div")
    let randomColor = getRandomColor();
    h3.innerText = randomColor;
    div.style.backgroundColor = randomColor;

});
