import { useState } from "react";
import "./App.css";
import LikeButton from "./likeButton";
import LudoBoard from "./LudoBoard";

function App() {
  const [count, setCount] = useState(0);

  return (
    <>
      <h1>UseState</h1>
      <LudoBoard></LudoBoard>      
      <LikeButton />
    </>
  );
}

export default App;
