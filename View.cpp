//
// Created by rebec on 11/4/2021.
//

#include "View.h"

void View::welcome() {
    cout << "\tSouvenirs de Costa Rica Para El Mundo\n";
    cout << "\t\tSCORIM\n\n";
}

void View::goodbye() {
    cout << "Thank you for using our systems! :)\n";
}

void View::returnMessage() {
    cout << "Loaded...\n";
}

bool View::userLogin() {
    string password;

    cout << "User login\n";
    cout << "Please, enter the administer access password: "; cin >> password;
    if (password != "1234"){
        cout << "Wrong password!\n";
        return false;
    }
    cout << "Password accepted. Loaded ...\n";
    return true;
}

Inventory *View::InventoryCreation() {
    int id, size;
    string name;
    cout << "\tInventory creation\n";

    cout << "Enter the inventory's name: "; cin >> name;
    cout << "Enter the inventory's id: "; cin >> id;
    cout << "Enter the inventory's product capacity: "; cin >> size;

    return new Inventory(id, name, size);

}


int View::selectAView() {
    int option;
    cout << "-----------View Selection----------\n\n";
    cout << "\t1. Administrator Menu\n";
    cout << "\t2. Seller Menu\n";
    cout << "\t3. Exit\n";
    cout << "\n\tEnter your option: "; cin >> option;
    return option;
}

int View::sellerMenu() {
    int option;
    cout << "-----------Seller Menu----------\n";
    cout << "\t1. View inventory's name\n";
    cout << "\t2. Make the purchase\n";
    cout << "\t3. General view of the inventory\n";
    cout << "\t4. Return to the previous menu\n";
    cout << "\nEnter your option: "; cin >> option;
    return option;
}

int View::adminMenu() {
    int option;
    cout << "-----------Administrator Menu----------\n";
    cout << "\t1. View inventory's identifier\n";
    cout << "\t2. Change inventory's identifier\n";
    cout << "\t3. View inventory's name\n";
    cout << "\t4. Change inventory's name\n";
    cout << "\t5. Overall view of the inventory\n";
    cout << "\t6. Add an item to the inventory\n";
    cout << "\t7. Increase an item's quantity\n";
    cout << "\t8. Reduce an item's quantity\n";
    cout << "\t9. Delete an item\n";
    cout << "\t10. Ask for a specific product\n";
    cout << "\t11. Pay money to the Cash Register\n";
    cout << "\t12. Pull back money from the Cash Register\n";
    cout << "\t13. Return to the previous menu\n";
    cout << "\n\tPlease, enter your option: "; cin >> option;
    return option;
}

void View::method1(int identifier) {
    cout << "\t1. View inventory's identifier\n";
    cout << "Inventory's identifier: " << identifier;
}

void View::method2(IAdmin *myInventory) {
    int id;
    cout << "\t2. Change inventory's identifier\n";
    cout << "Enter the new id here: "; cin >> id;

    cout<<"The Inventory's id has been successfully updated!\n";
    myInventory->setIdentifier(id);
}

void View::method3(string name) {
    cout << "\t3. View inventory's name\n";
    cout << "Inventory's name: " << name << "\n";
}

void View::method4(IAdmin *myInventory) {
    string name;
    cout << "\t4. Change inventory's name\n";
    cout << "Enter the new name here: "; cin >> name;
    myInventory->setName(name);
}

void View::method5(IAdmin *myInventory) {
    cout << "\t5. Overall view of the inventory\n";
    cout << myInventory->toString() << "\n";
}

