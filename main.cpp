#include <iostream>
#include "Gacha.h"
#include "Jugador.h"



int main() {

    Gacha gambling(50.0);


    Jugador player("Alskito", 500.0, &gambling);

    // Sobreescritura sin polimorfismo
    Mejoras prueba_mejoras("algo", "Raro", 25.0);
    Reliquias prueba_reliquia("sepa", "Legendario", 15.0);
    Multiplicador prueba_multiplicador("idk", "Epico", 2.0);

    std::cout << "--- Objetos >:D ---\n";
    std::cout << prueba_mejoras.to_string();
    std::cout << prueba_reliquia.to_string();
    std::cout << prueba_multiplicador.to_string();
    std::cout << "-------------------------------\n\n";


    /*
    player.agrega_mejora("algo", "Raro", 25.0);
    player.agrega_reliquia("sepa", "Legendario", 15.0);
    player.agrega_multiplicador("idk", "Epico", 2.0);
    */


    player.mostrar_inventario();
    
    std::cout << "\n";
    player.conseguir_monedas();
    std::cout << "\n";

   
    gambling.mostrar_probabilidades();
    gambling.tirar();      
    gambling.tirar(10);    

    return 0;
}

/*
Todavia falta bastante, nada es realmente funcional, tengo que agregar los menus, un sistema para conseguir dinero,
el generador de objetos y el gancha en si, ya que todo lo que hace ahorita es imprimir texto.
Posiblemente requiera agregar mas cosas,sin embargo, creo que hasta ahora esto es una buena base.
*/