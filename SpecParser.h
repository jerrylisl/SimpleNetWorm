#ifndef SPECPARSER
#define SPECPARSER

#include<Parser.h>
#include<Hooker.h>
#include<vector>
#include<string>

class SpecParser
{
public:
    //特定站点的抓取
    enum HOST {DOUYU, QUANMIN, PANDA, HUYA};
    explicit SpecParser(HOST host);

private:
    static std::vector<string> _hostTable;
    HOST _host;

};

#endif // SPECPARSER

