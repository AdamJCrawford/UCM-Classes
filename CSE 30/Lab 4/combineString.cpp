#include <iostream>
#include <string>
using namespace std;

string combineStr(string input, int numStrings)
{
   string combined;

   for (int i = 0; i < numStrings; i++)
   {
      combined += input;
   }
   return(combined);
}


int main()
{
   while (true)
   {
      string input;
      int    numStrings;
      cout << "Enter a string: ";
      cin >> input;
      cout << "Enter a number of times: ";
      cin >> numStrings;
      if (numStrings == 0)
      {
         return(0);
      }
      cout << "The resulting string is " << combineStr(input,
                                                       numStrings) <<
         endl << endl;
   }
   return(0);
}
