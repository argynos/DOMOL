/**
 * PROYECTO FINAL DOMOL
 *
 * gramatica.y
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
%{
	#include <iostream>
	#include <stdio.h>
	#include <string.h>
	#include <string>
	#include <math.h>
	#include "SymbolTable.h"
	#include "TransitionsTable.h"

	using namespace std;

	extern int n_lines;
	extern int yylex();
	extern FILE *yyin;
	extern FILE *yyout;

	int codigo = 0;
	bool real=false;
	bool semErr = false;

    /*
    * 1 -> La variable no ha sido definida.
    * 2 -> No se pueden realizar operaciones aritméticas con tipo lógico    
    * 3 -> La operación '%' sólo puede ser realizadas con variables de tipo entero.
    * 4 -> No se puede cambiar el tipo de una variable ya definida.
    * 5- > Identificador ya usado
    */
	int tipoErr = 0;
                        
	SymbolTable *st = new SymbolTable();
	tipo_datoTS *tsaux = new tipo_datoTS;
	tipo_datoTS *tserr = new tipo_datoTS;
	tipo_cadena aux ="";
	
	TransitionsTable *tt = new TransitionsTable();
	tipo_datoTT *ttaux;
	tipo_datoTT *origen = new tipo_datoTT;
	tipo_datoTT *destino = new tipo_datoTT;

	int pos = 0;
	int estados=0;
	int transiciones=0;
	int casos=0;
	int n_estados=1;

    /**
    * Control de errores semánticos según el tipo.
    */
    void errorSemantico() {
    
    if(tipoErr==1) {
        printf("Error semántico en la línea %d. El identificador %s no ha sido definido.\n", n_lines+1, tserr->nombre);
    } 
	if(tipoErr==2) {
            printf("Error semántico en la línea %d. No se pueden realizar operaciones aritméticas con variables de tipo lógico.\n", n_lines+1);
        } 
	if(tipoErr==3) {
            printf("Error semántico en la línea %d. La operación %c sólo puede ser realizada con variables de tipo entero.\n", n_lines, 37);
        } 
	if(tipoErr==4) {
		if(real) 
            		printf("Error semántico en la línea %d. %s es de tipo entero y no se puede hacer una operacion real.\n", n_lines, tserr->nombre, tserr->tipo, codigo);
		else
			printf("Error semántico en la línea %d. %s es de tipo real y no se puede hacer una operacion entera.\n", n_lines, tserr->nombre, tserr->tipo, codigo);
    }
    if(tipoErr==5) {
    		printf("Error semántico en la línea %d. El identificador %s esta duplicado. \n", n_lines, tserr->nombre);
    }
    if(tipoErr==6) {
    		printf("Error semántico en la línea %d. El identificador %s esta duplicado. \n", n_lines+1, tserr->nombre);
	}
    if(tipoErr==7) {
    		printf("Error semántico en la línea %d. %s no es un estado. \n", n_lines, tserr->nombre);
    }
	if(tipoErr==8) {
        printf("Error semántico en la línea %d. El identificador %s no ha sido definido como un actuador.\n", n_lines, tserr->nombre);
    } 
    if(tipoErr==9) {
        printf("Error semántico en la línea %d. %s no es una transicion.\n", n_lines, tserr->nombre);
    }
    if(tipoErr==10) {
        printf("Error semántico en la línea %d. %s no es un estado de origen valido.\n", n_lines, tserr->nombre);
    }
 	if(tipoErr==11) {
        printf("Error semántico en la línea %d. %s no es un estado de destino valido.\n", n_lines, tserr->nombre);
    }
    if(tipoErr==12) {
        printf("Error semántico en global. Existen estados inacesibles.\n");
    }
    
    if(tipoErr==13) {
        printf("Error semántico en la línea %d. La transicion %s no tiene al estado %s como estado inicial.\n", n_lines, tserr->nombre, aux);
    }
    if(tipoErr==14) {
    		printf("Error semántico en la línea %d. %s no es un estado. \n", n_lines+1, tserr->nombre);
    }    
        tipoErr=0;
        semErr=false;
        real=false;

	}

    /**
    * Control de los errores del programa.
    */
	void yyerror(const char *s) {
        if(semErr)
            errorSemantico();
        else
            printf("Error sintáctico en la línea %d.\n", n_lines);
        codigo = 0;
        tipoErr=0;
        semErr=false;
        real=false;
	}

	
    /**
    * Vuelca el contenido de la tabla de símbolos al fichero de salida.
    */
	void mostrar() {
		fprintf(yyout, "\t\t\t\t\tTABLA DE SIMBOLOS\n_________________________________________________________\n");
    	fprintf(yyout, st->mostrar().c_str());
    	fprintf(yyout, "TABLA DE TRANSICIONES\n=====================\n");
    	fprintf(yyout, tt->mostrar(estados, casos).c_str());
	}
   
    /**
    * Construye el tipo de dato para insertar una entrada en la tabla de símbolos.    
    */   
    tipo_datoTS construirTipoDato(tipo_cadena var, double num) {
        tipo_datoTS *ts = new tipo_datoTS;
        strcpy(ts->nombre, var);
      	if (!semErr){
      	if((codigo%10) == 0) {
		    ts->tipo = 0;
		    ts->valor.valor_entero = (int) num;

		} else if((codigo%10) == 1) {
		    ts->tipo = 1;
		    ts->valor.valor_real = num;

		} else if((codigo%10) == 2) {
		    ts->tipo = 2;
		    ts->valor.valor_logico = (int) num;
		}else {
			ts->tipo = codigo;
			if (codigo == 4)
				ts->valor.valor_entero=estados;
			if (codigo == 5)
				ts->valor.valor_entero=transiciones;
		}
		if (codigo>=10)
      		ts->tipo +=10;
		if(!st->insertar(ts)){
			semErr=true;
            tipoErr=4;
			strcpy(tserr->nombre,var);
			errorSemantico();
		}
		ts=NULL;
	}else{
		errorSemantico();
	}
	codigo = 0;
    }

