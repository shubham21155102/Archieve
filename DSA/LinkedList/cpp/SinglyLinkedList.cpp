#include <iostream>
using namespace std;
struct Node
{
  int data;
  Node *next;
  Node(int x)
  {
    this->data = x;
    this->next = nullptr;
  }
};
Node *insertAtHead(Node *head, int x)
{
  Node *ll = new Node(x);
  ll->next = head;
  return ll;
}
Node *insertAtTail(Node *head, int x)
{
  Node *ll = new Node(x);
  Node *temp = head;
  while (temp->next != nullptr)
  {
    temp = temp->next;
  }
  temp->next = ll;
  return head;
}
Node *deleteAtHead(Node *head)
{
  if (head == NULL)
    return NULL;
  else
  {
    // return head->next;
    Node *temp = head->next;
    delete head;
    return temp;
  }
}
Node *deleteAtTail(Node *head)
{
  if (head == nullptr)
    return nullptr;
  if (head->next == nullptr)
  {
    delete head;
    return nullptr;
  }
  Node *temp = head;
  while (temp->next->next != nullptr)
  {
    temp = temp->next;
  }
  delete temp->next;
  temp->next = nullptr;
  return head;
}
Node *insertAtPosition(int x, int pos, Node *head)
{
  if (pos == 1)
  {
    head = insertAtHead(head, x);
    return head;
  }
  Node *temp = new Node(x);
  Node *curr = head;
  for (int i = 1; i <= pos - 2 && head != nullptr; i++)
    curr = curr->next;
  if (curr == nullptr)
  {
    cout << "out of range you are saying to insert so inserting at tail"
         << "\n";
    head = insertAtTail(head, x);
    return head;
  }
  temp->next=curr->next;
  curr->next=temp;
  return head;
}
int search(int x,Node *head){
  int pos=1;
  if(head==nullptr) return -1;
  Node* curr=head;
  while(curr!=nullptr){
    if(curr->data==x) return pos;
    curr=curr->next;
    pos++;
  }
  return -1;
}
void PrintList(Node *head)
{
  if (head == nullptr)
    return;
  cout << head->data << " ";
  PrintList(head->next);
}
int main()
{
  Node *ll = new Node(5);
  ll->next = new Node(10);
  ll->next->next = new Node(15);
  while (ll)
  {
    int x = ll->data;
    cout << x << " ";
    ll = ll->next;
  }
  cout << "\n";
  Node *head = new Node(10);
  Node *temp1 = new Node(29);
  Node *temp2 = new Node(54);
  head->next = temp1;
  temp1->next = temp2;
  while (head)
  {
    int x = head->data;
    cout << x << " ";
    head = head->next;
  }
  cout << "\n";
  head = insertAtHead(head, 90);
  head = insertAtHead(head, 98);
  PrintList(head);
  cout << "\n";
  head = insertAtTail(head, 89);
  head = insertAtTail(head, 99);
  head = insertAtTail(head, 809);
  head = insertAtTail(head, 898);
  head = insertAtTail(head, 891);
  head = insertAtTail(head, 189);
  head = deleteAtHead(head);
  head = deleteAtTail(head);
  head = deleteAtTail(head);
  head=insertAtPosition(3,5,head);
  int x=search(90,head);
  cout<<x<<"\n";
  PrintList(head);
  cout << "\n";
  return 0;
}