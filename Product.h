//
// Created by norma on 29/3/2021.
//

#ifndef PROJECT1_PRODUCT_H
#define PROJECT1_PRODUCT_H
#include <iostream>
#include <sstream>
using namespace std;

// Aquí se ve Open-Closed Principle: la super clase esta abierta a su extensión
// pero cerrada a su modificación

// Aquí se respeta el concepto de Segregación de Interfaz, dado que usamos los
// métodos en las clases hijas

class Product {
protected:
    string name;
    string id; //Agregé este atributo para usarlo posteriormente en la coleccion
    float price;
    int amount;
public:
    Product(const string& = "Undefined", const string& = "Undefined", const float& = 0, const int& = 0);
    virtual ~Product();

    string getName() const;
    string getId() const;
    virtual float getPrice() const = 0;
    int getAmount() const;

    void setName(const string&);
    void setId(const string&);
    void setPrice(const float&);
    void setAmount(const int&);

    virtual void calculatePrice() = 0;
    virtual string toString() const;
};


#endif //PROJECT1_PRODUCT_H
