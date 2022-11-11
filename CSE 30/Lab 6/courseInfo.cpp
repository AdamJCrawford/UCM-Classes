#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Time
{
    int hour;
    int minutes;
    int seconds;
};

struct Course
{
    string name;
    int    credits;
    bool   majorRequirement;
    double avgGrade;
    string days;
    Time   startTime;
    Time   endTime;
};


ostream& operator <<(ostream& os, const Time& secondTime)
{
    secondTime.hour > 12 ? os << secondTime.hour - 12 :os << secondTime.hour;
    os << ':';
    secondTime.minutes < 9 ? os << "0" << secondTime.minutes:os << secondTime.minutes;
    os << ':';
    secondTime.seconds < 9 ? os << "0" << secondTime.seconds:os << secondTime.seconds;
}


void printSchedule(Course courses[], int size)
{
    cout << "-------------------" << endl;
    cout << "SCHEDULE OF STUDENT" << endl;
    cout << "-------------------" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "COURSE " << i + 1 << ": ";
        cout << courses[i].name << endl;
        courses[i].majorRequirement? cout << "Note: this course is a major requirement!" : cout << "Note: this course is not a major requirement...";
        cout << endl << "Number of Credits: " << courses[i].credits << endl;
        cout << "Days of Lectures: " << courses[i].days << endl;
        cout << "Lecture Time: ";
        courses[i].startTime.hour >= 12? cout << courses[i].startTime << "pm" : cout << courses[i].startTime << "am";
        cout << " - ";
        courses[i].endTime.hour >= 12? cout << courses[i].endTime << "pm" : cout << courses[i].endTime << "am";
        cout << endl << "Stat: on average students get " << courses[i].avgGrade << "% in this course." << endl;
        cout << "-------------------" << endl;
    }
}


Time convertTime(string line)
{
    //could not get Time type to play well with the template so I made a seperate function for handling Time objects.
    Time time;

    time.hour    = (10 * (line[0] - '0') + (line[1] - '0'));
    time.minutes = (10 * (line[3] - '0') + (line[4] - '0'));
    time.seconds = (10 * (line[6] - '0') + (line[7] - '0'));
    return time;
}


template<typename t>
t convert(string line, int convertTo)
{
    // convertTo meanings: 1 -> int, 2 -> bool, 3->double
    if (convertTo == 1)
    {
        return line[0] - '0';
    }
    else if (convertTo == 2)
    {
        return line == "1";
    }
    else if (convertTo == 3)
    {
        return (line[0] - '0') * 10 + line[1] - '0';
    }
}


int main()
{
    ifstream file;
    string   data;

    file.open("in.txt");
    getline(file, data);
    int    size = data[0] - '0';
    string strings[size * 7];

    for (int i = 0; i < size * 7; i++)
    {
        getline(file, data);
        strings[i] = data;
    }
    file.close();
    Course courses[size];

    for (int i = 0; i < size; i++)
    {
        courses[i].name             = strings[7 * i];
        courses[i].credits          = convert<int>(strings[7 * i + 1], 1);
        courses[i].majorRequirement = convert<bool> (strings[7 * i + 2], 2);
        courses[i].avgGrade         = convert<double>(strings[7 * i + 3], 3);
        courses[i].days             = strings[7 * i + 4];
        courses[i].startTime        = convertTime(strings[7 * i + 5]);
        courses[i].endTime          = convertTime(strings[7 * i + 6]);
    }
    printSchedule(courses, size);
    return 0;
}
