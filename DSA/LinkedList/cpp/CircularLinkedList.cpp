#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        this->data = x;
        next = nullptr;
    }
};
void PrintList(Node *head)
{
    Node *trav = head;
    do
    {
        cout << trav->data << " ";
        trav = trav->next;
    } while (trav != head);
}
int main()
{
    Node *head = new Node(10);
    Node *temp1 = new Node(20);
    Node *temp2 = new Node(30);
    head->next = temp1;
    temp1->next = temp2;
    temp2->next = head;
    Node *trav1 = head;
    do
    {
        cout << trav1->data << " ";
        trav1 = trav1->next;
    } while (trav1 != head);

    return 0;
}