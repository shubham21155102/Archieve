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
    - If switch fails total network loss
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
  - choose a congestion free path through which the data packet will travel
  - receive data packet from sender analyse it and forward data packet to receiver by choosing congestion free path.
  - Uses both LAN and WAN
  - Advantages
    - Provides connection b/w two diff devices
    - congestionless
    - transmission rate very high
    - provides both wire and wireless facility
  - Disadvantages
    - more expension compared to others
    - complex to maintain
    - security issue
    - only works with routable protocol
  - ```mermaid
    graph LR;
    C[Computer 1]-->A
    D[Computer 2]-->A
    A-->E[Computer 3]
    A[HUB]-->B[ROUTER]
    A-->F[Computer 4]
    B--Traffic:1:less-->AA[so go]-->G[Router]
    B--Traffic:1,2,3,4-->G
    B--Traffic:1,2,3,4,5-->G
    I-->H[Computer 1]
    G-->I[HUB]
    I-->J[Computer 2]
    I-->K[Computer 4]
    I-->L[Computer 5]
    ```
- **REPEATER**

  - Boostup the weeken signals
  - Used in wired and wireless both
  - Advantages
    - Used to regenerate the weak signals
    - Cheaper
    - ability to extend the length of signal
    - increase /maintain the signal performance
  - Disadvantages
    - No of repeater too much required for some distances
    - unable to connect dissimilar type of N/W(Analog/Digital)
    - Can't reduce network traffic
