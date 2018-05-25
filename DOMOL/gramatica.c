/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 15 "gramatica.y" /* yacc.c:339  */

	#include <iostream>
	#include <stdio.h>
	#include <string.h>
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


#line 235 "gramatica.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


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
#line 185 "gramatica.y" /* yacc.c:355  */

	int entero;
	float real;
	char id[20];
	bool booleano;

#line 317 "gramatica.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 332 "gramatica.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   270

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  99
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  194

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   292

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      44,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    41,     2,     2,
      51,    52,    39,    37,    50,    38,     2,    40,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    45,    46,
       2,    49,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    48,     2,    47,    42,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    43
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   215,   215,   216,   226,   228,   230,   231,   233,   234,
     236,   246,   263,   266,   269,   270,   273,   275,   276,   278,
     279,   280,   281,   282,   283,   284,   287,   288,   290,   291,
     293,   294,   296,   303,   312,   314,   334,   337,   341,   342,
     345,   394,   398,   400,   403,   404,   407,   421,   425,   427,
     430,   431,   434,   444,   449,   452,   456,   457,   459,   460,
     463,   472,   483,   484,   485,   489,   491,   494,   495,   498,
     499,   500,   504,   505,   506,   525,   526,   527,   528,   529,
     530,   531,   532,   535,   536,   538,   539,   541,   542,   544,
     545,   547,   548,   550,   551,   552,   553,   554,   555,   556
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VARIABLES", "SENSORES", "ACTUADORES",
  "ESTADOS", "TRANSICIONES", "COMPORTAMIENTO", "MOV", "CASOS", "CASO",
  "HT", "HET", "LT", "LET", "AND", "OR", "NOT", "EQUAL", "NOT_EQUAL", "ID",
  "FLOAT", "INT", "BOOL", "SI", "SINO", "ACTIVAR", "DESACTIVAR",
  "TRANSICION", "ENTONCES", "NUMERO", "REAL", "TRUE", "FALSE", "VERDADERO",
  "FALSO", "'+'", "'-'", "'*'", "'/'", "'%'", "'^'", "MenosUnario",
  "'\\n'", "':'", "';'", "']'", "'['", "'='", "','", "'('", "')'",
  "$accept", "programa", "zona_casos", "inicio_zona_casos", "lista_casos",
  "caso_uso", "l_estados", "zona_comportamiento",
  "inicio_zona_comportamiento", "lista_comportamientos",
  "comportamiento_estado", "inicio_comportamiento", "instruccion_basica",
  "lista_alternativas", "alternativa", "alternativa_sino",
  "instrucion_actuador", "instruccion_variable", "instruccion_transicion",
  "zona_transiciones", "inicio_zona_transiciones", "lista_transiciones",
  "transicion", "zona_estados", "inicio_zona_estados", "lista_estados",
  "estado", "zona_actuadores", "inicio_zona_actuadores",
  "lista_actuadores", "actuador", "zona_sensores", "inico_zona_sensores",
  "lista_sensores", "linea_sensores", "sensores", "tipo", "zona_variables",
  "inicio_zona_variables", "lista_variables", "variable", "expr",
  "expr_logic", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,    43,    45,    42,
      47,    37,    94,   292,    10,    58,    59,    93,    91,    61,
      44,    40,    41
};
# endif

#define YYPACT_NINF -160

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-160)))

