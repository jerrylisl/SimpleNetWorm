#ifndef PARSER
#define PARSER

#include<htmlcxx/html/ParserDom.h>
#include<vector>
#include<iostream>
#include<unordered_map>

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

    std::pair<std::string, std::string> getTitles(std::string name);  //如果a标签有该属性，搜索之

private:
    std::string _page;
    std::string _host;
    HTML::ParserDom _parser;
    tree<HTML::Node> _dom;
    std::unordered_map<std::string, std::string> _titles;
};

#endif // PARSER

