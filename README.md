# Jueguito-gacha
El propósito de este proyecto es crear un juego gacha. El jugador tendrá que conseguir dinero (todavía no defino cómo), el cual podrá usar en el gacha (gambling) para conseguir objetos de distintas rarezas que servirán como buffs a la hora de conseguir más dinero.

## Funcionalidad
El programa, a través de un menú, permitirá al usuario conseguir dinero, ver su inventario, gamblear en el gacha, etc. TODAVÍA HAY MUCHAS COSAS QUE QUIERO IMPLEMENTAR, COMO UN MINIJUEGO PARA CONSEGUIR EL DINERO, UN SISTEMA DE VENTA DE ITEMS, UNA MANERA DE PERDER, ETC., POR LO QUE ESTA SECCIÓN CAMBIARÁ CONSTANTEMENTE.

## Casos que harían que el proyecto deje de funcionar:

Fugas de memoria: Si no se implementa un destructor en la versión final y el usuario hace demasiadas tiradas, la memoria se saturará y el programa terminará crasheando.

Errores de memoria: Debido al manejo de punteros, existe la posibilidad de que ocurra un acceso inválido que termine la ejecución del programa.

Fallo en la lógica del juego: Actualmente el gacha no verifica la cantidad de dinero que tiene el jugador. Tengo que corregirlo, ya que el usuario podrá tirar infinitamente (incluso con saldo negativo), rompiendo todo.
## Consideraciones
Visual studio code:

Hasta ahora no he tenido ningún problema al ejecutar el código en VS Code, pero recomiendo usar la terminal de Windows por si acaso.

Terminal:

Hasta ahora el programa solamente ha sido probado en Windows, por lo que las instrucciones solo están pensadas para ese sistema operativo. A futuro, probaré el programa en Linux para asegurarme de que funcione en ambos OS.
Recuerda que todos los archivos .h deben estar en la misma carpeta que el archivo main.

`g++ main.cpp -o gacha`

`.\gacha.exe`

## UML
<img width="1610" height="1318" alt="Gacha-Jueguito" src="https://github.com/user-attachments/assets/d70102d8-8ee3-4209-a7e8-cd37919ddabd" />

