```mermaid
graph TD;
A("<img src='https://raw.githubusercontent.com/shubham21155102/Archieve/main/Backend/nodejs.png'; width='100%' />")
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
A("<img src='https://raw.githubusercontent.com/shubham21155102/Archieve/main/Backend/v8.png'; width='30' />" <br> V8 Engine)-->B[Node js]
C("<img src='https://raw.githubusercontent.com/shubham21155102/Archieve/main/Backend/libuv.png'; width='30' />" <br> libuv)-->B
```

## libuv

- written in c++
- make js asynchronous I/O operations

## Threading

- Node js is single threaded run time environment
- Java Runtime Environment Supports Multi threading
- so let's understanding how node js executes multiple requests simultaneously

```mermaid
graph LR;
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
A[<strong>Multi Threaded</strong><br><br>all will excute<br> at same time ]
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
X("<img src='https://raw.githubusercontent.com/shubham21155102/Archieve/main/Backend/java.png'; width='30' />")
Y("<img src='https://raw.githubusercontent.com/shubham21155102/Archieve/main/Backend/php.png'; width='30' />")
end
```
