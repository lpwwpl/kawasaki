
%defines 

%{
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
%}

%pure-parser

%define parse.error verbose

%param       {void * parm}

%locations
%token ELSEIF
%token SIGNAL
%token LINE_GAP
%token GAP
%token TYPE

%token END_OF_LINE
%token CALL
%token TRANS
%token BASE
%token TOOL
%token STOP
%token HOME
%token GOTO
%token REALS
%token STRINGS
%token JOINTS
%token TO
%token JMOVE
%token RETURN
%token FUNC
%token FTRUE
%token FFALSE
%token IF
%token THEN
%token ELSE
%token END_ST
%token END_DOT

%token STRING_DEFINITION
%token IDENTIFIER
%token NUMBER
%token SINGLE_LINE_COMMENT
%token DIVIDE_MOD
%token ARG_SPLITTER
%token PLUS
%token MINUS
%token DIVIDE
%token MULTIPLY
%token ASSIGN
%token MORE
%token LESS
%token MORE_OR_EQUAL
%token LESS_OR_EQUAL
%token EQUAL
%token NOT_EQUAL
%token OPEN_BRACKET
%token CLOSE_BRACKET
%token AND
%token OR
%token FKFLOAT
%token SWAIT
%token COLON
%token FOR
%token OPEN_SQUARE_BRACKET
%token CLOSE_SQUARE_BRACKET
%token IDENTIFIER_DOT
%token IDENTIFIER_POINTER
%token FNULL
%token SWITCH CASE DEFAULT
%token SIG
%token QUOTATION
%token TWAIT
%token SPACE
%token OF 
%right ASSIGN
%left  OR
%left  AND
%left  MORE LESS MORE_OR_EQUAL LESS_OR_EQUAL EQUAL NOT_EQUAL
%left PLUS MINUS
%left DIVIDE MULTIPLY DIVIDE_MOD
%left  OPEN_BRACKET   /* Precedence added for the array subscript expression (foo[N]) */
%left  CLOSE_BRACKET  /* Array subscript/access precedence */
%left  DOT  /* Member access with the dot operator (foo.bar) */


//%expect 4
%type<str> IDENTIFIER  
%type<str> NUMBER
%type<str> STRING_DEFINITION
%type<str> PLUS
%type<str> MINUS
%type<str> END_ST
%type<str> END_DOT
%type<str> DIVIDE
%type<str> MULTIPLY
%type<str> DIVIDE_MOD
%type<str> MORE LESS MORE_OR_EQUAL LESS_OR_EQUAL EQUAL NOT_EQUAL
%type<str> FTRUE FFALSE
%type<str> ASSIGN
%type<str> AND OR
%type<str> FKFLOAT FNULL
%type<str> IDENTIFIER_DOT  
%type<str> IDENTIFIER_POINTER  
%type<str> signal_num_stm

//%type <syntree> dimension_list
%type<syntree> math_expr
%type<syntree> block
%type<syntree> stmt
%type<syntree> else_stmt
%type<syntree> if_stmt
%type<syntree> cmp
%type<syntree> body
%type<syntree> return_stmt
%type<syntree> explicit_value
%type<syntree> variable
%type<syntree> expr
%type<syntree> var
%type<syntree> assign_stmt
%type<syntree> cmp_value
%type<syntree> assign_value
%type<syntree> expr_value
%type<syntree> for_stmt
%type<syntree> switch_stmt
%type<syntree> switch_case_define
%type<syntree> switch_case_list
%type<syntree> function_declaration
%type<syntree> function_declaration_arguments
%type<syntree> arg
%type<syntree> arg_expr
%type<syntree> function_call_arguments
%type<syntree> function_call
%type<syntree> GOTO_stm LABEL_stm HOME_stm TOOL_stm BASE_stm TYPE_stm STOP_stm
%type<syntree> SIGNAL_stm
%type<syntree>  JMOVE_stm
%type<syntree> SWAIT_stm TWAIT_stm
%type<syntree>  STRINGS_head  TRANS_head trans_define FKFLOATs_define REALS_head 
%type<syntree> strings_define reals_define 
//const_array_list_value
%type<syntree> SIG_stm 
//access_expr
%%

