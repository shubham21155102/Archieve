package OOPS_JAVA;

class Demo {
    // private
    int price = 100;
    int spent = 0;
    String name = "Demo";
    Demo() {
        System.out.println("Object created");
    }

    void buy(int price) {
        spent += price;
    }

    void show() {
        System.out.println("Name: " + name);
        System.out.println("Price: " + price);
        System.out.println("Spent: " + spent);
    }
}

public class P_1 {
    public static void main(String[] args) {
        Demo d1=new Demo();
        d1.buy(0);
        d1.show();
    }
}
class Car {
    String make;
    String model;
    int year;

    // Default constructor
    public Car() {
        this.make = "Unknown";
        this.model = "Unknown";
        this.year = 0;
    }

    // Constructor with one parameter
    public Car(String make) {
        this.make = make;
        this.model = "Unknown";
        this.year = 0;
    }

    // Constructor with two parameters
    public Car(String make, String model) {
        this.make = make;
        this.model = model;
        this.year = 0;
    }

    // Constructor with three parameters
    public Car(String make, String model, int year) {
        this.make = make;
        this.model = model;
        this.year = year;
    }

    // Display car details
    public void displayCarInfo() {
        System.out.println("Make: " + make + ", Model: " + model + ", Year: " + year);
    }

    public static void main(String[] args) {
        // Using different constructors
        Car car1 = new Car();
        Car car2 = new Car("Toyota");
        Car car3 = new Car("Honda", "Civic");
        Car car4 = new Car("Ford", "Mustang", 2023);

        // Displaying car information
        car1.displayCarInfo();
        car2.displayCarInfo();
        car3.displayCarInfo();
        car4.displayCarInfo();
    }
}