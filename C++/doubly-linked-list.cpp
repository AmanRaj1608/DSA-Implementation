// C++ implementation of Doubly Linked List

#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *prev, *next;
    Node(int);
};

Node::Node(int data)
{
    this->data = data;
    prev = next = NULL;
}

class DLL
{
public:
    Node *head, *tail;
    DLL();
    void insertBeg(int);
    void insertEnd(int);
    void print();
    void printReverse();
};

DLL::DLL() { head = tail = NULL; }

void DLL::insertBeg(int value)
{
    Node *temp = new Node(value);
    if(head == NULL)
    {
        head = tail = temp;
        return ;
    }
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void DLL::insertEnd(int value)
{
    Node *temp = new Node(value);
    if(head == NULL)
    {
        head = tail = temp;
        return ;
    }
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void DLL::print()
{
    if(head == NULL)
    {
        cout << "\nThe list is empty.\n";
        return ;
    }
    Node *temp = head;
    cout << "\n";
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

void DLL::printReverse()
{
    if(head == NULL)
    {
        cout << "\nThe list is empty.\n";
        return ;
    }
    Node *temp = tail;
    cout << "\n";
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << "\n";
}

int main()
{
    DLL var;
    int option, input;
    do {
        cout << "\n\nDOUBLY LINKED LIST:\n\n";
        cout << "\n(1) Insert at the beginning";
        cout << "\n(2) Insert at the end";
        cout << "\n(3) Print the list";
        cout << "\n(4) Print the list in reverse order";
        cout << "\n(5) Exit";
        cout << "\n\nEnter your option: ";
        cin >> option;
        switch (option) {
            case 1: cout << "\nEnter an integer: ";
                    cin >> input;
                    var.insertBeg(input);
                    break;
            case 2: cout << "\nEnter an integer: ";
                    cin >> input;
                    var.insertEnd(input);
                    break;
            case 3: var.print();
                    break;
            case 4: var.printReverse();
                    break;
        }
    } while(option != 5);
    return 0;
}
