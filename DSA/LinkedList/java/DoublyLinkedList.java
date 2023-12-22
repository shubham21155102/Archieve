package DSA.LinkedList.java;

public class DoublyLinkedList {
   public static void main(String[] args) {
     Node_DLL head=new Node_DLL(12);
    Node_DLL temp1=new Node_DLL(34);
    Node_DLL temp2=new Node_DLL(8);
    head.next=temp1;
    temp1.prev=head;
    temp1.next=temp2;
    temp2.prev=temp1;
    Node_DLL trav1=head;
    while(trav1!=null){
        System.out.print(trav1.data+" ");
        trav1=trav1.next;
    }
   }
    
}
