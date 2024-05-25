// T.C -> O(n)
// S.C ->  ===> O(1) <=== : We can also use Floyd's cycle detection algorithm (slow and fast pointers)

// if slow pointer == fast pointer then there is cycle in linked-list

// fast pointer go by 2 steps and slow pointer go by 1 step




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


Node* FloydDetectLoop(Node* head){

    if(head == NULL){
        return head;
    }

    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast != NULL){
        
        fast = fast -> next;
        
        if(fast != NULL){
            fast = fast->next;
        }

        slow = slow->next;

        if(slow == fast){   // if slow == fast then there is cycle in linked-list
            return slow;
        }


    }
    
    return NULL;  // else no cycle in the linked-list
}



Node* getStartingNode(Node* head){

    Node* intersection = FloydDetectLoop(head);
    Node* slow = head;


    // now if slow == intersection that's means we got the starting of the loop

    while(slow != intersection){
        slow = slow->next;
        intersection = intersection -> next;
    }



    return intersection;   // if they equal then we return intersection.


}


void RemoveLoop(Node* head){
    
    if(head == NULL) return;

    Node* startOfLoop = getStartingNode(head);
    Node* temp = startOfLoop;
    while(temp-> next != startOfLoop){   // run till if temp != starting node
        temp = temp->next;  // run and run 
    }

    temp -> next = NULL;  // nulling the previous node which pointing to the starting node.
}


int main(){

    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    InsertAtBeginning(head, 20);
    InsertAtBeginning(head, 30);
    InsertAtBeginning(head, 40);

    tail->next = head-> next;

    // Display(head);
    Node* starting = getStartingNode(head);
    cout<<"The loop of linked-list started from here : "<< starting-> data<<endl;
    RemoveLoop(head); // try by commenting and un-commenting this line 
    Display(head);

    return 0;
}