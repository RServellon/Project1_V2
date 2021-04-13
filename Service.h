//
// Created by norma on 29/3/2021.
//

#ifndef PROJECT1_SERVICE_H
#define PROJECT1_SERVICE_H
#include "Product.h"
#include"CalculatePrice.h"

// Aquí se ve el Open-Closed Principle
// La super clase esta abierta a su extensión pero
// cerrada a su modificación
class Service : public Product, public CalculatePriceService{
private:
    float discountRate;
public:
    Service(const string& = "Undefined", const string& = "Undefined", const float& = 0, const int& = 0, const float& = 0);
    ~Service();

    void setDiscountRate(float);
    float getDiscountRate() const;

    float getPrice() const override;
    string toString() const override;

    void calculatePrice() override;
    float discountService() override;
};

#endif //PROJECT1_SERVICE_H
