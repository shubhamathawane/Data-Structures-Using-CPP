// this also is called doubly linked-list

#include <bits/stdc++.h>

using namespace std;

class Node{

public:

    int data;
    Node *prev;   
    Node *next;

    Node(int data){        // Created constructor to initialize the node value;
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
    ~Node(){
        int val = this->data;
        if(next != NULL){
            delete next;
            next = NULL;
        }

        cout<<"Memory free for node with data : "<<val<<endl;
    }


    
};


void insertAtBeginning(Node* &head, int data){

    Node* temp = new Node(data);  // creating new node with new data, this node will contain new data with Prev and Next Pointer with null

    temp->next = head;         // point temp's next to current head

    head->prev = temp;          // pointing head's -> prev to new temp;

    head = temp;  // updating the head to new head;

}


void insertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}



void insertAtPosition(Node* &head , Node* &tail, int pos, int d){
        
        if(pos == 1){
            insertAtBeginning(head, d);
            return;
        }


        Node* temp = head;
        int cnt = 1;
        
        while(cnt < pos-1){
            temp = temp->next;
            cnt++;
        }

        // if inserting at beginning 

        if(head->next == NULL){
            insertAtTail(tail, d);
            return;
        }

        // else in middle of the linked-list

        Node* new_node = new Node(d);

        new_node -> next = temp->next;
        temp -> next = new_node;
        temp->next->prev = new_node;
        new_node -> prev = temp;

}

// deleting at beginning

void DeleteNode(Node* &head, int pos){

    if(pos == 1){
        Node* temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }else{
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;

        while(cnt < pos-1){
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        curr -> prev = NULL;
        prev -> next = curr -> next;
        curr -> next = NULL;

        delete curr;
    }

}



void Print(Node* head){
    Node* temp = head;

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}


int getLength(Node* head){
    Node* temp = head;
    int len = 0;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    return len;
}



int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    insertAtBeginning(head, 20);
    insertAtBeginning(head, 40);
    insertAtBeginning(head, 50);
    insertAtBeginning(head, 60);
    insertAtTail(tail, 100);
    insertAtBeginning(head, 70);
    insertAtPosition(head, tail,7, 110);
    DeleteNode(head, 1);
    DeleteNode(head, 4);
    Print(head);
    return 0;
}