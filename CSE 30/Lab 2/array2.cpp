#include <iostream>
#include <string>
using namespace std;

int main()
{
  string user_input;
  string reversed_input;

  cout << "Enter the string to reverse ";
  cin >> user_input;
  //Go through the user_input backwards and make a new string with those revsed chars.
  for(int i = user_input.length(); i >= 0; i--)
  {
    reversed_input += user_input[i];
  }

  cout << reversed_input;
  return 0;
}
