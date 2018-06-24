#include<Hooker.h>
#include<functional>
#include<iostream>

std::string Hooker::_currentPage = "";


int Hooker::getFromURL()
{
    if (!_curl)
    {
        std::cout << "error" << std::endl;
        return -1;
    }

    using namespace std::placeholders;

    curl_easy_setopt(_curl, CURLOPT_URL, _url.c_str());//url地址
    curl_easy_setopt(_curl, CURLOPT_POST, 0); //设置问非0表示本次操作为post
    //curl_easy_setopt(_curl, CURLOPT_POSTFIELDS, pParameter); //post参数
    curl_easy_setopt(_curl, CURLOPT_WRITEFUNCTION, &Hooker::handleFunc); //对返回的数据进行操作的函数地址
                                                               //curl_easy_setopt(curl,CURLOPT_WRITEDATA,fptr); //这是write_data的第四个参数值
    //curl_easy_setopt(curl, CURLOPT_VERBOSE, 1); //打印调试信息
    //curl_easy_setopt(curl, CURLOPT_HEADER, 1); //将响应头信息和相应体一起传给write_data
    curl_easy_setopt(_curl, CURLOPT_FOLLOWLOCATION, true); //表示follow服务器返回的重定向信息。
    curl_easy_setopt(_curl, CURLOPT_FORBID_REUSE, 1); //当进程处理完毕后强制关闭会话，不再缓存供重用
    curl_easy_setopt(_curl, CURLOPT_TIMEOUT, 10);  //设置访问的超时
    curl_easy_setopt(_curl, CURLOPT_COOKIEFILE, "curlposttest.txt");//包含cookie信息的文件
    curl_easy_setopt(_curl, CURLOPT_COOKIEJAR, "curlposttest.txt"); //连接结束后保存cookie信息的文件
    curl_easy_setopt(_curl, CURLOPT_USERAGENT, "libcurl-agent/1.0"); //HTTP头中User-Agent的值


    _res = curl_easy_perform(_curl);
    if (_res == 0)
    {
        _page = _currentPage;
        _currentPage = "";
    }
    return _res;

}



size_t Hooker::handleFunc(void* buffer, size_t size, size_t nmemb, void *stream)
{
    _currentPage += (char*)buffer;
    return size * nmemb;
}
