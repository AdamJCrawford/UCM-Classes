#include <iostream>

using namespace std;

int find_point(int array[], int array_size, bool max)
{
   int extremeValue = 0;

   if (max)
   {
      for (int i = 0; i < array_size; i++)
      {
         if (array[i] < array[extremeValue])
         {
            extremeValue = i;
         }
      }
   }
   else
   {
      for (int i = 0; i < array_size; i++)
      {
         if (array[i] > array[extremeValue])
         {
            extremeValue = i;
         }
      }
   }
   return extremeValue;
}


void sortArr(int user_array[], int array_size, bool descending)
{
   if (descending)
   {
      for (int i = 0; i < array_size; i++)
      {
         int extremeValue = find_point(user_array, array_size - i, true);
         int temp         = user_array[array_size - i - 1];
         if (user_array[extremeValue] != temp)
         {
            user_array[array_size - i - 1] = user_array[extremeValue];
            user_array[extremeValue]       = temp;
         }
      }
   }
   else
   {
      for (int i = 0; i < array_size; i++)
      {
         int extremeValue = find_point(user_array, array_size - i, false);
         int temp         = user_array[array_size - i - 1];
         if (user_array[extremeValue] != temp)
         {
            user_array[array_size - i - 1] = user_array[extremeValue];
            user_array[extremeValue]       = temp;
         }
      }
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
   sortArr(user_array, array_size, descending);
   cout << "This is the sorted array in " << (descending ? "descending" : "ascending") << " order: " << endl;

   for (int i = 0; i < array_size; i++)
   {
      cout << user_array[i] << " ";
   }
   cout << endl;

   return 0;
}
