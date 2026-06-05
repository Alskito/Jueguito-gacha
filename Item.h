/*
 * Jueguito-gacha
 * Alexander Zamudio Cano
 * A01710688
 * 04/06/2026
 */

 /*
 * Clase Item es la clase base abstracta de la que heredan
 * Mejoras, Reliquias y Herramienta. Representa un objeto 
 * general que el jugador puede obtener al tirar en el gacha.
 *
 */

#ifndef ITEM_H_
#define ITEM_H_

#include <iostream>
#include <sstream>
#include <string>

class Item {
    protected: // Se declaran los atributos
        std::string nombre;
        std::string rareza;
    public: // Se declaran los metodos
        /**
         * Constructor por default
         * Inicializa el nombre y rareza con cadenas vacias.
         *
         * @param
         * @return Objeto Item
         */
        Item(): nombre(""), rareza("") {};

        /**
         * Constructor con parametros
         * Asigna un nombre y una rareza al item al ser creado.
         *
         * @param nom Nombre del item
         * @param rar Rareza del item
         * @return Objeto Item
         */

        Item(std::string nom, std::string rar): nombre(nom), rareza(rar) {};

        /**
         * Destructor virtual
         * Para borrar los objetos una vez termine el programa
         *
         * @param
         * @return 
         */
        virtual ~Item() {};

        std::string get_nombre();
        std::string get_rareza();

        void set_nombre(std::string);
        void set_rareza(std::string);

        virtual double aplicar_efecto() = 0;
        virtual std::string to_string() = 0;
        virtual std::string get_tipo() = 0;
        
};

/**
 * Devuelve el nombre del item.
 *
 * @param
 * @return String con el nombre
 */
std::string Item::get_nombre(){
  return nombre;
}

/**
 * Devuelve la rareza del item.
 *
 * @param
 * @return String con la rareza
 */
std::string Item::get_rareza(){
  return rareza;
}

/**
 * Modifica el nombre del item.
 *
 * @param nom Nuevo nombre a asignar
 * @return
 */
void Item ::set_nombre(std::string nom){
    nombre = nom;
}

/**
 * Modifica la rareza del item.
 *
 * @param rar Nueva rareza a asignar
 * @return
 */
void Item ::set_rareza(std::string rar){
    rareza = rar;
}

#endif
