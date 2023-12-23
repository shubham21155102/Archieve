# Linked List in Javascript
## Class
```javascript
class Node {
    constructor(data, next = null) {
        this.data = data;
        this.next = next;
    }
}
```
## Create a Linked List

```javascript
var n1 = new Node(12);
n1.next = new Node(14);
n1.next.next = new Node(16);
console.log(n1);
```
## Print a Linked List
```javascript
const printList = (head) => {
    var curr = head;
    while (curr!== null) {
        console.log(curr.data);
        console.log(curr.next)
    
        curr = curr.next;
    }
}
```

```plaintext
In JavaScript, when we log an object (like a Node in our case) to the console, it displays the object's properties and their values. The next property in each node points to the next node in the linked list or null if it's the end of the list.

Regarding our observation about the output displaying Node {...} along with the node's properties and values, that's the default behavior of JavaScript when logging an object to the console. It shows the properties and their values for the logged object.

JavaScript doesn't explicitly display memory addresses like some other programming languages (e.g., C/C++). Instead, when you log an object, it presents a representation of that object showing its properties and their values.

So, in the output you've provided:

The initial log displays a Node object with its data and next properties.
Subsequent logs display each node's data value while traversing the linked list.
The output we see represents the properties and values of each Node in our linked list, not their memory addresses.
```

```shell
 node "/Users/shubham/Downloads/shubham/system-design/DSA/LinkedList/js/SLL.js"
Node {
  data: 19,
  next: Node { data: 17, next: Node { data: 12, next: [Node] } }
}
19
Node {
  data: 17,
  next: Node { data: 12, next: Node { data: 14, next: [Node] } }
}
17
Node {
  data: 12,
  next: Node { data: 14, next: Node { data: 16, next: [Node] } }
}
12
Node {
  data: 14,
  next: Node { data: 16, next: Node { data: 167, next: null } }
}
14
Node { data: 16, next: Node { data: 167, next: null } }
16
Node { data: 167, next: null }
167
null
```
## Insertion in Linked List at Head
```javascript
const insertAtHead = (x, head) => {
    if (head === null) return new Node(x);
    const temp = new Node(x);
    temp.next = head;
    return temp;
}
```
## Insertion in Linked List at Tail
```javascript
const insertAtTail = (x, head) => {
    if (head === null) return new Node(x);
    const temp = new Node(x);
    var curr = head;
    while (curr.next !== null) curr = curr.next;
    curr.next = temp;
    return head;
}
```
