//
// Created by rebec on 11/4/2021.
//

#include "View.h"

void View::welcome() {
    cout << "\tSouvenirs de Costa Rica Para El Mundo\n";
    cout << "\t\tSCORIM\n\n";
}

void View::goodbye() {
    cout << "\n\tThank you for using our systems! :)\n";
}

void View::returnMessage() {
    cout << "\n\tLoaded...\n";
}

void View::failMenu() {
    cin.clear();
    cin.ignore(10000, '\n');
    clearScreen();
}


void View::clearScreen() {
    cout << "\n\tPrint ENTER to continue...";
    cin.get();
    cout << string(50, '\n');
}


bool View::userLogin() {
    string password;

    cout << "\n\n\tUser login\n";
    cout << "Please, enter the administer access password: "; cin >> password;
    if (password != "1234"){
        cout << "Wrong password!\n\n";
        return false;
    }
    cout << "Password accepted!\n\n";
    return true;
}

Inventory *View::InventoryCreation() {
    int id, size;
    string name;
    cout << "\tInventory creation\n";

    cout << "\nEnter the inventory's name: "; cin >> name;
    cout << "Enter the inventory's id: "; cin >> id;
    while(cin.fail()){
        cout << "You must enter a number!\n";
        failMenu();
        cout << "Enter the inventory's id: "; cin >> id;
    }

    cout << "Enter the inventory's product capacity: "; cin >> size;
    while(cin.fail()){
        cout << "You must enter a number!\n";
        failMenu();
        cout << "Enter the inventory's product capacity: "; cin >> size;
    }

    return new Inventory(id, name, size);
}

int View::selectAView() {
    int option;
    cout << "-----------View Selection----------\n\n";
    cout << "\t1. Administrator Menu\n";
    cout << "\t2. Seller Menu\n";
    cout << "\t3. Exit\n";
    cout << "\n\tEnter your option: "; cin >> option;

    while(cin.fail()){
        cout << "You must enter a number!\n";
        failMenu();
        cout << "-----------View Selection----------\n\n";
        cout << "\t1. Administrator Menu\n";
        cout << "\t2. Seller Menu\n";
        cout << "\t3. Exit\n";
        cout << "\n\tEnter your option: "; cin >> option;
    }

    return option;
}

int View::sellerMenu() {
    int option;
    cout << "-----------Seller Menu----------\n";
    cout << "\t1. View inventory's name\n";
    cout << "\t2. Make the purchase\n";
    cout << "\t3. General view of the inventory\n";
    cout << "\t4. Return to the previous menu\n";
    cout << "\nPlease, enter your option: "; cin >> option;

    while(cin.fail()){
        cout << "You must enter a number!\n";
        failMenu();
        cout << "-----------Seller Menu----------\n";
        cout << "\t1. View inventory's name\n";
        cout << "\t2. Make the purchase\n";
        cout << "\t3. General view of the inventory\n";
        cout << "\t4. Return to the previous menu\n";
        cout << "\n\tEnter your option: "; cin >> option;
    }

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

    while(cin.fail()){
        cout << "You must enter a number!\n";
        failMenu();
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
        cout << "\n\tPlease, enter your option: ";
        cout << "\n\tEnter your option: "; cin >> option;
    }

    return option;
}

void View::method1(int identifier) {
    cout << "\t1. View inventory's identifier\n\n";
    cout << "Inventory's identifier: " << identifier << "\n";
}

void View::method2(IAdmin *myInventory) {
    int id;
    cout << "\t2. Change inventory's identifier\n\n";
    cout << "Enter the new id here: "; cin >> id;

    while(cin.fail()){
        cout << "You must enter a number!\n";
        failMenu();
        cout << "Enter the new id here: "; cin >> id;
    }

    myInventory->setIdentifier(id);
    cout << "\nThe inventory's id has been successfully updated!\n\n";
}

void View::method3(string name) {
    cout << "\t3. View inventory's name\n";
    cout << "Inventory's name: " << name << "\n";
}

