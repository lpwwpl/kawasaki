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
	FKLOG("[bison]: bison new type %s %p line %d %d %d", #x, p, ((myflexer *)parm)->lineno(), yylloc.first_line, yylsp->first_line);
	
%}

%pure-parser

%define parse.error verbose

%param       {void * parm}

%locations
%token OF 
%token TO
%token RETURN
%token FUNC
%token WHILE
%token FTRUE
%token FFALSE
%token IF
%token THEN
%token ELSE
%token END
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
%token COLON
%token FOR
%token OPEN_SQUARE_BRACKET
%token CLOSE_SQUARE_BRACKET
%token IDENTIFIER_DOT
%token IDENTIFIER_POINTER
%token FNULL
%token SWITCH CASE DEFAULT

%left PLUS MINUS
%left DIVIDE MULTIPLY DIVIDE_MOD

%expect 56

%type<str> IDENTIFIER  
%type<str> NUMBER
%type<str> STRING_DEFINITION
%type<str> PLUS
%type<str> MINUS
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

%type<syntree> function_declaration
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
%type<syntree> function_call
%type<syntree> var
%type<syntree> assign_stmt
%type<syntree> cmp_value
%type<syntree> assign_value
%type<syntree> expr_value
%type<syntree> for_stmt
%type<syntree> switch_stmt
%type<syntree> switch_case_define
%type<syntree> switch_case_list

%%

/* Top level rules */
program: 
	const_head 
	body 
	;

const_head:
	/* empty */
	{
	}
	|
	const_define
	|
	const_head const_define
	;

const_define:
	IDENTIFIER ASSIGN explicit_value
	{
		FKLOG("[bison]: const_define %s", $1.c_str());
		myflexer *l = (myflexer *)parm;
		l->add_const_desc($1.c_str(), $3);
	}
	;

body:
	/* empty */
	{
	}
	|
	function_declaration
	|
	body function_declaration
	;

/* function declaration begin */

function_declaration:
	FUNC IDENTIFIER OPEN_BRACKET CLOSE_BRACKET block END
	{
		FKLOG("[bison]: function_declaration <- block %s %d", $2.c_str(), yylloc.first_line);
		NEWTYPE(p, func_desc_node);
		p->funcname = $2;
		p->block = dynamic_cast<block_node*>($5);
		p->endline = yylloc.first_line;
		myflexer *l = (myflexer *)parm;
		l->add_func_desc(p);
	}
	;
	
function_call:
	IDENTIFIER OPEN_BRACKET CLOSE_BRACKET 
	{
		FKLOG("[bison]: function_call <- function_call_arguments %s", $1.c_str());
		NEWTYPE(p, function_call_node);
		p->fuc = $1;
		p->prefunc = 0;
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
  
stmt:
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
	FOR block TO block THEN block END
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
	IF cmp THEN block else_stmt END
	{
		FKLOG("[bison]: if_stmt <- cmp block");
		NEWTYPE(p, if_stmt);
		p->cmp = dynamic_cast<cmp_stmt*>($2);
		p->block = dynamic_cast<block_node*>($4);
		p->elses = dynamic_cast<else_stmt*>($5);
		$$ = p;
	}
	;	
	
else_stmt:
	/*empty*/
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
	function_call
	{
		FKLOG("[bison]: expr_value <- function_call");
		$$ = $1;
	}
	|
	variable
	{
		FKLOG("[bison]: expr_value <- variable");
		$$ = $1;
	}
	;
	
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
	;      
	
switch_stmt:
	SWITCH cmp_value OF switch_case_list DEFAULT block END
	{
		FKLOG("[bison]: switch_stmt");
		NEWTYPE(p, switch_stmt);
		p->cmp = $2;
		p->caselist = $4;
		p->def = $6;
		$$ = p;
	}
	|
	SWITCH cmp_value OF switch_case_list END
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
	
