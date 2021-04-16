
//
// Created by norma on 29/3/2021.
//

#include "Date.h"

Date::Date(int day, int month, int year) {
    this->day = day;
    this->month = month;
    this->year = year;
}

Date::~Date() {
}

int Date::getDay() const {
    return day;
}

int Date::getMonth() const {
    return month;
}

int Date::getYear() const {
    return year;
}

void Date::setDay(int day) {
    this->day = day;
}

void Date::setMonth(int month) {
    this->month = month;
}

void Date::setYear(int year) {
    this->year = year;
}

string Date::toString() const {
    stringstream s;
    s << "( " << this-> getDay() << "/" << this-> getMonth() << "/"<< this-> getYear() << ")";
    return s.str();
}