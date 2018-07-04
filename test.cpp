#include<iostream>
#include<string>
#include<htmlcxx/html/ParserDom.h>
#include"Hooker.h"
#include"Parser.h"
#include"NetBug.h"
#include"SpecParser.h"
using namespace std;


static string urls[] = { "https://www.quanmin.tv/game/hearthstone",
                         "https://www.douyu.com/directory/game/How",
                         "https://www.panda.tv/cate/hearthstone",
                         "https://www.huya.com/g/hearthstone"    };

static string urlHosts[] = {"https://www.quanmin.tv/",
                         "https://www.douyu.com/",
                         "https://www.panda.tv/",
                         "https://www.huya.com/"    };

const int nums = 4;


int main() {


    SpecParser worker(SpecParser::HUYA);
    auto res = worker.search("魔法之风");
    if (res.first != "")
        cout << res.first << res.second << endl;
    else
        cout << "Can't find it" << endl;
    NetBug worker2;
    for (int i = 0; i < nums; ++ i)
        worker2.addUrl(urls[i], urlHosts[i]);
    auto res2 = worker2.findByTitle("王大锤");
    if (res.first != "")
        cout << res2.first << res2.second << endl;
    else
        cout << "Can't find it" << endl;
    return 0;
}

