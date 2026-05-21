/*
 * Jueguito-gacha
 * Alexander Zamudio Cano
 * A01710688
 * 20/5/2026
 */

#ifndef JUGADOR_H_
#define JUGADOR_H_

#include <string>
#include <iostream>
#include <vector>
#include "Item.h"
#include "Mejoras.h"
#include "Multiplicador.h"
#include "Reliquias.h"
#include "Gacha.h"

class Jugador{
    private:
        std::string nombre;
        double moneda;
        std::vector<Item*> inventario; //No estoy 100% seguro si esto es correcto
        Gacha* sistema_gacha;
    public:
        Jugador(): nombre(""), moneda(0.0), sistema_gacha(NULL) {};
        Jugador(std::string nom, double mon, Gacha* gacha): nombre(nom), moneda(mon), sistema_gacha(gacha) {};

        void conseguir_monedas();
        void mostrar_inventario();

        /*
        void agrega_mejora(std::string nom, std::string rar, double bonus);
        void agrega_reliquia(std::string nom, std::string rar, double descuento);
        void agrega_multiplicador(std::string nom, std::string rar, double porcentaje);
        */
};

void Jugador::conseguir_monedas() {
    moneda = moneda + 100.0;
    std::cout << "[Jugador] " << nombre << " recolecto monedas. Balance: " << moneda << "\n";
}

void Jugador::mostrar_inventario() {
    std::cout << "--- Inventario de " << nombre << " ---\n";
    for (size_t i = 0; i < inventario.size(); i++) {
        // Se llama al to_string() del hijo correspondiente gracias al polimorfismo
        std::cout << inventario[i]->to_string();
    }
}

/*
void Jugador::agrega_mejora(std::string nom, std::string rar, double bonus) {
    inventario.push_back(new Mejoras(nom, rar, bonus));
}

void Jugador::agrega_reliquia(std::string nom, std::string rar, double descuento) {
    inventario.push_back(new Reliquias(nom, rar, descuento));
}

void Jugador::agrega_multiplicador(std::string nom, std::string rar, double porcentaje) {
    inventario.push_back(new Multiplicador(nom, rar, porcentaje));
}

Por ahora esto esta comentado debido a que es polimorfismo y requiero aprender a usarlo bien
*/

#endif