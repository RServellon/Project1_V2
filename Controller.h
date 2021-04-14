//
// Created by rebec on 11/4/2021.
//

#ifndef MAIN_CPP_CONTROLLER_H
#define MAIN_CPP_CONTROLLER_H
#include"View.h"

// Se usa el Principio de Responsabilidad Única al mostrar los mensajes
// a través de métodos desde la clase View

// Acá se presenta el Principio de Inversión de dependencias, ya que
// la clase Controller no depende directamente de Inventario sino de las
// abstracciones IAdmin y ISeller

class Controller {
private:
    ISeller* sellerInventory;
    IAdmin* adminInventory;
public:
    Controller();
    ~Controller();

    void setSellerInventory(ISeller*);
    void setAdminInventory(IAdmin*);
    ISeller* getSellerInventory();
    IAdmin* getAdminInventory();

    void generalControl();
    void control1();
    void control2();

};


#endif //MAIN_CPP_CONTROLLER_H
