//
// Created by norma on 29/3/2021.
//

#include "CashRegister.h"

CashRegister::CashRegister(const float & money): money(money) {
}

CashRegister::~CashRegister(){
}

string CashRegister::changeBreakdown(int &change) {
    stringstream s;
    int opChange1 = 0, opChange2 = 0, opChange3 = 0, opChange4 = 0;

    s << "\n\n\tChange Breakdown";
    s << "\n\tThe total change is " << change;

    if (change >= 2000){
        opChange1 = change / 2000;
        change = change % 2000;
    }
    if (change >= 1000){
        opChange2 = change / 1000;
        change = change % 1000;
    }
    if(change >= 500){
        opChange3 = change / 500;
        change = change % 500;
    }
    if (change >= 100){
        opChange4 = change / 100;
        change = change % 100;
    }

    s << "\n\t2000 bill(s): " << opChange1;
    s << "\n\t1000 bill(s): " << opChange2;
    s << "\n\t500 coin(s): " << opChange3;
    s << "\n\t100 coin(s): " << opChange4;
    s << "\n\n";
    return s.str();
}

void CashRegister::setMoney(const int& money) {
    this-> money = money;
}

int CashRegister::getMoney() const {
    return money;
}

string CashRegister::toString() const {
    stringstream ss;
    ss << "\nCash Register";
    ss << "\n\tMoney: "<< getMoney() << "\n\n";
    return ss.str();
}
