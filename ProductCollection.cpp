//
// Created by rebec on 29/3/2021.
//

#include "ProductCollection.h"

ProductCollection::ProductCollection(const int& size): size(size), num(0) {
    vector = new Product * [getSize()];
    for (int i = 0; i < getSize(); i++) {
        vector[i] = nullptr;
    }
}

ProductCollection::~ProductCollection() {
    for (int i = 0; i < getNum(); i++) {
        if (vector[i]) {
            delete vector[i];
        }
    }
    delete[] vector;
    setNum(0);
}

void ProductCollection::setNum(int num) {
    this->num = num;
}

int ProductCollection::getSize() const {
    return size;
}

int ProductCollection::getNum() const {
    return num;
}

string ProductCollection::toString() const{
    stringstream s;
    s << "\nProduct List\n";
    for(int i = 0; i < getNum(); i++){
        s  << vector[i]->toString() << "\n";
    }
    return s.str();
}

void ProductCollection::moveToLeft(int position) {
    for (int i = position; i < getNum(); i++) {
        vector[i] = vector[i + 1];
    }
    vector[getNum() - 1] = nullptr;
}

void ProductCollection::deleteProduct(string id) {
    stringstream ss;
    for (int i = 0; i < getNum(); i++) {
        if (vector[i]->getId() == id) {
            delete vector[i];
            moveToLeft(i);
            setNum(getNum() - 1);
        }
    }
}

bool ProductCollection::verifyProduct(string id) {
    for (int i = 0; i < getNum(); i++) {
        if (vector[i]->getId() == id) {
            return true;
        }
    }
    return false;
}

bool ProductCollection::addProduct(Product * myProduct) {
    if (getNum() < getSize()) {
        vector[getNum()] = myProduct;
        setNum(getNum() + 1);
        return true;
    }
    return false;
}

Product *ProductCollection::productReturn(string id) {
    for (int i = 0; i < getNum(); i++){
        if(vector[i]->getId() == id){
            return vector[i];
        }
    }
    return nullptr;
}

void ProductCollection::increaseQuantity(string id, int x) {
    for (int i = 0; i < getNum(); i++) {
        if (vector[i]->getId() == id) {
            vector[i]->setAmount(vector[i]->getAmount() + x );
        }
    }
}

void ProductCollection::reduceQuantity(string id, int x) {
    for (int i = 0; i < getNum(); i++) {
        if (vector[i]->getId() == id and x < vector[i]->getAmount()) {
            vector[i]->setAmount(vector[i]->getAmount() - x);
        }
        if (vector[i]->getId() == id and x >= vector[i]->getAmount()){
            vector[i]->setAmount(0);
        }
    }
}

bool ProductCollection::empty() {
    for (int i = 0; i < getNum(); i++) {
        if (vector[i] == nullptr)
            return true;
    }
    return false;
}