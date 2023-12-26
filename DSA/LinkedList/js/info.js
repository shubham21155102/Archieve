class Node {
    constructor(data, next = null) {
        this.data = data;
        this.next = next;
    }
}

var x = Math.random();
x = parseInt(x * 1000);
var head = new Node(x);
head.next = new Node(parseInt(1000 * Math.random()));
head.next.next = new Node(parseInt(1000 * Math.random()));
head.next.next.next = new Node(parseInt(1000 * Math.random()));



const members = document.getElementById('members');
function printList(head) {
    var curr = head;
    const members = document.getElementById('members');

    while (curr !== null) {
        const nodeElement = document.createElement('span');
        nodeElement.textContent = curr.data;
        nodeElement.classList.add('node');
        members.appendChild(nodeElement);
        if (curr.next !== null) {
            const arrowElement = document.createElement('span');
            arrowElement.textContent = '--->';
            members.appendChild(arrowElement);
        }

        curr = curr.next;
    }
}

function addToHead(event) {
    event.preventDefault();
    const nodeValue = document.getElementById('nodeValue1').value;
    if (nodeValue === "") {
        return;
    }
    const newNode = new Node(parseInt(nodeValue));
    newNode.next = head;
    head = newNode;
    members.innerHTML = "";
    printList(head);
}
const addToHeadButton = document.getElementById('addToHeadButton');
addToHeadButton.addEventListener('click', addToHead);
const inputForm1 = document.getElementById('inputForm1');
inputForm1.addEventListener('submit', function (event) {
    event.preventDefault();
});
function addRandomAtHead(event) {
    event.preventDefault();
    var x = Math.random();
    x = parseInt(x * 1000);
    const newNode = new Node(x);
    newNode.next = head;
    head = newNode;
    members.innerHTML = "";
    printList(head);
}
const addRandomAtHeadButton = document.getElementById('addRandomAtHeadButton');
addRandomAtHeadButton.addEventListener('click', addRandomAtHead);
const inputForm6 = document.getElementById('inputForm6');
inputForm6.addEventListener('submit', function (event) {
    event.preventDefault();
});
function addRandomAtTail(event) {
    event.preventDefault();
    var x = Math.random();
    x = parseInt(x * 1000);
    const newNode = new Node(x);
    if (head === null) {
        head = newNode;
    } else {
        var temp = head;
        while (temp.next != null) temp = temp.next;
        temp.next = newNode;
    }
    members.innerHTML = "";
    printList(head);
}
const addRandomAtTailButton = document.getElementById('addRandomAtTailButton');
addRandomAtTailButton.addEventListener('click', addRandomAtTail);
const inputForm7 = document.getElementById('inputForm7');
inputForm7.addEventListener('submit', function (event) {
    event.preventDefault();
});

function addToTail(event) {
    event.preventDefault();
    const nodeValue = document.getElementById('nodeValue2').value;

    if (nodeValue === "") return;

    const newNode = new Node(parseInt(nodeValue, 10));

    if (head === null) {
        head = newNode;
    } else {
        var temp = head;
        while (temp.next != null) temp = temp.next;
        temp.next = newNode;
    }

    members.innerHTML = "";
    printList(head);
}

const addToTailButton = document.getElementById('addToTailButton');
addToTailButton.addEventListener('click', addToTail);
const inputForm2 = document.getElementById('inputForm2');
inputForm2.addEventListener('submit', function (event) {
    event.preventDefault();
})
function deleteFromHead(event) {
    event.preventDefault();
    if (head === null) return;
    head = head.next;
    members.innerHTML = ""
    printList(head);
}
const deleteFromHeadButton = document.getElementById('deleteFromHeadButton');
deleteFromHeadButton.addEventListener('click', deleteFromHead);
const inputForm3 = document.getElementById('inputForm3');
inputForm3.addEventListener('submit', function (event) {
    event.preventDefault();
})
function deleteFromTail(event) {
    event.preventDefault();
    if (head === null) return;

    if (head.next === null) {
        head = null;
    } else {
        var temp = head;
        while (temp.next.next !== null) {
            temp = temp.next;
        }
        temp.next = null;
    }
    members.innerHTML = "";
    printList(head);
}
const deleteFromTailButton = document.getElementById('deleteFromTailButton');
deleteFromTailButton.addEventListener('click', deleteFromTail);
const inputForm4 = document.getElementById('inputForm4');
inputForm4.addEventListener('submit', function (event) {
    event.preventDefault();
})
function addAtPosition(event) {
    event.preventDefault();
    const nodeValue = document.getElementById('nodeValue3').value;
    const position = document.getElementById('position1').value;

    if (nodeValue === "" || isNaN(position) || position < 1) return;

    if (position === 1) {
        addToHead(event);
        return;
    }

    let temp = head;
    const newNode = new Node(parseInt(nodeValue, 10));

    for (let i = 1; i < position - 1 && temp !== null; i++) {
        temp = temp.next;
    }

    if (temp === null) {
        temp = head;
        while (temp.next !== null) {
            temp = temp.next;
        }
        temp.next = newNode;
    } else {
        newNode.next = temp.next;
        temp.next = newNode;
    }

    members.innerHTML = "";
    printList(head);
}

const addAtPositionButton = document.getElementById('addAtPositionButton');
addAtPositionButton.addEventListener('click', addAtPosition);

const inputForm5 = document.getElementById('inputForm5');
inputForm5.addEventListener('submit', function (event) {
    event.preventDefault();
});
function Search(event) {
    event.preventDefault();
    if (head === null) {
        alert("Given Linked List is Empty");
        return;
    }
    var temp = head;
    var nodeSearch = document.getElementById("nodeValue4").value;
    nodeSearch = parseInt(nodeSearch);
    console.log(nodeSearch)
    let pos = 1;
    while (temp !== null) {
        if (temp.data === nodeSearch) {
            alert("Congratulations you got the Number at " + pos + " position");
            return;
        }
        else {
            temp = temp.next;
            pos = pos + 1;
        }
    }
    alert("Uff number is not present");
    return;
}
const searchButton = document.getElementById("searchButton");
searchButton.addEventListener('click', Search);
const inputForm8 = document.getElementById("inputForm8");
inputForm8.addEventListener('submit', function (event) {
    event.preventDefault();
})
printList(head);