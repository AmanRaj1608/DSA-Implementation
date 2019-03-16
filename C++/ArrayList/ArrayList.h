#include <iostream>
#include <limits.h>

using namespace std;

class ArrayList
{
  private:
    int *arr;
    int current_pos, max_size;

  public:
    ArrayList();
    ArrayList(int max_size);
    bool insert(int element, int pos);
    int remove (int pos);
    int elementAt(int pos);
    bool isEmpty();
    int sizeOf();
    void view();
};

ArrayList::ArrayList()
{
    arr = new int[10]; //  If nothing is mentioned, by default size will be 10
    this->max_size = 10;
    this->current_pos = 0;
}
ArrayList::ArrayList(int max_size)
{
    arr = new int[max_size]; //  What should be the initial size of the array, given at the time of  object creation.
    this->max_size = max_size;
    this->current_pos = 0;
}
bool ArrayList::insert(int element, int pos)
{
    if (pos < 0 || pos > this->current_pos)
        return false; // Failure of insert operation, as the position entered is not valid.
    if (this->current_pos == this->max_size)
    {
        int *temp_arr = new int[2 * this->max_size]; //increase the size of the array, double +2 to that of first time
        this->max_size = 2 * (this->max_size + 1);
        for (int i = 0; i < this->current_pos; i++)
            temp_arr[i] = this->arr[i]; //copying the old array to the new one.
        this->arr = temp_arr;           //almost renaming
    }
    for (int i = pos + 1; i <= this->current_pos; i++)
        this->arr[i] = this->arr[i - 1];
    this->arr[pos] = element;
    this->current_pos++;
    return true;
}

int ArrayList::remove(int pos)
{
    if (pos < 0 || pos >= this->current_pos) // Failure of remove operation, as the position entered is not valid.
    {
        std::cerr << "Bad Index\n" ;
        return INT_MIN;
    }
    int x = this->arr[pos];
    for (int i = pos; i < this->current_pos - 1; i++)
        this->arr[i] = this->arr[i + 1];
    this->current_pos--;
    return x;
}

int ArrayList::elementAt(int pos)
{
    if (pos < 0 || pos >= this->current_pos) // Failure of access operation, as the position entered is not valid.
    {
        cerr << "Bad Index\n";
        return INT_MIN;
    }
    return this->arr[pos];
}

bool ArrayList::isEmpty()
{
    if (this->current_pos == 0)
        return true;
    return false;
}

int ArrayList::sizeOf()
{
    return this->current_pos;
}
