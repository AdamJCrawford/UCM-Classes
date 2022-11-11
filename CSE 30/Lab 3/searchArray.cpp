#include <iostream>

using namespace std;

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

  int number_to_seach_for;
  cout << "Enter a number to search for in the array: ";
  cin >> number_to_seach_for;

  for(int i = 0; i < array_size; i++)
  {
    if(user_array[i] == number_to_seach_for)
    {
      cout << "Found value " << number_to_seach_for << " at index " << i << ", which took " << i + 1 << " checks." << endl;
      if(i == 0)
      {
        cout << "We ran into the best case scenario!";
      }
      else if (i == array_size - 1)
      {
        cout << "We ran into the worst case scenario!";
      }
      return 0;
    }
  }
  cout << "The value " << number_to_seach_for << " was not found in the array";

  return 0;
}
