/*
 * Jueguito-gacha
 * Alexander Zamudio Cano
 * A01710688
 * 04/06/2026
 */

/*
 * Clase Robar maneja el minijuego de la caja fuerte.
 * Permite al jugador apostar monedas y adivinar un PIN
 * de 3 digitos para ganar monedas.
 *
 */

#ifndef ROBAR_H_
#define ROBAR_H_

#include <iostream>
#include <cstdlib>
#include "Jugador.h"



class Robar {
    private: // Se declaran los atributos
        // Variables para almacenar los 3 digitos del PIN secreto
        int num1, num2, num3;
        // Limite de intentos del jugador segun la dificultad
        int intentos_maximos;
        // Factor por el cual se multiplicara la apuesta ganada
        int multiplicador_premio;

        /**
         * Limpia la consola para mantener limpia la interfaz.
         * Dependiendo del OS compila system("cls") o system("clear").
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
    public: // Se declaran los metodos
        /**
         * Constructor por default
         * Inicializa numeros en 0, 6 intentos y el multiplicador en 2x.
         *
         * @param
         * @return Objeto Robar
         */
        Robar() : num1(0), num2(0), num3(0), intentos_maximos(6),
                  multiplicador_premio(2) {};

        void jugar(Jugador& player);
};

/**
 * Ejecuta la logica principal del minijuego.
 * Genera el PIN aleatorio, maneja las apuestas y resta o suma las
 * monedas del objeto Jugador pasado por referencia.
 *
 * @param player Objeto Jugador (pasado por referencia)
 * @return
 */

void Robar::jugar(Jugador& player) {

    // Generacion del PIN aleatorio
    num1 = (rand() % 10);
    num2 = (rand() % 10);
    num3 = (rand() % 10);


    std::cout << "\n=== ADIVINA EL CODIGO ===\n";
    std::cout << "Balance actual: " << player.get_moneda() << " monedas.\n";

    std::cout << "\nQue tipo de objetivo deseas asaltar hoy?\n";
    std::cout << "1. Casa Normal (Dificultad Facil: 6 intentos | Premio x2)\n";
    std::cout << "2. Banco Local (Dificultad Media: 3 intentos | Premio x3)\n";
    std::cout << "3. Boveda del Gobierno (Dificultad Dificil: 1 intento "
              << "| Premio x4)\n";
    std::cout << "Elige tu objetivo (1-3): ";

    int opcion_dificultad;
    std::cin >> opcion_dificultad;
    limpiar_pantalla();

    if (opcion_dificultad == 2) {
        intentos_maximos = 3;
        multiplicador_premio = 3;
        std::cout << "\n[!] Has elegido: Banco Local\n";
    } else if (opcion_dificultad == 3) {
        intentos_maximos = 1;
        multiplicador_premio = 4;
        std::cout << "\n[!] Has elegido: Boveda del Gobierno\n";
    } else {
        intentos_maximos = 6;
        multiplicador_premio = 2;
        if (opcion_dificultad != 1) {
            std::cout << "\nOpcion no valida. Seleccionando "
                      << "'Casa Normal' por defecto]\n";
        } else {
            std::cout << "\n[!] Has elegido: Casa Normal\n";
        }
    }

    double apuesta;
    std::cout << "¿Cuanto dinero deseas invertir en las herramientas "
              << "para el robo? (0 para salir): ";
    std::cin >> apuesta;

    if (apuesta <= 0) return;

    if (apuesta > player.get_moneda()) {
        std::cout << "No puedes pagar el robo.\n";
        return;
    }

    player.restar_monedas(apuesta);

    limpiar_pantalla();
    std::cout << "\n[!] La caja fuerte tiene un "
              << "PIN de 3 digitos (del 0 al 9).\n";
    std::cout << "[!] Los numeros SE PUEDEN REPETIR.\n";
    std::cout << " - \033[1;32mVERDE\033[0m: "
              << "Numero correcto en la posicion correcta.\n";
    std::cout << " - \033[1;33mAMARILLO\033[0m: El numero esta en el PIN, "
              << "pero en otra posicion.\n";
    std::cout << " - \033[1;31mROJO\033[0m: "
              << "El numero no forma parte del PIN.\n";
    std::cout << "Tienes " << intentos_maximos
              << " intentos para adivinar el codigo correcto.\n";
    std::cout << "\n\033[1;31m SI FALLAS SE ACTIVARA LA ALARMA\033[0m\n";

    int intentos_extra = player.obtener_intentos_extra();
    int intentos_actuales = intentos_maximos + intentos_extra;
    bool abierta = false;

    while (intentos_actuales > 0 && !abierta) {
        std::cout << "\n--- Intentos restantes: "
                  << intentos_actuales << " ---\n";
        std::cout << "Ingresa 3 numeros separados por un espacio (ej. 4 1 9): ";

        int u1, u2, u3;
        std::cin >> u1 >> u2 >> u3;

        int secreto[3] = {num1, num2, num3};
        int intento[3] = {u1, u2, u3};
        char resultado[3] = {'R', 'R', 'R'};
        bool usado_secreto[3] = {false, false, false};

        for(int i = 0; i < 3; i++) {
            if(intento[i] == secreto[i]) {
                resultado[i] = 'G';
                usado_secreto[i] = true;
            }
        }

        for(int i = 0; i < 3; i++) {
            if(resultado[i] != 'G') {
                for(int j = 0; j < 3; j++) {
                    if(!usado_secreto[j] && intento[i] == secreto[j]) {
                        resultado[i] = 'Y';
                        usado_secreto[j] = true;
                        break;
                    }
                }
            }
        }

        std::cout << "Resultado: [ ";
        for(int i = 0; i < 3; i++) {
            if(resultado[i] == 'G') {
                std::cout << "\033[1;32m" << intento[i] << "\033[0m ";
            } else if(resultado[i] == 'Y') {
                std::cout << "\033[1;33m" << intento[i] << "\033[0m ";
            } else {
                std::cout << "\033[1;31m" << intento[i] << "\033[0m ";
            }
        }
        std::cout << "]\n";

        if(resultado[0] == 'G' && resultado[1] == 'G' && resultado[2] == 'G') {
            abierta = true;
        } else {
            intentos_actuales--;
        }
    }

    if (abierta) {
        double premio = apuesta * multiplicador_premio;
        double bonus_mejoras = player.obtener_bonus_monedas();
        double premio_total = premio + bonus_mejoras;

        limpiar_pantalla();
        std::cout << "\n[!!!] Robo exitoso [!!!]\n";

        std::cout << "La caja fuerte se ha abierto. ¡Robaste "
                  << premio_total << " monedas!\n";
        player.sumar_monedas(premio_total);
    } else {
        limpiar_pantalla();
        std::cout << "\n\033[1;31m[X] ALARMA ACTIVADA [X]\033[0m\n";
        std::cout << "El codigo correcto era: [ " << num1 << " " << num2 << " "
                  << num3 << " ]\n";
        std::cout << "Afortunadamente lograste escapar, "
                  << "pero tuviste que dejar tus herramientas\n";
        std::cout << "Perdiste " << apuesta << " monedas.\n";
    }
}

#endif
