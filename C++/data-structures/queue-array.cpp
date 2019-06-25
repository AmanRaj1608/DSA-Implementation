// C++ array list implementation of Queue

#include <iostream>

using namespace std;

class Queue
{
public:
    int size, index, front, *arr;
    Queue();
    void enqueue(int);
    void dequeue();
    void getFront();
    bool isEmpty();
    void print();
};
    Queue::Queue()
    {
        size = 2;
        front = -1;
        arr = new int[size];
    }

    void Queue::enqueue(int value)
    {
        if(front == -1)
        {
            ++front;
            index = 0;
        }
        arr[index] = value;
        ++index;
        if(index == size)
        {
            int *newArr = new int[size * 2];
            for(int i = 0; i < size; ++i)
                newArr[i] = arr[i];
            arr = newArr;
            size *= 2;
        }
    }

    void Queue::dequeue()
    {
        if(front == -1)
        {
            cout << "\nThe queue is empty.\n";
            return ;
        }
        if(front == index - 1)
        {
            front = -1;
            return ;
        }
        ++front;
    }

    void Queue::getFront()
    {
        if(front == -1)
        {
            cout << "\nThe queue is empty.\n";
            return ;
        }
        cout << "\n" << arr[front] << "\n";
    }

    bool Queue::isEmpty()
    {
        if(front == -1)
            return true;
        return false;
    }

    void Queue::print()
    {
        if(front == -1)
        {
            cout << "\nThe queue is empty.\n";
            return ;
        }
        cout << "\n";
        for(int i = front; i < index; ++i)
            cout << arr[i] << " ";
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
