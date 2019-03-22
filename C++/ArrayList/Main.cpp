#include <iostream>
#include <limits.h>
#include <stddef.h>
#include "ArrayList.h"

using namespace std;

void ArrayList::view()
{
    for (int i = 0; i < this->current_pos; i++)
        cout << this->arr[i] << " ";
    cout << endl;
}

int main()
{
    ArrayList obj(2);
    int choice, ele, pos;
    bool n = true, flag = false;
    while (n)
    {
        cout << "1 . Insert an element\n2 . Delete\n3 . Access element\n4 . Show List\n5 . Exit\nEnter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the position and element to enter : ";
            cin >> pos >> ele;
            if (obj.insert(ele, pos))
                cout << "Operation Successfull!" << endl;
            else
                cout << "Operation Failed!\nEnter a valid position" << endl;
            break;
        case 2:
            cout << "Enter removing position : ";
            cin >> pos;
            if (obj.remove(pos) == INT_MIN)
                cout << "Failed!" << endl;
            else
                cout << "Done!" << endl;
            break;
        case 3:
            cout << "Enter the position : ";
            cin >> pos;
            if (obj.elementAt(pos) != INT_MIN)
                cout << "Element is : " << obj.elementAt(pos) << endl;
            else
                cout << "Failed" << endl;
            break;
        case 4:
            obj.view();
            break;
        case 5:
            flag = true;
            break;
        default:
            cout << "Wrong option" << endl;
            break;
        }
        if (flag)
            break;
        cout << "Want to enter again (1 - YES 0-NO) : ";
        cin >> n;
    }
    return 0;
}
