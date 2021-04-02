const antares = require('antares-http');
const express = require('express')
const app = express()

antares.setAccessKey('c94390064b1a5459:2685783ce1bcbc1a');

app.use((req, res, next) => {
  res.header('Access-Control-Allow-Origin', '*');
  next();
});

app.get('/', function(req, res, next) {
	antares.get('smartgardenn', 'sensor')
            .then(function(response) {
                console.log(response.content);
                res.json(response.content);
            });
});
app.listen(3000);