/* Top level rules */
program: 	
	body REALS_head TRANS_head STRINGS_head
	;

TRANS_head:
	%empty
	{
	}
	|
	TRANS trans_define END_DOT{}
	;

trans_define:
	IDENTIFIER ASSIGN FKFLOATs_define
	{
	myflexer *l = (myflexer *)parm;
	}
	|
	IDENTIFIER OPEN_SQUARE_BRACKET dimension_list CLOSE_SQUARE_BRACKET ASSIGN FKFLOATs_define 
	{
	myflexer *l = (myflexer *)parm;
	}
	;

FKFLOATs_define:
	FKFLOAT {}
	| FKFLOAT GAP FKFLOATs_define {}
	;

REALS_head:
	%empty
	{
	}
	|
	REALS reals_define END_DOT{}
	;

reals_define:
	IDENTIFIER ASSIGN FKFLOAT
	{
		/*FKLOG("[bison]: const_define %s", $1.c_str());
		myflexer *l = (myflexer *)parm;
		l->add_const_desc($1.c_str(), $3);*/
		myflexer *l = (myflexer *)parm;
	}
	|
	IDENTIFIER OPEN_SQUARE_BRACKET dimension_list CLOSE_SQUARE_BRACKET ASSIGN FKFLOAT 
	{
	myflexer *l = (myflexer *)parm;
	}
	;

STRINGS_head:
	%empty
	{
	}
	|
	STRINGS strings_define END_DOT
	{
	}
	;


strings_define:
	IDENTIFIER ASSIGN STRING_DEFINITION {
		NEWTYPE(p, strings_define);
		p->var = $3;
		$$ = p;

		myflexer *l = (myflexer *)parm;
	} 
	|
	IDENTIFIER OPEN_SQUARE_BRACKET dimension_list CLOSE_SQUARE_BRACKET ASSIGN STRING_DEFINITION  
	{
		NEWTYPE(p, strings_define);
		p->var = $6;
		$$ = p;
		myflexer *l = (myflexer *)parm;

	}
	;


body:
	%empty
	{
	}
	|
	function_declaration
	|
	body function_declaration
	;


/* function declaration begin */

function_declaration:
	FUNC IDENTIFIER OPEN_BRACKET function_declaration_arguments CLOSE_BRACKET block END_DOT
	{
		FKLOG("[bison]: function_declaration <- block %s %d", $2.c_str(), yylloc.first_line);
		NEWTYPE(p, func_desc_node);
		p->funcname = $2;
		p->arglist = dynamic_cast<func_desc_arglist_node*>($4);
		p->block = dynamic_cast<block_node*>($6);
		p->endline = yylloc.first_line;
		myflexer *l = (myflexer *)parm;
		l->add_func_desc(p);
	}
	;

function_declaration_arguments: 
	%empty
	{
		$$ = 0;
	}
	| 
	function_declaration_arguments ARG_SPLITTER arg 
	{
		FKLOG("[bison]: function_declaration_arguments <- arg function_declaration_arguments");
		assert($1->gettype() == est_arglist);
		func_desc_arglist_node * p = dynamic_cast<func_desc_arglist_node*>($1);
		p->add_arg($3);
		$$ = p;
	}
	| 
	arg
	{
		FKLOG("[bison]: function_declaration_arguments <- arg");
		NEWTYPE(p, func_desc_arglist_node);
		p->add_arg($1);
		$$ = p;
	}
	;

arg : 
	IDENTIFIER
	{
		FKLOG("[bison]: arg <- IDENTIFIER %s", $1.c_str());
		NEWTYPE(p, identifier_node);
		p->str = $1;
		$$ = p;
	}
	;

arg_expr:
	expr_value
	{
		FKLOG("[bison]: arg_expr <- expr_value");
		$$ = $1;
	}
	;


dimension_list: NUMBER          { }
              | dimension_list ',' NUMBER       {}
              ;
/*
access_expr: IDENTIFIER  '[' dimension_list ']'    {}
           | IDENTIFIER '[' access_expr ']'       {}
           ;
*/

