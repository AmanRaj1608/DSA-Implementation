// C++ implementation of Linked List

#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int);
};

Node::Node(int data)
{
    this->data = data;
    next = NULL;
}

class LinkedList
{
public:
    Node *head, *tail;
    int count;
    LinkedList();
    void insertBeg(int);
    void insertEnd(int);
    void insertPos(int, int);
    void deleteBeg();
    void deleteEnd();
    void deletePos(int);
    void print();
    void printReverse(Node *);
    void reverseIter();
    void reverseRec(Node *);
    bool isEmpty();
    void search(int);
};

LinkedList::LinkedList()
{
    head = tail = NULL;
    count = 0;
}

void LinkedList::insertBeg(int value)
{
    ++count;
    Node *temp = new Node(value);
    if(head == NULL)
    {
        head = tail = temp;
        return ;
    }
    temp->next = head;
    head = temp;
}

void LinkedList::insertEnd(int value)
{
    ++count;
    Node *temp = new Node(value);
    if(head == NULL)
    {
        head = tail = temp;
        return ;
    }
    tail->next = temp;
    tail = temp;
}

void LinkedList::deleteBeg()
{
    if(head == NULL)
    {
        cout << "\nThe list is empty.\n";
        return ;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
    --count;
}

void LinkedList::print()
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

void LinkedList::printReverse(Node *r)
{
    if(r == NULL)
        return ;
    printReverse(r->next);
    cout << r->data << " ";
}

void LinkedList::reverseIter()
{
    Node *before = NULL, *after = NULL, *cur = head;
    while(cur != NULL)
    {
        after = cur->next;
        cur->next = before;
        before = cur;
        cur = after;
    }
    head = before;
}

void LinkedList::reverseRec(Node *r)
{
    if(r->next == NULL)
    {
        head = r;
        return ;
    }
    reverseRec(r->next);
    Node *temp = r->next;
    temp->next = r;
    r->next = NULL;
}

bool LinkedList::isEmpty()
{
    if(head == NULL)
        return true;
    return false;
}

void LinkedList::deleteEnd()
{
    if(head == NULL)
    {
        cout << "\nThe list is empty.\n";
        return ;
    }
    int i = 1;
    Node *temp = head;
    while(i != count - 1)
    {
        temp = temp->next;
        ++i;
    }
    Node *ptr = temp->next;
    temp->next = NULL;
    // tail = temp;
    delete ptr;
    --count;
}

void LinkedList::deletePos(int pos)
{
    if(pos < 1 || pos > count)
    {
        cout << "\nInvalid position.\n";
        return ;
    }
    if(head == NULL)
    {
        cout << "\nThe list is empty.\n";
        return ;
    }
    if(pos == 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        --count;
        return ;
    }
    int i;
    Node *temp = head, *ptr = NULL;
    while(i != pos)
    {
        if(i == pos - 1)
            ptr = temp;
        temp = temp->next;
        ++i;
    }
    ptr->next = temp->next;
    temp->next = NULL;
    delete temp;
    --count;
}

void LinkedList::insertPos(int value, int pos)
{
    ++count;
    if(pos < 1 || pos > count)
    {
        cout << "\nInvalid position.\n";
        return ;
    }
    Node *temp = new Node(value);
    if(pos == 1)
    {
        if(head == NULL)
        {
            head = tail = temp;
            return ;
        }
        temp->next = head;
        head = temp;
    }
    else
    {
        int i = 1;
        Node *ptr = head;
        while(i != pos - 1)
        {
            ptr = ptr->next;
            ++i;
        }
        temp->next = ptr->next;
        ptr->next = temp;
    }
}

void LinkedList::search(int value)
{
    if(head == NULL)
    {
        cout << "\nThe list is empty.\n";
        return ;
    }
    bool found = false;
    int i = 1;
    Node *temp = head;
    while(temp != NULL)
    {
        if(temp->data == value)
        {
            cout << "\n" << value << " found at position: " << i << "\n";
            found = true;
        }
        temp = temp->next;
        ++i;
    }
    if(found == false)
        cout << "\n" << value << " is NOT present in the list.\n";
}

int main()
{
    LinkedList var;
    int option, input, position;
    do {
        cout << "\n\nLINKED LIST:\n";
        cout << "\n(1) Insert at the beginning";
        cout << "\n(2) Insert at the end";
        cout << "\n(3) Insert at a particular position";
        cout << "\n(4) Delete from the beginning";
        cout << "\n(5) Delete from the end";
        cout << "\n(6) Delete from a particular position";
        cout << "\n(7) Print the list";
        cout << "\n(8) Print the list in reverse order";
        cout << "\n(9) Reverse the list iteratively";
        cout << "\n(10) Reverse the list recursively";
        cout << "\n(11) Search for an element";
        cout << "\n(12) Check if the list is empty";
        cout << "\n(13) Exit";
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
            case 3: cout << "\nEnter an integer: ";
                    cin >> input;
                    cout << "\nEnter a position: ";
                    cin >> position;
                    var.insertPos(input, position);
                    break;
            case 4: var.deleteBeg();
                    break;
            case 5: var.deleteEnd();
                    break;
            case 6: cout << "\nEnter a position: ";
                    cin >> position;
                    var.deletePos(position);
                    break;
            case 7: var.print();
                    break;
            case 8: cout << "\n";
                    var.printReverse(var.head);
                    cout << "\n";
                    break;
            case 9: var.reverseIter();
                    break;
            case 10:var.reverseRec(var.head);
                    break;
            case 11:cout << "\nEnter an integer: ";
                    cin >> input;
                    var.search(input);
                    break;
            case 12:if(var.isEmpty())
                        cout << "\nThe list is empty.\n";
                    else
                        cout << "\nThe list is NOT empty.\n";
                    break;
        }
    } while(option != 13);
    return 0;
}
