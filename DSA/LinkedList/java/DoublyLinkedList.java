package LinkedList.java;

public class DoublyLinkedList {
    public static void main(String[] args) {
        Node_DLL head = new Node_DLL(12);
        Node_DLL temp1 = new Node_DLL(34);
        Node_DLL temp2 = new Node_DLL(8);
        head.next = temp1;
        temp1.prev = head;
        temp1.next = temp2;
        temp2.prev = temp1;
        Node_DLL trav1 = head;
        while (trav1 != null) {
            System.out.print(trav1.data + " ");
            trav1 = trav1.next;
        }
        System.out.println();
        head = insertAtHead(39, head);
        Node_DLL trav2 = head;
        while (trav2 != null) {
            System.out.print(trav2.data + " ");
            trav2 = trav2.next;
        }
        System.out.println();
        head = insertAtTail(12, head);
        head = insertAtTail(22, head);
        head = insertAtTail(13, head);
        head = insertAtTail(42, head);
        head = insertAtTail(52, head);
        Node_DLL trav3 = head;
        while (trav3 != null) {
            System.out.print(trav3.data + " ");
            trav3 = trav3.next;
        }
        System.out.println();
        head = reverseDLL(head);
        Node_DLL trav4 = head;
        while (trav4 != null) {
            System.out.print(trav4.data + " ");
            trav4 = trav4.next;
        }
        System.out.println();
        head = deleteHead(head);
        Node_DLL trav5 = head;
        while (trav5 != null) {
            System.out.print(trav5.data + " ");
            trav5 = trav5.next;
        }
        System.out.println();
        head = deleteAtTail(head);
        Node_DLL trav6 = head;
        while (trav6 != null) {
            System.out.print(trav6.data + " ");
            trav6 = trav6.next;
        }
        

    }

    public static Node_DLL insertAtHead(int x, Node_DLL head) {
        if (head == null)
            return new Node_DLL(x);
        Node_DLL temp = new Node_DLL(x);
        temp.next = head;
        head.prev = temp;
        return temp;
    }

    public static Node_DLL insertAtTail(int x, Node_DLL head) {
        Node_DLL temp = new Node_DLL(x);
        if (head == null)
            return temp;
        if (head.next == null) {
            head.next = temp;
            temp.prev = head;
            return head;
        }
        Node_DLL curr = head;
        while (curr.next != null) {
            curr = curr.next;
        }
        curr.next = temp;
        temp.prev = curr;
        return head;
    }
    public static Node_DLL reverseDLL(Node_DLL head) {
        if (head == null)
            return null;
        if (head.next == null)
            return head;
        Node_DLL curr = head;
        Node_DLL prev = null;
        while (curr != null) {
            prev = curr.prev;
            curr.prev = curr.next;
            curr.next = prev;
            curr = curr.prev;
        }
        return prev.prev;
    }
    public static Node_DLL deleteHead(Node_DLL head) {
        if (head == null)
            return null;
        if (head.next == null)
            return null;
        head = head.next;
        head.prev = null;
        return head;
    }
    public static Node_DLL deleteAtTail(Node_DLL head) {
        if (head == null)
            return null;
        if (head.next == null)
            return null;
        Node_DLL curr = head;
        while (curr.next != null) {
            curr = curr.next;
        }
        curr.prev.next = null;
        return head;
    }
}
