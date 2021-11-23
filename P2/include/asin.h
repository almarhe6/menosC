/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_ASIN_H_INCLUDED
# define YY_YY_ASIN_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    PUNTOCOMA_ = 258,
    CORCHETEIZQ_ = 259,
    CORCHETEDER_ = 260,
    STRUCT_ = 261,
    LLAVEIZQ_ = 262,
    LLAVEDER_ = 263,
    IF_ = 264,
    INT_ = 265,
    BOOL_ = 266,
    PARENTESISIZQ_ = 267,
    PARENTESISDER_ = 268,
    COMA_ = 269,
    IGUAL_ = 270,
    ELSE_ = 271,
    READ_ = 272,
    PRINT_ = 273,
    WHILE_ = 274,
    RETURN_ = 275,
    PUNTO_ = 276,
    TRUE_ = 277,
    FALSE_ = 278,
    OPAND_ = 279,
    OPOR_ = 280,
    OPIGUAL_ = 281,
    OPNOTIGUAL_ = 282,
    COMPMAYOR_ = 283,
    COMPMENOR_ = 284,
    COMPMAYORIG_ = 285,
    COMPMENORIG_ = 286,
    OPSUMA_ = 287,
    OPRESTA_ = 288,
    OPMULT_ = 289,
    OPDIV_ = 290,
    OPNOT_ = 291,
    CTE_ = 292,
    ID_ = 293
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 8 "src/asin.y"

	int cent;
	char *ident;
	int referencia;
	int expr;

#line 103 "asin.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_ASIN_H_INCLUDED  */
