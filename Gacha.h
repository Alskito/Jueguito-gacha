/*
 * Jueguito-gacha
 * Alexander Zamudio Cano
 * A01710688
 * 20/5/2026
 */

#ifndef GACHA_H_
#define GACHA_H_

#include <iostream>


class Gacha{
    private:
        double precio_tirada;
    public:
        Gacha(): precio_tirada(0.0) {};
        Gacha(double pre): precio_tirada(pre) {};

        double get_precio_tirada();

        void set_precio_tirada(double);

    
        void tirar();
        void tirar(int cantidad);
        void mostrar_probabilidades();
};

double Gacha::get_precio_tirada(){
    return precio_tirada;
}

void Gacha::set_precio_tirada(double pre){
    precio_tirada = pre;
}

void Gacha::tirar(){
    std::cout << "[Gacha] Tirada individual por " << precio_tirada << " monedas.\n";
}

void Gacha::tirar(int cantidad) {
    std::cout << "[Gacha] Tirada multiple de " << cantidad << " items por " 
         << (precio_tirada * cantidad) << " monedas.\n";
}

void Gacha::mostrar_probabilidades() {
    std::cout << "[Gacha] Probabilidades: Comun 70%, Raro 20%, Epico 8%, Legendario 2%.\n";
}

/* 
Nada es funcional todavia, sin embargo deberia de servir como avance... espero.
Posiblemente haga listas de varias palabras que se junten aleatoriamente al tirar el gacha para darle nombre al Item,
tambien ocurriria lo mismo con la rareza.

*/
#endif