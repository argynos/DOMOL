					TABLA DE SIMBOLOS
_________________________________________________________
========================================================|
Nombre			|	Tipo			|	Valor			|
========================================================|
A				|	entero			|	1				|	
Bb				|	real			|	25.40			|	
Cc				|	lógico			|	falso			|	
_logico			|	lógico			|	falso			|	
X				|	entero			|	2				|	
aa				|	entero			|	2				|	
T1				|	sensor			|	real			|	
T2				|	entero			|	0				|	
Reloj			|	sensor			|	entero			|	
S				|	sensor			|	lógico			|	
Calefaccion		|	actuador		|					|
A_C				|	actuador		|					|
SYSTEM			|	actuador		|					|
Inicial			|	estado			|	0				|
Final			|	estado			|	1				|
Todo_OFF		|	estado			|	2				|
C_ON			|	estado			|	3				|
AC_ON			|	estado			|	4				|
iniciar			|	transicion		|	0				|
encender_calef	|	transicion		|	1				|
apagar_calef	|	transicion		|	2				|
encender_airea	|	transicion		|	3				|
apagar_airea	|	transicion		|	4				|
acabar1			|	transicion		|	5				|
acabar2			|	transicion		|	6				|
acabar3			|	transicion		|	7				|
========================================================|

TABLA DE TRANSICIONES
=====================
               Inicial        Final          Todo_OFF       C_ON           AC_ON          
               ===========================================================================
Inicial       |                              iniciar                                                                                                                                                                                                                                                                       
Final         |                                                                                                                                                                                                                                                                                                            
Todo_OFF      |               acabar1                       encender_calef encender_airea                                                                                                                                                                                                                                  
C_ON          |               acabar2        apagar_calef                                                                                                                                                                                                                                                                  
AC_ON         |               acabar3        apagar_airea                                                                                                                                                                                                                                                                  
