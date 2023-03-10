
%option c++
%option warn
%option noyywrap
%option nounistd
%option yylineno

%{

/* +-------------------------------------------------+ *
 * | Prologue section, copied to output source file: | *
 * +-------------------------------------------------+ */

/*
 * NOTE: Flex version 2.6 or higher recommended.
 */

#define INC_LEXER 1
#include "common.hpp"
#undef  INC_LEXER

#include "symbol_table.hpp"

namespace moon
{

/* +-------------------------------------------------+ *
 * | Helper macros used by the generated code:       | *
 * +-------------------------------------------------+ */

// Note that these logging macros capture the current context,
// so they can only be called from within the FlexLexer class.
// Enabling these can be useful for debugging the lexer.
#if MOON_DUMP_LEXER_TOKENS
    #ifndef MOON_LEXER_LOG_STREAM
        #define MOON_LEXER_LOG_STREAM stdout
    #endif // MOON_LEXER_LOG_STREAM
    #define LEX_LOG_COMMENT(msg)  std::fprintf(MOON_LEXER_LOG_STREAM, "[LEX_CM](%02i): %s\n", lineno(), (msg))
    #define LEX_LOG_TOKEN(token)  std::fprintf(MOON_LEXER_LOG_STREAM, "[LEX_TK](%02i): '%s'\n", (yylineno), (token))
    #define LEX_LOG_TYPE(type)    std::fprintf(MOON_LEXER_LOG_STREAM, "[LEX_TP](%02i): '%s'\n", (yylineno), (type))
    #define LEX_LOG_KEYW(keyword) std::fprintf(MOON_LEXER_LOG_STREAM, "[LEX_KW](%02i): '%s'\n", (yylineno), (keyword))
    #define LEX_LOG_IDENT()       std::fprintf(MOON_LEXER_LOG_STREAM, "[LEX_ID](%02i): '%s'\n", (yylineno), (yytext))
    #define LEX_LOG_LIT(type)     std::fprintf(MOON_LEXER_LOG_STREAM, "[LEX_LI](%02i): '%s' (%s)\n", (yylineno), (yytext), (type))
#else // !MOON_DUMP_LEXER_TOKENS
    #define LEX_LOG_COMMENT(msg)
    #define LEX_LOG_TOKEN(token)
    #define LEX_LOG_TYPE(type)
    #define LEX_LOG_KEYW(keyword)
    #define LEX_LOG_IDENT()
    #define LEX_LOG_LIT(type)
#endif // MOON_DUMP_LEXER_TOKENS

// We are forced to cast the yyFlexLexer 'this' pointer to our moon::Lexer when
// calling the helper methods or using the extended ParseContext member. I do not know
// of a more elegant way of handling this with the generated FlexLexer code at the moment...
#define AS_MOON_LEXER(ptr) (*static_cast<moon::Lexer *>(ptr))

// Overwritten so we can capture the input to
// remember the current line for error printing.
#define YY_INPUT(buf, result, maxSize) AS_MOON_LEXER(this).lexOnInput((char *)buf, result, maxSize)

// Calls our custom error handler (called by FlexLexer).
#define YY_FATAL_ERROR(message) AS_MOON_LEXER(this).lexOnError(message)

/* +-------------------------------------------------+ *
 * | moon::Lexer local methods:                      | *
 * +-------------------------------------------------+ */

void Lexer::lexOnError(const char * message)
{
    const std::string filename = (ctx.srcFile != nullptr) ? *ctx.srcFile : "???";
    lexerError(message, filename, lineno(), ctx.currText);
}

void Lexer::lexOnInput(char * buf, int & result, const int maxSize)
{
    const auto readCount = LexerInput(buf, maxSize);
    if (readCount < 0)
    {
        YY_FATAL_ERROR("lexer input failed");
    }
    if (ctx.currText != nullptr && readCount > 0)
    {
        ctx.currText->append(buf, readCount);
    }
    result = readCount;
}

void Lexer::lexOnNewLine()
{
    if (ctx.currText != nullptr)
    {
        ctx.currText->clear();
    }
}

void Lexer::lexOnSingleLineComment()
{
    int ch;
    LEX_LOG_COMMENT("Skipping single-line comment");
    while ((ch = yyinput()) != '\n' && ch != YY_NULL) { }
}

void Lexer::lexOnMultiLineComment()
{
    LEX_LOG_COMMENT("Skipping multi-line comment");
    for (int ch;;)
    {
        while ((ch = yyinput()) != '*' && ch != YY_NULL)
        {
            // Skip chars until the next '*' or EOF.
        }
        if (ch == '*')
        {
            while ((ch = yyinput()) == '*')
            {
                // Eat up any '*' that follow the first one.
            }
            if (ch == '/')
            {
                break; // Found the comment's end.
            }
        }
        if (ch == YY_NULL)
        {
            YY_FATAL_ERROR("unexpected end-of-file while scanning multi-line comment");
            break;
        }
    }
}

/* +-------------------------------------------------+ *
 * | moon::Lexer special symbol/token handlers:      | *
 * +-------------------------------------------------+ */

void Lexer::lexOnIdentifier()
{
    MOON_ASSERT(ctx.yylval   != nullptr);
    MOON_ASSERT(ctx.symTable != nullptr);
    ctx.yylval->asSymbol = ctx.symTable->findOrDefineIdentifier(YYText(), lineno());
}

void Lexer::lexOnIntLiteral()
{
    MOON_ASSERT(ctx.yylval   != nullptr);
    MOON_ASSERT(ctx.symTable != nullptr);
    ctx.yylval->asSymbol = ctx.symTable->findOrDefineLiteral(YYText(), lineno(), Symbol::Type::IntLiteral);
}

void Lexer::lexOnFloatLiteral()
{
    MOON_ASSERT(ctx.yylval   != nullptr);
    MOON_ASSERT(ctx.symTable != nullptr);
    ctx.yylval->asSymbol = ctx.symTable->findOrDefineLiteral(YYText(), lineno(), Symbol::Type::FloatLiteral);
}

void Lexer::lexOnBoolLiteral()
{
    MOON_ASSERT(ctx.yylval   != nullptr);
    MOON_ASSERT(ctx.symTable != nullptr);
    ctx.yylval->asSymbol = ctx.symTable->findOrDefineLiteral(YYText(), lineno(), Symbol::Type::BoolLiteral);
}

void Lexer::lexOnStrLiteral()
{
    MOON_ASSERT(ctx.yylval   != nullptr);
    MOON_ASSERT(ctx.symTable != nullptr);

    // We have to do this special handling here to
    // resolve escaped string characters like \n, \t, \r, etc.
    const std::string escaped = escapeString(YYText());
    ctx.yylval->asSymbol = ctx.symTable->findOrDefineLiteral(escaped.c_str(), lineno(), Symbol::Type::StrLiteral);
}

} // namespace moon {}

%}

