// C++ implementation of Min Heap

#include <iostream>

using namespace std;

class minHeap
{
public:
    int capacity, size, *arr;
    minHeap();
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
    void insert(int);
    bool deleteMin();
    bool peek();
    void heapifyUp();
    void heapifyDown();
    void printLevelOrder();
};

minHeap::minHeap()
{
    capacity = 2;
    size = 0;
    arr = new int[capacity];
}

int minHeap::getLeftChildIndex(int index) { return 2*index + 1; }

int minHeap::getRightChildIndex(int index) { return 2*index + 2; }

int minHeap::getParentIndex(int index) { return (index - 1)/2; }

bool minHeap::hasLeftChild(int index) { return getLeftChildIndex(index) < size; }

bool minHeap::hasRightChild(int index) { return getRightChildIndex(index) < size; }

bool minHeap::hasParent(int index) { return getParentIndex(index) >= 0; }

int minHeap::leftChild(int index) { return arr[getLeftChildIndex(index)]; }

int minHeap::rightChild(int index) { return arr[getRightChildIndex(index)]; }

int minHeap::parent(int index) { return arr[getParentIndex(index)]; }

void minHeap::swap(int firstIndex, int secondIndex)
{
    int temp = arr[firstIndex];
    arr[firstIndex] = arr[secondIndex];
    arr[secondIndex] = temp;
}

void minHeap::checkCapacity()
{
    if(size == capacity)
    {
        int *newArr = new int [capacity * 2];
        for(int i = 0; i < size; ++i)
            newArr[i] = arr[i];
        arr = newArr;
        capacity *= 2;
    }
}

bool minHeap::peek()
{
    if(size == 0)
        return false;
    cout << "\n" << arr[0] << "\n";
    return true;
}

void minHeap::insert(int value)
{
    checkCapacity();
    arr[size] = value;
    ++size;
    heapifyUp();
}

bool minHeap::deleteMin()
{
    if(size == 0)
        return false;
    cout << "\n" << arr[0] << "\n";
    arr[0] = arr[size - 1];
    --size;
    heapifyDown();
    return true;
}

void minHeap::heapifyUp()
{
    int index = size - 1;
    while(hasParent(index) && parent(index) > arr[index])
    {
        swap(getParentIndex(index), index);
        index = getParentIndex(index);
    }
}

void minHeap::heapifyDown()
{
    int index = 0;
    while(hasLeftChild(index))
    {
        int smallerChildIndex = getLeftChildIndex(index);
        if(hasRightChild(index) && rightChild(index) < leftChild(index))
            smallerChildIndex = getRightChildIndex(index);
        if(arr[index] <= arr[smallerChildIndex])
            break;
        swap(index, smallerChildIndex);
        index = smallerChildIndex;
    }
}

void minHeap::printLevelOrder()
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
    minHeap var;
    int option, input;
    do {
        cout << "\n\nMIN-HEAP:\n";
        cout << "\n(1) Insert an element in the heap";
        cout << "\n(2) Delete the minimum element present in the heap";
        cout << "\n(3) Get the minimum element present in the heap";
        cout << "\n(4) Print the elements of the heap (level order)";
        cout << "\n(5) Exit";
        cout << "\n\nEnter your option: ";
        cin >> option;
        switch (option) {
            case 1: cout << "\nEnter an integer: ";
                    cin >> input;
                    var.insert(input);
                    break;
            case 2: if(!var.deleteMin())
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
