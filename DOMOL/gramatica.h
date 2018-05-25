/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_GRAMATICA_H_INCLUDED
# define YY_YY_GRAMATICA_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    VARIABLES = 258,
    SENSORES = 259,
    ACTUADORES = 260,
    ESTADOS = 261,
    TRANSICIONES = 262,
    COMPORTAMIENTO = 263,
    MOV = 264,
    CASOS = 265,
    CASO = 266,
    HT = 267,
    HET = 268,
    LT = 269,
    LET = 270,
    AND = 271,
    OR = 272,
    NOT = 273,
    EQUAL = 274,
    NOT_EQUAL = 275,
    ID = 276,
    FLOAT = 277,
    INT = 278,
    BOOL = 279,
    SI = 280,
    SINO = 281,
    ACTIVAR = 282,
    DESACTIVAR = 283,
    TRANSICION = 284,
    ENTONCES = 285,
    NUMERO = 286,
    REAL = 287,
    TRUE = 288,
    FALSE = 289,
    VERDADERO = 290,
    FALSO = 291,
    MenosUnario = 292
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 185 "gramatica.y" /* yacc.c:1909  */

	int entero;
	float real;
	char id[20];
	bool booleano;

#line 99 "gramatica.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GRAMATICA_H_INCLUDED  */
