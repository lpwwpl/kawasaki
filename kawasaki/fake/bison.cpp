/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 4 "fake\\parser.y" /* yacc.c:339  */

#include "semantic.h"
#include "types.h"
#include "fake.h"

#define YYPARSE_PARAM   parm
#define YYLEX_PARAM     parm

#define yyerror(loc, param, msg) my_yyerror(msg, param)

int yylex(YYSTYPE *lvalp, YYLTYPE * loc, void * parm)
{
	myflexer *l = (myflexer *)parm;
	int ret = l->yylex(lvalp, loc);
	FKLOG("[bison]: bison get token[%s] str[%s] line[%d,%d]", fkget_token_name(ret).c_str(), lvalp->str.c_str(), loc->first_line, loc->last_line);
	return ret;
}

int my_yyerror(const char *s, void * parm)
{
    myflexer *l = (myflexer *)parm;
    l->LexerError(s);
    return 1;
}

#define NEWTYPE(p, x) \
	x* p = (x*)(((myflexer *)parm)->malloc(sizeof(x), #x)); \
	new (p) x(); \
	p->fk = ((myflexer *)parm)->getfake(); \
	p->lno = yylsp->first_line; \
	FKLOG("[bison]: bison new type %s %p line %d %d %d", #x, p,    yylloc.first_line, yylsp->first_line);
	//((myflexer *)parm)->lineno(),

#line 100 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:339  */

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "bison.hpp".  */
#ifndef YY_YY_D_FREECAD_0_19_1_BUILD_SRC_MOD_KAWASAKI_KAWASAKI_KAWASAKI_FAKE_BISON_HPP_INCLUDED
# define YY_YY_D_FREECAD_0_19_1_BUILD_SRC_MOD_KAWASAKI_KAWASAKI_KAWASAKI_FAKE_BISON_HPP_INCLUDED
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
    ELSEIF = 258,
    SIGNAL = 259,
    LINE_GAP = 260,
    GAP = 261,
    TYPE = 262,
    END_OF_LINE = 263,
    CALL = 264,
    TRANS = 265,
    BASE = 266,
    TOOL = 267,
    STOP = 268,
    HOME = 269,
    GOTO = 270,
    REALS = 271,
    STRINGS = 272,
    JOINTS = 273,
    TO = 274,
    JMOVE = 275,
    RETURN = 276,
    FUNC = 277,
    FTRUE = 278,
    FFALSE = 279,
    IF = 280,
    THEN = 281,
    ELSE = 282,
    END_ST = 283,
    END_DOT = 284,
    STRING_DEFINITION = 285,
    IDENTIFIER = 286,
    NUMBER = 287,
    SINGLE_LINE_COMMENT = 288,
    DIVIDE_MOD = 289,
    ARG_SPLITTER = 290,
    PLUS = 291,
    MINUS = 292,
    DIVIDE = 293,
    MULTIPLY = 294,
    ASSIGN = 295,
    MORE = 296,
    LESS = 297,
    MORE_OR_EQUAL = 298,
    LESS_OR_EQUAL = 299,
    EQUAL = 300,
    NOT_EQUAL = 301,
    OPEN_BRACKET = 302,
    CLOSE_BRACKET = 303,
    AND = 304,
    OR = 305,
    FKFLOAT = 306,
    SWAIT = 307,
    COLON = 308,
    FOR = 309,
    OPEN_SQUARE_BRACKET = 310,
    CLOSE_SQUARE_BRACKET = 311,
    IDENTIFIER_DOT = 312,
    IDENTIFIER_POINTER = 313,
    FNULL = 314,
    SWITCH = 315,
    CASE = 316,
    DEFAULT = 317,
    OF = 318,
    SIG = 319,
    QUOTATION = 320,
    TWAIT = 321,
    SPACE = 322,
    UMINUS = 323,
    DOT = 324
  };
#endif

/* Value type.  */

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif



int yyparse (void * parm);

#endif /* !YY_YY_D_FREECAD_0_19_1_BUILD_SRC_MOD_KAWASAKI_KAWASAKI_KAWASAKI_FAKE_BISON_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 229 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   588

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  71
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  121
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  219

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   324

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    70,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   181,   181,   185,   189,   193,   198,   205,   206,   210,
     214,   218,   226,   233,   237,   244,   252,   264,   268,   270,
     277,   291,   296,   305,   315,   325,   333,   334,   343,   352,
     361,   368,   385,   394,   404,   414,   424,   434,   442,   452,
     460,   470,   480,   489,   499,   509,   519,   523,   530,   540,
     550,   551,   552,   553,   554,   555,   556,   557,   558,   559,
     560,   562,   568,   574,   581,   587,   593,   601,   613,   626,
     631,   639,   650,   654,   658,   664,   674,   684,   694,   704,
     714,   724,   734,   744,   754,   764,   778,   784,   790,   798,
     808,   820,   826,   832,   840,   848,   856,   865,   873,   883,
     889,   895,   903,   909,   919,   929,   939,   949,   961,   967,
     973,  1008,  1017,  1026,  1035,  1044,  1053,  1075,  1085,  1097,
    1105,  1116
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ELSEIF", "SIGNAL", "LINE_GAP", "GAP",
  "TYPE", "END_OF_LINE", "CALL", "TRANS", "BASE", "TOOL", "STOP", "HOME",
  "GOTO", "REALS", "STRINGS", "JOINTS", "TO", "JMOVE", "RETURN", "FUNC",
  "FTRUE", "FFALSE", "IF", "THEN", "ELSE", "END_ST", "END_DOT",
  "STRING_DEFINITION", "IDENTIFIER", "NUMBER", "SINGLE_LINE_COMMENT",
  "DIVIDE_MOD", "ARG_SPLITTER", "PLUS", "MINUS", "DIVIDE", "MULTIPLY",
  "ASSIGN", "MORE", "LESS", "MORE_OR_EQUAL", "LESS_OR_EQUAL", "EQUAL",
  "NOT_EQUAL", "OPEN_BRACKET", "CLOSE_BRACKET", "AND", "OR", "FKFLOAT",
  "SWAIT", "COLON", "FOR", "OPEN_SQUARE_BRACKET", "CLOSE_SQUARE_BRACKET",
  "IDENTIFIER_DOT", "IDENTIFIER_POINTER", "FNULL", "SWITCH", "CASE",
  "DEFAULT", "OF", "SIG", "QUOTATION", "TWAIT", "SPACE", "UMINUS", "DOT",
  "','", "$accept", "program", "TRANS_head", "trans_define",
  "FKFLOATs_define", "REALS_head", "reals_define", "STRINGS_head",
  "strings_define", "body", "function_declaration",
  "function_declaration_arguments", "arg", "arg_expr", "dimension_list",
  "function_call_arguments", "function_call", "block", "GOTO_stm",
  "LABEL_stm", "HOME_stm", "BASE_stm", "TOOL_stm", "TYPE_stm", "STOP_stm",
  "JMOVE_stm", "TWAIT_stm", "SWAIT_stm", "signal_num_stm", "SIGNAL_stm",
  "SIG_stm", "stmt", "for_stmt", "if_stmt", "else_stmt", "end_statement",
  "optional_semicolon", "cmp", "cmp_value", "return_stmt", "assign_stmt",
  "assign_value", "var", "variable", "expr", "math_expr", "expr_value",
  "explicit_value", "switch_stmt", "switch_case_list",
  "switch_case_define", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
      44
};
# endif

#define YYPACT_NINF -134

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-134)))