function_call_arguments: 
	function_call_arguments ARG_SPLITTER arg_expr
	{
		FKLOG("[bison]: function_call_arguments <- arg_expr function_call_arguments");
		assert($1->gettype() == est_call_arglist);
		function_call_arglist_node * p = dynamic_cast<function_call_arglist_node*>($1);
		p->add_arg($3);
		$$ = p;
	}
	| 
	arg_expr
	{

		FKLOG("[bison]: function_call_arguments <- arg_expr");
		NEWTYPE(p, function_call_arglist_node);
		p->add_arg($1);
		$$ = p;
	}
	|	
	%empty
	{
		$$ = 0;
	}
	;  
	
function_call:
	CALL IDENTIFIER OPEN_BRACKET function_call_arguments CLOSE_BRACKET 
	{
		FKLOG("[bison]: function_call <- function_call_arguments %s", $2.c_str());
		NEWTYPE(p, function_call_node);
		p->fuc = $2;
		p->prefunc = 0;
		p->arglist = dynamic_cast<function_call_arglist_node*>($4);
		p->fakecall = false;
		p->classmem_call = false;
		$$ = p;
	} 
	;
 

/* function declaration end */

block:
	block stmt 
	{
		FKLOG("[bison]: block <- block stmt");
		assert($1->gettype() == est_block);
		block_node * p = dynamic_cast<block_node*>($1);
		p->add_stmt($2);
		$$ = p;
	}
	|
	stmt 
	{
		FKLOG("[bison]: block <- stmt");
		NEWTYPE(p, block_node);
		p->add_stmt($1);
		$$ = p;
	}
	;
  
GOTO_stm:
	GOTO IDENTIFIER
	{
		FKLOG("[bison]: stmt <- GOTO_stm");
		NEWTYPE(p, GOTO_stm);
		p->var = $2;
		$$ = p;
	}
	;

LABEL_stm:
	IDENTIFIER COLON 
	{
		FKLOG("[bison]: stmt <- LABEL_stm");
		NEWTYPE(p, LABEL_stm);
		p->var = $1;
		$$ = p;
	}
	;

HOME_stm:
	HOME NUMBER 
	{
		FKLOG("[bison]: stmt <- HOME_stm");
		NEWTYPE(p, HOME_stm);
		p->var = $2;
		$$ = p;
	}
	;

BASE_stm:
	BASE IDENTIFIER
	{
		FKLOG("[bison]: stmt <- BASE_stm");
		NEWTYPE(p, BASE_stm);
		p->var = $2;
		$$ = p;
	}
	|
	BASE FNULL 
	{
		FKLOG("[bison]: stmt <- BASE_stm");
		NEWTYPE(p, BASE_stm);
		p->var = $2;
		$$ = p;
	}
	;

TOOL_stm:
	TOOL IDENTIFIER 
	{
		FKLOG("[bison]: stmt <- TOOL_stm");
		NEWTYPE(p, TOOL_stm);
		p->var = $2;
		$$ = p;
	}
	|
	TOOL FNULL 
	{
		FKLOG("[bison]: stmt <- TOOL_stm");
		NEWTYPE(p, TOOL_stm);
		p->var = $2;
		$$ = p;
	}
	;

TYPE_stm:
	TYPE STRING_DEFINITION
	{
		FKLOG("[bison]: stmt <- TYPE_stm");
		NEWTYPE(p, TYPE_stm);
		p->var = $2;
		$$ = p;
	}
	;

STOP_stm:
	STOP 
	{
		FKLOG("[bison]: stmt <- STOP_stm");
		NEWTYPE(p, STOP_stm);
		$$ = p;
	}
	;

JMOVE_stm:
	JMOVE IDENTIFIER 
	{
		FKLOG("[bison]: stmt <- JMOVE_stm");
		NEWTYPE(p, JMOVE_stm);
		p->var = $2;
		$$ = p;
	}
	;

	TWAIT_stm:	
	TWAIT FKFLOAT
	{
		FKLOG("[bison]: stmt <- TWAIT_stm");
		NEWTYPE(p, TWAIT_stm);
		p->var = $2;
		$$ = p;
	}	
	;

