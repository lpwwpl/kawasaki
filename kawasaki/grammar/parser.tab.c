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

#line 37 "parser.tab.c" // lalr1.cc:398

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

#include "parser.tab.h"

// User implementation prologue.

#line 51 "parser.tab.c" // lalr1.cc:406
// Unqualified %code blocks.
#line 40 "parser.y" // lalr1.cc:407

    #include "translator.hpp"
    #include "ast.h"
    extern int lineNumber;
    static int yylex(Language::Parser::semantic_type *yylval, Language::Lexer  &lexer);

#line 60 "parser.tab.c" // lalr1.cc:407


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

#line 5 "parser.y" // lalr1.cc:473
namespace Language {
#line 127 "parser.tab.c" // lalr1.cc:473

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
#line 94 "parser.y" // lalr1.cc:846
    {}
#line 561 "parser.tab.c" // lalr1.cc:846
    break;

  case 3:
#line 95 "parser.y" // lalr1.cc:846
    {}
#line 567 "parser.tab.c" // lalr1.cc:846
    break;

  case 4:
#line 99 "parser.y" // lalr1.cc:846
    { }
#line 573 "parser.tab.c" // lalr1.cc:846
    break;

  case 5:
#line 100 "parser.y" // lalr1.cc:846
    {}
#line 579 "parser.tab.c" // lalr1.cc:846
    break;

  case 6:
#line 104 "parser.y" // lalr1.cc:846
    {}
#line 585 "parser.tab.c" // lalr1.cc:846
    break;

  case 7:
#line 106 "parser.y" // lalr1.cc:846
    {
    (yylhs.value.trans_str_stmNode) = new TransStrNode((yystack_[0].value.sval));
    }
#line 593 "parser.tab.c" // lalr1.cc:846
    break;

  case 8:
#line 112 "parser.y" // lalr1.cc:846
    {}
#line 599 "parser.tab.c" // lalr1.cc:846
    break;

  case 9:
#line 113 "parser.y" // lalr1.cc:846
    {}
#line 605 "parser.tab.c" // lalr1.cc:846
    break;

  case 10:
#line 114 "parser.y" // lalr1.cc:846
    {}
#line 611 "parser.tab.c" // lalr1.cc:846
    break;

  case 11:
#line 115 "parser.y" // lalr1.cc:846
    {}
#line 617 "parser.tab.c" // lalr1.cc:846
    break;

  case 12:
#line 119 "parser.y" // lalr1.cc:846
    {

	}
#line 625 "parser.tab.c" // lalr1.cc:846
    break;

  case 13:
#line 123 "parser.y" // lalr1.cc:846
    {}
#line 631 "parser.tab.c" // lalr1.cc:846
    break;

  case 14:
#line 127 "parser.y" // lalr1.cc:846
    {
	}
#line 638 "parser.tab.c" // lalr1.cc:846
    break;

  case 15:
#line 130 "parser.y" // lalr1.cc:846
    { (yystack_[0].value.listNode)->Execute(); }
#line 644 "parser.tab.c" // lalr1.cc:846
    break;

  case 16:
#line 134 "parser.y" // lalr1.cc:846
    { (yylhs.value.listNode) = new ListNode<ASTNode>((yystack_[0].value.functionNode));}
#line 650 "parser.tab.c" // lalr1.cc:846
    break;

  case 17:
#line 135 "parser.y" // lalr1.cc:846
    {(yystack_[1].value.listNode)->push_back((yystack_[0].value.functionNode));}
#line 656 "parser.tab.c" // lalr1.cc:846
    break;

  case 18:
#line 139 "parser.y" // lalr1.cc:846
    {(yylhs.value.functionNode) = new FunctionNode(token::VoidType, (yystack_[5].value.sval), (yystack_[3].value.parameterListNode), (yystack_[1].value.statementListNode)); }
#line 662 "parser.tab.c" // lalr1.cc:846
    break;

  case 19:
#line 149 "parser.y" // lalr1.cc:846
    { (yylhs.value.parameterListNode) = new ListNode<ParameterNode>((yystack_[0].value.parameterNode)); }
#line 668 "parser.tab.c" // lalr1.cc:846
    break;

