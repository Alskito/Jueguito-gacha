/*
 * Jueguito-gacha
 * Alexander Zamudio Cano
 * A01710688
 * 04/06/2026
 */

/*
 * Main del projecto, ejecuta el juego.
 * Contiene el flujo principal, el menu de opciones interactivo
 * y la instanciacion de los objetos Jugador, Gacha y Robar.
 *
 */


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Gacha.h"
#include "Jugador.h"
#include "Robar.h"

#ifdef _WIN32
    #include <windows.h>
#endif

/**
 * Limpia la consola para mantener una interfaz limpia.
 * Ejecutar "cls" en Windows
 * o "clear" en otros sistemas.
 *
 * @param
 * @return
 */
void limpiar_pantalla() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main() {

    #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
    #endif

    // Semilla generadora: hace que los números de rand()
    // cambien en cada ejecución basada en el reloj de la compu.
    srand(time(NULL));

    std::cout << "\033[1;36m";
    std::cout << "==========================================\n";
    std::cout << "     .𖥔 ݁ ˖๋ ࣭ ⭑   GACHA  .𖥔 ݁ ˖๋ ࣭ ⭑    \n";
    std::cout << "==========================================\n";
    std::cout << "\033[0m";

    std::string nombre;
    std::cout << "Ingresa tu nombre: ";
    std::cin >> nombre;

    // Se instancian los objetos principales del juego
    Gacha gambling(100.0);
    Jugador player(nombre, 100.0);
    Robar minijuego_caja;
    limpiar_pantalla();

    // Un poco de lore
    std::cout << "====================================\n";
    std::cout << " Eres una persona promedio. Sin embargo, "
              << "todo cambio cuando descubriste\n";
    std::cout << " un pequeño juego llamado \033[1;35m'Gonshin Impacto'\033[0m"
              << "(perdon, la falta de originalidad).\n\n";
    std::cout << " Te volviste un adicto sin remedio a su sistema gacha. "
              << "Gastaste hasta el\n";
    std::cout << " ultimo centavo y ahora no tienes dinero. "
              << "En tu total desesperacion, has\n";
    std::cout << " decidido abandonar la moralidad y "
              << "\033[1;31mrecurrir al robo\033[0m.\n";
    std::cout << "====================================\n";
    std::cin.ignore();
    std::cout << "\n\033[1;33mPresiona ENTER para "
              << "comenzar tu vida criminal...\033[0m";
    std::cin.get();

    int opcion = 0;

    // Bucle principal del juego
    while (opcion != 4) {
        limpiar_pantalla();
        // Condicion de derrota
        if (player.get_moneda() <= 0) {
            std::cout << "\n\033[1;31m=== BANCARROTA ===\n"
                      << "Te has quedado sin dinero. GAME OVER.\033[0m\n";
            opcion = 4;
        }
        else {
            // Se calcula el costo del gacha para mostrar en la interfaz
            double costo_base = gambling.get_precio_tirada();
            double descuento = player.obtener_descuento_gacha();
            double costo_actual_gacha = costo_base - descuento;

            // Precio minimo para que el gacha nunca sea gratis
            if (costo_actual_gacha < 5.0) {
                costo_actual_gacha = 5.0;
            }

            // Menu principal
            std::cout << "\n\033[1;36m----------------------"
                      << "--------------------\033[0m\n";
            std::cout << "  \033[1;33mBALANCE:\033[0m \033[1;32m"
                      << player.get_moneda() << "\033[0m monedas\n";
            std::cout << "\033[1;36m------------------"
                      << "------------------------\033[0m\n";
            std::cout << "Que deseas hacer?\n";
            std::cout << "  \033[1;31m[1]\033[0m Robar\n";
            std::cout << "  \033[1;35m[2]\033[0m Tirar en el Gacha ("
                      << costo_actual_gacha << " monedas)\n";
            std::cout << "  \033[1;34m[3]\033[0m Ver mi Inventario\n";
            std::cout << "  \033[1;37m[4]\033[0m Salir del juego\n";
            std::cout << "Elige una opcion (1-4): ";

            std::cin >> opcion;
            limpiar_pantalla();

            switch (opcion) {
                case 1:
                    minijuego_caja.jugar(player);
                    std::cout << "\n\033[1;33mPresiona ENTER para "
                              << "volver al menú principal\033[0m";
                    std::cin.ignore();
                    std::cin.get();
                    break;

                case 2: {
                    int cantidad;
                    gambling.mostrar_probabilidades();
                    std::cout << "¿Cuantas tiradas quieres hacer? ("
                              << costo_actual_gacha << " c/u): ";
                    std::cin >> cantidad;

                    if (cantidad > 0) {
                        double costo_total = costo_actual_gacha * cantidad;

                        if (player.get_moneda() >= costo_total) {
                            player.restar_monedas(costo_total);
                            std::cout << "\n" << nombre << " pago "
                                      << costo_total
                                      << " monedas. Monedas restantes: "
                                      << player.get_moneda() << "\n";

                            if (cantidad == 1) {
                                player.agregar_al_inventario(gambling.tirar());
                            } else {
                                std::vector<Item*> premios =
                                    gambling.tirar(cantidad);

                                for (int i = 0; i < premios.size(); i++) {
                                    player.agregar_al_inventario(premios[i]);
                                }
                            }
                        } else {
                            std::cout << "\n" << nombre
                                      << ", no tienes suficientes monedas "
                                      << "para " << cantidad
                                      << " tiradas. Ocupas "
                                      << costo_total
                                      << " monedas POBRE >:(.\n";
                        }
                    }

                    std::cout << "\n\033[1;33mPresiona ENTER "
                              << "para volver al menú principal\033[0m";
                    std::cin.ignore();
                    std::cin.get();
                    break;
                }

                case 3:
                    player.mostrar_inventario();
                    std::cout << "\n\033[1;33mPresiona ENTER "
                              << "para volver al menú principal\033[0m";
                    std::cin.ignore();
                    std::cin.get();
                    break;

                case 4:
                    // Libertad de expresion idk
                    std::cout << "                  ⢀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
                    std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⠤⠖⠛⠉⠉⠉⠉⠉⠉⠓⠲⠤⣄⠀⠀⠀⠀\n";
                    std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⣀⠔⠋⢀⠄⠊⠀⠀⠤⢀⠀⠒⠢⡀⠀⠀⠀⠙⠢⣄⠀⠀⠀\n";
                    std::cout << "⠀⠀⠀⠀⠀⠀⢀⠖⠁⠀⠀⣠⠀⠀⠀⠀⠀⠀⠀⠀⠀⠑⠄⠀⠀⠀⠀⠈⢧⡀⠀⠀⠀\n";
                    std::cout << "⠀⠀⠀⠀⠀⢰⠋⠀⠀⢀⣼⠇⢀⡎⠀⠀⠀⠀⠀⠀⠀⣤⠀⠀⠀⠀⠀⠀⠀⢳⡀⠀⠀\n";
                    std::cout << "⠀⠀⠀⠀⢠⡟⠀⢠⢂⡾⣿⢆⣿⡑⠀⠀⠀⢀⡀⢸⠀⣿⡀⢸⡄⠀⠀⠀⠀⠀⢧⠀\n";
                    std::cout << "⠀⠀⣀⡴⠋⠀⠀⡾⣸⠇⠧⠞⡹⠉⠀⠀⠀⢸⢀⣿⣴⢏⣧⢸⡿⠀⠀⠀⠀⠀⠸⡆\n";
                    std::cout << "⠈⠙⠧⢴⡎⠀⠀⣷⣏⣠⣴⣶⣯⡂⠐⠒⠢⠏⠞⣽⠋⠀⠿⢼⢻⠀⠀⠀⠀⠀⢳"
                              << "⣷\n";                
                    std::cout << "⠀⠀⠀⢸⢠⠄⠀⡿⣿⠋⣎⣸⣟⡏⠀⠀⠀⠀⠀⣿⣿⣿⢦⡀⢸⡂⠀⠀⠐⢸⡀⠛"
                              << "⢤⣀ \n";
                    std::cout << "⠀⠀⠀⢸⡰⡇⠀⣿⡝⠀⢯⣈⣹⠇⠀⠀⠀⠀⢸⢣⣾⣛⡇⢻⣾⠁⠀⡆⠀⢸⡿⣶⠒"
                              << "⠚⠉\n";
                    std::cout << "⠀⠀⠀⠀⢷⣳⡀⢸⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⠧⣄⡼⠃⠈⡼⠀⢠⡇⠁⣸⢿⠇\n";
                    std::cout << "⠀⠀⠀⠀⠈⠛⢷⡀⢿⣷⣤⣀⠀⠀⢄⡀⢀⡀⠀⠀⠀⠀⠀⣰⠇⢐⣼⢁⣴⣿⠟⠀\n";
                    std::cout << "⠀⠀⠀⠀⠀⠀⠀⠙⠚⠻⠉⠀⣽⣶⣶⡶⠥⠤⣤⣴⣶⣶⢿⠏⣴⣾⣻⣽⠋⠈⠀\n";
                    std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣿⣷⣿⠈⠑⢚⣿⣟⣿⣿⠛⠋⠛⠛⠉⠀⠀⠀\n";
                    std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣴⢿⣟⣿⣿⣿⣿⣿⣿⣾⡟⣟⣦⠀⠀⠀⠀⠀⠀⠀⠀\n";
                    std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⢠⣾⢯⣿⡞⢺⣿⣿⣿⣿⣿⠿⣞⡵⣫⢧⠀⠀⠀⠀⠀⠀⠀\n";
                    std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⡞⢳⣿⡷⣭⣿⣿⣿⣿⣿⣿⡖⣿⣷⣭⠿⣧⡀⠀⠀⠀⠀⠀\n";
                    std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⢹⣽⡁⣿⣿⣿⣿⣛⣿⡟⢱⢿⣾⡿⠻⠀⠀⠀⠀⠀⠀\n";
                    std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡷⣻⣷⣾⣿⣿⣿⣿⡿⡽⣞⣿⠉⠊⠀⠀⠀⠀⠀⠀⠀\n";
                    std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠙⡇⠀⠀⢸⢏⠉⠿⢳⠟⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
                    std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⠀⠀⢸⢸⠀⠀⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
                    std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⡶⣶⡟⠘⡤⢤⣾⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
                    std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⠉⠁⠀⠛⠛⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";

                    std::cout << "\n\033[1;32m¡Gracias por jugar, " << nombre
                              << ".... Benji no me repruebe\033[0m\n";
                    break;

                default:
                    std::cout << "\033[1;31mOpcion no valida.\033[0m\n";
                    std::cout << "\n\033[1;33mPresiona ENTER "
                              << "para volver al menú principal\033[0m";
                    std::cin.ignore();
                    std::cin.get();
                    break;
            }
        }
    }
 return 0;
}