SWAIT_stm:
	SWAIT signal_num_stm
	{
		FKLOG("[bison]: stmt <- SWAIT_stm");
		NEWTYPE(p, SWAIT_stm);
		p->var = $2;
		$$ = p;
	}
	;

signal_num_stm:
	NUMBER 
	{
		$$ =  $1;
	}
	| NUMBER ARG_SPLITTER GAP signal_num_stm 
	{
		$$;	
	}
	;

SIGNAL_stm:
	SIGNAL signal_num_stm
	{
		FKLOG("[bison]: stmt <- SIGNAL_stm");
		NEWTYPE(p, SIGNAL_stm);
		p->var = $2;
		$$ = p;
	}
	;

SIG_stm:
	SIG OPEN_BRACKET NUMBER CLOSE_BRACKET
	{
		FKLOG("[bison]: stmt <- SIG_stm");
		NEWTYPE(p, SIGNAL_stm);
		p->var = $3;
		$$ = p;
	}
	;

stmt:
	SWAIT_stm { FKLOG("[bison]: stmt <- SWAIT_stm");$$ = $1;}
	| TWAIT_stm {FKLOG("[bison]: stmt <- TWAIT_stm");$$ = $1;}
	| STOP_stm{FKLOG("[bison]: stmt <- STOP_stm");$$ = $1;}
	| JMOVE_stm{FKLOG("[bison]: stmt <- JMOVE_stm");$$ = $1;}
	| BASE_stm{FKLOG("[bison]: stmt <- BASE_stm");$$ = $1;}
	| TOOL_stm{FKLOG("[bison]: stmt <- TOOL_stm");$$ = $1;}
	| HOME_stm{FKLOG("[bison]: stmt <- HOME_stm");$$ = $1;}
	| GOTO_stm{FKLOG("[bison]: stmt <- GOTO_stm");$$ = $1;}
	| TYPE_stm{FKLOG("[bison]: stmt <- TYPE_stm");$$ = $1;}
	| LABEL_stm{FKLOG("[bison]: stmt <- LABEL_stm");$$ = $1;}
	| SIGNAL_stm {FKLOG("[bison]: stmt <- SIGNAL_stm");$$ = $1;}
	|
	if_stmt
	{
		FKLOG("[bison]: stmt <- if_stmt");
		$$ = $1;
	}
	|
	return_stmt
	{
		FKLOG("[bison]: stmt <- return_stmt");
		$$ = $1;
	}
	|
	assign_stmt
	{
		FKLOG("[bison]: stmt <- assign_stmt");
		$$ = $1;
	}
	|
	expr
	{
		FKLOG("[bison]: stmt <- expr");
		$$ = $1;
	}
	|
	for_stmt
	{
		FKLOG("[bison]: stmt <- for_stmt");
		$$ = $1;
	}
	|
	switch_stmt
	{
		FKLOG("[bison]: stmt <- switch_stmt");
		$$ = $1;
	}
	;
		
for_stmt:
	FOR block TO block THEN block end_statement
	{
		FKLOG("[bison]: for_stmt <- block cmp block");
		NEWTYPE(p, for_stmt);
		p->beginblock = dynamic_cast<block_node*>($2);
		p->endblock = dynamic_cast<block_node*>($4);
		p->block = dynamic_cast<block_node*>($6);
		$$ = p;
	}
	;	
	
if_stmt:
	IF cmp THEN block else_stmt end_statement
	{
		FKLOG("[bison]: if_stmt <- cmp block");
		NEWTYPE(p, if_stmt);
		p->cmp = dynamic_cast<cmp_stmt*>($2);
		p->block = dynamic_cast<block_node*>($4);
		p->elses = dynamic_cast<else_stmt*>($5);
		p->elseifs = NULL;
		$$ = p;
	}	
	;	
	
else_stmt:	
	%empty
	{
		$$ = 0;
	}
	|
	ELSE block
	{
		FKLOG("[bison]: else_stmt <- block");
		NEWTYPE(p, else_stmt);
		p->block = dynamic_cast<block_node*>($2);
		$$ = p;
	}
	|
	ELSE
	{
		FKLOG("[bison]: else_stmt <- empty");
		NEWTYPE(p, else_stmt);
		p->block = 0;
		$$ = p;
	}
	;
	;

