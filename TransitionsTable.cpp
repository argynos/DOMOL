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

tipo_datoTS *ts = new tipo_datoTS;
int main() {
    SymbolTable *sy = new SymbolTable();
    tipo_cadena tipo_cad = "Inicial";
    strcpy(ts->nombre, tipo_cad);
    ts->tipo = 4;
    ts->valor.valor_entero = 0;
    sy->insertar(ts);

    ts = NULL;
    delete ts;
//    tipo_datoTS *ts1 = new tipo_datoTS;
//    tipo_cadena tipo_cad1 = "Final";
//    strcpy(ts1->nombre, tipo_cad1);
//    ts1->tipo = 4;
//    ts1->valor.valor_entero = 1;
//    sy->insertar(ts1);
//    ts1 = NULL;

    tipo_datoTS *ts2 = new tipo_datoTS;
    tipo_cadena tipo_cad2 = "Todo_OFF";
    strcpy(ts2->nombre, tipo_cad2);
    ts2->tipo = 4;
    ts2->valor.valor_entero = 2;
    sy->insertar(ts2);
    ts2 = NULL;

    delete ts2;

    tipo_datoTS *ts3 = new tipo_datoTS;
    tipo_cadena tipo_cad3 = "iniciar";
    strcpy(ts3->nombre, tipo_cad3);
    ts3->tipo = 5;
    ts3->valor.valor_entero = 0;
    sy->insertar(ts3);
    ts3 = NULL;
    delete(ts3);
//
//    tipo_datoTS *ts4 = new tipo_datoTS;
//    tipo_cadena tipo_cad4 = "AC_ON";
//    strcpy(ts4->nombre, tipo_cad4);
//    ts4->tipo = 4;
//    ts4->valor.valor_entero = 4;
//    sy->insertar(ts4);
//    ts4 = NULL;

    TransitionsTable *tst = new TransitionsTable();
    campoTabla *c = new campoTabla;
    c->tipo = -1;
    tipo_cadena nulla = "";
    strcpy(c->nombre, nulla);
    campoTabla *estados[4];
    campoTabla *c1 = new campoTabla;
    c1->tipo = -1;
    strcpy(c1->nombre, nulla);
    campoTabla *c2= new campoTabla;
    c2->tipo = -1;
    strcpy(c2->nombre, nulla);
    campoTabla *c3 = new campoTabla;
    c3->tipo = -1;
    strcpy(c3->nombre, nulla);
    campoTabla *c4 = new campoTabla;
    c4->tipo = -1;
    strcpy(c4->nombre, nulla);
//    campoTabla *c5 = new campoTabla;
//    c5->tipo = -1;
//    strcpy(c5->nombre, nulla);
//    campoTabla *c6 = new campoTabla;
//    c6->tipo = -1;
//    strcpy(c6->nombre, nulla);


    estados[0] = c;
    estados[1] = c1;
    estados[2] = c2;
    estados[3] = c3;
    estados[4] = c4;
//    estados[5] = c5;
//    estados[6] = c6;

    delete c;
    delete c1;
    delete c2;
    delete c3;
    delete c4;
//    delete c5;
//    delete c6;
    int size = sy->size();
    if(tst->buscarEstados(sy->tablaSimbolos, size, estados)) {
        tst->insertarEstados(estados);
//        tst->mostrar();
    }

    sy->buscar(0, ts3, 5);
    sy->buscar(0, ts2, 4);
    sy->buscar(2, ts, 4);
    tst->insertarTransiciones(ts3, ts2, ts);
    tst->mostrar();


}


