#include <iostream>
using namespace std;
struct Node{
  int data;
  Node* prev;
  Node* next;
  Node(int x){
    this->data=x;
    prev=nullptr;
    next=nullptr;
  }
};
int main(){
    Node *head=new Node(56);
    Node* temp1=new Node(34);
    Node* temp2=new Node(45);
    head->next=temp1;
    temp1->prev=head;
    temp1->next=temp2;
    temp2->prev=temp1;
    Node* trav1=head;
    while(trav1!=nullptr){
        cout<<trav1->data<<" ";
        trav1=trav1->next;
    }
    return 0;
}