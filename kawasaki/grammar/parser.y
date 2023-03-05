%skeleton "lalr1.cc"
%require  "3.0"
%debug
%defines
%define api.namespace {Language}
%define parser_class_name {Parser}
%define parse.error verbose

%code requires{
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
}

%lex-param   { Lexer  &lexer  }
%parse-param { Lexer  &lexer  }

%code{
    #include "translator.hpp"
    #include "ast.h"

    
    extern int lineNumber;
    static int yylex(Language::Parser::semantic_type *yylval, Language::Lexer  &lexer);
}

/* token types */
%union {
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
}

%left GE LE EQ NE GREATER LESS
%left MINUS ADD SUB
%left MULTIP DEVIDE
%nonassoc UMINUS
%nonassoc IFX
%nonassoc ELSE

//DIV
%token GE LE EQ NE IF While ADD SUB MUL  PRINT LT GT RETURN NumberType TextType VoidType SPACE THEN 
%token ASS LR RR COMMA LC RC  LESS GREATER COLON SWITCH CASE 
%token FTRUE FFALSE FOR TO JOINTS_VAR DO UNTIL FINE STEP LDEPART
%token JOINTS TRANS  TRANS_DOT ALWAYS
%token HERE BREAK DECOMPOSE SPEED ALIGN ACCURACY LAPPRO JAPPRO DRAW DECODE
%token DRIVE TDRAW POINT TCP_SEND TCP_CLOSE C1MOVE LMOVE TCP_RECV TCP_CONNECT TCP_STATUS WEIGHT VAL
%token STOP HOME BASE TOOL TYPE TWAIT SIGNAL GOTO FUNC SIG JMOVE SWAIT END_ST END_DOT AND OR MOD
%token CALL  DEFAULT FNULL OF DEFINES  MM_S MM_MIN POINT_X POINT_Z POINT_OAT SHIFT BY BITS  PAUSE LDEPART PULSE DOLAR JIN   DISTANCE
%token  END    0     "end of file"
%token <dval> Number 
%token <ival> LNumber
%token <sval> Identifier
%token <sval> String 


%type<pNode> TOOL TWAIT JMOVE BREAK LMOVE JAPPRO LAPPRO HOME SIGNAL SIG SWAIT TYPE GOTO   switch_case_define TRANS_STR_stm  JOINTS_STR_stm
%type<pNode>  program expression assignment print statement function_call while_loop if switch return STOP BASE for do_until
%type <parameterNode> parameter_declaration
%type <ival> /*type*/ NumberType TextType VoidType
%type <functionNode> function_declaration
%type <listNode> expression_list function_declaration_list switch_case_list 
%type <parameterListNode> parameter_declaration_list
%type <statementListNode>statement_list function_body
%type <signal_num_stmNode> signal_num_stm 
%type <param_stmNode> param_stm
%type <dim_num_stmNode> dim_num_stm
%type <trans_strNode> str_list
%type <trans_strNode> str_comma_list
%type <trans_strNode> expression_comma_list
%%


program: 	
	body DEFINES_list  {}
    | DEFINES_list body {}
	;

assignment_list:
    assignment {  }
    | assignment_list assignment { }
    ;

expression_comma_list:
 | expression {  $$ = new TransStrNode($1); }
 | expression_comma_list COMMA expression {  $1->push_back($3);}
 | {$$ = new TransStrNode(NULL);}
 ;


str_comma_list:
    Number 
    { 
        NumberLiteralNode* num = new NumberLiteralNode($1);
        $$ = new TransStrNode(num); 
    }
    | str_comma_list COMMA Number 
    {
        NumberLiteralNode* num = new NumberLiteralNode($3);
        $1->push_back(num);
    }
    | {$$ = new TransStrNode(NULL);}
;

str_list:
    Number 
    { 
        NumberLiteralNode* num = new NumberLiteralNode($1);
        $$ = new TransStrNode(num); 
    }
    | str_list  Number 
    {
        NumberLiteralNode* num = new NumberLiteralNode($2);
        $1->push_back(num);
    }
    | {$$ = new TransStrNode(NULL);}
;

TRANS_STR_stm:
    {}
    |
    Identifier str_list {
        $$ = new AssignmentNode($1, $2);
    }
    |
    Identifier LR dim_num_stm RR str_list {
        $$ = new AssignmentNode($1, $5,$3);
    }
    ;

JOINTS_STR_stm:
    {}
    |
    Identifier str_list {
        $$ = new AssignmentNode($1, $2);
    }
    |
    Identifier LR dim_num_stm RR str_list {
        $$ = new AssignmentNode($1, $5,$3);
    }
    ;

TRANS_head:
    {

	}
	|
	TRANS_DOT TRANS_list END_DOT {}
	;

