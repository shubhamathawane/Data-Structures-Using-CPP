// remove duplicates from sorted LinkedList

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~Node()
    {
        int val = this->data;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
    }
};

void InsertAtBeginning(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void Display(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// we will check if item->val == item->next->val ? if yes then item->next = item->next->next;

void RemoveDuplicates(Node *&head)
{   
    if(head == NULL){
        return;
    }

    Node *curr = head;

    while (curr != NULL)
    {
        if ((curr->next != NULL ) && curr->data == curr->next->data)
        {
            Node *next_next = curr->next->next;
            // Node *temp_to_delete = curr->next;
            // delete(temp_to_delete);
            curr->next = next_next;
        }
        else
        {
            curr = curr->next;
        }
    }
}

int main()
{

    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;

    InsertAtBeginning(head, 20);
    InsertAtBeginning(head, 30);
    InsertAtBeginning(head, 40);
    InsertAtBeginning(head, 40);
    InsertAtBeginning(head, 50);
    Display(head);
    cout << endl;
    RemoveDuplicates(head);
    Display(head);

    return 0;
}