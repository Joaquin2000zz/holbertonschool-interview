#!/usr/bin/node
const request = require('request');

function doRequest (url) {
  return new Promise((resolve, reject) => {
    request(url, (error, res, body) => {
      if (!error && res.statusCode === 200) {
        resolve(body);
      } else {
        reject(error);
      }
    });
  });
}

async function f () {
  try {
    // every variable with await
    // will be whatever you passed to `resolve()` at the top
    const link = `https://swapi-api.hbtn.io/api/films/${process.argv[2]}`;
    const response = await doRequest(link);
    for (const character of JSON.parse(response).characters) {
      const charResp = await doRequest(character);
      console.log(JSON.parse(charResp).name);
    }
  } catch (error) {
    // `error` will be whatever you passed to `reject()` at the top
    console.error(error);
  }
}

f();
