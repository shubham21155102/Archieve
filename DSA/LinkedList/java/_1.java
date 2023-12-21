package DSA.LinkedList.java;

public class _1 {
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
}
