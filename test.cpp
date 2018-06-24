#include <iostream>
#include<htmlcxx/html/ParserDom.h>
#include<Hooker.h>
#include<Parser.h>
#include<NetBug.h>
using namespace std;





int main() {

    string pURL = "https://www.quanmin.tv/game/hearthstone";
    string pp = "https://www.quanmin.tv";
    NetBug worker;
    worker.addUrl(pURL, pp);
    NetBug::urlResult res = worker.findByTitle("王大锤");
    cout << res.first << res.second << endl;
    return 0;
}

