/*
 * Jueguito-gacha
 * Alexander Zamudio Cano
 * A01710688
 * 20/5/2026
 */
 #ifndef MEJORAS_H
 #define MEJORAS_H
 
 #include "Item.h"

 class Mejoras : public Item {
    private:
        double bonus_monedas;
    public:
        Mejoras():Item(), bonus_monedas(0.0) {};
        Mejoras(std::string nom, std::string rar, double bon) 
        : Item(nom, rar), bonus_monedas(bon) {};

        double get_bonus_monedas();

        void set_bonus_monedas(double);

        double aplicar_efecto();
        std::string to_string();
    
 };

double Mejoras::get_bonus_monedas(){
        return bonus_monedas;
 }

void Mejoras::set_bonus_monedas(double bon){
        bonus_monedas = bon;
 }

double Mejoras::aplicar_efecto() {
        return bonus_monedas;
 }

std::string Mejoras::to_string() {
    std::stringstream aux;
    aux << "Mejora: " << nombre << " | Rareza: " << rareza 
        << " | Bonus: +" << bonus_monedas << " monedas.\n";
    return aux.str();
}

#endif