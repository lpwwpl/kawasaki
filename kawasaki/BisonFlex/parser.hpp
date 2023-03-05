// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton interface for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2013 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

/**
 ** \file D:\FreeCAD-0.19.1-build\src\Mod\kawasaki\kawasaki\\kawasaki\BisonFlex\parser.hpp
 ** Define the moon::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

#ifndef YY_YY_D_FREECAD_0_19_1_BUILD_SRC_MOD_KAWASAKI_KAWASAKI_KAWASAKI_BISONFLEX_PARSER_HPP_INCLUDED
# define YY_YY_D_FREECAD_0_19_1_BUILD_SRC_MOD_KAWASAKI_KAWASAKI_KAWASAKI_BISONFLEX_PARSER_HPP_INCLUDED
// //                    "%code requires" blocks.
#line 43 "BisonFlex\\parser.y" // lalr1.cc:371


#define INC_PARSER 1
#include "common.hpp"
#undef  INC_PARSER


#line 52 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\BisonFlex\\parser.hpp" // lalr1.cc:371

# include <cassert>
# include <vector>
# include <iostream>
# include <stdexcept>
# include <string>
# include "stack.hh"



/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

#line 17 "BisonFlex\\parser.y" // lalr1.cc:371
namespace moon {
#line 70 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\BisonFlex\\parser.hpp" // lalr1.cc:371





  /// A Bison parser.
  class Parser
  {
  public:
#ifndef YYSTYPE
    /// Symbol semantic values.

#else
    typedef YYSTYPE semantic_type;
#endif

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const std::string& m);
    };

    /// Tokens.
    struct token
    {
      enum yytokentype
      {
        END_OF_FILE = 0,
        OP_ASSIGN = 258,
        OP_PLUS = 259,
        OP_MINUS = 260,
        OP_MULTIPLY = 261,
        OP_DIVIDE = 262,
        OP_MODULO = 263,
        OP_PLUS_ASSIGN = 264,
        OP_MINUS_ASSIGN = 265,
        OP_MULTIPLY_ASSIGN = 266,
        OP_DIVIDE_ASSIGN = 267,
        OP_MODULO_ASSIGN = 268,
        OP_CMP_GREATER_THAN = 269,
        OP_CMP_LESS_THAN = 270,
        OP_CMP_GREATER_EQUAL = 271,
        OP_CMP_LESS_EQUAL = 272,
        OP_CMP_EQUAL = 273,
        OP_CMP_NOT_EQUAL = 274,
        OP_LOGIC_AND = 275,
        OP_LOGIC_OR = 276,
        OP_LOGIC_NOT = 277,
        TID_INT = 278,
        TID_LONG = 279,
        TID_FLT = 280,
        TID_DBL = 281,
        TID_BOOL = 282,
        TID_STR = 283,
        TID_ARRAY = 284,
        TID_RANGE = 285,
        TID_ANY = 286,
        TID_TYPEID = 287,
        TID_FUNC = 288,
        KW_IMPORT = 289,
        KW_IF = 290,
        KW_THEN = 291,
        KW_ELSE = 292,
        KW_ELSEIF = 293,
        KW_END = 294,
        KW_RETURN = 295,
        KW_LET = 296,
        KW_FUNC = 297,
        KW_MATCH = 298,
        KW_WITH = 299,
        KW_CASE = 300,
        KW_DEFAULT = 301,
        KW_IN = 302,
        KW_DO = 303,
        KW_FOR = 304,
        KW_WHILE = 305,
        KW_LOOP = 306,
        KW_BREAK = 307,
        KW_CONTINUE = 308,
        KW_TYPE = 309,
        KW_ENUM = 310,
        KW_STRUCT = 311,
        KW_TYPEOF = 312,
        KW_AS = 313,
        KW_NULL = 314,
        INT_LITERAL = 315,
        FLT_LITERAL = 316,
        BOOL_LITERAL = 317,
        STR_LITERAL = 318,
        MEMBER_REF = 319,
        OPEN_PAR = 320,
        CLOSE_PAR = 321,
        OPEN_CBRAC = 322,
        CLOSE_CBRAC = 323,
        OPEN_BRAC = 324,
        CLOSE_BRAC = 325,
        COMMA = 326,
        SEMICOLON = 327,
        COLON = 328,
        RANGE = 329,
        VARARGS = 330,
        ARROW = 331,
        IDENTIFIER = 332,
        UNARY_MINUS = 333,
        UNARY_PLUS = 334
      };
    };

    /// (External) token type, as returned by yylex.
    typedef token::yytokentype token_type;

    /// Internal symbol number.
    typedef int symbol_number_type;

    /// Internal symbol number for tokens (subsumed by symbol_number_type).
    typedef unsigned char token_number_type;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol type
    /// via type_get().
    ///
    /// Provide access to semantic value.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol ();

      /// Copy constructor.
      basic_symbol (const basic_symbol& other);

      /// Constructor for valueless symbols.
      basic_symbol (typename Base::kind_type t);

      /// Constructor for symbols with semantic value.
      basic_symbol (typename Base::kind_type t,
                    const semantic_type& v);

      ~basic_symbol ();

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      semantic_type value;

    private:
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& other);
    };

    /// Type access provider for token (enum) based symbols.
    struct by_type
    {
      /// Default constructor.
      by_type ();

      /// Copy constructor.
      by_type (const by_type& other);

      /// The symbol type as needed by the constructor.
      typedef token_type kind_type;

      /// Constructor from (external) token numbers.
      by_type (kind_type t);

      /// Steal the symbol type from \a that.
      void move (by_type& that);

      /// The (internal) type number (corresponding to \a type).
      /// -1 when this symbol is empty.
      symbol_number_type type_get () const;

      /// The token.
      token_type token () const;

      enum { empty = 0 };

      /// The symbol type.
      /// -1 when this symbol is empty.
      token_number_type type;
    };

    /// "External" symbols: returned by the scanner.
    typedef basic_symbol<by_type> symbol_type;


    /// Build a parser object.
    Parser (ParseContext & ctx_yyarg);
    virtual ~Parser ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param msg    a description of the syntax error.
    virtual void error (const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

  private:
    /// This class is not copyable.
    Parser (const Parser&);
    Parser& operator= (const Parser&);

    /// State numbers.
    typedef int state_type;

    /// Generate an error message.
    /// \param yystate   the state where the error occurred.
    /// \param yytoken   the lookahead token type, or yyempty_.
    virtual std::string yysyntax_error_ (state_type yystate,
                                         symbol_number_type yytoken) const;

    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yylhs     the nonterminal to push on the stack
    state_type yy_lr_goto_state_ (state_type yystate, int yylhs);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue);

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue);

    static const short int yypact_ninf_;
    static const short int yytable_ninf_;

    /// Convert a scanner token number \a t to a symbol number.
    static token_number_type yytranslate_ (int t);

    // Tables.
  // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
  // STATE-NUM.
  static const short int yypact_[];

  // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
  // Performed when YYTABLE does not specify something else to do.  Zero
  // means the default is an error.
  static const unsigned char yydefact_[];

  // YYPGOTO[NTERM-NUM].
  static const short int yypgoto_[];

  // YYDEFGOTO[NTERM-NUM].
  static const short int yydefgoto_[];

  // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
  // positive, shift that token.  If negative, reduce the rule whose
  // number is the opposite.  If YYTABLE_NINF, syntax error.
  static const short int yytable_[];

  static const short int yycheck_[];

  // YYSTOS[STATE-NUM] -- The (internal number of the) accessing
  // symbol of state STATE-NUM.
  static const unsigned char yystos_[];

  // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
  static const unsigned char yyr1_[];

  // YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.
  static const unsigned char yyr2_[];


    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *n);


    /// For a symbol, its name in clear.
    static const char* const yytname_[];
#if YYDEBUG
  // YYRLINE[YYN] -- Source line where rule number YYN was defined.
  static const unsigned short int yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r);
    /// Print the state stack on the debug stream.
    virtual void yystack_print_ ();

    // Debugging.
    int yydebug_;
    std::ostream* yycdebug_;

    /// \brief Display a symbol type, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param s         The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state ();

      /// The symbol type as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s);

      /// Copy constructor.
      by_state (const by_state& other);

      /// Steal the symbol type from \a that.
      void move (by_state& that);

      /// The (internal) type number (corresponding to \a state).
      /// "empty" when empty.
      symbol_number_type type_get () const;

      enum { empty = 0 };

      /// The state.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, symbol_type& sym);
      /// Assignment, needed by push_back.
      stack_symbol_type& operator= (const stack_symbol_type& that);
    };

    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, stack_symbol_type& s);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, state_type s, symbol_type& sym);

    /// Pop \a n symbols the three stacks.
    void yypop_ (unsigned int n = 1);

    // Constants.
    enum
    {
      yyeof_ = 0,
      yylast_ = 1348,           //< Last index in yytable_.
      yynnts_ = 59,  //< Number of nonterminal symbols.
      yyempty_ = -2,
      yyfinal_ = 3, //< Termination state number.
      yyterror_ = 1,
      yyerrcode_ = 256,
      yyntokens_ = 80    //< Number of tokens.
    };


    // User arguments.
    ParseContext & ctx;
  };


#line 17 "BisonFlex\\parser.y" // lalr1.cc:371
} // moon
#line 477 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\BisonFlex\\parser.hpp" // lalr1.cc:371




#endif // !YY_YY_D_FREECAD_0_19_1_BUILD_SRC_MOD_KAWASAKI_KAWASAKI_KAWASAKI_BISONFLEX_PARSER_HPP_INCLUDED
