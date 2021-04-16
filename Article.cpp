//
// Created by norma on 29/3/2021.
//

#include "Article.h"

Article::Article(const string &name, const string &id, const float &price,const int &amount, Date* date):
Product(name, id, price, amount), date(date) {
}

Article::~Article() {
    if(this->getDate()){
        delete this->getDate();
    }
}

void Article::setDate(Date *date) {
    this->date = date;
}

Date *Article::getDate() const {
    return date;
}

float Article::getPrice() const{
    return price;
}

string Article::toString() const {
    stringstream s;
    s << "\nArticle";
    s << Product::toString();
    s << "\n\tEntry date: " << getDate()->toString();
    return s.str();
}

void Article::calculatePrice() {
    this->setPrice(discountArticle());
}

int Article::convertToDays() {
    int totalDays1;
    int totalDays2;

    time_t now = time(nullptr);
    struct tm * tmp = localtime(&now);
    int actualDay = tmp->tm_mday;
    int actualMonth = tmp->tm_mon + 1;
    int actualYear = 1900 + tmp->tm_year;

    totalDays1 = (actualYear * 365) + (actualMonth * 30) + actualDay;
    totalDays2 = (getDate()->getYear() * 365) + (getDate()->getMonth() * 30) + getDate()->getDay();

    return totalDays1 - totalDays2;
}

bool Article::moreThan90Days(int total) {
    if(total > 90){
        return true;
    }
    return false;
}

float Article::discountArticle() {
    if (moreThan90Days(convertToDays())) {
        return float (getPrice() - (getPrice() * 0.5));
    }
    return price;
}

