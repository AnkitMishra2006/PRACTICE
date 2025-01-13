const { faker } = require("@faker-js/faker");
const mysql = require("mysql2");

const connection = mysql.createConnection({
  host: "localhost",
  user: "root",
  database: "practice",
  password: "MySQLpassword",
});

try {
  connection.query("SHOW TABLES", (err, res) => {
    if (err) throw err;
    console.log(res);
  });
} catch (err) {
  console.log(err);
}

let getRandomUser = () => {
  return {
    id: faker.string.uuid(),
    username: faker.internet.username(),
    email: faker.internet.email(),
    password: faker.internet.password(),
  };
};

connection.end();
// console.log(getRandomUser());
