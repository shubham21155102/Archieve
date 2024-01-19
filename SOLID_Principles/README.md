# SOLID

- SOLID is a set of principles that helps us to write clean, readable, maintainable, testable, reusable, extensible and scalable code

## Robert C. Martin

- S: Single Responsibility
- O: Open/Closed
- L: Liskov's Substitution
- I:  Interface Segregation
- D: Dependency Inversion

## Interface Segregation/ Inversion of Control / Dependency Injection / Dependency Inversion

# Context

- Simple Zoo Game
- Characters - Animals/Staff/ Visitors
- Structures-

```java
//in OOP a class models a concept 
// in classes we have - properties and methods
class ZooEntity{
String entityType;
String name;
Color color;
Float weight;
Float height;
Float length;
String species;
Boolean canBreathUnderWater;
Boolean canFly;

String staffName;
String staffRole;
String staffDepartment;
String staffShift;
Integer staffAge;
String staffGender;

String visitorName;
String visitorAge;
String visitorGender;
String visitorTicketType;
String visitorTicketNumber;
String visitorTicketPrice;

void eat(){};
void sleep(){};
void walk(){};
void swim(){};
void fly(){};
void poop(){};
void makeNoise(){};


void clean(){};
void sellTicket(){};
void checkTicket(){};
void feed(){};
void entertain(){};
void educate(){};
void clean(){};
void sellFood(){};
void sellMerchandise(){};
void sellTickets(){};
void checkTickets(){};
}
```

## Readabale

- Readable code is easy to understand and follow
- But there is no separation of concerns
- No separation of concerns means that the code is not modular
- Code base is going to be bulky and difficult to maintain

## Maintainable

- Difficult to maintain
- Tons and tons of merge conflicts if multiple developers are working on the same file
- so due to this reason S is important
- S - Single Responsibility Principle
- Each class should have only one responsibility

## Testable

- Yes i can write testcases for each methods

## Reusable

## Extensible

## Scalable

## SOLID

# ⭐ S - Single Responsibility Principle

- Any Class / function should have only one responsibility
- Any piece of code should have only one reason to change
- If a class has more than one responsibility, then the responsibilities become coupled

```java
class ZooEntity{
   
}
```

```java
class Animal{
    // Attribute and Behaviours only related to Animal
    String name;
    Color color;
    Float weight;
    Species species;
    Boolean canBreathUnderWater;
    Boolean canFly;

    void eat(){};
    void sleep(){};
    void walk(){};
    void swim(){};
    void fly(){};
    void poop(){};
    void makeNoise(){};
}
```

```java
class Staff{
    String staffName;
String staffRole;
String staffDepartment;
String staffShift;
Integer staffAge;
String staffGender;
void clean(){};
void sellTicket(){};
void checkTicket(){};
void feed(){};
void entertain(){};
void educate(){};
void clean(){};
void sellFood(){};
void sellMerchandise(){};
void sellTickets(){};
void checkTickets(){};
}
```

```java
class Visitor{
String visitorName;
String visitorAge;
String visitorGender;
String visitorTicketType;
String visitorTicketNumber;
String visitorTicketPrice;
}
```

```java
class Animal extends ZooEntity{
    // Attribute and Behaviours only related to Animal
    String name;
    Color color;
    Float weight;
    Species species;
    Boolean canBreathUnderWater;
    Boolean canFly;

    void eat(){};
    void sleep(){};
    void walk(){};
    void swim(){};
    void fly(){};
    void poop(){};
    void makeNoise(){};
}
```

```java
class Staff extends ZooEntity{
String staffName;
String staffRole;
String staffDepartment;
String staffShift;
Integer staffAge;
String staffGender;
void clean(){};
void sellTicket(){};
void checkTicket(){};
void feed(){};
void entertain(){};
void educate(){};
void clean(){};
void sellFood(){};
void sellMerchandise(){};
void sellTickets(){};
void checkTickets(){};
}
```

- Readable
  - Yes
  - but too much of code duplication
  - there are 4 classes with same attributes and methods
  - if i am a CTO of a company, i would not want to pay my developers to write the same code again and again
  - if i am a developer, i would not want to write the same code again and again
  - there are more files to maintain now but only work is to maintain the same code
- Testable
  - Yes
  - i can write testcases for each methods
- Maintainable
  - Yes
  - No conflicts
  - No merge conflicts

### Focus on Animals

```java
[Library] class simpleZooAnimal {
    // Attribute and Behaviours only related to Animal
    String name;
    Color color;
    Float weight;
    Species species;
    Boolean canBreathUnderWater;
    Boolean canFly;

    void eat(){};
    void sleep(){};
    void walk(){};
    void swim(){};
    void fly(){
        if(species=="Eagle"){
            System.out.println("Flys high");
        }
        else if(species=="Sparrow"){
            System.out.println("Flys low");
        }
        else if(species=="Penguin"){
            System.out.println("Cannot Fly");
        }
    };
    void poop(){};
    void makeNoise(){};
}
[our code] class ZooGame{
    import simpleZooAnimal;
    // we want to add modifications to the library code
    // we want to add a new feature to the library code
    // here extension is not possible
    // we have to modify the library code
    // So here O  came into picture
    // O - Open/Closed Principle
}
```

# ⭐ O - Open/Closed Principle

- we can extend the functionality of a class without modifying it using Object Oriented Programming
- Why modification i bad?
  - we write code on local machine
  - other developers and other teams will review the code
    - Iterate
    - Merge
  - Quality Assurance Team(QA) will test the code
    - Iterate
    - Merge
  - Deployment Phase
  - Staging Servers
    - A/B testing
      - deploy to 1% of the users
      - monitor the performance
        - users are happy?
        - users are not happy?
        - bugs?
        - crashes?
        - performance?
          - security?
          - speed?
        - Sells are increasing?
        - Sells are decreasing?
  - Now all this process is going to take time
  - Now we will change the entire user code base
## Extensible 
- Yes
- we can extend the functionality of a class without modifying it using Object Oriented Programming
- i want to add a new feature to the library code that i was not allowed to modify
- same thing we did for Single Responsibility Principle
- Solution is same but the intent is different
- in case if library author added some bad code we can not modify it as per own level
### Staff Engineers / Senior Engineers/ Principal Engineers in Tier 1 companies
- salary upto 3 Cr per annum
### Object Oriented Programming
