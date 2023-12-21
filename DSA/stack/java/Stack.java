package stack.java;

public class Stack {
    private int arr[];
    private int capacity;
    private int topIndex;
    Stack(int x){
        this.capacity=x;
        this.topIndex=-1;
        this.arr=new int[x];
    }
    public int size(){
        return this.topIndex+1;
    }
    public int peek(){
        if(topIndex==-1){
            System.out.println("No element in the stack");
            return -1;
        }
        return arr[topIndex];
    }
    public void pop() {
        if(topIndex==-1){
            System.out.println("No element in the stack");
            return;
        }
        if (isEmpty()) {
            // throw new IllegalStateException("Stack is empty, cannot pop.");
            return;
        }
        topIndex--;
    }
    
    public void push(int p){
        topIndex++;
        arr[topIndex]=p;
    }
    public boolean isEmpty(){
        return topIndex==-1;
    }

}
