%{
#include <stdio.h>
#include "header.h"
#include "libtds.h"
#include <string.h>
#include "libgci.h"
int dvaraux;
%}



%union{
	int cent;
	char *ident;
	CAMPOS referencia;
	int expr;
	ESTRUCT estructura;
	REFAUX refaux;
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

%type  <estructura>  expresion expresionIgualdad expresionRelacional 
		expresionAditiva expresionMultiplicativa expresionUnaria expresionSufija constante
               
               

%%

programa: 
	{ 
		si=0; dvar=0; niv = 0;  cargaContexto(niv); 
		$<refaux>$.r1 = creaLans(si);
		emite(INCTOP, crArgNul(), crArgNul(), crArgEnt($<refaux>$.r1)); //Variables globales
		$<refaux>$.r2 = creaLans(si);
        emite(GOTOS, crArgNul(), crArgNul(), crArgEtq($<refaux>$.r2)); //Empieza
	}

    listaDeclaraciones 
		{ 
			completaLans($<refaux>1.r1, crArgEnt(dvar));
			if(verTdS) mostrarTdS();
			if(obtTdS("main").t == T_ERROR) yyerror("El programa no tiene main"); 
			SIMB sim = obtTdS("main");

			completaLans($<refaux>1.r2, crArgEtq(sim.d));
		}
    ;

listaDeclaraciones
    : declaracion { $$ = $1; }
    | listaDeclaraciones declaracion { $$ = $1 + $2; }
    ;

declaracion
    : declaracionVariable {$$ = 0;} 
    | declaracionFuncion  { $$ = $1; }
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
		if(!insTdS($5, VARIABLE, T_RECORD, niv, dvar, $3.ref)) {yyerror("Identificador de struct ya utilizado");}
		else dvar += TALLA_TIPO_SIMPLE;
		if(verTdS) mostrarTdS();
	}
	;

tipoSimple
	: INT_ { $$ = T_ENTERO; }
	| BOOL_ { $$ = T_LOGICO; }
	;

listaCampos
	: tipoSimple ID_ PUNTOCOMA_ 
		{
			$$.ref = insTdR(-1, $2, $1, 0);
			dvar += TALLA_TIPO_SIMPLE; 
		}
	| listaCampos tipoSimple ID_ PUNTOCOMA_ {
		if (insTdR($$.ref, $3, $2, dvar) == -1) yyerror("Campo de struct ya declarado");
		else{
		insTdR($$.ref,$3, $2, dvar);
		dvar += TALLA_TIPO_SIMPLE;
		}
	}
	;

declaracionFuncion
	: tipoSimple ID_
		{
			niv = 1;
			cargaContexto(niv);
		}
	
	PARENTESISIZQ_ parametrosFormales PARENTESISDER_ 

		{
			if(!insTdS($2,FUNCION,$1,niv-1,si,$5.ref)) yyerror("Ya hay una función con ese nombre");
			$<cent>$ = dvar;
			dvaraux=dvar;
			dvar = 0;
		}
		
	bloque
		
		{
			if(verTdS) mostrarTdS();
			descargaContexto(niv);
			niv = 0;
			dvar = dvaraux;
		}
	;

parametrosFormales
	: listaParametrosFormales
		{
			$$= $1;
			$$.talla = $1.talla;
		}
	| 
		{
			$$.ref = insTdD(-1, T_VACIO);
			$$.talla = 0;
		}
	;

listaParametrosFormales
	: tipoSimple ID_
		{
			$$.ref = insTdD(-1,$1);
			
			if (!insTdS($2, PARAMETRO, $1, niv, -$$.talla, -1))
				yyerror("Identificador de parametro repetido");
			$$.talla += TALLA_SEGENLACES + TALLA_TIPO_SIMPLE;
			if(verTdS) mostrarTdS();
		}
	| tipoSimple ID_ COMA_ listaParametrosFormales 
	{
		$$.ref = insTdD($4.ref,$1);
		if (!insTdS($2, PARAMETRO, $1, niv, -$$.talla, -1))
			yyerror("Identificador de parametro repetido");
		$$.talla += $4.talla + TALLA_TIPO_SIMPLE;
		if(verTdS) mostrarTdS();
	}
	;

