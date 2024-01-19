package LinkedList.java;

public class SinglyLinkedList {
    public static void main(String[] args) {
        Node ll = new Node(10);
        Node temp1 = new Node(5);
        Node temp2 = new Node(7);
        ll.next = temp1;
        temp1.next = temp2;
        while (ll != null) {
            int x = ll.data;
            System.out.print(x);
            System.out.print(" ");
            ll = ll.next;
        }
        System.out.println();
        ll = insertAtHead(78, ll);
        ll = insertAtHead(12, ll);
        PrintList(ll);
        System.out.println();
        ll = insertAtTail(90, ll);
        ll = insertAtTail(67, ll);
        PrintList(ll);
        System.out.println();
        ll = insertAtHead(13, ll);
        ll = insertAtHead(14, ll);
        ll = insertAtHead(53, ll);
        ll = insertAtHead(63, ll);
        ll = insertAtTail(90, ll);
        ll = insertAtTail(67, ll);
        ll = deleteAtHead(ll);
        PrintList(ll);
        System.out.println();
        ll = insertAtHead(13, ll);
        ll = insertAtHead(14, ll);
        ll = insertAtHead(53, ll);
        ll = insertAtHead(63, ll);
        ll = insertAtTail(90, ll);
        ll = insertAtTail(68, ll);
        ll = deleteAtHead(ll);
        ll = insertAtPosition(12, 9, ll);
        int x=search(68, ll);
        System.out.println(x+1);
        PrintList(ll);
        System.out.println();
    }

    public static void PrintList(Node head) {
        if (head == null)
            return;
        System.out.print(head.data + " ");
        PrintList(head.next);
    }

    public static Node insertAtHead(int x, Node head) {
        Node ll = new Node(x);
        ll.next = head;
        return ll;
    }

    public static Node insertAtTail(int x, Node head) {
        Node ll = new Node(x);
        Node temp = head;
        while (temp.next != null) {
            temp = temp.next;
        }
        temp.next = ll;
        return head;
    }

    public static Node deleteAtHead(Node head) {
        if (head == null) {
            return null;
        } else {
            return head.next;
        }
    }

    public static Node deleteAtTail(Node head) {
        if (head == null)
            return null;
        if (head.next == null)
            return null;
        Node temp = head;
        while (temp.next != null)
            temp = temp.next;
        temp.next = null;
        return head;
    }

    public static Node insertAtPosition(int pos, int x, Node head) {
        if (pos <= 0) {
            System.out.println("Invalid position");
            return head;
        }

        if (pos == 1) {
            head = insertAtHead(x, head);
            return head;
        }

        Node temp = new Node(x);
        Node curr = head;

        for (int i = 1; i <= pos - 2 && curr != null; i++) {
            curr = curr.next;
        }

        if (curr == null) {
            System.out.println("Position exceeds the length of the list. Inserting at the end.");
            return insertAtTail(x, head);
        }

        temp.next = curr.next;
        curr.next = temp;
        return head;
    }
    public static int search(int x,Node head){
        int pos=0;
        if(head==null) return -1;
        Node curr=head;
        while (curr!=null) {
            if(curr.data==x)
            return pos;
            curr=curr.next;
            pos++;
        }
        return -1;
    }

}
