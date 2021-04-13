//
// Created by rebec on 30/3/2021.
//

#ifndef MAIN_CPP_CALCULATEPRICE_H
#define MAIN_CPP_CALCULATEPRICE_H
#include "Date.h"


class CalculatePriceArticle {
public:
    virtual int convertToDays() = 0;
    virtual bool moreThan90Days(int) = 0;
    virtual float discountArticle() = 0;
};

class CalculatePriceService{
public:
    virtual float discountService() = 0;
};

#endif //MAIN_CPP_CALCULATEPRICE_H
