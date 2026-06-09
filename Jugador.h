/*
 * Jueguito-gacha
 * Alexander Zamudio Cano
 * A01710688
 * 04/06/2026
 */

/*
 * Clase Jugador gestiona al usuario.
 * Controla el balance de monedas, el almacenamiento de items (inventario),
 * y la interaccion directa con el sistema del Gacha.
 *
 */
#ifndef JUGADOR_H_
#define JUGADOR_H_

#include <string>
#include <iostream>
#include <vector>
#include "Item.h"
#include "Mejoras.h"
#include "Herramienta.h"
#include "Reliquias.h"

class Jugador{
    private: // Se declaran los atributos
        // Nombre del jugador
        std::string nombre;
        // Cantidad de dinero disponible para apostar
        double moneda;
        // Vector polimorfico que almacena los Items ganados
        // (Mejoras, Reliquias, Herramientas)
        std::vector<Item*> inventario;

    public: // Se declaran los metodos
        /**
         * Constructor por default
         * Inicializa nombre vacio y monedas en 0 
         *
         * @param
         * @return Objeto Jugador
         */
        Jugador(): nombre(""), moneda(0.0) {};

        /**
         * Constructor con parametros
         * Inicializa el jugador con un nombre y
         * monedas iniciales.
         *
         * @param nom Nombre del jugador
         * @param mon Monedas iniciales
         * @return Objeto Jugador
         */
        Jugador(std::string nom, double mon)
        : nombre(nom), moneda(mon) {};

        /**
         * Destructor
         * Libera la memoria de los punteros guardados en el inventario
         * para evitar fugas de memoria.
         *
         * @param
         * @return
         */
        ~Jugador() {
            for (size_t i = 0; i < inventario.size(); i++) {
                delete inventario[i];
            }
        }

        double get_moneda();

        void sumar_monedas(double cantidad);
        void restar_monedas(double cantidad);
        void agregar_al_inventario(Item* nuevo_item);
        void mostrar_inventario();

        double obtener_descuento_gacha();
        double obtener_bonus_monedas();
        int obtener_intentos_extra();
};

/**
 * Devuelve la cantidad de monedas actuales del jugador.
 *
 * @param
 * @return Double con las monedas
 */
double Jugador::get_moneda() {
    return moneda;
}

/**
 * Incrementa las monedas del jugador sumandole una cantidad especifica.
 *
 * @param cantidad Monto a sumar
 * @return
 */
void Jugador::sumar_monedas(double cantidad) {
    moneda += (cantidad);
}

/**
 * Reduce las monedas del jugador restandole una cantidad especifica.
 *
 * @param cantidad Monto a restar
 * @return
 */
void Jugador::restar_monedas(double cantidad) {
    moneda -= cantidad;
}

/**
 * Agrega un item al inventario del jugador
 * @param nuevo_item Puntero a un objeto de tipo Item que se va a agregar.
 * @return
*/
    void Jugador::agregar_al_inventario(Item* nuevo_item) {
        inventario.push_back(nuevo_item);
}

/**
 * Recorre el vector del inventario e imprime en pantalla
 * la informacion (to_string) de todos los items almacenados.
 *
 * @param
 * @return
 */
void Jugador::mostrar_inventario() {
    std::cout << "--- Inventario de " << nombre << " ---\n";
    for (size_t i = 0; i < inventario.size(); i++) {
        std::cout << inventario[i]->to_string();
    }
}

/**
 * Recorre el inventario buscando items de tipo "Reliquia" y
 * suma sus efectos para calcular el descuento total acumulado.
 *
 * @param
 * @return Double con el descuento total a aplicar
 */
double Jugador::obtener_descuento_gacha() {
            double descuento_total = 0.0;
            for (size_t i = 0; i < inventario.size(); i++) {
                if (inventario[i]->get_tipo() == "Reliquia") {
                    descuento_total += inventario[i]->aplicar_efecto();
                }
            }
            return descuento_total;
}

/**
 * Recorre el inventario buscando items de tipo "Mejora" y
 * suma sus efectos para calcular el bonus total acumulado.
 *
 * @param
 * @return Double con el bonus total de monedas a otorgar
 */
double Jugador::obtener_bonus_monedas() {
    double bonus_total = 0.0;
    for (size_t i = 0; i < inventario.size(); i++) {
        if (inventario[i]->get_tipo() == "Mejora") {
            bonus_total += inventario[i]->aplicar_efecto();
        }
    }
    return bonus_total;
}

/**
 * Recorre el inventario buscando items de tipo "Herramienta" y
 * suma sus efectos para calcular los intentos extra totales.
 *
 * @param
 * @return Int con el total de intentos extra conseguidos
 */
int Jugador::obtener_intentos_extra() {
    int intentos_totales = 0;
    for (size_t i = 0; i < inventario.size(); i++) {
        if (inventario[i]->get_tipo() == "Herramienta") {
            intentos_totales += (int)inventario[i]->aplicar_efecto();
        }
    }
    return intentos_totales;
}


#endif
