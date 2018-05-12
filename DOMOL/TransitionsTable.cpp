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

template<typename T>
inline size_t Countof(const T (&)) { return 0; }

template<typename T, size_t S>
inline size_t Countof(const T (&)[S]) { return S; }

using namespace std;


TransitionsTable::TransitionsTable() {
    campoTabla *tipe = new campoTabla;
    tipo_cad namenull = "";
    strcpy(tipe->nombre, namenull);
    tipe->tipo = -1;
    this->ntransitions = 0;
    this->nstates = 0;
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            this->tablaTransciones[i][j] = tipe;
        }
    }
}

bool TransitionsTable::insertarEstados(campoTabla *estados[]) {
    int k = 0;
    bool firstRow = false;
    bool firstColumn = false;
    for (int i = 0; i < this->statesSize() + 1 && (k < this->statesSize()); i++) {
        for (int j = 0; j < this->statesSize() + 1 && (k < this->statesSize()); j++) {
            if ((i == 0) && (j != 0))
                if (k < this->statesSize()) {
                    tablaTransciones[i][j] = estados[k];
                    k++;
                    if (k == this->statesSize()) {
                        firstRow = true;
                    }
                }
        }
    }
    k = 0;
    for (int i = 0; i < this->statesSize() + 1 && (k < this->statesSize()); i++) {
        for (int j = 0; j < this->statesSize() + 1 && (k < this->statesSize()); j++) {
            if (i != 0 && j == 0)
                if (k < this->statesSize()) {
                    tablaTransciones[i][j] = estados[k];
                    k++;
                    if (k == this->statesSize()) {
                        firstColumn = true;
                    }
                }
        }
    }
    return firstColumn && firstRow;
}

string TransitionsTable::mostrar() {
    string cad = "";
    cad += "           ";
    for (int i = 0; i < statesSize() + 1; i++) {
        for (int j = 0; j < statesSize() + 1; j++) {
            if (i == 0 && j != 0) {
                cad += this->tablaTransciones[i][j]->nombre;
                cad += "  ";
            } else if (i != 0 && j == 0) {
                cad += this->tablaTransciones[i][j]->nombre;
            } else {
                if (this->tablaTransciones[i][j]->tipo != -1) {
                    cad += this->tablaTransciones[i][j]->nombre;
                    cad += "  ";
                }
            }
        }
        cad += "\n";
    }
    return cad;

}

bool TransitionsTable::buscarEstados(tipo_datoTS *symbolTable[], int size, campoTabla *estados[]) {
    int k = 0;
    bool found = false;

    for (int i = 0; i < size; i++) {
        if (symbolTable[i]->tipo == 4) {
            found = true;
            strcpy(estados[k]->nombre, symbolTable[i]->nombre);
            estados[k]->tipo = symbolTable[i]->valor.valor_entero;
            k++;
            this->nstates++;
        }
    }
    return found;
}

int TransitionsTable::statesSize() {
    return this->nstates;
}

int TransitionsTable::transitionsSize() {
    return this->ntransitions;
}

bool TransitionsTable::buscarEnTabla(tipo_datoTS *symbolTable[], int size, int toFound, tipo_datoTS *&id) {
    bool found = false;
    for (int i = 0; i < size; i++) {
        if(symbolTable[i]->valor.valor_entero == toFound) {
            found = true;
            id = symbolTable[i];
        }
    }
    return found;
}

bool TransitionsTable::insertarTransiciones(tipo_datoTS *transicion, tipo_datoTS *estadoOrigen, tipo_datoTS *estadoDestino) {
    int column = 0;
    int row = 0;
    bool dFound = false;
    bool oFound = false;
    for (int i = 0; i < this->statesSize()+1; i++) {
        for (int j = 0; j < this->statesSize()+1; j++) {
            if(i == 0 && j != 0) {
                if(this->tablaTransciones[i][j]->tipo == estadoDestino->valor.valor_entero) {
                    column = j;
                    dFound = true;
                }
            }
            if(i != 0 && j == 0) {
                if(this->tablaTransciones[i][j]->tipo == estadoOrigen->valor.valor_entero) {
                    row = i;
                    oFound = true;
                }
            }
        }
    }

    if(oFound && dFound) {
        strcpy(this->tablaTransciones[row][column]->nombre, transicion->nombre);
        this->tablaTransciones[row][column]->tipo = transicion->valor.valor_entero;
    }
    return false;
}

TransitionsTable::~TransitionsTable() {

}

