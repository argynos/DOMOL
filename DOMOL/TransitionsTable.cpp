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
    aux->valor=-1;
    for (int i = 0; i < 20; i++) {
        this->tablaEstados[i] = aux ;
        for (int j = 0; j < 20; j++) {
            this->tablaTransciones[i][j] = aux;
            this->tablaCasos[i][j] = aux;
        }
    }
}

void TransitionsTable::insertarTransicion(tipo_datoTT *id, int i, int j){
    this->tablaTransciones[i][j]=id;
}

void TransitionsTable::insertarEstado (tipo_datoTT *id, int estado){
    this->tablaEstados[estado]=id;
}

void TransitionsTable::insertarCaso (tipo_datoTT *origen, tipo_datoTT *destino, int fila, int col) {
    int o,d;
    if (col==0){
        this->tablaCasos[fila][col]=origen; 
    }else{
        for (int i=0; i<20; i++){
            if (strcmp(this->tablaEstados[i]->nombre, origen->nombre) == 0)
                o=i;
            if (strcmp(this->tablaEstados[i]->nombre, destino->nombre) == 0)
                d=i;
        }
        this->tablaCasos[fila][col] =this->tablaTransciones[o][d];
    }
    
}

bool TransitionsTable::conectividad(int limit) {
    bool cruz=true;
    bool filas=true;
    bool fila=false;
    for (int i=0; i<20 && i<limit && cruz; i++){
        if (this->tablaTransciones[i][0]->valor!=-1 || this->tablaTransciones[1][i]->valor!=-1)
            cruz=false;

    }


    for (int i=0; i<20 && i<limit && filas; i++){
        if (i!=1){
        for (int j=0; j<20 && j<limit && !fila; j++){
            if(this->tablaTransciones[i][j]->valor!=-1)
                fila=true;
        }
        if (!fila)
            filas=false;
        fila=false;
        }
    }

    return (filas && cruz);
}

bool TransitionsTable::test5(tipo_cadena estado, tipo_cadena transicion, int limit){
    int iestado=0;
    bool valida=false;
    for (int i=0; i<20 && i<limit; i++){
        if (strcmp(this->tablaEstados[i]->nombre, estado) == 0 ){
            iestado=i;
        }
    } 
    for (int i=0;i<20 && i<limit; i++){
        for (int j=0; j<20 && j<limit; j++){
            if (strcmp(this->tablaTransciones[i][j]->nombre, transicion) == 0 ){
                if (i==iestado)
                    valida=true;
            }
        }
    }
    return valida;
}

string TransitionsTable::mostrar(int limit, int casos) {
    string cad = "               ";
    string blancos="  ";
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
     cad +="\n";
    
    cad += "COMPROBACION DE LOS CASOS DE USO\n";
    cad += "================================\n";
     for (int i = 0; i < 20 && i < casos; i++) {
        cad = cad + "CASO ";
        for (int j = 0; j < 20 && i < limit; j++) {
            aux = this->tablaCasos[i][j]->nombre;
            aux= aux.substr(0,2);
            if (strcmp(aux.c_str(), blancos.c_str()) !=0){
                if (j!=0)
                    cad+='\t';
                cad= cad + this->tablaCasos[i][j]->nombre + '\n';
            }
        }
        cad +="\n";  
        }

    return cad;

}


