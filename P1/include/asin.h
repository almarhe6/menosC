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
    OPSUMA_ = 258,
    OPRESTA_ = 259,
    OPMULT_ = 260,
    OPDIV_ = 261,
    OPMOD_ = 262,
    OPAND_ = 263,
    OPOR_ = 264,
    OPNOT_ = 265,
    OPINCREMENTO_ = 266,
    OPDECREMENTO_ = 267,
    COMPMAYOR_ = 268,
    COMPMENOR_ = 269,
    COMPMAYORIG_ = 270,
    COMPMENORIG_ = 271,
    OPIGUAL_ = 272,
    OPNOTIGUAL_ = 273,
    PUNTO_ = 274,
    IGUAL_ = 275,
    MASIGUAL_ = 276,
    MENOSIGUAL_ = 277,
    PORIGUAL_ = 278,
    DIVIGUAL_ = 279,
    WHILE_ = 280,
    DO_ = 281,
    IF_ = 282,
    ELSEIF_ = 283,
    ELSE_ = 284,
    STRUCT_ = 285,
    COMA_ = 286,
    RETURN_ = 287,
    INT_ = 288,
    BOOL_ = 289,
    READ_ = 290,
    PRINT_ = 291,
    CTE_ = 292,
    ID_ = 293,
    TRUE_ = 294,
    FALSE_ = 295,
    LLAVE1_ = 296,
    LLAVE2_ = 297,
    PARENTESIS1_ = 298,
    PARENTESIS2_ = 299,
    CORCHETE1_ = 300,
    CORCHETE2_ = 301,
    SEMICOLON_ = 302
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_ASIN_H_INCLUDED  */
