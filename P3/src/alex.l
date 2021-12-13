%{
#include <stdio.h>
#include "header.h"
#include "asin.h"
#define retornar(x) {if (verbosidad) ECHO; return(x);}
%}

%option noinput
%option nounput
%option yylineno

delimitador	[ \t\n]+
digito	[0-9]
letra	[a-zA-Z]
id	{letra}({letra}|{digito}|_)*
entero	{digito}+
realantes	{digito}*\.{digito}+
realdespues	{digito}+\.{digito}*
real	{realantes}|{realdespues}
comentario	"//".*
cte	{real}|{entero}

%%

{delimitador} {if (verbosidad) ECHO;}
{comentario} {if (verbosidad) ECHO;}

"int" {retornar (INT_);}
"bool" {retornar (BOOL_);}
"true" {retornar (TRUE_);}
"false" {retornar (FALSE_);}
"read" {retornar (READ_);}
"print" {retornar (PRINT_);}
"struct" {retornar (STRUCT_);}
"while" {retornar (WHILE_);}
"else" {retornar (ELSE_);}
"if" {retornar (IF_);}
"return" {retornar (RETURN_);}

"!" {retornar (OPNOT_);}
"+" {retornar (OPSUMA_);}
"-" {retornar (OPRESTA_);}
"*" {retornar (OPMULT_);}
"/" {retornar (OPDIV_);}
"==" {retornar (OPIGUAL_);}
"!=" {retornar (OPNOTIGUAL_);}

"&&" {retornar (OPAND_);}
"||" {retornar (OPOR_);}
"=" {retornar (IGUAL_);}
"<" {retornar (COMPMENOR_);}
">" {retornar (COMPMAYOR_);} 
"<=" {retornar (COMPMENORIG_);}
">=" {retornar (COMPMAYORIG_);}

"(" {retornar (PARENTESISIZQ_);}
")" {retornar (PARENTESISDER_);}
"{" {retornar (LLAVEIZQ_);}
"}" {retornar (LLAVEDER_);}
"[" {retornar (CORCHETEIZQ_);}
"]" {retornar (CORCHETEDER_);}
"." {retornar (PUNTO_);}
"," {retornar (COMA_);}
";" {retornar (PUNTOCOMA_);}

{cte}        	 { yylval.cent = atoi(yytext); retornar(CTE_); }
{id}             { yylval.ident = strdup(yytext); retornar(ID_); }

. {yyerror("Caracter desconocido");}

%%
