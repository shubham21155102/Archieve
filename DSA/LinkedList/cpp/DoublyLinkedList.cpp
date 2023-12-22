#include <iostream>
using namespace std;
struct Node
{
  int data;
  Node *prev;
  Node *next;
  Node(int x)
  {
    this->data = x;
    prev = nullptr;
    next = nullptr;
  }
};
Node *insertAtHead(Node *head, int x)
{
  Node *temp = new Node(x);
  temp->next = head;
  if (head != nullptr)
  {
    head->prev = temp;
  }
  return temp;
}
Node *insertAtTail(Node *head, int x)
{
  Node *temp = new Node(x);
  if (head == nullptr)
  {
    return temp;
  }
  Node *trav = head;
  while (trav->next != nullptr)
  {
    trav = trav->next;
  }
  trav->next = temp;
  temp->prev = trav;
  return head;
}
Node *reverseDLL(Node *head)
{
  if (head == nullptr || head->next == nullptr)
  {
    return head;
  }

  Node *curr = head;
  Node *temp = nullptr;

  while (curr != nullptr)
  {
    temp = curr->prev;
    curr->prev = curr->next;
    curr->next = temp;
    curr = curr->prev;
  }

  if (temp != nullptr)
  {
    head = temp->prev;
  }

  return head;
}
Node* deleteHead(Node* head){
  if(head == nullptr){
    return nullptr;
  }
  if(head->next == nullptr){
    delete head;
    return nullptr;
  }
  Node* temp = head;
  head = head->next;
  head->prev = nullptr;
  delete temp;
  return head;
}
Node* deleteTail(Node* head){
  if(head == nullptr){
    return nullptr;
  }
  if(head->next == nullptr){
    delete head;
    return nullptr;
  }
  Node* trav = head;
  while(trav->next != nullptr){
    trav = trav->next;
  }
  trav->prev->next = nullptr;
  delete trav;
  return head;
}

int main()
{
  Node *head = new Node(56);
  Node *temp1 = new Node(34);
  Node *temp2 = new Node(45);
  head->next = temp1;
  temp1->prev = head;
  temp1->next = temp2;
  temp2->prev = temp1;
  Node *trav1 = head;
  while (trav1 != nullptr)
  {
    cout << trav1->data << " ";
    trav1 = trav1->next;
  }
  cout << endl;
  Node *trav2 = temp2;
  while (trav2 != nullptr)
  {
    cout << trav2->data << " ";
    trav2 = trav2->prev;
  }
  cout << endl;
  head = insertAtHead(head, 78);
  Node *trav3 = head;
  while (trav3 != nullptr)
  {
    cout << trav3->data << " ";
    trav3 = trav3->next;
  }
  cout << endl;
  head = insertAtTail(head, 90);
  Node *trav4 = head;
  while (trav4 != nullptr)
  {
    cout << trav4->data << " ";
    trav4 = trav4->next;
  }
  cout << endl;
  head = reverseDLL(head);
  Node *trav5 = head;
  while (trav5 != nullptr)
  {
    cout << trav5->data << " ";
    trav5 = trav5->next;
  }
  cout << endl;
  head = deleteHead(head);
  Node *trav6 = head;
  while (trav6 != nullptr)
  {
    cout << trav6->data << " ";
    trav6 = trav6->next;
  }
  cout << endl;
  head = deleteTail(head);
  Node *trav7 = head;
  while (trav7 != nullptr)
  {
    cout << trav7->data << " ";
    trav7 = trav7->next;
  }
  cout << endl;
  
  return 0;
}