#include <iostream>

using namespace std;

void sortArr(int *user_array, int& array_size, bool descending)
{
   for (int i = 1; i < array_size; i++)
   {
      int saved = user_array[i];
      int j     = i;
      //kind of a lot of stuff on the line but it checks if the sorted array should be descending uses the correct sign to get the desired result.
      while (j > 0 && (descending ? user_array[j - 1] < saved : user_array[j - 1] > saved))
      {
         user_array[j] = user_array[j - 1];
         j--;
      }
      user_array[j] = saved;
   }
}


int main()
{
   int array_size;

   cout << "Enter the size of the array: ";
   cin >> array_size;
   if (array_size < 1)
   {
      cout << "ERORR: you entered an incorrect value for the array size!";
      return -1;
   }

   int user_array[array_size];

   cout << "Enter the numbers in the array, sperated by a space, and press enter: ";
   for (int i = 0; i < array_size; i++)
   {
      cin >> user_array[i];
   }

   bool descending;

   cout << "Sort in ascending (0) or descending (1) order? ";
   cin >> descending;
   cout << endl;
   sortArr(user_array, array_size, descending);
   cout << "This is the sorted array in " << (descending ? "descending" : "ascending") << " order: " << endl;

   for (int i = 0; i < array_size; i++)
   {
      cout << user_array[i] << " ";
   }
   cout << endl;

   return 0;
}
