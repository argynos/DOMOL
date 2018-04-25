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

%}

%union {
	int entero;
	float real;
	char id[20];
	bool booleano;
}

%start programa
%token VARIABLES SENSORES ACTUADORES ESTADOS TRANSICIONES COMPORTAMIENTO
%token HT HET LT LET AND OR NOT EQUAL NOT_EQUAL
%token <id> ID
%token <entero> int NUMERO
%token <real> float REAL
%token <booleano> bool TRUE FALSE


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
	| zona1 zona2 zona3
	;

zona1: 	VARIABLES
		| VARIABLES lista_variables
	;

lista_variables: variable
				| lista_variables variable
				;

variable: 	ID '=' expr 		{$$=$3;}
			| ID '=' expr_logic	{$$=$3;}
			;

zona2:
	;

zona3:
	;

expr: 	NUMERO	{$$=$1;}
		| REAL 	{$$=$1;}
        | ID     {;}
        	
		| '-' expr %prec MenosUnario {$$=-$2;}
		| expr '+' expr {$$=$1+$3;}
		| expr '-' expr {$$=$1-$3;}
		| expr '*' expr {$$=$1*$3;}
		| expr '/' expr {$$=tipo_div(op, $1, $3);}
			
		| expr '^' expr {$$=pow($1, $3);}
		| '('expr')'   {$$=$2;}
		;

expr_logic: TRUE {$$=true;}
		| FALSE {$$=false;}
    	| expr EQUAL expr {$$=$1==$3;}
		| expr NOT_EQUAL expr {$$=$1!=$3;}
		| expr HT expr {$$=$1>$3;}
		| expr HET expr {$$=$1>=$3;}
		| expr LT expr {$$=$1<$3;}
		| expr LET expr {$$=$1<=$3;}
		;

%%

int (int argc, char *argv[]) {
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