void View::method6(IAdmin *myInventory) {
    string name, id;
    int opt, day, month, year, amount;
    float price, discount;
    Date* myDate = nullptr;
    Product* myProduct = nullptr;

    cout << "\t6. Add an item to the inventory\n";

    cout << "\nWhat kind of product would you want to add?\n";
    cout << "1. Article\n";
    cout << "2. Service\n";
    cout << "\nPlease, enter your option: "; cin >> opt;

    system("cls");

    switch(opt){
        case 1:
        {
            cin.ignore();
            cout << "Enter the article's name: "; getline(cin, name);
            cout << "\nEnter the article's id: "; cin >> id;
            cout << "\nEnter the price: "; cin >> price;
            cout << "\nEnter the total amount of products: "; cin >> amount; // TODO: ¿verificacion para ingresar >=1?
            cout << "\n\nEnter the product's date of entry";
            cout << "\nDay: "; cin >> day;
            cout << "\nMonth: "; cin >> month;
            cout << "\nYear: "; cin >> year;

            myDate = new Date(day, month, year);
            myProduct = new Article(name, id, price, amount, myDate);
            myProduct->calculatePrice();
            myInventory->insert(myProduct);
            //ver si se ingreso y funciona descuento
            myInventory->check(id)->toString();
        }
            break;
        case 2:
        {
            cin.ignore();
            cout << "Enter the service's name: "; getline(cin, name);
            cout << "\nEnter the service's id: "; cin >> id;
            cout << "\nEnter the price: "; cin >> price;
            cout << "\nEnter the total amount of times: "; cin >> amount;
            cout << "\nEnter the discount rate: "; cin >> discount;

            myProduct = new Service(name, id, price, amount, discount);
            myProduct->calculatePrice();
            myInventory->insert(myProduct);
            //ver si se ingreso y funciona descuento
            myInventory->check(id)->toString();
        }
            break;
        default:
            cout << "The option does not exist!\n";
            break;
    }
}

void View::method7(IAdmin *myInventory) {
    string id;
    int amount;
    cout << "\t7. Increase an item's quantity\n";

    cout << myInventory->toString();
    cout << "\nPlease, enter the interested item's id: "; cin >> id;

    if (myInventory->check(id)){
        cout << "\nHow many more items would you like to add? "; cin>> amount;
        myInventory->increaseQuantity(id, amount);
    }
}

void View::method8(IAdmin *myInventory) {
    int amount;
    string id;

    cout << "\nReduce an item's quantity\n";
    cout << myInventory->toString();
    cout << "\nPlease, enter the item's id: "; cin>> id;
    if (myInventory->check(id)){
        cout<<"\nHow many fewer items would you want to decrease? "; cin >> amount;
        myInventory->reduceQuantity(id, amount);
    }
}

void View::method9(IAdmin *myInventory) {
    string id;
    cout << "\t9. Delete an item\n";

    cout << myInventory->toString();
    cout << "\nPlease, enter the item's id: ";
    cin >> id;
    if (myInventory->check(id)) {
        myInventory->deleteProduct(id);
    }
}

void View::method10(IAdmin *myInventory) {
    string id;
    cout << "\t10. Ask for a specific product\n";
    cout<<"\nPlease, enter the item's id: "; cin >> id;
    if (myInventory->check(id)){
        cout << "\nThe product is available!\n";
        cout << myInventory->check(id)->toString();
    }
    cout << "\nSorry, the product is not available\n";
}

void View::method11(IAdmin *myInventory) {
    int money;
    cout << "\t11. Pay money to the Cash Register\n";
    cout << "\nPay money to the Cash Register\n";
    cout << "\nHow much money would you want to deposit? "; cin >> money;
    myInventory->depositMoney(money);
}

void View::method12(IAdmin *myInventory) {
    int money;
    cout << "\t12. Pull back money from the Cash Register\n";
    cout << "\nWithdraw money from the Cas Register\n";
    cout << "\nHow much money would you want to pull back? "; cin >> money;
    myInventory->withdrawMoney(money);
}

void View::option1(string name) {
    cout << "\t1. View inventory's name\n";
    cout << "Inventory's name: " << name << "\n";
}

void View::option2(ISeller *myInventory) {
    if (myInventory->avilable()){
        string id;
        int amount;
        int paymentAmount;

        myInventory->toMakeThePurchase(id,amount,paymentAmount);
    }
    else{
        cout << "\t2. there is no avilable items\n";
    }
}

void View::option3(ISeller *myInventory) {
    cout << "\t3. General view of the inventory\n";
    cout << myInventory->toStringS() << "\n";
}

void View::optionErrorMessage() {
    cout << "\nThe option does not exist!\n";
}
