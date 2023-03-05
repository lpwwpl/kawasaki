%{

#include <QString>
#include "lexer.hpp"
	//eGlobal = 0;
	//eLocal =1;
extern int lineNumber;

typedef Language::Parser::token token;
QString buf;
#define yyterminate() return( token::END )
#define YY_NO_UNISTD_H // For msvc

%}

%option debug
%option yyclass="Lexer"
%option  noyywrap 
%option c++
%x SINGLE_LINE_COMMENT_STATE
%x TRANS_LINES_STATE

SPACE       [ \f\n\r\t\v]+
GAP         [ \f\n\r\t\v]*
IF          IF
ELSE        ELSE
THEN        THEN
RETURN      RETURN
GOTO        GOTO
WHILE       WHILE
PRINT       PRINT
STOP        STOP
HOME        HOME
BASE        BASE
TOOL        TOOL
TYPE        TYPE
TWAIT       TWAIT
SIGNAL      SIGNAL
PROGRAM    .PROGRAM
SIG         SIG
JMOVE       JMOVE
SWAIT       SWAIT
END_ST         END
END_DOT        .END
AND         AND
OR          OR
CASE        CASE
VALUE       VALUE
BITS        BITS
CALL        CALL
ANY         ANY
NULL        NULL
OF          OF
REALS      .REALS
STRINGS    .STRINGS
JOINTS     .JOINTS

TRUE        TRUE
FALSE       FALSE
LMOVE       LMOVE
DO          DO
ALIGN       ALIGN
BREAK       BREAK
HERE        HERE    
DECOMPOSE   DECOMPOSE
SPEED       SPEED
JAPPRO      JAPPRO
C1MOVE      C1MOVE
LAPPRO      LAPPRO
ACCURACY    ACCURACY
DRIVE       DRIVE
DRAW        DRAW
POINT       POINT
LDEPART    LDEPART
POINT_X    POINT\/X
POINT_Z    POINT\/Z
POINT_OAT   POINT\/OAT
MM_S        MM\/S
MM_MIN      MM\/MIN
TDRAW       TDRAW
TCP_SEND    TCP_SEND
TCP_CLOSE   TCP_CLOSE
TCP_CONNECT     TCP_CONNECT
TCP_STATUS      TCP_STATUS
TCP_RECV    TCP_RECV
SHIFT       SHIFT
ALWAYS      ALWAYS
FOR         FOR
PULSE       PULSE
TO          TO
UNTIL       UNTIL
FINE        FINE
STEP        STEP
BY          BY
MOD         MOD
PAUSE       PAUSE
DISTANCE    DISTANCE
WEIGHT      WEIGHT
VAL         VAL
%%

";"	yy_push_state(SINGLE_LINE_COMMENT_STATE);
<SINGLE_LINE_COMMENT_STATE>{
	[^\n]*	;
	"\n"	{
		yy_pop_state(); 
	}
}


                                                 



[\n]            				{ lineNumber++; }

\/\/(.)* ;
\"(\\.|[^"])*\" 				{
                                        yylval->sval = new QString( yytext );
                                        return token::String;
                                }

                         

(-?[0-9]+|(-?[0-9]*\.[0-9]+)([eE][-+]?[0-9]+)?)	{
                                                        yylval->dval = atof(yytext);
                                                        return token::Number;
                                                }

^[1-9]\d*$            {
                                      yylval->ival = atoi(yytext);
                                       return token::LNumber;
                     }                                     


