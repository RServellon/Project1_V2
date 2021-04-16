//
// Created by rebec on 11/4/2021.
//

#include "Controller.h"

Controller::Controller() {
    sellerInventory = new Inventory();
    adminInventory = new Inventory();
}

Controller::~Controller() {
}

void Controller::setSellerInventory(ISeller *sellerInventory) {
    this->sellerInventory = sellerInventory;
}

void Controller::setAdminInventory(IAdmin *adminInventory) {
    this->adminInventory = adminInventory;
}

ISeller *Controller::getSellerInventory() {
    return sellerInventory;
}

IAdmin *Controller::getAdminInventory() {
    return adminInventory;
}

void Controller::generalControl() {
    Inventory* myInventory = nullptr;
    int option = 0;

    View::welcome();
    View::clearScreen();

    myInventory = View::InventoryCreation();
    View::clearScreen();

    this->setAdminInventory(myInventory);
    this->setSellerInventory((myInventory));

    while(option != 3){
        option = View::selectAView();

        switch(option){
            case 1:
                if(View::userLogin()){
                    View::clearScreen();
                    control2();
                }
                break;
            case 2:
                View::clearScreen();
                control1();
                break;
            case 3:
                View::goodbye();
                break;
            default:
                View::optionErrorMessage();
                break;
        }
        View::clearScreen();
    }
    delete myInventory;
}

//seller menu
void Controller::control1() {
    int option = 0;
    while (option != 4) {

        option = View::sellerMenu();
        View::clearScreen();
        switch(option){
            case 1:
                View::option1(getSellerInventory()->getNameS());
                break;
            case 2:
                View::option2(getSellerInventory());
                break;
            case 3:
                View::option3(getSellerInventory());
                break;
            case 4:
                View::returnMessage();
                break;
            default:
                View::optionErrorMessage();
                break;
        }
        View::clearScreen();
    }

}
void Controller::control2() {
    int option = 0;

    while(option != 13){

        option = View::adminMenu();
        View::clearScreen();

        switch(option){
            case 1:
                View::method1(getAdminInventory()->getIdentifier());
                break;
            case 2:
                View::method2(getAdminInventory());
                break;
            case 3:
                View::method3(getAdminInventory()->getName());
                break;
            case 4:
                View::method4(getAdminInventory());
                break;
            case 5:
                View::method5(getAdminInventory());
                break;
            case 6:
                View::method6(getAdminInventory());
                break;
            case 7:
                View::method7(getAdminInventory());
                break;
            case 8:
                View::method8(getAdminInventory());
                break;
            case 9:
                View::method9(getAdminInventory());
                break;
            case 10:
                View::method10(getAdminInventory());
                break;
            case 11:
                View::method11(getAdminInventory());
                break;
            case 12:
                View::method12(getAdminInventory());
                break;
            case 13:
                View::returnMessage();
                break;
            default:
                View::optionErrorMessage();
                break;
        }
        View::clearScreen();
    }
}