- **BRIDGE**

  - Used to separate LAN in to number of 	Sections
  - Oprates both physical as well as data link layer of OSI model
  - Advantages:
    - Network extending
    - broadcast the data of each node like **HUB** and **REPEATER**
    - Collisions can be reduced easily
    - more Intelligent
  - Disadvantages
    - Doesn't estabish connection b/w two diff devices
    - epensives
    - transmission rate less than repeater
    - Non reversible(message sent can't be stopped)
  - ```mermaid
    graph LR;
    A[HUB] --> B[BRIDGE] --> C[HUB]
        subgraph X[Noted Data by Bridge]
        AY[BRIDGE]-->AA
        AY-->BB
        AA[MAC Addr.]
        BB[PORT No.]
        AA-->AX[19.63.373.8]
        AA-->BX[19.63.373.85]
        BB-->3000
        BB-->80

        end
    ```
- **GATEWAY**

  - Used to connect two difference type of devices(n/w)
  - allow us to send and receive data through the internet even it is LAN network
  - working same as **SWITCH**
  - Advantages:
    - Connect two networks of different protocol
    - operates all 7 layers of **OSI** model
    - can't access internet without a gateway
    - security
  - Disadvantages
    - expensive
    - data transmission rate slower
    - difficult to maintain and complex to use
    - less intelligent
  - operates all 7 layer of OSI Model
    ```mermaid
    graph LR;
    A[WAN SERVER]--d1:Gateway-->B[GATEWAY/SWITCH]
    B--d1-->C[G1]
    B--d2:Switch-->D[G2]
    B-->E[G3]
    C-->P11
    C-->P21
    D--d2-->P12
    D--d2-->P22
    E-->P13
    E-->P23
    P11--need outside data d1:Gateway-->Computer1
    P21-->Computer2
    P12--need d2 from c4-->Computer3
    P22--d2-->Computer4
    P13-->Computer5
    P23-->Computer6
    ```
- **NIC**

  - NIC:Network Interface Card
  - without NIC impossible to connect device with network/internet
  - Two Types:
    - Internal NIC
    - External NIC
  - INIC:MotherBoard has a slot for n/w card where it can be inserted
  - RJ45 n/w cable required in INIC
  - ENIC:
    - Wireless
    - USB Cable
- **MODEM**

  - Modulator & Demodulator
  - Placed b/w computer and telephone line
  - Modulator : Digital(0,1) to Analog(curvy)
  - Allow computer to connect internet
  - DeModulator:Analog(curvy) to Digital(0,1)
    ```mermaid
    graph LR;
    Sender-->Modulator--d to a-->Demodulator--a to d-->Receiver
    ```

## Network Topology

- Physical arrangement of of the computer system/node which is connected to each other via communiation medium
- **BUS TOPOLOGY**
- **STAR TOPOLOGY**
- **RING TOPOLOGY**
- **MESH TOPOLOGY**
- **HYBRID TOPOLOGY**
- **TREE TOPOLOGY**
- **BUS TOPOLOGY:**

  - One long wire act as single communcation channel for all PC
  - Advantages
    - Single wire
    - any malicious node can be detached
    - less expensive
    - broadcasting can be done
    - easy to maintain
  - Disadvantage
    - Cable fail cause all to disconnect
    - due to broadcasting messages are not secure
    - cable length limited
    - time consuming in communication
    - data transmission only in one direction
  - ```mermaid
    graph LR;
    C1-->Wire
    C2-->Wire
    Wire-Start-->Wire
    C3-->Wire
    C4-->Wire
    Wire-->C5
    Wire-->C6
    Wire-->Wire-End
    Wire-->C7
    Wire-->C8
    ```
- **RING TOPOLOGY**

  - Advatnages:
    - Strong connection
    - Broadcast
    - Bidirectional
    - transmission rate very high
  - Disadvantages
    - Very difficult to add new network
    - if we want to send data not to adjacent that will cause unnecessary data transmission
    - single point of failure cause complete loss
    - Can't send private message

  ```mermaid
  graph LR;
  C1-->C2-->C3-->C1
  ```
- **STAR TOPOLOGY**

  - All nodes are connected to a central device called **HUB**
  - Advantages:

    - Broadcast
    - less cable
    - less expensive
    - easy to connect new node without affecting any one
    - single point failure not affect other
  - Disadvantages

    - must require a n/w device like switch hub etc
    - if two networks want to share data then it only be possible via hub
    - can't send private data
    - if hub fail then total loss

    ```mermaid
    graph LR;
    C1-->HUB
    C2-->HUB
    HUB-->C3
    HUB-->C4
    ```
- **MESH TOPOLOGY**

  - Each computer is directly connected with each other
  - Advantages
    - Very good topology to send private messages
    - each connected with each other so point to point connection
    - single failure can't affect all
    - multiple devices can send and receive data simultaneously
  - Disadvantages
    - Very difficult to add new node
    - if any one fail then we will not able to send or receive to or from failed device
  - ```mermaid
    graph LR;
    A-->B 
    A-->C
    A-->D
    A-->E
    B-->C
    B-->D
    B-->E
    C-->D
    C-->E
    D-->E
    ```
- **HYBRID TOPOLOGY**

  ```mermaid
  graph LR;
  MESH-->A[Computer]
  RING-->A
  STAR-->A
  BUSH-->A
  ```
- **TREE TOPOLOGY**
  - Combination of **STAR** and **BUS** topology
  - all the nodes are connected to a central device called **HUB**
  - **HUB** is connected to another **HUB** via cable
  - all the nodes are connected like branch of a tree
  - Advantages
    - Easy to extend
    - Easy to maintain
    - Easy to detect fault
    - Easy to add new node
  - Disadvantages
    - If root fail then total network fail
    - If cable fail then total network fail
    - If hub fail then total network fail
    - If any node fail then total network fail
   ```mermaid
    graph LR;
    A[Computer]-->B[Computer]
    B--BUS-->C
    C--BUS-->D
    A-->C[Computer]
    A-->D[Computer]
    B-->E[Computer]
    B-->F[Computer]
    C-->G[Computer]
    C-->H[Computer]
    D-->I[Computer]
    D-->J[Computer]
    E-->K[Computer]
    E-->L[Computer]
    F-->M[Computer]
    F-->N[Computer]
    G-->O[Computer]
    G-->P[Computer]
    H-->Q[Computer]
    H-->R[Computer]
    I-->S[Computer]
    I-->T[Computer]
    J-->U[Computer]
    J-->V[Computer]
    K-->W[Computer]
    K-->X[Computer]
    L-->Y[Computer]
    L-->Z[Computer]
    ```
    ```mermaid
    graph LR;
    A[Computer]-->B[Computer]
    A-->C[Computer]
    A-->D[Computer]
    B-->E[Computer]
    B-->F[Computer]
    C-->G[Computer]
    C-->H[Computer]
    D-->I[Computer]
    D-->J[Computer]
    E-->K[Computer]
    E-->L[Computer]
    F-->M[Computer]
    F-->N[Computer]
    G-->O[Computer]
    G-->P[Computer]
    H-->Q[Computer]
    H-->R[Computer]
    I-->S[Computer]
    I-->T[Computer]
    J-->U[Computer]
    J-->V[Computer]
    K-->W[Computer]
    K-->X[Computer]
    L-->Y[Computer]
    L-->Z[Computer]
    ```