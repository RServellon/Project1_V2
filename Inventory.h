//
// Created by norma on 29/3/2021.
//

#ifndef PROJECT1_INVENTORY_H
#define PROJECT1_INVENTORY_H
#include"ProductCollection.h"
#include"CashRegister.h"
#include"IAdmin.h"
#include"ISeller.h"

// Acá se presenta el Principio de Inversión de dependencias, ya que
// la clase Controller no depende directamente de Inventario sino de las
// abstracciones IAdmin y ISeller
class Inventory:public IAdmin, public ISeller{
private:
    int identifier;
    string name;
    ProductCollection* myCollection;
    CashRegister* myCashRegister;
public:
    Inventory(const int& = 0, const string& = "Undefined", const int& = 0);
    ~Inventory();

    //I Admin
    void setIdentifier(const int&) override;
    void setName(const string&) override;
    void setProductCollection(ProductCollection*);
    void setCashRegister(CashRegister*);
    int getIdentifier() const override;
    string getName() const override;
    ProductCollection* getProductCollection() const;
    CashRegister* getCashRegister() const;
    string toString() const override;
    void insert(Product*) override;
    void increaseQuantity(string, int) override;
    void reduceQuantity(string, int) override;
    void deleteProduct(string) override;
    Product* check(string) override;
    void depositMoney(int) override ;
    bool withdrawMoney(int) override;
    bool areSpace();

    //I Seller
    string getNameS() const override;
    string toMakeThePurchase(string, int, int, int) override;//TODO
    string toStringS() const override;//TODO
    bool collectionEmpty() const override;
};


#endif //PROJECT1_INVENTORY_H
