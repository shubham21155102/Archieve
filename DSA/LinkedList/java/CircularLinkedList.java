package DSA.LinkedList.java;

public class CircularLinkedList {
    public static void main(String[] args) {
        Node head = new Node(10);
        Node temp1 = new Node(20);
        Node temp2 = new Node(30);
        head.next = temp1;
        temp1.next = temp2;
        temp2.next = head;
        Node trav = head;
        do {
            System.out.print(trav.data + " ");
            trav = trav.next;
        } while (trav != head);
        System.out.println();
    }

    public static void PrintList(Node head) {
        Node trav = head;
        do {
            System.out.print(trav.data + " ");
            trav = trav.next;
        } while (trav != head);
        System.out.println();
    }

    public static Node insertAtHead(int x, Node head) {
        Node temp = new Node(x);
        if (head == null) {
            temp.next = temp; 
            return temp;
        } else {
            temp.next = head;
            Node curr = head;
            while (curr.next != head) {
                curr = curr.next;
            }
            curr.next = temp;
            return temp; 
        }
    }

}
