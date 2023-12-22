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
Node *insertAtHead(Node* head,int x){
    Node* temp=new Node(x);
    temp->next=head;
    if(head!=nullptr){
        head->prev=temp;
    }
    return temp;
}
Node *insertAtTail(Node* head,int x){
    Node* temp=new Node(x);
    if(head==nullptr){
        return temp;
    }
    Node* trav=head;
    while(trav->next!=nullptr){
        trav=trav->next;
    }
    trav->next=temp;
    temp->prev=trav;
    return head;
}
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
    cout<<endl;
    Node* trav2=temp2;
    while(trav2!=nullptr){
        cout<<trav2->data<<" ";
        trav2=trav2->prev;
    }
    cout<<endl;
    head=insertAtHead(head,78);
    Node* trav3=head;
    while(trav3!=nullptr){
        cout<<trav3->data<<" ";
        trav3=trav3->next;
    }
    cout<<endl;
    head=insertAtTail(head,90);
    Node* trav4=head;
    while(trav4!=nullptr){
        cout<<trav4->data<<" ";
        trav4=trav4->next;
    }
    cout<<endl;
    
    return 0;
}