end_statement
    : END_ST optional_semicolon
    ;

optional_semicolon
    : %empty
    ;

cmp:
	OPEN_BRACKET cmp CLOSE_BRACKET
	{
		FKLOG("[bison]: cmp <- ( cmp )");
		$$ = $2;
	}
	|
	cmp AND cmp
	{
		FKLOG("[bison]: cmp <- cmp AND cmp");
		NEWTYPE(p, cmp_stmt);
		p->cmp = "&&";
		p->left = $1;
		p->right = $3;
		$$ = p;
	}
	|
	cmp OR cmp
	{
		FKLOG("[bison]: cmp <- cmp OR cmp");
		NEWTYPE(p, cmp_stmt);
		p->cmp = "||";
		p->left = $1;
		p->right = $3;
		$$ = p;
	}
	|
	cmp_value LESS cmp_value
	{
		FKLOG("[bison]: cmp <- cmp_value LESS cmp_value");
		NEWTYPE(p, cmp_stmt);
		p->cmp = $2;
		p->left = $1;
		p->right = $3;
		$$ = p;
	}
	|
	cmp_value MORE cmp_value
	{
		FKLOG("[bison]: cmp <- cmp_value MORE cmp_value");
		NEWTYPE(p, cmp_stmt);
		p->cmp = $2;
		p->left = $1;
		p->right = $3;
		$$ = p;
	}
	|
	cmp_value EQUAL cmp_value
	{
		FKLOG("[bison]: cmp <- cmp_value EQUAL cmp_value");
		NEWTYPE(p, cmp_stmt);
		p->cmp = $2;
		p->left = $1;
		p->right = $3;
		$$ = p;
	}
	|
	cmp_value MORE_OR_EQUAL cmp_value
	{
		FKLOG("[bison]: cmp <- cmp_value MORE_OR_EQUAL cmp_value");
		NEWTYPE(p, cmp_stmt);
		p->cmp = $2;
		p->left = $1;
		p->right = $3;
		$$ = p;
	}
	|
	cmp_value LESS_OR_EQUAL cmp_value
	{
		FKLOG("[bison]: cmp <- cmp_value LESS_OR_EQUAL cmp_value");
		NEWTYPE(p, cmp_stmt);
		p->cmp = $2;
		p->left = $1;
		p->right = $3;
		$$ = p;
	}
	|
	cmp_value NOT_EQUAL cmp_value
	{
		FKLOG("[bison]: cmp <- cmp_value NOT_EQUAL cmp_value");
		NEWTYPE(p, cmp_stmt);
		p->cmp = $2;
		p->left = $1;
		p->right = $3;
		$$ = p;
	}
	|
	FTRUE
	{
		FKLOG("[bison]: cmp <- true");
		NEWTYPE(p, cmp_stmt);
		p->cmp = "true";
		p->left = 0;
		p->right = 0;
		$$ = p;
	}
	|
	FFALSE
	{
		FKLOG("[bison]: cmp <- false");
		NEWTYPE(p, cmp_stmt);
		p->cmp = "false";
		p->left = 0;
		p->right = 0;
		$$ = p;
	}
	|
	SIG_stm
	{
		FKLOG("[bison]: cmp <- false");
		$$ = $1;
	}
	/*|
	function_call
	{
		FKLOG("[bison]: expr <- function_call");
		$$ = $1;
	}*/
	;

cmp_value:
	explicit_value
	{
		FKLOG("[bison]: cmp_value <- explicit_value");
		$$ = $1;
	}
	|
	variable
	{
		FKLOG("[bison]: cmp_value <- variable");
		$$ = $1;
	}
	|
	expr
	{
		FKLOG("[bison]: cmp_value <- expr");
		$$ = $1;
	}
	;
	
return_stmt:	
	RETURN
	{
		FKLOG("[bison]: return_stmt <- RETURN");
		NEWTYPE(p, return_stmt);
		p->returnlist = 0;
		$$ = p;
	}
	; 

assign_stmt:
	var ASSIGN assign_value
	{
		FKLOG("[bison]: assign_stmt <- var assign_value");
		NEWTYPE(p, assign_stmt);
		p->var = $1;
		p->value = $3;
		p->isnew = false;
		$$ = p;
	}
	;
	
