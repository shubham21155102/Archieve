## Computer Networks

- A group of computers connected for the purpose of sharing their resources is called computer networks.
- First Computer Network:ARPANET
- ARPANET:Advanced Research Project Agency Network

## Characteristics

- Resource Sharing
- Communication Speed
- Backup
- Scalability
- Reliability
- S/W & H/W sharing
- Security

## Network Devices

- Modem
- HUB
- Switch
- Gateway
- BRIDEGE
- Router
- Repeater

## Network Types

- PAN : Personal Area Network

  - Range: <10 M
  - Used for personal use
  - Home
    ```mermaid
    graph LR;
    A[Bluetooth]-->B[Computer]
    C[Laptop]-->B
    B-->D[Speaker]
    B-->E[Wifi]
    ```
- LAN : Local Area Network

  - Range <150 m
  - Use:Office Building
    ```mermaid
    graph LR;
    A[Computer 1]-->B[Computer 3]
    C[Computer 2]-->B
    D[Computer 4]-->A
    E[Computer 5]-->B
    E-->A
    D-->B
    C-->A
    ```
- MAN :Metropolitan Area Network

  - Range <50 km
  - Used within a city
  - EX:Connection of LAN

    ```mermaid
    graph TD;
    A[College LAN]-->F
    B[School Lan]-->F
    C[Hospital Lan]-->F
    D[Temple LAN]-->F
    E[HOME LAN]-->F
    F[MAN]
    ```
- WAN: Wide Area Network

  - Range not fixed
  - used for countries or all around the world
    ```mermaid
    graph TD;
    A[LAN 1]-->F
    B[MAN 1]-->F
    C[LAN 2]-->F
    D[LAN 3]-->F
    E[MAN 2]-->F
    F[WAN]
    ```

  ## Advantages
- Open to everyone
- file sharing
- open to everyone
- security
- backup storage
- easy to add new device

## Disadvantages

- N/W device required
- virus attack
- required handler
- high speed internet required
- server

## Devices

- **HUB**

  - Network device that is used to connect multiple computers in a network
  - All the infomation send to HUB are sent to each port of every devices
  - less expensive ,less intelligence,less expensive
  - generlly used to connect computers in LAN
  - Advantages:
    - Can broadcast the message
    - less expensive so anyone can use it
    - easy installation
    - robust
  - Dis-Advantages:
    - On HUB failure entire network will fail
    - We can't send private/personal data through hub
    - **HUB** doesn't provide any security
    - can't support full duplex transmission
  - Tranmission mode of **HUB** is Half Duplex
  - Half Duplex:
    - One process at a time (receive or send)
  - ```mermaid
    graph LR;
    A[HUB:PORTS:A+B+C+D ]-->C[Computer 1]
    A-->B[Computer 2]
    D[Computer 3]-->A
    E[Computer 4]-->A
    ```
- **SWITCH:**

  - Connect multiple computers in a network
  - used to send private messages
  - no wastage of data (ie: no broadcasting)
  - Easily identify which device is connected with which port by using MAC Adrresss
  - By this it deliveres messages where we want to send
  - more intelligent than HUB
  - Advantages
    - Generally used to unicast the message
    - provides more security than HUB
    - Provides duplex transmssion mode
    - used to send data packet based on MAC aadress
    - If a node fails then total network will not get distuurbed
  - Disadvantages
    - If sitch fails total network loss
    - expensive
    - Difficult setup
  - ```mermaid
    graph LR;
    A[SWITCH:G1,G2 ]
    X[G1:A]-->C[Computer 1]
    Y[G1:B]-->B[Computer 2]
    Z[G2:E]-->D[Computer 3]
    W[G2:H]-->E[Computer 4]
    T[G1:PORTS:A+B+C+D]-->X
    T-->Y
    U[G2:PORTS:E+F+G+H]-->Z
    U-->W
    A-->T
    A-->U
    ```
- **ROUTER**

  - Work as traffic controller
  -
