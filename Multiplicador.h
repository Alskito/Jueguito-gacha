/*
 * Jueguito-gacha
 * Alexander Zamudio Cano
 * A01710688
 * 20/5/2026
 */

 #ifndef MULTIPLICADOR_H
 #define MULTIPLICADOR_H

 #include "Item.h"

 class Multiplicador : public Item {
    private:
        double porcentaje_extra;
    public:
        Multiplicador():Item(), porcentaje_extra(0.0) {};
        Multiplicador(std::string nom, std::string rar, double por) 
        : Item(nom, rar), porcentaje_extra(por) {};

        double get_porcentaje_extra();

        void set_porcentaje_extra(double);

        double aplicar_efecto();
        std::string to_string();
    
 };

 double Multiplicador::get_porcentaje_extra(){
        return porcentaje_extra;
 }

 void Multiplicador::set_porcentaje_extra(double por){
        porcentaje_extra = por;
 }

 double Multiplicador::aplicar_efecto() {
        return porcentaje_extra;
 }

std::string Multiplicador::to_string() {
    std::stringstream aux;
    aux << "Multiplicador: " << nombre << " | Rareza: " << rareza 
        << " | Efecto: " << porcentaje_extra << "x\n";
    return aux.str();
}

#endif