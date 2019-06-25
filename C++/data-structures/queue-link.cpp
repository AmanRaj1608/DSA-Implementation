// C++ linked list implementation of Queue

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

class Queue
{
public:
    Node *front, *rear;
    Queue();
    void enqueue(int);
    void dequeue();
    void getFront();
    bool isEmpty();
    void print();
};

Queue::Queue() { front = rear = NULL; }

void Queue::enqueue(int value)
{
    Node *temp = new Node(value);
    if(front == NULL)
    {
        front = rear = temp;
        return ;
    }
    rear->next = temp;
    rear = temp;
}

void Queue::dequeue()
{
    if(front == NULL)
    {
        cout << "\nThe queue is empty.\n";
        return ;
    }
    Node *temp = front;
    front = front->next;
    delete temp;
}

void Queue::getFront()
{
    if(front == NULL)
    {
        cout << "\nThe queue is empty.\n";
        return ;
    }
    cout << "\n" << front->data << "\n";
}

bool Queue::isEmpty()
{
    if(front == NULL)
        return true;
    return false;
}

void Queue::print()
{
    if(front == NULL)
    {
        cout << "\nThe queue is empty.\n";
        return ;
    }
    Node *temp = front;
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
    Queue var;
    int option, input;
    do {
        cout << "\n\nQUEUE:\n";
        cout << "\n(1) Enqueue";
        cout << "\n(2) Dequeue";
        cout << "\n(3) Get the element at the front of the queue";
        cout << "\n(4) Check whether the queue is empty or not";
        cout << "\n(5) Print the elements of the queue";
        cout << "\n(6) Exit";
        cout << "\n\nEnter your option: ";
        cin >> option;
        switch (option) {
            case 1: cout << "\nEnter an integer: ";
                    cin >> input;
                    var.enqueue(input);
                    break;
            case 2: var.dequeue();
                    break;
            case 3: var.getFront();
                    break;
            case 4: if(var.isEmpty())
                    cout << "\nThe queue is empty.\n";
                    else
                    cout << "\nThe queue is NOT empty.\n";
                    break;
            case 5: var.print();
                    break;
        }
    } while(option != 6);
    return 0;
}
