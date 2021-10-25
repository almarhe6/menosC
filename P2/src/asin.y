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

%token PUNTOCOMA_ CORCHETEIZQ_ CORCHETEDER_ STRUCT_ LLAVEIZQ_ LLAVEDER_ IF_
%token INT_ BOOL_ 
%token PARENTESISIZQ_ PARENTESISDER_ COMA_ IGUAL_ ELSE_ READ_ PRINT_ WHILE_ RETURN_
%token PUNTO_ TRUE_ FALSE_ OPAND_ OPOR_ OPIGUAL_ OPNOTIGUAL_ COMPMAYOR_ COMPMENOR_ COMPMAYORIG_
%token COMPMENORIG_ OPSUMA_ OPRESTA_ OPMULT_ OPDIV_ OPNOT_

%token <cent>  CTE_
%token <ident> ID_
%type  <lista> listaParametrosFormales parametrosFormales
%type  <cent>  tipoSimple operadorIncremento operadorUnario operadorMultiplicativo
			   operadorAditivo operadorRelacional operadorIgualdad  operadorLogico 
			   listaDeclaraciones declaracion declaracionFuncion cabeceraFuncion

%type  <texp>  expresionOpcional expresion expresionIgualdad expresionRelacional 
			   expresionAditiva expresionMultiplicativa expresionUnaria expresionSufija
               constante

%%

programa
	: { dvar=0; niv = 0; cargaContexto(niv); }
    listaDeclaraciones { if(verTdS) mostrarTdS(); }
    ;

listaDeclaraciones
    : declaracion { $$ = $1; }
    | listaDeclaraciones declaracion { $$ = $1 + $2; }
    ;

declaracion
    : declaracionVariable { $$ = 0; }
    | declaracionFuncion { $$ = $1; }
    ;

declaracionVariable
	: tipoSimple ID_ PUNTOCOMA_
	{ 
		if (!insTdS($2, VARIABLE, $1, niv, dvar, -1))
            yyerror("Ya existe una variable con el mismo identificador.");
        else
            dvar += TALLA_TIPO_SIMPLE; 
	}
	| tipoSimple ID_ CORCHETEIZQ_ CTE_ CORCHETEDER_ PUNTOCOMA_
	{ 
        if ($4 <= 0) {
            yyerror("El indice de inicialización de los vectores tiene que ser un entero positivo.");
        } else {
			int ref = insTdA($1, $4);
			if (!insTdS($2, VARIABLE, T_ARRAY, niv, dvar, ref))
				yyerror("Ya existe un vector con el mismo identificador.");
			else
				dvar += $4 * TALLA_TIPO_SIMPLE; 
		}
        
	}
	| STRUCT_ LLAVEIZQ_ listaCampos LLAVEDER_ ID_ PUNTOCOMA_
	;

tipoSimple
	: INT_ { $$ = T_ENTERO; }
	| BOOL_ { $$ = T_LOGICO; }
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
