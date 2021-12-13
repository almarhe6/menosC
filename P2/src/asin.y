%{
#include <stdio.h>
#include "header.h"
#include "libtds.h"
#include <string.h>
%}

%union{
	int cent;
	char *ident;
	int referencia;
	int expr;
}


%token PUNTOCOMA_ CORCHETEIZQ_ CORCHETEDER_ STRUCT_ LLAVEIZQ_ LLAVEDER_ IF_
%token INT_ BOOL_ 
%token PARENTESISIZQ_ PARENTESISDER_ COMA_ IGUAL_ ELSE_ READ_ PRINT_ WHILE_ RETURN_
%token PUNTO_ TRUE_ FALSE_ OPAND_ OPOR_ OPIGUAL_ OPNOTIGUAL_ COMPMAYOR_ COMPMENOR_ COMPMAYORIG_
%token COMPMENORIG_ OPSUMA_ OPRESTA_ OPMULT_ OPDIV_ OPNOT_

%token <cent>  CTE_
%token <ident> ID_
%type  <referencia> listaParametrosFormales parametrosFormales listaCampos listaParametrosActuales parametrosActuales
%type  <cent>  tipoSimple operadorUnario operadorMultiplicativo 
			   operadorAditivo operadorRelacional operadorIgualdad  operadorLogico 
			   listaDeclaraciones declaracion declaracionFuncion bloque

%type  <expr>  expresion expresionIgualdad expresionRelacional 
			   expresionAditiva expresionMultiplicativa expresionUnaria expresionSufija 
               constante
               

%%

programa: { dvar=0; niv = 0; cargaContexto(niv); }
    listaDeclaraciones { if(verTdS) mostrarTdS(); if(obtTdS("main").t == T_ERROR) yyerror("El programa no tiene main"); }
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
            yyerror("Ya existe una variable con el mismo nombre");
        else
            dvar += TALLA_TIPO_SIMPLE; 
        if(verTdS) mostrarTdS();
	}
	| tipoSimple ID_ CORCHETEIZQ_ CTE_ CORCHETEDER_ PUNTOCOMA_
	{ 
	int numelem = $4;
        if (numelem <= 0) {
            yyerror("Talla inapropiada del array");
		numelem = 0;
        }
	if (!insTdS($2, VARIABLE, T_ARRAY, niv, dvar, insTdA($1, numelem)))
		yyerror("Identificador repetido");
	else
		dvar += numelem * TALLA_TIPO_SIMPLE; 
	if(verTdS) mostrarTdS();
	}

	// insTdR para cada elemento
	| STRUCT_ LLAVEIZQ_ listaCampos LLAVEDER_ ID_ PUNTOCOMA_ 
	{
		if(!insTdS($5, VARIABLE, T_RECORD, niv, dvar, $3)) {yyerror("Identificador de struct ya utilizado");}
		else dvar += TALLA_TIPO_SIMPLE;
		if(verTdS) mostrarTdS();
	}
	;

tipoSimple
	: INT_ { $$ = T_ENTERO; }
	| BOOL_ { $$ = T_LOGICO; }
	;

listaCampos
	: tipoSimple ID_ PUNTOCOMA_ {
					$$ = insTdR(-1, $2, $1, 0); 
					dvar += TALLA_TIPO_SIMPLE; 
	}
	| listaCampos tipoSimple ID_ PUNTOCOMA_ {
		if (insTdR($$, $3, $2, dvar) == -1) yyerror("Campo de struct ya declarado");
		else{
		insTdR($$,$3, $2, dvar);
		dvar += TALLA_TIPO_SIMPLE;
		}
	}
	;

