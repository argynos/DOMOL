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
#include "TransitionsTable.h"
#include <iostream>
#include "SymbolTable.h"
#include <string.h>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

/**
* Implementación de la clase TransitionsTable
*/

TransitionsTable::TransitionsTable() {
    tipo_datoTT *aux = new tipo_datoTT;
    strcpy(aux->nombre, "            ");
    for (int i = 0; i < 20; i++) {
        this->tablaEstados[i] = aux ;
        for (int j = 0; j < 20; j++) {
            this->tablaTransciones[i][j] = aux;
        }
    }
}

void TransitionsTable::insertarTransicion(tipo_datoTT *id, int i, int j){
    this->tablaTransciones[i][j]=id;
}

void TransitionsTable::insertarEstado (tipo_datoTT *id, int estado){
    this->tablaEstados[estado]=id;
}

string TransitionsTable::mostrar(int limit) {
    string cad = "               ";
    string aux = "";
    for (int i = 0; i< 20 && i< limit; i++){
        aux="";
        aux =aux + this->tablaEstados[i]->nombre+"               ";
        cad = cad + aux.substr(0,15);
    }
    cad += "\n               ";
    for (int i = 0; i< 20 && i< limit; i++)
        cad += "===============";
    cad +="\n";
    for (int i = 0; i < 20 && i < limit; i++) {
        aux="";
        aux =aux + this->tablaEstados[i]->nombre + "               ";
        cad = cad + aux.substr(0,14);
        cad = cad + "|";
        for (int j = 0; j < 20 && i < limit; j++) {
            aux="";
            aux =aux + this->tablaTransciones[i][j]->nombre+"               ";
            cad = cad + aux.substr(0,15);
        }
        cad +="\n";
    }
    return cad;

}


