# Jueguito-gacha
El propósito de este proyecto es simular la experiencia de un sistema gacha. El jugador asume el rol de alguien que ha invertido todo su dinero en tiradas y, en su desesperación, debe recurrir a "robar" distintos objetivos para conseguir monedas.

Entre mayor sea la dificultad del objetivo, mejor será la recompensa. Las monedas obtenidas se pueden apostar en el gacha para obtener objetos que funcionan como buffs pasivos para facilitar los futuros robos.

## Funcionalidad
A través de un menú interactivo, el programa permite al usuario:

Robar (Minijuego): Sistema para adivinar un PIN secreto de 3 dígitos. Cuenta con intentos limitados según la dificultad elegida y un sistema de pistas estilo Wordle (indica qué números pertenecen al código y cuáles están en la posición correcta).

Tirar en el Gacha: Sistema de apuestas con cálculo de probabilidades para obtener objetos de diferentes rarezas.

Gestionar Inventario: Visualización de los ítems obtenidos (Mejoras, Reliquias y Herramientas).

## Casos que harían que el proyecto deje de funcionar:

Errores de memoria: Debido al manejo de punteros, existe la posibilidad de que ocurra un acceso inválido que termine la ejecución del programa.

Entrada del usuario en el minijuego: El sistema espera que el código se ingrese con un formato específico (tres números separados por espacios). Ingresar caracteres no numéricos o formatos extraños puede romper el flujo de lectura (std::cin) y causar un mal funcionamiento.

## Consideraciones
SEGUIR LAS INSTRUCCIONES

Visual studio code:
Hasta ahora no he tenido ningún problema al ejecutar el código en VS Code, pero recomiendo usar la terminal de Windows por si acaso.

Terminal:

El archivo debería funcionar tanto en Windows como en Linux (también en Mac, pero dudo que alguien lo haga...). En el caso de Mac, no tengo idea de cómo se haría.
Recuerda que todos los archivos .h deben estar en la misma carpeta que el archivo main.

Windows

`g++ main.cpp -o gacha`

`.\gacha.exe`

Linux:

`g++ main.cpp -o gacha`

`./gacha`

## UML
<img width="1738" height="1426" alt="UML" src="https://github.com/user-attachments/assets/79cf6d2f-d191-4194-9301-5459f58e75d6" />


