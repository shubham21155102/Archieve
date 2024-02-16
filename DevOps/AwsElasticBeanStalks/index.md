# AWS Elasticbeanstalks

## What is AWS Elasticbeanstalks?

AWS Elastic Beanstalk is an easy-to-use service for deploying and scaling web applications and services developed with Java, .NET, PHP, Node.js, Python, Ruby, Go, and Docker on familiar servers such as Apache, Nginx, Passenger, and IIS.

## How to deploy a web application using AWS Elasticbeanstalks?

1. Open the Elastic Beanstalk console using this preconfigured link: [https://console.aws.amazon.com/elasticbeanstalk](https://console.aws.amazon.com/elasticbeanstalk)
2. Choose Create New Application.
3. In the Application Name box, type a name for your application, and then choose Create.
4. Choose Create one now to create an environment in the AWS Management Console.
5. Choose the platform that matches your application code.
6. Choose the platform version that matches your application code.
7. Choose the sample application to deploy.
8. Choose Create environment.
9. Choose the URL to open your running sample application.

## Difference between application and environment in AWS Elasticbeanstalks?

- An application is a logical collection of Elastic Beanstalk components, including environments, versions, and environment configurations. In Elastic Beanstalk, you can create and manage multiple applications. An environment is a versioned, runnable instance of an application. You can run one or more environments in an application.

## Instance traffic and scaling

1. **Capacity Settings** :

* **Min instances** : Specifies the minimum number of instances that Elastic Beanstalk should maintain for your environment.
* **Max instances** : Specifies the maximum number of instances that Elastic Beanstalk can scale up to based on traffic and load.

2. **Instance Types and AMI** :

* **Instance types** : Defines the type of EC2 instances used in your environment. In this case, `t4g.small` instances are being used.
* **AMI ID** : Specifies the Amazon Machine Image (AMI) used to launch the EC2 instances.

3. **Scaling Settings** :

* **Scaling cooldown** : The amount of time, in seconds, that Elastic Beanstalk should wait before scaling the number of instances again. This helps prevent rapid scaling up and down in response to fluctuating traffic.
* **Breach duration** : The amount of time, in seconds, that a metric must breach the threshold before triggering a scaling action.
* **Upper threshold** : The threshold for the metric (`NetworkOut` in this case) that, when exceeded, triggers scaling up (adding more instances).
* **Lower threshold** : The threshold for the metric that, when not exceeded, triggers scaling down (removing instances).
* **Scale up increment** : The number of instances to add when scaling up.
* **Scale down increment** : The number of instances to remove when scaling down.

4. **Load Balancer Settings** :

* **Load balancer visibility** : Specifies whether the load balancer is public or internal.
* **Load balancer subnets** : Specifies the subnets where the load balancer is deployed.
* **Load balancer type** : Specifies the type of load balancer (e.g., application, network).
* **Load balancer is shared** : Indicates whether the load balancer is shared with other environments.

5. **Other Settings** :

* **IMDSv1** : Controls whether EC2 instance metadata service version 1 is enabled.
* **EC2 Security Groups** : Specifies the security groups associated with the EC2 instances in your environment.
* **Processor type** : Specifies the processor architecture used by the EC2 instances (e.g., `arm64`).
* **Availability Zones** : Specifies the availability zones where instances can be launched.
