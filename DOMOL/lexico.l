/**
 * PROYECTO FINAL DOMOL
 *
 * lexico.l
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
^[/][/]                           BEGIN(COM1);
<COM1>.                    		;
<COM1>\n                        BEGIN(0);n_lines++;
"//"                            BEGIN(COM2);
<COM2>.                    		;
<COM2>\n                        BEGIN(0);n_lines++;return('\n');



^[\n]											{n_lines++;}
^[\t ]*[\n]										{n_lines++;}
[V][A][R][I][A][B][L][E][S]						return VARIABLES;
[S][E][N][S][O][R][E][S]						return SENSORES;
[A][C][T][U][A][D][O][R][E][S]					return ACTUADORES;
[E][S][T][A][D][O][S]							return ESTADOS;
[T][R][A][N][S][I][C][I][O][N][E][S]			return TRANSICIONES;
[C][O][M][P][O][R][T][A][M][I][E][N][T][O]		return COMPORTAMIENTO;
[-][>]											return MOV;
[i][n][t]										return INT;
[f][l][o][a][t]									return FLOAT;
[b][o][o][l]									return BOOL;
[t][r][u][e]									return TRUE;
[f][a][l][s][e]									return FALSE;
[v][e][r][d][a][d][e][r][o]						return VERDADERO;
[f][a][l][s][o]									return FALSO;
[s][i]											return SI;
[e][n][t][o][n][c][e][s]						return ENTONCES;
[s][i][n][o]									return SINO;
[a][c][t][i][v][a][r]							return ACTIVAR;
[d][e][s][a][c][t][i][v][a][r]					return DESACTIVAR;
[t][r][a][n][s][i][c][i][o][n]					return TRANSICION;
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
[\t ]*											;
. 												return (yytext[0]); 

%%
