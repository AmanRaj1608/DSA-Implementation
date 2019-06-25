// C++ implementation of Max Heap

#include <iostream>

using namespace std;

class maxHeap
{
public:
    int capacity, size, *arr;
    maxHeap();
    int getLeftChildIndex(int);
    int getRightChildIndex(int);
    int getParentIndex(int);
    bool hasLeftChild(int);
    bool hasRightChild(int);
    bool hasParent(int);
    int leftChild(int);
    int rightChild(int);
    int parent(int);
    void swap(int, int);
    void checkCapacity();
    bool peek();
    void insert(int);
    bool deleteMax();
    void heapifyUp();
    void heapifyDown();
    void printLevelOrder();
};

maxHeap::maxHeap()
{
    size = 0;
    capacity = 2;
    arr = new int[capacity];
}

int maxHeap::getLeftChildIndex(int index) { return 2*index + 1; }

int maxHeap::getRightChildIndex(int index) { return 2*index + 2; }

int maxHeap::getParentIndex(int index) { return (index - 1)/2; }

bool maxHeap::hasLeftChild(int index) { return getLeftChildIndex(index) < size; }

bool maxHeap::hasRightChild(int index) { return getRightChildIndex(index) < size; }

bool maxHeap::hasParent(int index) { return getParentIndex(index) >= 0; }

int maxHeap::leftChild(int index) { return arr[getLeftChildIndex(index)]; }

int maxHeap::rightChild(int index) { return arr[getRightChildIndex(index)]; }

int maxHeap::parent(int index) { return arr[getParentIndex(index)]; }

void maxHeap::swap(int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void maxHeap::checkCapacity()
{
    if(size == capacity)
    {
        int *newArr = new int[capacity * 2];
        for(int i = 0; i < size; ++i)
            newArr[i] = arr[i];
        arr = newArr;
        capacity *= 2;
    }
}

bool maxHeap::peek()
{
    if(size == 0)
        return false;
    cout << "\n" << arr[0] << "\n";
    return true;
}

void maxHeap::insert(int value)
{
    checkCapacity();
    arr[size] = value;
    ++size;
    heapifyUp();
}

bool maxHeap::deleteMax()
{
    if(size == 0)
        return false;
    cout << "\n" << arr[0] << "\n";
    arr[0] = arr[size - 1];
    --size;
    heapifyDown();
    return true;
}

void maxHeap::heapifyUp()
{
    int index = size - 1;
    while(hasParent(index) && parent(index) < arr[index])
    {
        swap(getParentIndex(index), index);
        index = getParentIndex(index);
    }
}

void maxHeap::heapifyDown()
{
    int index = 0;
    while(hasLeftChild(index))
    {
        int largerChildIndex = getLeftChildIndex(index);
        if(hasRightChild(index) && rightChild(index) > leftChild(index))
            largerChildIndex = getRightChildIndex(index);
        if(arr[index] >= arr[largerChildIndex])
            break;
        swap(index, largerChildIndex);
        index = largerChildIndex;
    }
}

void maxHeap::printLevelOrder()
{
    if(size == 0)
    {
        cout << "\nThe heap is empty.\n";
        return ;
    }
    cout << "\n";
    for(int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    maxHeap var;
    int option, input;
    do {
        cout << "\n\nMAX-HEAP:\n";
        cout << "\n(1) Insert an element in the heap";
        cout << "\n(2) Delete the maximum element present in the heap";
        cout << "\n(3) Print the maximum element present in the heap";
        cout << "\n(4) Print the elements of the heap (level order)";
        cout << "\n(5) Exit";
        cout << "\n\nEnter your option: ";
        cin >> option;
        switch (option) {
            case 1: cout << "\nEnter an integer: ";
                    cin >> input;
                    var.insert(input);
                    break;
            case 2: if(!var.deleteMax())
                        cout << "\nThe heap is empty.\n";
                    break;
            case 3: if(!var.peek())
                        cout << "\nThe heap is empty.\n";
                    break;
            case 4: var.printLevelOrder();
                    break;
        }
    } while(option != 5);
    return 0;
}
