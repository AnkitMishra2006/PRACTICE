let btn = document.querySelector(".addBtn");
let ul = document.querySelector(".ulTasks");
let inp = document.querySelector("#taskInput")

btn.addEventListener("click",function() {
    let item = document.createElement("li");
    item.classList.add("liTask")
    let task = document.createElement("span")
    task.classList.add("task")
    task.innerText = inp.value;
    item.appendChild(task)

    let delBtn = document.createElement("button");
    delBtn.innerText = "delete";
    delBtn.classList.add("delete");
    delBtn.addEventListener("click",function(){
        let par = delBtn.parentElement;
        par.remove();
    });

    item.appendChild(delBtn);
    ul.appendChild(item);
    inp.value = "";
});

