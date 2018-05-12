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
#include <iostream>
#include "SymbolTable.h"
#include <string.h>
#include <string>
#include <sstream>
using namespace std;

SymbolTable::SymbolTable() {
    this->counter = 0;
}

bool SymbolTable::buscar(tipo_cadena nombre, tipo_datoTS *&id, int &pos) {
    bool encontrado = false;

    for (int i = 0; i < this->size() && !encontrado; i++) {
        if(strcmp(this->tablaSimbolos[i]->nombre, nombre) == 0) {
            encontrado = true;
            id = this->tablaSimbolos[i];
            pos = i;
        }
    }
    return encontrado;
}

bool SymbolTable::buscar(int value, tipo_datoTS *&id, int type) {
    bool encontrado = false;
    for (int i = 0; i < this->size() && !encontrado; i++) {
        if(this->tablaSimbolos[i]->valor.valor_entero == value && this->tablaSimbolos[i]->tipo == type) {
            encontrado = true;
            id = this->tablaSimbolos[i];
        }
    }

    return encontrado;
}


bool SymbolTable::insertar(tipo_datoTS *id) {
    tipo_datoTS *idAux = new tipo_datoTS;
    int pos = -1;
    if (buscar(id->nombre, idAux, pos)) {
        //update
        if (id->tipo == idAux->tipo) {
            this->tablaSimbolos[pos]->valor = id->valor;
            return true;
        } else
            return false;

    } else {
        //insert
        (this->tablaSimbolos[counter]) = (id);
        counter++;
        return true;
    }
}

int SymbolTable::size() {
    return counter;
}


string SymbolTable::mostrar() {
    string cad = "";
    if(this->size() > 0) {
    for (int i = 0; i < this->size(); i++) {
        cad = cad + this->tablaSimbolos[i]->nombre;
        cad = cad + "\t\t";
        if (this->tablaSimbolos[i]->tipo==3)
            cad+="actuador"; 
        if (this->tablaSimbolos[i]->tipo==4)
            cad+="estado";
        if (this->tablaSimbolos[i]->tipo==5)
            cad+="transicion";     
        else if (this->tablaSimbolos[i]->tipo>=10)
                cad+="sensor ";        
        if((this->tablaSimbolos[i]->tipo % 10) == 0 ) {
            cad += "entero";
            cad = cad + "\t\t";
            if (this->tablaSimbolos[i]->tipo<10)
                cad += static_cast<std::ostringstream*>(&(std::ostringstream() << this->tablaSimbolos[i]->valor.valor_entero))->str();
        } else if((this->tablaSimbolos[i]->tipo % 10) == 1 ) {
            cad += "real";            
            cad = cad + "\t\t";
            if (this->tablaSimbolos[i]->tipo<10)
                cad += static_cast<std::ostringstream*>(&(std::ostringstream() << this->tablaSimbolos[i]->valor.valor_real))->str();   
        } else if((this->tablaSimbolos[i]->tipo % 10) == 2 ) {
            cad += "lógico";
            cad = cad + "\t\t";
            if (this->tablaSimbolos[i]->tipo<10)
            if(this->tablaSimbolos[i]->valor.valor_logico == 0) {
                cad += "falso";
            } else {
                cad += "verdadero";    
            }
        }else if(this->tablaSimbolos[i]->tipo == 4 ||  this->tablaSimbolos[i]->tipo == 5 ) {
            cad = cad + "\t\t";
            cad += static_cast<std::ostringstream*>(&(std::ostringstream() << this->tablaSimbolos[i]->valor.valor_entero))->str();   
        } 
        cad += "\n";
    }
    } else {
        cout << "La tabla está vacía." << endl;
    }
    return cad;
}

