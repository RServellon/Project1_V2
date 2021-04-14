//
// Created by norma on 29/3/2021.
//

#include "Product.h"

Product::Product(const string &name, const string &id, const float &price, const int &amount) {
    this-> name = name;
    this-> id = id;
    this-> price = price;
    this-> amount = amount;
}

Product::~Product(){

}

string Product::getName() const {
    return name;
}

string Product::getId() const {
    return id;
}

int Product::getAmount() const {
    return amount;
}

void Product::setName(const string &name) {
    this->name = name;
}

void Product::setId(const string &id) {
    this->id = id;
}

void Product::setPrice(const float &price) {
    this->price = price;
}

void Product::setAmount(const int &amount) {
    this->amount = amount;
}

string Product::toString() const {
    stringstream ss;
    ss << "\n\tName: " << getName();
    ss << "\n\tID: " << getId();
    ss << "\n\tPrice: " << getPrice();
    ss << "\n\tAmount: " << getAmount();
    return ss.str();
}