/**
 * PROYECTO FINAL DOMOL
 *
 * Fecha: 2017/2018
 * Versión: 2.0
 *
 * Autores: Sergio Fernández Rincón
 *          Luis González Gómez.
 *
 *
 * TEORÍA DE LENGUAJES
 */
#ifndef SYMBOLTABLE_DOMOL_TRANSITIONSTABLE_H
#define SYMBOLTABLE_DOMOL_TRANSITIONSTABLE_H

#include <iostream>
#include <string>
#include <vector>
#include "SymbolTable.h"

using namespace std;

typedef char tipo_cadena[50];
struct tipo_datoTT {
    tipo_cadena nombre;
    int valor;
};

/**
 * Declaración de la clase TransitionsTable.
 *
 */
class TransitionsTable {


public:
    
    /**
    * Tabla de estados
    */
    tipo_datoTT *tablaEstados[20];

    /**
    * Tabla de transiciones 
    */
    tipo_datoTT *tablaTransciones[20][20];

    tipo_datoTT *tablaCasos[20][20];

    bool test5(tipo_cadena estado, tipo_cadena transicion, int limit); 
    /**
     * Constructor por defecto del sistema.
     * Inicializa la tabla de transiciones con entradas a null y a ''.
     */
    TransitionsTable();

	/**
	* Inserta una nueva transición en la tabla de transiciones.
	*
	* @param id: tipo de  dato a insertar en la tabla de transiciones.
	* @param i: fila.
	* @param j: columna.
	*/
    void insertarTransicion (tipo_datoTT *id, int i, int j);

    /**
	* Inserta un nuevo estado en la tabla de estados.
	*
	* @param id: tipo de estado a insertar en la tabla de estados.
	* @param i: posición en la que insertar.
	*/
    void insertarEstado (tipo_datoTT *id, int i);

    void insertarCaso (tipo_datoTT *origen, tipo_datoTT *destino, int fila, int col);

    bool conectividad(int limit);

    /**
     * This method shows the transition table of the system
     * @param an int to limit the print method acording with the states quantity
     * @return a string with the transition table.
     */
    string mostrar(int limit, int casos);



};

#endif //SYMBOLTABLE_DOMOL_TRANSITIONSTABLE_H
