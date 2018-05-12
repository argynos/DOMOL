
/*
 * SymbolTable.h
 *
 *  Created on: 17 abr. 2018
 *      Author: y3_y0
 */

#ifndef SYMBOLTABLE_H_
#define SYMBOLTABLE_H_

#include <iostream>
#include <string>

using namespace std;

typedef char tipo_cadena[50];
typedef char cadena[250];
/**
  * Tipo de valor del tipo de dato que almacenaremos en la tabla de s?mbolos.
  */
union tipo_valor {
    int valor_entero;
    float valor_real;
    bool valor_logico;
};

/**
 * Struct que guarda las columnas de la tabla de s?mbolos. Cada variabele es una columna.
 * Si a?adimos un nuevo tipo_datoTS, estamos a?adiendo una nueva fila a la tabla.
 */
struct tipo_datoTS {
    tipo_cadena nombre;
    int tipo;
    tipo_valor valor;
};

class SymbolTable {

private:
    /**
     * Contador de inserciones en la tabla de s?mbolos.
     */
    int counter;

    tipo_datoTS *tablaSimbolos[100];

public:

    /**
     * Constructor por defecto
     */
    SymbolTable();

    /**
     * Busca un elemento en la tabla de s?mbolos por el nombre de tipo cadena dado por par?metro.
     * Si el elemento existe, retorna el tipo de dato en la variable id, la posici?n en la que se encuentra en
     * la variable pos, y devuelve true.
     * Si no existe, retorna false.
     *
     * @param list: tabla de s?mbolos.
     * @param nombre: id a buscar.
     * @param id: elemento encontrado.
     * @param pos: posici?n en la que se encuentra el elemento encontrado.
     * @return true si se encuentra, false si no.
     */
    bool buscar(tipo_cadena nombre, tipo_datoTS *&id, int &pos);


    /**
     * Inserta un nuevo dato en la tambla de s?mbolos. Si ya existe y el tipo de dato es igual al que ya hay almacenado
     * en la tambla de s?mbolos, lo actualiza. Si no existe, lo inserta en la ?ltima posici?n de la tabla.
     *
     * @param list: Tabla de s?mbolos.
     * @param id: elemento a insertar.
     */
    bool insertar(tipo_datoTS *id);

    int size();

    string mostrar();
};
#endif /* SYMBOLTABLE_H_ */
