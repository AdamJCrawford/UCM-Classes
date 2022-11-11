#include "Time.h"

Time::Time(int h, int m, int s)
{
    hour    = h;
    minutes = m;
    seconds = s;
}


Time::Time()
{
    hour    = 0;
    minutes = 0;
    seconds = 0;
}


Time::~Time()
{
}


int Time::getHour()
{
    return hour;
}


int Time::getMinutes()
{
    return minutes;
}


int Time::getSeconds()
{
    return seconds;
}


void Time::setHour(int h)
{
    hour = h;
}


void Time::setMinutes(int m)
{
    minutes = m;
}


void Time::setSeconds(int s)
{
    seconds = s;
}