#define YYTABLE_NINF -66

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      15,   -17,    35,    66,    72,  -160,  -160,    27,    87,     2,
      54,    50,    12,  -160,  -160,    58,    99,   115,    82,  -160,
    -160,  -160,   181,  -160,    22,   106,  -160,   133,  -160,  -160,
      91,   132,   140,    96,   123,   100,  -160,  -160,  -160,  -160,
     141,  -160,  -160,  -160,  -160,  -160,  -160,    56,   133,   105,
      -5,  -160,   155,   177,   189,   157,   158,   127,  -160,  -160,
    -160,  -160,  -160,    56,  -160,    71,   -15,    56,    56,    56,
      56,   133,   133,    56,    56,    56,    56,    56,    56,  -160,
     133,   133,   133,   133,  -160,  -160,   168,   196,   190,   170,
     173,   162,  -160,  -160,  -160,  -160,   156,  -160,  -160,   191,
     191,   191,   191,   138,  -160,   138,  -160,   195,   195,   183,
     183,   183,   183,   118,    38,    38,   138,  -160,   138,  -160,
    -160,   194,  -160,    64,   197,   152,     7,  -160,   188,  -160,
     206,  -160,  -160,   198,   218,   103,  -160,  -160,   199,  -160,
     200,   133,   219,   223,   224,    68,   221,  -160,  -160,  -160,
    -160,   238,  -160,   203,  -160,  -160,    56,   -10,   207,   208,
     209,   210,  -160,  -160,  -160,  -160,   229,   234,   182,   212,
    -160,  -160,  -160,  -160,   213,  -160,   -12,  -160,   188,  -160,
    -160,   237,   145,  -160,   215,    53,   216,   214,  -160,  -160,
     188,   160,   217,  -160
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     0,     0,    66,     1,     0,     0,     0,
       0,     0,     0,    68,    55,     0,     0,     0,     0,    63,
      62,    64,     0,    57,     0,     0,    71,     0,    67,    49,
       0,     0,     0,     0,     0,     0,    51,    59,    56,    58,
       0,    60,    74,    72,    73,    83,    84,     0,     0,     0,
       0,    43,     0,     0,     0,     0,     0,     0,    45,    53,
      52,    50,    61,     0,    75,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    69,
       0,     0,     0,     0,    70,    37,     0,     0,     0,     0,
       0,     0,    38,    47,    46,    44,     0,    82,    99,    93,
      94,    95,    96,    85,    89,    86,    90,    76,    77,    78,
      79,    80,    81,     0,    97,    98,    87,    91,    88,    92,
      13,     0,     3,     0,     0,     0,     0,    14,     0,    41,
       0,    39,     5,     0,     0,     0,     6,    18,     0,    15,
       0,     0,     0,     0,     0,     0,    22,    26,    19,    20,
      21,     0,     9,     0,     7,    17,     0,     0,     0,     0,
       0,     0,    23,    24,    25,    27,     0,     0,     0,     0,
      32,    33,    35,    16,     0,    10,     0,    34,     0,    40,
       8,     0,     0,    11,     0,     0,     0,     0,    29,    31,
       0,     0,     0,    30
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -160,  -160,  -160,  -160,  -160,   128,  -160,  -160,  -160,  -160,
     139,  -160,  -159,  -160,   120,  -160,  -123,  -122,  -115,  -160,
    -160,  -160,   176,  -160,  -160,  -160,   211,  -160,  -160,  -160,
     235,  -160,  -160,  -160,   242,  -160,  -160,  -160,  -160,  -160,
     257,   -27,   -19
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,   122,   123,   135,   136,   176,    87,    88,   126,
     127,   128,   145,   146,   147,   188,   148,   149,   150,    53,
      54,    91,    92,    31,    32,    57,    58,    16,    17,    35,
      36,     8,     9,    22,    23,    24,    25,     3,     4,    12,
      13,   113,    50
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      49,    80,    81,    18,    82,    83,    80,    81,   124,    82,
      83,    80,    81,    10,    82,    83,   -65,   -12,     1,   182,
      64,    65,   162,   163,    19,    20,    21,     5,   125,    66,
     164,   191,   180,    11,   181,     6,    96,    98,   169,    84,
      99,   100,   101,   102,   103,   105,   107,   108,   109,   110,
     111,   112,   104,   106,   186,   116,   118,    82,    83,   162,
     163,   114,   115,   117,   119,   133,    39,   164,   162,   163,
       7,    14,    40,    10,   -28,   134,   164,    42,   -28,   187,
     -28,   -28,   -28,    67,    68,    69,    70,    43,    44,   140,
      71,    72,    15,    11,    47,   142,   143,   144,    26,    27,
     -28,    33,    29,    -4,   133,    30,   -48,    63,    73,    74,
      75,    76,    77,    78,   134,   161,    33,    67,    68,    69,
      70,    34,   157,    97,    71,    72,    37,    41,    55,   168,
      67,    68,    69,    70,   -42,    51,    34,    71,    72,    52,
      59,    55,    73,    74,    75,    76,    77,    78,    56,    79,
      67,    68,    69,    70,    42,    73,    74,    75,    76,    77,
      78,    56,    62,    89,    43,    44,   140,    60,    45,    46,
     -36,    47,   142,   143,   144,    73,    74,    75,    76,    77,
      78,   140,    18,    90,    48,    86,   -54,   142,   143,   144,
      89,   124,   184,    73,    74,    75,    76,    77,    78,    85,
     138,    93,    94,    19,    20,    21,   121,   192,    97,   140,
      90,   125,   120,   141,   129,   142,   143,   144,   130,    73,
      74,    75,    76,    77,    78,    78,   177,   151,    73,    74,
      75,    76,    77,    78,    75,    76,    77,    78,   132,   153,
     158,   137,   152,   155,   159,   160,   141,   166,   167,   156,
     174,   170,   171,   172,   173,   175,   178,   179,   183,   185,
     189,   193,   190,   154,    38,   139,   165,   131,    95,    28,
      61
};

