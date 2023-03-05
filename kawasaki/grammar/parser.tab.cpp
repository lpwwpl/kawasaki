// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

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


// First part of user declarations.

#line 37 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:398

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

#include "parser.tab.hpp"

// User implementation prologue.

#line 51 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:406
// Unqualified %code blocks.
#line 82 "grammar\\parser.y" // lalr1.cc:407

    #include "translator.hpp"
    #include "ast.h"

    
    extern int lineNumber;
    static int yylex(Language::Parser::semantic_type *yylval, Language::Lexer  &lexer);

#line 62 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:407


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif



// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyempty = true)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 5 "grammar\\parser.y" // lalr1.cc:473
namespace Language {
#line 129 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:473

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  Parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
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
              // Fall through.
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  Parser::Parser (Lexer  &lexer_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      lexer (lexer_yyarg)
  {}

  Parser::~Parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/

  inline
  Parser::syntax_error::syntax_error (const std::string& m)
    : std::runtime_error (m)
  {}

  // basic_symbol.
  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
  {
    value = other.value;
  }


  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v)
    : Base (t)
    , value (v)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t)
    : Base (t)
    , value ()
  {}

  template <typename Base>
  inline
  Parser::basic_symbol<Base>::~basic_symbol ()
  {
  }

  template <typename Base>
  inline
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
    value = s.value;
  }

  // by_type.
  inline
  Parser::by_type::by_type ()
     : type (empty)
  {}

  inline
  Parser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  Parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  Parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.type = empty;
  }

  inline
  int
  Parser::by_type::type_get () const
  {
    return type;
  }


  // by_state.
  inline
  Parser::by_state::by_state ()
    : state (empty)
  {}

  inline
  Parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.state = empty;
  }

  inline
  Parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  Parser::symbol_number_type
  Parser::by_state::type_get () const
  {
    return state == empty ? 0 : yystos_[state];
  }

  inline
  Parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  Parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s)
  {
    value = that.value;
    // that is emptied.
    that.type = empty;
  }

  inline
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    return *this;
  }


  template <typename Base>
  inline
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YYUSE (yysym.type_get ());
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " (";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
  Parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  Parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  Parser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yylhs)
  {
    int yyr = yypgoto_[yylhs - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yylhs - yyntokens_];
  }

  inline bool
  Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::parse ()
  {
    /// Whether yyla contains a lookahead.
    bool yyempty = true;

    // State.
    int yyn;
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// $$ and @$.
    stack_symbol_type yylhs;

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULL, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyempty)
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            yyla.type = yytranslate_ (yylex (&yyla.value, lexer));
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
        yyempty = false;
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Discard the token being shifted.
    yyempty = true;

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
    /* If YYLEN is nonzero, implement the default value of the action:
       '$$ = $1'.  Otherwise, use the top of the stack.

       Otherwise, the following line sets YYLHS.VALUE to garbage.
       This behavior is undocumented and Bison
       users should not rely upon it.  */
    if (yylen)
      yylhs.value = yystack_[yylen - 1].value;
    else
      yylhs.value = yystack_[0].value;


    // Perform the reduction.
    YY_REDUCE_PRINT (yyn);
    try
      {
        switch (yyn)
          {
  case 2:
#line 149 "grammar\\parser.y" // lalr1.cc:846
    {}
#line 563 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 3:
#line 150 "grammar\\parser.y" // lalr1.cc:846
    {}
#line 569 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 4:
#line 154 "grammar\\parser.y" // lalr1.cc:846
    {  }
#line 575 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 5:
#line 155 "grammar\\parser.y" // lalr1.cc:846
    { }
#line 581 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 7:
#line 159 "grammar\\parser.y" // lalr1.cc:846
    {  (yylhs.value.trans_strNode) = new TransStrNode((yystack_[0].value.pNode)); }
#line 587 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 8:
#line 160 "grammar\\parser.y" // lalr1.cc:846
    {  (yystack_[2].value.trans_strNode)->push_back((yystack_[0].value.pNode));}
#line 593 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 9:
#line 161 "grammar\\parser.y" // lalr1.cc:846
    {(yylhs.value.trans_strNode) = new TransStrNode(NULL);}
#line 599 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 10:
#line 167 "grammar\\parser.y" // lalr1.cc:846
    { 
        NumberLiteralNode* num = new NumberLiteralNode((yystack_[0].value.dval));
        (yylhs.value.trans_strNode) = new TransStrNode(num); 
    }
#line 608 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 11:
#line 172 "grammar\\parser.y" // lalr1.cc:846
    {
        NumberLiteralNode* num = new NumberLiteralNode((yystack_[0].value.dval));
        (yystack_[2].value.trans_strNode)->push_back(num);
    }
#line 617 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 12:
#line 176 "grammar\\parser.y" // lalr1.cc:846
    {(yylhs.value.trans_strNode) = new TransStrNode(NULL);}
#line 623 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 13:
#line 181 "grammar\\parser.y" // lalr1.cc:846
    { 
        NumberLiteralNode* num = new NumberLiteralNode((yystack_[0].value.dval));
        (yylhs.value.trans_strNode) = new TransStrNode(num); 
    }
#line 632 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 14:
#line 186 "grammar\\parser.y" // lalr1.cc:846
    {
        NumberLiteralNode* num = new NumberLiteralNode((yystack_[0].value.dval));
        (yystack_[1].value.trans_strNode)->push_back(num);
    }
#line 641 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 15:
#line 190 "grammar\\parser.y" // lalr1.cc:846
    {(yylhs.value.trans_strNode) = new TransStrNode(NULL);}
#line 647 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 16:
#line 194 "grammar\\parser.y" // lalr1.cc:846
    {}
#line 653 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 17:
#line 196 "grammar\\parser.y" // lalr1.cc:846
    {
        (yylhs.value.pNode) = new AssignmentNode((yystack_[1].value.sval), (yystack_[0].value.trans_strNode));
    }
#line 661 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 18:
#line 200 "grammar\\parser.y" // lalr1.cc:846
    {
        (yylhs.value.pNode) = new AssignmentNode((yystack_[4].value.sval), (yystack_[0].value.trans_strNode),(yystack_[2].value.dim_num_stmNode));
    }
#line 669 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 19:
#line 206 "grammar\\parser.y" // lalr1.cc:846
    {}
#line 675 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 20:
#line 208 "grammar\\parser.y" // lalr1.cc:846
    {
        (yylhs.value.pNode) = new AssignmentNode((yystack_[1].value.sval), (yystack_[0].value.trans_strNode));
    }
#line 683 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 21:
#line 212 "grammar\\parser.y" // lalr1.cc:846
    {
        (yylhs.value.pNode) = new AssignmentNode((yystack_[4].value.sval), (yystack_[0].value.trans_strNode),(yystack_[2].value.dim_num_stmNode));
    }
#line 691 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 22:
#line 218 "grammar\\parser.y" // lalr1.cc:846
    {

	}
#line 699 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 23:
#line 222 "grammar\\parser.y" // lalr1.cc:846
    {}
#line 705 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 24:
#line 226 "grammar\\parser.y" // lalr1.cc:846
    {}
#line 711 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 25:
#line 227 "grammar\\parser.y" // lalr1.cc:846
    {}
#line 717 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 26:
#line 231 "grammar\\parser.y" // lalr1.cc:846
    {

	}
#line 725 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 27:
#line 235 "grammar\\parser.y" // lalr1.cc:846
    {}
#line 731 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 28:
#line 239 "grammar\\parser.y" // lalr1.cc:846
    {}
#line 737 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 29:
#line 240 "grammar\\parser.y" // lalr1.cc:846
    {}
#line 743 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 30:
#line 244 "grammar\\parser.y" // lalr1.cc:846
    {}
#line 749 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 31:
#line 245 "grammar\\parser.y" // lalr1.cc:846
    {}
#line 755 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 32:
#line 246 "grammar\\parser.y" // lalr1.cc:846
    {}
#line 761 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 33:
#line 247 "grammar\\parser.y" // lalr1.cc:846
    {}
#line 767 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 34:
#line 248 "grammar\\parser.y" // lalr1.cc:846
    {}
#line 773 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 35:
#line 249 "grammar\\parser.y" // lalr1.cc:846
    {}
#line 779 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 36:
#line 253 "grammar\\parser.y" // lalr1.cc:846
    {

	}
#line 787 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 37:
#line 257 "grammar\\parser.y" // lalr1.cc:846
    {}
#line 793 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 38:
#line 261 "grammar\\parser.y" // lalr1.cc:846
    {
	}
#line 800 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 39:
#line 264 "grammar\\parser.y" // lalr1.cc:846
    { (yystack_[0].value.listNode)->Execute(); }
#line 806 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 40:
#line 268 "grammar\\parser.y" // lalr1.cc:846
    { (yylhs.value.listNode) = new ListNode<ASTNode>((yystack_[0].value.functionNode));}
#line 812 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 41:
#line 269 "grammar\\parser.y" // lalr1.cc:846
    {(yystack_[1].value.listNode)->push_back((yystack_[0].value.functionNode));}
#line 818 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 42:
#line 273 "grammar\\parser.y" // lalr1.cc:846
    {(yylhs.value.functionNode) = new FunctionNode(token::VoidType, (yystack_[5].value.sval), (yystack_[3].value.parameterListNode), (yystack_[1].value.statementListNode)); }
#line 824 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 44:
#line 275 "grammar\\parser.y" // lalr1.cc:846
    {(yylhs.value.functionNode) = new FunctionNode(token::VoidType, (yystack_[7].value.sval), (yystack_[5].value.parameterListNode), (yystack_[1].value.statementListNode)); }
#line 830 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 45:
#line 285 "grammar\\parser.y" // lalr1.cc:846
    { (yylhs.value.parameterListNode) = new ListNode<ParameterNode>((yystack_[0].value.parameterNode)); }
#line 836 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 46:
#line 286 "grammar\\parser.y" // lalr1.cc:846
    {(yystack_[2].value.parameterListNode)->push_back((yystack_[0].value.parameterNode));}
#line 842 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 47:
#line 287 "grammar\\parser.y" // lalr1.cc:846
    {(yylhs.value.parameterListNode) = new ListNode<ParameterNode>();}
#line 848 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 48:
#line 291 "grammar\\parser.y" // lalr1.cc:846
    {(yylhs.value.parameterNode) = new ParameterNode((yystack_[0].value.sval));}
#line 854 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 49:
#line 296 "grammar\\parser.y" // lalr1.cc:846
    {(yylhs.value.statementListNode)=NULL;}
#line 860 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 50:
#line 297 "grammar\\parser.y" // lalr1.cc:846
    {(yylhs.value.statementListNode) = (yystack_[0].value.statementListNode);}
#line 866 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 51:
#line 301 "grammar\\parser.y" // lalr1.cc:846
    {(yylhs.value.statementListNode) = new StatementListNode((yystack_[0].value.pNode));}
#line 872 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 52:
#line 302 "grammar\\parser.y" // lalr1.cc:846
    {(yystack_[1].value.statementListNode)->push_back((yystack_[0].value.pNode));}
#line 878 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 53:
#line 306 "grammar\\parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = (yystack_[0].value.parameterNode);}
#line 884 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 54:
#line 307 "grammar\\parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = (yystack_[0].value.pNode);}
#line 890 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 55:
#line 308 "grammar\\parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = (yystack_[0].value.pNode);}
#line 896 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 56:
#line 309 "grammar\\parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = (yystack_[0].value.pNode);}
#line 902 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 57:
#line 310 "grammar\\parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = (yystack_[0].value.pNode); }
#line 908 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 58:
#line 311 "grammar\\parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = (yystack_[0].value.pNode);}
#line 914 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 59:
#line 312 "grammar\\parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = (yystack_[0].value.pNode); }
#line 920 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 60:
#line 313 "grammar\\parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = (yystack_[0].value.pNode); }
#line 926 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 61:
#line 314 "grammar\\parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = (yystack_[0].value.pNode);}
#line 932 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 62:
#line 315 "grammar\\parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new StopNode(NULL); }
#line 938 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 63:
#line 316 "grammar\\parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = new BaseNode((yystack_[0].value.pNode));}
#line 944 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 64:
#line 317 "grammar\\parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = new ToolNode((yystack_[0].value.pNode));}
#line 950 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 65:
#line 318 "grammar\\parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = new TWaitNode((yystack_[0].value.pNode));}
#line 956 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 66:
#line 319 "grammar\\parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = new JMoveNode((yystack_[0].value.pNode));}
#line 962 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 67:
#line 320 "grammar\\parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = new HomeNode(0);}
#line 968 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 68:
#line 321 "grammar\\parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = new SignalNode((yystack_[0].value.signal_num_stmNode));}
#line 974 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 69:
#line 322 "grammar\\parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = new SWaitNode((yystack_[0].value.signal_num_stmNode));}
#line 980 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 70:
#line 323 "grammar\\parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = new TypeNode((yystack_[0].value.pNode));}
#line 986 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 71:
#line 324 "grammar\\parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new PauseNode(NULL);}
#line 992 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 72:
#line 325 "grammar\\parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = new LMoveNode((yystack_[0].value.pNode));}
#line 998 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 73:
#line 326 "grammar\\parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new AlignNode(NULL);}
#line 1004 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 74:
#line 327 "grammar\\parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = new BreakNode(NULL);}
#line 1010 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 75:
#line 328 "grammar\\parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = new HereNode((yystack_[0].value.pNode));}
#line 1016 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 76:
#line 329 "grammar\\parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = new SpeedNode((yystack_[0].value.param_stmNode));}
#line 1022 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 77:
#line 330 "grammar\\parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = new LDepartNode((yystack_[0].value.pNode));}
#line 1028 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 78:
#line 331 "grammar\\parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = new SpeedNode((yystack_[0].value.pNode));}
#line 1034 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 79:
#line 332 "grammar\\parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = new JapproNode((yystack_[2].value.pNode),(yystack_[0].value.pNode));}
#line 1040 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 80:
#line 333 "grammar\\parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = new PulseNode((yystack_[2].value.pNode),(yystack_[0].value.pNode));}
#line 1046 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 81:
#line 334 "grammar\\parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = new C1MoveNode((yystack_[0].value.pNode));}
#line 1052 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 82:
#line 335 "grammar\\parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = new LapproNode((yystack_[2].value.pNode),(yystack_[0].value.pNode));}
#line 1058 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 83:
#line 336 "grammar\\parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new AccuracyNode((yystack_[0].value.param_stmNode));}
#line 1064 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 84:
#line 337 "grammar\\parser.y" // lalr1.cc:846
    { SignalNumsNode* sigNums = new SignalNumsNode((yystack_[0].value.signal_num_stmNode));(yylhs.value.pNode) = new AccuracyNode(sigNums);}
#line 1070 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 85:
#line 338 "grammar\\parser.y" // lalr1.cc:846
    {  (yylhs.value.pNode) = new DrawNode((yystack_[0].value.param_stmNode));}
#line 1076 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 86:
#line 339 "grammar\\parser.y" // lalr1.cc:846
    { SignalNumsNode* sigNums = new SignalNumsNode((yystack_[0].value.signal_num_stmNode));  (yylhs.value.pNode) = new DrawNode(sigNums);}
#line 1082 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 87:
#line 340 "grammar\\parser.y" // lalr1.cc:846
    { SignalNumsNode* sigNums = new SignalNumsNode((yystack_[0].value.signal_num_stmNode));  (yylhs.value.pNode) = new DriveNode(sigNums);}
#line 1088 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 88:
#line 341 "grammar\\parser.y" // lalr1.cc:846
    { SignalNumsNode* sigNums = new SignalNumsNode((yystack_[0].value.signal_num_stmNode));  (yylhs.value.pNode) = new TDrawNode(sigNums);}
#line 1094 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 89:
#line 342 "grammar\\parser.y" // lalr1.cc:846
    { SignalNumsNode* sigNums = new SignalNumsNode((yystack_[0].value.signal_num_stmNode));  (yylhs.value.pNode) = new WeightNode(sigNums);}
#line 1100 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 90:
#line 343 "grammar\\parser.y" // lalr1.cc:846
    {  (yylhs.value.pNode) = new TDrawNode((yystack_[0].value.param_stmNode));}
#line 1106 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 91:
#line 345 "grammar\\parser.y" // lalr1.cc:846
    {     
     (yylhs.value.pNode) = new PointNode((yystack_[11].value.pNode),(yystack_[7].value.pNode),(yystack_[5].value.pNode),(yystack_[3].value.pNode),(yystack_[1].value.pNode));
    }
#line 1114 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 92:
#line 348 "grammar\\parser.y" // lalr1.cc:846
    { /*TransNode* trans = new TransNode($4);*/(yylhs.value.pNode) = new PointNode((yystack_[5].value.pNode),(yystack_[1].value.signal_num_stmNode),1);}
#line 1120 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 93:
#line 349 "grammar\\parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = new PointNode((yystack_[2].value.pNode),(yystack_[0].value.pNode),0);}
#line 1126 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 94:
#line 350 "grammar\\parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = new PointOATNode((yystack_[2].value.pNode),(yystack_[0].value.pNode));}
#line 1132 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 95:
#line 351 "grammar\\parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = new PointXNode((yystack_[2].value.pNode),(yystack_[0].value.pNode));}
#line 1138 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 96:
#line 352 "grammar\\parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = new PointZNode((yystack_[2].value.pNode),(yystack_[0].value.pNode));}
#line 1144 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 97:
#line 354 "grammar\\parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new PrintNode((yystack_[2].value.pNode),(yystack_[0].value.trans_strNode));}
#line 1150 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 98:
#line 355 "grammar\\parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = new PrintNode((yystack_[0].value.trans_strNode));}
#line 1156 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 99:
#line 356 "grammar\\parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = new TCPSendNode((yystack_[0].value.trans_strNode));}
#line 1162 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 100:
#line 357 "grammar\\parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new TCPCloseNode((yystack_[0].value.trans_strNode));}
#line 1168 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 101:
#line 358 "grammar\\parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = new TCPStatusNode((yystack_[0].value.trans_strNode));}
#line 1174 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 102:
#line 359 "grammar\\parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new TCPRecvNode((yystack_[0].value.trans_strNode));}
#line 1180 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 103:
#line 360 "grammar\\parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new TCPConnectNode((yystack_[0].value.trans_strNode));}
#line 1186 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 104:
#line 362 "grammar\\parser.y" // lalr1.cc:846
    {  (yylhs.value.pNode) = new GotoNode((yystack_[0].value.pNode));}
#line 1192 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 105:
#line 363 "grammar\\parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = (yystack_[0].value.pNode);}
#line 1198 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 106:
#line 364 "grammar\\parser.y" // lalr1.cc:846
    { IdentifierNode* id = new IdentifierNode((yystack_[1].value.sval));(yylhs.value.pNode) = new LabelNode(id);   }
#line 1204 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 107:
#line 365 "grammar\\parser.y" // lalr1.cc:846
    { NumberLiteralNode* id = new NumberLiteralNode((yystack_[0].value.dval));(yylhs.value.pNode) = new LabelNode(id);   }
#line 1210 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 108:
#line 378 "grammar\\parser.y" // lalr1.cc:846
    {
        (yylhs.value.signal_num_stmNode) = new SignalNumsNode((yystack_[0].value.pNode)); 
    }
#line 1218 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 109:
#line 382 "grammar\\parser.y" // lalr1.cc:846
    {
		(yystack_[2].value.signal_num_stmNode)->push_back((yystack_[0].value.pNode));    
	}
#line 1226 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 110:
#line 389 "grammar\\parser.y" // lalr1.cc:846
    {
        (yylhs.value.param_stmNode) = new ParamNode((yystack_[1].value.signal_num_stmNode),1);
    }
#line 1234 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 111:
#line 393 "grammar\\parser.y" // lalr1.cc:846
    {
        (yylhs.value.param_stmNode) = new  ParamNode((yystack_[2].value.signal_num_stmNode),1,true);
    }
#line 1242 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 112:
#line 397 "grammar\\parser.y" // lalr1.cc:846
    {
        (yylhs.value.param_stmNode) = new  ParamNode((yystack_[3].value.signal_num_stmNode),1,true,true);
    }
#line 1250 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 113:
#line 401 "grammar\\parser.y" // lalr1.cc:846
    {
        (yylhs.value.param_stmNode) = new  ParamNode((yystack_[2].value.signal_num_stmNode),1,false,true);
    }
#line 1258 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 114:
#line 405 "grammar\\parser.y" // lalr1.cc:846
    {
        (yylhs.value.param_stmNode) = new  ParamNode((yystack_[1].value.signal_num_stmNode),2);
    }
#line 1266 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 115:
#line 409 "grammar\\parser.y" // lalr1.cc:846
    {
        (yylhs.value.param_stmNode) = new  ParamNode((yystack_[2].value.signal_num_stmNode),2,true);
    }
#line 1274 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 116:
#line 413 "grammar\\parser.y" // lalr1.cc:846
    {
        (yylhs.value.param_stmNode) = new ParamNode((yystack_[2].value.signal_num_stmNode),2,false,true);
    }
#line 1282 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 117:
#line 417 "grammar\\parser.y" // lalr1.cc:846
    {
        (yylhs.value.param_stmNode) = new ParamNode((yystack_[3].value.signal_num_stmNode),2,true,true);
    }
#line 1290 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 118:
#line 421 "grammar\\parser.y" // lalr1.cc:846
    {
        (yylhs.value.param_stmNode) = new ParamNode((yystack_[2].value.signal_num_stmNode),0,true,true);
    }
#line 1298 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 119:
#line 425 "grammar\\parser.y" // lalr1.cc:846
    {
        (yylhs.value.param_stmNode) = new ParamNode((yystack_[1].value.signal_num_stmNode),0,false,true);
    }
#line 1306 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 120:
#line 429 "grammar\\parser.y" // lalr1.cc:846
    {
        (yylhs.value.param_stmNode) = new ParamNode((yystack_[1].value.signal_num_stmNode),0,true);
    }
#line 1314 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 121:
#line 434 "grammar\\parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = new ReturnNode(NULL); }
#line 1320 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 122:
#line 438 "grammar\\parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new WhileNode((yystack_[2].value.pNode), (yystack_[0].value.statementListNode)); }
#line 1326 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 123:
#line 442 "grammar\\parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new DoUntilNode((yystack_[0].value.pNode),(yystack_[2].value.statementListNode)); }
#line 1332 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 124:
#line 446 "grammar\\parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = new FunctionCallNode((yystack_[3].value.sval), (yystack_[1].value.listNode));}
#line 1338 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 125:
#line 447 "grammar\\parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new FunctionCallNode((yystack_[0].value.sval), new ListNode<ASTNode>());}
#line 1344 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 126:
#line 452 "grammar\\parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new ForNode((yystack_[6].value.pNode),(yystack_[4].value.pNode),(yystack_[2].value.pNode),(yystack_[1].value.statementListNode));}
#line 1350 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 127:
#line 453 "grammar\\parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new ForNode((yystack_[4].value.pNode),(yystack_[2].value.pNode),NULL,(yystack_[1].value.statementListNode));}
#line 1356 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 128:
#line 457 "grammar\\parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new IfNode((yystack_[3].value.pNode), (yystack_[1].value.statementListNode)); }
#line 1362 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 129:
#line 458 "grammar\\parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new IfNode((yystack_[5].value.pNode), (yystack_[3].value.statementListNode), (yystack_[1].value.statementListNode)); }
#line 1368 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 130:
#line 463 "grammar\\parser.y" // lalr1.cc:846
    {
        (yylhs.value.pNode) = new SWitchNode((yystack_[3].value.pNode),(yystack_[1].value.listNode),NULL);
    }
#line 1376 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 131:
#line 470 "grammar\\parser.y" // lalr1.cc:846
    {
        (yylhs.value.listNode) = new SWitchCaseListNode((yystack_[0].value.pNode));
	}
#line 1384 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 132:
#line 475 "grammar\\parser.y" // lalr1.cc:846
    {
        (yystack_[1].value.listNode)->push_back((yystack_[0].value.pNode));   
	}
#line 1392 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 133:
#line 482 "grammar\\parser.y" // lalr1.cc:846
    {
        (yylhs.value.pNode) = new CaseNode((yystack_[2].value.pNode),(yystack_[0].value.statementListNode)); //$$->dimListType->push_back($1);
	}
#line 1400 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 134:
#line 488 "grammar\\parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new PrintNode((yystack_[0].value.pNode));}
#line 1406 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 135:
#line 493 "grammar\\parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new AssignmentNode((yystack_[2].value.sval), (yystack_[0].value.pNode));}
#line 1412 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 136:
#line 495 "grammar\\parser.y" // lalr1.cc:846
    { BitsNode* node = new BitsNode((yystack_[3].value.pNode),(yystack_[1].value.pNode),0); (yylhs.value.pNode) = new AssignmentNode((yystack_[7].value.sval), node);}
#line 1418 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 137:
#line 497 "grammar\\parser.y" // lalr1.cc:846
    { DistanceNode* distance = new DistanceNode((yystack_[1].value.pNode)); (yylhs.value.pNode) = new AssignmentNode((yystack_[5].value.sval),distance);}
#line 1424 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 138:
#line 499 "grammar\\parser.y" // lalr1.cc:846
    { AccessNode* acc = new AccessNode((yystack_[8].value.sval), (yystack_[6].value.dim_num_stmNode));DistanceNode* distance = new DistanceNode((yystack_[1].value.trans_strNode)); (yylhs.value.pNode) = new AssignmentNode(acc,distance);}
#line 1430 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 139:
#line 501 "grammar\\parser.y" // lalr1.cc:846
    { VALNode* val = new VALNode((yystack_[1].value.pNode)); (yylhs.value.pNode) = new AssignmentNode((yystack_[5].value.sval),val);}
#line 1436 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 140:
#line 503 "grammar\\parser.y" // lalr1.cc:846
    { QString str = "BITS";(yylhs.value.pNode) = new AssignmentNode(&str,(yystack_[2].value.trans_strNode), (yystack_[0].value.pNode),NULL);}
#line 1442 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 141:
#line 506 "grammar\\parser.y" // lalr1.cc:846
    { 
        (yylhs.value.pNode) = new AssignmentNode((yystack_[5].value.sval), (yystack_[0].value.pNode), (yystack_[3].value.dim_num_stmNode));
    }
#line 1450 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 142:
#line 512 "grammar\\parser.y" // lalr1.cc:846
    {
        //NumberLiteralNode* node  = new NumberLiteralNode($1);
        (yylhs.value.dim_num_stmNode) = new DimNumsNode((yystack_[0].value.pNode)); //$$->dimListType->push_back($1);
    }
#line 1459 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 143:
#line 517 "grammar\\parser.y" // lalr1.cc:846
    {
        (yystack_[2].value.dim_num_stmNode)->push_back((yystack_[0].value.pNode));   
        //NumberLiteralNode* node = new NumberLiteralNode($3);
		//$1->push_back(node);    
	}
#line 1469 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 144:
#line 525 "grammar\\parser.y" // lalr1.cc:846
    { (yylhs.value.listNode) = new ListNode<ASTNode>((yystack_[0].value.pNode)); }
#line 1475 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 145:
#line 526 "grammar\\parser.y" // lalr1.cc:846
    {(yystack_[2].value.listNode)->push_back((yystack_[0].value.pNode));}
#line 1481 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 146:
#line 527 "grammar\\parser.y" // lalr1.cc:846
    {(yylhs.value.listNode) = new ListNode<ASTNode>(); }
#line 1487 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 147:
#line 531 "grammar\\parser.y" // lalr1.cc:846
    {(yylhs.value.pNode)=NULL;}
#line 1493 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 148:
#line 532 "grammar\\parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new IdentifierNode((yystack_[0].value.sval)); }
#line 1499 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 149:
#line 533 "grammar\\parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = (yystack_[1].value.trans_strNode);}
#line 1505 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 150:
#line 534 "grammar\\parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new StringLiteralNode((yystack_[0].value.sval));}
#line 1511 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 151:
#line 535 "grammar\\parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new NullNode();}
#line 1517 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 152:
#line 536 "grammar\\parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = new NumberLiteralNode((yystack_[0].value.dval)); }
#line 1523 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 153:
#line 537 "grammar\\parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = (yystack_[0].value.pNode);}
#line 1529 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 154:
#line 538 "grammar\\parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = new NumberLiteralNode(1);}
#line 1535 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 155:
#line 539 "grammar\\parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = new NumberLiteralNode(0);}
#line 1541 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 156:
#line 541 "grammar\\parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new OperatorNode(token::ADD, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 1547 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 157:
#line 542 "grammar\\parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new OperatorNode(token::SUB, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 1553 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 158:
#line 543 "grammar\\parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new OperatorNode(token::MUL, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 1559 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 159:
#line 544 "grammar\\parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new OperatorNode(token::LT, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 1565 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 160:
#line 545 "grammar\\parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new OperatorNode(token::GT, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 1571 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 161:
#line 546 "grammar\\parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new OperatorNode(token::GE, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 1577 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 162:
#line 547 "grammar\\parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new OperatorNode(token::LE, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 1583 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 163:
#line 548 "grammar\\parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new OperatorNode(token::NE, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 1589 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 164:
#line 549 "grammar\\parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new OperatorNode(token::EQ, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 1595 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 165:
#line 550 "grammar\\parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = new OperatorNode(token::AND, (yystack_[2].value.pNode), (yystack_[0].value.pNode));}
#line 1601 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 166:
#line 551 "grammar\\parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = new OperatorNode(token::OR, (yystack_[2].value.pNode), (yystack_[0].value.pNode));}
#line 1607 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 167:
#line 552 "grammar\\parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = new OperatorNode(token::MOD, (yystack_[2].value.pNode), (yystack_[0].value.pNode));}
#line 1613 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 168:
#line 553 "grammar\\parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new OperatorNode(token::UMINUS, (yystack_[0].value.pNode)); }
#line 1619 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 169:
#line 554 "grammar\\parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = new AccessNode((yystack_[3].value.sval), (yystack_[1].value.dim_num_stmNode));}
#line 1625 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 170:
#line 555 "grammar\\parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new DecodeNode((yystack_[1].value.trans_strNode));}
#line 1631 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 171:
#line 556 "grammar\\parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new BuildInNode((yystack_[3].value.sval),(yystack_[1].value.trans_strNode));}
#line 1637 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;

  case 172:
#line 557 "grammar\\parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = new SigNode((yystack_[1].value.signal_num_stmNode));}
#line 1643 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
    break;


#line 1647 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:846
          default:
            break;
          }
      }
    catch (const syntax_error& yyexc)
      {
        error (yyexc);
        YYERROR;
      }
    YY_SYMBOL_PRINT ("-> $$ =", yylhs);
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();

    // Shift the result of the reduction.
    yypush_ (YY_NULL, yylhs);
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yysyntax_error_ (yystack_[0].state,
                                           yyempty ? yyempty_ : yyla.type_get ()));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyempty)
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyempty = true;
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }


      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyempty)
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyempty)
          yy_destroy_ (YY_NULL, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULL, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what());
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (state_type yystate, symbol_number_type yytoken) const
  {
    std::string yyres;
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yytoken) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (yytoken != yyempty_)
      {
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULL;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
        YYCASE_(0, YY_("syntax error"));
        YYCASE_(1, YY_("syntax error, unexpected %s"));
        YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const short int Parser::yypact_ninf_ = -133;

  const short int Parser::yytable_ninf_ = -148;

  const short int
  Parser::yypact_[] =
  {
      72,   -92,   -84,   -73,   -85,    62,  -133,  -133,    72,  -133,
     103,   -25,  -133,   -29,  -133,   -52,   -26,  -133,   -51,    44,
     562,    95,     5,  -133,  -133,  -133,  -133,  -133,  -133,   103,
    -133,   661,  -133,     8,  -133,  -133,   661,     8,  -133,  -133,
      10,   661,  -133,  -133,    34,   115,   145,    76,  -133,  -133,
     -10,  -133,    71,  -133,  1343,   217,   661,  -133,  -133,   124,
    1343,  -133,   128,  -133,   138,  -133,    52,  -133,   142,   571,
     661,   157,   661,   571,   661,   661,   661,   661,   661,   661,
     661,   661,   661,   661,   661,   661,   661,   661,   166,   169,
     182,  1343,   150,   118,   661,   118,    10,   739,  -133,   121,
     160,   173,  1343,   586,   207,   179,  1343,  1343,    57,    57,
      57,    57,    52,    52,  1343,  1343,  1343,  1343,  1343,  1343,
     661,   661,   661,   183,     8,  1343,     8,  -133,   661,   661,
     158,  -133,   661,   -85,   809,   661,   661,  -133,   661,  -133,
     661,   661,   661,   661,   661,   661,   661,   276,   276,   661,
     661,   276,   276,   276,   661,  -133,  -133,   661,   661,   661,
     661,   661,   661,   661,   661,   661,   661,   661,  -133,   661,
     131,  -133,    40,  -133,   137,   809,  -133,  -133,  -133,  -133,
    -133,  -133,  -133,  -133,  -133,  -133,  -133,  -133,   661,  -133,
     184,  1343,  -133,  -133,   943,   963,   996,   652,  1016,  1036,
     212,  1056,   920,   209,   208,  1343,  1343,   107,  -133,   900,
     107,  -133,  1077,  1097,   107,  -133,   221,   107,  -133,  1128,
     212,   212,  1343,  1343,   212,   212,   212,   221,  1343,  1343,
    1343,  1343,   221,  1343,  1343,   221,  1149,  1169,  1190,  1221,
     809,  -133,  -133,  -133,  1343,   661,  -133,  -133,   661,  -133,
     224,  1343,   809,   809,   276,   223,   661,   661,  -133,   213,
      43,    51,   661,   661,   577,   661,   661,   661,   661,   167,
    1343,  1241,   571,    -2,  -133,   212,   661,   -20,  -133,   372,
    1343,  -133,  -133,   216,  -133,   218,  1343,  1343,   229,   231,
    1343,  1343,  1343,  1343,  1343,  -133,  -133,   188,   809,  -133,
    1262,  -133,  -133,   661,   180,  -133,  -133,   661,   661,  -133,
     185,   809,   481,  -133,   189,   630,  -133,  -133,   187,  -133,
     661,  -133,  1282,   661,  1302,   661,  1322,  -133
  };

  const unsigned char
  Parser::yydefact_[] =
  {
      22,    19,    16,     0,     0,     0,    31,    32,    22,    30,
      22,    39,    40,    15,    28,     0,    15,    24,     0,     0,
     147,     0,     0,     4,     1,    33,    34,    35,     3,     2,
      41,   147,    13,    20,    27,    29,   147,    17,    23,    25,
      47,   147,   154,   155,    12,     0,     0,     0,   151,   152,
     148,   150,     0,   153,     7,   147,   147,    37,     5,     0,
     142,    14,     0,    48,     0,    45,   168,    10,     0,   147,
     147,   125,   147,   147,   147,   147,   147,   147,   147,   147,
     147,   147,   147,   147,   147,   147,   147,   147,     0,     0,
       0,   135,     0,    15,   147,    15,     0,    49,   149,     0,
       0,     0,   108,   147,     0,     0,   140,     8,   161,   162,
     164,   163,   156,   157,   158,   159,   160,   165,   166,   167,
     147,   147,   147,     0,    21,   143,    18,    46,   147,   147,
       6,   121,   147,     0,    49,   147,   147,    74,   147,    73,
     147,   147,   147,   147,   147,   147,   147,     6,     6,   147,
     147,     6,     6,     6,   147,    62,    67,   147,   147,   147,
     147,   147,   147,   147,   147,   147,   147,   147,    71,   147,
       0,   107,    48,    53,     0,    50,    51,    61,    57,    58,
      56,    60,    59,   105,    55,    54,    11,   170,   147,   172,
       0,   144,   169,   171,     0,     0,     0,   147,     0,     0,
      98,     7,     0,     0,     0,    77,    75,     0,    76,    78,
      84,    83,     0,     0,    86,    85,    87,    88,    90,     0,
      99,   100,    81,    72,   102,   103,   101,    89,    63,    64,
      70,    65,    68,   104,    66,    69,     0,     0,     0,     0,
      49,   106,    42,    52,   109,   147,   124,   139,   147,   137,
       0,   141,    49,    49,     6,     0,   147,   147,   119,   120,
     110,   114,   147,   147,   147,   147,   147,   147,   147,     0,
     145,     0,   147,     0,   122,    97,   147,     0,   131,    49,
     123,   118,   113,   111,   116,   115,    82,    79,     0,     0,
      93,    95,    96,    94,    80,    44,   136,     0,    49,   128,
       0,   130,   132,   147,     0,   112,   117,   147,   147,   138,
       0,    49,    49,   127,     0,     0,   129,   133,     0,    92,
     147,   126,     0,   147,     0,   147,     0,    91
  };

  const short int
  Parser::yypgoto_[] =
  {
    -133,  -133,  -133,   -66,  -133,     0,    19,  -133,     1,  -133,
      13,  -133,   255,    32,   260,  -133,   263,  -133,   -38,  -103,
    -133,   100,  -132,    46,  -133,  -133,  -133,   -69,  -133,  -133,
    -133,  -133,     6,  -133,    11,   129,  -133,   -31
  };

  const short int
  Parser::yydefgoto_[] =
  {
      -1,     5,    22,    52,    68,    33,    17,    14,     6,    18,
       7,    15,     8,     9,    10,    11,    12,    64,   173,   174,
     175,   176,   101,   208,   177,   178,   179,    53,   181,   182,
     183,   277,   278,   184,   185,    59,   190,    54
  };

  const short int
  Parser::yytable_[] =
  {
      60,    31,    65,   100,    36,    60,   207,   105,   210,    25,
      66,   214,   216,   217,   298,    23,    37,   276,    20,    13,
      72,    26,   227,    73,    91,    60,    21,    16,   180,   232,
      25,   204,   235,    58,    35,    34,    38,    39,    19,   102,
      27,    60,    26,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,     3,   127,    16,
      16,    27,    24,   125,   200,   180,   301,    80,    81,    55,
      56,    82,   191,    83,    84,   241,    82,    40,    83,    84,
      32,   220,   221,    32,   299,   224,   225,   226,   282,   194,
     195,   196,    57,   124,   283,   126,   284,   198,   199,   201,
      74,   202,   285,    75,   205,   206,   180,   209,    20,   102,
     212,   213,   102,   102,   102,   219,    21,    61,   222,   223,
       1,    63,     2,   102,    55,    56,   228,   229,   230,   231,
     102,   233,   234,   102,   236,   237,   238,   269,   239,   188,
      85,    86,    87,    67,   203,    85,    86,    87,    69,   273,
     274,     1,   258,     2,     3,    93,    94,   244,   259,    95,
      94,  -147,  -147,  -147,  -147,    62,   251,     4,  -147,    41,
      96,   180,    97,    98,    99,   314,   304,  -147,    70,  -147,
    -147,   123,    94,   180,   180,    92,   211,    71,   275,   215,
     103,   218,    75,  -147,   187,   310,    42,    43,     4,   120,
      44,   104,   121,   260,   261,   188,   297,   189,   317,   318,
     180,    75,   197,   193,   270,   122,   245,   271,   246,    45,
      75,   188,   309,   319,   242,   279,   280,    32,    41,   180,
     186,   286,   287,   290,   291,   292,   293,   294,   192,    94,
     240,    46,   180,   180,    75,   300,  -147,  -147,  -147,    47,
     256,    48,   257,   188,   295,    42,    43,   272,   281,    44,
     276,   305,   307,   306,   308,    29,   313,    49,    28,    50,
      51,   316,   312,   321,    30,   243,   102,   315,    45,  -147,
    -147,  -147,  -147,   302,     0,     0,  -147,    41,     0,   322,
      88,     0,   324,     0,   326,  -147,     0,  -147,  -147,     0,
      46,     0,     0,     0,     0,     0,     0,     0,    47,     0,
      48,     0,     0,     0,    42,    43,     0,     0,    44,     0,
      89,     0,     0,     0,     0,    90,    49,     0,    50,    51,
       0,     0,     0,     0,     0,     0,     0,    45,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    46,
       0,     0,     0,     0,  -147,  -147,  -147,    47,     0,    48,
       0,     0,     0,     0,     0,    76,    77,    78,    79,     0,
       0,     0,    80,    81,     0,    49,     0,    50,    51,   128,
     129,    82,   130,    83,    84,   131,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   132,     0,
       0,     0,   133,     0,     0,   134,     0,     0,   303,   135,
       0,     0,     0,     0,   136,   137,     0,   138,   139,   140,
     141,   142,   143,     0,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,     0,   155,   156,   157,   158,
     159,   160,   161,   162,     0,     0,   163,   164,     0,     0,
      85,    86,    87,    47,     0,     0,     0,     0,     0,     0,
     165,   166,   167,     0,     0,    20,   168,   169,     0,     0,
       0,   171,     0,   172,    76,    77,    78,    79,     0,     0,
       0,    80,    81,     0,     0,     0,     0,     0,   128,   129,
      82,   130,    83,    84,   131,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   132,     0,     0,
       0,   133,     0,     0,   134,     0,     0,     0,   135,     0,
       0,     0,     0,   136,   137,     0,   138,   139,   140,   141,
     142,   143,     0,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,     0,   155,   156,   157,   158,   159,
     160,   161,   162,     0,     0,   163,   164,     0,     0,    85,
      86,    87,    47,    41,     0,     0,     0,     0,     0,   165,
     166,   167,    41,     0,    20,   168,   169,     0,    41,     0,
     171,    -6,   172,     0,    -6,     0,     0,    41,     0,     0,
      42,    43,     0,    -6,    44,    -6,     0,     0,     0,    42,
      43,     0,     0,    44,     0,    42,    43,     0,  -146,    44,
    -146,     0,     0,    45,    42,    43,   288,     0,    44,     0,
       0,     0,    45,    76,    77,    78,    79,     0,    45,     0,
      80,    81,     0,     0,     0,    46,     0,    45,     0,    82,
       0,    83,    84,    47,    46,    48,     0,     0,     0,     0,
      46,     0,    47,    41,    48,     0,     0,     0,    47,    46,
      48,    49,    41,    50,    51,     0,     0,    47,   289,    48,
      49,     0,    50,    51,     0,     0,    49,     0,    50,    51,
      42,    43,     0,     0,    44,    49,     0,    50,    51,    42,
      43,     0,     0,    44,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    45,     0,     0,     0,     0,    85,    86,
      87,     0,    45,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   320,     0,     0,    46,     0,     0,     0,     0,
       0,     0,     0,    47,    46,    48,     0,     0,     0,     0,
       0,     0,    47,     0,    48,     0,   128,   129,     0,   130,
     250,    49,   131,    50,    51,     0,     0,     0,     0,     0,
      49,     0,    50,    51,     0,   132,     0,     0,     0,   133,
       0,     0,   134,     0,     0,     0,   135,     0,     0,     0,
       0,   136,   137,     0,   138,   139,   140,   141,   142,   143,
       0,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,     0,   155,   156,   157,   158,   159,   160,   161,
     162,     0,     0,   163,   164,     0,   128,   129,     0,   130,
      47,     0,   131,     0,     0,     0,     0,   165,   166,   167,
       0,     0,    20,   168,   169,   132,   170,     0,   171,   133,
     172,     0,   134,     0,     0,     0,   135,     0,     0,     0,
       0,   136,   137,     0,   138,   139,   140,   141,   142,   143,
       0,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,     0,   155,   156,   157,   158,   159,   160,   161,
     162,     0,     0,   163,   164,     0,     0,     0,     0,     0,
      47,     0,     0,    76,    77,    78,    79,   165,   166,   167,
      80,    81,    20,   168,   169,     0,     0,     0,   171,    82,
     172,    83,    84,    76,    77,    78,    79,     0,     0,     0,
      80,    81,  -108,     0,     0,     0,     0,     0,     0,    82,
       0,    83,    84,     0,     0,  -108,    76,    77,    78,    79,
       0,  -108,     0,    80,    81,     0,     0,     0,     0,     0,
       0,     0,    82,     0,    83,    84,    76,    77,    78,    79,
       0,     0,     0,    80,    81,     0,     0,   247,     0,     0,
       0,     0,    82,     0,    83,    84,     0,     0,    85,    86,
      87,     0,     0,     0,     0,   248,  -108,  -108,     0,    76,
      77,    78,    79,     0,     0,     0,    80,    81,    85,    86,
      87,     0,     0,     0,   255,    82,     0,    83,    84,    76,
      77,    78,    79,     0,     0,     0,    80,    81,     0,     0,
     249,    85,    86,    87,     0,    82,     0,    83,    84,    76,
      77,    78,    79,     0,   252,     0,    80,    81,     0,     0,
       0,    85,    86,    87,     0,    82,     0,    83,    84,    76,
      77,    78,    79,     0,     0,     0,    80,    81,     0,     0,
       0,     0,     0,     0,     0,    82,     0,    83,    84,   253,
      76,    77,    78,    79,    85,    86,    87,    80,    81,     0,
       0,   254,     0,     0,     0,     0,    82,     0,    83,    84,
      76,    77,    78,    79,    85,    86,    87,    80,    81,   262,
       0,     0,     0,     0,     0,     0,    82,     0,    83,    84,
       0,     0,     0,     0,    85,    86,    87,     0,     0,   263,
       0,    76,    77,    78,    79,     0,     0,     0,    80,    81,
       0,     0,     0,     0,    85,    86,    87,    82,     0,    83,
      84,     0,    76,    77,    78,    79,     0,   264,     0,    80,
      81,     0,     0,     0,     0,    85,    86,    87,    82,     0,
      83,    84,    76,    77,    78,    79,     0,     0,   265,    80,
      81,     0,     0,     0,     0,    85,    86,    87,    82,     0,
      83,    84,     0,    76,    77,    78,    79,     0,   266,     0,
      80,    81,     0,     0,     0,     0,     0,     0,     0,    82,
       0,    83,    84,     0,     0,     0,    85,    86,    87,   267,
       0,     0,     0,     0,    76,    77,    78,    79,     0,     0,
       0,    80,    81,     0,     0,     0,     0,    85,    86,    87,
      82,     0,    83,    84,    76,    77,    78,    79,     0,     0,
       0,    80,    81,   268,     0,     0,     0,    85,    86,    87,
      82,     0,    83,    84,     0,    76,    77,    78,    79,     0,
       0,     0,    80,    81,     0,   296,     0,     0,    85,    86,
      87,    82,     0,    83,    84,    76,    77,    78,    79,     0,
       0,     0,    80,    81,     0,     0,     0,   311,     0,     0,
       0,    82,     0,    83,    84,    76,    77,    78,    79,    85,
      86,    87,    80,    81,   323,     0,     0,     0,     0,     0,
       0,    82,     0,    83,    84,    76,    77,    78,    79,    85,
      86,    87,    80,    81,   325,     0,     0,     0,     0,     0,
       0,    82,     0,    83,    84,     0,    76,    77,    78,    79,
      85,    86,    87,    80,    81,     0,   327,     0,     0,     0,
       0,     0,    82,     0,    83,    84,     0,     0,     0,     0,
      85,    86,    87,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      85,    86,    87,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      85,    86,    87,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    85,    86,    87
  };

  const short int
  Parser::yycheck_[] =
  {
      31,    30,    40,    69,    30,    36,   138,    73,   140,     8,
      41,   143,   144,   145,    16,     4,    16,    37,   103,   111,
      30,     8,   154,    33,    55,    56,   111,   111,    97,   161,
      29,   134,   164,    22,    15,    87,    87,    18,   111,    70,
       8,    72,    29,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    82,    96,   111,
     111,    29,     0,    94,   130,   134,    86,    10,    11,    29,
      30,    19,   103,    21,    22,    35,    19,    33,    21,    22,
     109,   147,   148,   109,    86,   151,   152,   153,    45,   120,
     121,   122,    87,    93,    51,    95,    45,   128,   129,   130,
      29,   132,    51,    32,   135,   136,   175,   138,   103,   140,
     141,   142,   143,   144,   145,   146,   111,   109,   149,   150,
      48,   111,    50,   154,    29,    30,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   240,   169,    32,
      88,    89,    90,   109,   133,    88,    89,    90,    33,   252,
     253,    48,    45,    50,    82,    31,    32,   188,    51,    31,
      32,     3,     4,     5,     6,    36,   197,    95,    10,    11,
      32,   240,    34,    31,    32,   307,   279,    19,    33,    21,
      22,    31,    32,   252,   253,    56,   140,   111,   254,   143,
      33,   145,    32,    35,    34,   298,    38,    39,    95,    33,
      42,    72,    33,    96,    97,    32,   272,    34,   311,   312,
     279,    32,    29,    34,   245,    33,    32,   248,    34,    61,
      32,    32,    34,    34,    87,   256,   257,   109,    11,   298,
     109,   262,   263,   264,   265,   266,   267,   268,    31,    32,
     109,    83,   311,   312,    32,   276,    88,    89,    90,    91,
      41,    93,    44,    32,    87,    38,    39,    33,    45,    42,
      37,    45,    33,    45,    33,    10,    86,   109,     8,   111,
     112,    86,   303,    86,    11,   175,   307,   308,    61,     3,
       4,     5,     6,   277,    -1,    -1,    10,    11,    -1,   320,
      73,    -1,   323,    -1,   325,    19,    -1,    21,    22,    -1,
      83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,    -1,
      93,    -1,    -1,    -1,    38,    39,    -1,    -1,    42,    -1,
     103,    -1,    -1,    -1,    -1,   108,   109,    -1,   111,   112,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,
      -1,    -1,    -1,    -1,    88,    89,    90,    91,    -1,    93,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,    -1,
      -1,    -1,    10,    11,    -1,   109,    -1,   111,   112,    17,
      18,    19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    -1,
      -1,    -1,    40,    -1,    -1,    43,    -1,    -1,    46,    47,
      -1,    -1,    -1,    -1,    52,    53,    -1,    55,    56,    57,
      58,    59,    60,    -1,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    -1,    74,    75,    76,    77,
      78,    79,    80,    81,    -1,    -1,    84,    85,    -1,    -1,
      88,    89,    90,    91,    -1,    -1,    -1,    -1,    -1,    -1,
      98,    99,   100,    -1,    -1,   103,   104,   105,    -1,    -1,
      -1,   109,    -1,   111,     3,     4,     5,     6,    -1,    -1,
      -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    17,    18,
      19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    -1,    -1,
      -1,    40,    -1,    -1,    43,    -1,    -1,    -1,    47,    -1,
      -1,    -1,    -1,    52,    53,    -1,    55,    56,    57,    58,
      59,    60,    -1,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    -1,    74,    75,    76,    77,    78,
      79,    80,    81,    -1,    -1,    84,    85,    -1,    -1,    88,
      89,    90,    91,    11,    -1,    -1,    -1,    -1,    -1,    98,
      99,   100,    11,    -1,   103,   104,   105,    -1,    11,    -1,
     109,    29,   111,    -1,    32,    -1,    -1,    11,    -1,    -1,
      38,    39,    -1,    32,    42,    34,    -1,    -1,    -1,    38,
      39,    -1,    -1,    42,    -1,    38,    39,    -1,    32,    42,
      34,    -1,    -1,    61,    38,    39,    49,    -1,    42,    -1,
      -1,    -1,    61,     3,     4,     5,     6,    -1,    61,    -1,
      10,    11,    -1,    -1,    -1,    83,    -1,    61,    -1,    19,
      -1,    21,    22,    91,    83,    93,    -1,    -1,    -1,    -1,
      83,    -1,    91,    11,    93,    -1,    -1,    -1,    91,    83,
      93,   109,    11,   111,   112,    -1,    -1,    91,   101,    93,
     109,    -1,   111,   112,    -1,    -1,   109,    -1,   111,   112,
      38,    39,    -1,    -1,    42,   109,    -1,   111,   112,    38,
      39,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,    88,    89,
      90,    -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   102,    -1,    -1,    83,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    91,    83,    93,    -1,    -1,    -1,    -1,
      -1,    -1,    91,    -1,    93,    -1,    17,    18,    -1,    20,
     108,   109,    23,   111,   112,    -1,    -1,    -1,    -1,    -1,
     109,    -1,   111,   112,    -1,    36,    -1,    -1,    -1,    40,
      -1,    -1,    43,    -1,    -1,    -1,    47,    -1,    -1,    -1,
      -1,    52,    53,    -1,    55,    56,    57,    58,    59,    60,
      -1,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    -1,    74,    75,    76,    77,    78,    79,    80,
      81,    -1,    -1,    84,    85,    -1,    17,    18,    -1,    20,
      91,    -1,    23,    -1,    -1,    -1,    -1,    98,    99,   100,
      -1,    -1,   103,   104,   105,    36,   107,    -1,   109,    40,
     111,    -1,    43,    -1,    -1,    -1,    47,    -1,    -1,    -1,
      -1,    52,    53,    -1,    55,    56,    57,    58,    59,    60,
      -1,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    -1,    74,    75,    76,    77,    78,    79,    80,
      81,    -1,    -1,    84,    85,    -1,    -1,    -1,    -1,    -1,
      91,    -1,    -1,     3,     4,     5,     6,    98,    99,   100,
      10,    11,   103,   104,   105,    -1,    -1,    -1,   109,    19,
     111,    21,    22,     3,     4,     5,     6,    -1,    -1,    -1,
      10,    11,    32,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      -1,    21,    22,    -1,    -1,    45,     3,     4,     5,     6,
      -1,    51,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    19,    -1,    21,    22,     3,     4,     5,     6,
      -1,    -1,    -1,    10,    11,    -1,    -1,    34,    -1,    -1,
      -1,    -1,    19,    -1,    21,    22,    -1,    -1,    88,    89,
      90,    -1,    -1,    -1,    -1,    32,    96,    97,    -1,     3,
       4,     5,     6,    -1,    -1,    -1,    10,    11,    88,    89,
      90,    -1,    -1,    -1,    94,    19,    -1,    21,    22,     3,
       4,     5,     6,    -1,    -1,    -1,    10,    11,    -1,    -1,
      34,    88,    89,    90,    -1,    19,    -1,    21,    22,     3,
       4,     5,     6,    -1,    28,    -1,    10,    11,    -1,    -1,
      -1,    88,    89,    90,    -1,    19,    -1,    21,    22,     3,
       4,     5,     6,    -1,    -1,    -1,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    19,    -1,    21,    22,    43,
       3,     4,     5,     6,    88,    89,    90,    10,    11,    -1,
      -1,    35,    -1,    -1,    -1,    -1,    19,    -1,    21,    22,
       3,     4,     5,     6,    88,    89,    90,    10,    11,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    19,    -1,    21,    22,
      -1,    -1,    -1,    -1,    88,    89,    90,    -1,    -1,    32,
      -1,     3,     4,     5,     6,    -1,    -1,    -1,    10,    11,
      -1,    -1,    -1,    -1,    88,    89,    90,    19,    -1,    21,
      22,    -1,     3,     4,     5,     6,    -1,    29,    -1,    10,
      11,    -1,    -1,    -1,    -1,    88,    89,    90,    19,    -1,
      21,    22,     3,     4,     5,     6,    -1,    -1,    29,    10,
      11,    -1,    -1,    -1,    -1,    88,    89,    90,    19,    -1,
      21,    22,    -1,     3,     4,     5,     6,    -1,    29,    -1,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      -1,    21,    22,    -1,    -1,    -1,    88,    89,    90,    29,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,    -1,    -1,
      -1,    10,    11,    -1,    -1,    -1,    -1,    88,    89,    90,
      19,    -1,    21,    22,     3,     4,     5,     6,    -1,    -1,
      -1,    10,    11,    32,    -1,    -1,    -1,    88,    89,    90,
      19,    -1,    21,    22,    -1,     3,     4,     5,     6,    -1,
      -1,    -1,    10,    11,    -1,    34,    -1,    -1,    88,    89,
      90,    19,    -1,    21,    22,     3,     4,     5,     6,    -1,
      -1,    -1,    10,    11,    -1,    -1,    -1,    35,    -1,    -1,
      -1,    19,    -1,    21,    22,     3,     4,     5,     6,    88,
      89,    90,    10,    11,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    19,    -1,    21,    22,     3,     4,     5,     6,    88,
      89,    90,    10,    11,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    19,    -1,    21,    22,    -1,     3,     4,     5,     6,
      88,    89,    90,    10,    11,    -1,    34,    -1,    -1,    -1,
      -1,    -1,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,
      88,    89,    90,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      88,    89,    90,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      88,    89,    90,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    88,    89,    90
  };

  const unsigned char
  Parser::yystos_[] =
  {
       0,    48,    50,    82,    95,   114,   121,   123,   125,   126,
     127,   128,   129,   111,   120,   124,   111,   119,   122,   111,
     103,   111,   115,   147,     0,   121,   123,   126,   127,   125,
     129,    30,   109,   118,    87,   119,    30,   118,    87,   119,
      33,    11,    38,    39,    42,    61,    83,    91,    93,   109,
     111,   112,   116,   140,   150,    29,    30,    87,   147,   148,
     150,   109,   148,   111,   130,   131,   150,   109,   117,    33,
      33,   111,    30,    33,    29,    32,     3,     4,     5,     6,
      10,    11,    19,    21,    22,    88,    89,    90,    73,   103,
     108,   150,   148,    31,    32,    31,    32,    34,    31,    32,
     116,   135,   150,    33,   148,   116,   150,   150,   150,   150,
     150,   150,   150,   150,   150,   150,   150,   150,   150,   150,
      33,    33,    33,    31,   118,   150,   118,   131,    17,    18,
      20,    23,    36,    40,    43,    47,    52,    53,    55,    56,
      57,    58,    59,    60,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    74,    75,    76,    77,    78,
      79,    80,    81,    84,    85,    98,    99,   100,   104,   105,
     107,   109,   111,   131,   132,   133,   134,   137,   138,   139,
     140,   141,   142,   143,   146,   147,   109,    34,    32,    34,
     149,   150,    31,    34,   150,   150,   150,    29,   150,   150,
     116,   150,   150,   147,   132,   150,   150,   135,   136,   150,
     135,   136,   150,   150,   135,   136,   135,   135,   136,   150,
     116,   116,   150,   150,   116,   116,   116,   135,   150,   150,
     150,   150,   135,   150,   150,   135,   150,   150,   150,   150,
     109,    35,    87,   134,   150,    32,    34,    34,    32,    34,
     108,   150,    28,    43,    35,    94,    41,    44,    45,    51,
      96,    97,    32,    32,    29,    29,    29,    29,    32,   132,
     150,   150,    33,   132,   132,   116,    37,   144,   145,   150,
     150,    45,    45,    51,    45,    51,   150,   150,    49,   101,
     150,   150,   150,   150,   150,    87,    34,   116,    16,    86,
     150,    86,   145,    46,   132,    45,    45,    33,    33,    34,
     132,    35,   150,    86,   135,   150,    86,   132,   132,    34,
     102,    86,   150,    32,   150,    32,   150,    34
  };

  const unsigned char
  Parser::yyr1_[] =
  {
       0,   113,   114,   114,   115,   115,   116,   116,   116,   116,
     117,   117,   117,   118,   118,   118,   119,   119,   119,   120,
     120,   120,   121,   121,   122,   122,   123,   123,   124,   124,
     125,   125,   125,   125,   125,   125,   126,   126,   127,   127,
     128,   128,   129,   129,   129,   130,   130,   130,   131,   132,
     132,   133,   133,   134,   134,   134,   134,   134,   134,   134,
     134,   134,   134,   134,   134,   134,   134,   134,   134,   134,
     134,   134,   134,   134,   134,   134,   134,   134,   134,   134,
     134,   134,   134,   134,   134,   134,   134,   134,   134,   134,
     134,   134,   134,   134,   134,   134,   134,   134,   134,   134,
     134,   134,   134,   134,   134,   134,   134,   134,   135,   135,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   137,   138,   139,   140,   140,   141,   141,   142,   142,
     143,   144,   144,   145,   146,   147,   147,   147,   147,   147,
     147,   147,   148,   148,   149,   149,   149,   150,   150,   150,
     150,   150,   150,   150,   150,   150,   150,   150,   150,   150,
     150,   150,   150,   150,   150,   150,   150,   150,   150,   150,
     150,   150,   150
  };

  const unsigned char
  Parser::yyr2_[] =
  {
       0,     2,     2,     2,     1,     2,     0,     1,     3,     0,
       1,     3,     0,     1,     2,     0,     0,     2,     5,     0,
       2,     5,     0,     3,     1,     2,     0,     3,     1,     2,
       1,     1,     1,     2,     2,     2,     0,     3,     0,     1,
       1,     2,     7,     0,     9,     1,     3,     0,     1,     0,
       1,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     2,     2,     1,     2,     2,
       2,     1,     2,     1,     1,     2,     2,     2,     2,     4,
       4,     2,     4,     2,     2,     2,     2,     2,     2,     2,
       2,    13,     7,     4,     4,     4,     4,     4,     2,     2,
       2,     2,     2,     2,     2,     1,     2,     1,     1,     3,
       2,     3,     4,     3,     2,     3,     3,     4,     3,     2,
       2,     1,     4,     4,     5,     2,     8,     6,     5,     7,
       5,     1,     2,     4,     2,     3,     8,     6,     9,     6,
       4,     6,     1,     3,     1,     3,     0,     0,     1,     3,
       1,     1,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     4,
       4,     4,     4
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "GE", "LE", "EQ", "NE",
  "GREATER", "LESS", "MINUS", "ADD", "SUB", "MULTIP", "DEVIDE", "UMINUS",
  "IFX", "ELSE", "IF", "While", "MUL", "PRINT", "LT", "GT", "RETURN",
  "NumberType", "TextType", "VoidType", "SPACE", "THEN", "ASS", "LR", "RR",
  "COMMA", "LC", "RC", "COLON", "SWITCH", "CASE", "FTRUE", "FFALSE", "FOR",
  "TO", "JOINTS_VAR", "DO", "UNTIL", "FINE", "STEP", "LDEPART", "JOINTS",
  "TRANS", "TRANS_DOT", "ALWAYS", "HERE", "BREAK", "DECOMPOSE", "SPEED",
  "ALIGN", "ACCURACY", "LAPPRO", "JAPPRO", "DRAW", "DECODE", "DRIVE",
  "TDRAW", "POINT", "TCP_SEND", "TCP_CLOSE", "C1MOVE", "LMOVE", "TCP_RECV",
  "TCP_CONNECT", "TCP_STATUS", "WEIGHT", "VAL", "STOP", "HOME", "BASE",
  "TOOL", "TYPE", "TWAIT", "SIGNAL", "GOTO", "FUNC", "SIG", "JMOVE",
  "SWAIT", "END_ST", "END_DOT", "AND", "OR", "MOD", "CALL", "DEFAULT",
  "FNULL", "OF", "DEFINES", "MM_S", "MM_MIN", "POINT_X", "POINT_Z",
  "POINT_OAT", "SHIFT", "BY", "BITS", "PAUSE", "PULSE", "DOLAR", "JIN",
  "DISTANCE", "Number", "LNumber", "Identifier", "String", "$accept",
  "program", "assignment_list", "expression_comma_list", "str_comma_list",
  "str_list", "TRANS_STR_stm", "JOINTS_STR_stm", "TRANS_head",
  "TRANS_list", "JOINTS_head", "JOINTS_list", "DEFINES_list",
  "DEFINES_head", "body", "function_declaration_list",
  "function_declaration", "parameter_declaration_list",
  "parameter_declaration", "function_body", "statement_list", "statement",
  "signal_num_stm", "param_stm", "return", "while_loop", "do_until",
  "function_call", "for", "if", "switch", "switch_case_list",
  "switch_case_define", "print", "assignment", "dim_num_stm",
  "expression_list", "expression", YY_NULL
  };

#if YYDEBUG
  const unsigned short int
  Parser::yyrline_[] =
  {
       0,   149,   149,   150,   154,   155,   158,   159,   160,   161,
     166,   171,   176,   180,   185,   190,   194,   196,   200,   206,
     208,   212,   218,   222,   226,   227,   231,   235,   239,   240,
     244,   245,   246,   247,   248,   249,   253,   257,   261,   264,
     268,   269,   273,   274,   275,   285,   286,   287,   291,   296,
     297,   301,   302,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,   332,
     333,   334,   335,   336,   337,   338,   339,   340,   341,   342,
     343,   344,   348,   349,   350,   351,   352,   354,   355,   356,
     357,   358,   359,   360,   362,   363,   364,   365,   377,   381,
     388,   392,   396,   400,   404,   408,   412,   416,   420,   424,
     428,   434,   438,   442,   446,   447,   452,   453,   457,   458,
     462,   469,   474,   481,   488,   493,   495,   497,   499,   501,
     503,   505,   512,   516,   525,   526,   527,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   550,   551,   552,   553,   554,
     555,   556,   557
  };

  // Print the state stack on the debug stream.
  void
  Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  Parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  // Symbol number corresponding to token number t.
  inline
  Parser::token_number_type
  Parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112
    };
    const unsigned int user_token_number_max_ = 367;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }

#line 5 "grammar\\parser.y" // lalr1.cc:1156
} // Language
#line 2523 "D:\\FreeCAD-0.19.1-build\\src\\Mod\\kawasaki\\kawasaki\\\\kawasaki\\grammar\\parser.tab.cpp" // lalr1.cc:1156
#line 563 "grammar\\parser.y" // lalr1.cc:1157




void Language::Parser::error( const std::string &err_message )
{
   std::cerr << "Error: Line:" << lineNumber << "' - " << err_message << "\n";
}

static int yylex( Language::Parser::semantic_type *yylval, Language::Lexer  &lexer)
{
   return( lexer.yylex(yylval) );
}