void View::method4(IAdmin *myInventory) {
    string name;
    cout << "\t4. Change inventory's name\n\n";
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
    Date *myDate = nullptr;
    Product *myProduct = nullptr;

    cout << "\t6. Add an item to the inventory\n\n";
    if (myInventory->areSpace()) {

        cout << "\nWhat kind of product would you want to add?";
        cout << "\n1. Article";
        cout << "\n2. Service";
        cout << "\n\nPlease, enter your option: ";
        cin >> opt;
        while (cin.fail()) {
            cout << "You must enter a number!\n";
            failMenu();
            cout << "\t6. Add an item to the inventory\n";

            cout << "\nWhat kind of product would you want to add?";
            cout << "\n1. Article";
            cout << "\n2. Service";
            cout << "Please, enter your option: ";
            cin >> opt;
        }

        system("cls");

        switch (opt) {
            case 1: {
                cin.ignore();
                cout << "\nEnter the article's id: ";
                cin >> id;

                if (myInventory->check(id)) {
                    cout << "The article's id already exist in the inventory!\n";
                } else {
                    cout << "\nEnter the article's name: ";
                    cin >> name;
                    //getline(cin, name);
                    cout << "\nEnter the price: ";
                    cin >> price;
                    while (cin.fail()) {
                        cout << "You must enter a number!\n";
                        failMenu();
                        cout << "Enter the price: ";
                        cin >> price;
                    }

                    cout << "\nEnter the total amount of products: ";
                    cin >> amount;
                    while (cin.fail() || amount <= 0) {
                        cout << "You must enter a number (from 1 onwards)!\n";
                        failMenu();
                        cout << "Enter the total amount of products: ";
                        cin >> amount;
                    }

                    cout << "\n\nEnter the product's date of entry (dd/mm/yyyy)";
                    cout << "\nDay: ";
                    cin >> day;
                    while (cin.fail()) {
                        cout << "You must enter a number!\n";
                        failMenu();
                        cout << "\nEnter the day: ";
                        cin >> day;
                    }

                    cout << "\nMonth: ";
                    cin >> month;
                    while (cin.fail()) {
                        cout << "You must enter a number!\n";
                        failMenu();
                        cout << "\nEnter the month: ";
                        cin >> month;
                    }

                    cout << "\nYear: ";
                    cin >> year;
                    while (cin.fail()) {
                        cout << "You must enter a number!\n";
                        failMenu();
                        cout << "\nEnter the year: ";
                        cin >> year;
                    }

                    myDate = new Date(day, month, year);
                    myProduct = new Article(name, id, price, amount, myDate);
                    myProduct->calculatePrice();
                    myInventory->insert(myProduct);
                }
            }
                break;
            case 2: {
                cin.ignore();
                cout << "\nEnter the service's id: ";
                cin >> id;
                if (myInventory->check(id)) {
                    cout << "The service's id already exist in the inventory!\n";
                } else {
                    cout << "\nEnter the service's name: ";
                    //getline(cin, name);
                    cin >> name;

                    cout << "\nEnter the price: ";
                    cin >> price;
                    while (cin.fail()) {
                        cout << "You must enter a number!\n";
                        failMenu();
                        cout << "\nEnter the price: ";
                        cin >> price;
                    }

                    cout << "\nEnter the total amount: ";
                    cin >> amount;
                    while (cin.fail()) {
                        cout << "You must enter a number!\n";
                        failMenu();
                        cout << "\nEnter the total amount of times: ";
                        cin >> amount;
                    }

                    cout << "\nEnter the discount rate: ";
                    cin >> discount;
                    while (cin.fail()) {
                        cout << "You must enter a number!\n";
                        failMenu();
                        cout << "\nEnter the discount rate: ";
                        cin >> discount;
                    }

                    myProduct = new Service(name, id, price, amount, discount);
                    myProduct->calculatePrice();
                    myInventory->insert(myProduct);
                }
            }
                break;
            default:
                cout << "\n\tThe option does not exist!\n";
                break;
        }
    } else {
        cout << "\n\tThere is not enough space in inventory, you can delete items\n";
    }
}

void View::method7(IAdmin *myInventory) {
    string id;
    int amount;
    cout << "\t7. Increase an item's quantity\n";

    cout << myInventory->toString();
    cout << "\n\nPlease, enter the item's id: "; cin >> id;

    if (myInventory->check(id)){
        cout << "How many more items would you like to add? "; cin >> amount;
        while(cin.fail()){
            cout << "You must enter a number!\n";
            failMenu();
            cout << "\nHow many more items would you like to add? "; cin >> amount;
        }

        myInventory->increaseQuantity(id, amount);
    }
    else {
        cout << "\nThe product's id does not exist!\n";
    }
}

void View::method8(IAdmin *myInventory) {
    int amount;
    string id;

    cout << "\nReduce an item's quantity\n";
    cout << myInventory->toString();
    cout << "\n\nPlease, enter the item's id: "; cin >> id;

    if (myInventory->check(id)){
        cout << "How many fewer items would you want to decrease? "; cin >> amount;
        while(cin.fail()){
            cout << "You must enter a number!\n";
            failMenu();
            cout << "\nHow many fewer items would you want to decrease? "; cin >> amount;
        }

        myInventory->reduceQuantity(id, amount);
    }
    else {
        cout << "\nThe product's id does not exist!\n";
    }
}

