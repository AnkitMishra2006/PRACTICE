const { faker } = require("@faker-js/faker");
const mysql = require("mysql2");

const connection = mysql.createConnection({
  host: "localhost",
  user: "root",
  database: "practice",
  password: "MySQLpassword",
});

let q = "INSERT INTO user (id, username, email, password) VALUES ?";
let data = [];
for (let i = 0; i < 30; i++) {
  data.push(getRandomUser());
}

try {
  connection.query(q, [data], (err, res) => {
    if (err) throw err;
    console.log(res);
  });
} catch (err) {
  console.log(err);
}

function getRandomUser() {
  return [
    faker.string.uuid(),
    faker.internet.username(),
    faker.internet.email(),
    faker.internet.password(),
  ];
}

connection.end();
// console.log(getRandomUser());