#define YYTABLE_NINF -111

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       4,    28,    34,    53,  -134,     0,  -134,    39,    70,  -134,
      55,   -31,     7,    67,    83,  -134,   -21,  -134,    75,    96,
    -134,   -30,   101,   102,  -134,    55,   515,  -134,  -134,   -10,
      81,    96,  -134,   -27,   105,  -134,   110,   113,   117,   -26,
     -20,  -134,   120,   122,   126,  -134,  -134,  -134,    26,  -134,
     -38,  -134,   184,  -134,   110,   515,  -134,  -134,  -134,   184,
     108,  -134,   225,  -134,  -134,  -134,  -134,  -134,  -134,  -134,
    -134,  -134,  -134,  -134,  -134,  -134,  -134,  -134,  -134,   123,
     133,  -134,   224,   232,  -134,  -134,   139,   128,   156,  -134,
       6,   148,    96,  -134,   146,  -134,  -134,   135,  -134,  -134,
    -134,  -134,  -134,  -134,  -134,     3,    16,   130,    26,   136,
    -134,     5,   154,   282,  -134,   288,  -134,   529,  -134,   157,
     153,  -134,   283,   141,  -134,  -134,  -134,   184,   529,   529,
     529,   529,   529,   151,  -134,    81,   166,  -134,    18,   180,
     529,    57,   157,   177,   515,    26,    26,   184,   184,   184,
     184,   184,   184,   529,  -134,   138,  -134,  -134,   515,   150,
    -134,   282,  -134,   288,  -134,    63,    63,  -134,  -134,  -134,
    -134,    81,   172,   110,  -134,    -3,   232,  -134,   165,   341,
    -134,   168,  -134,  -134,  -134,  -134,  -134,  -134,   170,  -134,
     399,   184,   -24,  -134,  -134,   189,  -134,   529,  -134,  -134,
     515,   192,   515,   191,  -134,   515,  -134,  -134,  -134,  -134,
     515,  -134,   457,   515,  -134,   457,  -134,   515,  -134
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      17,     0,     0,     9,    18,     0,     1,     0,     3,    19,
      21,     0,     0,     0,    13,    24,     0,    23,     0,     0,
      10,     0,     0,     0,     2,     0,     0,    11,    26,     0,
       0,     0,     4,     0,     0,    22,     0,     0,     0,     0,
       0,    42,     0,     0,     0,    89,   111,   112,     0,   114,
      95,   113,     0,   115,     0,     0,    98,    97,   116,     0,
       0,   100,     0,    57,    59,    56,    54,    55,    58,    52,
      53,    51,    50,    60,    33,    65,    64,    61,    62,     0,
     110,    63,   101,     0,   109,    66,     0,     0,     7,     5,
       0,     0,     0,    14,    46,    48,    41,     0,    37,    38,
      39,    40,    36,    34,    43,   111,   112,    95,     0,     0,
      85,     0,     0,    87,    88,    86,    35,     0,   110,     0,
     101,    45,     0,     0,    44,    20,    32,     0,     0,     0,
       0,     0,     0,     0,    27,     0,     0,    15,     0,     0,
      30,     0,    88,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   108,     0,    99,   102,     0,     0,
      90,    92,    93,    91,   107,   103,   104,   106,   105,    12,
       8,     0,     0,     0,    29,     0,    25,    74,     0,    69,
      75,    76,    78,    77,    80,    81,    79,    82,   108,    96,
       0,     0,     0,   119,     6,     0,    47,     0,    31,    49,
      71,     0,     0,     0,    73,     0,   118,   120,    16,    28,
      70,    68,     0,     0,    72,     0,    67,   121,   117
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -134,  -134,  -134,  -134,  -127,  -134,  -134,  -134,  -134,  -134,
     227,  -134,   208,    50,   -29,  -134,  -134,   -55,  -134,  -134,
    -134,  -134,  -134,  -134,  -134,  -134,  -134,  -134,   -48,  -134,
    -134,   -61,  -134,  -134,  -134,  -133,  -134,  -105,   -11,  -134,
    -134,  -134,  -134,   -36,    19,    -9,  -110,    76,  -134,  -134,
      59
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    14,    22,    89,     8,    12,    24,    34,     3,
       4,    16,    17,   174,    29,   175,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    95,    73,
     110,    74,    75,    76,   201,   206,   214,   111,   112,    77,
      78,   160,    79,    80,    81,    82,    83,    84,    85,   192,
     193
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     122,   126,    90,   141,   204,    98,   121,   155,   170,    18,
      30,   100,   113,    91,    25,   116,   118,   117,   164,   165,
     166,   167,   168,   113,    19,    31,     1,    26,    92,   -83,
     176,   144,   197,    99,     6,    38,    20,   191,   205,   101,
     180,   181,   -84,   120,   194,   198,    86,    10,   123,   105,
     106,   -83,   -83,   -83,   145,   146,    49,   107,    51,     5,
      87,   126,   136,   138,   -84,   -84,   -84,   114,   211,     7,
      11,   119,   113,   108,   172,     1,    87,    53,   114,   216,
      13,   118,   218,    56,    57,    58,    15,   176,    87,   179,
     109,   161,   118,   118,   118,   118,   118,   128,    21,   120,
      23,   131,   132,   190,   118,   177,   145,   146,   154,   113,
     113,   113,   113,   113,   113,   113,   113,   118,   126,   154,
     154,   154,   154,   154,   115,   196,    27,   142,    28,   126,
      32,   154,    88,    33,    93,   115,   182,   183,   184,   185,
     186,   187,    94,    96,   188,   210,   162,   212,    97,   126,
     215,   126,   102,   103,   126,   113,   126,   104,   217,   124,
     134,   118,   135,   127,   114,   114,   114,   114,   114,   114,
     114,   114,   128,   -94,   129,   130,   131,   132,   137,   133,
     203,   139,   140,   143,   115,   117,   173,  -108,   154,  -108,
    -108,  -108,  -108,    38,   189,   147,   148,   149,   150,   151,
     152,   157,   169,   163,   159,   156,   171,    46,    47,   178,
     114,   191,   195,   199,    49,   107,    51,   145,   157,   208,
     204,   115,   115,   115,   115,   115,   115,   115,   115,    36,
       9,    52,    37,    35,    38,    53,    39,    40,    41,    42,
      43,    56,    57,    58,   213,    44,    45,   209,    46,    47,
      48,   207,     0,     0,   125,    49,    50,    51,  -108,     0,
    -108,  -108,  -108,  -108,     0,     0,   128,   115,   129,   130,
     131,   132,    52,     0,     0,     0,    53,    54,     0,    55,
       0,     0,    56,    57,    58,    59,     0,    36,     0,     0,
      37,    60,    38,     0,    39,    40,    41,    42,    43,     0,
       0,     0,   158,    44,    45,     0,    46,    47,    48,     0,
       0,     0,     0,    49,    50,    51,  -110,     0,  -110,  -110,
    -110,  -110,  -109,     0,  -109,  -109,  -109,  -109,     0,     0,
      52,     0,     0,     0,    53,    54,     0,    55,     0,     0,
      56,    57,    58,    59,     0,    36,     0,     0,    37,    60,
      38,     0,    39,    40,    41,    42,    43,     0,     0,     0,
       0,    44,    45,     0,    46,    47,    48,     0,   200,     0,
       0,    49,    50,    51,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    52,     0,
       0,     0,    53,    54,     0,    55,     0,     0,    56,    57,
      58,    59,     0,    36,     0,     0,    37,    60,    38,     0,
      39,    40,    41,    42,    43,     0,     0,     0,     0,    44,
      45,     0,    46,    47,    48,   202,     0,     0,     0,    49,
      50,    51,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    52,     0,     0,     0,
      53,    54,     0,    55,     0,     0,    56,    57,    58,    59,
       0,    36,     0,     0,    37,    60,    38,     0,    39,    40,
      41,    42,    43,     0,     0,     0,     0,    44,    45,     0,
      46,    47,    48,     0,     0,   204,     0,    49,    50,    51,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    52,     0,     0,     0,    53,    54,
       0,    55,     0,     0,    56,    57,    58,    59,     0,    36,
       0,     0,    37,    60,    38,     0,    39,    40,    41,    42,
      43,     0,     0,     0,     0,    44,    45,     0,    46,    47,
      48,     0,     0,     0,     0,    49,    50,    51,     0,     0,
       0,     0,    46,    47,     0,     0,     0,     0,     0,    49,
     107,    51,    52,     0,     0,     0,    53,    54,     0,    55,
       0,     0,    56,    57,    58,    59,   153,     0,     0,     0,
      53,    60,     0,     0,     0,     0,    56,    57,    58
};

