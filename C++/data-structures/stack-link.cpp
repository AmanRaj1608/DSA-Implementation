// C++ linked list implementation of Stack

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

class Stack
{
public:
    Node *top;
    Stack();
    void push(int);
    void pop();
    void getTop();
    bool isEmpty();
    void print();
};

Stack::Stack() { top = NULL; }

void Stack::push(int value)
{
    Node *temp = new Node(value);
    if(top == NULL)
    {
        top = temp;
        return ;
    }
    temp->next = top;
    top = temp;
}

void Stack::pop()
{
    if(top == NULL)
    {
        cout << "\nThe stack is empty.\n";
        return ;
    }
    Node *temp = top;
    top = top->next;
    delete temp;
}

void Stack::getTop()
{
    if(top == NULL)
    {
        cout << "\nThe stack is empty.\n";
        return ;
    }
    cout << "\n" << top->data << "\n";
}

bool Stack::isEmpty()
{
    if(top == NULL)
        return true;
    return false;
}

void Stack::print()
{
    if(top == NULL)
    {
        cout << "\nThe stack is empty.\n";
        return ;
    }
    Node *temp = top;
    cout << "\n";
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

int main()
{
    Stack var;
    int option, input;
    do {
        cout << "\n\nSTACK:\n";
        cout << "\n(1) Push";
        cout << "\n(2) Pop";
        cout << "\n(3) Get the top-most element of the stack";
        cout << "\n(4) Check whether the stack is empty or not";
        cout << "\n(5) Print the elements of the stack";
        cout << "\n(6) Exit";
        cout << "\n\nEnter your option: ";
        cin >> option;
        switch (option) {
            case 1: cout << "\nEnter an integer: ";
                    cin >> input;
                    var.push(input);
                    break;
            case 2: var.pop();
                    break;
            case 3: var.getTop();
                    break;
            case 4: if(var.isEmpty())
                        cout << "\nThe stack is empty.\n";
                    else
                        cout << "\nThe stack is NOT empty.\n";
                    break;
            case 5: var.print();
                    break;
        }
    } while(option != 6);
    return 0;
}
