//
// Created by norma on 29/3/2021.
//

#ifndef PROJECT1_DATE_H
#define PROJECT1_DATE_H
#include <iostream>
#include <sstream>
using namespace std;

class Date {
private:
    int day;
    int month;
    int year;
public:
    Date(int = 0, int = 0, int = 0 );
    ~Date();

    int getDay() const;
    int getMonth() const;
    int getYear() const;

    void setDay(int);
    void setMonth(int);
    void setYear(int);

    string toString() const;
};

#endif //PROJECT1_DATE_H
