/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "src/asin.y"

#include <stdio.h>
#include "header.h"
#include "libtds.h"
#include <string.h>

#line 77 "asin.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 175 "asin.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_ASIN_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   148

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  80
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  151

#define YYUNDEFTOK  2
#define YYMAXUTOK   293


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    36,    36,    36,    41,    42,    46,    47,    51,    59,
      74,    83,    84,    88,    92,   102,   108,   102,   121,   122,
     126,   134,   145,   149,   150,   154,   155,   159,   160,   161,
     162,   163,   167,   178,   198,   215,   222,   231,   231,   239,
     239,   246,   247,   262,   263,   280,   281,   296,   297,   311,
     312,   326,   327,   351,   352,   353,   364,   374,   389,   409,
     410,   411,   415,   416,   420,   421,   425,   426,   430,   431,
     435,   436,   437,   438,   442,   443,   447,   448,   452,   453,
     454
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PUNTOCOMA_", "CORCHETEIZQ_",
  "CORCHETEDER_", "STRUCT_", "LLAVEIZQ_", "LLAVEDER_", "IF_", "INT_",
  "BOOL_", "PARENTESISIZQ_", "PARENTESISDER_", "COMA_", "IGUAL_", "ELSE_",
  "READ_", "PRINT_", "WHILE_", "RETURN_", "PUNTO_", "TRUE_", "FALSE_",
  "OPAND_", "OPOR_", "OPIGUAL_", "OPNOTIGUAL_", "COMPMAYOR_", "COMPMENOR_",
  "COMPMAYORIG_", "COMPMENORIG_", "OPSUMA_", "OPRESTA_", "OPMULT_",
  "OPDIV_", "OPNOT_", "CTE_", "ID_", "$accept", "programa", "$@1",
  "listaDeclaraciones", "declaracion", "declaracionVariable", "tipoSimple",
  "listaCampos", "declaracionFuncion", "$@2", "$@3", "parametrosFormales",
  "listaParametrosFormales", "bloque", "declaracionVariableLocal",
  "listaInstrucciones", "instruccion", "instruccionAsignacion",
  "instruccionEntradaSalida", "instruccionSeleccion", "$@4",
  "instruccionIteracion", "$@5", "expresion", "expresionIgualdad",
  "expresionRelacional", "expresionAditiva", "expresionMultiplicativa",
  "expresionUnaria", "expresionSufija", "constante", "parametrosActuales",
  "listaParametrosActuales", "operadorLogico", "operadorIgualdad",
  "operadorRelacional", "operadorAditivo", "operadorMultiplicativo",
  "operadorUnario", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293
};
# endif

