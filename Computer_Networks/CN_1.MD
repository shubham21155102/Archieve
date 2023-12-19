## Network Protocol

- Set of rules used in digital communication to connect network devices and exchange information b/w them
  ```mermaid
  graph LR;
  A-->B
  B-->A
  A--Some set of rules for connection -->B
  ```

## Types

- **TCP/IP**
  - TCP:**Transmission Control Protocol**
  - Data transfer
  - Base Protocol
  - IP: Internet Protocol

    ```mermaid
    graph LR;
    A>A]--Connect<br/>TCP-->B[(B)]
    B--Share<br/>IP-->A
    ```
- **HTTP**
  - **Hyper Text Transfer Protocol**
  - **Application Layer**
  - **Web**
  - **WWW**
  - **TCP/IP**
  - **Port: 80**
  - **Request/Response**
  - **Stateless**
  - **Connectionless**
  - **Unencrypted**
  - **HTTP/1.1**
  - **HTTP/2**
  - **HTTP/3**
- **HTTPS**
  - **Hyper Text Transfer Protocol Secure**
  - **Application Layer**
  - **Web**
  - **WWW**
  - **TCP/IP**
  - **Port: 443**
  - **Request/Response**
  - **Stateless**
  - **Connectionless**
  - **Encrypted**
  - **HTTP/1.1**
  - **HTTP/2**
  - **HTTP/3**
- **FTP**
  - **File Transfer Protocol**
  - **Application Layer**
  - **TCP/IP**
  - **Port: 20, 21**
  - **Request/Response**
  - **Stateless**
  - **Connectionless**
  - **Unencrypted**
  - **FTP**
  - **FTPS**
  - **SFTP**
- **SMTP**
  - **Simple Mail Transfer Protocol**
  - **Application Layer**
  - **TCP/IP**
  - **Port: 25**
  - **Request/Response**
  - **Stateless**
  - **Connectionless**
  - **Unencrypted**
  - **SMTP**
  - **SMTPS**
  - **STARTTLS**
- **POP**
  - **Post Office Protocol**
  - **Application Layer**
  - **TCP/IP**
  - **Port: 110**
  - **Request/Response**
  - **Stateless**
  - **Connectionless**
  - **Unencrypted**
  - **POP**
  - **POP3**
  - **POP3S**
- **IMAP**
  - **Internet Message Access Protocol**
  - **Application Layer**
  - **TCP/IP**
  - **Port: 143**
  - **Request/Response**
  - **Stateless**
  - **Connectionless**
  - **Unencrypted**
  - **IMAP**
  - **IMAP3**
  - **IMAP3S**
- **UDP**
  - **User Datagram Protocol**
  - **Connectionless**
  - **Unreliable**
  - **No error checking**
  - **No flow control**
  - **No congestion control**
  - **No sequencing**
  - **No ACK**
  - **No handshake**
  - **No connection**
  - **No state**
  - **No guarantee**
  - **No guarantee of delivery**
  - **No guarantee of order**
  - **No guarantee of duplicate protection**
  - **No guarantee of integrity**
  - **No guarantee of bandwidth**
  - **No guarantee of latency**
  - **No guarantee of jitter**
  - **No guarantee of security**
  - **No guarantee of privacy**
  - **No guarantee of reliability**
  - **No guarantee of availability**
  - **No guarantee of scalability**
  - **No guarantee of maintainability**
  - **No guarantee of interoperability**
  - **No guarantee of portability**
  - **No guarantee of extensibility**
  - **No guarantee of usability**
  - **No guarantee of testability**
  - **No guarantee of reusability**
  - **No guarantee of readability**
  - **No guarantee of writability**
  - **No guarantee of modifiability**
  - **No guarantee of understandability**
  - **No guarantee of traceability**
  - **No guarantee of adaptability**
  - **No guarantee of flexibility**
  - **No guarantee of robustness**
  - **No guarantee of resilience**
  - **No guarantee of reliability**
  - **No guarantee of availability**
  - **No guarantee of security**
  - **No guarantee of safety**
  - **No guarantee of maintainability**
  - **No guarantee of portability**
  - **No guarantee of interoperability**
  - **No guarantee of usability**
  - **No guarantee of testability**
  - **No guarantee of reusability**
  - **No guarantee of readability**
  - **No guarantee of writability**
  - **No guarantee of modifiability**
  - **No guarantee of understandability**
  - **No guarantee of traceability**
  - **No guarantee of adaptability**
  - **No guarantee of flexibility**
  - **No guarantee of robustness**
  - **No guarantee of resilience**
  - **No guarantee of reliability**
  - **No guarantee of availability**