TRANS_list:
    TRANS_STR_stm{}
    | TRANS_list TRANS_STR_stm{}
    ;

JOINTS_head:
    {

	}
	|
	JOINTS JOINTS_list END_DOT {}
	;

JOINTS_list:
    JOINTS_STR_stm{}
    | JOINTS_list TRANS_STR_stm{}
    ;

DEFINES_list:
    DEFINES_head{}
    | TRANS_head{}
    | JOINTS_head{}
    | DEFINES_list TRANS_head {}
    | DEFINES_list JOINTS_head {}
    | DEFINES_list DEFINES_head{}
    ;

DEFINES_head:
	{

	}
	|
	DEFINES assignment_list END_DOT {}
	;

body:
	{
	}
	|
	function_declaration_list{ $1->Execute(); }
    ;

function_declaration_list:
    function_declaration { $$ = new ListNode<ASTNode>($1);}
    | function_declaration_list function_declaration {$1->push_back($2);}
    ;

function_declaration:
    FUNC Identifier LC parameter_declaration_list RC function_body END_DOT {$$ = new FunctionNode(token::VoidType, $2, $4, $6); }
    |
    | FUNC Identifier LC parameter_declaration_list RC JIN Number  function_body END_DOT {$$ = new FunctionNode(token::VoidType, $2, $4, $8); }
    ;

/*type:
    NumberType {$$ = token::NumberType;}
    | TextType {$$ = token::TextType;}
    | VoidType {$$ = token::VoidType;}
    ;*/

parameter_declaration_list:
    parameter_declaration { $$ = new ListNode<ParameterNode>($1); }
    | parameter_declaration_list COMMA parameter_declaration {$1->push_back($3);}
    | {$$ = new ListNode<ParameterNode>();}
;

parameter_declaration:
    Identifier {$$ = new ParameterNode($1);}
    //| Identifier ASS expression {$$ = new ParameterNode($1, $3);}
;

function_body:
 {$$=NULL;}
 |    statement_list  {$$ = $1;}
;

statement_list:
    statement {$$ = new StatementListNode($1);}
    | statement_list statement {$1->push_back($2);}
    ;

statement:
    parameter_declaration  { $$ = $1;}
    | assignment  {$$ = $1;}
    | print  { $$ = $1;}
    | function_call  {$$ = $1;}
    | while_loop { $$ = $1; }
    | do_until {$$ = $1;}
    | if { $$ = $1; }
    | for { $$ = $1; }
    | return  { $$ = $1;}
    | STOP { $$ = new StopNode(NULL); }
    | BASE expression {$$ = new BaseNode($2);}
    | TOOL expression {$$ = new ToolNode($2);}
    | TWAIT expression {$$ = new TWaitNode($2);}
    | JMOVE expression {$$ = new JMoveNode($2);}
    | HOME {$$ = new HomeNode(0);}
    | SIGNAL signal_num_stm {$$ = new SignalNode($2);}
    | SWAIT  signal_num_stm {$$ = new SWaitNode($2);}
    | TYPE expression {$$ = new TypeNode($2);}
    | PAUSE  { $$ = new PauseNode(NULL);}
    | LMOVE expression {$$ = new LMoveNode($2);}
    | ALIGN { $$ = new AlignNode(NULL);}
    | BREAK {$$ = new BreakNode(NULL);}
    | HERE expression {$$ = new HereNode($2);}
    | SPEED param_stm {$$ = new SpeedNode($2);}
    | LDEPART expression {$$ = new LDepartNode($2);}
    | SPEED expression {$$ = new SpeedNode($2);}
    | JAPPRO expression COMMA expression {$$ = new JapproNode($2,$4);}
    | PULSE expression COMMA expression {$$ = new PulseNode($2,$4);}
    | C1MOVE expression {$$ = new C1MoveNode($2);}
    | LAPPRO expression COMMA expression {$$ = new LapproNode($2,$4);}
    | ACCURACY param_stm { $$ = new AccuracyNode($2);}
    | ACCURACY signal_num_stm { SignalNumsNode* sigNums = new SignalNumsNode($2);$$ = new AccuracyNode(sigNums);}  
    | DRAW param_stm {  $$ = new DrawNode($2);}
    | DRAW signal_num_stm { SignalNumsNode* sigNums = new SignalNumsNode($2);  $$ = new DrawNode(sigNums);}
    | DRIVE signal_num_stm { SignalNumsNode* sigNums = new SignalNumsNode($2);  $$ = new DriveNode(sigNums);}
    | TDRAW signal_num_stm { SignalNumsNode* sigNums = new SignalNumsNode($2);  $$ = new TDrawNode(sigNums);}
    | WEIGHT signal_num_stm { SignalNumsNode* sigNums = new SignalNumsNode($2);  $$ = new WeightNode(sigNums);}
    | TDRAW param_stm {  $$ = new TDrawNode($2);}
    | POINT expression ASS SHIFT LC expression BY expression COMMA expression COMMA expression RC 
    {     
     $$ = new PointNode($2,$6,$8,$10,$12);
    }
    | POINT expression ASS TRANS LC signal_num_stm RC { /*TransNode* trans = new TransNode($4);*/$$ = new PointNode($2,$6,1);}
    | POINT expression ASS expression {$$ = new PointNode($2,$4,0);}
    | POINT_OAT expression ASS expression  {$$ = new PointOATNode($2,$4);}
    | POINT_X expression ASS expression {$$ = new PointXNode($2,$4);}
    | POINT_Z expression ASS expression {$$ = new PointZNode($2,$4);}
    ///////////////////////expression_comma_list->signal_num_stm
    | PRINT expression COLON expression_comma_list { $$ = new PrintNode($2,$4);}
    | PRINT expression_comma_list {$$ = new PrintNode($2);}
    | TCP_SEND expression_comma_list {$$ = new TCPSendNode($2);}
    | TCP_CLOSE expression_comma_list{ $$ = new TCPCloseNode($2);}
    | TCP_STATUS expression_comma_list {$$ = new TCPStatusNode($2);}
    | TCP_RECV expression_comma_list{ $$ = new TCPRecvNode($2);}
    | TCP_CONNECT expression_comma_list { $$ = new TCPConnectNode($2);}
    //| DECOMPOSE {$$ = new DecomposeNode($2);}//angle_c[1] = #camera1
    | GOTO expression  {  $$ = new GotoNode($2);} 
    | switch {$$ = $1;}
    | Identifier COLON { IdentifierNode* id = new IdentifierNode($1);$$ = new LabelNode(id);   }
    | Number { NumberLiteralNode* id = new NumberLiteralNode($1);$$ = new LabelNode(id);   }
    //| BITS LC expression COMMA expression RC { $$ = new BitsNode($3,$5,0);}
    //| BITS expression COMMA expression ASS expression {$$ = new BitsNode($2,$4,1);}

    ;
