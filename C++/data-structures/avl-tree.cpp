// C++ implementation of AVL Tree

#include <iostream>
#include <queue>

using namespace std;

class Node
{
public:
    int data, height;
    Node *left, *right;
    Node(int);
    int getHeight(Node *);
    int getBalance(Node *);
};

Node::Node(int data)
{
    this->data = data;
    height = 0;
    left = right = NULL;
}

int Node::getHeight(Node *r)
{
    if(r == NULL)
        return -1;
    int leftHeight = getHeight(r->left);
    int rightHeight = getHeight(r->right);
    if(leftHeight > rightHeight)
        return leftHeight + 1;
    return rightHeight + 1;
}

int Node::getBalance(Node *r) { return getHeight(r->left) - getHeight(r->right); }

Node * findMinValue(Node *r)
{
    if(r->left == NULL)
        return r;
    return findMinValue(r->left);
}

class AVLtree
{
public:
    Node *root;
    AVLtree();
    Node * insert(Node *, int);
    Node * deletion(Node *, int);
    bool contains(Node *, int);
    void printLevelOrder(Node *);
    Node * leftRotate(Node *);
    Node * rightRotate(Node *);
};

AVLtree::AVLtree() { root = NULL; }

bool AVLtree::contains(Node *r, int value)
{
    if(r == NULL)
        return false;
    if(value == r->data)
        return true;
    if(value < r->data)
        return contains(r->left, value);
    return contains(r->right, value);

}

void AVLtree::printLevelOrder(Node *r)
{
    if(r == NULL)
    {
        cout << "\nThe AVL tree is empty.\n";
        return ;
    }
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

Node * AVLtree::leftRotate(Node *parent)
{
    Node *child = parent->right;
    Node *temp = child->left;

    child->left = parent;
    parent->right = temp;

    parent->height = parent->getHeight(parent);
    child->height = child->getHeight(child);

    return child;
}

Node * AVLtree::rightRotate(Node *parent)
{
    Node *child = parent->left;
    Node *temp = child->right;

    child->right = parent;
    parent->left = temp;

    parent->height = parent->getHeight(parent);
    child->height = child->getHeight(child);

    return child;
}

Node * AVLtree::insert(Node *r, int value)
{
    if(r == NULL)
        r = new Node(value);
    else if(value < r->data)
        r->left = insert(r->left, value);
    else if(value > r->data)
        r->right = insert(r->right, value);
    else
        return r;

    r->height = r->getHeight(r);
    int balance = r->getBalance(r);

    if(balance > 1 && value < r->left->data)
        return rightRotate(r);

    if(balance > 1 && value > r->left->data)
    {
        r->left = leftRotate(r->left);
        return rightRotate(r);
    }

    if(balance < -1 && value > r->right->data)
        return leftRotate(r);

    if(balance < -1 && value < r->right->data)
    {
        r->right = rightRotate(r->right);
        return leftRotate(r);
    }

    return r;
}

Node * AVLtree::deletion(Node *r, int value)
{
    if(r == NULL)
    {
        cout << "\nThe AVL tree is empty.\n";
        return r;
    }
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

    r->height = r->getHeight(r);
    int balance = r->getBalance(r);

    if(balance > 1 && r->left->getBalance(r->left) >= 0)
        return rightRotate(r);

    if(balance > 1 && r->left->getBalance(r->left) < 0)
    {
        r->left = leftRotate(r->left);
        return rightRotate(r);
    }

    if(balance < -1 && r->right->getBalance(r->right) <= 0)
        return leftRotate(r);

    if(balance < -1 && r->right->getBalance(r->right) > 0)
    {
        r->right = rightRotate(r->right);
        return leftRotate(r);
    }

    return r;
}

int main()
{
    AVLtree var;
    int option, input;
    do {
        cout << "\n\nAVL TREE:\n";
        cout << "\n(1) Insert an element in the AVL tree (duplicate elements are NOT allowed)";
        cout << "\n(2) Delete an element from the AVL tree";
        cout << "\n(3) Check whether a particular element is present in the AVL tree or not";
        cout << "\n(4) Print the elements of the AVL tree (level order)";
        cout << "\n(5) Exit";
        cout << "\n\nEnter your option: ";
        cin >> option;
        switch (option) {
            case 1: cout << "\nEnter an integer: ";
                    cin >> input;
                    var.root = var.insert(var.root, input);
                    break;
            case 2: cout << "\nEnter an integer: ";
                    cin >> input;
                    var.root = var.deletion(var.root, input);
                    break;
            case 3: cout << "\nEnter an integer: ";
                    cin >> input;
                    if(var.contains(var.root, input))
                        cout << "\n" << input << " is present in the AVL tree.\n";
                    else
                        cout << "\n" << input << " is NOT present in the AVL tree.\n";
                    break;
            case 4: var.printLevelOrder(var.root);
                    break;
        }
    } while(option != 5);
    return 0;
}
