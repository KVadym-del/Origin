#include <boost/spirit/include/lex_lexertl.hpp>

#include <iostream>
#include <string>

#include "../include/token.hpp"
#include "../include/grammar.hpp"

using namespace boost::spirit;

typedef std::string::iterator originBaseIterator_t;

typedef lex::lexertl::token<originBaseIterator_t> originToken_t;

typedef lex::lexertl::lexer<originToken_t> originLexer_t;

typedef OriginTokens<originLexer_t> originLex_t;

typedef originLex_t::iterator_type originIterator_t;

typedef OriginGrammar<originIterator_t> originGrammar_t;

int main()
{
    originLex_t lex;
    originGrammar_t calc(lex);

    std::string str(R"(
    {
	    hello world, hello it is me
    }
    )");

    std::string::iterator it = str.begin();
    originIterator_t iter = lex.begin(it, str.end());
    originIterator_t end = lex.end();

    bool r = qi::phrase_parse(iter, end, calc, qi::in_state("WS")[lex.white_space]);

    if (r && iter == end)
    {
        std::cout << "-------------------------\n";
        std::cout << "Parsing succeeded\n";
        std::cout << "-------------------------\n";
    }
    else
    {
        std::string rest(iter, end);
        std::cout << "-------------------------\n";
        std::cout << "Parsing failed\n";
        std::cout << "stopped at: \"" << rest << "\"\n";
        std::cout << "-------------------------\n";
    }

    std::cout << "Bye... :-) \n\n";
    return 0;
}