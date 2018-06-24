#include<NetBug.h>

NetBug::urlResult NetBug::findByTitle(std::string name)
{
    _exist.clear();
    while (!_urlQueue.empty())
        _urlQueue.pop();
    for (int i = 0; i < _urls.size(); ++ i)
        _urlQueue.push(NetBug::urlTarget(1, _urls[i]));
    while (!_urlQueue.empty())
    {
        auto url = _urlQueue.front();
        _urlQueue.pop();
        if (url.first < 3 && url.second.second != "")
        {
            auto thooker = Hooker(url.second.first, url.second.second);
            auto t = thooker.getFromURL();
            if (t == 0)
            {
                auto tparser = Parser(thooker.getPage(), thooker.getHost());
                if (tparser.getTitle().find(name) != std::string::npos)
                    return NetBug::urlResult(tparser.getTitle(), url.second.first);
                auto res = tparser.getLinks();
                for (int i = 0; i < res.size(); ++ i)
                {
                    if (!_exist.count(res[i]))
                    {
                        _exist.insert(res[i]);
                        _urlQueue.push(urlTarget(url.first + 1,
                                                 NetBug::urlMessage(res[i],tparser.getHost())));
                    }
                }
            }
        }
    }
    return NetBug::urlResult("", "");
}
