# Sistema de Semáforos
Concepto de un sistema de semáforo implementado en C++, el cual cuenta con un semáforo con tres luces para los autos y un semáforo de dos luces para los peatones.

## Instalacion
Para poder ejecutar la interfáz gráfica, es necesario instalar la librería de SFML de acuerdo a la plataforma en la que se desee ejecutar.

### Windows
Se debe descargar la librería desde la página oficial de [`SFML`](https://www.sfml-dev.org/download/sfml/2.5.1/) y luego instalarla.
Asegurarse de tener un compilador de C++ instalado en el sistema, por ejemplo [`MinGW`](https://sourceforge.net/projects/mingw/).

### Linux
Se debe instalar la librería de SFML usando el siguiente comando.

```
sudo apt-get install libsfml-dev
```

## Ejecución
### Windows
Es necesario tener instalado [`CLion`](https://www.jetbrains.com/es-es/clion/) y desde allí, abrir la carpeta source.
CLion detectará el archivo `CMakeLists.txt` y estará listo para ejecutarse.

### Linux
Se puede realizar de la misma manera que en Windows si se tiene CLion instalado.
De no ser así, también puede ser compilado y ejecutado por consola, siguiendo los comandos siguientes.

```
~/Sistema_de_Semaforo$  cd source
~/Sistema_de_Semaforo/source$  cmake CMakeLists.txt
~/Sistema_de_Semaforo/source$  make
~/Sistema_de_Semaforo/source$  ./Sistema_Semaforo
```

De esta manera, se va a abrir la ventana gráfica y se va a poder hacer uso del software.

## Funcionalidad

