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

- For Distributed System

<img src="https://raw.githubusercontent.com/shubham21155102/Archieve/main/System_Design/Lambort.jpg"/>

```mermaid
graph LR;
a[Server 1<br>USA Washington DC<br> time:8:23 AM]
b[Server 2<br>India<br> time:6:53 PM]
c[Server 3<br>UK<br> time:1:23 PM]
a-->b-->c-->a
subgraph Events
A[How can we find which event is first occuring]
end
```

# Scalability

```mermaid
graph
A[Scaling]-->B[Horizontal Scaling]
A-->C[Vertical Scaling]
```

## Vertical Scaling

```mermaid
graph LR;
A[Server<br> 25 GB ]-->B[Server <br> 100 GB]
```

### Pros

- Easy Implementation
- Less Power
- Management Easy
- Security

### Cons

- Single Point of failure
- Limitation of storage (After a limit we can not increase the Storage)
- Price (same company's machine equipment add on)

## Horizontal Scaling

### Pros

- No Single Point of failure
- No Limitation of storage
- No Price Isuue we can use less costly machine for less consumotion need where we need that

### Cons

- Security maintainance issue
- Management issue
- More Power Consumption
- Complex Implementation

# Redundancy and Replication

## Redundancy

- Simply duplication of nodes or components so that when a node or component fails the duplicate node is availabe to service

### Types

- **Active Redundancy:**
  - Activite Redundancy is considered when each unit is operating/active and responding to the action.Multiple nodes are connected to a load balancer and each unit recives an equal load
- **Passive Server**
  - Passive Redundancy is considered when each unit is not operating/active and not responding to the action.Multiple nodes are connected to a load balancer and each unit recives an equal load

## Replication

- **Redundancy along with Synchronisation**
- Copy along this sync
- All the data should be copy to all the server
- Used in databases

### Types

- **Active Replication**
  - Active Replication is considered when each unit is operating/active and responding to the action.Multiple nodes are connected to a load balancer and each unit recives an equal load
  - also all will be doing the same work like read and write in case of database
  - All nodes would be master
- **Passive Replication**
  - Passive Replication is considered when each unit is not operating/active and not responding to the action.Multiple nodes are connected to a load balancer and each unit recives an equal load
  - also all will be doing the same work like read and write in case of database
  - One node would be master and other would be slave
  - Master will be doing the write operation and slave will be doing the read operation
  - if instaly we are updating then asynchronisation will be there
  - if we are updating to slave after some scheduled time then asynchronisation will be there

```mermaid
graph LR;
D-->A
A-->D[Server 2]
E[Server 3]-->D
D-->E
E-->A
A-->E
A[Server 1]-->B[Copy 1<br> I am awaking and <br> continuously Copying the data  from server <br> So i am Actively Redundance]
A-->C[Copy 2<br> I am sleeping and <br> not Copying the data  from server <br> So i am Passively Replication]
subgraph Redundancy
X[Active Redundancy]
Y[Passive Redundancy]
end
```

```mermaid
graph LR;
subgraph Active Replication
D-->A
A-->D[Server 2]
E[Server 3]-->D
D-->E
E-->A
A-->E
A[Server 1]-->a[DB 1 <br> Master Node<br> read write simultaneously]
A-->c[DB 2 <br> Master Node<br> read write simultaneously]
A-->d[DB 3 <br> Master Node<br> read write simultaneously]
A-->e[DB 4 <br> Master Node<br> read write simultaneously]
A-->f[DB 5 <br> Master Node<br> read write simultaneously]
a-->c
c-->a
c-->d
d-->c
d-->e
e-->d
e-->f
f-->e
f-->a
a-->f
end
subgraph Passive Replication
D1-->A1
A1-->D1[Server 2]
E1[Server 3]-->D1
D1-->E1
E1-->A1
A1-->E1
A1[Server 1]-->a1[DB 1 <br> Master Node<br> read write simultaneously]
A1-->c1[DB 2 <br> Slave Node<br> read write on permission <br> by Master Node]
A1-->d1[DB 3 <br> Slave Node<br> read write on permission <br> by Master Node]
A1-->e1[DB 4 <br> Slave Node<br> read write on permission <br> by Master Node]
A1-->f1[DB 5 <br> Slave Node<br> read write on permission <br> by Master Node]
a1-->c1
c1-->a1
c1-->d1
d1-->c1
d1-->e1
e1-->d1
e1-->f1
f1-->e1
f1-->a1
a1-->f1
end
subgraph Replication
X[Active Replication ]
Y[Passive Replication]
end
```

# Load Balancer

- Process of efficient distribution of incoming network traffic across all nodes in a distributed system
## NGINX

- Pronounciation :Engine X
- PowerFul Web Server
- Uses non-threaded and event driven structure
- Used as a reverse proxy server, load balancer, mail proxy server, and HTTP cache

**Diagram of Normal HTTP Connection**

```mermaid
   graph LR
    A[Client] -- Normal HTTP Connection --> B[Server]
```

**Diagram of HTTP Connection with VPN**

- Forward Proxy Sever is used to connect to the VPN

```mermaid
   graph LR
    A[Client] -- Normal HTTP Connection --> B[Server]
    A <--> C[Forward Proxy Server]
    C <--> B
```

```mermaid
   graph LR
    A[Client 1] <--> B[Forward Proxy :VPN]
    C[Client 2]<--> B
    D[Client 3]<--> B
    E[Client 4]<-->B
    B<-->F[Server]   
  
```

- Server is not able to identify the client in forward proxy server
  - Forward Proxy Server is used to connect to the VPN

**Connection of NGINX**

```mermaid
   graph LR
    A[Client] -- Normal HTTP Connection --> B[Reverse Proxy S:NGINX]
    B <--> C[Server 1]
    B <--> D[Server 2]
    B <--> E[Server 3]
    B <--> F[Server 4]
  
```

- NGINX is used to connect to the VPN
  - Client is not able to identify the server in NGINX case

```mermaid
graph LR;
A[Client 1]<-->B[NGINX]
C[Client 2]<-->B
D[Client 3]<-->B
E[Client 4]<-->B
F[Client 5]<-->B
G[Client 6]<-->B
H[Client 7]<-->B
B--Request Sending On specific server after decision-->I[Decision Output]
I-->J[Server 1]
I-->K[Server 2]
I-->L[Server 3]
I-->M[Server 4]
I-->N[Server 5]
I-->O[Server 6]
I-->P[Server 7]
I-->Q[Server 8]

```

**More Clearation**

```mermaid
graph LR;
A[Client 1]<-->B[NGINX]
C[Client 2]<-->B
D[Client 3]<-->B
E[Client 4]<-->B
F[Client 5]<-->B
G[Client 6]<-->B
H[Client 7]<-->B
B--/admin-->J[Server 1]
B--/user-->K[Server 2]
B--/admin-->L[Server 3]
B--/settings-->M[Server 4]
B--/all-->N[Server 5]
B--/todo-->O[Server 6]
B--/example-->P[Server 7]
B--/ex-->Q[Server 8]
```

## Contributions

- Can Handle 10000 Concurrent Requests
- Catche HTTP Requests
- Act as Reverse Proxy
- Act as Load Balancer
- Act as an API Gateway(see upper example)
- Serve and Cache Static files like images ,videos etc.
- Handle SSL Certificates
- Load distribution is equal over all the servers
- Health Check of all the servers
- Ensures High Availability, Scalability and Reliability
- NGINX is used by 66% of the world's busiest websites
## When to use Load Balancer
- In distributed system
- In Microservices Architecture
- Not In Monolithic Architecture
## Challenges
- Single Point of Failure
## Solutions
- Multiple Load Balancer
- Passive Load Balancer
- Active Load Balancer
## Advantages
- Optimized Resource Usage
- Reduced Processing Time
- Better User Experience
- Improved Scalability
- Prevents Overloading of a single server
- Better Security
- Prevents Downtime
- Flexibility
- Redundancy
## Load Balancing Algorithms
- Round Robin(Static) Algorithm
  - Rotation fashion
  - 1st request goes to 1st server
  - 2nd request goes to 2nd server
  - 3rd request goes to 3rd server
  - 4th request goes to 4th server
  - 5th request goes to 1st server
  - 6th request goes to 2nd server
  - 7th request goes to 3rd server
  - 8th request goes to 4th server
  - 9th request goes to 1st server
  - 10th request goes to 2nd server
  - 11th request goes to 3rd server
  - and so on
- Weighted Round Robin(Static) Algorithm
  - similar to Round Robin but servers have different capacity
  - so work will be distributed according to the capacity of the server
- IP Hash Algorithm
  - IP address of the client is used to determine which server receives the request
  - so if the client is same then the server will be same
  - here we hash the ip of user then we generate a number and that number will represent the server
- Source IP Hash(Static) Algorithm
  - similar to IP Hash Algorithm but here we hash the ip of server then we generate a number and that number will represent the server
  - we use ip of both source and destination
- Least Connection(Dynamic) Algorithm
  - server with least connection will be selected
  - if server 1 has 10 connection
  - server 2 has 5 connection
  - server 3 has 3 connection
  - server 4 has 2 connection
  - then server 4 will be selected
- Least Response Time(Dynamic) Algorithm
  - Server will see active connection and response time
  - server with least response time will be selected
  - if server 1 has 10 ms response time
  - server 2 has 5 ms response time
  - server 3 has 3 ms response time
  - server 4 has 2 ms response time
  - then server 4 will be selected

# Caching
## What is caching?
- Caching is the process of storing data in a cache.
- A cache is a temporary storage area.
- Caching is used to speed up data access.
- Caching is used to reduce load on underlying resources.
## Real world example
- I have used caching in my project to reduce the load on the database.
- website link :[FMC Weekend](https://www.fmcweekend.in/)
- I have used caching in the following way:
  - I have used caching to store the data of the users who have registered for the event.
- Their Profile data is stored in the cache.
- When the user logs in, the data is fetched from the cache.
- If the data is not present in the cache, then the data is fetched from the database and stored in the cache.
- This reduces the load on the database.
## Types of caching
- There are two types of caching:
  - **In Memory/Local Cache**
  - **Distributed Cache/Internal Cache**
### In Memory/Local Cache
- In Memory/Local Cache is a cache that is stored in the memory of the server.
- Example:
  - Memcached
### Distributed Cache/Internal Cache
- Distributed Cache/Internal Cache is a cache that is stored in a shared network/memory.
- Example:
  - Redis
## When to use caching?
- Caching should be used when:
  - The data is not updated frequently.
  - The data is not sensitive.
  - The data is not large.
  - static content (images, videos,html,css etc.)
  - Example :
    - Read Intensive in Twitter
    - Read Intensive in Facebook
    - Read Intensive in Instagram
## Types of caching we are storing in our project
- Application Server Cache 
- CDN
## Cache Eviction
- Cache eviction is the process of removing an entry from the cache on a definite time or on a condition.
## Cache Eviction Techniques
- How we are deleting the data from the cache?
- There are following types of cache eviction techniques:
  - **LRU (Least Recently Used) Eviction**
  - **LFU (Least Frequently Used) Eviction**
  - **FIFO (First In First Out) Eviction**
  - **MRU(Most Recently Used) Eviction**
  - **LFU (Least Frequently Used) Eviction**
  - **LIFO (Last In First Out) Eviction**
  - **RR (Random Replacement) Eviction**
### LRU (Least Recently Used) Eviction
- In this technique, the entry which is least recently used is removed from the cache.
- Example:
  - If the cache size is 5 and the cache is full.
  - If we want to add a new entry in the cache, then the entry which is least recently used is removed from the cache.
### LFU (Least Frequently Used) Eviction

- In this technique, the entry which is least frequently used is removed from the cache.
- Example:
  - If the cache size is 5 and the cache is full.
  - If we want to add a new entry in the cache, then the entry which is least frequently used is removed from the cache.
### FIFO (First In First Out) Eviction
- In this technique, the entry which is first inserted in the cache is removed from the cache.
- Example:
  - If the cache size is 5 and the cache is full.
  - If we want to add a new entry in the cache, then the entry which is first inserted in the cache is removed from the cache.
### MRU(Most Recently Used) Eviction
- In this technique, the entry which is most recently used is removed from the cache.
- Example:
  - If the cache size is 5 and the cache is full.
  - If we want to add a new entry in the cache, then the entry which is most recently used is removed from the cache.
### LFU (Least Frequently Used) Eviction
- In this technique, the entry which is least frequently used is removed from the cache.
- Example:
  - If the cache size is 5 and the cache is full.
  - If we want to add a new entry in the cache, then the entry which is least frequently used is removed from the cache.
### LIFO (Last In First Out) Eviction
- In this technique, the entry which is last inserted in the cache is removed from the cache.
- Example:
  - If the cache size is 5 and the cache is full.
  - If we want to add a new entry in the cache, then the entry which is last inserted in the cache is removed from the cache.
### RR (Random Replacement) Eviction
- In this technique, the entry which is randomly selected is removed from the cache.
- Example:
  - If the cache size is 5 and the cache is full.
  - If we want to add a new entry in the cache, then the entry which is randomly selected is removed from the cache.
## Cache Invalidation
- Cache Invalidation is the process of removing an entry from the cache on a definite time or on a condition.
## Cache Invalidation Techniques
- How we are deleting the data from the cache?
- There are following types of cache invalidation techniques:
  - **Time To Live (TTL)**
  - **Write Through**
  - **Write Back**
### Time To Live (TTL)
- In this technique, the entry is removed from the cache after a definite time.
- Example:
  - If the cache size is 5 and the cache is full.
  - If we want to add a new entry in the cache, then the entry which is least recently used is removed from the cache.
### Write Through
- In this technique, the entry is removed from the cache after a definite time.
- Example:
  - If the cache size is 5 and the cache is full.
  - If we want to add a new entry in the cache, then the entry which is least recently used is removed from the cache.
### Write Back
- In this technique, the entry is removed from the cache after a definite time.
- Example:
  - If the cache size is 5 and the cache is full.
  - If we want to add a new entry in the cache, then the entry which is least recently used is removed from the cache.
## Cache Consistency
- Cache Consistency is the process of maintaining the consistency of the data in the cache.
## Cache Consistency Techniques
- How we are maintaining the consistency of the data in the cache?
- There are following types of cache consistency techniques:
  - **Write Through**
  - **Write Back**
### Write Through   
- In this technique, the entry is removed from the cache after a definite time.
- Example:
  - If the cache size is 5 and the cache is full.
  - If we want to add a new entry in the cache, then the entry which is least recently used is removed from the cache.
### Write Back
- In this technique, the entry is removed from the cache after a definite time.
- Example:
  - If the cache size is 5 and the cache is full.
  - If we want to add a new entry in the cache, then the entry which is least recently used is removed from the cache.
# File Based Storage System
## What is File Based Storage System?
- File Based Storage System is a system in which the data is stored in the form of files.
- Example:
  - File System
## When to use File Based Storage System?
- File Based Storage System should be used when:
  - The data is not updated frequently.
  - The data is not sensitive.
  - The data is not large.
  - Example :
    - Read Intensive in Twitter
    - Read Intensive in Facebook
    - Read Intensive in Instagram
## Types of File Based Storage System
- There are two types of File Based Storage System:
  - **Local File System**
  - **Distributed File System**
### Local File System
- Local File System is a file system that is stored in the memory of the server.
- Example:
  - Ext4
### Distributed File System
- Distributed File System is a file system that is stored in a shared network/memory.
- Example:
  - HDFS
## Challenges in File Based Storage System
- Data Redundancy
- Data Consistency
- Data Security
- Slow Data Access

# Database
## RDBMS
- RDBMS stands for Relational Database Management System.
- RDBMS is a database management system that is based on the relational model.
- Stored data in the form of tables.
- Connected data with the help of foreign keys.
- Example:
  - MySQL
  - PostgreSQL
  - Oracle
  - Microsoft SQL Server
### Advantages of RDBMS
- Data Redundancy is reduced.
- Data Consistency is maintained.
- Data Security is maintained.
- Data Access is fast.
- Data Integrity is maintained.
### Disadvantages of RDBMS
- Rigid Schema
- Scaling is difficult(Horizontal Scaling)
- High Cost
- Not suitable for unstructured data
- Vertical Scaling is possible but it is expensive and limited.
## NoSQL
- NoSQL stands for Not Only SQL.
- NoSQL is a database management system that is not based on the relational model.
### Types of NoSQL
- There are four types of NoSQL:
  - **Key Value Store**
    - Generrally used for caching.
    - Example:
      - Redis
      - Memcached
  - **Document Store**
    - Brimgs both RDMS and NoSQL together.
    - Used for storing unstructured data.
    - Example:
      - MongoDB
      - CouchDB
  - **Column Store**
    - Used for storing large amount of data.
    - For Data Management during machine learning.
    - Column Store is a type of NoSQL database that stores data in columns rather than rows.
    - Example:
      - Cassandra
      - HBase
  - **Graph Database**
    - Used for storing data in the form of nodes and edges.
    - Used for storing data in the form of graphs.
    - Google Maps
    - Social Media LinkedIn connection graph
    - Example:
      - Neo4j
      - OrientDB

<img src="https://raw.githubusercontent.com/shubham21155102/Archieve/main/System_Design/cassandra.jpg"/>

## Examples

- Google Maps - Graph DB
- LinkedIn - Graph DB
- Amazon Cart- Key Valued DB :Redis
- Payment :We won't use NoSQL ,  We use SQL DB for consistency

# Polyglot Persistance

- Multiple Databases are used as per requirement in the system

```mermaid
graph TD;
X("<img src='https://raw.githubusercontent.com/shubham21155102/Archieve/main/System_Design/psql.png'; width='50' />")
Y("<img src='https://raw.githubusercontent.com/shubham21155102/Archieve/main/System_Design/cassandral.png'; width='75' />")
Z("<img src='https://raw.githubusercontent.com/shubham21155102/Archieve/main/System_Design/mong.webp'; width='70' />")
W("<img src='https://raw.githubusercontent.com/shubham21155102/Archieve/main/System_Design/redis.png'; width='70' />")
```

```mermaid
graph TD;
A[Ecommerce Platform]-->B[Shopping Cart<br> & <br> Session Data]-->C[Key Valued DB]-->W("<img src='https://raw.githubusercontent.com/shubham21155102/Archieve/main/System_Design/redis.png'; width='70' />")
A-->D[Completed Order]-->E[Document DB]-->Z("<img src='https://raw.githubusercontent.com/shubham21155102/Archieve/main/System_Design/mong.webp'; width='70' />")
A-->F[Inventory <br>&<br>Item Price]-->G[RDBMS<br>Legacy DB]-->X("<img src='https://raw.githubusercontent.com/shubham21155102/Archieve/main/System_Design/psql.png'; width='50' />")
A-->H[Customer <br>Social Graph]-->I[Graph DB]-->CC("<img src='https://raw.githubusercontent.com/shubham21155102/Archieve/main/System_Design/neo4j.svg'; width='80' />")
```
# Normalisation

- Putting data in multiple table to reduce redundancy

# Denormalisation

- Putting data in one table to increase performance

## Benefits of Denormalisation

- Faster reads
- Simpler queries
- Management Convenience
- High availability
- Reduces the network calls
- Reduces the number of joins

## Drawbacks of Denormalisation

- Slower writes
- Redundant data- wastage of space and money
- Increase Complexity
- Data inconsistency
- Difficult to maintain

# Indexing

- Indexing is a way to optimize the performance of a database by minimizing the number of disk accesses required when a query is processed. It is a data structure technique which is used to quickly locate and access the data in a database.

```mermaid
graph LR;
subgraph Students
A[id name age netWorth]
B[1 Ram 12 8000]
C[2 Radha 14 3400]
D[3 Seeta 14 300]
E[4 Ramu 14 3000]
end
subgraph Networth
X[netWorth]
Y[300]
Z[3000]
WW[3400]
W[8000]
end
D-->Y
B-->W
C-->WW
E-->Z
subgraph Indexing
XRT[Now it is optimised <br>here a separate memory<br>is assigned]
end
subgraph DataStructure
XRTR[B-trees structure <br>used to store indexing]
end
```

- Used in Read Intensive Application

# Synchronous Communication

```mermaid
graph LR;
A("<img src='https://raw.githubusercontent.com/shubham21155102/Archieve/main/System_Design/amazon.png'; width='80' />")-->B("<img src='https://raw.githubusercontent.com/shubham21155102/Archieve/main/System_Design/cart.jpeg'; width='80' />")-->C[Synchronous<br>Item in stock<br> or not during order<br>wait or block to check<br>highly consistent]
D("<img src='https://raw.githubusercontent.com/shubham21155102/Archieve/main/System_Design/amazon.png''; width='80' />")-->E("<img src='https://raw.githubusercontent.com/shubham21155102/Archieve/main/System_Design/pay.jpeg'; width='80' />")-->F[Synchronous<br>Payment<br>highly consistent]
G("<img src='https://raw.githubusercontent.com/shubham21155102/Archieve/main/System_Design/amazon.png''; width='80' />")-->H("<img src='https://raw.githubusercontent.com/shubham21155102/Archieve/main/System_Design/notification.png'; width='80' />")-->I[ASynchronous<br>no problem if<br>we receive notification<br> with delay]
```

## Where Asynchronous Communication is necessary

- Computation takes a lot of time
- Scalability of application
- Avoid Cascading Failures

# Message Based Communication

- Client send requests in the form of messages to the server and server send response in the form of messages to the client
- so it is asynchronous communication

## Producer

## Consumer

## Agent

## P2P Model

- Peer to Peer Model
- Email are not sent immediately
- Email are stored in the queue and then sent
- Email are sent in the form of messages
- Email are sent asynchronously

## Public Subscriber Model

- Email are sent to all the subscribers
- Email are sent in the form of messages
- Email are sent asynchronously

## Examples

- Kafka
- RabbitMQ
- ActiveMQ
- Amazon SQS

# Kafka

- Zomato :

  - Live loaction of delivery partner we see
  - life feed we are getting each second of driver location
  - this can not be done using data base because if we are calling database each second our database will go down
  - throughput of database is low
  - throughput of kafka is high
- Kafka has high throughput
- but Kafka's storage is temporary and very low
- DB: throughput low ,storage high, we can query the data

```mermaid
graph LR;
A["<img src='https://raw.githubusercontent.com/shubham21155102/Archieve/main/System_Design/zomato.png''; width='80' />"<br>Zomato<br>producing 1m data per seconds<br><br>Producer]
B["<img src='https://raw.githubusercontent.com/shubham21155102/Archieve/main/System_Design/kafka.png''; width='80' />"<br>Kafka<br>Consuming the datas]
A-->B--Bulk insert after<br> a fixed time-->C["<img src='https://raw.githubusercontent.com/shubham21155102/Archieve/main/System_Design/psql.png''; width='80' />"<br>Kafka<br>Consuming the datas]
subgraph Datas
B-->Speed
B-->Distance
B-->Time
X[1 million datas]
end
```

## Sharding

- Sharding is a type of database partitioning that separates large databases into smaller, faster, more easily managed parts. These smaller parts are called data shards. The word shard means "a small part of a whole."

## Partitioning

- Partitioning is a database design technique that splits large tables into smaller ones. There are several benefits to partitioning data in a large database. Partitioning can make large tables more manageable and scalable, and it can speed up query times when dealing with large tables.

## Difference between Sharding and Partitioning

- We do sharding when we have to scale our database horizontally
- We do partitioning when we have to scale our database vertically
- Sharding is done when we have to scale our database to multiple machines
- Partitioning is done when we have to scale our database to single machine

**We will be doing partitioning in case of Kafka to manage large data because Kafka is singly here and here we can vertically scale the system so Partitioning will be here**

```mermaid
graph LR;
A["<img src='https://raw.githubusercontent.com/shubham21155102/Archieve/main/System_Design/zomato.png''; width='80' />"<br>Producer]
subgraph Kafka Server
B["<img src='https://raw.githubusercontent.com/shubham21155102/Archieve/main/System_Design/kafka.png''; width='80' />"<br> Kafka]
subgraph Partition1
AX[Managing Riders Update]
AXX[Managing Data For USA]
AXY[Managing Data For India]
AX-->AXY
AX-->AXX
end
subgraph Partition2
AY[Managing Restaurent Updates]
AYX[Managing Data For USA]
AYY[Managing Data For India]
AY-->AYY
AY-->AYX
end
end
A-->AX
A-->AY
C[Consumer 1]
D[Consumer 2]
AXX-->C
AYX-->C
AXY-->D
AYY-->D
C--Consistent-->D
D--Consistent-->C
```

```mermaid
graph LR;
subgraph Consumer Groups;
subgraph Topic
A[P1]
B[P2]
C[P3]
D[P4]
end
end
subgraph Consumers
D1[D1]
end
A-->D1
B-->D1
C-->D1
D-->D1
```

```mermaid
graph LR;
subgraph Consumer Groups;
subgraph Topic
A[P1]
B[P2]
C[P3]
D[P4]
end
end
subgraph Consumers
D1[D1]
D2[D2]
end
A-->D1
B-->D1
C-->D2
D-->D2
```

```mermaid
graph LR;
subgraph Consumer Groups;
subgraph Topic
A[P1]
B[P2]
C[P3]
D[P4]
end
end
subgraph Consumers
D1[D1]
D2[D2]
D3[D3]
end
A-->D1
B-->D1
C-->D2
D-->D3
```

```mermaid
graph LR;
subgraph Consumer Groups;
subgraph Topic
A[P1]
B[P2]
C[P3]
D[P4]
end
end
subgraph Consumers
D1[D1]
D2[D2]
D3[D3]
D4[D4]
end
A-->D4
B-->D1
C-->D2
D-->D3
```

```mermaid
graph LR;
subgraph Consumer Groups;
subgraph Topic
A[P1]
B[P2]
C[P3]
D[P4]
end
end
subgraph Consumers Group 1
D1[D1]
D2[D2]
D3[D3]
D4[D4]
D5[D5]
end
A-->D4
B-->D1
C-->D2
D-->D3
subgraph Consumers Group 2
D11[D1]
D21[D2]
end
A-->D11
B-->D11
C-->D21
D-->D21
```

```mermaid
graph TD;
A[Kafka as a]
B[Queue]
C[PUB/SUB]
A-->B
A-->C
B-->D[When No. of <br> Consumers==Producers]
C-->E[When No. of <br> Consumers!=Producers]
```

```mermaid
graph LR;
subgraph Consumer Groups;
subgraph Topic
A[P1]
B[P2]
C[P3]
D[P4]
end
end
subgraph Consumers
D1[D1]
D2[D2]
D3[D3]
D4[D4]
end
A-->D4
B-->D1
C-->D2
D-->D3
subgraph Behaviour
T[Here Kafka will act as Queue]
end
```

```mermaid
graph LR;
subgraph Consumer Groups;
subgraph Topic
A[P1]
B[P2]
C[P3]
D[P4]
end
end
subgraph Consumers Group 1
D1[D1]
D2[D2]
D3[D3]
D4[D4]
D5[D5]
end
A-->D4
B-->D1
C-->D2
D-->D3
subgraph Consumers Group 2
D11[D1]
D21[D2]
end
A-->D11
B-->D11
C-->D21
D-->D21
subgraph Behaviour
T[Here Kafka will act as PUB/SUB]
end
```

## Zookeeper

- Zookeeper is a distributed co-ordination service to manage large set of hosts
- Zookeeper is used to manage Kafka
- Manage Kafka Internally
- Zookeeper is used to manage the broker
- Zookeeper is used to manage the consumer group
# Web Server

- Tools or programs that help keep the web application always up and running
- Just like a computer, a web server has a CPU, memory, and storage
- The web server is responsible for storing and serving the web application’s static assets, content, images, videos, and other files
- On hardware side web server is a computer that stores web server software and a website’s component files
- On software side web server is a program that uses HTTP (Hypertext Transfer Protocol) to serve the files that form web pages to users, in response to their requests, which are forwarded by their computers’ HTTP clients
- Web server is a computer that runs websites

## Difference between Web Server and Application Server

- Web server is a computer that runs websites
- Application server is a program that handles all application operations between users and an organization’s backend business applications or databases
- A web server is a program that uses HTTP (Hypertext Transfer Protocol) to serve the files that form web pages to users, in response to their requests, which are forwarded by their computers’ HTTP clients

# Communication Protocols

- A protocol which set a rule between client and server to communicate with each other
- can be implemented in hardware or software or combination of both

## Models

### Pull/Polling

- Client send request to server and wait for response

### Long Polling

- Client send request to server and wait for response
- Number of requests too much
- Server will store the request in the queue
- Server will send response to the client after some time
- Server will awake the client after some time
- Server will always busy

### Push

- In this model server will send response to the client without any request
- The server pushes new events to the client as they happen
- Reduces the server load
- Example: Facebook, Twitter likes

### Socket

- Socket is a two way communication protocol
- Client and server can send and receive data at the same time
- Example: Chatting application

### Server Sent Events

- Server Sent Events (SSE) is a server push technology enabling a client to receive automatic updates from a server via HTTP connection
- Example: Stock market,Cricket score

# Difference between Website and Web Application

- Website is static
- Web Application is dynamic

## Client and Server

- Client is a computer that request data from the server
  - Example: Browser,Instagram App
- Server is a computer that stores data and send data to the client
  - Example: Instagram Server

## Requirement for communication between client and server

- Fast
- Light Weight
- Language Independent
- Platform Independent
- Enable Communication over the n/w

# REST

- REST stands for Representational State Transfer
- REST is an architectural style for developing applications that can be accessed over the network
- CREATE, READ, UPDATE, DELETE

# SOA(Service Oriented Architecture)

- SOA is a style of architecture that promotes loose coupling and granular application to make the components of the software reusable

## Advantages

- Selective scalability
- Different Tech Stacks
- Loose Coupling
- Agile(Independency)

## Disadvantages

- High Latency
- High Complexity
- Complex uderstanding
- complex to secure

# Microservices

- evolution of SOA
- Microservices is an architectural style that structures an application as a collection of services that are
  - Highly maintainable and testable
  - Loosely coupled
  - Independently deployable
  - Organized around business capabilities
  - Owned by a small team
- different databases

# Tier Architecture

- Tier is a logical partition of the application
- Frontend, Backend, Database different tiers
- First tier is the client tier, second tier is the application tier, and the third tier is the database tier
- Each tier is completely independent from the other tiers, except for the interface to the next tier
- Each tier can be managed or scaled independently

# Authentication vs Authorization

- Authentication is the process of verifying who you are
- Authorization is the process of verifying what you have access to

# Basic Authentication
- Basic authentication is a simple authentication scheme built into the HTTP protocol
- Each time username and password is sent to the server
- It is not secure
- It is not used in production
## Token Based Authentication
- Token based authentication is stateless
- Token is generated by the server and sent to the client
- Token is stored in the client side
- Token is sent to the server for every request
- Token is valid for a certain period of time
- Token is not stored in the server side
- Token is stored in the client side
## OAuth
- OAuth is an open standard for access delegation
- OAuth provides client applications a 'secure delegated access' to server resources on behalf of a resource owner
- Can be login with google,facebook,github etc