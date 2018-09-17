# SimpleNetWorm



一个简单的网络爬虫，通过title标签进行爬取，提供了一个示例程序。


该例子使用了libcurl获取页面，htmlcxx作相关解析，需要对上述库进行安装，库安装如下：
```
sudo apg-get install libhtmlcxx-dev
sudo apg-get install libcurl4-openssl-dev
```
之后可make编译: make CXXFLAGS="-std=c++11 -lcurl -lhtmlcxx"


重新组织了搜索顺序，添加了指定单个站点的搜索

修改了搜索顺序，在搜索本页title后，会判断a标签中潜在的title属性，并作为搜索项（对个别站点有效）

添加了makefile