/*
signal_num_stm_expression:
     Identifier { $$ = new IdentifierNode($1); } 
     | Number {$$ = new NumberLiteralNode($1); }
     ;
*/
signal_num_stm:
	expression 	
    {
        $$ = new SignalNumsNode($1); 
    }
	| signal_num_stm  COMMA  expression 
	{
		$1->push_back($3);    
	} 
	;

param_stm:
    signal_num_stm MM_S 
    {
        $$ = new ParamNode($1,1);
    }
    | signal_num_stm MM_S ALWAYS
    {
        $$ = new  ParamNode($1,1,true);
    }
    | signal_num_stm MM_S ALWAYS FINE
    {
        $$ = new  ParamNode($1,1,true,true);
    }
    | signal_num_stm MM_S FINE
    {
        $$ = new  ParamNode($1,1,false,true);
    }
    | signal_num_stm MM_MIN
    {
        $$ = new  ParamNode($1,2);
    }
    | signal_num_stm MM_MIN ALWAYS
    {
        $$ = new  ParamNode($1,2,true);
    }
    | signal_num_stm MM_MIN FINE
    {
        $$ = new ParamNode($1,2,false,true);
    }
    | signal_num_stm MM_MIN ALWAYS FINE
    {
        $$ = new ParamNode($1,2,true,true);
    }
    | signal_num_stm ALWAYS FINE
    {
        $$ = new ParamNode($1,0,true,true);
    }
    | signal_num_stm FINE
    {
        $$ = new ParamNode($1,0,false,true);
    }
    | signal_num_stm ALWAYS
    {
        $$ = new ParamNode($1,0,true);
    }

return:
    RETURN /*expression*/ {$$ = new ReturnNode(NULL); }
;

while_loop:
    While /*LC*/ expression /*RC*/ DO function_body { $$ = new WhileNode($2, $4); }
    ;

do_until:
    DO function_body UNTIL expression { $$ = new DoUntilNode($4,$2); }
    ;

function_call:
    CALL Identifier LC expression_list RC {$$ = new FunctionCallNode($2, $4);}
    | CALL  Identifier { $$ = new FunctionCallNode($2, new ListNode<ASTNode>());}
;


for:
    FOR assignment TO expression STEP expression function_body END_ST { $$ = new ForNode($2,$4,$6,$7);}
    | FOR assignment TO expression function_body END_ST { $$ = new ForNode($2,$4,NULL,$5);}
    ;

if:
    IF  expression  THEN function_body %prec IFX END_ST { $$ = new IfNode($2, $4); }
    | IF  expression  THEN function_body ELSE function_body  END_ST { $$ = new IfNode($2, $4, $6); }
