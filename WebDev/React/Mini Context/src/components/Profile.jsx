import React from "react";
import { useContext, useState } from "react";
import UserContext from "../context/UserContext";

function Profile() {
  const { user } = useContext(UserContext);
  if (!user) {
    return <h2>Please log in</h2>;
  }
  return <div className="text-center text-3xl">Welcome {user.username}</div>;
}

export default Profile;