  case 20:
#line 150 "parser.y" // lalr1.cc:846
    {(yystack_[2].value.parameterListNode)->push_back((yystack_[0].value.parameterNode));}
#line 674 "parser.tab.c" // lalr1.cc:846
    break;

  case 21:
#line 151 "parser.y" // lalr1.cc:846
    {(yylhs.value.parameterListNode) = new ListNode<ParameterNode>();}
#line 680 "parser.tab.c" // lalr1.cc:846
    break;

  case 22:
#line 155 "parser.y" // lalr1.cc:846
    {(yylhs.value.parameterNode) = new ParameterNode((yystack_[0].value.sval));}
#line 686 "parser.tab.c" // lalr1.cc:846
    break;

  case 23:
#line 156 "parser.y" // lalr1.cc:846
    {(yylhs.value.parameterNode) = new ParameterNode((yystack_[2].value.sval), (yystack_[0].value.pNode));}
#line 692 "parser.tab.c" // lalr1.cc:846
    break;

  case 24:
#line 160 "parser.y" // lalr1.cc:846
    {(yylhs.value.statementListNode) = (yystack_[0].value.statementListNode);}
#line 698 "parser.tab.c" // lalr1.cc:846
    break;

  case 25:
#line 164 "parser.y" // lalr1.cc:846
    {(yylhs.value.statementListNode) = new StatementListNode((yystack_[0].value.pNode));}
#line 704 "parser.tab.c" // lalr1.cc:846
    break;

  case 26:
#line 165 "parser.y" // lalr1.cc:846
    {(yystack_[1].value.statementListNode)->push_back((yystack_[0].value.pNode));}
#line 710 "parser.tab.c" // lalr1.cc:846
    break;

  case 27:
#line 169 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = (yystack_[0].value.parameterNode);}
#line 716 "parser.tab.c" // lalr1.cc:846
    break;

  case 28:
#line 170 "parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = (yystack_[0].value.pNode);}
#line 722 "parser.tab.c" // lalr1.cc:846
    break;

  case 29:
#line 171 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = (yystack_[0].value.pNode);}
#line 728 "parser.tab.c" // lalr1.cc:846
    break;

  case 30:
#line 172 "parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = (yystack_[0].value.pNode);}
#line 734 "parser.tab.c" // lalr1.cc:846
    break;

  case 31:
#line 173 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = (yystack_[0].value.pNode); }
#line 740 "parser.tab.c" // lalr1.cc:846
    break;

  case 32:
#line 174 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = (yystack_[0].value.pNode); }
#line 746 "parser.tab.c" // lalr1.cc:846
    break;

  case 33:
#line 175 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = (yystack_[0].value.pNode);}
#line 752 "parser.tab.c" // lalr1.cc:846
    break;

  case 34:
#line 176 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new StopNode(NULL); }
#line 758 "parser.tab.c" // lalr1.cc:846
    break;

  case 35:
#line 177 "parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = new BaseNode((yystack_[0].value.pNode));}
#line 764 "parser.tab.c" // lalr1.cc:846
    break;

  case 36:
#line 178 "parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = new ToolNode((yystack_[0].value.pNode));}
#line 770 "parser.tab.c" // lalr1.cc:846
    break;

  case 37:
#line 179 "parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = new TWaitNode((yystack_[0].value.pNode));}
#line 776 "parser.tab.c" // lalr1.cc:846
    break;

  case 38:
#line 180 "parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = new JMoveNode((yystack_[0].value.pNode));}
#line 782 "parser.tab.c" // lalr1.cc:846
    break;

  case 39:
#line 181 "parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = new HomeNode((yystack_[0].value.pNode));}
#line 788 "parser.tab.c" // lalr1.cc:846
    break;

  case 40:
#line 182 "parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = new SignalNode((yystack_[0].value.signal_num_stmNode));}
#line 794 "parser.tab.c" // lalr1.cc:846
    break;

  case 41:
#line 183 "parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = new SigNode((yystack_[0].value.pNode));}
#line 800 "parser.tab.c" // lalr1.cc:846
    break;

