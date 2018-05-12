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
};
/**
 * Declaración de la clase TransitionsTable.
 *
 */
class TransitionsTable {

private:




public:
    /**
    * Tabla de transiciones y Tabla de estados.
    */
    tipo_datoTT *tablaEstados[20];
    tipo_datoTT *tablaTransciones[20][20];

    void insertarTransicion (tipo_datoTT *id, int i, int j);
    void insertarEstado (tipo_datoTT *id, int i);
    /**
     * Constructor por defecto del sistema.
     * Inicializa la tabla de transiciones con entradas a null y a '      '.
     */
    TransitionsTable();

   

    /**
     * This method shows the transition table of the system
     * @param an int to limit the print method acording with the states quantity
     * @return a string with the transition table.
     */
    string mostrar(int limit);



};

#endif //SYMBOLTABLE_DOMOL_TRANSITIONSTABLE_H
