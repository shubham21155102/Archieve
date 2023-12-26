```mermaid
graph TD;
A("<img src='./nodejs.png'; width='100%' />")
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
A("<img src='./v8.png'; width='30' />" <br> V8 Engine)-->B[Node js]
C("<img src='./libuv.png'; width='30' />" <br> libuv)-->B
```