;

switch:
    SWITCH expression OF switch_case_list END_ST
    {
        $$ = new SWitchNode($2,$4,NULL);
    }
    ;

switch_case_list:
	switch_case_define
	{
        $$ = new SWitchCaseListNode($1);
	}
	|
	switch_case_list switch_case_define
	{
        $1->push_back($2);   
	}
	;

switch_case_define:
	CASE expression COLON function_body
	{
        $$ = new CaseNode($2,$4); //$$->dimListType->push_back($1);
	}
	;

print:
    PRINT expression { $$ = new PrintNode($2);}
    ;

assignment:

    Identifier ASS expression { $$ = new AssignmentNode($1, $3);}
    |
    Identifier ASS BITS LC expression COMMA expression RC { BitsNode* node = new BitsNode($5,$7,0); $$ = new AssignmentNode($1, node);}
    |
    Identifier ASS DISTANCE LC expression RC { DistanceNode* distance = new DistanceNode($5); $$ = new AssignmentNode($1,distance);}
    |
    Identifier LR dim_num_stm RR ASS DISTANCE LC expression_comma_list RC { AccessNode* acc = new AccessNode($1, $3);DistanceNode* distance = new DistanceNode($8); $$ = new AssignmentNode(acc,distance);}
    |
    Identifier ASS VAL LC expression RC { VALNode* val = new VALNode($5); $$ = new AssignmentNode($1,val);}
    |
    BITS expression_comma_list ASS expression { QString str = "BITS";$$ = new AssignmentNode(&str,$2, $4,NULL);}
    |
    Identifier LR dim_num_stm RR ASS expression 
    { 
        $$ = new AssignmentNode($1, $6, $3);
    }
    ;

dim_num_stm:
	expression 	{
        //NumberLiteralNode* node  = new NumberLiteralNode($1);
        $$ = new DimNumsNode($1); //$$->dimListType->push_back($1);
    }
	| dim_num_stm  COMMA  expression 
	{
        $1->push_back($3);   
        //NumberLiteralNode* node = new NumberLiteralNode($3);
		//$1->push_back(node);    
	}
	;

expression_list:
    expression { $$ = new ListNode<ASTNode>($1); }
    | expression_list COMMA expression {$1->push_back($3);}
    | {$$ = new ListNode<ASTNode>(); }
;

expression:
 {$$=NULL;}
 | Identifier { $$ = new IdentifierNode($1); }
 | JOINTS_VAR str_comma_list RR {$$ = $2;}
 | String { $$ = new StringLiteralNode($1);}
 | FNULL { $$ = new NullNode();}
 | Number {$$ = new NumberLiteralNode($1); }
 | function_call { $$ = $1;}
 | FTRUE {$$ = new NumberLiteralNode(1);}
 | FFALSE {$$ = new NumberLiteralNode(0);}

 | expression ADD expression { $$ = new OperatorNode(token::ADD, $1, $3); }
 | expression SUB expression { $$ = new OperatorNode(token::SUB, $1, $3); }
 | expression MUL expression { $$ = new OperatorNode(token::MUL, $1, $3); }
 | expression LT expression { $$ = new OperatorNode(token::LT, $1, $3); }
 | expression GT expression { $$ = new OperatorNode(token::GT, $1, $3); }
 | expression GE expression { $$ = new OperatorNode(token::GE, $1, $3); }
 | expression LE expression { $$ = new OperatorNode(token::LE, $1, $3); }
 | expression NE expression { $$ = new OperatorNode(token::NE, $1, $3); }
 | expression EQ expression { $$ = new OperatorNode(token::EQ, $1, $3); }
 | expression AND expression {$$ = new OperatorNode(token::AND, $1, $3);}
 | expression OR expression {$$ = new OperatorNode(token::OR, $1, $3);}
 | expression MOD expression {$$ = new OperatorNode(token::MOD, $1, $3);}
 | SUB  expression %prec UMINUS { $$ = new OperatorNode(token::UMINUS, $2); }
 | Identifier LR dim_num_stm RR {$$ = new AccessNode($1, $3);}
 | DECODE LC expression_comma_list RC { $$ = new DecodeNode($3);}
 | Identifier LC expression_comma_list RC { $$ = new BuildInNode($1,$3);}
 | SIG  LC signal_num_stm RC {$$ = new SigNode($3);}

 ;



%%



void Language::Parser::error( const std::string &err_message )
{
   std::cerr << "Error: Line:" << lineNumber << "' - " << err_message << "\n";
}

static int yylex( Language::Parser::semantic_type *yylval, Language::Lexer  &lexer)
{
   return( lexer.yylex(yylval) );
}

