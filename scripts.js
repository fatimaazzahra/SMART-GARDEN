const antares = require('antares-http');
const express = require('express')
const app = express()

antares.setAccessKey('ca55fee49ab1a048:ac85441edd41a2b7');

app.use((req, res, next) => {
  res.header('Access-Control-Allow-Origin', '*');
  next();
});

app.get('/', function(req, res, next) {
	antares.get('SmartGarden01', 'smartgarden')
            .then(function(response) {
                console.log(response.content);
                res.json(response.content);
            });
});
app.listen(3000);