[![MIT License](https://img.shields.io/badge/License-MIT-green.svg)](https://choosealicense.com/licenses/mit/)

# TATETI en C - Juego de Consola

Este es un juego de TATETI (Tambien conocido como TIC-TAC-TOE) simple implementado en C para jugar en la consola. El objetivo es proporcionar una versión básica y funcional del juego para dos jugadores.

## Requisitos

Para compilar y ejecutar el juego, necesitarás un compilador de C, como GCC, instalado en tu sistema. Si aún no lo tienes instalado, puedes descargarlo [aquí](https://gcc.gnu.org/).

## Instrucciones

### Clona este repositorio en tu máquina local.

```bash
    git clone https://github.com/paluz/TA-TE-TI.git
```

### Compila el codigo
    
```bash
    cd /TA-TE-TI/
    gcc tateti.c -o tateti
```

### Ejecuta el juego

Una vez compilado con éxito, podrás ejecutar el juego con el siguiente comando:

```bash
    ./tateti
```

## Cómo jugar

El juego se juega en una cuadrícula de 3x3. Un jugador utiliza "X" y el otro "O". El juego comienza con un tablero vacío, y los jugadores se turnan para seleccionar una celda vacía donde colocar su ficha. El objetivo es conseguir tres fichas en línea en horizontal, vertical o diagonal.

- El primer jugador es "X" y el segundo jugador es "O".

- Para hacer una jugada, simplemente ingresa el numero correspondiente de la celda en la que deseas colocar tu ficha siguiendo la distribucion del teclado numerico. 
Por ejemplo, "1" colocaría tu ficha en la fila inferior y la primera columna.

- El juego detectará automáticamente cuando un jugador gane o se produzca un empate.

- Diviértete y ¡buena suerte!

## Personalización

Si deseas personalizar el juego o agregar nuevas características, puedes modificar el archivo fuente `tateti.c`.

## Contribuciones

Si deseas contribuir al proyecto o informar sobre problemas, siéntete libre de abrir un problema o enviar una solicitud de extracción.

¡Disfruta del juego de TATETI en C!

---

Este proyecto es proporcionado "tal cual" y sin garantías. Puedes utilizarlo y modificarlo según tus necesidades. ¡Diviértete jugando!

[![MIT License](https://img.shields.io/badge/License-MIT-green.svg)](https://choosealicense.com/licenses/mit/)

    
