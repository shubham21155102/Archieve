class Node {
    constructor(data, prev = null, next = null) {
        this.data = data;
        this.prev = prev;
        this.next = next;
    }
};
function insertAtHead(x, head) {
    if (head === null) return new Node(x);
    const temp = new Node(x);
    temp.next = head;
    head.prev = temp;
    return temp;
}
function insertAtTail(x, head) {
    if (head === null) return new Node(x);
    const temp = new Node(x);
    var curr = head;
    while (curr.next !== null) curr = curr.next;
    curr.next = temp;
    temp.prev = curr;
    return head;
}
function printList(head) {
    var curr = head;
    while (curr !== null) {
        console.log(curr.data);
        console.log(curr.prev);
        console.log(curr.next);
        curr = curr.next;
    }
}
var n1 = new Node(12);
n1.next = new Node(14);
n1.next.next = new Node(16);
n1 = insertAtHead(17, n1);
n1 = insertAtHead(19, n1);
n1 = insertAtTail(167, n1);
console.log(n1);
printList(n1);