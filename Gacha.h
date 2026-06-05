/*
 * Jueguito-gacha
 * Alexander Zamudio Cano
 * A01710688
 * 04/06/2026
 */

 /*
 * Clase Gacha controla el sistema de recompensas aleatorias.
 * Se encarga de generar los objetos, calcular probabilidades 
 * y manejar los costos de cada tirada.
 *
 */
#ifndef GACHA_H_
#define GACHA_H_

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // Para la función rand() de generación aleatoria.
#include "Item.h"
#include "Mejoras.h"
#include "Reliquias.h"
#include "Herramienta.h"


class Gacha{ 
    private: // Se declaran los atributos
        // Costo base por cada tirada del gacha
        double precio_tirada; 

    public: // Se declaran los metodos
        /**
         * Constructor por default
         * Inicializa el precio de la tirada en 0.0.
         *
         * @param
         * @return Objeto Gacha
         */
        Gacha(): precio_tirada(0.0) {};

        /**
         * Constructor con parametros
         * Inicializa el precio de la tirada.
         *
         * @param pre Valor double del costo de tirada
         * @return Objeto Gacha
         */
        Gacha(double pre): precio_tirada(pre) {};

        double get_precio_tirada();

        void set_precio_tirada(double);

        void mostrar_probabilidades();
        Item* tirar(); 
        std::vector<Item*> tirar(int cantidad);
};

/**
 * Devuelve el precio actual de la tirada.
 *
 * @param
 * @return Double con el precio
 */
double Gacha::get_precio_tirada(){
    return precio_tirada;
}

/**
 * Modifica el precio de la tirada en el gacha.
 *
 * @param pre Nuevo precio
 * @return
 */
void Gacha::set_precio_tirada(double pre){
    precio_tirada = pre;
}

/**
 * Imprime en consola las probabilidades de obtener 
 * las distintas rarezas (Comun, Raro, Epico, Legendario).
 *
 * @param
 * @return
 */
void Gacha::mostrar_probabilidades() {
    std::cout << "Probabilidades: Comun 70%, Raro 20%, Epico 8%, Legendario 2%.\n";
}

/**
 * Realiza una tirada en el gacha.
 * Genera un nombre y determina la rareza basada en probabilidades 
 * y crea dinamicamente un objeto (Mejora, Reliquia o Herramienta).
 *
 * @param
 * @return Puntero al nuevo Item generado
 */
Item* Gacha::tirar() {
    //Lista de palabras para crear objetos
    std::string palabras1[] = {"Cristal", "Amuleto", "Anillo", "Fragmento", "Artefacto"};
    std::string palabras2[] = {"Mistico", "Antiguo", "Roto", "Luminoso", "Oscuro"};
    std::string palabras3[] = {"del Rey", "del Caos", "del Vacio", "de los Dioses", "del Abismo"};
    // Selecciona una palabra aleatoria de cada arreglo (rand() % 5 da un número entre 0 y 4) y las une con espacios.
    std::string nombre_gen = palabras1[rand() % 5] + " " + palabras2[rand() % 5] + " " + palabras3[rand() % 5];
    int dado = (rand() % 100) + 1;  // Tira un "dado" de 100 caras (genera de 1 a 100)
    std::string rareza_gen; // Variable para almacenar la rareza obtenida.
    double buff_poder = 1.0; // Multiplicador de estadística base del item.

    if (dado <= 70) {
        rareza_gen = "Comun";
        buff_poder = 1.0;
    } else if (dado <= 90) { 
        rareza_gen = "Raro";
        buff_poder = 2.5;
    } else if (dado <= 98) { 
        rareza_gen = "Epico";
        buff_poder = 5.0;
    } else {                 
        rareza_gen = "Legendario";
        buff_poder = 15.0;
    }

    int tipo = rand() % 3; // Genera 0, 1 o 2 para decidir que clase hija va a ser
    Item* nuevo_item = nullptr; // Inicializa un puntero vacío de la clase padre

    if (tipo == 0) {
        nuevo_item = new Mejoras(nombre_gen, rareza_gen, 10.0 * buff_poder);
    } else if (tipo == 1) {
        nuevo_item = new Reliquias(nombre_gen, rareza_gen, 2.0 * buff_poder);
    } else {
        nuevo_item = new Herramienta (nombre_gen, rareza_gen, 1 * (int)buff_poder);
    }

    std::cout << "Has obtenido: " << nombre_gen << " (" << rareza_gen << ")!\n";
    return nuevo_item;
}

/**
 * Realiza multiples tiradas en el gacha de forma consecutiva.
 * Llama repetidamente a la funcion tirar() normal.
 *
 * @param cantidad Numero entero de tiradas a realizar
 * @return Vector con punteros a los Items generados
 */
std::vector<Item*> Gacha::tirar(int cantidad) {
    std::vector<Item*> resultados;
    std::cout << "\nTirada multiple de " << cantidad << " deseos...\n";
    for(int i = 0; i < cantidad; i++) {
        resultados.push_back(tirar()); 
    }
    return resultados;
}

#endif
