cmake_minimum_required(VERSION 3.17)
project(Project1_V2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Product.h Product.cpp main.cpp Article.cpp Article.h Date.cpp Date.h CashRegister.cpp CashRegister.h
        Inventory.cpp Inventory.h Service.cpp Service.h ISeller.h IAdmin.h ProductCollection.cpp
        ProductCollection.h
        CalculatePrice.h View.cpp View.h Controller.cpp Controller.h)