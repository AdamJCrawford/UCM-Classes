#include <iostream>
using namespace std;

int main()
{
  int num_lines, typo_line;
  cout << "Enter the number of lines for the punishment: ";
  cin >> num_lines;
  if (num_lines < 1)
  {
    cout << "You entered an incorrect value for the number of lines!";
    return 0;
  }
  cout << "Enter the line for which we want to make a typo: ";
  cin >> typo_line;
  if (typo_line < 1)
  {
    cout << "You entered an incorrect value for the line typo!";
    return 0;
  }
  for(int i = 0; i < num_lines; i++)
  {
    if(i != typo_line - 1)
    {
      cout << "I will always use object oriented programming. ";
    }
    else
    {
      cout << "I will always use object oriented programing. ";
    }
  }
  return 0;
}