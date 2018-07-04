#include"Parser.h"
#include<iterator>

std::vector<std::string> Parser::getLinks()
{
    std::vector<std::string> res;
    tree<HTML::Node>::iterator it = _dom.begin();
    tree<HTML::Node>::iterator end = _dom.end();

    for(; it != end; ++it)
    {

        if (it->tagName() == "a")
        {
            it->parseAttributes();
            if (it->attribute("href").first)
            {
                auto temp = it->attribute("href").second;
                while (temp[0] == '/')
                    temp = temp.substr(1);
                if (temp.substr(0, 3) == "www" || temp.substr(0, 4) == "http")
                    res.push_back(temp);
                else
                    res.push_back(_host + temp);
            }
        }
    }
    return res;
}

std::string Parser::getTitle()
{
    tree<HTML::Node>::iterator it = _dom.begin();
    tree<HTML::Node>::iterator end = _dom.end();

    for(; it != end; ++it)
    {

        if (it->tagName() == "title")
        {
            return std::next(it)->text();
        }
    }
    return "NO TITLE";
}

std::pair<std::string, std::string> Parser::getTitles(std::string name)
{
    tree<HTML::Node>::iterator it = _dom.begin();
    tree<HTML::Node>::iterator end = _dom.end();
    for(; it != end; ++it)
    {

        if (it->tagName() == "a")
        {

            it->parseAttributes();
            if (it->attribute("href").first && it->attribute("title").first)
            {

                auto title = it->attribute("title").second;
                if (title.find(name) != std::string::npos)
                {
                    auto temp = it->attribute("href").second;
                    while (temp[0] == '/')
                        temp = temp.substr(1);
                    if (temp.substr(0, 3) != "www" && temp.substr(0, 4) != "http")
                        temp = _host + temp;
                    _titles[title] = temp;
                    return std::pair<std::string, std::string>(title, temp);
                }
            }
        }
    }
    return std::pair<std::string, std::string>("","");
}
