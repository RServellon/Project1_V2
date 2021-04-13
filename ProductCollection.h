//
// Created by rebec on 29/3/2021.
//

#ifndef MAIN_CPP_PRODUCTCOLLECTION_H
#define MAIN_CPP_PRODUCTCOLLECTION_H
#include"Product.h"
#include"Service.h"
#include"Article.h"

class ProductCollection {
private:
    Product** vector;
    int num;
    int size;
public:
    ProductCollection(const int& = 0);
    ~ProductCollection();

    void setNum(int);
    int getSize() const;
    int getNum() const;
    string toString() const;
    void clear();
    void moveToLeft(int);
    void deleteProduct(string);
    bool verifyProduct(string);
    bool addProduct(Product*);
    Product* productReturn(string);
    void increaseQuantity(string, int);
    void reduceQuantity(string, int);
    bool empty();
};


#endif //MAIN_CPP_PRODUCTCOLLECTION_H
