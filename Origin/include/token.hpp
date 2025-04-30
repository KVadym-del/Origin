#include <boost/spirit/include/lex_lexertl.hpp>
#include <boost/spirit/include/qi.hpp>

using namespace boost::spirit;

template <typename Lexer> struct OriginTokens : lex::lexer<Lexer>
{
    OriginTokens()
    {
        identifier = "[a-zA-Z_][a-zA-Z0-9_]*";
        this->self = lex::char_(',') | '{' | '}' | identifier;

        this->white_space = "[ \\t\\n]+";
        this->self("WS") = white_space;
    }

    lex::token_def<> identifier, white_space;
};