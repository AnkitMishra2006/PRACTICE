import createContext, { useContext, useReducer } from 'react';

export const TodoContext = createContext({
    todos: [
        { id: 1, title: 'Learn React', completed: false },
        { id: 2, title: 'Learn Context API', completed: false },
        { id: 3, title: 'Learn Redux', completed: false },
    ],
    addTodo : (todo) => {},
    updateTodo: (id, todo) => {},
    deleteTodo: (id) => {},
    toggleTodo: (id) => {},
});


export const useTodo = () => {
    return useContext(TodoContext);
}

export const TodoProvider = TodoContext.Provider;