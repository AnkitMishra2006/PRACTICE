import { useState } from "react";

export default function CommentsForm() {
  let [formData, setFormData] = useState({
    username: "",
    remarks: "",
    rating: 5,
  });

  let handleInputChange = (event) => {
    setFormData((currData) => {
      return {
        ...currData,
        [event.target.name]: event.target.value,
      };
    });
  };

  let handleSubmit = (event) => {
    console.log(formData);
    event.preventDefault();
    setFormData({
      username: "",
      remarks: "",
      rating: 5,
    });
  };

  return (
    <>
      <h1>Give a Comment</h1>
      <form onSubmit={handleSubmit}>
        <label htmlFor="username">Username</label>
        <input
          type="text"
          placeholder="username"
          name="username"
          value={formData.username}
          onChange={handleInputChange}
          id="username"
        />{" "}
        <br /> <br />
        <label htmlFor="remarks">Remarks</label>
        <textarea
          placeholder="ADD A REMARK"
          name="remarks"
          id="remarks"
          value={formData.remarks}
          onChange={handleInputChange}
        >
          remarks
        </textarea>{" "}
        <br /> <br />
        <label htmlFor="rating">Rating</label>
        <input
          type="number"
          placeholder="rating"
          min={1}
          max={5}
          name="rating"
          value={formData.rating}
          onChange={handleInputChange}
          id="rating"
        />{" "}
        <br />
        <br />
        <button type="submit">Add Comment</button>
      </form>
    </>
  );
}
