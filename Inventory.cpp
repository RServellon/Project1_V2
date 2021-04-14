//
// Created by norma on 29/3/2021.
//

#include "Inventory.h"

//Relacion asociación por composición, porque crea los objetos parte en la misma clase
Inventory::Inventory(const int &identifier, const string &name, const int &size){
    this-> identifier = identifier;
    this-> name = name;
    myCollection = new ProductCollection(size);
    myCashRegister = new CashRegister();
}

Inventory::~Inventory() {
    if (getProductCollection()){
        delete getProductCollection();
    }
    if(getCashRegister()){
        delete getCashRegister();
    }
}

void Inventory::setIdentifier(const int &identifier) {
    this-> identifier = identifier;
}

void Inventory::setName(const string &name) {
    this->name = name;
}

void Inventory::setProductCollection(ProductCollection * myCollection) {
    this->myCollection = myCollection;
}

void Inventory::setCashRegister(CashRegister *myCashRegister) {
    this->myCashRegister = myCashRegister;
}

int Inventory::getIdentifier() const{
    return identifier;
}

string Inventory::getName() const {
    return name;
}

ProductCollection *Inventory::getProductCollection() const {
    return myCollection;
}

CashRegister *Inventory::getCashRegister() const {
    return myCashRegister;
}

string Inventory::toString() const {
    stringstream s;
    s << "\nInventory";
    s << "\n\tID: " << getIdentifier();
    s << "\n\tName: " << getName();
    if (!myCollection->empty())
        s << "\n" << getProductCollection()->toString();
    s << "\n" << getCashRegister()->toString();
    return s.str();
}

void Inventory::insert(Product *P) {
    getProductCollection()->addProduct(P);
}

void Inventory::increaseQuantity(string id, int cant) {
    getProductCollection()->increaseQuantity(id, cant);
}

void Inventory::reduceQuantity(string id, int cant) {
    getProductCollection()->reduceQuantity(id, cant);
}

void Inventory::deleteProduct(string id) {
    getProductCollection()->deleteProduct(id);
}

Product *Inventory::check(string id) {
    if(getProductCollection()->verifyProduct(id)){
        return getProductCollection()->productReturn(id);
    }
    return nullptr;
}

void Inventory::depositMoney(int c)  {
    getCashRegister()->setMoney(getCashRegister()->getMoney() + c);
}

void Inventory::withdrawMoney(int x) {
    int money = 0;
    money = getCashRegister()->getMoney();
    if (x <= money){
        getCashRegister()->setMoney(money - x);
    } else{
        cout<<"not founds"<<endl;
    }
}

string Inventory::getNameS() const {
    return name;
}

string Inventory::toMakeThePurchase(string id, int quantity, int payingAmount) {
    int opcbill;
    cout<<myCollection->toString();
    cout<< "\nwhich product(s) you need?";cin>>id;
    if (myCollection->verifyProduct(id) ){
        cout<< "\nhow many products?";cin>>quantity;
        if (quantity<=myCollection->productReturn(id)->getAmount()){
            payingAmount=myCollection->productReturn(id)->getPrice() * quantity;
            cout<< "\nwith what amount do you want to pay? (20.000, 10.000, 5.000)";
            cin>>opcbill;
            if (opcbill>=payingAmount){
                if (opcbill-payingAmount < myCashRegister->getMoney() + payingAmount){
                    cout<< "\nsuccessful purchase!";
                    depositMoney(payingAmount);
                    int change=opcbill-payingAmount;
                    cout<<"money: "<<opcbill<<endl;
                    cout<<"To pay: "<<payingAmount<<endl;
                    cout<< myCashRegister->changeBreakdown(change);
                    myCollection->reduceQuantity(id, quantity);
                }
                else{
                    cout<< "\nnot enough money for change!";
                }
            }
            else{
                cout<< "\ninsufficient funds!";
            }

        }else{
            cout<< "\ninsufficient quantity!";
        }
    }
    else{
        cout<< "\nthere is no item with that id ";
    }
return "";
}

string Inventory::toStringS() const {
    stringstream s;
    s<<"\t\nProductos disponibles";
    s<<myCollection->toString();
    return s.str();
}

string Inventory::toStringSimple() const{
    stringstream ss;
    ss << "\nInventory";
    ss << "\n\tID: " << getIdentifier();
    ss << "\n\tName: " << getName();
    return ss.str();
}

bool Inventory::avilable() {
    if (myCollection->empty())
        return false;
    return true;
}

Product *Inventory::isInInvent(string c) {
    if (myCollection->verifyProduct(c))
        return myCollection->productReturn(c);
    else
        return nullptr;
}
