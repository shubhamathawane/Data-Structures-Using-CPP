#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(Node *&head, int d)
{

    // create new node
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void InsertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void insertAtParticularPosition(Node *&tail, Node *&head, int pos, int d)
{
    // # if inserting at head;

    if (pos == 1)
    {
        insertAtHead(head, d);
        return;
    }

    int i = 1;
    Node *temp = head;
    while (i < pos - 1)
    {
        temp = temp->next;
        i++;
    }

    // if inserting at tail

    if (temp->next == NULL)
    {
        InsertAtTail(tail, d);
        return;
    }



    Node *node_to_insert = new Node(d);

    node_to_insert->next = temp->next;

    temp->next = node_to_insert;
}



// deleting the node : 1. using position 2. value

void DeleteNodePosition(int pos, Node* &head){
    int cnt = 1;
    Node* temp = head;
    while(temp -> next != NULL){
        if(cnt == pos-1){
            temp -> next = temp -> next -> next;
        }
        temp = temp -> next;
        cnt++;
    }
}


void Traverse(Node *&head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " " << endl;
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *node1 = new Node(10);
    Node *tail = node1;
    Node *head = node1;

    insertAtHead(head, 12);
    insertAtHead(head, 15);
    InsertAtTail(tail, 2);
    insertAtParticularPosition(tail, head, 1, 22);
    DeleteNodePosition(3, head);

    Traverse(head);


    cout<<"head : "<< head -> data<<endl;
    cout<<"Tail : "<< tail -> data<<endl;

    return 0;
}