#  星火商店

#### 介绍
星火商店商店，由深度社区爱好者维护
web页面部分正在开发当中，详情请见[web仓库](https://gitee.com/deepin-community-store/DCSAPP_WEB)

#### 说明

当前服务器线路列表（项目中包含）：

```
http://sucdn.jerrywang.top/
http://store.jerrywang.top/
http://dcstore.spark-app.store/
```

#### 参数

参数只有一个Url，该url应当遵循这种格式：`spk://<任意合法字符>/web分类/包名`

例如:

[spk://abcdefg/network/firefox-zh](spk://abcdefg/network/firefox-zh)

[spk://higklmn/network/firefox-zh](spk://higklmn/network/firefox-zh)

可选的web分类：

| 分类名称 | web分类   　    |
| -------- | -------------- |
| 网络应用 | network        |
| 社交沟通 | chat           |
| 音乐欣赏 | music          |
| 视频播放 | video          |
| 图形图像 | image_graphics |
| 游戏娱乐 | games          |
| 办公学习 | office         |
| 阅读翻译 | reading        |
| 编程开发 | development    |
| 系统工具 | tools          |
| 主题美化 | themes         |
| 其他应用 | others         |

 #### 目录结构

安装软件过程中产生的包，图标，截图等被储存到`/tmp/deepin-community-store/`中。

配置文件被储存到`~/.config/deepin-community-store/`中。

线路文件：新版的线路文件被放置于源服务器中，可随时刷新更新源列表

#### 如何编译

Deepin V20/UOS 系统下, 安装依赖

```shell
sudo apt install qt5-default libdtkcore-dev libdtkwidget-dev qtwebengine5-dev
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

#### 参与贡献

1.  Fork 本仓库
