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

typedef char tipo_cad[50];

/**
 * Campos de la tabla de transiciones.
 */
struct campoTabla {
    tipo_cad nombre;
    int tipo;
};

/**
 * Declaración de la clase TransitionsTable.
 *
 */
class TransitionsTable {

private:

    /**
     * Número de estados.
     */
    int nstates;

    /**
     * Número de transiciones.
     */
    int ntransitions;

    /**
    * Tabla de transiciones del sistema.
    */
    campoTabla *tablaTransciones[20][20];

public:

    /**
     * Constructor por defecto del sistema.
     * Inicializa la tabla de transiciones con entradas a null y a -1.
     */
    TransitionsTable();

    /**
    * Este método busca los estados que haya en la tabla de símbolos y los guarda
    * en el vector de estado
    *
    * @param SymbolTable: tabla de símbolos donde buscar.
    * @param estados: vector de estados.
    * @return true si hay estados, false si no.
    */
    bool buscarEstados(tipo_datoTS *symbolTable[], int size, campoTabla *estados[]);

    /**
     * Este método inserta los estados en la tabla de transiciones.
     *
     * @param estados: vector de estados a insertar.
     * @return true si se ha conseguido la inserción, false si no.
     */
    bool insertarEstados(campoTabla *estados[]);

    /**
     * Devuelve el número de estados que tiene la tabla de transiciones.
     *
     * @return número de estados como entero.
     */
    int statesSize();

    /**
     * Devuelve el número de transiciones que tiene la tabla de transiciones.
     *
     * @return número de transiciones como entero.
     */
    int transitionsSize();


    /**
     * Este método inserta todas las transiciones en la tabla.
     *
     * @param transiciones: vector de transiciones a insertar.
     * @return true si se consigue la inserción, false si no.
     */
    bool insertarTransiciones( tipo_datoTS *transicion, tipo_datoTS *estadoOrigen, tipo_datoTS *estadoDestino);

    /**
     * This method shows the transition table of the system
     *
     * @return a string with the transition table.
     */
    string mostrar();

    /**
     * Destructor del sistema.
     */
    ~TransitionsTable();

    bool buscarEnTabla(tipo_datoTS *symbolTable[], int size, int toFound, tipo_datoTS *&id);

};

#endif //SYMBOLTABLE_DOMOL_TRANSITIONSTABLE_H
