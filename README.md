#  星火应用商店


众所周知，国内的Linux应用比较少，wine应用难以获取，优质工具分散在民间各大论坛，无法形成合力，难以改善生态

生态构建需要的不是某一方的单打独斗，而是人人行动起来，汇聚星火，产生燎原之势

我们创建了这个应用商店，广泛收录大家需要的软件包，搜集优质小工具，主动适配wine应用，存放到储存库供大家获取

我们支持：Deepin 20 ; Ubuntu 20.04 LTS ; UOS Home 20

希望看到这里的人也可以加入我们的队伍，开发或者投递应用都很欢迎，共同构建Linux应用生态

### [在这里投稿](http://upload.spark-app.store)

web页面部分正在开发当中，详情请见[web仓库](https://gitee.com/deepin-community-store/DCSAPP_WEB)


#### 说明

当前服务器线路列表（项目中包含）：

```
https://d.store.deepinos.org.cn/
https://store.deepinos.org.cn/
```

#### 调用参数(spk规则)

参数只有一个Url，该url应当遵循这种格式：`spk://<任意合法字符>/web分类/包名`

例如:

[spk://abcdefg/games/store.spark-app.hmcl](spk://abcdefg/games/store.spark-app.hmcl)


可选的web分类：

| 分类名称 | web分类   　    |
| -------- | -------------- |
| 网络应用 | network        |
| 社交沟通 | chat           |
| 音乐欣赏 | music          |
| 视频播放 | video          |
| 图形图像 | graphics       |
| 游戏娱乐 | games          |
| 办公学习 | office         |
| 阅读翻译 | reading        |
| 编程开发 | development    |
| 系统工具 | tools          |
| 主题美化 | beautify       |
| 其他应用 | others         |



#### 如何编译

Deepin V20/UOS 系统下, 安装依赖

```shell
sudo apt install qt5-default libdtkcore-dev libdtkwidget-dev qtwebengine5-dev libnotify-dev
```

```shell
git clone https://gitee.com/deepin-community-store/spark-store.git
cd spark-store
mkdir build
cd build
qmake ..
make -j
```

./build文件下的spark-store即为可执行文件