- **PPP**
  - **Point-to-Point Protocol**
  - **Connection-oriented**
  - **Reliable**
  - **Error checking**
  - **Flow control**
  - **Congestion control**
  - **Sequencing**
  - **ACK**
  - **Handshake**
  - **Connection**
  - **State**
  - **Guarantee**
  - **Guarantee of delivery**
  - **Guarantee of order**
  - **Guarantee of duplicate protection**
  - **Guarantee of integrity**
  - **Guarantee of bandwidth**
  - **Guarantee of latency**
  - **Guarantee of jitter**
  - **Guarantee of security**
  - **Guarantee of privacy**
  - **Guarantee of reliability**
  - **Guarantee of availability**
  - **Guarantee of scalability**
  - **Guarantee of maintainability**
  - **Guarantee of interoperability**
  - **Guarantee of portability**
  - **Guarantee of extensibility**
  - **Guarantee of usability**
  - **Guarantee of testability**
  - **Guarantee of reusability**
  - **Guarantee of readability**
  - **Guarantee of writability**
  - **Guarantee of modifiability**
  - **Guarantee of understandability**
  - **Guarantee of traceability**
  - **Guarantee of adaptability**
  - **Guarantee of flexibility**
  - **Guarantee of robustness**
  - **Guarantee of resilience**
  - **Guarantee of reliability**
  - **Guarantee of availability**
  - **Guarantee of security**
  - **Guarantee of safety**
  - **Guarantee of maintainability**
  - **Guarantee of portability**
  - **Guarantee of interoperability**
  - **Guarantee of usability**
  - **Guarantee of testability**
  - **Guarantee of reusability**
  - **Guarantee of readability**
  - **Guarantee of writability**
  - **Guarantee of modifiability**
  - **Guarantee of understandability**
  - **Guarantee of traceability**
  - **Guarantee of adaptability**

## TCP/IP

- TCP is used to transfer data over the internet
- TCP divides the data in to small packets and send it to destination through network
- IP used for addressing through which data reaches the final destination

## HTTP

- HTTP is a protocol which is used to transfer data over the web
- HTTP is a stateless protocol
- HTTP is a connectionless protocol
- used in address of web browser before of www
- if we type www.google.com in browser then it will send a request to google server and google server will send a response to browser

## FTP

- FTP is a protocol which is used to transfer files over the internet
- FTP is a connection oriented protocol
- Uses TCP/IP for data transfer
- FTP uses two ports for data transfer
  - 20: Data transfer
  - 21: Control
- FTP uses two modes for data transfer
  - Active mode
  - Passive mode
- FTP uses two types of connections
  - Control connection
  - Data connection
- FTP uses two types of authentication
  - Anonymous
  - Authenticated
- FTP uses two types of data transfer
  - ASCII
  - Binary
- Client requests file from website
- Server sends file to client

## SMTP
- SMTP is a protocol which is used to send emails over the internet
- SMTP is a connection oriented protocol
- uses TCP/IP for data transfer
- There are two more protocols which are used to receive emails
  - POP
  - IMAP
- SMTP uses two ports for data transfer
    - 25: Data transfer
    - 587: Control
## POP
- POP is a protocol which is used to receive emails over the internet
- POP is a connection oriented protocol
- uses TCP/IP for data transfer and helps **SMTP** from end to end communication
- POP uses two ports for data transfer
    - 110: Data transfer
    - 995: Control  
## IMAP
- IMAP is a protocol which is used to receive emails over the internet
- IMAP is a connection oriented protocol
- uses TCP/IP for data transfer
- IMAP uses two ports for data transfer
- actually a mail box which is actually an improvement over POP
- by using imap main advantage is that we can retrieve our deleted emails from server
    - 143: Data transfer
    - 993: Control
## UDP
- UDP is a protocol which is used to transfer data over the internet
- UDP is a connectionless protocol
- UDP is a unreliable protocol
- UDP is a stateless protocol
- UDP is a unencrypted protocol
- UDP is a faster than TCP
