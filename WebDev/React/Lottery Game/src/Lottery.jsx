import { useState } from "react";
import "./Lottery.css";
import { genTicket, sum } from "./helper";
import Ticket from "./Ticket";

function Lottery({n, winningSum}) {
  let [ticket, setTicket] = useState(genTicket(n));
  let isWin = sum(ticket) === winningSum;

  let buyTicket = () => {
    setTicket(genTicket(n));
  };
  return (
    <div>
      <h1>Lottery Game</h1>
      <div className="ticket">
        <Ticket ticket={ticket}/>
      </div>
      <h3>{isWin && "Congrats You Won!!"}</h3>
      <br />
      <br />
      <button onClick={buyTicket}>Buy New Ticket</button>
    </div>
  );
}

// ----------AAM ZINDAGI ------------------//
// function Lottery() {
//   let [ticket, setTicket] = useState(genTicket(3));
//   let isWin = sum(ticket) === 15;

//   let buyTicket = () => {
//     setTicket(genTicket(3));
//   };
//   return (
//     <div>
//       <h1>Lottery Game</h1>
//       <div className="ticket">
//         <span>{ticket[0]}</span>
//         <span>{ticket[1]}</span>
//         <span>{ticket[2]}</span>
//       </div>
//       <h3>{isWin && "Congrats You Won!!"}</h3>
//       <br />
//       <br />
//       <button onClick={buyTicket}>Buy New Ticket</button>
//     </div>
//   );
// }

export default Lottery;
