#ifndef Time_H
#define Time_H

class Time {
private:
    int hour;
    int minutes;
    int seconds;
public:
    Time(int, int, int);
    Time();

    ~Time();

    int getHour(void);
    int getMinutes(void);
    int getSeconds(void);

    void setHour(int);
    void setMinutes(int);
    void setSeconds(int);
};

#endif