  case 42:
#line 184 "parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = new SWaitNode((yystack_[0].value.signal_num_stmNode));}
#line 806 "parser.tab.c" // lalr1.cc:846
    break;

  case 43:
#line 185 "parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = new TypeNode((yystack_[0].value.pNode));}
#line 812 "parser.tab.c" // lalr1.cc:846
    break;

  case 44:
#line 186 "parser.y" // lalr1.cc:846
    {  (yylhs.value.pNode) = new GotoNode((yystack_[0].value.pNode));}
#line 818 "parser.tab.c" // lalr1.cc:846
    break;

  case 45:
#line 196 "parser.y" // lalr1.cc:846
    {
        (yylhs.value.signal_num_stmNode) = new SignalNumsNode((yystack_[0].value.pNode)); 
    }
#line 826 "parser.tab.c" // lalr1.cc:846
    break;

  case 46:
#line 200 "parser.y" // lalr1.cc:846
    {
		(yystack_[2].value.signal_num_stmNode)->push_back((yystack_[0].value.pNode));    
	}
#line 834 "parser.tab.c" // lalr1.cc:846
    break;

  case 47:
#line 206 "parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = new ReturnNode(NULL); }
#line 840 "parser.tab.c" // lalr1.cc:846
    break;

  case 48:
#line 210 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new WhileNode((yystack_[2].value.pNode), (yystack_[0].value.statementListNode)); }
#line 846 "parser.tab.c" // lalr1.cc:846
    break;

  case 49:
#line 214 "parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = new FunctionCallNode((yystack_[3].value.sval), (yystack_[1].value.listNode));}
#line 852 "parser.tab.c" // lalr1.cc:846
    break;

  case 50:
#line 215 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new FunctionCallNode((yystack_[0].value.sval), new ListNode<ASTNode>());}
#line 858 "parser.tab.c" // lalr1.cc:846
    break;

  case 51:
#line 219 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new IfNode((yystack_[2].value.pNode), (yystack_[1].value.statementListNode)); }
#line 864 "parser.tab.c" // lalr1.cc:846
    break;

  case 52:
#line 220 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new IfNode((yystack_[4].value.pNode), (yystack_[3].value.statementListNode), (yystack_[1].value.statementListNode)); }
#line 870 "parser.tab.c" // lalr1.cc:846
    break;

  case 53:
#line 224 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new PrintNode((yystack_[0].value.pNode));}
#line 876 "parser.tab.c" // lalr1.cc:846
    break;

  case 54:
#line 228 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new AssignmentNode((yystack_[2].value.sval), (yystack_[0].value.pNode));}
#line 882 "parser.tab.c" // lalr1.cc:846
    break;

  case 55:
#line 231 "parser.y" // lalr1.cc:846
    { 
        (yylhs.value.pNode) = new AssignmentNode((yystack_[5].value.sval), (yystack_[0].value.pNode), (yystack_[3].value.dim_num_stmNode));
    }
#line 890 "parser.tab.c" // lalr1.cc:846
    break;

  case 56:
#line 237 "parser.y" // lalr1.cc:846
    {
        //NumberLiteralNode* node  = new NumberLiteralNode($1);
        (yylhs.value.dim_num_stmNode) = new DimNumsNode((yystack_[0].value.pNode)); //$$->dimListType->push_back($1);
    }
#line 899 "parser.tab.c" // lalr1.cc:846
    break;

  case 57:
#line 242 "parser.y" // lalr1.cc:846
    {
        (yystack_[2].value.dim_num_stmNode)->push_back((yystack_[0].value.pNode));   
        //NumberLiteralNode* node = new NumberLiteralNode($3);
		//$1->push_back(node);    
	}
#line 909 "parser.tab.c" // lalr1.cc:846
    break;

  case 58:
#line 250 "parser.y" // lalr1.cc:846
    { (yylhs.value.listNode) = new ListNode<ASTNode>((yystack_[0].value.pNode)); }
#line 915 "parser.tab.c" // lalr1.cc:846
    break;

  case 59:
#line 251 "parser.y" // lalr1.cc:846
    {(yystack_[2].value.listNode)->push_back((yystack_[0].value.pNode));}
#line 921 "parser.tab.c" // lalr1.cc:846
    break;

