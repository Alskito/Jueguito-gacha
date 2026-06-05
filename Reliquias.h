/*
 * Jueguito-gacha
 * Alexander Zamudio Cano
 * A01710688
 * 04/06/2026
 */

 /*
 * Clase Reliquias hereda de Item.
 * Representa un objeto que aplica un descuento en el costo
 * de las tiradas del minijuego Gacha.
 *
 */

 #ifndef RELIQUIAS_H_
 #define RELIQUIAS_H_
 
 #include "Item.h"

 class Reliquias : public Item {
    private: // Se declaran los atributos
        // Valor que se restara al precio del gacha
        double descuento_gacha;

    public: // Se declaran los metodos
        /**
         * Constructor por default
         * Llama al constructor de Item e inicializa el descuento en 0.0.
         *
         * @param
         * @return Objeto Reliquias
         */
        Reliquias():Item(), descuento_gacha(0.0) {};

        /**
         * Constructor con parametros
         * Llama al constructor de Item con nombre y rareza, e inicializa el descuento.
         *
         * @param nom Nombre de la reliquia
         * @param rar Rareza de la reliquia
         * @param desc Cantidad a descontar
         * @return Objeto Reliquias
         */
        Reliquias(std::string nom, std::string rar, double desc) 
        : Item(nom, rar), descuento_gacha(desc) {};

        double get_descuento_gacha();

        void set_descuento_gacha(double);

        double aplicar_efecto();
        std::string get_tipo();
        std::string to_string();
        
    
 };

/**
 * Devuelve la cantidad de descuento que ofrece la reliquia.
 *
 * @param
 * @return Double con el valor del descuento
 */
 double Reliquias::get_descuento_gacha(){
        return descuento_gacha;
 }

 /**
 * Modifica la cantidad de descuento de la reliquia.
 *
 * @param desc Nuevo valor para el descuento
 * @return
 */
 void Reliquias::set_descuento_gacha(double desc){
        descuento_gacha = desc;
 }

 /**
 * Metodo sobreescrito de la clase Item.
 * Devuelve el valor del efecto de este item especifico.
 *
 * @param
 * @return Double equivalente al descuento de gacha
 */
 double Reliquias::aplicar_efecto() {
        return descuento_gacha;
 }

 /**
 * Metodo sobreescrito de la clase Item.
 * Identifica el tipo especifico de la clase hija.
 *
 * @param
 * @return String con la palabra "Reliquia"
 */
 std::string Reliquias::get_tipo() { 
    return "Reliquia"; 
 }

 /**
 * Genera una cadena de texto con la informacion detallada de la reliquia.
 *
 * @param
 * @return String formateado con nombre, rareza y efecto
 */
std::string Reliquias::to_string() {
    std::stringstream aux;
    aux << "Reliquia: " << nombre << " | Rareza: " << rareza 
        << " | Descuento: -" << descuento_gacha << "%\n";
    return aux.str();
} 

#endif


