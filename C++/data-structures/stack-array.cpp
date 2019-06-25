// C++ array list implementation of Stack

#include <iostream>

using namespace std;

class Stack
{
public:
    int size, index, top, *arr;
    Stack();
    void push(int);
    void pop();
    void getTop();
    bool isEmpty();
    void print();
};

Stack::Stack()
{
    size = 2;
    index = 0;
    top = -1;
    arr = new int[size];
}

void Stack::push(int value)
{
    ++top;
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

void Stack::pop()
{
    if(top == -1)
    {
        cout << "\nThe stack is empty.\n";
        return ;
    }
    --top;
    --index;
}

void Stack::getTop()
{
    if(top == -1)
    {
        cout << "\nThe stack is empty.\n";
        return ;
    }
    cout << "\n" << arr[top] << "\n";
}

bool Stack::isEmpty()
{
    if(top == -1)
        return true;
    return false;
}

void Stack::print()
{
    if(top == -1)
    {
        cout << "\nThe stack is empty.\n";
        return ;
    }
    cout << "\n";
    for(int i = top; i >= 0; --i)
        cout << arr[i] << " ";
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
