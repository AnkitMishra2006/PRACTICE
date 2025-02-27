import { useState } from "react";
import "./App.css";
import LikeButton from "./likeButton";
import LudoBoard from "./LudoBoard";
import CommentsForm from "./CommentsForm";

function App() {
  const [count, setCount] = useState(0);

  return (
    <>
      {/* <h1>UseState</h1>
      <LudoBoard></LudoBoard>      
      <LikeButton /> */}
      <CommentsForm></CommentsForm>
    </>
  );
}

export default App;
