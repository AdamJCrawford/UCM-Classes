#include <iostream>

using namespace std;

int main()
{
  int size;
  cout << "Enter the size of a 2D array ";
  cin >> size;
  //Check if the entered size is valid, that is between 1 and 10
  if(size > 10 || size < 1)
  {
    cout << "invalid size";
    return 0;
  }
  int user_array[size][size];

  //nested for loops to process user input. NOTE almost certainly a better way of doing this but as the size is so small the n^2 should not matter.
  for(int i = 0; i < size; i++)
  {
    cout << "Enter the values in the array for row " << i + 1 << ", separated by a space, and press enter: ";
    for(int j = 0; j < size; j++)
    {
      cin >> user_array[i][j];
    }
  }
  // count the number of negative numbers in the array
  int num_of_neg_nums = 0;
  for(int i = 0; i < size; i++)
  {
    for(int j = 0; j < size; j++)
    {
      if(user_array[i][j] < 0)
      {
        num_of_neg_nums++;
      }
    }
  }
  //if num_of_neg_nums is not 0
  if(num_of_neg_nums)
  {
    cout << "There are " << num_of_neg_nums << " negative values!";
  }
  else
  {
    cout << "All values are non-negative!";
  }
  return 0;
}
