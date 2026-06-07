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
#include "Gacha.h"

class Jugador{
    private: // Se declaran los atributos
        // Nombre del jugador
        std::string nombre;
        // Cantidad de dinero disponible para apostar
        double moneda;
        // Vector polimorfico que almacena los Items ganados
        // (Mejoras, Reliquias, Herramientas)
        std::vector<Item*> inventario;
        // Puntero para interactuar con el sistema gacha
        Gacha* sistema_gacha;

    public: // Se declaran los metodos
        /**
         * Constructor por default
         * Inicializa nombre vacio, monedas en 0 y puntero nulo para el gacha.
         *
         * @param
         * @return Objeto Jugador
         */
        Jugador(): nombre(""), moneda(0.0), sistema_gacha(nullptr) {};

        /**
         * Constructor con parametros
         * Inicializa el jugador con un nombre,
         * monedas iniciales y conexion al gacha.
         *
         * @param nom Nombre del jugador
         * @param mon Monedas iniciales
         * @param gacha Puntero al objeto Gacha global
         * @return Objeto Jugador
         */
        Jugador(std::string nom, double mon, Gacha* gacha)
        : nombre(nom), moneda(mon), sistema_gacha(gacha) {};

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
        void mostrar_inventario();
        void apostar_en_gacha(int cantidad_tiradas);

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
 * Cobra el precio al jugador y genera Items desde el gacha para
 * agregarlos al inventario. Calcula los costos aplicando descuentos.
 *
 * @param cantidad_tiradas El numero de veces que se tirara en el gacha
 * @return
 */
void Jugador::apostar_en_gacha(int cantidad_tiradas) {
    double costo_base = sistema_gacha->get_precio_tirada();
    double descuento = obtener_descuento_gacha();
    double costo_final_por_tirada = costo_base - descuento;

    if (costo_final_por_tirada < 5.0) {
        costo_final_por_tirada = 5.0;
    }
    double costo_total = costo_final_por_tirada * cantidad_tiradas;

    if (moneda >= costo_total) {
        moneda -= costo_total;
        std::cout << "\n" << nombre << " pago " << costo_total
                  << " monedas. Monedas restantes: " << moneda << "\n";

        if (cantidad_tiradas == 1) {
            inventario.push_back(sistema_gacha->tirar());
        } else {
            std::vector<Item*> premios = sistema_gacha->tirar(cantidad_tiradas);
            for (int i = 0; i < premios.size(); i++) {
                inventario.push_back(premios[i]);
            }
        }

    } else {
        std::cout << "\n" << nombre << ", no tienes suficientes monedas para "
                  << cantidad_tiradas << " tiradas. Ocupas "
                  << costo_total << " monedas POBRE >:(.\n";
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
