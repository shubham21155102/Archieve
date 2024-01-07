const grpc = require("@grpc/grpc-js");
const protoLoader = require("@grpc/proto-loader");

const packageDef = protoLoader.loadSync("calculator.proto");
const grpcObject = grpc.loadPackageDefinition(packageDef);
const calculatorPackage = grpcObject.Calculator;

function add(call, callback) {
    timeI=Date.now();
    console.log("add invoked", call.request);
    const result = call.request.a + call.request.b;
    console.log("result", result);
    timeF=Date.now();
    console.log("time",timeF-timeI);
    callback(null, { value: result });
}

function sub(call, callback) {
    timeI=Date.now();
    console.log("sub invoked", call.request);
    const result = call.request.a - call.request.b;
    console.log("result", result);
    timeF=Date.now();
    console.log("time",timeF-timeI);
    callback(null, { value: result });
}
function mul(call, callback) {
    timeI=Date.now();
    console.log("mul invoked", call.request);
    const result = call.request.a * call.request.b;
    console.log("result", result);
    timeF=Date.now();
    console.log("time",timeF-timeI);
    callback(null, { value: result });
}
function div(call, callback) {
    timeI=Date.now();
    console.log("div invoked", call.request);
    const result = call.request.a / call.request.b;
    console.log("result", result);
    timeF=Date.now();
    console.log("time",timeF-timeI);
    callback(null, { value: result });
}


function main() {
    const address = "127.0.0.1:50051";
    const server = new grpc.Server();
    server.addService(calculatorPackage.service, { add: add, sub: sub, mul: mul, div: div });

    server.bindAsync(address, grpc.ServerCredentials.createInsecure(), (err, port) => {
        if (err) {
            console.error("Server bind failed:", err);
            return;
        }
        server.start();
        console.log("Server running at grpc://" + address);
    });
}
main();
