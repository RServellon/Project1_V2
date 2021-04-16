//
// Created by norma on 29/3/2021.
//

#ifndef PROJECT1_ISELLER_H
#define PROJECT1_ISELLER_H
#include<iostream>
#include<sstream>
using namespace std;

class ISeller{
public:
    virtual ~ISeller() {}
    virtual string getNameS() const = 0;
    virtual string toMakeThePurchase(string, int, int, int) = 0;
    virtual string toStringS() const = 0;
    virtual bool collectionEmpty() const = 0;
    virtual Product* check(string) = 0;
};


#endif //PROJECT1_ISELLER_H
