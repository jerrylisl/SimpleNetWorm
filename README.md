# SimpleNetWorm


一个简单的网络爬虫，通过title标签进行爬取，提供了一个示例程序。

该例子使用了libcurl获取页面，htmlcxx作相关解析，需要对上述库进行安装，库安装如下：
```
sudo apg-get install libhtmlcxx-dev
sudo apg-get install libcurl4-openssl-dev
```
之后可make编译
在qtcreator上进行开发，因此保留了qt的相关文件，请按需使用或忽略之。
