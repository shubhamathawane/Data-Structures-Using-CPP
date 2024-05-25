// T.C -> O(n)
// S.C -> O(n)  == We can also use Floyd's cycle detection algorithm (slow and fast pointers)

#include<iostream>
#include<map>
using namespace std;


class Node{
    public:
        int data;
        Node* next;
    
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};


void InsertAtBeginning(Node* &head, int d){
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void Display(Node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head -> next;
    }
}


bool DetectCycleInLinkedList(Node* head){
    map<Node* , bool> visited;
    while(head != NULL){

        if(visited[head]){
            cout<<"The cycle found at :"<<head->data<<endl;
            return true;
        }

        visited[head] = true;
        head = head->next;
    }

    for(auto it:visited){
        cout<<it.first->data<<" "<<it.second<<endl;
    }

    return false;

}

int main(){

    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    InsertAtBeginning(head, 20);
    InsertAtBeginning(head, 30);
    InsertAtBeginning(head, 40);

    // tail->next = head-> next;

    // Display(head);

    cout<<DetectCycleInLinkedList(head);

    return 0;
}