%}


%union{
	int entero;
	float real;
	char id[20];
	bool booleano;
}

%start programa
%token VARIABLES SENSORES ACTUADORES ESTADOS TRANSICIONES COMPORTAMIENTO MOV CASOS CASO
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
	| zona_variables zona_sensores zona_actuadores zona_estados zona_transiciones zona_comportamiento zona_casos { if (!tt->conectividad(estados)){
																										semErr=true;
																			        					tipoErr=12;
																			        					errorSemantico();
																										}
																										}
	;

/* CONJUNTO DE PRODUCIONES PARA LA ZONA DE CASOS DE USO */

zona_casos: inicio_zona_casos lista_casos
			;
inicio_zona_casos: CASOS '\n'
				;
lista_casos: caso_uso
			| lista_casos caso_uso
			;
caso_uso : CASO ID ':' l_estados '\n' { origen = new tipo_datoTT; strcpy(origen->nombre,$2); tt->insertarCaso(origen, destino, casos, 0); casos++; n_estados=1; }
			|error '\n' {yyerrok;}
			;
l_estados: ID {if (!st->buscar($1, tsaux, pos) || tsaux->tipo!=4){
											semErr=true;
				        					tipoErr=14;
				        					strcpy(tserr->nombre,$1);
					                		errorSemantico();
										}else{
											destino = new tipo_datoTT; 
											strcpy(destino->nombre,$1);
										}
										}
		| l_estados ';' ID  {if (!st->buscar($3, tsaux, pos) || tsaux->tipo!=4){
											semErr=true;
				        					tipoErr=14;
				        					strcpy(tserr->nombre,$3);
					                		errorSemantico();
										}else{
											origen = new tipo_datoTT; 
											strcpy(origen->nombre,destino->nombre);
											destino = new tipo_datoTT; 
											strcpy(destino->nombre,$3);
											tt->insertarCaso(origen, destino, casos, n_estados); 
											n_estados++;
										}
										}

/* CONJUNTO DE PRODUCIONES PARA LA ZONA DE COMPORTAMIENTO */

zona_comportamiento: inicio_zona_comportamiento lista_comportamientos 
					;

inicio_zona_comportamiento : COMPORTAMIENTO '\n' 
							;							

lista_comportamientos: comportamiento_estado 
					| lista_comportamientos comportamiento_estado 
					;

comportamiento_estado: inicio_comportamiento instruccion_basica ']' '\n' 
					;	
inicio_comportamiento: ID '[' '\n' {strcpy(aux, $1);}
					| error '\n' {yyerrok;}
					;
instruccion_basica: instrucion_actuador 
					| instruccion_variable
					| instruccion_transicion
					| lista_alternativas
					| instruccion_basica instrucion_actuador 
					| instruccion_basica instruccion_variable
					| instruccion_basica instruccion_transicion	
					;

lista_alternativas: alternativa 
					| lista_alternativas alternativa 
					;
alternativa: SI expr_logic '[' '\n' instruccion_basica ']' '\n'			
			|SI expr_logic '[' '\n' instruccion_basica ']' '\n' alternativa_sino	
			;
alternativa_sino: SINO '[' instruccion_basica ']' '\n'
				| error '\n' {yyerrok;}
				;
instrucion_actuador : ACTIVAR ID  '\n' {if (!st->buscar($2, tsaux, pos) || tsaux->tipo!=3){
											semErr=true;
				        					tipoErr=8;
				        					strcpy(tserr->nombre,$2);
					                		errorSemantico();
										}	
					}
					| DESACTIVAR ID '\n' {if (!st->buscar($2, tsaux, pos) || tsaux->tipo!=3){
											semErr=true;
				        					tipoErr=8;
				        					strcpy(tserr->nombre,$2);
					                		errorSemantico();
										}	
					}
					;