  case 60:
#line 252 "parser.y" // lalr1.cc:846
    {(yylhs.value.listNode) = new ListNode<ASTNode>(); }
#line 927 "parser.tab.c" // lalr1.cc:846
    break;

  case 61:
#line 256 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new IdentifierNode((yystack_[0].value.sval)); }
#line 933 "parser.tab.c" // lalr1.cc:846
    break;

  case 62:
#line 257 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new StringLiteralNode((yystack_[0].value.sval));}
#line 939 "parser.tab.c" // lalr1.cc:846
    break;

  case 63:
#line 258 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = NULL;}
#line 945 "parser.tab.c" // lalr1.cc:846
    break;

  case 64:
#line 259 "parser.y" // lalr1.cc:846
    {(yylhs.value.pNode) = new NumberLiteralNode((yystack_[0].value.dval)); }
#line 951 "parser.tab.c" // lalr1.cc:846
    break;

  case 65:
#line 260 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = (yystack_[0].value.pNode);}
#line 957 "parser.tab.c" // lalr1.cc:846
    break;

  case 66:
#line 261 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new OperatorNode(token::UMINUS, (yystack_[0].value.pNode)); }
#line 963 "parser.tab.c" // lalr1.cc:846
    break;

  case 67:
#line 262 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new OperatorNode(token::ADD, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 969 "parser.tab.c" // lalr1.cc:846
    break;

  case 68:
#line 263 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new OperatorNode(token::SUB, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 975 "parser.tab.c" // lalr1.cc:846
    break;

  case 69:
#line 264 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new OperatorNode(token::MUL, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 981 "parser.tab.c" // lalr1.cc:846
    break;

  case 70:
#line 265 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new OperatorNode(token::DIV, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 987 "parser.tab.c" // lalr1.cc:846
    break;

  case 71:
#line 266 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new OperatorNode(token::LT, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 993 "parser.tab.c" // lalr1.cc:846
    break;

  case 72:
#line 267 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new OperatorNode(token::GT, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 999 "parser.tab.c" // lalr1.cc:846
    break;

  case 73:
#line 268 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new OperatorNode(token::GE, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 1005 "parser.tab.c" // lalr1.cc:846
    break;

  case 74:
#line 269 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new OperatorNode(token::LE, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 1011 "parser.tab.c" // lalr1.cc:846
    break;

  case 75:
#line 270 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new OperatorNode(token::NE, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 1017 "parser.tab.c" // lalr1.cc:846
    break;

  case 76:
#line 271 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = new OperatorNode(token::EQ, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 1023 "parser.tab.c" // lalr1.cc:846
    break;

  case 77:
#line 272 "parser.y" // lalr1.cc:846
    { (yylhs.value.pNode) = (yystack_[1].value.pNode); }
#line 1029 "parser.tab.c" // lalr1.cc:846
    break;


#line 1033 "parser.tab.c" // lalr1.cc:846
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


  const signed char Parser::yypact_ninf_ = -50;

  const signed char Parser::yytable_ninf_ = -1;

  const short int
  Parser::yypact_[] =
  {
     -33,   -49,   -45,   -50,    12,   -50,   -33,   -50,   -12,   -24,
     -50,   -10,    24,   -34,   -50,   -50,   -50,   -50,   -50,   -12,
     -50,   -32,   109,   109,   -50,   -50,     3,    35,   -50,   109,
      21,   -50,   -50,   -50,   -50,   109,   -50,   198,    16,   198,
     109,   145,   -32,   -50,    29,    48,   109,   109,   109,   109,
     109,   109,   109,   109,   109,   109,   109,    31,   198,   109,
      38,   109,   -50,   -50,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   109,    36,   -50,    61,   145,   -50,   -50,
     -50,   -50,   -50,   -50,   -50,   -50,   109,   -50,    71,    71,
      71,    71,    71,    71,    87,    87,   -50,   -50,   198,   109,
     105,   109,   198,   198,   198,   198,   198,   198,    46,   198,
     198,   198,   198,    46,   109,   -50,   -50,    43,   198,   198,
      -7,    62,   109,   198,   -50,   109,   145,   -50,   145,   198,
     198,    65,   -50,   -50
  };