assign_value:
	explicit_value
	{
		FKLOG("[bison]: assign_value <- explicit_value");
		$$ = $1;
	}
	|
	variable
	{
		FKLOG("[bison]: assign_value <- variable");
		$$ = $1;
	}
	|
	expr
	{
		FKLOG("[bison]: assign_value <- expr");
		$$ = $1;
	}
	;
	
var:
	variable
	{
		FKLOG("[bison]: var <- variable");
		$$ = $1;
	}
	;

variable:
	IDENTIFIER
	{
		FKLOG("[bison]: variable <- IDENTIFIER %s", $1.c_str());
		NEWTYPE(p, variable_node);
		p->str = $1;
		$$ = p;
	}
	|
	IDENTIFIER OPEN_SQUARE_BRACKET expr_value CLOSE_SQUARE_BRACKET
	{
		FKLOG("[bison]: container_get_node <- IDENTIFIER[expr_value] %s", $1.c_str());
		NEWTYPE(p, container_get_node);
		p->container = $1;
		p->key = $3;
		$$ = p;
	}
	|
	IDENTIFIER_POINTER
	{
		FKLOG("[bison]: variable <- IDENTIFIER_POINTER %s", $1.c_str());
		NEWTYPE(p, struct_pointer_node);
		p->str = $1;
		$$ = p;
	}
	|
	IDENTIFIER_DOT
	{
		FKLOG("[bison]: variable <- IDENTIFIER_DOT %s", $1.c_str());
		NEWTYPE(p, variable_node);
		p->str = $1;
		$$ = p;
	}
	;

expr:
	OPEN_BRACKET expr CLOSE_BRACKET
	{
		FKLOG("[bison]: expr <- (expr)");
		$$ = $2;
	}
	|
	function_call
	{
		FKLOG("[bison]: expr <- function_call");
		$$ = $1;
	}
	|
	math_expr
	{
		FKLOG("[bison]: expr <- math_expr");
		$$ = $1;
	}
	;

math_expr:
	OPEN_BRACKET math_expr CLOSE_BRACKET
	{
		FKLOG("[bison]: math_expr <- (math_expr)");
		$$ = $2;
	}
	|
	expr_value PLUS expr_value
	{
		FKLOG("[bison]: math_expr <- expr_value %s expr_value", $2.c_str());
		NEWTYPE(p, math_expr_node);
		p->oper = "+";
		p->left = $1;
		p->right = $3;
		$$ = p;
	}
	|
	expr_value MINUS expr_value
	{
		FKLOG("[bison]: math_expr <- expr_value %s expr_value", $2.c_str());
		NEWTYPE(p, math_expr_node);
		p->oper = "-";
		p->left = $1;
		p->right = $3;
		$$ = p;
	}
	|
	expr_value MULTIPLY expr_value
	{
		FKLOG("[bison]: math_expr <- expr_value %s expr_value", $2.c_str());
		NEWTYPE(p, math_expr_node);
		p->oper = "*";
		p->left = $1;
		p->right = $3;
		$$ = p;
	}
	|
	expr_value DIVIDE expr_value
	{
		FKLOG("[bison]: math_expr <- expr_value %s expr_value", $2.c_str());
		NEWTYPE(p, math_expr_node);
		p->oper = "/";
		p->left = $1;
		p->right = $3;
		$$ = p;
	}
	|
	expr_value DIVIDE_MOD expr_value
	{
		FKLOG("[bison]: math_expr <- expr_value %s expr_value", $2.c_str());
		NEWTYPE(p, math_expr_node);
		p->oper = "%";
		p->left = $1;
		p->right = $3;
		$$ = p;
	}
	;	

expr_value:
	math_expr
	{
		FKLOG("[bison]: expr_value <- math_expr");
		$$ = $1;
	}
	|
	explicit_value
	{
		FKLOG("[bison]: expr_value <- explicit_value");
		$$ = $1;
	}
	|
	variable
	{
		FKLOG("[bison]: expr_value <- variable");
		$$ = $1;
	}
	;

