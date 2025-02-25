import { useState } from "react";
import "./App.css";
import Lottery from "./Lottery";
import Ticket from "./Ticket";

function App() {
  const [count, setCount] = useState(0);

  return (
    <>
      <Lottery n = {3} winningSum={15}/>
    </>
  );
}

export default App;
