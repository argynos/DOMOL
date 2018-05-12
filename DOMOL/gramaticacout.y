/*
*
* PROYECTO FINAL DOMOL
*
* gramatica.y
*
* Autores: Fernández Rincón, Sergio Y González Gómez, Luis.
* Version: 1.0
* Fecha: 02/05/2018
*/
%{
	#include <iostream>
	#include <stdio.h>
	#include <string.h>
	#include <math.h>
	
	using namespace std;

	extern int n_lines;
	extern int yylex();
	extern FILE *yyin;
	extern FILE *yyout;

	void yyerror(const char *s) {
        printf("Error sintáctico en la línea %d.\n", n_lines);
	}

%}

%union{
	int entero;
	float real;
	char id[20];
	bool booleano;
}

%start programa
%token VARIABLES SENSORES ACTUADORES ESTADOS TRANSICIONES COMPORTAMIENTO MOV
%token HT HET LT LET AND OR NOT EQUAL NOT_EQUAL
%token <id> ID 
%token <id> FLOAT INT BOOL SI SINO ACTIVAR DESACTIVAR  TRANSICION ENTONCES
%token <entero> NUMERO
%token <real> REAL
%token <booleano> TRUE FALSE VERDADERO FALSO
%type <real> expr
%type <booleano> expr_logic

%left TRUE FALSE
%left AND OR
%right NOT
%left HT HET LT LET EQUAL NOT_EQUAL

%left '+' '-'  /* asociativo por la izquierda, misma prioridad */
%left '*' '/' '%'   /* asociativo por la izquierda, prioridad alta */
%right '^' /*asociativo por la derecha, prioridad mas alta */
%left MenosUnario  /*asociativo por la izquierda, siempre la mas alta*/

%%


programa: {;}
	| programa zona_variables zona_sensores zona_actuadores zona_estados zona_transiciones zona_comportamiento
	;

/* CONJUNTO DE PRODUCIONES PARA LA ZONA DE COMPORTAMIENTO */

zona_comportamiento: inicio_zona_comportamiento lista_comportamientos {cout <<"ZONA COMPORTAMIETNOS" <<endl;}
					;

inicio_zona_comportamiento : COMPORTAMIENTO '\n' {cout << "inicio zona comportamiento"<< n_lines << endl;}
							;							

lista_comportamientos: comportamiento_estado {cout << "un solo comportamiento" << endl;}
					| lista_comportamientos comportamiento_estado {cout << "varios comportamientos" << endl;}

comportamiento_estado: ID '[' '\n' instruccion_basica ']' '\n' {cout << "comportamientgo estado "<< $1<< " detectado " << endl;}
					| ID '[' '\n' lista_alternativas ']' '\n' {cout << "comportamientgo estado "<< $1<< " detectado " << endl;}
					| error '\n' {yyerrok;}
					;	

instruccion_basica: instrucion_actuador 
					| instruccion_variable
					| instruccion_transicion
					| instruccion_basica instrucion_actuador 
					| instruccion_basica instruccion_variable
					| instruccion_basica instruccion_transicion					
					;

instrucion_actuador : ACTIVAR ID  '\n'{cout << "activar " << $2 << endl;}
					| DESACTIVAR ID '\n' {cout << "desactivar " << $2 << endl;}
					| error '\n' {yyerrok;}
					;

instruccion_variable : ID '=' expr '\n' {cout << "asignacion " << $1 <<endl;}


lista_alternativas: alternativa {cout << "una sola alternativa" << endl;}
					| lista_alternativas alternativa {cout << "varias alternativas" << endl;}
					;
alternativa: SI expr_logic '[' '\n' instruccion_basica ']' '\n'			{cout <<  "Hemos encontrado un SI simple"<< endl;}
			|SI expr_logic '[' '\n' instruccion_basica ']' '\n' SINO '[' instruccion_basica ']' '\n'			{cout <<  "Hemos encontrado un SI con un SINO"<< endl;}
			;

instruccion_transicion : TRANSICION ID '\n' {cout << "transicion hacia " << $2 << " detecetada" << endl;}
						;


/* CONJUNTO DE PRODUCIONES PARA LA ZONA DE TRANSICIONES */
zona_transiciones: inicio_zona_transiciones lista_transiciones {cout<< "ZONA TRANSICIONES" << endl;}
	;

inicio_zona_transiciones: TRANSICIONES '\n' {cout << "inicio zona transiciones" << n_lines << endl;}
	;


lista_transiciones: transicion {cout << "una sola linea de transicion" << endl;}	
			|lista_transiciones transicion {cout << "varias lineas de transiciones" << endl;}
			|;

transicion:  ID ':' ID MOV ID  '\n' {cout << "transicion" << endl;}
		| error '\n' {yyerrok;}
		;

