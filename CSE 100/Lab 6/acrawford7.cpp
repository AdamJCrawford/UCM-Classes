#include <iostream>
#include <iterator>
#include <list>
#include <string>
using namespace std;

struct index
{
    int i;
    int j;
};

string deleteKey(list<int> *nums[], string usr, index val, int size)
{
    list<int>::iterator it = nums[val.i]->begin();

    advance(it, val.j);
    int value = *it;

    nums[val.i]->erase(it);
    return to_string(value);
}


int returnHash(int val, int mod)
{
    return val % mod;
}


void insert(list<int> *arr[], string val, int size)
{
    int num = stoi(val);

    arr[returnHash(num, size)]->push_front(num);
}


index search(list<int> *arr[], string usr, int size)
{
    index returnVal;

    returnVal.i = -1;
    returnVal.j = -1;
    int num = stoi(usr);
    int j   = 0;

    for (auto item : *arr[returnHash(num, size)])
    {
        if (item == num)
        {
            returnVal.i = returnHash(num, size);
            returnVal.j = j;
            return returnVal;
        }
        j++;
    }
    return returnVal;
}


void print(list<int> *arr, int size)
{
    int                 counter = 0;
    list<int>::iterator it;

    for (it = arr->begin(); it != arr->end(); ++it)
    {
        cout << *it << "->";
    }
    cout << ";\n";
}


int main()
{
    int size;

    cin >> size;
    list<int> *arr[size];

    for (int i = 0; i < size; i++)
    {
        arr[i] = new list<int>;
    }
    string usr;

    while (usr != "e")
    {
        cin >> usr;
        if (usr[0] == 'i')
        {
            usr.erase(0, 1);
            insert(arr, usr, size);
        }
        else if (usr[0] == 'd')
        {
            usr.erase(0, 1);
            index values = search(arr, usr, size);
            values.i != -1 ? cout << deleteKey(arr, usr, values, size) << ":DELETED;\n" : cout << usr << ":DELETE_FAILED;\n";
        }
        else if (usr[0] == 's')
        {
            usr.erase(0, 1);
            index values = search(arr, usr, size);
            values.i != -1 ? cout << usr << ":FOUND_AT" << values.i << "," << values.j << ";\n" : cout << usr << ":NOT_FOUND;\n";
        }
        else if (usr[0] == 'o')
        {
            for (int i = 0; i < size; i++)
            {
                cout << i << ":";
                print(arr[i], size);
            }
        }
    }
    return 0;
}