/* +-------------------------------------------------+ *
 * | Macros used by the rules (regular expressions): | *
 * +-------------------------------------------------+ */

LETTER        [a-z_A-Z]
DIGIT         [0-9]
HEXA_CHAR     [a-fA-F]
FRACT         "."{DIGIT}+
INT_LITERAL   -?({DIGIT})({DIGIT}|{HEXA_CHAR})*
FLT_LITERAL   -?{DIGIT}+{FRACT}
BOOL_LITERAL  ("true"|"false")
STR_LITERAL   \"(\\.|[^\"])*\"
IDENTIFIER    {LETTER}({LETTER}|{DIGIT})*
WHITE_SPACE   [ \t\f\v]
NEW_LINE      [\n\r]

/* +-------------------------------------------------+ *
 * | The lexer rules (language tokens / leaf nodes): | *
 * +-------------------------------------------------+ */

%%

    /* ---- Comments and whitespace: ---- */
{WHITE_SPACE}    { }                                               /* Whitespace ignored                               */
{NEW_LINE}       { AS_MOON_LEXER(this).lexOnNewLine();           } /* Keep track of the latest line for error printing */
";"             { AS_MOON_LEXER(this).lexOnSingleLineComment(); } /* C++ style single line comment                    */

    /* ---- Miscellaneous tokens and operators: ---- */
