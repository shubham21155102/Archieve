package OOPS_JAVA;

class Animal {
    // Property
    String name;

    // Constructor
    Animal(String name) {
        this.name = name;
    }

    // Method
    void eat() {
        System.out.println(name + " is eating.");
    }
}

class Dog extends Animal {
    // Additional property for Dog
    String breed;

    // Constructor
    Dog(String name, String breed) {
        // Call the constructor of the superclass (Animal)
        super(name);
        this.breed = breed;
    }

    // Method specific to Dog
    void bark() {
        System.out.println(name + " is barking.");
    }
}

public class P_7_Inheritance {
  public static void main(String[] args) {
    // Create an object of Dog
    Dog dog = new Dog("Tommy", "Labrador");

    // Access the properties and methods of Dog
    dog.eat();
    dog.bark();
  }
}
