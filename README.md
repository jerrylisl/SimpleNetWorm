# SimpleNetWorm

<<<<<<< HEAD

一个简单的网络爬虫，通过title标签进行爬取，提供了一个示例程序。
=======
一个简单的网络爬虫，目前仅能通过title标签进行爬取，提供了一个示例程序，效果为为某直播平台炉石区的某主播进行搜寻，并返回标题与url。
>>>>>>> 179fb3228adb0137ceb3b7a136e29213ea90c46b

该例子使用了libcurl获取页面，htmlcxx作相关解析，需要对上述库进行安装，库安装如下：
```
sudo apg-get install libhtmlcxx-dev
sudo apg-get install libcurl4-openssl-dev
```
<<<<<<< HEAD
之后可make编译: make CXXFLAGS="-std=c++11 -lcurl -lhtmlcxx"
在qtcreator上进行开发，因此保留了qt的相关文件，请按需使用或忽略之。
=======
在编译时添加选项 -lcurl -lhtmlcxx即可
我在qtcreator上进行开发，因此保留了qt的相关文件，请按需使用或忽略之。
>>>>>>> 179fb3228adb0137ceb3b7a136e29213ea90c46b
