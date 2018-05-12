Tabla de Símbolos
===================
Nombre			Tipo		Valor
==============================================
temp_basica		entero		20
temp_verano		real		22.0
temp_invierno		real		18.18
verano			lógico		falso
T1			sensor real
T2			sensor real
Reloj			sensor entero
S			sensor lógico
Calefaccion		actuador
A_C			actuador
SYSTEM			actuador
Inicial			estado		0
Final			estado		1
Todo_OFF		estado		2
C_ON			estado		3
AC_ON			estado		4
iniciar			transición	0
encender_calef		transición	1
apagar_calef		transición	2
encender_aireac		transición	3
apagar_aireac		transición	4
acabar1			transición	5
acabar2			transición	6
acabar3			transición	7

Tabla de tansiciones
=====================
	Inicial		Final		Todo_OFF	C_ON		AC_ON
======================================================================================
Inicial					iniciar
Final
Todo_OFF		acabar1				encender_calef	encender_airea
C_ON			acabar2		apagar_calef
AC_ON			acabar3		apagar_airea
