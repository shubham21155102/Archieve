# System Design

# **What is System**?

- Architecture or Collection of technologies serves a certain set of users to fullfill a certain set of requirements
- Collection of Components that serves a certain set of users to fulfill a certain set of requirements

```mermaid
graph LR;
subgraph A[System]
end
F(Architecture or <br/>Collection of technologies)--serves-->B[set of users]--to fulfill-->C[set of requirements]
```

**Computing Systems**

```mermaid
graph LR;
X[System]
Servers-->X
Databases-->X
Caches -->X
Applications-->X
A[Message Queues]-->X
X-->NF
X-->WA
X-->FB
X-->TW
```

# **What is Design**

- understanding the user requirements and selecting the components ,modules and software technologies,how they are going to be interact with each other to fullfill the requirements

# **System Design**

- Understanding the user requirements and selecting the components ,modules and software technologies,how they are going to be interact with each other to fullfill the requirements

# **Why System Design**

- To handle the scale
- To handle the complexity
- To handle the reliability
- To handle the availability
- To handle the performance
- To handle the security
- To handle the maintainability
- To handle the cost
- To handle the time to market
- To handle the user experience
- To handle the user requirements

# **How to do System Design**

- Understand the user requirements
- Understand the scale
- Understand the complexity
- Understand the reliability
- Understand the availability
- Understand the performance
- Understand the security
- Understand the maintainability
- Understand the cost

# **Components of System Design**

- Components
- Modules
- Software Technologies
- Hardware Technologies
- Network Technologies
- Storage Technologies

# **What is System Design**

- Process of designing the element of a system (app,website,web app) such as **Architectures**,**Modules** and **Components** ,the different **Interfaces** of those components and the **Data** that goes through the system.

# **Types**

```mermaid
graph TD;
A[System Design]-->B[HLD <br>High Level Design]
A-->C[LLD<br>Low Level Design]
subgraph HLD
X[Describes the main components that would be<br>developed for the resulting project <br> <br> The system architecture details,database design<br>services and processes the relationship between<br>various modules and features.]
end
subgraph LLD
Y[Describes the design of each elements mentioned<br>in the HLD of the system.Classes,Interfaces,<br>relationship between different classes and actual<br>logic of the various components]
end
```

# **Architecture**

- Internal Design Details for buliding the applications

```mermaid
graph
A[Types of Architecture]-->B[Monolithic]
A-->C[MicroServices]
```

```mermaid
graph TD;
subgraph Monolithic
a[Frontend]-->A
b[Backend]-->A
c[Database]-->A
A[System]
end
subgraph Microservices
a1[Frontend]-->X[System 1]
b1[Backend]-->Y[System 2]
c1[Database]-->Z[System 3]
end
```

## Monolithic Architecture

- Single Unit
- Single Code Base
- Single Deployment
- Single Database
- Single Unit Testing
- Single Unit of Scaling
- Single Unit of Failure
- Single Unit of Maintainance

## Advantages of Monolithic Architecture

- Single Unit of Deployment
- Single Unit of Scaling
- Integration testing is easy
- Esier to secure
- Fewer Network Calls
- Easy to deploy
- Less Confusion

## Disadvantages of Monolithic Architecture

- Single Unit of Failure can bring down the entire system
- Single module update requires the entire system to be deployed
- Any change in single module's programming language requires the entire system to be deployed
- Single Database so more chances of data corruption or more calls to database

## Distributed System/Microservices Architecture

- collection of multiple individual services that communicate with each other over the network to achieve a common goal

```mermaid
graph TD;
subgraph Microservices
a1[Frontend]-->X[System 1]
b1[Backend]-->Y[System 2]
c1[Database]-->Z[System 3]
a2[Frontend]-->W[System 4]
b2[Backend]-->V[System 5]
c2[Database]-->U[System 6]
a3[Frontend]-->T[System 7]
b3[Backend]-->S[System 8]
c3[Database]-->R[System 9]
X-->Y
Y-->Z
Z-->W
W-->V
V-->U
U-->T
T-->S
S-->R
R-->X
end
```

- **If any of the system fails then  the entire system will not fail**
- **It will jump to next system/replica**

