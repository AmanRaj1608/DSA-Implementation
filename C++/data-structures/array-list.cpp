// C++ implementation of Array List

#include <iostream>
#include <algorithm>

using namespace std;

class Array
{
public:
    int size, index, top, *arr;
    Array();
    void insertElement(int);
    void print();
    void printInReverse();
    bool isEmpty();
    void search(int);
    void deleteElement();
};

Array::Array()
{
    index = 0;
    size = 2;
    top = -1;
    arr = new int[size];
}

void Array::insertElement(int value)
{
    ++top;
    arr[index] = value;
    ++index;
    sort(arr, arr + index);
    if(index == size)
    {
        int *newArr = new int[size * 2];
        for(int i = 0; i < size; ++i)
            newArr[i] = arr[i];
        arr = newArr;
        size *= 2;
    }
}

void Array::print()
{
    if(top == -1)
    {
        cout << "\nThe array is empty.\n";
        return ;
    }
    cout << "\n";
    for(int i = 0; i < index; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

void Array::printInReverse()
{
    if(top == -1)
    {
        cout << "\nThe array is empty.\n";
        return ;
    }
    cout << "\n";
    for(int i = top; i >= 0; --i)
        cout << arr[i] << " ";
    cout << "\n";
}

bool Array::isEmpty()
{
    if(top == -1)
        return true;
    return false;
}

void Array::search(int value)
{
    if(top == -1)
    {
        cout << "\nThe array is empty.\n";
        return ;
    }
    bool found = false;
    for(int i = 0; i < index; ++i)
    {
        if(arr[i] == value)
        {
            cout << "\n" << value << " found at position: " << i + 1 << "\n";
            found = true;
        }
    }
    if(found == false)
        cout << "\n" << value << " is NOT present in the array.\n";
}

void Array::deleteElement()
{
    if(top == -1)
    {
        cout << "\nThe array is empty.\n";
        return ;
    }
    --top;
    --index;
}

int main()
{
    Array var;
    int option, input;
    do {
        cout << "\n\nARRAY LIST:\n";
        cout << "\n(1) Insert an element (at end)";
        cout << "\n(2) Delete an element (from end)";
        cout << "\n(3) Print the elements of the array";
        cout << "\n(4) Print the elements of the array in reverse order";
        cout << "\n(5) Check if the array is empty or NOT";
        cout << "\n(6) Search for an element";
        cout << "\n(7) Exit";
        cout << "\n\nEnter your option: ";
        cin >> option;
        switch (option) {
            case 1: cout << "\nEnter an integer: ";
                    cin >> input;
                    var.insertElement(input);
                    break;
            case 2: var.deleteElement();
                    break;
            case 3: var.print();
                    break;
            case 4: var.printInReverse();
                    break;
            case 5: if(var.isEmpty() == true)
                        cout << "\nThe array is empty.\n";
                    else
                        cout << "\nThe array is NOT empty.\n";
                    break;
            case 6: cout << "\nEnter an integer: ";
                    cin >> input;
                    var.search(input);
                    break;
        }
    } while(option != 7);
    return 0;
}
