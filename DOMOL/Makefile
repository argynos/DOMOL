#fichero Makefile

OBJ = gramatica.o lexico.o 
ejecucion: gramatica
	#./gramatica ejemplo1.dml salida1.txt
	#./gramatica ejemplo_errores.dml salida_errores.txt
	./gramatica ejemplo_errores_calculadora.dml salida_errores_calc.txt
gramatica.h : gramatica
	make clean

gramatica : $(OBJ)     
	g++ -ogramatica $(OBJ)  SymbolTable.cpp TransitionsTable.cpp

gramatica.o : gramatica.c       
	g++ -c -ogramatica.o  gramatica.c 
	
lexico.o : lex.yy.c	
	g++ -c -olexico.o  lex.yy.c 

gramatica.c : gramatica.y      
	bison -d -ogramatica.c gramatica.y

lex.yy.c: lexico.l
	flex lexico.l

.PHONY : clean
clean : 
	rm  -f  *.c *.o 
