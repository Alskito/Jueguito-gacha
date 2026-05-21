/*
 * Jueguito-gacha
 * Alexander Zamudio Cano
 * A01710688
 * 20/5/2026
 */
 #ifndef RELIQUIAS_H
 #define RELIQUIAS_H
 
 #include "Item.h"

 class Reliquias : public Item {
    private:
        double descuento_gacha;
    public:
        Reliquias():Item(), descuento_gacha(0.0) {};
        Reliquias(std::string nom, std::string rar, double desc) 
        : Item(nom, rar), descuento_gacha(desc) {};

        double get_descuento_gacha();

        void set_descuento_gacha(double);

        double aplicar_efecto();
        std::string to_string();
    
 };

 double Reliquias::get_descuento_gacha(){
        return descuento_gacha;
 }

 void Reliquias::set_descuento_gacha(double desc){
        descuento_gacha = desc;
 }

 double Reliquias::aplicar_efecto() {
        return descuento_gacha;
 }

std::string Reliquias::to_string() {
    std::stringstream aux;
    aux << "Reliquia: " << nombre << " | Rareza: " << rareza 
        << " | Descuento: -" << descuento_gacha << "%\n";
    return aux.str();
} 

#endif

