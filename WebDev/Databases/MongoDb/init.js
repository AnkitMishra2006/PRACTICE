const mongoose = require("mongoose");
const { faker } = require("@faker-js/faker");
const Chat = require("./models/chat.js");

main()
  .then(() => {
    console.log("Connection successful");
  })
  .catch((err) => console.log(err));

async function main() {
  await mongoose.connect("mongodb://127.0.0.1:27017/whatsapp");

  // use `await mongoose.connect('mongodb://user:password@127.0.0.1:27017/test');` if your database has auth enabled
}

function getRandomUser() {
  return {
    from: faker.person.firstName() + " " + faker.person.lastName(),
    to: faker.person.firstName() + " " + faker.person.lastName(),
    msg: faker.lorem.sentence(5),
    created_at: faker.date.anytime(),
  };
}

let data = [];

// data.push(getRandomUser());
// console.log(data);
for (let i = 0; i < 10; i++) {
  data.push(getRandomUser());
}

Chat.insertMany(data)
  .then((res) => console.log(res))
  .catch((err) => console.log(err));
