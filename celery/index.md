# Celery

- Celery is a simple, flexible, and reliable distributed system to process vast amounts of messages, while providing operations with the tools required to maintain such a system.
- It's a task queue with focus on real-time processing, while also supporting task scheduling.
- Task queues are used as a mechanism to distribute work across threads or machines
- A celery system can consists of multiple workers and brokers , giving way to high availability and horizontal scalling.
- Celery allows you to execute background tasks asynchronously, which is especially useful for long-running or time-consuming operations that shouldn't block the main application.
- Celery is written in Python, but the protocol can be implemented in any language.
- Celery can run on a single machine, on multiple machines, or even across data center.

```mermaid
graph RL;
subgraph Request Response Without Celery
A[User]--Request-->B[Application<br><hr><br>Generate account <br> statement and Email <br> to User]
end
B--Response<br><hr><br>After completion <br>of process<br>about 10 sec-->A
```

```mermaid
graph RL;
subgraph Request Response With Celery
A[User]--Request-->B[Application<br><hr><br>Generate account <br> statement and Email <br> to User]
B--Response<br><hr><br>Just after Request <br>about 1 sec-->A
B--Enqueue Task <br> to message <br> broker-->C[Message Broker <br>Redis/RabbitMQ <br><hr> ]
end

```
