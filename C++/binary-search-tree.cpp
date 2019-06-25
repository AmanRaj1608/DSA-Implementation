// C++ implementation of Binary Search Tree

#include <iostream>
#include <queue>

using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int);
};

Node::Node(int data)
{
    this->data = data;
    left = right = NULL;
}

Node * findMinValue(Node *r)
{
    if(r->left == NULL)
        return r;
    return findMinValue(r->left);
}

class binarySearchTree
{
public:
    Node *root;
    binarySearchTree();
    Node * insert(Node *, int);
    bool contains(Node *, int);
    Node * deletion(Node *, int);
    int height(Node *);
    bool minValueIterative(Node *);
    bool maxValueIterative(Node *);
    bool minValueRecursive(Node *);
    bool maxValueRecursive(Node *);
    void printInOrder(Node *);
    void printPreOrder(Node *);
    void printPostOrder(Node *);
    void printLevelOrder(Node *);
    int countLeaves(Node *);
};

binarySearchTree::binarySearchTree() { root = NULL; }

Node * binarySearchTree::insert(Node *r, int value)
{
    if(r == NULL)
        r = new Node(value);
    else if(value <= r->data)
        r->left = insert(r->left, value);
    else
        r->right = insert(r->right, value);
    return r;
}

bool binarySearchTree::contains(Node *r, int value)
{
    if(r == NULL)
        return false;
    if(value == r->data)
        return true;
    if(value < r->data)
        return contains(r->left, value);
    return contains(r->right, value);
}

Node * binarySearchTree::deletion(Node *r, int value)
{
    if(r == NULL)
        return r;
    if(value < r->data)
        r->left = deletion(r->left, value);
    else if(value > r->data)
        r->right = deletion(r->right, value);
    else
    {
        if(r->left == NULL)
        {
            Node *temp = r->right;
            delete r;
            return temp;
        }
        if(r->right == NULL)
        {
            Node *temp = r->left;
            delete r;
            return temp;
        }
        Node *temp = findMinValue(r->right);
        r->data = temp->data;
        r->right = deletion(r->right, temp->data);
    }
    return r;
}

int binarySearchTree::height(Node *r)
{
    if(r == NULL)
        return -1;
    int leftHeight = height(r->left);
    int rightHeight = height(r->right);
    if(leftHeight > rightHeight)
        return leftHeight + 1;
    return rightHeight + 1;
}

bool binarySearchTree::minValueIterative(Node *r)
{
    if(r == NULL)
        return false;
    Node *temp = r;
    while(temp->left != NULL)
        temp = temp->left;
    cout << "\n" << temp->data << "\n";
    return true;
}

bool binarySearchTree::maxValueIterative(Node *r)
{
    if(r == NULL)
        return false;
    Node *temp = r;
    while(temp->right != NULL)
        temp = temp->right;
    cout << "\n" << temp->data << "\n";
    return true;
}

bool binarySearchTree::minValueRecursive(Node *r)
{
    if(r == NULL)
        return false;
    if(r->left == NULL)
    {
        cout << "\n" << r->data << "\n";
        return true;
    }
    return minValueIterative(r->left);
}

bool binarySearchTree::maxValueRecursive(Node *r)
{
    if(r == NULL)
        return false;
    if(r->right == NULL)
    {
        cout << "\n" << r->data << "\n";
        return true;
    }
    return maxValueRecursive(r->right);
}

void binarySearchTree::printInOrder(Node *r)
{
    if(r != NULL)
    {
        printInOrder(r->left);
        cout << r->data << " ";
        printInOrder(r->right);
    }
}

void binarySearchTree::printPreOrder(Node *r)
{
    if(r != NULL)
    {
        cout << r->data << " ";
        printPreOrder(r->left);
        printPreOrder(r->right);
    }
}

void binarySearchTree::printPostOrder(Node *r)
{
    if(r != NULL)
    {
        printPostOrder(r->left);
        printPostOrder(r->right);
        cout << r->data << " ";
    }
}

void binarySearchTree::printLevelOrder(Node *r)
{
    if(r == NULL)
        return ;
    Node *cur;
    queue <Node *> Q;
    Q.push(r);
    cout << "\n";
    while(!Q.empty())
    {
        cur = Q.front();
        cout << cur->data << " ";
        if(cur->left != NULL)
            Q.push(cur->left);
        if(cur->right != NULL)
            Q.push(cur->right);
        Q.pop();
    }
    cout << "\n";
}

int binarySearchTree::countLeaves(Node *r)
{
    if(r == NULL)
        return 0;
    if(r->left == NULL && r->right == NULL)
        return 1;
    int leftCount = countLeaves(r->left);
    int rightCount = countLeaves(r->right);
    return leftCount + rightCount;
}

int main()
{
    binarySearchTree var;
    int option, input;
    do {
        cout << "\n\nBINARY SEARCH TREE:\n";
        cout << "\n(1) Insert a number";
        cout << "\n(2) Check if a particular number is present in the BST or not";
        cout << "\n(3) Delete a number from the BST";
        cout << "\n(4) Get the height of the BST";
        cout << "\n(5) Find the minimum value in the BST iteratively";
        cout << "\n(6) Find the maximum value in the BST iteratively";
        cout << "\n(7) Find the minimum value in the BST recursively";
        cout << "\n(8) Find the maximum value in the BST recursively";
        cout << "\n(9) Print the BST (in-order)";
        cout << "\n(10) Print the BST (pre-order)";
        cout << "\n(11) Print the BST (post-order)";
        cout << "\n(12) Print the BST (level-order)";
        cout << "\n(13) Get the number of leaf nodes in the BST";
        cout << "\n(14) Exit";
        cout << "\n\nEnter your option: ";
        cin >> option;
        switch (option) {
            case 1: cout << "\nEnter an integer: ";
                    cin >> input;
                    var.root = var.insert(var.root, input);
                    break;
            case 2: cout << "\nEnter an integer: ";
                    cin >> input;
                    if(var.contains(var.root, input))
                        cout << "\n" << input << " is present in the BST.\n";
                    else
                        cout << "\n" << input << " is NOT present in the BST.\n";
                    break;
            case 3: cout << "\nEnter an integer: ";
                    cin >> input;
                    var.root = var.deletion(var.root, input);
                    break;
            case 4: cout << "\nThe height of the BST is : " << var.height(var.root) << "\n";
                    break;
            case 5: if(!var.minValueIterative(var.root))
                        cout << "\nThe BST is empty.\n";
                    break;
            case 6: if(!var.maxValueIterative(var.root))
                        cout << "\nThe BST is empty.\n";
                    break;
            case 7: if(!var.minValueRecursive(var.root))
                        cout << "\nThe BST is empty.\n";
                    break;
            case 8: if(!var.maxValueRecursive(var.root))
                        cout << "\nThe BST is empty.\n";
                    break;
            case 9: cout << "\n";
                    var.printInOrder(var.root);
                    cout << "\n";
                    break;
            case 10:cout << "\n";
                    var.printPreOrder(var.root);
                    cout << "\n";
                    break;
            case 11:cout << "\n";
                    var.printPostOrder(var.root);
                    cout << "\n";
                    break;
            case 12:cout << "\n";
                    var.printLevelOrder(var.root);
                    cout << "\n";
                    break;
            case 13:cout << "\nNumber of leaf nodes in the BST = " << var.countLeaves(var.root) << "\n";
                    break;
        }
    } while(option != 14);
    return 0;
}
