%{
#include <cstdlib>
#include <cstring>
#include <string>

#include "semantic.h"
#include "bison.hpp"  
#include "types.h"
#include "myflexer.h"

#define YY_DECL int myflexer::yylex(YYSTYPE * lvalp, YYLTYPE * loc)

#define YY_USER_ACTION loc->first_line = loc->last_line = yylineno;

%}

%option c++
%option batch
%option stack
%option yylineno
%x STR
%x SINGLE_LINE_COMMENT_STATE

%%



";"	yy_push_state(SINGLE_LINE_COMMENT_STATE);
<SINGLE_LINE_COMMENT_STATE>{
	[^\n]*	;
	"\n"	{
		yy_pop_state(); 
	}
}

"[ \f\n\r\t\v]+" {return SPACE;}       
"[ \f\n\r\t\v]*" {return LINE_GAP;}    
"[ \f\t\v]+" {return GAP;}     
"STOP"	{return STOP;}      
"HOME"	{return HOME;}      	
"BASE"	{return BASE;}    	
"TOOL"	{return TOOL;}    	
"TYPE"	{return TYPE;}    		
"TWAIT"	{return TWAIT;}   	
"SIGNAL"  {return SIGNAL;}   	   
"RETURN"  {return RETURN;}   	     
"IF"      {return IF;}      
"THEN"    {return THEN;}        
"ELSE"    {return ELSE;}          
"ELSEIF"  {return ELSEIF;}        
"GOTO"    {return GOTO;}            
"\.PROGRAM"	  {return FUNC;}   
"FOR"			 {return FOR;}   
"SIG"			 {return SIG;}   
"JMOVE"		 {return JMOVE;}   
"SWAIT"		 {return SWAIT;}   
"TRUE" {
  lvalp->str = yytext;
  return FTRUE;
}

"FALSE" {
  lvalp->str = yytext;
  return FFALSE;
}

"END"
{
	return END_ST;
}
"\.END" {
	return END_DOT;
}

"AND" {
	return AND;
}

"OR" {
	return OR;
}

"CASE" {
	return SWITCH;
}

"CALL"
{
	return CALL;
}

"VALUE" {
	return CASE;
}

"ANY" {
	return DEFAULT;
}

"NULL" {
	return FNULL;
}


"OF"
{
	return OF;
}

"\."
{
   return DOT;
}

"\""
{
return QUOTATION;
}
"\.TRANS"
{
	return TRANS;
}

\n {
}

"\.REALS"
{
	return REALS;
}


"\.JOINTS"
{
	return JOINTS;
}

"\.STRINGS"
{
	return STRINGS;
}

"\""	yy_push_state(STR); lvalp->str = String();
<STR>\\n	lvalp->str += String("\n");
<STR>\\t	lvalp->str += String("\t");
<STR>\\s	lvalp->str += String(" ");
<STR>\\r	lvalp->str += String("\r");
<STR>\\\"	lvalp->str += String("\"");
<STR>[^\"] 	lvalp->str += String(yytext);
<STR>"\""	yy_pop_state(); return STRING_DEFINITION; 




"MOD" {
  return DIVIDE_MOD;
}

"\," {
	return ARG_SPLITTER;
}

"TO"
{
	return TO;
}

"\+" {
	return PLUS;
}

"\-" {
	return MINUS;
}

"\/" {
	return DIVIDE;
}

"\*" {
	return MULTIPLY;
}


"\=" {
	return ASSIGN;
}

"\>" {
	lvalp->str = String(yytext);
	return MORE;
}

"\<" {
	lvalp->str = String(yytext);
	return LESS;
}

"\>\=" {
	lvalp->str = String(yytext);
	return MORE_OR_EQUAL;
}

"\<\=" {
	lvalp->str = String(yytext);
	return LESS_OR_EQUAL;
}

"\=\=" {
	lvalp->str = String(yytext);
	return EQUAL;
}

"\!\=" {
	lvalp->str = String(yytext);
	return NOT_EQUAL;
}

"(" {
	return OPEN_BRACKET;
}

")" {
	return CLOSE_BRACKET;
}

":" {
	return COLON;
}

"\[" {
	return OPEN_SQUARE_BRACKET;
}

"\]" {
	return CLOSE_SQUARE_BRACKET;
}


[.#$a-zA-Z_][a-zA-Z0-9_]* {
	lvalp->str = String(yytext);
	return IDENTIFIER;
}

[a-zA-Z_][a-zA-Z0-9_]*(\.[a-zA-Z_][a-zA-Z0-9_]*)+ {
	lvalp->str = String(yytext);
	return IDENTIFIER_DOT;
}

[a-zA-Z_][a-zA-Z0-9_]*(\-\>[a-zA-Z_][a-zA-Z0-9_]*)+ {
	lvalp->str = String(yytext);
	return IDENTIFIER_POINTER;
}


-?[0-9]+ {
	lvalp->str = String(yytext);
	return NUMBER;
}

-?[0-9]+\.[0-9]+([Ee]-?[0-9]+)? {
	lvalp->str = String(yytext);
	return FKFLOAT;
}


%%
int yyFlexLexer::yywrap()
{
	return 1;
}
int yyFlexLexer::yylex()
{
	return 0;
}
