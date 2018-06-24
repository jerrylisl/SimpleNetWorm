#include<Parser.h>
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
                if (temp.substr(0, 3) == "www")
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
