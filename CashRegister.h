//
// Created by norma on 29/3/2021.
//

#ifndef PROJECT1_CAJA_H
#define PROJECT1_CAJA_H
#include<iostream>
#include<sstream>
using namespace std;

class CashRegister {
private:
    int money;
public:
    CashRegister(const float& = 0);
    ~CashRegister();

    string changeBreakdown(int&);
    void setMoney(const int&);
    int getMoney() const;
    string toString() const;
};

#endif //PROJECT1_CAJA_H
