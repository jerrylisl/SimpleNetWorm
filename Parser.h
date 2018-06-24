#ifndef PARSER
#define PARSER

#include<htmlcxx/html/ParserDom.h>
#include<vector>
#include<iostream>

using namespace htmlcxx;

class Parser
{
public:
    explicit Parser(std::string page, std::string host = "")
        : _page(page),
          _host(host),
          _parser(),
          _dom(_parser.parseTree(_page))   {    }

    void outputDom()
    {
        std::cout << _dom << std::endl;
    }

    tree<HTML::Node>::iterator domBegin()
    {
        return _dom.begin();
    }

    tree<HTML::Node>::iterator domEnd()
    {
        return _dom.end();
    }

    std::vector<std::string> getLinks();
    std::string getTitle();

    std::string getHost()
    {
        return _host;
    }

private:
    std::string _page;
    std::string _host;
    HTML::ParserDom _parser;
    tree<HTML::Node> _dom;
};

#endif // PARSER

