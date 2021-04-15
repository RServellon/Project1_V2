//
// Created by rebec on 11/4/2021.
//

#ifndef MAIN_CPP_VIEW_H
#define MAIN_CPP_VIEW_H
#include"Article.h"
#include <iostream>
#include <cstdlib>
#include"Service.h"
#include"Inventory.h"
#include"ISeller.h"
#include"IAdmin.h"

// Se usa el Principio de Responsabilidad Única ya que es una clase
// de servicio para interactuar con el usuario

class View {
public:
    static void welcome();
    static void goodbye();
    static void returnMessage();
    static void failMenu();
    static void clearScreen();
    static void optionErrorMessage();
    static bool userLogin();
    static Inventory* InventoryCreation();

    //Admin
    static int selectAView();
    static int sellerMenu();
    static int adminMenu();

    //Admin
    static void method1(int);
    static void method2(IAdmin*);
    static void method3(string);
    static void method4(IAdmin*);
    static void method5(IAdmin*);
    static void method6(IAdmin*);
    static void method7(IAdmin*);
    static void method8(IAdmin*);
    static void method9(IAdmin*);
    static void method10(IAdmin*);
    static void method11(IAdmin*);
    static void method12(IAdmin*);

    //SellMenu
    static void option1(string);
    static void option2(ISeller*);
    static void option3(ISeller*);

};


#endif //MAIN_CPP_VIEW_H