instruccion_variable : ID '=' expr '\n' 
					;
instruccion_transicion : TRANSICION ID '\n'{if (!st->buscar($2, tsaux, pos) || tsaux->tipo!=5){
												semErr=true;
					        					tipoErr=1;
					        					if (tsaux->tipo!=5)
					        					tipoErr=9;
					        					strcpy(tserr->nombre,$2);
						                		errorSemantico();
											}else{
												if (!tt->test5(aux, $2, estados)){
													semErr=true;
						        					tipoErr=13;
						        					strcpy(tserr->nombre,$2);
						                			errorSemantico();
												}
											}
									} 
					;


/* CONJUNTO DE PRODUCIONES PARA LA ZONA DE TRANSICIONES */
zona_transiciones: inicio_zona_transiciones lista_transiciones 
	;

inicio_zona_transiciones: TRANSICIONES '\n' 
	;


lista_transiciones: transicion 	
			|lista_transiciones transicion 
			;

transicion:  ID ':' ID MOV ID  '\n' {
										if (st->buscar($1, tsaux, pos)){
											semErr=true;
	                    					tipoErr=6;
	                    					strcpy(tserr->nombre,$1);
	                    					errorSemantico();
										}
										bool uno=true;
										bool dos=true;
										int primero, segundo;
										if (!st->buscar($3, tsaux, pos) || tsaux->tipo!=4){
												uno=false;
										}
										primero=tsaux->valor.valor_entero;
										if (!st->buscar($5, tsaux, pos) || tsaux->tipo!=4){
												dos=false;
										}
										segundo=tsaux->valor.valor_entero;
										if(uno && dos){
											if(primero==1){
												semErr=true;
		                    					tipoErr=10;
		                    					strcpy(tserr->nombre,$3);
		                    					errorSemantico();
											}else if(segundo==0){
												semErr=true;
		                    					tipoErr=10;
		                    					strcpy(tserr->nombre,$5);
		                    					errorSemantico();
											}else{
												codigo=5; 
												construirTipoDato($1, transiciones); 
												ttaux= new tipo_datoTT;
												strcpy(ttaux->nombre,$1);
												tt->insertarTransicion(ttaux, primero, segundo);
												transiciones++;
											}
										}else if (!uno){
											semErr=true;
	                    					tipoErr=7;
	                    					strcpy(tserr->nombre,$3);
	                    					errorSemantico();
										}else if (!dos){
											semErr=true;
	                    					tipoErr=7;
	                    					strcpy(tserr->nombre,$5);
	                    					errorSemantico();
										}
									}
		| error '\n' {yyerrok;}
		;

/* CONJUNTO DE PRODUCIONES PARA LA ZONA DE ESTADOS */
zona_estados: inicio_zona_estados lista_estados 
				;
inicio_zona_estados: ESTADOS '\n'
					; 

lista_estados: 	lista_estados estado 
				| estado 
			    ;

estado: ID '\n' {if (!st->buscar($1, tsaux, pos)){
						codigo=4; 
						construirTipoDato($1, estados);
						ttaux= new tipo_datoTT;
						strcpy(ttaux->nombre,$1);
						tt->insertarEstado(ttaux, estados); 
						estados++;
					}else{
						semErr=true;
                        tipoErr=5;
                        strcpy(tserr->nombre,$1);
                        errorSemantico();
					}		
					}
		| error '\n' {yyerrok;} 
		;

/* CONJUNTO DE PRODUCIONES PARA LA ZONA DE ACTUADORES */
zona_actuadores: inicio_zona_actuadores lista_actuadores
				;
inicio_zona_actuadores: ACTUADORES '\n' 
				;

lista_actuadores : 	lista_actuadores actuador 
				| actuador 
				;

actuador: ID '\n' {if (!st->buscar($1, tsaux, pos)){
						codigo=3; 
						construirTipoDato($1, 0);
					}else{
						semErr=true;
                        tipoErr=5;
                        strcpy(tserr->nombre,$1);
                        errorSemantico();
					}
					}
		| error '\n' {yyerrok;}
		;					


/* CONJUNTO DE PRODUCIONES PARA LA ZONA DE SENSORES */
zona_sensores: inico_zona_sensores lista_sensores 
	;

inico_zona_sensores: SENSORES '\n' 
	;


lista_sensores: lista_sensores linea_sensores 
			|linea_sensores 
			;
linea_sensores: sensores '\n'
			| error '\n' {yyerrok;}
			;		

