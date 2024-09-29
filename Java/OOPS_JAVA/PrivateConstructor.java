// package OOPS_JAVA;
// class A {
//     private A() {
//         System.out.println("Private constructor");
//     }
//     public A (A a) {
//         System.out.println("Copy constructor");
//     }
// }
// public class PrivateConstructor {
//     public static void main(String[] args) {
//         A a = new A();
//         A b = new A(a);
//     }
// }
package OOPS_JAVA;

class A {
    private A() {
        System.out.println("Private constructor");
    }

    public A(A a) {
        System.out.println("Copy constructor");
    }

    // Static factory method to create objects
    public static A createInstance() {
        return new A();
    }
   void show() {
        System.out.println("Private method");
    }
}

public class PrivateConstructor {
    public static void main(String[] args) {
        A a = A.createInstance(); 
        A b = new A(a);  
        b.show();
        
    }
}