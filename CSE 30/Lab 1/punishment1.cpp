#include <iostream>
using namespace std;

int main()
{
  int num_lines;
  cout << "Enter the number of lines for the punishment: ";
  cin >> num_lines;
  if (num_lines < 1)
  {
    cout << "You entered an incorrect value for the number of lines!";
  }
  for(int i = 0; i < num_lines; i++)
  {
    cout << "I will always use object oriented programming. ";
  }
  return 0;
}