#define YYPACT_NINF (-131)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -131,     6,    52,  -131,    35,  -131,  -131,    52,  -131,  -131,
     -10,  -131,    -9,  -131,    51,    11,   102,  -131,    22,    76,
      94,    62,    81,   100,    -9,  -131,   108,   113,   117,    84,
     110,  -131,  -131,  -131,  -131,    72,  -131,    -9,   114,  -131,
    -131,  -131,    52,  -131,    86,    -4,    51,  -131,   115,   116,
     118,   119,    38,     5,  -131,  -131,  -131,  -131,  -131,    14,
      38,    87,    38,    38,    38,  -131,  -131,  -131,  -131,  -131,
    -131,    73,    16,    56,    78,    82,    83,  -131,  -131,  -131,
      38,    38,    38,    88,  -131,    67,   120,    71,    74,    77,
      38,    38,    91,   124,  -131,  -131,    38,  -131,  -131,    38,
    -131,  -131,  -131,  -131,    38,  -131,  -131,    38,  -131,  -131,
      38,  -131,    43,    21,   121,  -131,   131,   132,  -131,  -131,
      48,    79,   125,  -131,  -131,  -131,    56,    78,    82,    83,
    -131,   122,  -131,    38,    18,  -131,  -131,    18,  -131,    38,
    -131,    38,    41,   123,  -131,  -131,    54,  -131,    18,  -131,
    -131
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     1,     0,    11,    12,     3,     4,     6,
       0,     7,     0,     5,    15,     0,     0,     8,     0,     0,
       0,     0,     0,     0,    19,    13,     0,     0,     0,     0,
       0,    18,    10,    14,     9,    20,    16,     0,     0,    21,
      23,    17,    25,    24,     0,     0,     0,    25,     0,     0,
       0,     0,     0,     0,    26,    28,    30,    29,    31,     0,
       0,     0,     0,     0,     0,    60,    61,    78,    79,    80,
      59,    55,     0,    41,    43,    45,    47,    49,    51,    53,
       0,     0,     0,     0,    27,     0,     0,     0,     0,     0,
       0,    62,     0,     0,    66,    67,     0,    68,    69,     0,
      70,    71,    72,    73,     0,    74,    75,     0,    76,    77,
       0,    52,     0,     0,     0,    37,     0,     0,    39,    54,
       0,    64,     0,    63,    56,    22,    42,    44,    46,    48,
      50,     0,    32,     0,     0,    35,    36,     0,    57,     0,
      58,     0,     0,     0,    40,    65,     0,    34,     0,    33,
      38
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -131,  -131,  -131,  -131,   133,    99,    27,  -131,  -131,  -131,
    -131,  -131,   105,  -131,  -131,    96,  -130,  -131,  -131,  -131,
    -131,  -131,  -131,   -52,    49,    45,    42,    40,   -63,  -131,
    -131,  -131,     9,  -131,  -131,  -131,  -131,  -131,  -131
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     7,     8,     9,    10,    16,    11,    19,
      38,    30,    31,    41,    42,    45,    54,    55,    56,    57,
     134,    58,   137,   121,    73,    74,    75,    76,    77,    78,
      79,   122,   123,    96,    99,   104,   107,   110,    80
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      72,     5,     6,    47,   143,    48,     3,   144,    85,    81,
      87,    88,    89,    49,    50,    51,    52,   111,   150,    93,
      82,    47,    84,    48,   132,    47,    83,    48,    14,   112,
     113,    49,    50,    51,    53,    49,    50,    51,   120,    15,
      94,    95,    12,    22,   147,    94,    95,   130,   131,    20,
      64,    29,    53,   138,    17,    18,    53,   149,     4,    23,
      65,    66,     5,     6,    29,    94,    95,    94,    95,    44,
      67,    68,    94,    95,    69,    70,    71,    90,    94,    95,
     115,   142,    97,    98,   117,    91,    37,   118,    24,   146,
     119,    94,    95,   139,    92,    94,    95,    25,    94,    95,
      26,    94,    95,    94,    95,    28,   100,   101,   102,   103,
      21,    32,     5,     6,   105,   106,    33,   108,   109,    27,
      34,    40,    35,    36,    46,    86,   114,    60,    61,   124,
      62,    63,   125,   116,   135,   136,   133,   141,   140,   148,
      13,    43,    39,    59,   127,   126,   128,   129,   145
};