static const yytype_int16 yycheck[] =
{
      55,    62,    31,   108,    28,    31,    54,   117,   135,    40,
      40,    31,    48,    40,    35,    53,    52,    55,   128,   129,
     130,   131,   132,    59,    55,    55,    22,    48,    55,    26,
     140,    26,    35,    59,     0,     9,    29,    61,    62,    59,
     145,   146,    26,    52,   171,    48,    56,    47,    59,    23,
      24,    48,    49,    50,    49,    50,    30,    31,    32,    31,
      70,   122,    56,    92,    48,    49,    50,    48,   201,    16,
      31,    52,   108,    47,    56,    22,    70,    51,    59,   212,
      10,   117,   215,    57,    58,    59,    31,   197,    70,   144,
      64,   127,   128,   129,   130,   131,   132,    34,    31,   108,
      17,    38,    39,   158,   140,    48,    49,    50,   117,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   179,   128,
     129,   130,   131,   132,    48,   173,    51,   108,    32,   190,
      29,   140,    51,    31,    29,    59,   147,   148,   149,   150,
     151,   152,    32,    30,   153,   200,   127,   202,    31,   210,
     205,   212,    32,    31,   215,   191,   217,    31,   213,    51,
      32,   197,     6,    40,   145,   146,   147,   148,   149,   150,
     151,   152,    34,    40,    36,    37,    38,    39,    30,    40,
     191,    35,    47,    47,   108,    55,     6,    34,   197,    36,
      37,    38,    39,     9,    56,    41,    42,    43,    44,    45,
      46,    48,    51,   127,    63,    48,    40,    23,    24,    32,
     191,    61,    40,    48,    30,    31,    32,    49,    48,    30,
      28,   145,   146,   147,   148,   149,   150,   151,   152,     4,
       3,    47,     7,    25,     9,    51,    11,    12,    13,    14,
      15,    57,    58,    59,    53,    20,    21,   197,    23,    24,
      25,   192,    -1,    -1,    29,    30,    31,    32,    34,    -1,
      36,    37,    38,    39,    -1,    -1,    34,   191,    36,    37,
      38,    39,    47,    -1,    -1,    -1,    51,    52,    -1,    54,
      -1,    -1,    57,    58,    59,    60,    -1,     4,    -1,    -1,
       7,    66,     9,    -1,    11,    12,    13,    14,    15,    -1,
      -1,    -1,    19,    20,    21,    -1,    23,    24,    25,    -1,
      -1,    -1,    -1,    30,    31,    32,    34,    -1,    36,    37,
      38,    39,    34,    -1,    36,    37,    38,    39,    -1,    -1,
      47,    -1,    -1,    -1,    51,    52,    -1,    54,    -1,    -1,
      57,    58,    59,    60,    -1,     4,    -1,    -1,     7,    66,
       9,    -1,    11,    12,    13,    14,    15,    -1,    -1,    -1,
      -1,    20,    21,    -1,    23,    24,    25,    -1,    27,    -1,
      -1,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,
      -1,    -1,    51,    52,    -1,    54,    -1,    -1,    57,    58,
      59,    60,    -1,     4,    -1,    -1,     7,    66,     9,    -1,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    -1,    20,
      21,    -1,    23,    24,    25,    26,    -1,    -1,    -1,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,
      51,    52,    -1,    54,    -1,    -1,    57,    58,    59,    60,
      -1,     4,    -1,    -1,     7,    66,     9,    -1,    11,    12,
      13,    14,    15,    -1,    -1,    -1,    -1,    20,    21,    -1,
      23,    24,    25,    -1,    -1,    28,    -1,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,    51,    52,
      -1,    54,    -1,    -1,    57,    58,    59,    60,    -1,     4,
      -1,    -1,     7,    66,     9,    -1,    11,    12,    13,    14,
      15,    -1,    -1,    -1,    -1,    20,    21,    -1,    23,    24,
      25,    -1,    -1,    -1,    -1,    30,    31,    32,    -1,    -1,
      -1,    -1,    23,    24,    -1,    -1,    -1,    -1,    -1,    30,
      31,    32,    47,    -1,    -1,    -1,    51,    52,    -1,    54,
      -1,    -1,    57,    58,    59,    60,    47,    -1,    -1,    -1,
      51,    66,    -1,    -1,    -1,    -1,    57,    58,    59
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    22,    72,    80,    81,    31,     0,    16,    76,    81,
      47,    31,    77,    10,    73,    31,    82,    83,    40,    55,
      29,    31,    74,    17,    78,    35,    48,    51,    32,    85,
      40,    55,    29,    31,    79,    83,     4,     7,     9,    11,
      12,    13,    14,    15,    20,    21,    23,    24,    25,    30,
      31,    32,    47,    51,    52,    54,    57,    58,    59,    60,
      66,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,   100,   102,   103,   104,   110,   111,   113,
     114,   115,   116,   117,   118,   119,    56,    70,    51,    75,
      85,    40,    55,    29,    32,    99,    30,    31,    31,    59,
      31,    59,    32,    31,    31,    23,    24,    31,    47,    64,
     101,   108,   109,   114,   115,   118,    53,    55,   114,   115,
     116,    99,    88,   109,    51,    29,   102,    40,    34,    36,
      37,    38,    39,    40,    32,     6,    56,    30,    85,    35,
      47,   108,   115,    47,    26,    49,    50,    41,    42,    43,
      44,    45,    46,    47,   116,   117,    48,    48,    19,    63,
     112,   114,   115,   118,   117,   117,   117,   117,   117,    51,
      75,    40,    56,     6,    84,    86,   117,    48,    32,    88,
     108,   108,   109,   109,   109,   109,   109,   109,   116,    56,
      88,    61,   120,   121,    75,    40,    99,    35,    48,    48,
      27,   105,    26,   109,    28,    62,   106,   121,    30,    84,
      88,   106,    88,    53,   107,    88,   106,    88,   106
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    71,    72,    73,    73,    74,    74,    75,    75,    76,
      76,    77,    77,    78,    78,    79,    79,    80,    80,    80,
      81,    82,    82,    82,    83,    84,    85,    85,    86,    86,
      86,    87,    88,    88,    89,    90,    91,    92,    92,    93,
      93,    94,    95,    96,    97,    98,    99,    99,   100,   101,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   103,   104,   105,
     105,   105,   106,   107,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   109,   109,   109,   110,
     111,   112,   112,   112,   113,   114,   114,   114,   114,   115,
     115,   115,   116,   116,   116,   116,   116,   116,   117,   117,
     117,   118,   118,   118,   118,   118,   118,   119,   119,   120,
     120,   121
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     0,     3,     3,     6,     1,     3,     0,
       3,     3,     6,     0,     3,     3,     6,     0,     1,     2,
       7,     0,     3,     1,     1,     1,     1,     3,     3,     1,
       0,     5,     2,     1,     2,     2,     2,     2,     2,     2,
       2,     2,     1,     2,     2,     2,     1,     4,     2,     4,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     7,     6,     0,
       2,     1,     2,     0,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     4,     1,     1,     3,
       1,     1,     3,     3,     3,     3,     3,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     7,     5,     1,
       2,     4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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
      yyerror (&yylloc, parm, YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

__attribute__((__unused__))
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location, parm); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, void * parm)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  YYUSE (parm);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, void * parm)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, parm);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, void * parm)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       , parm);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, parm); \
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
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
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

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
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, void * parm)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (parm);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void * parm)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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
      yychar = yylex (&yylval, &yylloc, parm);
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
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
| yyreduce -- Do a reduction.  |
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:
#line 186 "fake\\parser.y" /* yacc.c:1646  */
    {
	}
