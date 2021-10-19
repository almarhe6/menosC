%{
#include <stdio.h>
#include "header.h"
%}
%token OPSUMA_ OPRESTA_ OPMULT_ OPDIV_ OPMOD_ OPAND_ OPOR_ OPNOT_ OPINCREMENTO_ OPDECREMENTO_
%token COMPMAYOR_ COMPMENOR_ COMPMAYORIG_ COMPMENORIG_ OPIGUAL_ OPNOTIGUAL_ PUNTO_
%token IGUAL_   MASIGUAL_   MENOSIGUAL_ PORIGUAL_   DIVIGUAL_
%token WHILE_   DO_   IF_   ELSEIF_     ELSE_   STRUCT_ COMA_ RETURN_
%token INT_     BOOL_
%token READ_    PRINT_
%token CTE_     ID_     TRUE_   FALSE_
%token LLAVE1_  LLAVE2_ PARENTESIS1_ PARENTESIS2_ CORCHETE1_ CORCHETE2_ SEMICOLON_
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
    : tipoSimple ID_ SEMICOLON_
    | tipoSimple ID_ CORCHETE1_ CTE_ CORCHETE2_ SEMICOLON_
    | STRUCT_ LLAVE1_ listaCampos LLAVE2_ ID_ SEMICOLON_
    ;

tipoSimple
    : INT_
    | BOOL_
    ;

listaCampos
    : tipoSimple ID_ SEMICOLON_
    | listaCampos tipoSimple ID_ SEMICOLON_
    ;

declaracionFuncion
    : tipoSimple ID_ PARENTESIS1_ parametrosFormales PARENTESIS2_ bloque
    ;
    
parametrosFormales
    : /* instruccion vacia */
    | listaParametrosFormales
    ;

listaParametrosFormales
    : tipoSimple ID_
    | tipoSimple ID_ COMA_ listaParametrosFormales
    ;

bloque
    : LLAVE1_ declaracionVariableLocal listaInstrucciones RETURN_ expresion SEMICOLON_ LLAVE2_
    ;
    
listaInstrucciones
    : listaInstrucciones instruccion
    | /* instruccion vacia */
    ;

declaracionVariableLocal
    : /* instruccion vacia */
    | declaracionVariableLocal declaracionVariable
    ;

instruccion
    : LLAVE1_ listaInstrucciones LLAVE2_
    | instruccionAsignacion
    | instruccionSeleccion
    | instruccionEntradaSalida
    | instruccionIteracion
    ;

instruccionAsignacion
    : ID_ IGUAL_ expresion SEMICOLON_
    | ID_ CORCHETE1_ expresion CORCHETE2_ IGUAL_ expresion SEMICOLON_
    | ID_ PUNTO_ ID_ IGUAL_ expresion SEMICOLON_
    ;
    
instruccionEntradaSalida
    : READ_ PARENTESIS1_ ID_ PARENTESIS2_ SEMICOLON_
    | PRINT_ PARENTESIS1_ expresion PARENTESIS2_ SEMICOLON_
    ;
    
instruccionSeleccion
    : IF_ PARENTESIS1_ expresion PARENTESIS2_ instruccion ELSE_ instruccion
    ;

instruccionIteracion
    : WHILE_ PARENTESIS1_ expresion PARENTESIS2_ instruccion
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
    : PARENTESIS1_ expresion PARENTESIS2_
    | ID_ PUNTO_ ID_
    | ID_ CORCHETE1_ expresion CORCHETE2_
    | ID_
    | constante
    | ID_ PARENTESIS1_ parametrosActuales PARENTESIS2_
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


operadorUnario
    : OPSUMA_
    | OPRESTA_
    | OPNOT_
    ;

operadorMultiplicativo
    : OPMULT_
    | OPDIV_
    ;
%%
