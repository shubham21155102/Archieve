```mermaid
graph TD;
X("<img src='https://raw.githubusercontent.com/shubham21155102/Archieve/main/Backend/nodejs.png'; width='100%'/>")
```

# What is Node JS

- Runtime environment
- Not a frame work not a language
- **Node.**  **js is a JavaScript runtime built on top of the V8 JavaScript engine** .
- Work on V8 Engine
- Chrome--> V8 JS Engine
- Mozilla Firefox --> Spider Monkey JS Engine
- Microsoft Edge --> Chakra JS Engine
- Intially js was working on browsers so **Rayn Dahl** used V8 Engine and created a new Runtime Environment called Node.js that can run on our system. Our index.js js file can communicate with our system.

```mermaid
graph TD;
A("<img src='https://raw.githubusercontent.com/shubham21155102/Archieve/main/Backend/v8.png'; width='30' />" <br><br> V8 Engine)-->B[("<img src='https://raw.githubusercontent.com/shubham21155102/Archieve/main/Backend/nodejs.png'; width='100' />"Node js)]
C("<img src='https://raw.githubusercontent.com/shubham21155102/Archieve/main/Backend/libuv.png'; width='50'  />" <br><br> libuv)-->B
```

## Threading

- Node js is single threaded run time environment
- Java Runtime Environment Supports Multi threading
- so let's understanding how node js executes multiple requests simultaneously

```mermaid
graph RL;
A[<strong>Single Threaded</strong><br><br>all will wait until.<br> execution of prev <br> completed or not]
C1--req1-->S[Server]
S--res1<br>3 sec-->C1
C2--req2-->S
S--res2<br>6 sec-->C2
C3--req2-->S
S--res2<br>9 sec-->C3
C4--req2-->S
S--res2<br>9 sec-->C4
```

```mermaid
graph RL
A[<strong>Multi Threaded</strong><br><br>all requests will excute<br> at same time ]
C1
C2
C3
C4
subgraph Server
T1[Thread 1]
T2[Thread 2]
T3[Thread 3]
T4[Thread 4]
end
C1--req-->T1
T1--res<br>3sec-->C1
C2--req-->T2
T2--res<br>3sec-->C2
C3--req-->T3
T3--res<br>3sec-->C3
C4--req-->T4
T4--res<br>3sec-->C4
subgraph Languages
X["<img src='https://raw.githubusercontent.com/shubham21155102/Archieve/main/Backend/java.png'; width='30' /> Java"]
Y("<img src='https://raw.githubusercontent.com/shubham21155102/Archieve/main/Backend/php.png'; width='30' />")
end
```

- But Node js is Single Threaded so how it is fast

```mermaid
graph LR;
C1-->S[(Server)]
C2-->S
C3-->S
c4-->S
subgraph Workers
Req1
Req2
Req3
Req4
end
S-->Req1
S-->Req2
S-->Req3
S-->Req4
subgraph Environment
X("<img src='https://raw.githubusercontent.com/shubham21155102/Archieve/main/Backend/nodejs.png'; width='100' />")
end
```

## Synchronous vs Asynchronous

<img src="https://raw.githubusercontent.com/shubham21155102/Archieve/main/Backend/synasyn.jpg" />

## libuv

- written in c++
- make js asynchronous I/O operations
- Above Async. given by libuv

```js
console.log("Hii")
SetTimeOut(cb)
Promises
SetTimeOut
Promises
Promises
Promises
console.log("Bye")
```

```mermaid
graph TD;
A[Call Stack]
B[Node Api's Browser Api]
C[Micro Tasks Queue]
D[Callback Queue]
```

### Step 1

```mermaid
graph LR;
subgraph CallStack
A[Console.log-Hii]
B[Console.log-Bye]
end
```

### Step 2

```mermaid
graph LR;
subgraph Node API's Browser API
S1
P1
S2
P2
P3
P4
end
```

### Step 3

```mermaid
graph TD;
subgraph CallBack Queue
S1 
S2
end
subgraph Micro Tasks Queue
P1
P2 
P3
P4
end
```

### Step 4

```mermaid
graph TD;
subgraph T[CallBack Queue]
S1 
S2
end
subgraph U[Micro Tasks Queue]
P1
P2 
P3
P4
end
subgraph V[Event Loop]
X[now it will decide <br>which will executes first <br>vip Micro Tasks Queue <br>will be choosen first]
P1
P2 
P3
P4
end
```

```js
Output
Hii
Bye
P1
P2
P3
P4
S1
S2
```

## Event Loop and Thread Pool

<img src="https://raw.githubusercontent.com/shubham21155102/Archieve/main/Backend/eventloop.jpg" />

## Streams

- Data Chunk by Chunk

### Node js Streams

- Readable
  - Read Data from a source
- Writable
  - Write Data to a destination
- Duplex
  - Read and Write Data to a destination
- Transform
  - Read Data from a source and write to a destination

### Strems By Node js fs module

#### Readable Stream

