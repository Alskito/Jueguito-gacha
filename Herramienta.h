/*
 * Jueguito-gacha
 * Alexander Zamudio Cano
 * A01710688
 * 04/06/2026
 */

 /*
 * Clase Herramienta hereda de Item.
 * Representa un objeto que el jugador puede obtener en el gacha
 * y que le otorga intentos adicionales en el minijuego de robar.
 *
 */
 #ifndef Herramienta_H_
 #define Herramienta_H_

 #include "Item.h"

 class Herramienta : public Item {
    private: // Se declaran los atributos
        // Cantidad de intentos adicionales que otorga la herramienta
        int intentos_extra;

    public: // Se declaran los metodos
        /**
         * Constructor por default
         * Llama al constructor de Item e inicializa intentos_extra en 0.
         *
         * @param
         * @return Objeto Herramienta
         */
        Herramienta():Item(), intentos_extra(0) {};

        /**
         * Constructor con parametros
         * Llama al constructor de Item con nombre y rareza,
         * e inicializa intentos_extra.
         *
         * @param nom Nombre de la herramienta
         * @param rar Rareza de la herramienta
         * @param inten Cantidad de intentos extra
         * @return Objeto Herramienta
         */
        Herramienta(std::string nom, std::string rar, int inten)
        : Item(nom, rar), intentos_extra(inten) {};

        double get_intentos_extra();

        void set_intentos_extra(int);

        double aplicar_efecto();
        std::string get_tipo();
        std::string to_string();

 };

 /**
 * Devuelve la cantidad de intentos extra que da la herramienta.
 *
 * @param
 * @return Double con los intentos extra
 * se maneja como double por el polimorfismo
 */
 double Herramienta::get_intentos_extra(){
        return intentos_extra;
 }

 /**
 * Modifica la cantidad de intentos extra de la herramienta.
 *
 * @param inten Nueva cantidad de intentos
 * @return
 */
 void Herramienta::set_intentos_extra(int inten){
        intentos_extra = inten;
 }

/**
 * Metodo sobreescrito de la clase Item.
 * Devuelve el valor del efecto de este item especifico.
 *
 * @param
 * @return Double equivalente a los intentos extra
 */
 double Herramienta::aplicar_efecto() {
        return intentos_extra;
 }

 /**
 * Metodo sobreescrito de la clase Item.
 * Identifica el tipo especifico de la clase hija.
 *
 * @param
 * @return String con la palabra "Herramienta"
 */
 std::string Herramienta::get_tipo(){
    return "Herramienta";
 }

 /**
 * Genera una cadena de texto con la informacion de la herramienta.
 *
 * @param
 * @return String formateado con nombre, rareza y efecto
 */
std::string Herramienta::to_string() {
    std::stringstream aux;
    aux << "Herramienta: " << nombre << " | Rareza: " << rareza
        << " | Efecto: +" << intentos_extra << " intentos de robo\n";
    return aux.str();
}

#endif