sensores:  tipo ID {if (!st->buscar($2, tsaux, pos)){
							construirTipoDato($2, 0);
						}else{
							semErr=true;
	                        tipoErr=6;
	                        strcpy(tserr->nombre,$2);
	                        errorSemantico();
	                    }
					}
		| sensores ',' ID  {if (!st->buscar($3, tsaux, pos)){
							construirTipoDato($3, 0);
						}else{
							semErr=true;
	                        tipoErr=6;
	                        strcpy(tserr->nombre,$3);
	                        errorSemantico();
	                    }
					}
		;

tipo: INT {codigo=10;}
	| FLOAT {codigo=11;}
	| BOOL  {codigo=12;}
	;				

/* CONJUNTO DE PRODUCIONES PARA LA ZONA DE VARIABLES */
zona_variables:  inicio_zona_variables lista_variables 	
	;
inicio_zona_variables: VARIABLES '\n' 
	;

lista_variables:  lista_variables variable 
		| variable 
		;

variable: 	ID '=' expr '\n' {construirTipoDato($1, $3);real=false;semErr=false;}
		| ID '=' expr_logic '\n' {construirTipoDato($1, $3);real=false;semErr=false;} 
		| error '\n' {yyerrok;}
		;


expr: 	NUMERO	{$$=$1; codigo=0;}
	| REAL 	{$$=$1; codigo=1;}
    | ID     {if(!st->buscar($1, tsaux, pos)){
                        semErr=true;
                        tipoErr=1;
                        strcpy(tserr->nombre,$1);
                        errorSemantico();
            	} else if((codigo == 0 || codigo == 1) && tsaux->tipo == 2) {
                        semErr=true;
                        tipoErr=2;
                        errorSemantico();
                }
		else{ 
			if (tsaux->tipo==0){
			$$=tsaux->valor.valor_entero;codigo=0;}
			else if (tsaux->tipo==1){
			$$=tsaux->valor.valor_real;codigo=1;real=true;}
			else{
			$$=tsaux->valor.valor_logico;codigo=2;}
	
		};}
	| '-' expr %prec MenosUnario {$$=-$2;}
	| expr '+' expr {$$=$1+$3;}
	| expr '-' expr {$$=$1-$3;}
	| expr '*' expr {$$=$1*$3;}
	| expr '/' expr {$$=$1/ $3;}
	| expr '%' expr {if(real) { semErr = true; tipoErr = 3;} else {$$=(int)$1%(int)$3;}}	
	| expr '^' expr {$$=pow($1, $3);}
	| '('expr')'   {$$=$2;}
	;

expr_logic: VERDADERO {$$=true; codigo=2;}
	| FALSO {$$=false;codigo=2;}

	| expr EQUAL expr {$$=$1==$3;codigo=2;}
	| expr NOT_EQUAL expr {$$=$1!=$3;codigo=2;}

	| expr_logic EQUAL expr {$$=$1==$3;codigo=2;}
	| expr_logic NOT_EQUAL expr {$$=$1!=$3;codigo=2;}

	| expr EQUAL expr_logic {$$=$1==$3;codigo=2;}
	| expr NOT_EQUAL expr_logic {$$=$1!=$3;codigo=2;}
	
	| expr_logic EQUAL expr_logic {$$=$1==$3;codigo=2;}
	| expr_logic NOT_EQUAL expr_logic {$$=$1!=$3;codigo=2;}
	
	| expr HT expr {$$=$1>$3;codigo=2;}
	| expr HET expr {$$=$1>=$3;codigo=2;}
	| expr LT expr {$$=$1<$3;codigo=2;}
	| expr LET expr {$$=$1<=$3;codigo=2;}
	| expr_logic AND expr_logic {$$=$1&&$3;codigo=2;}
	| expr_logic OR expr_logic {$$=$1||$3;codigo=2;}
	| '('expr_logic')'   {$$=$2;codigo=2;}
	;

%%



int main(int argc, char *argv[]) {
	n_lines=0;

	if(argc != 2) {
		cout << "El número de argumentos debe ser igual a 2 y es " << argc << "." << endl;
	} else {
		string input_param = argv[1];
		string dot = ".";

		size_t found_input = input_param.find(dot); // Buscamos en la cadena de entrada el punto de la extensión.
		string token_input = input_param.substr(found_input+1, found_input); // guardamos en un string el nombre de la extensión
		string file_input_name = input_param.substr(0, found_input); // Y en otro, el nombre del fichero.

		if(token_input != "dml") {
			cout << "La extensión del archivo de entrada debe ser .dml y es: " << token_input << endl;
			return 0;
		} else {
			yyin = fopen(argv[1], "rt");
			string output_file = file_input_name + ".mch"; // creamos el nombre del fichero de salida.
			yyout = fopen(output_file.c_str(), "w"); // Abrimos el flujo
			yyparse();
			mostrar(); // Volcamos el contenido de la tabla de símbolos al fichero de salida.
			fclose(yyout);
		}
		
	}
	return 0;
}
