// first express api stuff (from firebase video)
const express = require("express");
const app = express();
const PORT = 8080;

app.listen(PORT, () => {
  console.log("Listening on 8080!");
});

app.use(express.json()); // middleware - converts body to json

app.get("/tshirt", (req, res) => {
  // req -> incoming data, res -> data we wanna send back
  res.status(200).send({
    // response 200 ok and then send data payload back
    tshirt: "Red",
    size: "large",
  });
});

app.post("/tshirt/:id", (req, res) => {
  const { id } = req.params;
  const { logo } = req.body;

  if (!logo) {
    res.status(418).send({ message: "We need a logo!" });
  }

  res.send({
    tshirt: "Tshirt with your logo " + logo + " and ID " + id,
  });
});

/* What I have learned from this:

In the past, I used to just throw everything in the query parameters

Today, I have learned that we can throw things inside the body of the post request (JSON)

This makes it so that url params don't get overloaded

*/