"."              { LEX_LOG_TOKEN( "."   ); return moon::Parser::token::MEMBER_REF;           }
"("              { LEX_LOG_TOKEN( "("   ); return moon::Parser::token::OPEN_PAR;             }
")"              { LEX_LOG_TOKEN( ")"   ); return moon::Parser::token::CLOSE_PAR;            }
"["              { LEX_LOG_TOKEN( "["   ); return moon::Parser::token::OPEN_BRAC;            }
"]"              { LEX_LOG_TOKEN( "]"   ); return moon::Parser::token::CLOSE_BRAC;           }
","              { LEX_LOG_TOKEN( ","   ); return moon::Parser::token::COMMA;                }
":"              { LEX_LOG_TOKEN( ":"   ); return moon::Parser::token::COLON;                }
"="              { LEX_LOG_TOKEN( "="   ); return moon::Parser::token::OP_ASSIGN;            }
"+"              { LEX_LOG_TOKEN( "+"   ); return moon::Parser::token::OP_PLUS;              }
"-"              { LEX_LOG_TOKEN( "-"   ); return moon::Parser::token::OP_MINUS;             }
"*"              { LEX_LOG_TOKEN( "*"   ); return moon::Parser::token::OP_MULTIPLY;          }
"/"              { LEX_LOG_TOKEN( "/"   ); return moon::Parser::token::OP_DIVIDE;            }
"mod"            { LEX_LOG_TOKEN( "mod" ); return moon::Parser::token::OP_MODULO;            }
">"              { LEX_LOG_TOKEN( ">"   ); return moon::Parser::token::OP_CMP_GREATER_THAN;  }
"<"              { LEX_LOG_TOKEN( "<"   ); return moon::Parser::token::OP_CMP_LESS_THAN;     }
">="             { LEX_LOG_TOKEN( ">="  ); return moon::Parser::token::OP_CMP_GREATER_EQUAL; }
"<="             { LEX_LOG_TOKEN( "<="  ); return moon::Parser::token::OP_CMP_LESS_EQUAL;    }
"=="             { LEX_LOG_TOKEN( "=="  ); return moon::Parser::token::OP_CMP_EQUAL;         }
"!="             { LEX_LOG_TOKEN( "!="  ); return moon::Parser::token::OP_CMP_NOT_EQUAL;     }
"and"            { LEX_LOG_TOKEN( "and" ); return moon::Parser::token::OP_LOGIC_AND;         }
"or"             { LEX_LOG_TOKEN( "or"  ); return moon::Parser::token::OP_LOGIC_OR;          }

    /* ---- Built-in types: ---- */

    /* ---- Language keywords: ---- */
"if"             { LEX_LOG_KEYW( "if"       ); return moon::Parser::token::KW_IF;            }
"then"           { LEX_LOG_KEYW( "then"     ); return moon::Parser::token::KW_THEN;          }
"else"           { LEX_LOG_KEYW( "else"     ); return moon::Parser::token::KW_ELSE;          }
"end"            { LEX_LOG_KEYW( "end"      ); return moon::Parser::token::KW_END;           }
"return"         { LEX_LOG_KEYW( "return"   ); return moon::Parser::token::KW_RETURN;        }
".program"       { LEX_LOG_KEYW( "func"     ); return moon::Parser::token::KW_FUNC;          }
"case"           { LEX_LOG_KEYW( "case"     ); return moon::Parser::token::KW_CASE;          }
"any"            { LEX_LOG_KEYW( "any"      ); return moon::Parser::token::KW_DEFAULT;       }
"do"             { LEX_LOG_KEYW( "do"       ); return moon::Parser::token::KW_DO;            }
"for"            { LEX_LOG_KEYW( "for"      ); return moon::Parser::token::KW_FOR;           }
"while"          { LEX_LOG_KEYW( "while"    ); return moon::Parser::token::KW_WHILE;         }
"break"          { LEX_LOG_KEYW( "break"    ); return moon::Parser::token::KW_BREAK;         }
"null"           { LEX_LOG_KEYW( "null"     ); return moon::Parser::token::KW_NULL;          }

    /* ---- Literal constants: ---- */
{INT_LITERAL}    { LEX_LOG_LIT( "int-literal"     ); AS_MOON_LEXER(this).lexOnIntLiteral();   return moon::Parser::token::INT_LITERAL;  }
{FLT_LITERAL}    { LEX_LOG_LIT( "float-literal"   ); AS_MOON_LEXER(this).lexOnFloatLiteral(); return moon::Parser::token::FLT_LITERAL;  }
{BOOL_LITERAL}   { LEX_LOG_LIT( "boolean-literal" ); AS_MOON_LEXER(this).lexOnBoolLiteral();  return moon::Parser::token::BOOL_LITERAL; }
{STR_LITERAL}    { LEX_LOG_LIT( "string-literal"  ); AS_MOON_LEXER(this).lexOnStrLiteral();   return moon::Parser::token::STR_LITERAL;  }

    /* ---- Identifies/names: ---- */
{IDENTIFIER}     { LEX_LOG_IDENT(); AS_MOON_LEXER(this).lexOnIdentifier(); return moon::Parser::token::IDENTIFIER; }

    /* ---- Anything not listed above is an error, handled by the special '.' rule: ---- */
.                { YY_FATAL_ERROR("invalid token"); }

%%
