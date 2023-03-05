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
 ** \file D:\FreeCAD-0.19.1-build\src\Mod\kawasaki\kawasaki\\kawasaki\grammar\parser.tab.hpp
 ** Define the Language::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

#ifndef YY_YY_D_FREECAD_0_19_1_BUILD_SRC_MOD_KAWASAKI_KAWASAKI_KAWASAKI_GRAMMAR_PARSER_TAB_HPP_INCLUDED
# define YY_YY_D_FREECAD_0_19_1_BUILD_SRC_MOD_KAWASAKI_KAWASAKI_KAWASAKI_GRAMMAR_PARSER_TAB_HPP_INCLUDED
// //                    "%code requires" blocks.
#line 9 "grammar\\parser.y" // lalr1.cc:371

   namespace Language {
      class Translator;
      class Lexer;
      class ASTNode;
      class ParameterNode;
      class FunctionNode;
      class OperatorNode;
      class StatementListNode;
      class StopNode;
      class ToolNode;
      class TWaitNode;
      class JMoveNode;
      class HomeNode;
      class SigNode;
      class SWaitNode;
      class TypeNode;
      class GotoNode;
      class SignalNode;
      class BaseNode;
      class SignalNumsNode;
      class DimNumsNode;
      class SWitchNode;
      class CaseNode;
      class SWitchCaseListNode;
      class AccessNode;
      class TransStrNode;
      class AccuracyNode;
      class AlignNode;
      class BreakNode;
      class C1MoveNode;
      class DecomposeNode;
      class ForNode;
      class HereNode;
      class JapproNode;
      class LapproNode;
      class LMoveNode;
      class SpeedNode;
      class PointNode;
      class DoUntilNode;
      class LabelNode;
      class ParamNode;
      class TDrawNode;
      class DrawNode;
      class PointNode;
      class PointXNode;
      class PointZNode;
      class PointOATNode;
      class DriveNode;
      class PrintNode;
      class DecodeNode;
      class TCPSendNode;
      class TCPCloseNode;
      class TCPRecvNode;
      class BitsNode;
      class BuildInNode;
      class PauseNode;
      class TCPConnectNode;
      class TCPStatusNode;
      class LDepartNode;
      class WeightNode;
      class VALNode;
      class PulseNode;
      class DistanceNode;
      class NullNode;
      template <class T> class ListNode;
   }
   class QString;

#line 114 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.hpp" // lalr1.cc:371


# include <vector>
# include <iostream>
# include <stdexcept>
# include <string>
# include "stack.hh"



/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

#line 5 "grammar\\parser.y" // lalr1.cc:371
namespace Language {
#line 132 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.hpp" // lalr1.cc:371





  /// A Bison parser.
  class Parser
  {
  public:
#ifndef YYSTYPE
    /// Symbol semantic values.
    union semantic_type
    {
    #line 92 "grammar\\parser.y" // lalr1.cc:371

   QString *sval;
   double dval;
   int ival;
   ASTNode * pNode;
   ParameterNode * parameterNode;
   FunctionNode * functionNode;
   ListNode<ASTNode> * listNode;
   ListNode<ParameterNode> * parameterListNode;
   StatementListNode * statementListNode;
   SignalNumsNode* signal_num_stmNode;
   ParamNode* param_stmNode;
   DimNumsNode*     dim_num_stmNode;
   TransStrNode* trans_strNode;   

#line 162 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.hpp" // lalr1.cc:371
    };
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
        END = 0,
        GE = 258,
        LE = 259,
        EQ = 260,
        NE = 261,
        GREATER = 262,
        LESS = 263,
        MINUS = 264,
        ADD = 265,
        SUB = 266,
        MULTIP = 267,
        DEVIDE = 268,
        UMINUS = 269,
        IFX = 270,
        ELSE = 271,
        IF = 272,
        While = 273,
        MUL = 274,
        PRINT = 275,
        LT = 276,
        GT = 277,
        RETURN = 278,
        NumberType = 279,
        TextType = 280,
        VoidType = 281,
        SPACE = 282,
        THEN = 283,
        ASS = 284,
        LR = 285,
        RR = 286,
        COMMA = 287,
        LC = 288,
        RC = 289,
        COLON = 290,
        SWITCH = 291,
        CASE = 292,
        FTRUE = 293,
        FFALSE = 294,
        FOR = 295,
        TO = 296,
        JOINTS_VAR = 297,
        DO = 298,
        UNTIL = 299,
        FINE = 300,
        STEP = 301,
        LDEPART = 302,
        JOINTS = 303,
        TRANS = 304,
        TRANS_DOT = 305,
        ALWAYS = 306,
        HERE = 307,
        BREAK = 308,
        DECOMPOSE = 309,
        SPEED = 310,
        ALIGN = 311,
        ACCURACY = 312,
        LAPPRO = 313,
        JAPPRO = 314,
        DRAW = 315,
        DECODE = 316,
        DRIVE = 317,
        TDRAW = 318,
        POINT = 319,
        TCP_SEND = 320,
        TCP_CLOSE = 321,
        C1MOVE = 322,
        LMOVE = 323,
        TCP_RECV = 324,
        TCP_CONNECT = 325,
        TCP_STATUS = 326,
        WEIGHT = 327,
        VAL = 328,
        STOP = 329,
        HOME = 330,
        BASE = 331,
        TOOL = 332,
        TYPE = 333,
        TWAIT = 334,
        SIGNAL = 335,
        GOTO = 336,
        FUNC = 337,
        SIG = 338,
        JMOVE = 339,
        SWAIT = 340,
        END_ST = 341,
        END_DOT = 342,
        AND = 343,
        OR = 344,
        MOD = 345,
        CALL = 346,
        DEFAULT = 347,
        FNULL = 348,
        OF = 349,
        DEFINES = 350,
        MM_S = 351,
        MM_MIN = 352,
        POINT_X = 353,
        POINT_Z = 354,
        POINT_OAT = 355,
        SHIFT = 356,
        BY = 357,
        BITS = 358,
        PAUSE = 359,
        PULSE = 360,
        DOLAR = 361,
        JIN = 362,
        DISTANCE = 363,
        Number = 364,
        LNumber = 365,
        Identifier = 366,
        String = 367
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
    Parser (Lexer  &lexer_yyarg);
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
      yylast_ = 1433,           //< Last index in yytable_.
      yynnts_ = 38,  //< Number of nonterminal symbols.
      yyempty_ = -2,
      yyfinal_ = 24, //< Termination state number.
      yyterror_ = 1,
      yyerrcode_ = 256,
      yyntokens_ = 113    //< Number of tokens.
    };


    // User arguments.
    Lexer  &lexer;
  };


#line 5 "grammar\\parser.y" // lalr1.cc:371
} // Language
#line 591 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.hpp" // lalr1.cc:371




#endif // !YY_YY_D_FREECAD_0_19_1_BUILD_SRC_MOD_KAWASAKI_KAWASAKI_KAWASAKI_GRAMMAR_PARSER_TAB_HPP_INCLUDED
