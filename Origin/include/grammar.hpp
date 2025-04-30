#include <boost/spirit/include/lex_lexertl.hpp>
#include <boost/spirit/include/qi.hpp>

using namespace boost::spirit;

template <typename Iterator> struct OriginGrammar : qi::grammar<Iterator, qi::in_state_skipper<lex::token_def<>>>
{
    template <typename TokenDef> OriginGrammar(TokenDef const &tok) : OriginGrammar ::base_type(start)
    {
        start = '{' >> *(tok.identifier >> -ascii::char_(',')) >> '}';
    }

    qi::rule<Iterator, qi::in_state_skipper<lex::token_def<>>> start;
};