static const yytype_uint8 yycheck[] =
{
      52,    10,    11,     7,   134,     9,     0,   137,    60,     4,
      62,    63,    64,    17,    18,    19,    20,    80,   148,     3,
      15,     7,     8,     9,     3,     7,    21,     9,    38,    81,
      82,    17,    18,    19,    38,    17,    18,    19,    90,    12,
      24,    25,     7,    16,     3,    24,    25,   110,     5,    38,
      12,    24,    38,     5,     3,     4,    38,     3,     6,    37,
      22,    23,    10,    11,    37,    24,    25,    24,    25,    42,
      32,    33,    24,    25,    36,    37,    38,     4,    24,    25,
      13,   133,    26,    27,    13,    12,    14,    13,    12,   141,
      13,    24,    25,    14,    21,    24,    25,     3,    24,    25,
      38,    24,    25,    24,    25,     5,    28,    29,    30,    31,
       8,     3,    10,    11,    32,    33,     3,    34,    35,    38,
       3,     7,    38,    13,    38,    38,    38,    12,    12,    38,
      12,    12,     8,    13,     3,     3,    15,    15,    13,    16,
       7,    42,    37,    47,    99,    96,   104,   107,   139
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    40,    41,     0,     6,    10,    11,    42,    43,    44,
      45,    47,     7,    43,    38,    45,    46,     3,     4,    48,
      38,     8,    45,    37,    12,     3,    38,    38,     5,    45,
      50,    51,     3,     3,     3,    38,    13,    14,    49,    51,
       7,    52,    53,    44,    45,    54,    38,     7,     9,    17,
      18,    19,    20,    38,    55,    56,    57,    58,    60,    54,
      12,    12,    12,    12,    12,    22,    23,    32,    33,    36,
      37,    38,    62,    63,    64,    65,    66,    67,    68,    69,
      77,     4,    15,    21,     8,    62,    38,    62,    62,    62,
       4,    12,    21,     3,    24,    25,    72,    26,    27,    73,
      28,    29,    30,    31,    74,    32,    33,    75,    34,    35,
      76,    67,    62,    62,    38,    13,    13,    13,    13,    13,
      62,    62,    70,    71,    38,     8,    63,    64,    65,    66,
      67,     5,     3,    15,    59,     3,     3,    61,     5,    14,
      13,    15,    62,    55,    55,    71,    62,     3,    16,     3,
      55
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    39,    41,    40,    42,    42,    43,    43,    44,    44,
      44,    45,    45,    46,    46,    48,    49,    47,    50,    50,
      51,    51,    52,    53,    53,    54,    54,    55,    55,    55,
      55,    55,    56,    56,    56,    57,    57,    59,    58,    61,
      60,    62,    62,    63,    63,    64,    64,    65,    65,    66,
      66,    67,    67,    68,    68,    68,    68,    68,    68,    69,
      69,    69,    70,    70,    71,    71,    72,    72,    73,    73,
      74,    74,    74,    74,    75,    75,    76,    76,    77,    77,
      77
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     1,     1,     3,     6,
       6,     1,     1,     3,     4,     0,     0,     8,     1,     0,
       2,     4,     7,     0,     2,     0,     2,     3,     1,     1,
       1,     1,     4,     7,     6,     5,     5,     0,     8,     0,
       6,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     2,     1,     3,     1,     3,     4,     4,     1,
       1,     1,     0,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 36 "src/asin.y"
          { dvar=0; niv = 0; cargaContexto(niv); }
#line 1463 "asin.c"
    break;

  case 3:
#line 37 "src/asin.y"
                       { if(verTdS) mostrarTdS(); if(obtTdS("main").t == T_ERROR) yyerror("El programa no tiene main"); }
#line 1469 "asin.c"
    break;

  case 4:
#line 41 "src/asin.y"
                  { (yyval.cent) = (yyvsp[0].cent); }
#line 1475 "asin.c"
    break;

  case 5:
#line 42 "src/asin.y"
                                     { (yyval.cent) = (yyvsp[-1].cent) + (yyvsp[0].cent); }
#line 1481 "asin.c"
    break;

  case 6:
#line 46 "src/asin.y"
                          { (yyval.cent) = 0; }
#line 1487 "asin.c"
    break;

  case 7:
#line 47 "src/asin.y"
                         { (yyval.cent) = (yyvsp[0].cent); }
#line 1493 "asin.c"
    break;

  case 8:
#line 52 "src/asin.y"
        { 
		if (!insTdS((yyvsp[-1].ident), VARIABLE, (yyvsp[-2].cent), niv, dvar, -1))
            yyerror("Ya existe una variable con el mismo nombre");
        else
            dvar += TALLA_TIPO_SIMPLE; 
        if(verTdS) mostrarTdS();
	}
#line 1505 "asin.c"
    break;

  case 9:
#line 60 "src/asin.y"
        { 
	int numelem = (yyvsp[-2].cent);
        if (numelem <= 0) {
            yyerror("Talla inapropiada del array");
		numelem = 0;
        }
	if (!insTdS((yyvsp[-4].ident), VARIABLE, T_ARRAY, niv, dvar, insTdA((yyvsp[-5].cent), numelem)))
		yyerror("Identificador repetido");
	else
		dvar += numelem * TALLA_TIPO_SIMPLE; 
	if(verTdS) mostrarTdS();
	}
#line 1522 "asin.c"
    break;

  case 10:
#line 75 "src/asin.y"
        {
		if(!insTdS((yyvsp[-1].ident), VARIABLE, T_RECORD, niv, dvar, (yyvsp[-3].referencia))) {yyerror("Identificador de struct ya utilizado");}
		else dvar += TALLA_TIPO_SIMPLE;
		if(verTdS) mostrarTdS();
	}
#line 1532 "asin.c"
    break;

  case 11:
#line 83 "src/asin.y"
               { (yyval.cent) = T_ENTERO; }
#line 1538 "asin.c"
    break;

  case 12:
#line 84 "src/asin.y"
                { (yyval.cent) = T_LOGICO; }
#line 1544 "asin.c"
    break;

  case 13:
#line 88 "src/asin.y"
                                    {
					(yyval.referencia) = insTdR(-1, (yyvsp[-1].ident), (yyvsp[-2].cent), 0); 
					dvar += TALLA_TIPO_SIMPLE; 
	}
#line 1553 "asin.c"
    break;

  case 14:
#line 92 "src/asin.y"
                                                {
		if (insTdR((yyval.referencia), (yyvsp[-1].ident), (yyvsp[-2].cent), dvar) == -1) yyerror("Campo de struct ya declarado");
		else{
		insTdR((yyval.referencia),(yyvsp[-1].ident), (yyvsp[-2].cent), dvar);
		dvar += TALLA_TIPO_SIMPLE;
		}
	}
#line 1565 "asin.c"
    break;

  case 15:
#line 102 "src/asin.y"
                         {if (!insTdS((yyvsp[0].ident), FUNCION, (yyvsp[-1].cent), niv, dvar, -1)) yyerror("Identificador de funcion repetido");
	niv = 1; cargaContexto(niv);
	}
#line 1573 "asin.c"
    break;

  case 16:
#line 108 "src/asin.y"
        {insTdS((yyvsp[-4].ident),FUNCION,(yyvsp[-5].cent),niv,dvar,(yyvsp[-1].referencia));}
#line 1579 "asin.c"
    break;

  case 17:
#line 112 "src/asin.y"
        {if(obtTdS((yyvsp[-6].ident)).t != (yyvsp[0].cent)){if(strcmp((yyvsp[-6].ident), "main") == 0)yyerror("Hay más de un main");
		else yyerror("Error de tipo en return");}
	if(verTdS) mostrarTdS();
	descargaContexto(niv);
	niv = 0;
	}
#line 1590 "asin.c"
    break;

  case 18:
#line 121 "src/asin.y"
                                 {(yyval.referencia)= (yyvsp[0].referencia);}
#line 1596 "asin.c"
    break;

  case 19:
#line 122 "src/asin.y"
          {(yyval.referencia) = insTdD(-1, T_VACIO);}
#line 1602 "asin.c"
    break;

  case 20:
#line 126 "src/asin.y"
                         {
		(yyval.referencia) = insTdD(-1,(yyvsp[-1].cent));

		if (!insTdS((yyvsp[0].ident), PARAMETRO, (yyvsp[-1].cent), niv, dvar, -1))
			yyerror("Variable con el mismo identificador ya declarada en struct");
		else dvar += TALLA_TIPO_SIMPLE;
		if(verTdS) mostrarTdS();
	}
#line 1615 "asin.c"
    break;

  case 21:
#line 135 "src/asin.y"
        {
		(yyval.referencia) = insTdD((yyvsp[0].referencia),(yyvsp[-3].cent));
		if (!insTdS((yyvsp[-2].ident), PARAMETRO, (yyvsp[-3].cent), niv, dvar, -1))
			yyerror("Variable con el mismo identificador ya declarada en struct");
		else dvar += TALLA_TIPO_SIMPLE;
		if(verTdS) mostrarTdS();
	}
#line 1627 "asin.c"
    break;

  case 22:
#line 145 "src/asin.y"
                                                                                                       {(yyval.cent) = (yyvsp[-2].expr);}
#line 1633 "asin.c"
    break;

  case 32:
#line 168 "src/asin.y"
        {
		SIMB sim = obtTdS((yyvsp[-3].ident));
		if((yyvsp[-1].expr) != T_ERROR){   
			if (sim.t == T_ERROR) {
				yyerror("Objeto no declarado");
			} else if (! ((sim.t == (yyvsp[-1].expr) && sim.t == T_ENTERO) || (sim.t == (yyvsp[-1].expr) && sim.t == T_LOGICO))) {
				yyerror("Error de tipos en la instruccion de asignacion");
			}
		}
	}
#line 1648 "asin.c"
    break;

  case 33:
#line 179 "src/asin.y"
        {
		SIMB sim = obtTdS((yyvsp[-6].ident)); DIM dim;
		
		if (sim.t != T_ARRAY) {
			yyerror("La variable no es un vector, no se puede acceder mediante indices.");
		} else {
			dim = obtTdA(sim.ref);
		}
		
		if ((yyvsp[-4].expr) != T_ERROR && (yyvsp[-1].expr) != T_ERROR) {                    
			if (sim.t == T_ERROR) {
				yyerror("No existe ninguna variable con ese identificador.");
			} else if (! ((yyvsp[-4].expr) == T_ENTERO)) {
				yyerror("El indice para acceder a un vector debe ser un entero 0 o positivo.");
			} else if (! ((yyvsp[-1].expr) == dim.telem)) { 
				yyerror("Incompatibilidad de tipos, no son el mismo tipo o no son equivalentes."); 
			}                      
		}
	}
#line 1672 "asin.c"
    break;

  case 34:
#line 199 "src/asin.y"
          {
		SIMB sim = obtTdS((yyvsp[-5].ident));
		SIMB sim2 = obtTdS((yyvsp[-3].ident));

		if (sim.t != T_RECORD) {yyerror("El identificador debe ser struct");}
		if((yyvsp[-1].expr) != T_ERROR && sim2.t != T_ERROR){
			if (sim.t == T_ERROR) {
				yyerror("Objeto no declarado.");
			}else if(sim2.t != (yyvsp[-1].expr)){
				yyerror("Tipos incompatibles.");
			}
		}
	  }
#line 1690 "asin.c"
    break;

  case 35:
#line 216 "src/asin.y"
        {
		SIMB sim = obtTdS((yyvsp[-2].ident));
		if (sim.t != T_ENTERO) {
			yyerror("El argumento de la funcion read() debe ser de tipo entero.");
		}
	}
#line 1701 "asin.c"
    break;

  case 36:
#line 223 "src/asin.y"
        {
		if ((yyvsp[-2].expr) != T_ERROR && (yyvsp[-2].expr) != T_ENTERO) {
			yyerror("El argumento de la funcion print() debe ser de tipo entero.");
		}
	}
#line 1711 "asin.c"
    break;

  case 37:
#line 231 "src/asin.y"
                                                        {
		if ((yyvsp[-1].expr) != T_ERROR)
			if ((yyvsp[-1].expr) != T_LOGICO) yyerror("La expresion de evaluacion del \"if\" debe ser de tipo logico.");
	}
#line 1720 "asin.c"
    break;

  case 39:
#line 239 "src/asin.y"
                                                                {
		if ((yyvsp[-1].expr) != T_ERROR)
			if ((yyvsp[-1].expr) != T_LOGICO) yyerror("La expresion de evaluacion del \"while\" debe ser logica");
	}
#line 1729 "asin.c"
    break;

  case 41:
#line 246 "src/asin.y"
                                { (yyval.expr) = (yyvsp[0].expr); }
#line 1735 "asin.c"
    break;

  case 42:
#line 248 "src/asin.y"
        {
		(yyval.expr) = T_ERROR;
		if ((yyvsp[-2].expr) != T_ERROR || (yyvsp[0].expr) != T_ERROR) {
			if ((yyvsp[-2].expr) != (yyvsp[0].expr) && (yyvsp[-2].expr) != T_VACIO && (yyvsp[0].expr) != T_VACIO) {
				printf("$1 = %d  $3 = %d",(yyvsp[-2].expr),(yyvsp[0].expr));
				yyerror("Incompatibilidad de tipos en expresion logica");
			} else {
				(yyval.expr) = T_LOGICO;
			}
		}
	}
#line 1751 "asin.c"
    break;

  case 43:
#line 262 "src/asin.y"
                                { (yyval.expr) = (yyvsp[0].expr); }
#line 1757 "asin.c"
    break;

  case 44:
#line 264 "src/asin.y"
        {	
		(yyval.expr) = T_ERROR;
		
		if ((yyvsp[-2].expr) != T_ERROR && (yyvsp[0].expr) != T_ERROR) {
			if ((yyvsp[-2].expr) != (yyvsp[0].expr)) {
				yyerror("Incompatibilidad de tipos en expresion igualdad");
			} else if ((yyvsp[0].expr) != T_LOGICO || (yyvsp[0].expr) != T_ENTERO) { 
				yyerror("Incompatibilidad de tipos, deben ser expresiones logicas o de enteros.");
			}  else {
				(yyval.expr) = T_LOGICO;
			}
		} 
	}
#line 1775 "asin.c"
    break;

  case 45:
#line 280 "src/asin.y"
                           {(yyval.expr) = (yyvsp[0].expr);}
#line 1781 "asin.c"
    break;

  case 46:
#line 282 "src/asin.y"
                {
            (yyval.expr) = T_ERROR;
			if ((yyvsp[-2].expr) != T_ERROR && (yyvsp[0].expr) != T_ERROR){
				if (!((yyvsp[-2].expr) == (yyvsp[0].expr) && (yyvsp[-2].expr) == T_ENTERO)) {
					yyerror("Error de tipos en expresion relacional");
				} else {
					(yyval.expr) = T_LOGICO;
				}
			}
		}
#line 1796 "asin.c"
    break;

  case 47:
#line 296 "src/asin.y"
                                  { (yyval.expr) = (yyvsp[0].expr); }
#line 1802 "asin.c"
    break;

  case 48:
#line 298 "src/asin.y"
        {
        (yyval.expr) = T_ERROR;
		if ((yyvsp[-2].expr) != T_ERROR && (yyvsp[0].expr) != T_ERROR) {
			if (!((yyvsp[-2].expr) == (yyvsp[0].expr) && (yyvsp[-2].expr) == T_ENTERO)) {
				yyerror("Error de tipos en expresion aditiva");
			} else {
				(yyval.expr) = T_ENTERO;
			}
		}
	}
#line 1817 "asin.c"
    break;

  case 49:
#line 311 "src/asin.y"
                          {(yyval.expr) = (yyvsp[0].expr);}
#line 1823 "asin.c"
    break;

  case 50:
#line 313 "src/asin.y"
                {
            (yyval.expr) = T_ERROR;
			if ((yyvsp[-2].expr) != T_ERROR && (yyvsp[0].expr) != T_ERROR) {
				if (!((yyvsp[-2].expr) == (yyvsp[0].expr) && (yyvsp[-2].expr) == T_ENTERO)) {
					yyerror("Incompatibilidad de tipos en expresion multiplicativa");
				} else {
					(yyval.expr) = T_ENTERO;
				} 
			}
		}
#line 1838 "asin.c"
    break;

  case 51:
#line 326 "src/asin.y"
                                {(yyval.expr) = (yyvsp[0].expr);}
#line 1844 "asin.c"
    break;

  case 52:
#line 328 "src/asin.y"
        {  
        (yyval.expr) = T_ERROR;
        if ((yyvsp[0].expr) != T_ERROR) {
            if ((yyvsp[0].expr) == T_ENTERO) {                                                                         
                if ((yyvsp[-1].cent) == OPNOT) {
					yyerror("Incompatibilidad de tipos, se está negando un entero");
			 	} else { 
					(yyval.expr) = T_ENTERO; 
				}
            } else if ((yyvsp[0].expr) == T_LOGICO) {                                                                  
                if ((yyvsp[-1].cent) == OPSUMA || (yyvsp[-1].cent) == OPRESTA) {
					yyerror("Incompatibilidad de tipos, solo se puede aplicar el operador unario \"+\" o \"-\" a una expresion entera.");
				} else { 
					(yyval.expr) = T_LOGICO;
				}
            } else {
				yyerror("Incompatibilidad de tipos, no son el mismo tipo o no son equivalentes.");
			}                                                               
        } 
    }
#line 1869 "asin.c"
    break;

  case 53:
#line 351 "src/asin.y"
                        {(yyval.expr) = (yyvsp[0].expr);}
#line 1875 "asin.c"
    break;

  case 54:
#line 352 "src/asin.y"
                                                        {(yyval.expr) = (yyvsp[-1].expr);}
#line 1881 "asin.c"
    break;

  case 55:
#line 354 "src/asin.y"
        {
			SIMB sim = obtTdS((yyvsp[0].ident));
			(yyval.expr) = T_ERROR;

		 	if (sim.t == T_ERROR) {
				 yyerror("No existe ninguna variable con ese identificador.");
			 } else { 
				 (yyval.expr) = sim.t;
			 }
		}
#line 1896 "asin.c"
    break;

  case 56:
#line 364 "src/asin.y"
                         {

  		if (obtTdS((yyvsp[-2].ident)).t != T_RECORD){ yyerror("Identificador debe ser struct");}
  		
	   	if (obtTdS((yyvsp[0].ident)).t == T_ERROR && obtTdS((yyvsp[-2].ident)).t == T_RECORD) {
	   		yyerror("Campo no declarado");
			(yyval.expr) = T_VACIO;
			}
	   	}
#line 1910 "asin.c"
    break;

  case 57:
#line 375 "src/asin.y"
        {
		SIMB sim = obtTdS((yyvsp[-3].ident));
		
		(yyval.expr) = T_ERROR;
	
		if (sim.t == T_ERROR) {
			yyerror("No existe ninguna variable con ese identificador.");
		} else if ((yyvsp[-1].expr) != T_ENTERO) {
			yyerror("El indice para acceder a un vector debe ser un entero 0 o positivo.");
		} else { 
			DIM dim = obtTdA(sim.ref);
			(yyval.expr) = dim.telem;
		}
	}
#line 1929 "asin.c"
    break;

  case 58:
#line 390 "src/asin.y"
        {
			SIMB sim = obtTdS((yyvsp[-3].ident));

			(yyval.expr) = T_ERROR;
			
			if (sim.t == T_ERROR) { 
				yyerror("No existe ninguna variable con ese identificador."); 
			}
			INF inf = obtTdD(sim.ref);

			if (inf.tipo == T_ERROR) { 
				yyerror("No existe ninguna funcion con ese identificador."); 
			} else {
				(yyval.expr) = inf.tipo;
			}
		}
#line 1950 "asin.c"
    break;

  case 59:
#line 409 "src/asin.y"
                 {(yyval.expr) = T_ENTERO;}
#line 1956 "asin.c"
    break;

  case 60:
#line 410 "src/asin.y"
                 {(yyval.expr) = T_LOGICO;}
#line 1962 "asin.c"
    break;

  case 61:
#line 411 "src/asin.y"
                 {(yyval.expr) = T_LOGICO;}
#line 1968 "asin.c"
    break;

  case 66:
#line 425 "src/asin.y"
                        {(yyval.cent) = OPAND;}
#line 1974 "asin.c"
    break;

  case 67:
#line 426 "src/asin.y"
                        {(yyval.cent) = OPOR;}
#line 1980 "asin.c"
    break;

  case 68:
#line 430 "src/asin.y"
                                {(yyval.cent) = OPIGUAL;}
#line 1986 "asin.c"
    break;

  case 69:
#line 431 "src/asin.y"
                        {(yyval.cent) = OPNOTIGUAL;}
#line 1992 "asin.c"
    break;

  case 70:
#line 435 "src/asin.y"
                        {(yyval.cent) = COMPMAYOR;}
#line 1998 "asin.c"
    break;

  case 71:
#line 436 "src/asin.y"
                        {(yyval.cent) = COMPMENOR;}
#line 2004 "asin.c"
    break;

  case 72:
#line 437 "src/asin.y"
                        {(yyval.cent) = COMPMAYORIG;}
#line 2010 "asin.c"
    break;

  case 73:
#line 438 "src/asin.y"
                        {(yyval.cent) = COMPMENORIG;}
#line 2016 "asin.c"
    break;

  case 74:
#line 442 "src/asin.y"
                  {(yyval.cent) = OPSUMA;}
#line 2022 "asin.c"
    break;

  case 75:
#line 443 "src/asin.y"
                   {(yyval.cent) = OPRESTA;}
#line 2028 "asin.c"
    break;

  case 76:
#line 447 "src/asin.y"
                  {(yyval.cent) = OPMULT;}
#line 2034 "asin.c"
    break;

  case 77:
#line 448 "src/asin.y"
                  {(yyval.cent) = OPDIV;}
#line 2040 "asin.c"
    break;

  case 78:
#line 452 "src/asin.y"
                  {(yyval.cent) = OPSUMA;}
#line 2046 "asin.c"
    break;

  case 79:
#line 453 "src/asin.y"
                   {(yyval.cent) = OPRESTA;}
#line 2052 "asin.c"
    break;

  case 80:
#line 454 "src/asin.y"
                 {(yyval.cent) = OPNOT;}
#line 2058 "asin.c"
    break;


#line 2062 "asin.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 456 "src/asin.y"

