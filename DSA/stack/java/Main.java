package stack.java;

public class Main {
    public static void main(String[] args) {
        Stack s=new Stack(5);
        s.pop();
        for(int i=1;i<=5;i++){
            s.push(i);
        }
        System.out.println(s.size());
        System.out.println(s.peek());
        System.out.println(s.size());
        System.out.println(s.isEmpty());

        s.pop();
        s.pop();
        System.out.println(s.peek());
    }
}
