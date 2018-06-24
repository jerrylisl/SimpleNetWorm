#ifndef HOOKER
#define HOOKER

#include<curl/curl.h>
#include<string>

class Hooker
{
public:
    explicit Hooker(std::string url, std:: string host = "")
        : _url(url),
          _host(host),
          _curl(curl_easy_init())
    {
        if (_host == "")
            _host = _url;
    }

    ~Hooker()
    {
        if (_curl)
        {
            curl_easy_cleanup(_curl);
        }

    };


    int getFromURL();

    std::string getPage()
    {
        return _page;
    }

    std::string getHost()
    {
        return _host;
    }

    int getSize()
    {
        return _page.size();
    }

    std::string getStatus()
    {
       return curl_easy_strerror(_res);
    }


private:
    static size_t handleFunc(void* buffer, size_t size, size_t nmemb, void *stream);

    std::string _url;
    std::string _host;
    CURL* _curl;
    CURLcode _res;
    std::string _page;

    static std::string _currentPage;

};



#endif // HOOKER

