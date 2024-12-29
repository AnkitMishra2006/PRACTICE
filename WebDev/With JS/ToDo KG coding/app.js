let todoList = [];

function addTodo() {
  let inputElement = document.querySelector("#todo-input");
  let todoItem = inputElement.value;
  todoList.push(todoItem);
  inputElement.value = "";
}
