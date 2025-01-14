const { faker } = require("@faker-js/faker");
const mysql = require("mysql2");
const express = require("express");
const app = express();
const path = require("path");
const methodOverride = require("method-override");

app.use(methodOverride("_method"));
app.use(express.urlencoded({ extended: true }));
app.use(express.json());
app.use(express.static(path.join(__dirname, "public")));

app.set("view engine", "ejs");
app.set("views", path.join(__dirname, "views"));

const connection = mysql.createConnection({
  host: "localhost",
  user: "root",
  database: "practice",
  password: "MySQLpassword",
});

function getRandomUser() {
  return [
    faker.string.uuid(),
    faker.internet.username(),
    faker.internet.email(),
    faker.internet.password(),
  ];
}

// console.log(getRandomUser());

app.get("/", (req, res) => {
  let q = `SELECT count(*) FROM user;`;

  try {
    connection.query(q, (err, result) => {
      if (err) throw err;
      console.log(result);
      let count = result[0]["count(*)"];
      res.render("home.ejs", { count });
    });
  } catch (err) {
    console.log(err);
    res.send("Some error in Database");
  }
});

// Show Route
app.get("/user", (req, res) => {
  let q = `SELECT * FROM user`;
  try {
    connection.query(q, (err, result) => {
      if (err) throw err;
      let users = result;
      res.render("showUsers.ejs", { users });
    });
  } catch {
    console.log(err);
    res.send("Some error in database");
  }
});

// EDIT Route
app.get("/user/:id/edit", (req, res) => {
  let { id } = req.params;
  let q = `SELECT * FROM user WHERE id = '${id}'`;
  try {
    connection.query(q, (err, result) => {
      if (err) throw err;
      let user = result[0];
      console.log(user);
      res.render("edit.ejs", { user });
    });
  } catch {
    console.log(err);
    // res.send("Some error in database");
  }
});

// UPDATE (DB) Route
app.patch("/user/:id", (req, res) => {
  let { id } = req.params;
  let { password: formPass, username: newUsername } = req.body;
  let q = `SELECT * FROM user WHERE id = '${id}'`;
  try {
    connection.query(q, (err, result) => {
      if (err) throw err;
      let user = result[0];
      if (formPass != user.password) res.send("Wrong Password");
      else {
        let q = `UPDATE user SET username='${newUsername}' WHERE id = '${id}'`;
        connection.query(q, (err, result) => {
          if (err) throw err;
          res.redirect("/user");
        });
      }
    });
  } catch {
    console.log(err);
    res.send("Some error in database");
  }
  // res.send("updated");
});

app.listen("8080", () => {
  console.log("Server running on port 8080");
});

// connection.end();