bloque
	: LLAVEIZQ_ 
		{
			emite(PUSHFP, crArgNul(), crArgNul(), crArgNul() );
			emite(FPTOP, crArgNul(), crArgNul(), crArgNul() );
			$<cent>$ = creaLans(si);
			//Variables locales               
			emite(INCTOP, crArgNul(), crArgNul(), crArgEnt(-1) ); 
      	}  
      	declaracionVariableLocal listaInstrucciones RETURN_ expresion PUNTOCOMA_ LLAVEDER_ 
		{
			INF inf = obtTdD(-1);
			if(inf.tipo == T_ERROR){
				yyerror("Return fuera de función");
			}
			else if(inf.tipo != $6.tipo){
				yyerror("Error de tipo en return");
			}
			
			completaLans($<cent>2, crArgEnt(dvar));
			
			int seg = TALLA_SEGENLACES + TALLA_TIPO_SIMPLE + inf.tsp;
			emite(EASIG, crArgPos(niv, $6.desp), crArgNul(), crArgPos(niv, -seg));
			emite(TOPFP, crArgNul(), crArgNul(), crArgNul() );
			emite(FPPOP, crArgNul(), crArgNul(), crArgNul() );
			//Si es main se acaba, si no retorna
			if (strcmp(inf.nom,"main") == 0) {
				emite(FIN, crArgNul(), crArgNul(), crArgNul()); 
			}
			else {
				emite(RET, crArgNul(), crArgNul(), crArgNul()); 
			}
		}
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
		if($3.tipo != T_ERROR){   
			if (sim.t == T_ERROR) {
				yyerror("Objeto no declarado");
			} else if (! ((sim.t == $3.tipo && sim.t == T_ENTERO) || (sim.t == $3.tipo && sim.t == T_LOGICO))) {
				yyerror("Error de tipos en la instruccion de asignacion");
			}
		}

		emite(EASIG, crArgPos(niv, $3.desp), crArgNul(), crArgPos(niv, sim.d));
	}
	| ID_ CORCHETEIZQ_ expresion CORCHETEDER_ IGUAL_ expresion PUNTOCOMA_
	{
		SIMB sim = obtTdS($1); DIM dim;
		
		if (sim.t != T_ARRAY) {
			yyerror("La variable no es un vector, no se puede acceder mediante indices.");
		} else {
			dim = obtTdA(sim.ref);
		}
		
		if ($3.tipo != T_ERROR && $6.tipo != T_ERROR) {                    
			if (sim.t == T_ERROR) {
				yyerror("No existe ninguna variable con ese identificador.");
			} else if (! ($3.tipo == T_ENTERO)) {
				yyerror("El indice para acceder a un vector debe ser un entero 0 o positivo.");
			} else if (! ($6.tipo == dim.telem)) { 
				yyerror("Incompatibilidad de tipos, no son el mismo tipo o no son equivalentes."); 
			}                      
		}
	}
  	| ID_ PUNTO_ ID_ IGUAL_ expresion PUNTOCOMA_
	  {
		SIMB sim = obtTdS($1);
		SIMB sim2 = obtTdS($3);

		if (sim.t != T_RECORD) {yyerror("El identificador debe ser struct");}
		if($5.tipo != T_ERROR && sim2.t != T_ERROR){
			if (sim.t == T_ERROR) {
				yyerror("Objeto no declarado.");
			}else if(sim2.t != $5.tipo){
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
		emite(EREAD, crArgNul(), crArgNul(),crArgPos(sim.n , sim.d));
	}
	| PRINT_ PARENTESISIZQ_ expresion PARENTESISDER_ PUNTOCOMA_
	{
		if ($3.tipo != T_ERROR && $3.tipo != T_ENTERO) {
			yyerror("El argumento de la funcion print() debe ser de tipo entero.");
		}
		emite(EWRITE, crArgNul(), crArgNul(), crArgPos(niv, $3.desp));  
	}
	;

instruccionSeleccion
	: IF_ PARENTESISIZQ_ expresion PARENTESISDER_
		{
			if ($3.tipo != T_ERROR){
				if ($3.tipo != T_LOGICO) yyerror("La expresion de evaluacion del \"if\" debe ser de tipo logico.");
			} 
			$<cent>$ = creaLans(si);
			emite(EIGUAL, crArgPos(niv, $3.desp), crArgEnt(FALSE), crArgEtq($<cent>$));
		}
	instruccion 
		{
			$<cent>$ = creaLans(si);
			emite(GOTOS, crArgNul(), crArgNul(), crArgEtq($<cent>$));
			completaLans($<cent>5, crArgEtq(si));
		} 
	ELSE_ instruccion
	{
		completaLans($<cent>7, crArgEtq(si));
	} 
	;

instruccionIteracion
	: WHILE_ 
		{
			$<cent>$ = si;
		}				
	PARENTESISIZQ_ expresion PARENTESISDER_ 	
		{
			if ($4.tipo != T_ERROR){ 
				if ($4.tipo != T_LOGICO) yyerror("La expresion de evaluacion del \"while\" debe ser logica");
			}
			$<cent>$ = creaLans(si);
        	emite(EIGUAL, crArgPos(niv, $4.desp), crArgEnt(FALSE), crArgEtq($<cent>$));
		} 
	instruccion
		{
			emite(GOTOS, crArgNul(), crArgNul(), crArgEtq($<cent>2));
        	completaLans($<cent>6, crArgEtq(si));
		}	
	;

expresion
	: expresionIgualdad	{ $$ = $1; }
	| expresion operadorLogico expresionIgualdad
	{
		$$.tipo = T_ERROR;
		if ($1.tipo != T_ERROR || $3.tipo != T_ERROR) {
			if ($1.tipo != $3.tipo && $1.tipo != T_VACIO && $3.tipo != T_VACIO) {
				printf("$1 = %d  $3 = %d",$1.tipo,$3.tipo);
				yyerror("Incompatibilidad de tipos en expresion logica");
			} else {
				$$.tipo = T_LOGICO;
			}
		}
	$$.desp = creaVarTemp();
        if ($2 == EMULT) { 
            emite(EMULT, crArgPos(niv, $1.desp), crArgPos(niv, $3.desp), crArgPos(niv, $$.desp));
        }else {
            emite(ESUM, crArgPos(niv, $1.desp), crArgPos(niv, $3.desp), crArgPos(niv, $$.desp));
            emite(EMENEQ, crArgPos(niv, $$.desp), crArgEnt(1), crArgEtq(si+2));
            emite(EASIG, crArgEnt(1), crArgNul(), crArgPos(niv, $$.desp));
        }
	}
	;

expresionIgualdad
	: expresionRelacional	{ $$ = $1; }
	| expresionIgualdad operadorIgualdad expresionRelacional
	{	
		$$.tipo = T_ERROR;
		
		if ($1.tipo != T_ERROR && $3.tipo != T_ERROR) {
			if ($1.tipo != $3.tipo) {
				yyerror("Incompatibilidad de tipos en expresion igualdad");
			} else if ($3.tipo != T_LOGICO && $3.tipo != T_ENTERO) { 
				yyerror("Incompatibilidad de tipos, deben ser expresiones logicas o de enteros.");
			}  else {
				$$.tipo = T_LOGICO;
			}
		} 
		$$.desp = creaVarTemp();
		emite(EASIG, crArgEnt(1), crArgNul(), crArgPos(niv, $$.desp));
		emite($2, crArgPos(niv, $1.desp), crArgPos(niv, $3.desp), crArgEtq(si + 2));
		emite(EASIG, crArgEnt(0), crArgNul(), crArgPos(niv, $$.desp));
	}
	;

expresionRelacional
	: expresionAditiva {$$ = $1;}
	| expresionRelacional operadorRelacional expresionAditiva
		{
            		$$.tipo = T_ERROR;
			if ($1.tipo != T_ERROR && $3.tipo != T_ERROR){
				if (!($1.tipo == $3.tipo && $1.tipo == T_ENTERO)) {
					yyerror("Error de tipos en expresion relacional");
				} else {
					$$.tipo = T_LOGICO;
				}
			}
			$$.desp = creaVarTemp();
			emite(EASIG, crArgEnt(1), crArgNul(), crArgPos(niv, $$.desp));
			emite($2, crArgPos(niv, $1.desp), crArgPos(niv, $3.desp), crArgEtq(si + 2));
			emite(EASIG, crArgEnt(0), crArgNul(), crArgPos(niv, $$.desp));
		}
	;
	
	

expresionAditiva
	: expresionMultiplicativa { $$ = $1; }
	| expresionAditiva operadorAditivo expresionMultiplicativa
	{
        $$.tipo = T_ERROR;
		if ($1.tipo != T_ERROR && $3.tipo != T_ERROR) {
			if (!($1.tipo == $3.tipo && $1.tipo == T_ENTERO)) {
				yyerror("Error de tipos en expresion aditiva");
			} else {
				$$.tipo = T_ENTERO;
			}
		}
		$$.desp = creaVarTemp();
        	emite($2, crArgPos(niv, $1.desp), crArgPos(niv, $3.desp), crArgPos(niv, $$.desp));
	}
	;

expresionMultiplicativa
	: expresionUnaria {$$ = $1;}
	| expresionMultiplicativa operadorMultiplicativo expresionUnaria
		{
            $$.tipo = T_ERROR;
			if ($1.tipo != T_ERROR && $3.tipo != T_ERROR) {
				if (!($1.tipo == $3.tipo && $1.tipo == T_ENTERO)) {
					yyerror("Incompatibilidad de tipos en expresion multiplicativa");
				} else {
					$$.tipo = T_ENTERO;
				} 
			}
			$$.desp = creaVarTemp();
        	emite($2, crArgPos(niv, $1.desp), crArgPos(niv, $3.desp), crArgPos(niv, $$.desp));
		}
	;

expresionUnaria
	: expresionSufija	{$$ = $1;}
	| operadorUnario expresionUnaria
	{  
        $$.tipo = T_ERROR;
        if ($2.tipo != T_ERROR) {
            if ($2.tipo == T_ENTERO) {                                                                         
                if ($1 == ESIG) {
				yyerror("Incompatibilidad de tipos, se está negando un entero");
			 	} else { 
					$$.tipo = T_ENTERO; 
				}
            } else if ($2.tipo == T_LOGICO) {                                                                  
                if ($1 == ESUM || $1 == EDIF) {
				yyerror("Solo se puede aplicar el operador unario + o - a un entero");
				} else { 
					$$.tipo = T_LOGICO;
				}
            } else {
			yyerror("Incompatibilidad de tipos");
			}                                                               
        } 
        //Similar a la forma vista en teoria de hacer NOT
            if ($1 == ESIG) {
                emite(EDIF, crArgEnt(1), crArgPos(niv, $2.desp), crArgPos(niv, $$.desp));    
            } else {
                emite($1, crArgEnt(0), crArgPos(niv, $2.desp), crArgPos(niv, $$.desp));
            }
    }
	;

expresionSufija
  	: constante	{
		$$.tipo = $1.tipo;
		$$.desp = creaVarTemp();
  		emite(EASIG, crArgEnt($1.valor), crArgNul(), crArgPos(niv, $$.desp)); }
	| PARENTESISIZQ_ expresion PARENTESISDER_	{$$ = $2;}
	| ID_
	{
		SIMB sim = obtTdS($1);
		$$.tipo = T_ERROR;

	 	if (sim.t == T_ERROR) {
			 yyerror("No existe ninguna variable con ese identificador.");
		 } else { 
			 $$.tipo = sim.t;
		 }
	    $$.desp = creaVarTemp();
		emite(EASIG, crArgPos(niv, sim.d), crArgNul(), crArgPos(niv, $$.desp));   
	}
  	| ID_ PUNTO_ ID_ {

  		if (obtTdS($1).t != T_RECORD){ yyerror("Identificador debe ser struct");}
  		
	   	if (obtTdS($3).t == T_ERROR && obtTdS($1).t == T_RECORD) {
	   		yyerror("Campo no declarado");
			$$.tipo = T_VACIO;
			}
	   	}
	   
	| ID_ CORCHETEIZQ_ expresion CORCHETEDER_
	{
		SIMB sim = obtTdS($1);
		
		$$.tipo = T_ERROR;
	
		if (sim.t == T_ERROR) {
			yyerror("No existe ninguna variable con ese identificador.");
		} else if ($3.tipo != T_ENTERO) {
			yyerror("El indice para acceder a un vector debe ser un entero 0 o positivo.");
		} else { 
			DIM dim = obtTdA(sim.ref);
			$$.tipo = dim.telem;
		}
		$$.desp = creaVarTemp();
        emite(EAV, crArgPos(sim.n, sim.d), crArgPos(niv, $3.desp), crArgPos(niv, $$.desp)); 
	}
	| ID_ PARENTESISIZQ_    
		{  emite(INCTOP, crArgNul(), crArgNul(), crArgEnt(TALLA_TIPO_SIMPLE)); } 
    	parametrosActuales {SIMB sim = obtTdS($1); 
    		if (!cmpDom(sim.ref, $4.ref)){yyerror("Error en el dominio de los parámetros actuales");}} 
    		PARENTESISDER_ 
	{
			$$.tipo = T_ERROR;
			SIMB sim = obtTdS($1);
			if (sim.t == T_ERROR) { 
				yyerror("No existe ninguna variable con ese identificador."); 
			}
			INF inf = obtTdD(sim.ref);
			
			if (inf.tipo == T_ERROR) { 
				yyerror("No existe ninguna funcion con ese identificador."); 
			}
			else {$$.tipo = inf.tipo;}
			emite(CALL, crArgNul(), crArgNul(), crArgEtq(sim.d)); 
			emite(DECTOP, crArgNul(), crArgNul(), crArgEnt(inf.tsp)); 
			$$.desp = creaVarTemp();
			emite(EPOP, crArgNul(), crArgNul(), crArgPos(niv, $$.desp));
	}
	;

constante
	: CTE_   {$$.tipo = T_ENTERO; $$.valor = $1;}
	| TRUE_  {$$.tipo = T_LOGICO; $$.valor = 1;}
	| FALSE_ {$$.tipo = T_LOGICO; $$.valor = 0;}
	;

parametrosActuales
	: {$$.ref = insTdD(-1, T_VACIO);} 
	| listaParametrosActuales{ $$.ref = $1.ref;} 
	;

listaParametrosActuales
	: expresion {$$.ref = insTdD(-1, $1.tipo);} 
	| expresion COMA_ listaParametrosActuales{ $$.ref = insTdD($3.ref, $1.tipo);} 
	;

operadorLogico
	: OPAND_	{$$ = EMULT;} //Al ser 0 y 1 si se multiplica es un AND
	| OPOR_	{$$ = ESUM;} //Al sumar si es positivo es true
	;

operadorIgualdad
	: OPIGUAL_	{$$ = EIGUAL;}
	| OPNOTIGUAL_	{$$ = EDIST;}
	;

operadorRelacional
	: COMPMAYOR_	{$$ = EMAY;}
	| COMPMENOR_	{$$ = EMEN;}
	| COMPMAYORIG_	{$$ = EMAYEQ;}
	| COMPMENORIG_	{$$ = EMENEQ;}
	;

operadorAditivo
	: OPSUMA_ {$$ = ESUM;}
	| OPRESTA_ {$$ = EDIF;}
	;

operadorMultiplicativo
	: OPMULT_ {$$ = EMULT;}
	| OPDIV_  {$$ = EDIVI;}
	;

operadorUnario
	: OPSUMA_ {$$ = ESUM;}
	| OPRESTA_ {$$ = EDIF;}
	| OPNOT_ {$$ = ESIG;} //Mirar implementacion teoria
	;
%%

