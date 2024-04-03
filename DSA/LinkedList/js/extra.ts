class ListNode{
    constructor(public data:number,public next:ListNode|null=null){
        this.data = data;
        this.next = next;
    }
}
const arr=[1,2,3,4,5,6];
let head = new ListNode(arr[0]);
let current = head;
arr.map((item,index)=>{
    if(index>0){
        current.next = new ListNode(item);
        current = current.next;
    }
}
)
console.log(head);

function rearrange(head: ListNode) {
    let slow: ListNode | null = head;
    let fast: ListNode | null = head;
    let prev: ListNode | null = null;
    while (fast && fast.next) {
        prev = slow;
        slow = slow!.next;
        fast = fast!.next!.next;
    }
    if (prev) {
        prev.next = null;
    }
    console.log("First Half:");
    console.log(head);
    console.log("Second Half:");
    console.log(slow);
}
rearrange(head);