/*
 * Jueguito-gacha
 * Alexander Zamudio Cano
 * A01710688
 * 04/06/2026
 */

/*
 * Clase Mejoras hereda de Item.
 * Representa un objeto que otorga un bonus en la cantidad
 * de monedas que el jugador gana al robar exitosamente.
 *
 */
 #ifndef MEJORAS_H_
 #define MEJORAS_H_
 
 #include "Item.h"

 class Mejoras : public Item {
    private: // Se declaran los atributos
        // Cantidad de monedas extra que da la mejora al ganar
        double bonus_monedas;

    public: // Se declaran los metodos
        /**
         * Constructor por default
         * Llama al constructor de Item e inicializa el bonus en 0.0.
         *
         * @param
         * @return Objeto Mejoras
         */
        Mejoras():Item(), bonus_monedas(0.0) {};

        /**
         * Constructor con parametros
         * Llama al constructor de Item con nombre y rareza, e inicializa el bonus.
         *
         * @param nom Nombre de la mejora
         * @param rar Rareza de la mejora
         * @param bon Cantidad de bonus de monedas
         * @return Objeto Mejoras
         */
        Mejoras(std::string nom, std::string rar, double bon) 
        : Item(nom, rar), bonus_monedas(bon) {};

        double get_bonus_monedas();

        void set_bonus_monedas(double);

        double aplicar_efecto();
        std::string get_tipo();
        std::string to_string();
    
 };

 /**
 * Devuelve la cantidad de bonus de monedas de la mejora.
 *
 * @param
 * @return Double con el bonus de monedas
 */
double Mejoras::get_bonus_monedas(){
        return bonus_monedas;
 }

 /**
 * Modifica la cantidad de bonus de la mejora.
 *
 * @param bon Nuevo valor para el bonus
 * @return
 */
void Mejoras::set_bonus_monedas(double bon){
        bonus_monedas = bon;
 }

 /**
 * Metodo sobreescrito de la clase Item.
 * Devuelve el valor del efecto de este item especifico.
 *
 * @param
 * @return Double equivalente al bonus de monedas
 */
double Mejoras::aplicar_efecto() {
        return bonus_monedas;
 }

 /**
 * Metodo sobreescrito de la clase Item.
 * Identifica el tipo especifico de la clase hija.
 *
 * @param
 * @return String con la palabra "Mejora"
 */
 std::string Mejoras::get_tipo() { 
    return "Mejora"; 
 }

 /**
 * Genera una cadena de texto con la informacion detallada de la mejora.
 *
 * @param
 * @return String formateado con nombre, rareza y efecto
 */
std::string Mejoras::to_string() {
    std::stringstream aux;
    aux << "Mejora: " << nombre << " | Rareza: " << rareza 
        << " | Bonus: +" << bonus_monedas << " monedas.\n";
    return aux.str();
}

#endif