declaracionFuncion
<<<<<<< HEAD
	: tipoSimple ID_ {
=======
	: tipoSimple ID_ {if (!insTdS($2, FUNCION, $1, niv, dvar, -1)) { yyerror("Identificador de funcion repetido");}
>>>>>>> 75717d664c6cd879fa944988b798a50776a6fd2f
	niv = 1; cargaContexto(niv);
	}
	
	PARENTESISIZQ_ parametrosFormales PARENTESISDER_ 

	{if(!insTdS($2,FUNCION,$1,niv-1,dvar,$5)) yyerror("Ya hay una función con ese nombre");
	}
	
	bloque
	
	{
	if(verTdS) mostrarTdS();
	descargaContexto(niv);
	niv = 0;
	}
	;

parametrosFormales
	: listaParametrosFormales{$$= $1;}
	| {$$ = insTdD(-1, T_VACIO);}
	;

listaParametrosFormales
	: tipoSimple ID_ {
		$$ = insTdD(-1,$1);

		if (!insTdS($2, PARAMETRO, $1, niv, dvar, -1))
			yyerror("Identificador de parametro repetido");
		else dvar += TALLA_TIPO_SIMPLE;
		if(verTdS) mostrarTdS();
	}
	| tipoSimple ID_ COMA_ listaParametrosFormales 
	{
		$$ = insTdD($4,$1);
		if (!insTdS($2, PARAMETRO, $1, niv, dvar, -1))
			yyerror("Identificador de parametro repetido");
		else dvar += TALLA_TIPO_SIMPLE;
		if(verTdS) mostrarTdS();
	}
	;

bloque
	: LLAVEIZQ_ declaracionVariableLocal listaInstrucciones RETURN_ expresion PUNTOCOMA_ LLAVEDER_ 
	{if(obtTdD(-1).tipo == T_ERROR){yyerror("Return fuera de función");}
	else if(obtTdD(-1).tipo != $5) yyerror("Error de tipo en return");}
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
		if($3 != T_ERROR){   
			if (sim.t == T_ERROR) {
				yyerror("Objeto no declarado");
			} else if (! ((sim.t == $3 && sim.t == T_ENTERO) || (sim.t == $3 && sim.t == T_LOGICO))) {
				yyerror("Error de tipos en la instruccion de asignacion");
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
		
		if ($3 != T_ERROR && $6 != T_ERROR) {                    
			if (sim.t == T_ERROR) {
				yyerror("No existe ninguna variable con ese identificador.");
			} else if (! ($3 == T_ENTERO)) {
				yyerror("El indice para acceder a un vector debe ser un entero 0 o positivo.");
			} else if (! ($6 == dim.telem)) { 
				yyerror("Incompatibilidad de tipos, no son el mismo tipo o no son equivalentes."); 
			}                      
		}
	}
  	| ID_ PUNTO_ ID_ IGUAL_ expresion PUNTOCOMA_
	  {
		SIMB sim = obtTdS($1);
		SIMB sim2 = obtTdS($3);

		if (sim.t != T_RECORD) {yyerror("El identificador debe ser struct");}
		if($5 != T_ERROR && sim2.t != T_ERROR){
			if (sim.t == T_ERROR) {
				yyerror("Objeto no declarado.");
			}else if(sim2.t != $5){
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
		if ($3 != T_ERROR && $3 != T_ENTERO) {
			yyerror("El argumento de la funcion print() debe ser de tipo entero.");
		}
	}
	;

instruccionSeleccion
	: IF_ PARENTESISIZQ_ expresion PARENTESISDER_	{
		if ($3 != T_ERROR)
			if ($3 != T_LOGICO) yyerror("La expresion de evaluacion del \"if\" debe ser de tipo logico.");
	}
	 instruccion ELSE_ instruccion
	;

instruccionIteracion
	: WHILE_ PARENTESISIZQ_ expresion PARENTESISDER_ 	{
		if ($3 != T_ERROR)
			if ($3 != T_LOGICO) yyerror("La expresion de evaluacion del \"while\" debe ser logica");
	}instruccion
	;

expresion
	: expresionIgualdad	{ $$ = $1; }
	| expresion operadorLogico expresionIgualdad
	{
		$$ = T_ERROR;
		if ($1 != T_ERROR || $3 != T_ERROR) {
			if ($1 != $3 && $1 != T_VACIO && $3 != T_VACIO) {
				printf("$1 = %d  $3 = %d",$1,$3);
				yyerror("Incompatibilidad de tipos en expresion logica");
			} else {
				$$ = T_LOGICO;
			}
		}
	}
	;

expresionIgualdad
	: expresionRelacional	{ $$ = $1; }
	| expresionIgualdad operadorIgualdad expresionRelacional
	{	
		$$ = T_ERROR;
		
		if ($1 != T_ERROR && $3 != T_ERROR) {
			if ($1 != $3) {
				yyerror("Incompatibilidad de tipos en expresion igualdad");
			} else if ($3 != T_LOGICO || $3 != T_ENTERO) { 
				yyerror("Incompatibilidad de tipos, deben ser expresiones logicas o de enteros.");
			}  else {
				$$ = T_LOGICO;
			}
		} 
	}
	;

expresionRelacional
	: expresionAditiva {$$ = $1;}
	| expresionRelacional operadorRelacional expresionAditiva
		{
            $$ = T_ERROR;
			if ($1 != T_ERROR && $3 != T_ERROR){
				if (!($1 == $3 && $1 == T_ENTERO)) {
					yyerror("Error de tipos en expresion relacional");
				} else {
					$$ = T_LOGICO;
				}
			}
		}
	;
	;

expresionAditiva
	: expresionMultiplicativa { $$ = $1; }
	| expresionAditiva operadorAditivo expresionMultiplicativa
	{
        $$ = T_ERROR;
		if ($1 != T_ERROR && $3 != T_ERROR) {
			if (!($1 == $3 && $1 == T_ENTERO)) {
				yyerror("Error de tipos en expresion aditiva");
			} else {
				$$ = T_ENTERO;
			}
		}
	}
	;

expresionMultiplicativa
	: expresionUnaria {$$ = $1;}
	| expresionMultiplicativa operadorMultiplicativo expresionUnaria
		{
            $$ = T_ERROR;
			if ($1 != T_ERROR && $3 != T_ERROR) {
				if (!($1 == $3 && $1 == T_ENTERO)) {
					yyerror("Incompatibilidad de tipos en expresion multiplicativa");
				} else {
					$$ = T_ENTERO;
				} 
			}
		}
	;

expresionUnaria
	: expresionSufija	{$$ = $1;}
	| operadorUnario expresionUnaria
	{  
        $$ = T_ERROR;
        if ($2 != T_ERROR) {
            if ($2 == T_ENTERO) {                                                                         
                if ($1 == OPNOT) {
					yyerror("Incompatibilidad de tipos, se está negando un entero");
			 	} else { 
					$$ = T_ENTERO; 
				}
            } else if ($2 == T_LOGICO) {                                                                  
                if ($1 == OPSUMA || $1 == OPRESTA) {
					yyerror("Incompatibilidad de tipos, solo se puede aplicar el operador unario \"+\" o \"-\" a una expresion entera.");
				} else { 
					$$ = T_LOGICO;
				}
            } else {
				yyerror("Incompatibilidad de tipos, no son el mismo tipo o no son equivalentes.");
			}                                                               
        } 
    }
	;

expresionSufija
  	: constante	{$$ = $1;}
	| PARENTESISIZQ_ expresion PARENTESISDER_	{$$ = $2;}
	| ID_
	{
			SIMB sim = obtTdS($1);
			$$ = T_ERROR;

		 	if (sim.t == T_ERROR) {
				 yyerror("No existe ninguna variable con ese identificador.");
			 } else { 
				 $$ = sim.t;
			 }
		}
  	| ID_ PUNTO_ ID_ {

  		if (obtTdS($1).t != T_RECORD){ yyerror("Identificador debe ser struct");}
  		
	   	if (obtTdS($3).t == T_ERROR && obtTdS($1).t == T_RECORD) {
	   		yyerror("Campo no declarado");
			$$ = T_VACIO;
			}
	   	}
	   
	| ID_ CORCHETEIZQ_ expresion CORCHETEDER_
	{
		SIMB sim = obtTdS($1);
		
		$$ = T_ERROR;
	
		if (sim.t == T_ERROR) {
			yyerror("No existe ninguna variable con ese identificador.");
		} else if ($3 != T_ENTERO) {
			yyerror("El indice para acceder a un vector debe ser un entero 0 o positivo.");
		} else { 
			DIM dim = obtTdA(sim.ref);
			$$ = dim.telem;
		}
	}
<<<<<<< HEAD
	| ID_ PARENTESISIZQ_ parametrosActuales {SIMB sim = obtTdS($1); if (!cmpDom(sim.ref, $3)){yyerror("Error en el dominio de los parámetros actuales");}} PARENTESISDER_ 
=======
	| ID_ PARENTESISIZQ_ parametrosActuales {SIMB sim = obtTdS($1); if (!cmpDom(sim.ref, $3)){yyerror("Tipos de parametros incorrectos");}} PARENTESISDER_
>>>>>>> 75717d664c6cd879fa944988b798a50776a6fd2f
	{
			
			SIMB sim = obtTdS($1);

			$$ = T_ERROR;
			
			if (sim.t == T_ERROR) { 
				yyerror("No existe ninguna variable con ese identificador."); 
			}
			INF inf = obtTdD(sim.ref);
			
<<<<<<< HEAD
			if (inf.tipo == T_ERROR) { 
				yyerror("No existe ninguna funcion con ese identificador."); 
=======
			if (inf.tipo != FUNCION) { 
				
				yyerror("No existe ninguna funcion con ese identificador."); 
			}

			 
			
			else {
				
				$$ = inf.tipo;
				
>>>>>>> 75717d664c6cd879fa944988b798a50776a6fd2f
			}
			else {$$ = inf.tipo;}
		}
	;

constante
	: CTE_   {$$ = T_ENTERO;}
	| TRUE_  {$$ = T_LOGICO;}
	| FALSE_ {$$ = T_LOGICO;}
	;

parametrosActuales
	: {$$ = insTdD(-1, T_VACIO);} 
	| listaParametrosActuales{ $$ = $1;} 
	;

listaParametrosActuales
	: expresion {$$ = insTdD(-1, $1);} 
	| expresion COMA_ listaParametrosActuales{ $$ = insTdD($3, $1);} 
	;

operadorLogico
	: OPAND_	{$$ = OPAND;}
	| OPOR_		{$$ = OPOR;}
	;

operadorIgualdad
	: OPIGUAL_		{$$ = OPIGUAL;}
	| OPNOTIGUAL_	{$$ = OPNOTIGUAL;}
	;

operadorRelacional
	: COMPMAYOR_	{$$ = COMPMAYOR;}
	| COMPMENOR_	{$$ = COMPMENOR;}
	| COMPMAYORIG_	{$$ = COMPMAYORIG;}
	| COMPMENORIG_	{$$ = COMPMENORIG;}
	;

operadorAditivo
	: OPSUMA_ {$$ = OPSUMA;}
	| OPRESTA_ {$$ = OPRESTA;}
	;

operadorMultiplicativo
	: OPMULT_ {$$ = OPMULT;}
	| OPDIV_  {$$ = OPDIV;}
	;

operadorUnario
	: OPSUMA_ {$$ = OPSUMA;}
	| OPRESTA_ {$$ = OPRESTA;}
	| OPNOT_ {$$ = OPNOT;}
	;
%%
