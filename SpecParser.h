#ifndef SPECPARSER
#define SPECPARSER

#include"NetBug.h"
#include<vector>
#include<string>

class SpecParser
{
public:
    //特定站点的抓取
    using urlResult = std::pair<std::string, std::string>;
    enum HOST {QUANMIN, DOUYU, PANDA, HUYA};
    explicit SpecParser(HOST host)
        : _host(host),
          _worker()
    {
        _worker.addUrl(urls[_host], urlHosts[_host]);
    }

    urlResult search(std::string name)
    {
        return _worker.findByTitle(name);
    }





private:
    static std::string urls[];
    static std::string urlHosts[];

    HOST _host;
    NetBug _worker;


};

#endif // SPECPARSER

