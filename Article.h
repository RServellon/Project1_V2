//
// Created by norma on 29/3/2021.
//

#ifndef PROJECT1_ARTICLE_H
#define PROJECT1_ARTICLE_H
#include<ctime>
#include"CalculatePrice.h"
#include "Product.h"
#include "Date.h"

// Aquí se ve Open-Closed Principle: la super clase esta abierta a su extensión
// pero cerrada a su modificación
class Article: public Product, public CalculatePriceArticle{
private:
    Date *date;
public:
    Article(const string& = "Undefined", const string& = "Undefined", const float& = 0,
            const int& = 0, Date* = nullptr);
    ~Article();

    void setDate(Date *);
    Date* getDate() const;
    float getPrice() const override;
    string toString() const override;
    void calculatePrice() override;

    int convertToDays() override;
    bool moreThan90Days(int) override;
    float discountArticle() override;
};

#endif //PROJECT1_ARTICLE_H