```mermaid
graph TD;
subgraph Microservices
a1[Replica]-->X[System 1]
b1[Replica]-->Y[System 2]
c1[Replica]-->Z[System 3]
a2[Replica]-->W[System 4]
b2[Replica]-->V[System 5]
c2[Replica]-->U[System 6]
a3[Replica]-->T[System 7]
b3[Replica]-->S[System 8]
c3[Replica]-->R[System 9]
X-->Y
Y-->Z
Z-->W
W-->V
V-->U
c2-->T
T-->S
S-->R
R-->X
end
```

### Advantages of Microservices Architecture

- Easy to scale
- No single point of failure

### Disadvantages of Microservices Architecture

- Complex
- Management of multiple services requires more resources
- Integration testing is difficult
- Difficult to secure
- More Network Calls
- Message may be lost in b/w nodes/services

# Latency

- Time taken to send a message from one point to another point

```mermaid
graph LR;
User--t1-->Server
Server--t2-->User
Server--t3:Computation-->Server
subgraph Latency
A[t1+t2+t3]
B[network delay<br>+<br>computational delay]
end
```

Monolithic<<Distrubuted :Latency

## Methods to reduce Latency

- Caching
  - Caching is the process of storing some data in the cache on the server. The cache is a temporary storage component area where the data is stored so that in future, data can be served faster rather than searching from the original location.
- CDN
  - CDNs are geographically distributed network of proxy servers and their data centers are spread across the globe to provide high availability and performance by distributing the service spatially relative to end users.

```js
function getName(userId){
.........we are getting this after 1000 lines of code.....
}
```

```js
function getName(userId="abc"){
if(userId==="abc"){
return [...results];
}
......... 1000 lines of code.....
}
```

- Upgrading the hardware

# Throughput

- Volume of data that can be handled by the system in a given time
- Amount of data transmitted per unit of time .
- Process rate flow
- Measured in bits per second
- Throughput is the number of such actions executed or results produced per unit of time.
- Distributed System has more throughput than Monolithic System because of multiple replicas

## Causes of Low Throughput

- Network Congestion
- Slow Network
- Latency
- Protocol Overhead
- Slow Server
- Slow Database

## Methods to increase Throughput

- Caching
- CDN
- Load Balancer
- Upgrading the hardware
- Use distributed system

# Availability

- The probability that a system will work as expected when required during the period of a mission.
- Goggle has 99.99% availability
- 99.99% availability means 52.56 minutes of downtime per year
- 99.999% availability means 5.26 minutes of downtime per year
- 99.9999% availability means 31.5 seconds of downtime per year
- 99.99999% availability means 3.15 seconds of downtime per year
- 99.999999% availability means 0.315 seconds of downtime per year
- In distributed system if any of the system fails then the entire system will not fail
- Availability of distributed system is more than monolithic system because of multiple replicas

## Causes of Low Availability

- Single point of failure
- Network Congestion
- Slow Network
- Latency
- Monoilithic System

## Methods to increase Availability

- Replication
- Redundancy
  - Each nodes are synchronized with each other
- Distributed System

# Consistency

- When a user updates a data then the user should get the updated data

```mermaid
graph TD;
subgraph Delhi
A[Ticket1<br>booked]
B[Ticket2]
C[Ticket3]
end
subgraph Pune
X[Ticket1<br>booked]
Y[Ticket2]
Z[Ticket3]
end
subgraph Status
T[Data should be updated<br> on change on any loaction's data]
end
```

- Consistency in monolithic system is easy
- Consistency in distributed system is difficult
- Because of multiple replicas, users are getting different servers for their use

## Types of Consistency

| Strong Consistency                                                                                          | Eventual Consistency                                                                                             | Weak Consistency                                                                         |
| ----------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------- |
| when the system doesn't allow<br />read operation until the data <br />is written to <br />all the replicas | when the system allows read<br />operation <br />even if the data is not written <br />to <br />all the replicas | Not need to update all<br />the replicas <br />it depends upon the<br />business logics |
| Example: Ticket Booking                                                                                     | Example: Social media post<br />Update                                                                           |                                                                                          |
# CAP Theorem
- C Consistency
- A Availability
- P Partition Tolerance:
  - One server is down but the system is still working using replicas
- CAP Theorem says that we can only have two of the three properties at a time and compromise on the third one
- CAP Theorem is applicable for distributed system
- In banking system we compromise during update
- In social media we compromise consistency
- CP/AP Only 
- Blog Website - AP
- Multiplayer Game - CP
- Stock Market - CP
- Banking System - CP
- Social Media - AP
- Ticket Booking - CP
- Video Streaming - AP
# Lamport Logical Clock

