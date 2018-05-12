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
#ifndef SYMBOLTABLE_H_
#define SYMBOLTABLE_H_

#include <iostream>
#include <string>

using namespace std;

/**
* vector de chars para montar un string.
*/
typedef char tipo_cadena[50];

/**
  * Tipo de valor del tipo de dato que almacenaremos en la tabla de símbolos.
  */
union tipo_valor {
    int valor_entero;
    float valor_real;
    bool valor_logico;
};

/**
 * Struct que guarda las columnas de la tabla de símbolos. Cada variabele es una columna.
 * Si añadimos un nuevo tipo_datoTS, estamos añadiendo una nueva fila a la tabla.
 */
struct tipo_datoTS {
    tipo_cadena nombre;
    int tipo;
    tipo_valor valor;
};

/**
* Declaración de la clase SymbolTable.
*/
class SymbolTable {

private:
    /**
     * Contador de inserciones en la tabla de símbolos.
     */
    int counter;

public:

    /**
    * Tabla de símbolos de la aplicación.
    */
    tipo_datoTS *tablaSimbolos[100];

    /**
     * Constructor por defecto
     */
    SymbolTable();

    /**
     * Busca un elemento en la tabla de símbolos por el nombre de tipo cadena dado por parámetro.
     * Si el elemento existe, retorna el tipo de dato en la variable id, la posición en la que se encuentra en
     * la variable pos, y devuelve true.
     * Si no existe, retorna false.
     *
     * @param nombre: id a buscar.
     * @param id: elemento encontrado.
     * @param pos: posición en la que se encuentra el elemento encontrado.
     * @return true si se encuentra, false si no.
     */
    bool buscar(tipo_cadena nombre, tipo_datoTS *&id, int &pos);


    /**
     * Busca una entrada en la tabla por su tipo
     *
     * @param tipo: tipo a buscar.
     * @param id: entrada encontrada.
     * @return true si se ha encontrado, false si no.
     */
    bool buscar(int value, tipo_datoTS *&id, int type);

    /**
     * Inserta un nuevo dato en la tambla de símbolos. Si ya existe y el tipo de dato es igual al que ya hay almacenado
     * en la tambla de símbolos, lo actualiza. Si no existe, lo inserta en la última posición de la tabla.
     *
     * @param list: Tabla de símbolos.
     * @param id: elemento a insertar.
     * @return true si se ha insertado, false si no.
     */
    bool insertar(tipo_datoTS *id);

	/**
	 * Devuelve el tamaño de la tabla de símbolos.
	 *
	 * @return tamaño de la tabla de símbolos como entero.
	 */
    int size();

    /**
     * Este método monta la tabla de síbolos con el formato adecuado.
     *
     * @return string: cadena de caracteres con la tabla de símbolos.
     */
    string mostrar();

};
#endif /* SYMBOLTABLE_H_ */
