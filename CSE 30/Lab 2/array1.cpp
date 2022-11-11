#include <iostream>
using namespace std;

int main()
{
  int size_of_array;
  cout << "Enter the size of the array" << endl;
  cin >> size_of_array;

  //if the array will not have a positive size then it is invalid
  if (size_of_array <= 0)
  {
    cout << "ERROR: you entered an incorrect value for the array size" << endl;
    return 0;
  }

  int user_array[size_of_array];
  cout << "Enter the numbers in the array, separated by a space, and press enter: ";

  for(int i = 0; i < size_of_array; i++)
  {
    cin >> user_array[i];
  }

  //This is keeping track if the array is increasing, if at any point it does not increase then increasing_array will become false.
  bool increasing_array = true;

  for(int i = 0; i < size_of_array - 1; i++)
  {
      //This is met only when the array is not increasing
      if (user_array[i] > user_array[i + 1])
      {
          cout << "This is NOT an increasing array!" << endl;
          increasing_array = false;
          break;
      }
  }

  if(increasing_array)
  {
    cout << "This IS an increasing array" << endl;
  }

  //Print out all of the elements in the list.
  for (int i = 0; i < size_of_array; i++)
  {
      cout << user_array[i] << " ";
  }

  return 0;
}
