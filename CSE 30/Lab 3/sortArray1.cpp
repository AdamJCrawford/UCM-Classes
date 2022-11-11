#include <iostream>

using namespace std;

int find_max(int array[], int array_size)
{
  int max = 0;
  for(int i = 0; i < array_size; i ++)
  {
    if(array[i] > array[max])
    {
      max = i;
    }
  }
  return max;
}

int main()
{
  int array_size;
  cout << "Enter the size of the array: ";
  cin >> array_size;
  if(array_size < 1)
  {
    cout << "ERORR: you entered an incorrect value for the array size!";
    return -1;
  }

  int user_array[array_size];
  cout << " Enter the numbers in the array, sperated by a space, and press enter: ";
  for(int i = 0; i < array_size; i++)
  {
    cin >> user_array[i];
  }

  for(int i = 0; i < array_size; i++)
  {
    int max = find_max(user_array, array_size - i);
    int temp = user_array[array_size - i - 1];
    //cout << temp << " " << user_array[max] << endl;
    if(user_array[max] != temp)
    {
      user_array[array_size - i - 1] = user_array[max];
      user_array[max] = temp;
    }
  }

  cout << "This is the sorted array in ascending order: ";

  for(int i = 0; i < array_size; i ++)
  {
    cout << user_array[i] << " ";
  }

  cout << endl << "The algorithm selected the maximum for the traverse of the array" << endl;
  return 0;
}