#line 1639 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 189 "fake\\parser.y" /* yacc.c:1646  */
    {}
#line 1645 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 194 "fake\\parser.y" /* yacc.c:1646  */
    {
	myflexer *l = (myflexer *)parm;
	}
#line 1653 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 199 "fake\\parser.y" /* yacc.c:1646  */
    {
	myflexer *l = (myflexer *)parm;
	}
#line 1661 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 205 "fake\\parser.y" /* yacc.c:1646  */
    {}
#line 1667 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 206 "fake\\parser.y" /* yacc.c:1646  */
    {}
#line 1673 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 211 "fake\\parser.y" /* yacc.c:1646  */
    {
	}
#line 1680 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 214 "fake\\parser.y" /* yacc.c:1646  */
    {}
#line 1686 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 219 "fake\\parser.y" /* yacc.c:1646  */
    {
		/*FKLOG("[bison]: const_define %s", $1.c_str());
		myflexer *l = (myflexer *)parm;
		l->add_const_desc($1.c_str(), $3);*/
		myflexer *l = (myflexer *)parm;
	}
#line 1697 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 227 "fake\\parser.y" /* yacc.c:1646  */
    {
	myflexer *l = (myflexer *)parm;
	}
#line 1705 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 234 "fake\\parser.y" /* yacc.c:1646  */
    {
	}
