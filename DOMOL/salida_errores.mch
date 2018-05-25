					TABLA DE SIMBOLOS
_________________________________________________________
========================================================|
Nombre			|	Tipo			|	Valor			|
========================================================|
temp_basica		|	entero			|	20				|	
temp_verano		|	real			|	22.00			|	
temp_invierno	|	real			|	18.18			|	
verano			|	lógico			|	falso			|	
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
encender_calef	|	transicion		|	0				|
apagar_calef	|	transicion		|	1				|
encender_airea	|	transicion		|	2				|
apagar_airea	|	transicion		|	3				|
acabar1			|	transicion		|	5				|
========================================================|

TABLA DE TRANSICIONES
=====================
               Inicial        Final          Todo_OFF       C_ON           AC_ON          
               ===========================================================================
Inicial       |                                                                                                                                                                                                                                                                                                            
Final         |                                                                                                                                                                                                                                                                                                            
Todo_OFF      |               acabar1                       encender_calef encender_airea                                                                                                                                                                                                                                  
C_ON          |                              apagar_calef                                                                                                                                                                                                                                                                  
AC_ON         |               acabar1        apagar_airea                                                                                                                                                                                                                                                                  

COMPROBACION DE LOS CASOS DE USO
================================
