#include <iostream>

using namespace std;

int find_min(int array[], int array_size)
{
  int min = 0;
  for(int i = 0; i < array_size; i ++)
  {
    if(array[i] < array[min])
    {
      min = i;
    }
  }
  return min;
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
  int num_swaps = 0;
  for(int i = 0; i < array_size; i++)
  {
    int min = find_min(user_array, array_size - i);
    int temp = user_array[array_size - i - 1];
    //cout << temp << " " << user_array[max] << endl;
    if(user_array[min] != temp)
    {
      user_array[array_size - i - 1] = user_array[min];
      user_array[min] = temp;
      num_swaps++;
    }
  }

  cout << "This is the sorted array in decending order: ";

  for(int i = 0; i < array_size; i ++)
  {
    cout << user_array[i] << " ";
  }

  cout << endl << "The algorithm selected the minimum for the traverse of the array" << endl;
  cout << "It took " << num_swaps << " swaps to sort the array";
  return 0;
}
