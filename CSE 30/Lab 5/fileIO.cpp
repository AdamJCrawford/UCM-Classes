#include <iostream>
#include <fstream>
#include <string>
#include <typeinfo>

using namespace std;

int main(void)
{
    ifstream file;
    string   data;

    file.open("words_in.txt");
    int counter = 0;

    while (!file.eof())
    {
        getline(file, data);
        counter++;
    }
    string strings[counter];

    file.close();
    ifstream file2;
    string   data2;

    file2.open("words_in.txt");
    for (int i = 0; i < counter; i++)
    {
        getline(file2, data2);
        strings[i] = data2;
    }

    ofstream fileOut;

    fileOut.open("words_out.txt");

    for (int i = 0; i < counter; i++)
    {
        i + 1 < counter? fileOut << strings[i] << "\n" : fileOut << strings[i];
    }
    file2.close();
    fileOut.close();
    return 0;
}
