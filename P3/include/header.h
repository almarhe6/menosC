/*****************************************************************************/
/**   Ejemplo de un posible fichero de cabeceras donde situar las           **/
/** definiciones de constantes, variables y estructuras para MenosC.        **/
/** Los alumos deberan adaptarlo al desarrollo de su propio compilador.     **/
/*****************************************************************************/
#ifndef _HEADER_H
#define _HEADER_H

/****************************************************** Constantes generales */
#define TRUE  1
#define FALSE 0
#define TALLA_TIPO_SIMPLE 1
#define TALLA_SEGENLACES 2

typedef struct campos{
	int talla;
	int ref;
	}CAMPOS;


typedef struct refaux{
   int val;
   int r1;
   int r2; 
   int r3;
   int r4;
   int r5;
} REFAUX;


/************************************* Variables externas definidas en el AL */
extern int yylex();
extern int yyparse();
extern FILE *yyin;                           /* Fichero de entrada           */
extern int   yylineno;                       /* Contador del numero de linea */
extern char *yytext;                         /* Patron detectado             */
/********* Funciones y variables externas definidas en el Programa Principal */
extern void yyerror(const char * msg) ;   /* Tratamiento de errores          */

extern int verbosidad;                   /* Flag si se desea una traza       */
extern int numErrores;              /* Contador del numero de errores        */

extern int niv;			/* Nivel de anidamiento 0:global  1:local */
extern int dvar;			/* Desplazamiento variables */
extern int verTdS;			/* Si activo mostrar TdS */
extern int si; 			/* Desplazamiento relativo en el Segmento de Codigo */

typedef struct Estructura{
	int tipo;
	int desp;
} ESTRUCT;

#endif  /* _HEADER_H */
/*****************************************************************************/
