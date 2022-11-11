#include <iostream>
#include <ostream>
#include <string>

#include "Time.cpp"

using namespace std;

void print24Hour(Time timeclass)
{
    timeclass.getHour() <= 9 ? cout << "0" << timeclass.getHour():cout << timeclass.getHour();
    cout << ':';
    timeclass.getMinutes() <= 9 ? cout << "0" << timeclass.getMinutes():cout << timeclass.getMinutes();
    cout << ':';
    timeclass.getSeconds() <= 9 ? cout << "0" << timeclass.getSeconds():cout << timeclass.getSeconds();
}


bool checkFormat(string userString)
{
    //very manual checking, probably a better way of doing this but because there are only a few cases where we return false I think its fine.

    if (userString.size() != 8)
    {
        return false;
    }
    else if (!(isdigit(userString[0]) && isdigit(userString[1])))
    {
        return false;
    }
    else if (!(isdigit(userString[3]) && isdigit(userString[4])))
    {
        return false;
    }
    else if (!(isdigit(userString[6]) && isdigit(userString[7])))
    {
        return false;
    }
    else if (!(userString[2] == userString[5]) || (userString[2] != ':'))
    {
        return false;
    }
    else if ((10 * (userString[0] - '0') + (userString[1] - '0')) > 24)
    {
        return false;
    }
    else if ((10 * (userString[3] - '0') + (userString[4] - '0')) > 60)
    {
        return false;
    }
    else if ((10 * (userString[6] - '0') + (userString[7] - '0')) > 60)
    {
        return false;
    }
    return true;
}


int counter = 0;

bool getTimeFromUser(Time& userTime)
{
    string userString;

    counter ? cout << "Enter the end time for the lecture (format is HH:MM:SS): " : cout << "Enter the start time for the lecture (format is HH:MM:SS): ";

    getline(cin, userString);

    if (!checkFormat(userString))
    {
        cout << "The start time entered is invalid!" << endl;
        return false;
    }

    userTime.setHour((10 * (userString[0] - '0') + (userString[1] - '0')));
    userTime.setMinutes((10 * (userString[3] - '0') + (userString[4] - '0')));
    userTime.setSeconds((10 * (userString[6] - '0') + (userString[7] - '0')));
    counter++;
    return true;
}


int main()
{
    Time startTime;
    Time endTime;

    if (!getTimeFromUser(startTime))
    {
        return -1;
    }
    if (!getTimeFromUser(endTime))
    {
        return -1;
    }

    cout << "The lecture starts at ";
    print24Hour(startTime);
    cout << " and ends at ";
    print24Hour(endTime);
    cout << endl;

    return 0;
}
