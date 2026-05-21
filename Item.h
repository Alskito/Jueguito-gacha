/*
 * Jueguito-gacha
 * Alexander Zamudio Cano
 * A01710688
 * 20/5/2026
 */
#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <sstream>
#include <string>

class Item {
    protected:
        std::string nombre;
        std::string rareza;
    public:
        Item(): nombre(""), rareza("") {};
        Item(std::string nom, std::string rar): nombre(nom), rareza(rar) {};

        std::string get_nombre();
        std::string get_rareza();

        void set_nombre(std::string);
        void set_rareza(std::string);

        virtual double aplicar_efecto() = 0;
        virtual std::string to_string() = 0;
        
};


std::string Item::get_nombre(){
  return nombre;
}

std::string Item::get_rareza(){
  return rareza;
}

void Item ::set_nombre(std::string nom){
    nombre = nom;
}

void Item ::set_rareza(std::string rar){
    rareza = rar;
}

#endif