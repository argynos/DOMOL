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
#include "gramatica.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int n_lines;

%}

%option noyywrap

%x COM1 COM2
ID [a-zA-Z_][a-zA-Z0-9_]*
DIGITO [0-9]
ENTERO {DIGITO}+
REAL ({DIGITO}+[.]{DIGITO}*)|({DIGITO}*[.]{DIGITO}+)

%%
"//"                            BEGIN(COM1);
<COM1>.                    		;
<COM1>\n                        BEGIN(0);n_lines++;return('\n');


^[\n\t]+										{;}
[V][A][R][I][A][B][L][E][S]						return VARIABLES;
[S][E][N][S][O][R][E][S]						return SENSORES;
[A][C][T][U][A][D][O][R][E][S]					return ACTUADORES;
[E][S][T][A][D][O][S]							return ESTADOS;
[T][R][A][N][S][I][C][I][O][N][E][S]			return TRANSICIONES;
[C][O][M][P][O][R][T][A][M][I][E][N][T][O]		return COMPORTAMIENTO;
[i][n][t]										return int;
[f][l][o][a][t]									return float;
[b][o][o][l]									return bool;
[t][r][u][e]									return TRUE;
[f][a][l][s][e]									return FALSE;
"&&"											return AND;
"||"											return OR;
"!"												return NOT;
"<"												return LT;
"<="											return LET;
">"												return HT;
">="											return HET;
"=="											return EQUAL;
"!="											return NOT_EQUAL;
{ID}											strcpy(yylval.id, yytext); return ID; 	
{ENTERO}										yylval.entero = atoi(yytext);return NUMERO;
{REAL}											yylval.real = atof(yytext); return REAL;
\n												n_lines++; return (yytext[0]);
[\t ]*											n_lines++;	
. 												return (yytext[0]); 

%%