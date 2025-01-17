const { faker } = require("@faker-js/faker");
const express = require("express");
const app = express();
const mongoose = require("mongoose");
const path = require("path");
const methodOverride = require("method-override");
const Chat = require("./models/chat.js");

app.use(methodOverride("_method"));
app.use(express.urlencoded({ extended: true }));
app.use(express.json());
app.use(express.static(path.join(__dirname, "public")));

app.set("view engine", "ejs");
app.set("views", path.join(__dirname, "views"));

// mongoose.connect("mongodb://127.0.0.1:27017/test");

main()
  .then(() => {
    console.log("Connection successful");
  })
  .catch((err) => console.log(err));

async function main() {
  await mongoose.connect("mongodb://127.0.0.1:27017/whatsapp");

  // use `await mongoose.connect('mongodb://user:password@127.0.0.1:27017/test');` if your database has auth enabled
}
// Root
app.get("/", (req, res) => {
  res.send("Root is working working");
});

// All Chats
app.get("/chats", async (req, res) => {
  let chats = await Chat.find();
  res.render("index.ejs", { chats });
});

// Form for New Chat
app.get("/chats/new", (req, res) => {
  res.render("new.ejs");
});

// Create Route Post
app.post("/chats", async (req, res) => {
  let { from, to, msg } = req.body;
  let newChat = new Chat({
    from: from,
    msg: msg,
    to: to,
    created_at: new Date(),
  });
  newChat
    .save()
    .then((res) => console.log("New Chat Saved"))
    .catch((err) => console.log(err));
  res.redirect("/chats");
});

// Edit Route
app.get("/chats/:id/edit", async (req, res) => {
  let { id } = req.params;
  let chat = await Chat.findById(id);
  res.render("edit.ejs", { chat });
});

// Update Route
app.put("/chats/:id", async (req, res) => {
  let {id} = req.params;
  let {newMsg} = req.body;
  let updatedChat = await Chat.findByIdAndUpdate(id, {msg : newMsg}, {runValidators : true, new: true});
  console.log(updatedChat);
  res.redirect("/chats");
})

// Destroy Route
app.delete("/chats/:id", async (req, res) => {
  let {id} = req.params;
  let deletedChat = await Chat.findByIdAndDelete(id);
  console.log(deletedChat);
  res.redirect("/chats");
})


const port = 8080;

app.listen(port, () => {
  console.log(`Server running on Port: ${port}`);
});
