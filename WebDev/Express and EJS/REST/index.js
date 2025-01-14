const express = require("express");
const app = express();
const path = require("path");
const { v4: uuidv4 } = require("uuid");

app.use(express.urlencoded({ extended: true }));
app.use(express.json());

app.set("view engine", "ejs");
app.set("views", path.join(__dirname, "views"));
app.use(express.static(path.join(__dirname, "public")));

let posts = [
  {
    id: uuidv4(),
    username: "ankitmishra",
    content: "Learning full stack web development",
  },
  {
    id: uuidv4(),
    username: "deepakpal",
    content: "Started self development",
  },
  {
    id: uuidv4(),
    username: "priyanshu",
    content: "started new series arcane loving it",
  },
];

app.get("/posts", (req, res) => {
  res.render("index.ejs", { posts });
});

app.get("/posts/:id", (req, res) => {
  let { id } = req.params;
  let post = posts.find((p) => id === p.id);
  res.render("show.ejs", { post });
});

app.get("/posts/new", (req, res) => {
  res.render("new.ejs");
});

app.post("/posts", (req, res) => {  
  let { username, content } = req.body;
  let id = uuid();
  posts.push({ id, username, content });
  res.redirect("/posts");
});

const port = 8080;
app.listen(port, () => {
  console.log(`listening to port: ${port}`);
});
