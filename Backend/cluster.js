const cluster = require("cluster");
const os = require("os");
const numCPUs = os.cpus().length;
const express = require("express");
// console.log(numCPUs);
// console.log(os.machine());
// console.log(os.platform());
// console.log(os.release());
// console.log(os.type());
// console.log(os.userInfo());
// console.log(os.version());
// console.log(os.uptime());
// console.log(os.totalmem());
// console.log(os.freemem());
// console.log(os.networkInterfaces());
// console.log(os.homedir());
// console.log(os.hostname());
// console.log(os.arch());
// console.log(os.endianness());
// console.log(os.loadavg());
// console.log(os.tmpdir());
// const app = express();
// if (cluster.isPrimary) {
//     for (let i = 0; i < numCPUs; i++) {
//         cluster.fork();
//     }
//     cluster.on("exit", (worker, code, signal) => {
//         console.log("Worker " + worker.process.pid + " died");
//     })
// }
// else {
//     app.get("/", (req, res) => {
//         res.send("Hello World " + process.pid);
//     })
//     app.listen(3000, (req, res) => console.log("Server started on port 3000"));
// };
const netWorkInterfaces = os.networkInterfaces();
// console.log(netWorkInterfaces);
var netWorkInterfacesArray = Object.values(netWorkInterfaces);
netWorkInterfacesArray.forEach((element) => {
    element.forEach((element2) => {
        console.log(element2.family + "-->" + element2.address);

    });
});