/*
const_array_list_value:
	{
		FKLOG("[bison]: const_array_list_value <- null");
		NEWTYPE(p, const_array_list_value_node);
		$$ = p;
	}
	|
	explicit_value
	{
		FKLOG("[bison]: const_array_list_value <- explicit_value");
		NEWTYPE(p, const_array_list_value_node);
		p->add_ele($1);
		$$ = p;
	}
	|
	const_array_list_value explicit_value
	{
		FKLOG("[bison]: const_array_list_value <- const_array_list_value explicit_value");
		assert($1->gettype() == est_constarraylist);
		const_array_list_value_node * p = dynamic_cast<const_array_list_value_node*>($1);
		p->add_ele($2);
		$$ = p;
	}
	;
*/

explicit_value:
	FTRUE 
	{
		FKLOG("[bison]: explicit_value <- FTRUE");
		NEWTYPE(p, explicit_value_node);
		p->str = $1;
		p->type = explicit_value_node::EVT_TRUE;
		$$ = p;
	}
	|
	FFALSE 
	{
		FKLOG("[bison]: explicit_value <- FFALSE");
		NEWTYPE(p, explicit_value_node);
		p->str = $1;
		p->type = explicit_value_node::EVT_FALSE;
		$$ = p;
	}
	|
	NUMBER 
	{
		FKLOG("[bison]: explicit_value <- NUMBER %s", $1.c_str());
		NEWTYPE(p, explicit_value_node);
		p->str = $1;
		p->type = explicit_value_node::EVT_NUM;
		$$ = p;
	}
	|
	STRING_DEFINITION 
	{
		FKLOG("[bison]: explicit_value <- STRING_DEFINITION %s", $1.c_str());
		NEWTYPE(p, explicit_value_node);
		p->str = $1;
		p->type = explicit_value_node::EVT_STR;
		$$ = p;
	}
	|
	FKFLOAT
	{
		FKLOG("[bison]: explicit_value <- FKFLOAT %s", $1.c_str());
		NEWTYPE(p, explicit_value_node);
		p->str = $1;
		p->type = explicit_value_node::EVT_FLOAT;
		$$ = p;
	}
	|
	FNULL
	{
		FKLOG("[bison]: explicit_value <- FNULL %s", $1.c_str());
		NEWTYPE(p, explicit_value_node);
		p->str = $1;
		p->type = explicit_value_node::EVT_NULL;
		$$ = p;
	}
	/*
	|
	OPEN_SQUARE_BRACKET const_array_list_value CLOSE_SQUARE_BRACKET
	{
		FKLOG("[bison]: explicit_value <- const_array_list_value");
		NEWTYPE(p, explicit_value_node);
		p->str = "";
		p->type = explicit_value_node::EVT_ARRAY;
		p->v = $2;
		$$ = p;
	}*/
	;      
	
switch_stmt:
	SWITCH cmp_value  OF  switch_case_list DEFAULT block end_statement
	{
		FKLOG("[bison]: switch_stmt");
		NEWTYPE(p, switch_stmt);
		p->cmp = $2;
		p->caselist = $4;
		p->def = $6;
		$$ = p;
	}
	|
	SWITCH cmp_value OF switch_case_list end_statement
	{
		FKLOG("[bison]: switch_stmt");
		NEWTYPE(p, switch_stmt);
		p->cmp = $2;
		p->caselist = $4;
		p->def = 0;
		$$ = p;
	}
	;
	
switch_case_list:
	switch_case_define
	{
		FKLOG("[bison]: switch_case_list <- switch_case_define");
		NEWTYPE(p, switch_caselist_node);
		p->add_case($1);
		$$ = p;
	}
	|
	switch_case_list switch_case_define
	{
		FKLOG("[bison]: switch_case_list <- switch_case_list switch_case_define");
		assert($2->gettype() == est_switch_case_node);
		switch_caselist_node * p = dynamic_cast<switch_caselist_node*>($1);
		p->add_case($2);
		$$ = p;
	}
	;

switch_case_define:
	CASE cmp_value COLON block
	{
		FKLOG("[bison]: switch_case_define");
		NEWTYPE(p, switch_case_node);
		p->cmp = $2;
		p->block = $4;
		$$ = p;
	}
	;
	
