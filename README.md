# SimpleNetWorm

一个简单的网络爬虫，目前仅能通过title标签进行爬取，提供了一个示例程序，效果为为某直播平台炉石区的某主播进行搜寻，并返回标题与url。

该例子使用了libcurl获取页面，htmlcxx作相关解析，需要对上述库进行安装，库安装如下：
```
sudo apg-get install libhtmlcxx-dev
sudo apg-get install libcurl4-openssl-dev
```
在编译时添加选项 -lcurl -lhtmlcxx即可
我在qtcreator上进行开发，因此保留罗qt的相关问题，请按需使用或忽略之。