/* CONJUNTO DE PRODUCIONES PARA LA ZONA DE ESTADOS */
zona_estados: inicio_zona_estados lista_estados {cout << "ZONA ESTADOS" <<endl;}
				|;
inicio_zona_estados: ESTADOS '\n' {cout << "inicio estados" << n_lines << endl;}

lista_estados: 	lista_estados estado {cout << "varias lineas de estados" << endl;}
				| estado {cout << "un solo estado" << endl;}

estado: ID '\n' {cout << "estado " << $1 << endl;}	

/* CONJUNTO DE PRODUCIONES PARA LA ZONA DE ACTUADORES */
zona_actuadores: inicio_zona_actuadores lista_actuadores {cout << "ZONA ACTUADORES" <<endl;}
				|;
inicio_zona_actuadores: ACTUADORES '\n' {cout << "inicio actuadores" << endl;}

lista_actuadores : 	lista_actuadores actuador {cout << "varias lineas de actudores" << endl;}
				| actuador {cout << "un solo actuador" << endl;}

actuador: ID '\n' {cout << "acutador " << $1 << endl;}				


/* CONJUNTO DE PRODUCIONES PARA LA ZONA DE SENSORES */
zona_sensores: inico_zona_sensores lista_sensores {cout<< "ZONA SENSORES" << endl;}
	;

inico_zona_sensores: SENSORES '\n' {cout << "inicio zona sensores" << n_lines<< endl;}
	;


lista_sensores: lista_sensores linea_sensores {cout << "varias lineas de sensores" << endl;}
			|linea_sensores {cout << "una solo linea de sensores" << endl;}	
			|;
linea_sensores: sensores '\n' {cout << "completa linea sensores"<< endl;}		

sensores:  tipo ID  {cout << "sensor" << endl;}
		| sensores ',' ID  {cout << "linea de sensores" << endl;}	
		| error '\n' {yyerrok;}
		;

tipo: INT {cout << "tipo int" << endl;}
	| FLOAT {cout << "tipo float" << endl;}
	| BOOL  {cout << "tipo bool" << endl;}
	;				

/* CONJUNTO DE PRODUCIONES PARA LA ZONA DE VARIABLES */
zona_variables:  inicio_zona_variables lista_variables {cout << "ZONA VARIABLES"<< endl;}		
	;
inicio_zona_variables: VARIABLES '\n' {cout << "inicio zona variables"<< endl;}
	;

lista_variables:  lista_variables variable {cout << "lista variable"<< endl;}
		| variable {cout << "variable"<< endl;}	
		;

variable: 	ID '=' expr '\n' {cout << "asignacion expr"<< endl;}		
		| ID '=' expr_logic '\n' {cout << "asignacion expr_logic"<< endl;}
		| error '\n' {yyerrok;}
		;


expr: 	NUMERO	{$$=$1; cout << "NUMERO"<< endl;}
	| REAL 	{$$=$1; cout << "REAL"<< endl;}
    | ID     {cout << "ID" << endl;}     	
	| '-' expr %prec MenosUnario {$$=-$2;}
	| expr '+' expr {$$=$1+$3;}
	| expr '-' expr {$$=$1-$3;}
	| expr '*' expr {$$=$1*$3;}
	| expr '/' expr {$$=$1/ $3;}
			
	| expr '^' expr {$$=pow($1, $3);}
	| '('expr')'   {$$=$2;}
	;

expr_logic: TRUE {$$=true;cout << "TRUE"<< endl;}
	| FALSE {$$=false;cout << "FALSE"<< endl;}
	| VERDADERO {$$=true;cout << "VERDADERO"<< endl;}
	| FALSO {$$=false;cout << "FALSO"<< endl;}
	| expr_logic EQUAL expr {$$=$1==$3; cout << "comparacion logica " << endl;}
	| expr_logic NOT_EQUAL expr {$$=$1!=$3; cout << "comparacion logica "  << endl;}
	| expr HT expr {$$=$1>$3;}
	| expr HET expr {$$=$1>=$3;}
	| expr LT expr {$$=$1<$3;}
	| expr LET expr {$$=$1<=$3;}
	| expr_logic AND expr_logic {$$=$1&&$3;}
	| expr_logic OR expr_logic {$$=$1||$3;}
	| '('expr_logic')'   {$$=$2;}
	;

%%

int main (int argc, char *argv[]) {
	n_lines=0;

	if(argc != 2) {
		cout << "El número de argumentos debe ser igual a 2 y es " << argc << "." << endl;
	} else {
		yyin = fopen(argv[1], "rt");
		//yyout = fopen(argv[2], "wt");
		yyparse();
		
		//fclose(yyout);
	}
	return 0;
}