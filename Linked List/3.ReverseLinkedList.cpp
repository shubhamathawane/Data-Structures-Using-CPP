#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
        int data;
        Node *next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};


void insertAtBeginning(Node* &head, int d){
    Node* temp  = new Node(d);
    temp -> next = head;
    head = temp;
}


void Display(Node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}


void ReverseLinkedListIteratively(Node* head){
    Node* prev = NULL;
    Node* fw = head -> next;
    Node* curr = head;

    while(curr != NULL){
        fw = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = fw;
    }

    Display(prev);
}

void reverse(Node* &head, Node* curr, Node* prev){

    if(curr == NULL){
        head = prev;
        return;
    }

    Node* fw = curr -> next;
    reverse(head, fw, curr);
    curr -> next = prev;
}


int main(){
    Node *new_node = new Node(10);
    Node* head = new_node;
    Node* prev  = NULL;


    insertAtBeginning(head, 20);
    insertAtBeginning(head, 30);
    insertAtBeginning(head, 40);
    insertAtBeginning(head, 60);
    // ReverseLinkedListIteratively(head);
    reverse(head, head, NULL);
    Display(head);
}