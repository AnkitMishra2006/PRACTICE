import { useState } from "react";

function LikeButton() {
  let [isLiked, setIsLiked] = useState(false);
  let [count, setCount] = useState(0);

  function toggle() {
    setIsLiked(!isLiked);
  }
  let inc = () => {
    setCount(count + 1); // the value is updated not after the function call but when the page is re-rendered
    // setCount((currCount) => {
    //     return currCount + 1
    // })
  };

  let styles = {
    color: "red",
  };

  return (
    <div>
      <div>
        <p>Like Button</p>
        <p onClick={toggle}>
          {isLiked ? (
            <i className="fa-solid fa-heart" style={styles}></i>
          ) : (
            <i className="fa-regular fa-heart"></i>
          )}
        </p>
      </div>
      <div>
        <p>Counter: {count}</p>

        <button onClick={inc}>Increment</button>
      </div>
    </div>
  );
}

export default LikeButton;
