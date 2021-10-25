%{
#include <stdio.h>
#include "header.h"
#include "libtds.h"
#include <string.h>
%}

%union{
	int cent;
	char *ident;
	Lista lista;
	Expresion texp;
}

%token PUNTOCOMA_ ID_ CORCHETEIZQ_ CORCHETEDER_ CTE_ STRUCT_ LLAVEIZQ_ LLAVEDER_ IF_
%token INT_ BOOL_ 
%token PARENTESISIZQ_ PARENTESISDER_ COMA_ IGUAL_ ELSE_ READ_ PRINT_ WHILE_ RETURN_
%token PUNTO_ TRUE_ FALSE_ OPAND_ OPOR_ OPIGUAL_ OPNOTIGUAL_ COMPMAYOR_ COMPMENOR_ COMPMAYORIG_
%token COMPMENORIG_ OPSUMA_ OPRESTA_ OPMULT_ OPDIV_ OPNOT_

%%

programa
	: listaDeclaraciones
	;

listaDeclaraciones
	: declaracion
	| listaDeclaraciones declaracion
	;

declaracion
	: declaracionVariable
	| declaracionFuncion
	;

declaracionVariable
	: tipoSimple ID_ PUNTOCOMA_
	| tipoSimple ID_ CORCHETEIZQ_ CTE_ CORCHETEDER_ PUNTOCOMA_
	| STRUCT_ LLAVEIZQ_ listaCampos LLAVEDER_ ID_ PUNTOCOMA_
	;

tipoSimple
	: INT_
	| BOOL_
	;

listaCampos
	: tipoSimple ID_ PUNTOCOMA_
	| listaCampos tipoSimple ID_ PUNTOCOMA_
	;

declaracionFuncion
	: tipoSimple ID_ PARENTESISIZQ_ parametrosFormales PARENTESISDER_ bloque
	;

parametrosFormales
	:
	| listaParametrosFormales
	;

listaParametrosFormales
	: tipoSimple ID_
	| tipoSimple ID_ COMA_ listaParametrosFormales
	;

bloque
	: LLAVEIZQ_ declaracionVariableLocal listaInstrucciones RETURN_ expresion PUNTOCOMA_ LLAVEDER_
	;

declaracionVariableLocal
	:
	| declaracionVariableLocal declaracionVariable
	;

listaInstrucciones
	:
	| listaInstrucciones instruccion
	;

instruccion
	: LLAVEIZQ_ listaInstrucciones LLAVEDER_
	| instruccionAsignacion
	| instruccionSeleccion
	| instruccionEntradaSalida
	| instruccionIteracion
	;

instruccionAsignacion
	: ID_ IGUAL_ expresion PUNTOCOMA_
	| ID_ CORCHETEIZQ_ expresion CORCHETEDER_ IGUAL_ expresion PUNTOCOMA_
  	| ID_ PUNTO_ ID_ IGUAL_ expresion PUNTOCOMA_
	;

instruccionEntradaSalida
	: READ_ PARENTESISIZQ_ ID_ PARENTESISDER_ PUNTOCOMA_
	| PRINT_ PARENTESISIZQ_ expresion PARENTESISDER_ PUNTOCOMA_
	;

instruccionSeleccion
	: IF_ PARENTESISIZQ_ expresion PARENTESISDER_ instruccion ELSE_ instruccion
	;

instruccionIteracion
	: WHILE_ PARENTESISIZQ_ expresion PARENTESISDER_ instruccion
	;

expresion
	: expresionIgualdad
	| expresion operadorLogico expresionIgualdad
	;

expresionIgualdad
	: expresionRelacional
	| expresionIgualdad operadorIgualdad expresionRelacional
	;

expresionRelacional
	: expresionAditiva
	| expresionRelacional operadorRelacional expresionAditiva
	;

expresionAditiva
	: expresionMultiplicativa
	| expresionAditiva operadorAditivo expresionMultiplicativa
	;

expresionMultiplicativa
	: expresionUnaria
	| expresionMultiplicativa operadorMultiplicativo expresionUnaria
	;

expresionUnaria
	: expresionSufija
	| operadorUnario expresionUnaria
	;

expresionSufija
  	: constante
	| PARENTESISIZQ_ expresion PARENTESISDER_
	| ID_
  	| ID_ PUNTO_ ID_
	| ID_ CORCHETEIZQ_ expresion CORCHETEDER_
	| ID_ PARENTESISIZQ_ parametrosActuales PARENTESISDER_
	;

constante
	: CTE_
	| TRUE_
	| FALSE_
	;

parametrosActuales
	:
	| listaParametrosActuales
	;

listaParametrosActuales
	: expresion
	| expresion COMA_ listaParametrosActuales
	;

operadorLogico
	: OPAND_
	| OPOR_
	;

operadorIgualdad
	: OPIGUAL_
	| OPNOTIGUAL_
	;

operadorRelacional
	: COMPMAYOR_
	| COMPMENOR_
	| COMPMAYORIG_
	| COMPMENORIG_
	;

operadorAditivo
	: OPSUMA_
	| OPRESTA_
	;

operadorMultiplicativo
	: OPMULT_
	| OPDIV_
	;

operadorUnario
	: OPSUMA_
	| OPRESTA_
	| OPNOT_
	;
%%