"number"					{ return token::NumberType; }
"text"	 					{ return token::TextType; }
"void" 						{ return token::VoidType; }
{MOD}                       { return token::MOD;}
"$DECODE"                    { return token::DECODE;}
{BY}                        { return token::BY;}
{SHIFT}                     { return token::SHIFT;}
{IF}						{ return token::IF; }
{ELSE} 						{ return token::ELSE; }
{THEN}                      { return token::THEN; }
{WHILE} 					{ return token::While; }
{PRINT} 					{ return token::PRINT; }
{RETURN}  					{ return token::RETURN; }
{DISTANCE}                  {return token::DISTANCE;}
"TRANS"             {return token::TRANS;}
{STOP}                      { return token::STOP; }
{BITS}                      {return token::BITS;}
{HOME}	                    {return token::HOME;}      	
{BASE}	                    {return token::BASE;}    	
{TOOL}	                    {return token::TOOL;}    	
{TYPE}	                    {return token::TYPE;} 
{VAL}                       {return token::VAL;}
{PULSE}                     {return token::PULSE;}
{TWAIT}	                    {return token::TWAIT;}   	
{SIGNAL}                    {return token::SIGNAL;}   
{GOTO}                      {return token::GOTO;}  
{PROGRAM}	                {return token::FUNC;}  
{SIG}			            {return token::SIG;} 
{JMOVE}		                {return token::JMOVE;}   
{SWAIT}		                {return token::SWAIT;} 
{END_ST}                       {return token::END_ST;}
{END_DOT}                      {return token::END_DOT;}
{AND}                       {return token::AND;}
{OR}                        {return token::OR;}
{CASE}                      {return token::SWITCH;}
{CALL}                      {return token::CALL;}
{VALUE}                     {return token::CASE;}
{ANY}                       {return token::DEFAULT;}
{NULL}                      {return token::FNULL;}
{OF}                        {return token::OF;}
{SPACE}      {}
{REALS}   {return token::DEFINES;}
{STRINGS} {return token::DEFINES;}
{JOINTS}  {return token::JOINTS;}
".TRANS" {return token::TRANS_DOT;}
{TRUE}   {return token::FTRUE;}
{FALSE}  {return token::FFALSE;}
{LMOVE}  {return token::LMOVE;}
{DO}      {return token::DO;}
{UNTIL}   {return token::UNTIL;}
{ALIGN}       {return token::ALIGN;}
{BREAK}       {return token::BREAK;}
{HERE}        {return token::HERE;}    
{DECOMPOSE}   {return token::DECOMPOSE;}
{SPEED}       {return token::SPEED;}
{JAPPRO}      {return token::JAPPRO;}
{C1MOVE}      {return token::C1MOVE;}
{LAPPRO}      {return token::LAPPRO;}
{ACCURACY}    {return token::ACCURACY;}
{DRIVE}       {return token::DRIVE;}
{DRAW}        {return token::DRAW;}
{POINT}       {return token::POINT;}
{WEIGHT}        {return token::WEIGHT;}
{LDEPART}       {return token::LDEPART;}
{POINT_X}       {return token::POINT_X;}
{POINT_Z}       {return token::POINT_Z;}
{POINT_OAT}       {return token::POINT_OAT;}
{TDRAW}       {return token::TDRAW;}
{TCP_SEND}    {return token::TCP_SEND;}
{TCP_CLOSE}    {return token::TCP_CLOSE;}
{TCP_RECV}      {return token::TCP_RECV;}
{TCP_STATUS}    {return token::TCP_STATUS;}
{TCP_CONNECT}   {return token::TCP_CONNECT;}
{MM_S}          {return token::MM_S;}
{MM_MIN}        {return token::MM_MIN;}
{ALWAYS}        {return token::ALWAYS;}
{FOR}           {return token::FOR;}
{PAUSE}         {return token::PAUSE;}
{TO}            {return token::TO;}
{FINE}          {return token::FINE;}
{UNTIL}         {return token::UNTIL;}
{STEP}          {return token::STEP;}
"="                         {return token::ASS;}
"==" 						{ return token::EQ; }
">=" 						{ return token::GE; }
"<>" 						{ return token::NE; }
"<=" 						{ return token::LE; }
"["                    { return token::LR; }
"]"                    { return token::RR; }
","                     { return token::COMMA; }
"("                     { return token::LC; }
")"                     { return token::RC; }

"#"  {return token::JIN;}
"+"  { return token::ADD; }
"-"  { return token::SUB; }
"*"  { return token::MUL; }
":"    { return token::COLON; }  
"<"     {return token::LT;}
">"     {return token::GT;}
"$"     {return token::DOLAR;}
"#[" {return token::JOINTS_VAR;}

[.#|$]?[a-z|A-Z]([a-z|A-Z|0-9|_|.]+)?			{
                                                        yylval->sval = new QString( yytext );
                                                        return( token::Identifier );
                                             }

	

%%
