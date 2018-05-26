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

/**
* Vector de caracteres
*/
typedef char tipo_cadena[50];

/**
*
*/
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

    /**
    * Tabla de casos
    */
    tipo_datoTT *tablaCasos[20][20];
	
    /**
     * Constructor por defecto del sistema.
     * Inicializa la tabla de transiciones con entradas a null y a ''.
     */
    TransitionsTable();

    /**
    * Inserta una nueva transición en la tabla de transiciones.
    *
    * @param id: tipo de  dato a insertar en la tabla de transiciones.
    * @param i: fila de la tabla de transiciones en la que insertar.
    * @param j: columna de la tabla de transiciones en la que insertar.
    */
    void insertarTransicion (tipo_datoTT *id, int i, int j);

    /**
    * Inserta un nuevo estado en la tabla de estados.
    *
    * @param id: tipo de estado a insertar en la tabla de estados.
    * @param i: posición en la que insertar.
    */
    void insertarEstado (tipo_datoTT *id, int i);

    /**
    * Inserta un tipo_datoTT que representa una transición, en la que el origen es el estado 
    * recibido por parámetro y el destino es el estado destino recibido por parámetro.
    *
    * @param origen: tipo de dato de tipo estado como origen.
    * @param destino: tipo de dato de tipo estado como destino.
    * @param fila: fila de la tabla en la que insertar.
    * @param col: columna de la tabla en la que insertar.
    */
    void insertarCaso (tipo_datoTT *origen, tipo_datoTT *destino, int fila, int col);

    /**
    * Comprueba que no existen errores semánticos en lo que no se puede llegar de un estado
    * al estado final o que desde el estado inicial no se puede llegar al estado pasado por
    * parámetro.
    *
    * @param limit: número total de estados.
    * @return true si se puede llegar desde un estado a otro, false si no.
    */
    bool conectividad(int limit);
	
    /**
    * Comprueba que cuando se define el comportamiento de un estado, sólo se hace uso de 
    * transiciones que tienen como origen el estado del que estamos definiendo el comportamiento.
    *
    * @param estado:
    * @param transicion:
    * @param limit:
    */
    bool test5(tipo_cadena estado, tipo_cadena transicion, int limit); 

    /**
     * Este método monta una cadena con el contenido de la tabla de transiciones y la 
     *tabla de casos de uso.
     *
     * @param limit: número total de estados.
     * @param casos: número total de casos.
     * @return una cadena con la tabla montada como string.
     */
    string mostrar(int limit, int casos);



};

#endif //SYMBOLTABLE_DOMOL_TRANSITIONSTABLE_H
