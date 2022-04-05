const cluster = require('cluster');
const http = require("http");

const user = {
    nome: "Jorge",
    senha: "isi2022",
};

const html = `
  <html>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <head></head>
    
    <body style="
            margin: 0;
            padding: 0;
            overflow: hidden;"
    >
      <div style="
            width: 100vw;
            height: 100vh;
            display: flex;
            align-items: center;
            justify-content: center;"
      >
        <form method="POST" action="/login">
          <input name="nome" type="text" placeholder="Receba">
          <input name="senha" type="password" placeholder="Password">
          <button type="submit">Logar</button>
        </form>
      </div>
    </body>
  </html>
`;

const htmlLoginSuccess = `
  <html>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <head></head>
    
    <body style="
            margin: 0;
            padding: 0;
            overflow: hidden;"
    >
      <div style="
            width: 100vw;
            height: 100vh;
            display: flex;
            align-items: center;
            justify-content: center;"
      >
        <h1>Olá ${user.nome}, seja bem vindo!</h1>
        <a href="/">Voltar</a>
      </div>
    </body>
  </html>
`;

const htmlLoginError = `
  <html>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <head></head>
    
    <body style="
            margin: 0;
            padding: 0;
            overflow: hidden;"
    >
      <div style="
            width: 100vw;
            height: 100vh;
            display: flex;
            align-items: center;
            justify-content: center;"
      >
        <script>
          window.alert('Login incorreto!')
          window.location.replace('/')
        </script>
      </div>
    </body>
  </html>
`;

const numCPUs = require('os').cpus().length;

if (cluster.isMaster) {

    for (let i = 0; i < numCPUs; i++) {
        cluster.fork();
    }

    cluster.on('exit', (worker, code, signal) => {
        console.log(`Worker ${worker.process.pid} died`);
    })

} else {
    http
        .createServer((req, res) => {
            try {
                switch (req.url) {
                    case "/":
                        res.writeHead(200, "content-type: 'text/plain'");
                        res.write(html);
                        res.end();
                        break;
                    case "/login":
                        req.setEncoding("utf8");

                        req.on("data", (data) => {
                            const splitedData = data.split("&");

                            const extractedData = splitedData.map(
                                (item) => {
                                    const aux = item.split("=");
                                    return aux[1];
                                }
                            );

                            const formData = {
                                nome: extractedData[0],
                                senha: extractedData[1],
                            };

                            if (
                                formData.nome === user.nome &&
                                formData.senha === user.senha
                            ) {
                                res.writeHead(200);

                                res.write(htmlLoginSuccess);

                                res.end();
                            } else {
                                res.writeHead(401, {
                                    Location: `http://localhost:8080/`,
                                });

                                res.write(htmlLoginError);

                                res.end();
                            }
                        });
                        break;
                    default:
                        res.writeHead(404);
                        res.end(
                            JSON.stringify({
                                Error: "Página não encontrada",
                            })
                        );
                }
            } catch (error) {
                console.log(error);
                res.writeHead(500);
                res.end(
                    JSON.stringify({
                        Error: "Erro interno do servidor",
                    })
                );
            }
        })
        .listen(8080);

    console.log(`Worker ${process.pid} started`);
}