#line 1712 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 238 "fake\\parser.y" /* yacc.c:1646  */
    {
	}
#line 1719 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 244 "fake\\parser.y" /* yacc.c:1646  */
    {
		NEWTYPE(p, strings_define);
		p->var = (yyvsp[0].str);
		(yyval.syntree) = p;

		myflexer *l = (myflexer *)parm;
	}
#line 1731 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 253 "fake\\parser.y" /* yacc.c:1646  */
    {
		NEWTYPE(p, strings_define);
		p->var = (yyvsp[0].str);
		(yyval.syntree) = p;
		myflexer *l = (myflexer *)parm;

	}
#line 1743 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 265 "fake\\parser.y" /* yacc.c:1646  */
    {
	}
#line 1750 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 278 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: function_declaration <- block %s %d", (yyvsp[-5].str).c_str(), yylloc.first_line);
		NEWTYPE(p, func_desc_node);
		p->funcname = (yyvsp[-5].str);
		p->arglist = dynamic_cast<func_desc_arglist_node*>((yyvsp[-3].syntree));
		p->block = dynamic_cast<block_node*>((yyvsp[-1].syntree));
		p->endline = yylloc.first_line;
		myflexer *l = (myflexer *)parm;
		l->add_func_desc(p);
	}
#line 1765 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 292 "fake\\parser.y" /* yacc.c:1646  */
    {
		(yyval.syntree) = 0;
	}
#line 1773 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 297 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: function_declaration_arguments <- arg function_declaration_arguments");
		assert((yyvsp[-2].syntree)->gettype() == est_arglist);
		func_desc_arglist_node * p = dynamic_cast<func_desc_arglist_node*>((yyvsp[-2].syntree));
		p->add_arg((yyvsp[0].syntree));
		(yyval.syntree) = p;
	}
#line 1785 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 306 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: function_declaration_arguments <- arg");
		NEWTYPE(p, func_desc_arglist_node);
		p->add_arg((yyvsp[0].syntree));
		(yyval.syntree) = p;
	}
#line 1796 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 316 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: arg <- IDENTIFIER %s", (yyvsp[0].str).c_str());
		NEWTYPE(p, identifier_node);
		p->str = (yyvsp[0].str);
		(yyval.syntree) = p;
	}
#line 1807 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 326 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: arg_expr <- expr_value");
		(yyval.syntree) = (yyvsp[0].syntree);
	}
#line 1816 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 333 "fake\\parser.y" /* yacc.c:1646  */
    { }
#line 1822 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 334 "fake\\parser.y" /* yacc.c:1646  */
    {}
#line 1828 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 344 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: function_call_arguments <- arg_expr function_call_arguments");
		assert((yyvsp[-2].syntree)->gettype() == est_call_arglist);
		function_call_arglist_node * p = dynamic_cast<function_call_arglist_node*>((yyvsp[-2].syntree));
		p->add_arg((yyvsp[0].syntree));
		(yyval.syntree) = p;
	}
#line 1840 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 353 "fake\\parser.y" /* yacc.c:1646  */
    {

		FKLOG("[bison]: function_call_arguments <- arg_expr");
		NEWTYPE(p, function_call_arglist_node);
		p->add_arg((yyvsp[0].syntree));
		(yyval.syntree) = p;
	}
#line 1852 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 362 "fake\\parser.y" /* yacc.c:1646  */
    {
		(yyval.syntree) = 0;
	}
#line 1860 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 369 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: function_call <- function_call_arguments %s", (yyvsp[-3].str).c_str());
		NEWTYPE(p, function_call_node);
		p->fuc = (yyvsp[-3].str);
		p->prefunc = 0;
		p->arglist = dynamic_cast<function_call_arglist_node*>((yyvsp[-1].syntree));
		p->fakecall = false;
		p->classmem_call = false;
		(yyval.syntree) = p;
	}
#line 1875 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 386 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: block <- block stmt");
		assert((yyvsp[-1].syntree)->gettype() == est_block);
		block_node * p = dynamic_cast<block_node*>((yyvsp[-1].syntree));
		p->add_stmt((yyvsp[0].syntree));
		(yyval.syntree) = p;
	}
#line 1887 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 395 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: block <- stmt");
		NEWTYPE(p, block_node);
		p->add_stmt((yyvsp[0].syntree));
		(yyval.syntree) = p;
	}
#line 1898 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 405 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: stmt <- GOTO_stm");
		NEWTYPE(p, GOTO_stm);
		p->var = (yyvsp[0].str);
		(yyval.syntree) = p;
	}
#line 1909 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 415 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: stmt <- LABEL_stm");
		NEWTYPE(p, LABEL_stm);
		p->var = (yyvsp[-1].str);
		(yyval.syntree) = p;
	}
#line 1920 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 425 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: stmt <- HOME_stm");
		NEWTYPE(p, HOME_stm);
		p->var = (yyvsp[0].str);
		(yyval.syntree) = p;
	}
#line 1931 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 435 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: stmt <- BASE_stm");
		NEWTYPE(p, BASE_stm);
		p->var = (yyvsp[0].str);
		(yyval.syntree) = p;
	}
#line 1942 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 443 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: stmt <- BASE_stm");
		NEWTYPE(p, BASE_stm);
		p->var = (yyvsp[0].str);
		(yyval.syntree) = p;
	}
