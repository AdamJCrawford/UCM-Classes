#include <iostream>
#include <string>
using namespace std;

int main()
{
  //cout << "Hello World!";


  // string first_name;
  // cout << "Please enter your name: ";
  // cin >> first_name;
  // cout << "Welcome to CSE030 " << first_name;

  // int num_lines;
  // cout << "Enter the number of lines for the punishment: ";
  // cin >> num_lines;
  // if (num_lines < 1)
  // {
  //   cout << "You entered an incorrect value for the number of lines!";
  // }
  // for(int i = 0; i < num_lines; i++)
  // {
  //   cout << "I will always use object oriented programming. ";
  // }

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