void View::method9(IAdmin *myInventory) {
    string id;
    cout << "\t9. Delete an item\n";

    cout << myInventory->toString();
    cout << "\n\nPlease, enter the item's id: "; cin >> id;
    if (myInventory->check(id)) {
        myInventory->deleteProduct(id);
        cout << "\nThe product has been successfully deleted!\n";
    }
    else {
        cout << "\nThe product has not been found!\n";
    }
}

void View::method10(IAdmin *myInventory) {
    string id;
    cout << "\t10. Ask for a specific product\n";
    cout<<"\nPlease, enter the item's id: "; cin >> id;
    if (myInventory->check(id) && myInventory->check(id)->getAmount() > 0){
        cout << myInventory->check(id)->toString();
        cout << "\nThe product is available!\n";
    }
    else {
        cout << "\nSorry, the product is not available or it is not registered in the inventory!\n";
    }
}

void View::method11(IAdmin *myInventory) {
    int money;
    cout << "\t11. Pay money to the Cash Register\n";
    cout << "\nHow much money would you want to deposit? "; cin >> money;
    while(cin.fail()){
        cout << "\nYou must enter a number!\n";
        failMenu();
        cout << "\nHow much money would you want to deposit? "; cin >> money;
    }

    myInventory->depositMoney(money);
    cout << "\nThe deposit has been completed successfully!\n\n";
}

void View::method12(IAdmin *myInventory) {
    int money;
    cout << "\t12. Pull back money from the Cash Register\n";
    cout << "\nHow much money would you want to pull back? "; cin >> money;
    while(cin.fail()){
        cout << "\nYou must enter a number!\n";
        failMenu();
        cout << "\nHow much money would you want to pull back? "; cin >> money;
    }

    if(myInventory->withdrawMoney(money)){
        cout << "\nThe withdraw was successfully held!\n\n";
    }
    else {
        cout << "\nThere are not enough funds!\n\n";
    }
}

void View::option1(string name) {
    cout << "\n\t1. View inventory's name\n\n";
    cout << "Inventory's name: " << name << "\n\n";
}

void View::option2(ISeller *myInventory) {
    string id, msg2, msg1;
    int amount = 0, paymentAmount = 0, optionBill = 0;

    if(!myInventory->collectionEmpty()) {
       cout<< myInventory->toStringS();
        cout << "\n\nEnter the product's id that you need: ";
        cin >> id;

        if (myInventory->check(id)) {
            cout << myInventory->check(id)->toString();
            cout << "\n\nIs this your item? (Y/N): ";
            cin >> msg1;
            if (msg1 == "Y" or msg1 == "y" and msg1 != "n" or msg1 != "N") {
                cout << "Enter the amount (article) or times (service) you need: ";
                cin >> amount;
                while (cin.fail()) {
                    cout << "You must enter a number!\n";
                    failMenu();
                    cout << "\nHow many products?";
                    cin >> amount;
                }

                cout << "\nIs ( " << amount << " ) the correct amount? (Y/N): ";
                cin >> msg2;
                if (msg2 == "Y" or msg2 == "y" and msg2 != "n" or msg2 != "N") {
                    if (amount <= myInventory->check(id)->getAmount()) {
                        paymentAmount = myInventory->check(id)->getPrice() * amount;

                        cout << "\nWith what amount of money would you want to pay? ";
                        cin >> optionBill;
                        while (cin.fail()) {
                            cout << "You must enter a number!\n";
                            failMenu();
                            cout << "\nWith what amount do you want to pay? (20.000, 10.000, 5.000): ";
                        }
                        cout << myInventory->toMakeThePurchase(id, amount, paymentAmount, optionBill);
                    } else{
                        cout << "\nThere is an excess demand!";
                    }
                } else {
                    cout << "\nOperation cancelled!";
                }

            } else {
                cout << "\nOperation cancelled!";
            }
        } else{
            cout << "\nThe product's id does not exist!";
        }
    } else{
        cout << "\nSorry, there are currently no items to display\n";
    }

}

void View::option3(ISeller *myInventory) {
    cout << "\t3. General view of the inventory\n";
    cout << myInventory->toStringS() << "\n";
}

void View::optionErrorMessage() {
    cout << "\n\tThe option does not exist!\n";
}