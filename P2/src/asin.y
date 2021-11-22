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
%type  <cent>  tipoSimple operadorUnario operadorMultiplicativo
			   operadorAditivo operadorRelacional operadorIgualdad  operadorLogico 
			   listaDeclaraciones declaracion declaracionFuncion

%type  <texp>  expresion expresionIgualdad expresionRelacional 
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

	// insTdR para cada elemento
	| STRUCT_ LLAVEIZQ_ listaCampos LLAVEDER_ ID_ PUNTOCOMA_ 
	{
		if(!insTdS($5, VARIABLE, T_RECORD, niv, dvar, $3.ref) yyerror("Identificador de struct ya utilizado");
		else dvar += $3.talla;
	}
	;

tipoSimple
	: INT_ { $$.t = T_ENTERO; }
	| BOOL_ { $$.t = T_LOGICO; }
	;

listaCampos
	: tipoSimple ID_ PUNTOCOMA_ {
								$$.ref = insTdR(-1, $2, $1, 0); 
								$$.talla = TALLA_TIPO_SIMPLE; 
								}
	| listaCampos tipoSimple ID_ PUNTOCOMA_ {
		if (insTdR($1.ref, $3, $2, $1.talla) < 0){yyerror("Variable con el mismo identificador ya declarada en struct")
		$$.talla = $1.talla + TALLA_TIPO_SIMPLE;
		};
		
	}
	;

declaracionFuncion
	: tipoSimple ID_ PARENTESISIZQ_ parametrosFormales PARENTESISDER_ bloque
	;

parametrosFormales
	:
	| listaParametrosFormales
	;

listaParametrosFormales
	: tipoSimple ID_ {insTdS(-1, $2, $1, 0);
					  $$.talla = TALLA_TIPO_SIMPLE;}
	| tipoSimple ID_ COMA_ listaParametrosFormales {
		if (insTdR($1.ref, $3, $2, $1.talla) < 0){yyerror("Variable con el mismo identificador ya declarada en struct")
		$$.talla = $1.talla + TALLA_TIPO_SIMPLE;
		};
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
	{
		SIMB sim = obtTdS($1);
		if($3.t != T_ERROR){   
			if (sim.t == T_ERROR) {
				yyerror("No existe ninguna variable con ese identificador.");
			} else if (! ((sim.t == $3.t && sim.t == T_ENTERO) || (sim.t == $3.t && sim.t == T_LOGICO))) {
				yyerror("Incompatibilidad de tipos, no son el mismo tipo o no son equivalentes.");
			}
		}
	}
	| ID_ CORCHETEIZQ_ expresion CORCHETEDER_ IGUAL_ expresion PUNTOCOMA_
	{
		SIMB sim = obtTdS($1); DIM dim;
		
		if (sim.t != T_ARRAY) {
			yyerror("La variable no es un vector, no se puede acceder mediante indices.");
		} else {
			dim = obtTdA(sim.ref);
		}
		
		if ($3.t != T_ERROR && $6.t != T_ERROR) {                    
			if (sim.t == T_ERROR) {
				yyerror("No existe ninguna variable con ese identificador.");
			} else if (! ($3.t == T_ENTERO)) {
				yyerror("El indice para acceder a un vector debe ser un entero 0 o positivo.");
			} else if (! ($6.t == dim.telem)) { 
				yyerror("Incompatibilidad de tipos, no son el mismo tipo o no son equivalentes."); 
			}                      
		}
	}
  	| ID_ PUNTO_ ID_ IGUAL_ expresion PUNTOCOMA_
	  {
		SIMB sim = obtTdS($1);
		SIMB sim2 = obtTdS($3);

		if (sim.t != T_RECORD) {yyerror("La variable no es una estructura.");}
		if($5.t != T_ERROR && sim2.t != T_ERROR){
			if (sim.t == T_ERROR) {
				yyerror("Objeto no declarado.");
			}else if(sim2.t != $5.t){
				yyerror("Tipos incompatibles.");
			}
		}
	  }
	;

instruccionEntradaSalida
	: READ_ PARENTESISIZQ_ ID_ PARENTESISDER_ PUNTOCOMA_
	{
		SIMB sim = obtTdS($3);
		if (sim.t != T_ENTERO) {
			yyerror("El argumento de la funcion read() debe ser de tipo entero.");
		}
	}
	| PRINT_ PARENTESISIZQ_ expresion PARENTESISDER_ PUNTOCOMA_
	{
		if ($3.t != T_ERROR && $3.t != T_ENTERO) {
			yyerror("El argumento de la funcion print() debe ser de tipo entero.");
		}
	}
	;

instruccionSeleccion
	: IF_ PARENTESISIZQ_ expresion PARENTESISDER_ instruccion ELSE_ instruccion
	{
		if ($3.t != T_ERROR)
			if ($3.t != T_LOGICO) yyerror("La expresion de evaluacion del \"if\" debe ser de tipo logico.");
	}
	;

instruccionIteracion
	: WHILE_ PARENTESISIZQ_ expresion PARENTESISDER_ instruccion
	{
		if ($3.t != T_ERROR)
			if ($3.t != T_LOGICO) yyerror("La expresion de evaluacion del \"while\" debe ser de tipo logico.");
	}
	;

expresion
	: expresionIgualdad	{ $$.t = $1.t; }
	| expresion operadorLogico expresionIgualdad
	{
		$$.t = T_ERROR;
		if ($1.t != T_ERROR || $3.t != T_ERROR) {
			if (!($1.t == $3.t && $1.t == T_LOGICO)) {
				yyerror("Incompatibilidad de tipos, no son el mismo tipo o no son equivalentes.");
			} else {
				$$.t = T_LOGICO;
			}
		}
	}
	;

expresionIgualdad
	: expresionRelacional	{ $$.t = $1.t; }
	| expresionIgualdad operadorIgualdad expresionRelacional
	{	
		$$.t = T_ERROR;
		
		if ($1.t != T_ERROR && $3.t != T_ERROR) {
			if ($1.t != $3.t) {
				yyerror("Incompatibilidad de tipos, no son el mismo tipo o no son equivalentes.");
			} else if ($3.t != T_LOGICO || $3.t != T_ENTERO) { 
				yyerror("Incompatibilidad de tipos, deben ser expresiones logicas o de enteros.");
			}  else {
				$$.t = T_LOGICO;
			}
		} 
	}
	;

expresionRelacional
	: expresionAditiva {$$.t = $1.t;}
	| expresionRelacional operadorRelacional expresionAditiva
		{
            $$.t = T_ERROR;
			if ($1.t != T_ERROR && $3.t != T_ERROR){
				if (!($1.t == $3.t && $1.t == T_ENTERO)) {
					yyerror("Incompatibilidad de tipos, no son el mismo tipo o no son equivalentes.");
				} else {
					$$.t = T_LOGICO;
				}
			}
		}
	;
	;

expresionAditiva
	: expresionMultiplicativa { $$.t = $1.t; }
	| expresionAditiva operadorAditivo expresionMultiplicativa
	{
        $$.t = T_ERROR;
		if ($1.t != T_ERROR && $3.t != T_ERROR) {
			if (!($1.t == $3.t && $1.t == T_ENTERO)) {
				yyerror("Incompatibilidad de tipos, no son el mismo tipo o no son equivalentes.");
			} else {
				$$.t = T_ENTERO;
			}
		}
	}
	;

expresionMultiplicativa
	: expresionUnaria {$$.t = $1.t;}
	| expresionMultiplicativa operadorMultiplicativo expresionUnaria
		{
            $$.t = T_ERROR;
			if ($1.t != T_ERROR && $3.t != T_ERROR) {
				if (!($1.t == $3.t && $1.t == T_ENTERO)) {
					yyerror("Incompatibilidad de tipos, no son el mismo tipo o no son equivalentes. ");
				} else {
					$$.t = T_ENTERO;
				} 
			}
		}
	;

expresionUnaria
	: expresionSufija	{$$.t = $1.t;}
	| operadorUnario expresionUnaria
	{  
        $$.t = T_ERROR;
        if ($2.t != T_ERROR) {
            if ($2.t == T_ENTERO) {                                                                         
                if ($1 == OP_NOT) {
					yyerror("Incompatibilidad de tipos, no se puede negar un entero.");
				} else { 
					$$.t = T_ENTERO; 
				}
            } else if ($2.t == T_LOGICO) {                                                                  
                if ($1 == OP_SUMA || $1 == OP_RESTA) {
					yyerror("Incompatibilidad de tipos, solo se puede aplicar el operador unario \"+\" o \"-\" a una expresion entera.");
				} else { 
					$$.t = T_LOGICO;
				}
            } else {
				yyerror("Incompatibilidad de tipos, no son el mismo tipo o no son equivalentes.");
			}                                                               
        } 
    }
	;

expresionSufija
  	: constante	{$$.t = $1.t;}
	| PARENTESISIZQ_ expresion PARENTESISDER_	{$$.t = $2.t;}
	| ID_
	{
			SIMB sim = obtTdS($1);
			$$.t = T_ERROR;

		 	if (sim.t == T_ERROR) {
				 yyerror("No existe ninguna variable con ese identificador.");
			 } else { 
				 $$.t = sim.t;
			 }
		}
  	| ID_ PUNTO_ ID_ {if (obtTdS($1)==T_ERROR) yyerror("Variable %s no declarada", $1)
	   if (obtTdS($3) == T_ERROR) yyerror("Variable %s no declarada", $3);}
	   
	| ID_ CORCHETEIZQ_ expresion CORCHETEDER_
	{
		SIMB sim = obtTdS($1);
		
		$$.t = T_ERROR;
	
		if (sim.t == T_ERROR) {
			yyerror("No existe ninguna variable con ese identificador.");
		} else if ($3.t != T_ENTERO) {
			yyerror("El indice para acceder a un vector debe ser un entero 0 o positivo.");
		} else { 
			DIM dim = obtTdA(sim.ref);
			$$.t = dim.telem;
		}
	}
	| ID_ PARENTESISIZQ_ parametrosActuales PARENTESISDER_
	{
			SIMB sim = obtTdS($1);

			$$.t = T_ERROR;
			
			if (sim.t == T_ERROR) { 
				yyerror("No existe ninguna variable con ese identificador."); 
			}
			INF inf = obtTdD(sim.ref);
			if (inf.t == T_ERROR) { 
				yyerror("No existe ninguna funcion con ese identificador."); 
			} else {
				$$.t = inf.t;
			}
		}
	;

constante
	: CTE_   {$$.t = T_ENTERO;}
	| TRUE_  {$$.t = T_LOGICO;}
	| FALSE_ {$$.t = T_LOGICO;}
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
	: OPAND_	{$$ = OPAND_;}
	| OPOR_		{$$ = OPOR_;}
	;

operadorIgualdad
	: OPIGUAL_		{$$ = OPIGUAL_;}
	| OPNOTIGUAL_	{$$ = OPNOTIGUAL_;}
	;

operadorRelacional
	: COMPMAYOR_	{$$ = COMPMAYOR_;}
	| COMPMENOR_	{$$ = COMPMENOR_;}
	| COMPMAYORIG_	{$$ = COMPMAYORIG_;}
	| COMPMENORIG_	{$$ = COMPMENORIG_;}
	;

operadorAditivo
	: OPSUMA_ {$$ = OPSUMA_}
	| OPRESTA_ {$$ = OPRESTA_}
	;

operadorMultiplicativo
	: OPMULT_ {$$ = OPMULT_}
	| OPDIV_  {$$ = OPDIV_}
	;

operadorUnario
	: OPSUMA_ {$$ = OPSUMA_;}
	| OPRESTA_ {SS = OPRESTA_;}
	| OPNOT_ {SS = NOT;}
	;
%%
