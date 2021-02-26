let http = require("http");

function onRequest(request, response) {
  response.writeHead(200, {
    "Content-Type": "text/plain"
  });
  response.write("Hello world1");
  response.end();
}


let server = http.createServer(onRequest)

server.listen(8888);