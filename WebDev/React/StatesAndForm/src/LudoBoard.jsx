import { useState } from "react";

function LudoBoard() {
  let [moves, setMoves] = useState({ blue: 0, red: 0, yellow: 0, green: 0 });
  let [arr, setArr] = useState(["No Moves"]);

  let setBlue = () => {
    console.log(`moves.blue = ${moves.blue}`);
    setMoves((prevMoves) => {
      // moves.blue = moves.blue + 1;
      // setMoves(moves) will not work as reference of moves is passed so react will think there is no change
      return { ...prevMoves, blue: prevMoves.blue + 1 }; // if we use spread copy of the object will be passed diff reference means change page will be rendered again
    });
    setArr((prevArr) => {
      return [...prevArr, "Blue Moves"];
    });
  };
  let setRed = () => {
    console.log(`moves.blue = ${moves.red}`);
    setMoves((prevMoves) => {
      return { ...prevMoves, red: prevMoves.red + 1 };
    });
    setArr((prevArr) => {
      return [...prevArr, "Red Moves"];
    });
  };
  let setYellow = () => {
    console.log(`moves.blue = ${moves.yellow}`);
    setMoves((prevMoves) => {
      return { ...prevMoves, yellow: prevMoves.yellow + 1 };
    });
    setArr((prevArr) => {
      return [...prevArr, "Yellow Moves"];
    });
  };
  let setGreen = () => {
    console.log(`moves.blue = ${moves.green}`);
    setMoves((prevMoves) => {
      return { ...prevMoves, green: prevMoves.green + 1 };
    });
    setArr((prevArr) => {
      return [...prevArr, "Green Moves"];
    });
  };

  return (
    <div>
      <p>Game Begins!</p>
      <p>{arr}</p>
      <div>
        <p>Blue Moves: {moves.blue}</p>
        <button onClick={setBlue} style={{ backgroundColor: "blue" }}>
          +1
        </button>
        <p>red Moves: {moves.red}</p>
        <button onClick={setRed} style={{ backgroundColor: "red" }}>
          +1
        </button>
        <p>yellow Moves: {moves.yellow}</p>
        <button onClick={setYellow} style={{ backgroundColor: "yellow" }}>
          +1
        </button>
        <p>green Moves: {moves.green}</p>
        <button onClick={setGreen} style={{ backgroundColor: "green" }}>
          +1
        </button>
      </div>
    </div>
  );
}

export default LudoBoard;
