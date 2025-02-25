import { useState } from "react";
import { v4 as uuidv4 } from "uuid";

function Todo() {
  let [todos, setTodos] = useState([]);
  let [newTodo, setNewTodo] = useState("");
  let [isDone, setIsDone] = useState(false);

  let markAll = () => {
    setIsDone(!isDone);
  };

  let mark = (id) => {
    setTodos(
      todos.map((todo) => {
        if (todo.id == id) {
          return {
            ...todo,
            isDone: !todo.isDone,
          };
        } else {
          return todo;
        }
      })
    );
  };

  let updateTodos = () => {
    setTodos((prevTodos) => {
      return [...prevTodos, { task: newTodo, id: uuidv4(), isDone: false }];
    });
  };
  let updateNewTodo = (event) => {
    setNewTodo(event.target.value);
  };

  let deleteTodo = (id) => {
    console.log(id);
    let copy = todos.filter((todo) => todo.id != id);
    setTodos(copy);
  };

  return (
    <>
      <div>
        <input
          placeholder="Add a Task"
          value={newTodo}
          onChange={updateNewTodo}
        />{" "}
        <br />
        <button onClick={updateTodos}>Add Todo</button>
      </div>
      <br /> <br /> <hr />
      <div>
        <h2>All Todos</h2>
        {todos.map((todo) => {
          return (
            <li key={todo.id}>
              <span
                style={
                  todo.isDone ? { textDecorationLine: "line-through" } : {}
                }
              >
                {todo.task}
              </span>
              &nbsp; &nbsp;&nbsp;
              <button onClick={() => deleteTodo(todo.id)}>Delete</button>
              &nbsp;&nbsp;&nbsp;
              <button onClick={() => mark(todo.id)}>
                {todo.isDone ? "UnMark as Done" : "Mark as Done"}
              </button>
            </li>
          );
        })}
        <button onClick={markAll}>Mark all as done</button>
      </div>
    </>
  );
}

export default Todo;