#line 1953 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 453 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: stmt <- TOOL_stm");
		NEWTYPE(p, TOOL_stm);
		p->var = (yyvsp[0].str);
		(yyval.syntree) = p;
	}
#line 1964 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 461 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: stmt <- TOOL_stm");
		NEWTYPE(p, TOOL_stm);
		p->var = (yyvsp[0].str);
		(yyval.syntree) = p;
	}
#line 1975 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 471 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: stmt <- TYPE_stm");
		NEWTYPE(p, TYPE_stm);
		p->var = (yyvsp[0].str);
		(yyval.syntree) = p;
	}
#line 1986 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 481 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: stmt <- STOP_stm");
		NEWTYPE(p, STOP_stm);
		(yyval.syntree) = p;
	}
#line 1996 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 490 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: stmt <- JMOVE_stm");
		NEWTYPE(p, JMOVE_stm);
		p->var = (yyvsp[0].str);
		(yyval.syntree) = p;
	}
#line 2007 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 500 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: stmt <- TWAIT_stm");
		NEWTYPE(p, TWAIT_stm);
		p->var = (yyvsp[0].str);
		(yyval.syntree) = p;
	}
#line 2018 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 510 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: stmt <- SWAIT_stm");
		NEWTYPE(p, SWAIT_stm);
		p->var = (yyvsp[0].str);
		(yyval.syntree) = p;
	}
#line 2029 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 520 "fake\\parser.y" /* yacc.c:1646  */
    {
		(yyval.str) =  (yyvsp[0].str);
	}
#line 2037 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 524 "fake\\parser.y" /* yacc.c:1646  */
    {
		(yyval.str);	
	}
#line 2045 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 531 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: stmt <- SIGNAL_stm");
		NEWTYPE(p, SIGNAL_stm);
		p->var = (yyvsp[0].str);
		(yyval.syntree) = p;
	}
#line 2056 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 541 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: stmt <- SIG_stm");
		NEWTYPE(p, SIGNAL_stm);
		p->var = (yyvsp[-1].str);
		(yyval.syntree) = p;
	}
#line 2067 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 550 "fake\\parser.y" /* yacc.c:1646  */
    { FKLOG("[bison]: stmt <- SWAIT_stm");(yyval.syntree) = (yyvsp[0].syntree);}
#line 2073 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 551 "fake\\parser.y" /* yacc.c:1646  */
    {FKLOG("[bison]: stmt <- TWAIT_stm");(yyval.syntree) = (yyvsp[0].syntree);}
#line 2079 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 552 "fake\\parser.y" /* yacc.c:1646  */
    {FKLOG("[bison]: stmt <- STOP_stm");(yyval.syntree) = (yyvsp[0].syntree);}
#line 2085 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 553 "fake\\parser.y" /* yacc.c:1646  */
    {FKLOG("[bison]: stmt <- JMOVE_stm");(yyval.syntree) = (yyvsp[0].syntree);}
#line 2091 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 554 "fake\\parser.y" /* yacc.c:1646  */
    {FKLOG("[bison]: stmt <- BASE_stm");(yyval.syntree) = (yyvsp[0].syntree);}
#line 2097 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 555 "fake\\parser.y" /* yacc.c:1646  */
    {FKLOG("[bison]: stmt <- TOOL_stm");(yyval.syntree) = (yyvsp[0].syntree);}
#line 2103 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 556 "fake\\parser.y" /* yacc.c:1646  */
    {FKLOG("[bison]: stmt <- HOME_stm");(yyval.syntree) = (yyvsp[0].syntree);}
#line 2109 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 557 "fake\\parser.y" /* yacc.c:1646  */
    {FKLOG("[bison]: stmt <- GOTO_stm");(yyval.syntree) = (yyvsp[0].syntree);}
#line 2115 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 558 "fake\\parser.y" /* yacc.c:1646  */
    {FKLOG("[bison]: stmt <- TYPE_stm");(yyval.syntree) = (yyvsp[0].syntree);}
#line 2121 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 559 "fake\\parser.y" /* yacc.c:1646  */
    {FKLOG("[bison]: stmt <- LABEL_stm");(yyval.syntree) = (yyvsp[0].syntree);}
#line 2127 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 560 "fake\\parser.y" /* yacc.c:1646  */
    {FKLOG("[bison]: stmt <- SIGNAL_stm");(yyval.syntree) = (yyvsp[0].syntree);}
#line 2133 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 563 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: stmt <- return_stmt");
		(yyval.syntree) = (yyvsp[0].syntree);
	}
#line 2142 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 569 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: stmt <- assign_stmt");
		(yyval.syntree) = (yyvsp[0].syntree);
	}
#line 2151 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 575 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: stmt <- expr");
		(yyval.syntree) = (yyvsp[0].syntree);
	}
#line 2160 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 582 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: stmt <- if_stmt");
		(yyval.syntree) = (yyvsp[0].syntree);
	}
#line 2169 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 588 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: stmt <- for_stmt");
		(yyval.syntree) = (yyvsp[0].syntree);
	}
#line 2178 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 594 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: stmt <- switch_stmt");
		(yyval.syntree) = (yyvsp[0].syntree);
	}
#line 2187 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 602 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: for_stmt <- block cmp block");
		NEWTYPE(p, for_stmt);
		p->beginblock = dynamic_cast<block_node*>((yyvsp[-5].syntree));
		p->endblock = dynamic_cast<block_node*>((yyvsp[-3].syntree));
		p->block = dynamic_cast<block_node*>((yyvsp[-1].syntree));
		(yyval.syntree) = p;
	}
#line 2200 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 614 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: if_stmt <- cmp block");
		NEWTYPE(p, if_stmt);
		p->cmp = dynamic_cast<cmp_stmt*>((yyvsp[-4].syntree));
		p->block = dynamic_cast<block_node*>((yyvsp[-2].syntree));
		p->elses = dynamic_cast<else_stmt*>((yyvsp[-1].syntree));
		p->elseifs = NULL;
		(yyval.syntree) = p;
	}
#line 2214 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 627 "fake\\parser.y" /* yacc.c:1646  */
    {
		(yyval.syntree) = 0;
	}