```js
const fs = require('fs');
let data = '';
let readStream = fs.createReadStream('input.txt');
readStream.setEncoding('UTF8');
readStream.on('data', function(chunk) {
    data += chunk;
});
readStream.on('end', function() {
    console.log(data);
});
readStream.on('error', function(err) {
    console.log(err.stack);
});
console.log("Program Ended");
```

#### Writable Stream

```js
const fs = require('fs');
let data = 'Simply Easy Learning';
let writeStream = fs.createWriteStream('output.txt');
writeStream.write(data, 'UTF8');
writeStream.end();
writeStream.on('finish', function() {
    console.log("Write completed.");
});
writeStream.on('error', function(err) {
    console.log(err.stack);
});
console.log("Program Ended");
```

#### Piping

- Piping is a mechanism where we provide the output of one stream as the input to another stream.

```js
const fs = require('fs');
let readStream = fs.createReadStream('input.txt');
let writeStream = fs.createWriteStream('output.txt');
readStream.pipe(writeStream);
console.log("Program Ended");
```

#### Chaining

- Chaining is a mechanism to connect the output of one stream to another stream and create a chain of multiple stream operations.

```js
const fs = require('fs');
let zlib = require('zlib');
const gzip = zlib.createGzip();
var readStream = fs.createReadStream('input.txt');
var writeStream = fs.createWriteStream('input.txt.gz');
readStream.pipe(gzip).pipe(writeStream);
console.log("File Compressed.");
```

# Process Model of Node JS

```mermaid
graph LR;
C[Client]--HTTP-->S[Node js Server]
C--HTTP-->S
C--HTTP-->S
C--HTTP-->S
C--HTTP-->S
C--HTTP-->S
subgraph Workers
X[R1 <br> for req1]
R2
R3
R4
R5
end
S-->R1
S-->R2
S-->R3
S-->R4
S-->R5
```

# Globals

- Def: Global objects are global in nature and they are available in all modules. We do not need to include these objects in our application, rather we can use them directly. These objects are modules, functions, strings and object itself as explained below.

## When to use Node js and when not to use Node js

- Node js is not good for CPU intensive applications
- Node js is good for I/O intensive applications
- Node js is not good for heavy computation
- Node js is good for real time applications
- in Chat Application Node js is good
- in Video Encoding Node js is not good
- in Image Processing Node js is not good
- in Machine Learning Node js is not good
- in Data Science Node js is not good
- in Web Scraping Node js is good
- in Web Crawling Node js is good
- in Web Server Node js is good
- in Web Socket Node js is good
- in Micro Services Node js is good
- in Rest Api Node js is good
- in CRUD Application Node js is good
- in Single Page Application Node js is good
- in Multi Page Application Node js is good
- in Web Application Node js is good
- in Desktop Application Node js is good
- in Mobile Application Node js is good
- in IOT Application Node js is good
- in Embedded System Node js is good

## setImmediate vs setTimeout vs process.nextTick

```js
console.log("Start");
setTimeout(() => {
    console.log("Set Timeout");
}, 0);
setImmediate(() => {
    console.log("Set Immediate");
});
process.nextTick(() => {
    console.log("Process Next Tick");
});
console.log("End");
```

```js
Output
Start
End
Process Next Tick
Set Timeout
Set Immediate
```

- setImmediate --> Check Handelers/ Queue
- setTimeout --> timer Queue

# Child Process Module

- Def: Child processes always have three streams child.stdin, child.stdout, and child.stderr which may be shared with the stdio streams of the parent process.
- Basically we can run any command of command line in our system using child process module
- We used to integrate languages like python, java, c++ with node js using child process module

```js
const cp=require("child_process");
cp.execSync("mkdir hello");
```

```js
const cp=require("child_process");
cp.execSync("start chrome");
```

```js
const cp=require("child_process");
cp.execSync("start chrome https://www.google.com");
```

```js
const cp=require("child_process");
cp.execSync("start chrome https://www.google.com");
```

# Event Emitter

- Def: Node.js core API is built around an idiomatic asynchronous event-driven architecture in which certain kinds of objects (called "emitters") emit named events that cause Function objects ("listeners") to be called.
- Node js is event driven architecture
- Node js is single threaded
- Node js is non blocking I/O

```js
const EventEmitter=require("events");
const event=new EventEmitter();
event.on("sayMyName",()=>{
    console.log("Your name is Shubham");
});
event.on("sayMyName",()=>{
    console.log("Your name is Shubham Patel");
});
event.on("sayMyName",()=>{
    console.log("Your name is Shubham Patel and you are a web developer");
});
event.emit("sayMyName");
```

```js
Output
Your name is Shubham
Your name is Shubham Patel
Your name is Shubham Patel and you are a web developer
```

# PolyFill of Event Emitter

```js
  class EventEmitter {
    constructor() {
      this.events = {};
    }
    on(eventName, callback) {
      if (this.events[eventName]) {
        this.events[eventName].push(callback);
      } else {
        this.events[eventName] = [callback];
      }
    }
    emit(eventName) {
      if (this.events[eventName]) {
        this.events[eventName].forEach((callback) => {
          callback();
        });
      }
    }
  }
  module.exports = EventEmitter;
```
