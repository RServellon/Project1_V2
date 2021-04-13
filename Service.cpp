//
// Created by norma on 29/3/2021.
//

#include "Service.h"

Service::Service(const string& name, const string& id, const float& price, const int& amount, const float& discountRate) :
Product(name, id, price, amount ), discountRate(discountRate){
}

Service::~Service() {

}

void Service::setDiscountRate(float discountRate) {
    this->discountRate = discountRate;
}

float Service::getDiscountRate() const {
    return discountRate;
}

float Service::getPrice() const {
    return price;
}

string Service::toString() const{
    stringstream ss;
    ss << "\nService";
    ss << Product::toString();
    ss << "\n\tDiscount rate: "<< getDiscountRate();
    return ss.str();
}

void Service::calculatePrice() {
    this-> setPrice(discountService());
}

float Service::discountService() {
    return (getPrice() - (getPrice() * getDiscountRate()));
}

