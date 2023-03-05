/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
