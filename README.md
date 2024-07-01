#Proyecto "Maze Knights"

##Introducción:
Los estudiantes Sasha Chavarría, Leonardo Calderón y Andrey Bejarano diseñaron un programa que tiene como objetivo simular un laberinto en el cual 2 jugadores compiten por quedarse con un cofre del tesoro, todo bajo el lenguaje de programación c++ y el entorno de desarrollo QT

##Arquitectura del Sistema:
El proyecto está conformado por 2 partes importantes: backend y frontend. Contiene 7 archivos .cpp acompañados por sus respetivos encabezados (archivos .h) los cuales permitirán la creación de objetos y subrutinas necesarios para la ejecución correcta del programa, presentando complejidad algorítmica con el uso de nodos para la generación de rutas y caminos

##Diseño del Código:
En cada uno de los archivos .h se llevaron a cabo la definición de las constantes, clases y métodos necesarios según fuesen necesarios para el propósito con el que fueron creados, además de implementar las librerías de c++ requeridas en múltiples segmentos de código.

##Detalles de los Archivos:


gamewindow.cpp - gamewindow.h: Archivo que funciona como el núcleo del programa, encargado de empezar la ejecución de todos los procesos necesarios para la simulación (apartado gráfico del laberinto).


Graph.cpp - Graph.h: Archivo utilizado para la elaboración del grafo que permitirá la creación de las celdas y sus posibles conexiones, a partir de algoritmos como el de profundidad y anchura.


main.cpp - main.h: Archivo central del programa que se encarga de ejecutar la ventana principal del programa (ventana de Bienvenida).


mainwindow.cpp - mainwindow.h: Archivo encargado de generar la ventana del menu, donde se podrá comenzar con la ejecución del juego.


Matrix.cpp - Matrix.h: archivo encargado de crear la matriz, con la cual se podrá crear el laberinto con sus conexiones (aristas) con base en alguno de los algoritmos de búsqueda.


Node.cpp - Node.h: Archivo encargado de crear los nodos que formarán parte del grafo a utilizar dentro del programa, con su respectivo tipo de dato asignado de antemano


powers.cpp - powers.h: Archivo encargado de generar los poderes disponibles dentro del programa para cada uno de los jugadores y de la creación de portales para pasar de un lado a otro



##Ejecución


Descargar proyecto de Git


Instalar QT Pro


Abrir el proyecto en QT y correrlo



##Status del Proyecto
Atol de piña