  const unsigned char
  Parser::yydefact_[] =
  {
       6,     0,     0,     7,     0,     9,     6,     8,     6,    15,
      16,     0,     0,     0,     4,     1,    10,    11,     3,     2,
      17,    21,     0,     0,    13,     5,    22,     0,    19,     0,
       0,    63,    64,    61,    62,     0,    65,    54,     0,    56,
       0,     0,     0,    66,    50,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    23,     0,
       0,     0,    47,    34,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    22,    27,     0,    24,    25,    33,
      31,    30,    32,    29,    28,    20,    60,    77,    73,    74,
      76,    75,    72,    71,    68,    67,    69,    70,    57,     0,
       0,     0,    53,    39,    35,    36,    43,    37,    40,    45,
      44,    41,    38,    42,     0,    18,    26,     0,    58,    55,
       0,     0,     0,    23,    49,     0,     0,    51,     0,    46,
      59,     0,    48,    52
  };

  const signed char
  Parser::yypgoto_[] =
  {
     -50,   -50,   -50,    -3,   111,    -2,   117,   -50,   115,   -50,
      -6,   -38,   -50,    49,    52,   -50,   -50,   -39,   -50,   -50,
       9,   -50,   -50,   -22
  };

  const signed char
  Parser::yydefgoto_[] =
  {
      -1,     4,    13,     5,     6,     7,     8,     9,    10,    27,
      75,    76,    77,    78,   108,    79,    80,    36,    82,    83,
      84,    38,   117,   109
  };

  const unsigned char
  Parser::yytable_[] =
  {
      37,    39,    81,    16,    17,     1,    11,    43,   126,    24,
      12,    14,    15,    45,     1,    28,    16,    17,    58,     2,
       3,    12,    25,    26,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,   127,    85,   100,    81,   102,
       2,     3,   103,   104,   105,   106,   107,    21,   110,   111,
     112,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    81,   120,    40,   118,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    44,   119,    57,   121,
      52,    53,    54,    55,    22,    23,    86,    81,   131,    81,
     132,    99,   123,    41,    42,   101,   114,    23,    54,    55,
     129,   124,   125,   130,   115,   122,    87,   133,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    29,    19,
     128,    59,    60,    18,    20,   113,   116,    61,     0,     0,
      62,     0,     0,     0,     0,    63,    64,    65,    66,    67,
      68,    69,    70,     0,    71,    72,    73,     0,     0,     0,
       0,     0,    30,     0,     0,     0,    30,     0,     0,    31,
      74,    59,    60,    32,    33,    34,    35,    61,     0,     0,
      62,     0,     0,     0,     0,    63,    64,    65,    66,    67,
      68,    69,    70,     0,    71,    72,    73,     0,     0,     0,
       0,     0,    30,     0,     0,     0,     0,     0,     0,     0,
      74,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55
  };

  const short int
  Parser::yycheck_[] =
  {
      22,    23,    41,     6,     6,    38,    55,    29,    15,    43,
      55,     2,     0,    35,    38,    21,    19,    19,    40,    52,
      53,    55,    13,    55,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    42,    42,    59,    77,    61,
      52,    53,    64,    65,    66,    67,    68,    57,    70,    71,
      72,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,   100,   100,    60,    86,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    59,    55,    99,    62,   101,
       9,    10,    11,    12,    60,    61,    57,   126,   126,   128,
     128,    60,   114,    58,    59,    57,    60,    61,    11,    12,
     122,    58,    59,   125,    43,    59,    58,    42,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,     9,     8,
      58,    16,    17,     6,     9,    73,    77,    22,    -1,    -1,
      25,    -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    39,    40,    41,    -1,    -1,    -1,
      -1,    -1,    47,    -1,    -1,    -1,    47,    -1,    -1,    50,
      55,    16,    17,    54,    55,    56,    57,    22,    -1,    -1,
      25,    -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    39,    40,    41,    -1,    -1,    -1,
      -1,    -1,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      55,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12
  };