static const yytype_uint8 yycheck[] =
{
      27,    16,    17,     1,    19,    20,    16,    17,     1,    19,
      20,    16,    17,     1,    19,    20,     4,    10,     3,   178,
      47,    48,   145,   145,    22,    23,    24,    44,    21,    48,
     145,   190,    44,    21,    46,     0,    63,    52,    48,    44,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    71,    72,     1,    82,    83,    19,    20,   182,
     182,    80,    81,    82,    83,     1,    44,   182,   191,   191,
       4,    44,    50,     1,    21,    11,   191,    21,    25,    26,
      27,    28,    29,    12,    13,    14,    15,    31,    32,    21,
      19,    20,     5,    21,    38,    27,    28,    29,    44,    49,
      47,     1,    44,     0,     1,     6,     6,    51,    37,    38,
      39,    40,    41,    42,    11,    47,     1,    12,    13,    14,
      15,    21,   141,    52,    19,    20,    44,    21,     1,   156,
      12,    13,    14,    15,     7,    44,    21,    19,    20,     7,
      44,     1,    37,    38,    39,    40,    41,    42,    21,    44,
      12,    13,    14,    15,    21,    37,    38,    39,    40,    41,
      42,    21,    21,     1,    31,    32,    21,    44,    35,    36,
       8,    38,    27,    28,    29,    37,    38,    39,    40,    41,
      42,    21,     1,    21,    51,     8,     5,    27,    28,    29,
       1,     1,    47,    37,    38,    39,    40,    41,    42,    44,
      48,    44,    44,    22,    23,    24,    10,    47,    52,    21,
      21,    21,    44,    25,    44,    27,    28,    29,    45,    37,
      38,    39,    40,    41,    42,    42,    44,    21,    37,    38,
      39,    40,    41,    42,    39,    40,    41,    42,    44,    21,
      21,    44,    44,    44,    21,    21,    25,     9,    45,    49,
      21,    44,    44,    44,    44,    21,    44,    44,    21,    44,
      44,    44,    48,   135,    22,   126,   146,    91,    57,    12,
      35
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    54,    90,    91,    44,     0,     4,    84,    85,
       1,    21,    92,    93,    44,     5,    80,    81,     1,    22,
      23,    24,    86,    87,    88,    89,    44,    49,    93,    44,
       6,    76,    77,     1,    21,    82,    83,    44,    87,    44,
      50,    21,    21,    31,    32,    35,    36,    38,    51,    94,
      95,    44,     7,    72,    73,     1,    21,    78,    79,    44,
      44,    83,    21,    51,    94,    94,    95,    12,    13,    14,
      15,    19,    20,    37,    38,    39,    40,    41,    42,    44,
      16,    17,    19,    20,    44,    44,     8,    60,    61,     1,
      21,    74,    75,    44,    44,    79,    94,    52,    52,    94,
      94,    94,    94,    94,    95,    94,    95,    94,    94,    94,
      94,    94,    94,    94,    95,    95,    94,    95,    94,    95,
      44,    10,    55,    56,     1,    21,    62,    63,    64,    44,
      45,    75,    44,     1,    11,    57,    58,    44,    48,    63,
      21,    25,    27,    28,    29,    65,    66,    67,    69,    70,
      71,    21,    44,    21,    58,    44,    49,    95,    21,    21,
      21,    47,    69,    70,    71,    67,     9,    45,    94,    48,
      44,    44,    44,    44,    21,    21,    59,    44,    44,    44,
      44,    46,    65,    21,    47,    44,     1,    26,    68,    44,
      48,    65,    47,    44
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    54,    55,    56,    57,    57,    58,    58,
      59,    59,    60,    61,    62,    62,    63,    64,    64,    65,
      65,    65,    65,    65,    65,    65,    66,    66,    67,    67,
      68,    68,    69,    69,    70,    71,    72,    73,    74,    74,
      75,    75,    76,    77,    78,    78,    79,    79,    80,    81,
      82,    82,    83,    83,    84,    85,    86,    86,    87,    87,
      88,    88,    89,    89,    89,    90,    91,    92,    92,    93,
      93,    93,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     7,     2,     2,     1,     2,     5,     2,
       1,     3,     2,     2,     1,     2,     4,     3,     2,     1,
       1,     1,     1,     2,     2,     2,     1,     2,     7,     8,
       5,     2,     3,     3,     4,     3,     2,     2,     1,     2,
       6,     2,     2,     2,     2,     1,     2,     2,     2,     2,
       2,     1,     2,     2,     2,     2,     2,     1,     2,     2,
       2,     3,     1,     1,     1,     2,     2,     2,     1,     4,
       4,     2,     1,     1,     1,     2,     3,     3,     3,     3,
       3,     3,     3,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 215 "gramatica.y" /* yacc.c:1646  */
    {;}
#line 1570 "gramatica.c" /* yacc.c:1646  */
    break;

  case 3:
#line 216 "gramatica.y" /* yacc.c:1646  */
    { if (!tt->conectividad(estados)){
																										semErr=true;
																			        					tipoErr=12;
																			        					errorSemantico();
																										}
																										}
#line 1581 "gramatica.c" /* yacc.c:1646  */
    break;

  case 8:
#line 233 "gramatica.y" /* yacc.c:1646  */
    { origen = new tipo_datoTT; strcpy(origen->nombre,(yyvsp[-3].id)); tt->insertarCaso(origen, destino, casos, 0); casos++; n_estados=1; }
#line 1587 "gramatica.c" /* yacc.c:1646  */
    break;

  case 9:
#line 234 "gramatica.y" /* yacc.c:1646  */
    {yyerrok;}
#line 1593 "gramatica.c" /* yacc.c:1646  */
    break;

  case 10:
#line 236 "gramatica.y" /* yacc.c:1646  */
    {if (!st->buscar((yyvsp[0].id), tsaux, pos) || tsaux->tipo!=4){
											semErr=true;
				        					tipoErr=14;
				        					strcpy(tserr->nombre,(yyvsp[0].id));
					                		errorSemantico();
										}else{
											destino = new tipo_datoTT; 
											strcpy(destino->nombre,(yyvsp[0].id));
										}
										}
#line 1608 "gramatica.c" /* yacc.c:1646  */
    break;

  case 11:
#line 246 "gramatica.y" /* yacc.c:1646  */
    {if (!st->buscar((yyvsp[0].id), tsaux, pos) || tsaux->tipo!=4){
											semErr=true;
				        					tipoErr=14;
				        					strcpy(tserr->nombre,(yyvsp[0].id));
					                		errorSemantico();
										}else{
											origen = new tipo_datoTT; 
											strcpy(origen->nombre,destino->nombre);
											destino = new tipo_datoTT; 
											strcpy(destino->nombre,(yyvsp[0].id));
											tt->insertarCaso(origen, destino, casos, n_estados); 
											n_estados++;
										}
										}
#line 1627 "gramatica.c" /* yacc.c:1646  */
    break;

  case 17:
#line 275 "gramatica.y" /* yacc.c:1646  */
    {strcpy(aux, (yyvsp[-2].id));}
#line 1633 "gramatica.c" /* yacc.c:1646  */
    break;

  case 18:
#line 276 "gramatica.y" /* yacc.c:1646  */
    {yyerrok;}
#line 1639 "gramatica.c" /* yacc.c:1646  */
    break;

  case 31:
#line 294 "gramatica.y" /* yacc.c:1646  */
    {yyerrok;}
#line 1645 "gramatica.c" /* yacc.c:1646  */
    break;

  case 32:
#line 296 "gramatica.y" /* yacc.c:1646  */
    {if (!st->buscar((yyvsp[-1].id), tsaux, pos) || tsaux->tipo!=3){
											semErr=true;
				        					tipoErr=8;
				        					strcpy(tserr->nombre,(yyvsp[-1].id));
					                		errorSemantico();
										}	
					}
#line 1657 "gramatica.c" /* yacc.c:1646  */
    break;

  case 33:
#line 303 "gramatica.y" /* yacc.c:1646  */
    {if (!st->buscar((yyvsp[-1].id), tsaux, pos) || tsaux->tipo!=3){
											semErr=true;
				        					tipoErr=8;
				        					strcpy(tserr->nombre,(yyvsp[-1].id));
					                		errorSemantico();
										}	
					}
#line 1669 "gramatica.c" /* yacc.c:1646  */
    break;

  case 35:
#line 314 "gramatica.y" /* yacc.c:1646  */
    {if (!st->buscar((yyvsp[-1].id), tsaux, pos) || tsaux->tipo!=5){
												semErr=true;
					        					tipoErr=1;
					        					if (tsaux->tipo!=5)
					        					tipoErr=9;
					        					strcpy(tserr->nombre,(yyvsp[-1].id));
						                		errorSemantico();
											}else{
												if (!tt->test5(aux, (yyvsp[-1].id), estados)){
													semErr=true;
						        					tipoErr=13;
						        					strcpy(tserr->nombre,(yyvsp[-1].id));
						                			errorSemantico();
												}
											}
									}
#line 1690 "gramatica.c" /* yacc.c:1646  */
    break;

  case 40:
#line 345 "gramatica.y" /* yacc.c:1646  */
    {
										if (st->buscar((yyvsp[-5].id), tsaux, pos)){
											semErr=true;
	                    					tipoErr=6;
	                    					strcpy(tserr->nombre,(yyvsp[-5].id));
	                    					errorSemantico();
										}
										bool uno=true;
										bool dos=true;
										int primero, segundo;
										if (!st->buscar((yyvsp[-3].id), tsaux, pos) || tsaux->tipo!=4){
												uno=false;
										}
										primero=tsaux->valor.valor_entero;
										if (!st->buscar((yyvsp[-1].id), tsaux, pos) || tsaux->tipo!=4){
												dos=false;
										}
										segundo=tsaux->valor.valor_entero;
										if(uno && dos){
											if(primero==1){
												semErr=true;
		                    					tipoErr=10;
		                    					strcpy(tserr->nombre,(yyvsp[-3].id));
		                    					errorSemantico();
											}else if(segundo==0){
												semErr=true;
		                    					tipoErr=10;
		                    					strcpy(tserr->nombre,(yyvsp[-1].id));
		                    					errorSemantico();
											}else{
												codigo=5; 
												construirTipoDato((yyvsp[-5].id), transiciones); 
												ttaux= new tipo_datoTT;
												strcpy(ttaux->nombre,(yyvsp[-5].id));
												tt->insertarTransicion(ttaux, primero, segundo);
												transiciones++;
											}
										}else if (!uno){
											semErr=true;
	                    					tipoErr=7;
	                    					strcpy(tserr->nombre,(yyvsp[-3].id));
	                    					errorSemantico();
										}else if (!dos){
											semErr=true;
	                    					tipoErr=7;
	                    					strcpy(tserr->nombre,(yyvsp[-1].id));
	                    					errorSemantico();
										}
									}
#line 1744 "gramatica.c" /* yacc.c:1646  */
    break;

  case 41:
#line 394 "gramatica.y" /* yacc.c:1646  */
    {yyerrok;}
#line 1750 "gramatica.c" /* yacc.c:1646  */
    break;

  case 46:
#line 407 "gramatica.y" /* yacc.c:1646  */
    {if (!st->buscar((yyvsp[-1].id), tsaux, pos)){
						codigo=4; 
						construirTipoDato((yyvsp[-1].id), estados);
						ttaux= new tipo_datoTT;
						strcpy(ttaux->nombre,(yyvsp[-1].id));
						tt->insertarEstado(ttaux, estados); 
						estados++;
					}else{
						semErr=true;
                        tipoErr=5;
                        strcpy(tserr->nombre,(yyvsp[-1].id));
                        errorSemantico();
					}		
					}
#line 1769 "gramatica.c" /* yacc.c:1646  */
    break;

  case 47:
#line 421 "gramatica.y" /* yacc.c:1646  */
    {yyerrok;}
#line 1775 "gramatica.c" /* yacc.c:1646  */
    break;

  case 52:
#line 434 "gramatica.y" /* yacc.c:1646  */
    {if (!st->buscar((yyvsp[-1].id), tsaux, pos)){
						codigo=3; 
						construirTipoDato((yyvsp[-1].id), 0);
					}else{
						semErr=true;
                        tipoErr=5;
                        strcpy(tserr->nombre,(yyvsp[-1].id));
                        errorSemantico();
					}
					}
#line 1790 "gramatica.c" /* yacc.c:1646  */
    break;

  case 53:
#line 444 "gramatica.y" /* yacc.c:1646  */
    {yyerrok;}
#line 1796 "gramatica.c" /* yacc.c:1646  */
    break;

  case 59:
#line 460 "gramatica.y" /* yacc.c:1646  */
    {yyerrok;}
#line 1802 "gramatica.c" /* yacc.c:1646  */
    break;

  case 60:
#line 463 "gramatica.y" /* yacc.c:1646  */
    {if (!st->buscar((yyvsp[0].id), tsaux, pos)){
							construirTipoDato((yyvsp[0].id), 0);
						}else{
							semErr=true;
	                        tipoErr=6;
	                        strcpy(tserr->nombre,(yyvsp[0].id));
	                        errorSemantico();
	                    }
					}
#line 1816 "gramatica.c" /* yacc.c:1646  */
    break;

  case 61:
#line 472 "gramatica.y" /* yacc.c:1646  */
    {if (!st->buscar((yyvsp[0].id), tsaux, pos)){
							construirTipoDato((yyvsp[0].id), 0);
						}else{
							semErr=true;
	                        tipoErr=6;
	                        strcpy(tserr->nombre,(yyvsp[0].id));
	                        errorSemantico();
	                    }
					}
#line 1830 "gramatica.c" /* yacc.c:1646  */
    break;

  case 62:
#line 483 "gramatica.y" /* yacc.c:1646  */
    {codigo=10;}
#line 1836 "gramatica.c" /* yacc.c:1646  */
    break;

  case 63:
#line 484 "gramatica.y" /* yacc.c:1646  */
    {codigo=11;}
#line 1842 "gramatica.c" /* yacc.c:1646  */
    break;

  case 64:
#line 485 "gramatica.y" /* yacc.c:1646  */
    {codigo=12;}
#line 1848 "gramatica.c" /* yacc.c:1646  */
    break;

  case 69:
#line 498 "gramatica.y" /* yacc.c:1646  */
    {construirTipoDato((yyvsp[-3].id), (yyvsp[-1].real));real=false;semErr=false;}
#line 1854 "gramatica.c" /* yacc.c:1646  */
    break;

  case 70:
#line 499 "gramatica.y" /* yacc.c:1646  */
    {construirTipoDato((yyvsp[-3].id), (yyvsp[-1].booleano));real=false;semErr=false;}
#line 1860 "gramatica.c" /* yacc.c:1646  */
    break;

  case 71:
#line 500 "gramatica.y" /* yacc.c:1646  */
    {yyerrok;}
#line 1866 "gramatica.c" /* yacc.c:1646  */
    break;

  case 72:
#line 504 "gramatica.y" /* yacc.c:1646  */
    {(yyval.real)=(yyvsp[0].entero); codigo=0;}
#line 1872 "gramatica.c" /* yacc.c:1646  */
    break;

  case 73:
#line 505 "gramatica.y" /* yacc.c:1646  */
    {(yyval.real)=(yyvsp[0].real); codigo=1;}
#line 1878 "gramatica.c" /* yacc.c:1646  */
    break;

  case 74:
#line 506 "gramatica.y" /* yacc.c:1646  */
    {if(!st->buscar((yyvsp[0].id), tsaux, pos)){
                        semErr=true;
                        tipoErr=1;
                        strcpy(tserr->nombre,(yyvsp[0].id));
                        errorSemantico();
            	} else if((codigo == 0 || codigo == 1) && tsaux->tipo == 2) {
                        semErr=true;
                        tipoErr=2;
                        errorSemantico();
                }
		else{ 
			if (tsaux->tipo==0){
			(yyval.real)=tsaux->valor.valor_entero;codigo=0;}
			else if (tsaux->tipo==1){
			(yyval.real)=tsaux->valor.valor_real;codigo=1;real=true;}
			else{
			(yyval.real)=tsaux->valor.valor_logico;codigo=2;}
	
		};}
#line 1902 "gramatica.c" /* yacc.c:1646  */
    break;

  case 75:
#line 525 "gramatica.y" /* yacc.c:1646  */
    {(yyval.real)=-(yyvsp[0].real);}
#line 1908 "gramatica.c" /* yacc.c:1646  */
    break;

  case 76:
#line 526 "gramatica.y" /* yacc.c:1646  */
    {(yyval.real)=(yyvsp[-2].real)+(yyvsp[0].real);}
#line 1914 "gramatica.c" /* yacc.c:1646  */
    break;

  case 77:
#line 527 "gramatica.y" /* yacc.c:1646  */
    {(yyval.real)=(yyvsp[-2].real)-(yyvsp[0].real);}
#line 1920 "gramatica.c" /* yacc.c:1646  */
    break;

  case 78:
#line 528 "gramatica.y" /* yacc.c:1646  */
    {(yyval.real)=(yyvsp[-2].real)*(yyvsp[0].real);}
#line 1926 "gramatica.c" /* yacc.c:1646  */
    break;

  case 79:
#line 529 "gramatica.y" /* yacc.c:1646  */
    {(yyval.real)=(yyvsp[-2].real)/ (yyvsp[0].real);}
#line 1932 "gramatica.c" /* yacc.c:1646  */
    break;

  case 80:
#line 530 "gramatica.y" /* yacc.c:1646  */
    {if(real) { semErr = true; tipoErr = 3;} else {(yyval.real)=(int)(yyvsp[-2].real)%(int)(yyvsp[0].real);}}
#line 1938 "gramatica.c" /* yacc.c:1646  */
    break;

  case 81:
#line 531 "gramatica.y" /* yacc.c:1646  */
    {(yyval.real)=pow((yyvsp[-2].real), (yyvsp[0].real));}
#line 1944 "gramatica.c" /* yacc.c:1646  */
    break;

  case 82:
#line 532 "gramatica.y" /* yacc.c:1646  */
    {(yyval.real)=(yyvsp[-1].real);}
#line 1950 "gramatica.c" /* yacc.c:1646  */
    break;

  case 83:
#line 535 "gramatica.y" /* yacc.c:1646  */
    {(yyval.booleano)=true; codigo=2;}
#line 1956 "gramatica.c" /* yacc.c:1646  */
    break;

  case 84:
#line 536 "gramatica.y" /* yacc.c:1646  */
    {(yyval.booleano)=false;codigo=2;}
#line 1962 "gramatica.c" /* yacc.c:1646  */
    break;

  case 85:
#line 538 "gramatica.y" /* yacc.c:1646  */
    {(yyval.booleano)=(yyvsp[-2].real)==(yyvsp[0].real);codigo=2;}
#line 1968 "gramatica.c" /* yacc.c:1646  */
    break;

  case 86:
#line 539 "gramatica.y" /* yacc.c:1646  */
    {(yyval.booleano)=(yyvsp[-2].real)!=(yyvsp[0].real);codigo=2;}
#line 1974 "gramatica.c" /* yacc.c:1646  */
    break;

  case 87:
#line 541 "gramatica.y" /* yacc.c:1646  */
    {(yyval.booleano)=(yyvsp[-2].booleano)==(yyvsp[0].real);codigo=2;}
#line 1980 "gramatica.c" /* yacc.c:1646  */
    break;

  case 88:
#line 542 "gramatica.y" /* yacc.c:1646  */
    {(yyval.booleano)=(yyvsp[-2].booleano)!=(yyvsp[0].real);codigo=2;}
#line 1986 "gramatica.c" /* yacc.c:1646  */
    break;

  case 89:
#line 544 "gramatica.y" /* yacc.c:1646  */
    {(yyval.booleano)=(yyvsp[-2].real)==(yyvsp[0].booleano);codigo=2;}
#line 1992 "gramatica.c" /* yacc.c:1646  */
    break;

  case 90:
#line 545 "gramatica.y" /* yacc.c:1646  */
    {(yyval.booleano)=(yyvsp[-2].real)!=(yyvsp[0].booleano);codigo=2;}
#line 1998 "gramatica.c" /* yacc.c:1646  */
    break;

  case 91:
#line 547 "gramatica.y" /* yacc.c:1646  */
    {(yyval.booleano)=(yyvsp[-2].booleano)==(yyvsp[0].booleano);codigo=2;}
#line 2004 "gramatica.c" /* yacc.c:1646  */
    break;

  case 92:
#line 548 "gramatica.y" /* yacc.c:1646  */
    {(yyval.booleano)=(yyvsp[-2].booleano)!=(yyvsp[0].booleano);codigo=2;}
#line 2010 "gramatica.c" /* yacc.c:1646  */
    break;

  case 93:
#line 550 "gramatica.y" /* yacc.c:1646  */
    {(yyval.booleano)=(yyvsp[-2].real)>(yyvsp[0].real);codigo=2;}
#line 2016 "gramatica.c" /* yacc.c:1646  */
    break;

  case 94:
#line 551 "gramatica.y" /* yacc.c:1646  */
    {(yyval.booleano)=(yyvsp[-2].real)>=(yyvsp[0].real);codigo=2;}
#line 2022 "gramatica.c" /* yacc.c:1646  */
    break;

  case 95:
#line 552 "gramatica.y" /* yacc.c:1646  */
    {(yyval.booleano)=(yyvsp[-2].real)<(yyvsp[0].real);codigo=2;}
#line 2028 "gramatica.c" /* yacc.c:1646  */
    break;

  case 96:
#line 553 "gramatica.y" /* yacc.c:1646  */
    {(yyval.booleano)=(yyvsp[-2].real)<=(yyvsp[0].real);codigo=2;}
#line 2034 "gramatica.c" /* yacc.c:1646  */
    break;

  case 97:
#line 554 "gramatica.y" /* yacc.c:1646  */
    {(yyval.booleano)=(yyvsp[-2].booleano)&&(yyvsp[0].booleano);codigo=2;}
#line 2040 "gramatica.c" /* yacc.c:1646  */
    break;

  case 98:
#line 555 "gramatica.y" /* yacc.c:1646  */
    {(yyval.booleano)=(yyvsp[-2].booleano)||(yyvsp[0].booleano);codigo=2;}
#line 2046 "gramatica.c" /* yacc.c:1646  */
    break;

  case 99:
#line 556 "gramatica.y" /* yacc.c:1646  */
    {(yyval.booleano)=(yyvsp[-1].booleano);codigo=2;}
#line 2052 "gramatica.c" /* yacc.c:1646  */
    break;


#line 2056 "gramatica.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 559 "gramatica.y" /* yacc.c:1906  */


int main(int argc, char *argv[]) {
	n_lines=0;

	if(argc != 3) {
		cout << "El número de argumentos debe ser igual a 3 y es " << argc << "." << endl;
	} else {
		yyin = fopen(argv[1], "rt");
		yyout = fopen(argv[2], "wt");
		yyparse();
		mostrar(); // Volcamos el contenido de la tabla de símbolos al fichero de salida.
		fclose(yyout);
	}
	return 0;
}
