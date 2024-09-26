package OOPS_JAVA;

class Example {
    // Static variable
    static int count;

    // Static block for initialization
    static {
        System.out.println("Static block executed.");
        count = 10; // Initializing the static variable
    }

    // Constructor
    public Example() {
        System.out.println("Constructor called.");
    }

    public static void main(String[] args) {
        System.out.println("Main method started.");

        // Access the static variable
        System.out.println("Count: " + Example.count);

        // Create an object of the class
        Example obj = new Example();
    }
}

public class P_5_Static_Block {
    public static void main(String[] args) {
        Example.main(args);
        
    }

}