  const unsigned char
  Parser::yystos_[] =
  {
       0,    38,    52,    53,    64,    66,    67,    68,    69,    70,
      71,    55,    55,    65,    83,     0,    66,    68,    69,    67,
      71,    57,    60,    61,    43,    83,    55,    72,    73,     9,
      47,    50,    54,    55,    56,    57,    80,    86,    84,    86,
      60,    58,    59,    86,    55,    86,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    59,    62,    86,    16,
      17,    22,    25,    30,    31,    32,    33,    34,    35,    36,
      37,    39,    40,    41,    55,    73,    74,    75,    76,    78,
      79,    80,    81,    82,    83,    73,    57,    58,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    60,
      86,    57,    86,    86,    86,    86,    86,    86,    77,    86,
      86,    86,    86,    77,    60,    43,    76,    85,    86,    86,
      74,    86,    59,    86,    58,    59,    15,    42,    58,    86,
      86,    74,    74,    42
  };

  const unsigned char
  Parser::yyr1_[] =
  {
       0,    63,    64,    64,    65,    65,    66,    66,    67,    67,
      67,    67,    68,    68,    69,    69,    70,    70,    71,    72,
      72,    72,    73,    73,    74,    75,    75,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    77,    77,    78,    79,    80,
      80,    81,    81,    82,    83,    83,    84,    84,    85,    85,
      85,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86
  };

  const unsigned char
  Parser::yyr2_[] =
  {
       0,     2,     2,     2,     1,     2,     0,     1,     1,     1,
       2,     2,     0,     3,     0,     1,     1,     2,     7,     1,
       3,     0,     1,     3,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     1,     3,     1,     5,     5,
       2,     4,     6,     2,     3,     6,     1,     3,     1,     3,
       0,     1,     1,     1,     1,     1,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "GE", "LE", "EQ", "NE", "'>'",
  "'<'", "'-'", "'+'", "'*'", "'/'", "UMINUS", "IFX", "ELSE", "IF",
  "While", "ADD", "SUB", "MUL", "DIV", "PRINT", "LT", "GT", "RETURN",
  "NumberType", "TextType", "VoidType", "ArrayType", "STOP", "HOME",
  "BASE", "TOOL", "TYPE", "TWAIT", "SIGNAL", "GOTO", "FUNC", "SIG",
  "JMOVE", "SWAIT", "END_ST", "END_DOT", "AND", "OR", "SWITCH", "CALL",
  "CASE", "DEFAULT", "FNULL", "OF", "DEFINES", "TRANS_STR", "Number",
  "Identifier", "String", "'('", "')'", "','", "'='", "'['", "']'",
  "$accept", "program", "assignment_list", "TRANS_STR_stm", "DEFINES_list",
  "DEFINES_head", "body", "function_declaration_list",
  "function_declaration", "parameter_declaration_list",
  "parameter_declaration", "function_body", "statement_list", "statement",
  "signal_num_stm", "return", "while_loop", "function_call", "if", "print",
  "assignment", "dim_num_stm", "expression_list", "expression", YY_NULL
  };

#if YYDEBUG
  const unsigned short int
  Parser::yyrline_[] =
  {
       0,    94,    94,    95,    99,   100,   104,   106,   112,   113,
     114,   115,   119,   123,   127,   130,   134,   135,   139,   149,
     150,   151,   155,   156,   160,   164,   165,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   195,   199,   206,   210,   214,
     215,   219,   220,   224,   228,   230,   237,   241,   250,   251,
     252,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272
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
      57,    58,    11,    10,    59,     9,     2,    12,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       8,    60,     7,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    61,     2,    62,     2,     2,     2,     2,     2,     2,
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
       5,     6,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56
    };
    const unsigned int user_token_number_max_ = 305;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }

#line 5 "parser.y" // lalr1.cc:1156
} // Language
#line 1559 "parser.tab.c" // lalr1.cc:1156
#line 277 "parser.y" // lalr1.cc:1157




void Language::Parser::error( const std::string &err_message )
{
   std::cerr << "Error: Line:" << lineNumber << "' - " << err_message << "\n";
}

static int yylex( Language::Parser::semantic_type *yylval, Language::Lexer  &lexer)
{
   return( lexer.yylex(yylval) );
}

