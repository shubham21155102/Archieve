package OOPS_JAVA;

class Singleton {
    // Step 1: Create a private static instance of the class
    private static Singleton instance;

    // Step 2: Make the constructor private to prevent instantiation from outside
    private Singleton() {
        System.out.println("Singleton instance created!");
    }

    // Step 3: Provide a public static method to get the instance of the class
    public static Singleton getInstance() {
        if (instance == null) {
            instance = new Singleton(); // Lazy initialization
        }
        return instance;
    }

    // Example method
    public void showMessage() {
        System.out.println("Hello from Singleton class!");
    }
}

public class P_3_Examples {
    public static void main(String[] args) {
        // Step 4: Try to get the Singleton instance using the public method
        Singleton obj1 = Singleton.getInstance();
        Singleton obj2 = Singleton.getInstance();

        // Verify both references point to the same instance
        System.out.println(obj1 == obj2); // Output will be true, as both are the same instance

        obj1.showMessage();
    }
}