#line 2222 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 632 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: else_stmt <- block");
		NEWTYPE(p, else_stmt);
		p->block = dynamic_cast<block_node*>((yyvsp[0].syntree));
		(yyval.syntree) = p;
	}
#line 2233 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 640 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: else_stmt <- empty");
		NEWTYPE(p, else_stmt);
		p->block = 0;
		(yyval.syntree) = p;
	}
#line 2244 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 659 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: cmp <- ( cmp )");
		(yyval.syntree) = (yyvsp[-1].syntree);
	}
#line 2253 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 665 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: cmp <- cmp AND cmp");
		NEWTYPE(p, cmp_stmt);
		p->cmp = "&&";
		p->left = (yyvsp[-2].syntree);
		p->right = (yyvsp[0].syntree);
		(yyval.syntree) = p;
	}
#line 2266 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 675 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: cmp <- cmp OR cmp");
		NEWTYPE(p, cmp_stmt);
		p->cmp = "||";
		p->left = (yyvsp[-2].syntree);
		p->right = (yyvsp[0].syntree);
		(yyval.syntree) = p;
	}
#line 2279 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 685 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: cmp <- cmp_value LESS cmp_value");
		NEWTYPE(p, cmp_stmt);
		p->cmp = (yyvsp[-1].str);
		p->left = (yyvsp[-2].syntree);
		p->right = (yyvsp[0].syntree);
		(yyval.syntree) = p;
	}
#line 2292 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 695 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: cmp <- cmp_value MORE cmp_value");
		NEWTYPE(p, cmp_stmt);
		p->cmp = (yyvsp[-1].str);
		p->left = (yyvsp[-2].syntree);
		p->right = (yyvsp[0].syntree);
		(yyval.syntree) = p;
	}
#line 2305 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 705 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: cmp <- cmp_value EQUAL cmp_value");
		NEWTYPE(p, cmp_stmt);
		p->cmp = (yyvsp[-1].str);
		p->left = (yyvsp[-2].syntree);
		p->right = (yyvsp[0].syntree);
		(yyval.syntree) = p;
	}
#line 2318 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 715 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: cmp <- cmp_value MORE_OR_EQUAL cmp_value");
		NEWTYPE(p, cmp_stmt);
		p->cmp = (yyvsp[-1].str);
		p->left = (yyvsp[-2].syntree);
		p->right = (yyvsp[0].syntree);
		(yyval.syntree) = p;
	}
#line 2331 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 725 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: cmp <- cmp_value LESS_OR_EQUAL cmp_value");
		NEWTYPE(p, cmp_stmt);
		p->cmp = (yyvsp[-1].str);
		p->left = (yyvsp[-2].syntree);
		p->right = (yyvsp[0].syntree);
		(yyval.syntree) = p;
	}
#line 2344 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 735 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: cmp <- cmp_value NOT_EQUAL cmp_value");
		NEWTYPE(p, cmp_stmt);
		p->cmp = (yyvsp[-1].str);
		p->left = (yyvsp[-2].syntree);
		p->right = (yyvsp[0].syntree);
		(yyval.syntree) = p;
	}
#line 2357 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 745 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: cmp <- true");
		NEWTYPE(p, cmp_stmt);
		p->cmp = "true";
		p->left = 0;
		p->right = 0;
		(yyval.syntree) = p;
	}
#line 2370 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 755 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: cmp <- false");
		NEWTYPE(p, cmp_stmt);
		p->cmp = "false";
		p->left = 0;
		p->right = 0;
		(yyval.syntree) = p;
	}
#line 2383 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 765 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: cmp <- false");
		(yyval.syntree) = (yyvsp[0].syntree);
	}
#line 2392 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 779 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: cmp_value <- explicit_value");
		(yyval.syntree) = (yyvsp[0].syntree);
	}
#line 2401 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 785 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: cmp_value <- variable");
		(yyval.syntree) = (yyvsp[0].syntree);
	}
#line 2410 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 791 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: cmp_value <- expr");
		(yyval.syntree) = (yyvsp[0].syntree);
	}
#line 2419 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 799 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: return_stmt <- RETURN");
		NEWTYPE(p, return_stmt);
		p->returnlist = 0;
		(yyval.syntree) = p;
	}
#line 2430 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 809 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: assign_stmt <- var assign_value");
		NEWTYPE(p, assign_stmt);
		p->var = (yyvsp[-2].syntree);
		p->value = (yyvsp[0].syntree);
		p->isnew = false;
		(yyval.syntree) = p;
	}
#line 2443 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 821 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: assign_value <- explicit_value");
		(yyval.syntree) = (yyvsp[0].syntree);
	}
#line 2452 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 827 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: assign_value <- variable");
		(yyval.syntree) = (yyvsp[0].syntree);
	}
#line 2461 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 833 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: assign_value <- expr");
		(yyval.syntree) = (yyvsp[0].syntree);
	}
#line 2470 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 841 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: var <- variable");
		(yyval.syntree) = (yyvsp[0].syntree);
	}
#line 2479 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 849 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: variable <- IDENTIFIER %s", (yyvsp[0].str).c_str());
		NEWTYPE(p, variable_node);
		p->str = (yyvsp[0].str);
		(yyval.syntree) = p;
	}
#line 2490 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 857 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: container_get_node <- IDENTIFIER[expr_value] %s", (yyvsp[-3].str).c_str());
		NEWTYPE(p, container_get_node);
		p->container = (yyvsp[-3].str);
		p->key = (yyvsp[-1].syntree);
		(yyval.syntree) = p;
	}
#line 2502 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 866 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: variable <- IDENTIFIER_POINTER %s", (yyvsp[0].str).c_str());
		NEWTYPE(p, struct_pointer_node);
		p->str = (yyvsp[0].str);
		(yyval.syntree) = p;
	}
#line 2513 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 874 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: variable <- IDENTIFIER_DOT %s", (yyvsp[0].str).c_str());
		NEWTYPE(p, variable_node);
		p->str = (yyvsp[0].str);
		(yyval.syntree) = p;
	}
