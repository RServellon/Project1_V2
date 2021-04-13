//
// Created by norma on 29/3/2021.
//

#ifndef PROJECT1_IADMIN_H
#define PROJECT1_IADMIN_H
#include"Product.h"

class IAdmin{
//TODO: aver confirmame esto x2
//Dependency inversion principle
//Modulos de alto nivel no deben depender de los pequeños
// sino viceversa
//Es decir, deben usar interfaces abstractas o clases no concretas
public:
    virtual ~IAdmin(){};
    virtual int getIdentifier() const = 0;
    virtual void setIdentifier(const int&)  =0;
    virtual string getName() const = 0;
    virtual void setName(const string&) = 0;
    virtual string toString() const = 0;
    virtual void insert(Product*) = 0;
    virtual void increaseQuantity(string, int) = 0;
    virtual void reduceQuantity(string, int) = 0;
    virtual void deleteProduct(string) = 0;
    virtual Product* check(string) = 0;
    virtual void depositMoney(int) = 0;
    virtual void withdrawMoney(int) = 0;
};


#endif //PROJECT1_IADMIN_H
