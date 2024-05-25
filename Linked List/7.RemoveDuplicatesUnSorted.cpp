// remove duplicates from sorted LinkedList

#include <iostream>
#include <map>
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

// there are 3 approaches to this problem
// 1. While Loop (Brutforce)
// 2. Sort the linkedlist and use sorted version to remove duplicate
// 3. hashmap based approach.

// Approach : 1
void RemoveDuplicates(Node *&head)
{
    Node *curr = head;

    while (curr != NULL && curr->next != NULL)
    {
        Node *fw = curr;

        while (fw->next != NULL)
        {
            if (curr->data == fw->next->data)
            {
                // Node* temp = fw->next;
                fw->next = fw->next->next;
                // delete temp;
            }
            else
            {
                fw = fw->next;
            }
        }

        curr = curr->next;
    }
}

// Approach 2 : Hashmap

void RemoveDuplicates_HashMap(Node *head)
{
    Node *curr = head;
    Node *prev = NULL;
    map<int, bool> visited;

    while (curr != NULL)
    {

        if (visited[curr->data])
        {
            Node *temp_to_delete = curr;
            prev->next = curr->next;
            // delete temp_to_delete;
            curr = curr->next;
        }
        else
        {

            visited[curr->data] = true;
            prev = curr;
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
    InsertAtBeginning(head, 40);
    InsertAtBeginning(head, 30);
    InsertAtBeginning(head, 20);
    InsertAtBeginning(head, 50);
    InsertAtBeginning(head, 40);
    // Display(head);
    // cout << endl;
    RemoveDuplicates_HashMap(head);
    Display(head);

    return 0;
}