#line 2524 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 884 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: expr <- (expr)");
		(yyval.syntree) = (yyvsp[-1].syntree);
	}
#line 2533 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 890 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: expr <- function_call");
		(yyval.syntree) = (yyvsp[0].syntree);
	}
#line 2542 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 896 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: expr <- math_expr");
		(yyval.syntree) = (yyvsp[0].syntree);
	}
#line 2551 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 904 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: math_expr <- (math_expr)");
		(yyval.syntree) = (yyvsp[-1].syntree);
	}
#line 2560 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 910 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: math_expr <- expr_value %s expr_value", (yyvsp[-1].str).c_str());
		NEWTYPE(p, math_expr_node);
		p->oper = "+";
		p->left = (yyvsp[-2].syntree);
		p->right = (yyvsp[0].syntree);
		(yyval.syntree) = p;
	}
#line 2573 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 920 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: math_expr <- expr_value %s expr_value", (yyvsp[-1].str).c_str());
		NEWTYPE(p, math_expr_node);
		p->oper = "-";
		p->left = (yyvsp[-2].syntree);
		p->right = (yyvsp[0].syntree);
		(yyval.syntree) = p;
	}
#line 2586 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 930 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: math_expr <- expr_value %s expr_value", (yyvsp[-1].str).c_str());
		NEWTYPE(p, math_expr_node);
		p->oper = "*";
		p->left = (yyvsp[-2].syntree);
		p->right = (yyvsp[0].syntree);
		(yyval.syntree) = p;
	}
#line 2599 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 940 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: math_expr <- expr_value %s expr_value", (yyvsp[-1].str).c_str());
		NEWTYPE(p, math_expr_node);
		p->oper = "/";
		p->left = (yyvsp[-2].syntree);
		p->right = (yyvsp[0].syntree);
		(yyval.syntree) = p;
	}
#line 2612 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 950 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: math_expr <- expr_value %s expr_value", (yyvsp[-1].str).c_str());
		NEWTYPE(p, math_expr_node);
		p->oper = "%";
		p->left = (yyvsp[-2].syntree);
		p->right = (yyvsp[0].syntree);
		(yyval.syntree) = p;
	}
#line 2625 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 962 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: expr_value <- math_expr");
		(yyval.syntree) = (yyvsp[0].syntree);
	}
#line 2634 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 968 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: expr_value <- explicit_value");
		(yyval.syntree) = (yyvsp[0].syntree);
	}
#line 2643 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 974 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: expr_value <- variable");
		(yyval.syntree) = (yyvsp[0].syntree);
	}
#line 2652 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 1009 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: explicit_value <- FTRUE");
		NEWTYPE(p, explicit_value_node);
		p->str = (yyvsp[0].str);
		p->type = explicit_value_node::EVT_TRUE;
		(yyval.syntree) = p;
	}
#line 2664 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 1018 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: explicit_value <- FFALSE");
		NEWTYPE(p, explicit_value_node);
		p->str = (yyvsp[0].str);
		p->type = explicit_value_node::EVT_FALSE;
		(yyval.syntree) = p;
	}
#line 2676 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 1027 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: explicit_value <- NUMBER %s", (yyvsp[0].str).c_str());
		NEWTYPE(p, explicit_value_node);
		p->str = (yyvsp[0].str);
		p->type = explicit_value_node::EVT_NUM;
		(yyval.syntree) = p;
	}
#line 2688 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 1036 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: explicit_value <- STRING_DEFINITION %s", (yyvsp[0].str).c_str());
		NEWTYPE(p, explicit_value_node);
		p->str = (yyvsp[0].str);
		p->type = explicit_value_node::EVT_STR;
		(yyval.syntree) = p;
	}
#line 2700 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 1045 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: explicit_value <- FKFLOAT %s", (yyvsp[0].str).c_str());
		NEWTYPE(p, explicit_value_node);
		p->str = (yyvsp[0].str);
		p->type = explicit_value_node::EVT_FLOAT;
		(yyval.syntree) = p;
	}
#line 2712 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 1054 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: explicit_value <- FNULL %s", (yyvsp[0].str).c_str());
		NEWTYPE(p, explicit_value_node);
		p->str = (yyvsp[0].str);
		p->type = explicit_value_node::EVT_NULL;
		(yyval.syntree) = p;
	}
#line 2724 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 1076 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: switch_stmt");
		NEWTYPE(p, switch_stmt);
		p->cmp = (yyvsp[-5].syntree);
		p->caselist = (yyvsp[-3].syntree);
		p->def = (yyvsp[-1].syntree);
		(yyval.syntree) = p;
	}
#line 2737 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 1086 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: switch_stmt");
		NEWTYPE(p, switch_stmt);
		p->cmp = (yyvsp[-3].syntree);
		p->caselist = (yyvsp[-1].syntree);
		p->def = 0;
		(yyval.syntree) = p;
	}
#line 2750 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 1098 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: switch_case_list <- switch_case_define");
		NEWTYPE(p, switch_caselist_node);
		p->add_case((yyvsp[0].syntree));
		(yyval.syntree) = p;
	}
#line 2761 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 1106 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: switch_case_list <- switch_case_list switch_case_define");
		assert((yyvsp[0].syntree)->gettype() == est_switch_case_node);
		switch_caselist_node * p = dynamic_cast<switch_caselist_node*>((yyvsp[-1].syntree));
		p->add_case((yyvsp[0].syntree));
		(yyval.syntree) = p;
	}
#line 2773 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 1117 "fake\\parser.y" /* yacc.c:1646  */
    {
		FKLOG("[bison]: switch_case_define");
		NEWTYPE(p, switch_case_node);
		p->cmp = (yyvsp[-2].syntree);
		p->block = (yyvsp[0].syntree);
		(yyval.syntree) = p;
	}
#line 2785 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
    break;


#line 2789 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\fake\\bison.cpp" /* yacc.c:1646  */
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
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
      yyerror (&yylloc, parm, YY_("syntax error"));
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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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
        yyerror (&yylloc, parm, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc, parm);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp, parm);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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
  yyerror (&yylloc, parm, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc, parm);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp, parm);
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
