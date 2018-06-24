#ifndef NETBUG
#define NETBUG

#include<Parser.h>
#include<Hooker.h>
#include<string>
#include<vector>
#include<queue>
#include<unordered_set>

class NetBug
{
public:
    using urlResult = std::pair<std::string, std::string>;
    using urlMessage = std::pair<std::string, std::string>;
    using urlTarget = std::pair<int, urlMessage>;
    urlResult findByTitle(std::string name);

    void addUrl(std::string url, std::string host)
    {
        _urls.push_back(urlMessage(url, host));
    }


private:
    std::vector<urlMessage> _urls;
    std::queue<urlTarget> _urlQueue;
    std::unordered_set<std::string> _exist;
};

#endif // NETBUG

