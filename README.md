#  星火应用商店


众所周知，国内的Linux应用比较少，wine应用难以获取，优质工具分散在民间各大论坛，无法形成合力，难以改善生态

生态构建需要的不是某一方的单打独斗，而是人人行动起来，汇聚星火，产生燎原之势

我们创建了这个应用商店，广泛收录大家需要的软件包，搜集优质小工具，主动适配wine应用，存放到储存库供大家获取

我们支持：deepin 20 ; ubuntu 20.04LTS ;UOS Home 20

希望看到这里的人也可以加入我们的队伍，开发或者投递应用都很欢迎，共同构建Linux应用生态

### [在这里投稿](http://upload.spark-app.store)

web页面部分正在开发当中，详情请见[web仓库](https://gitee.com/deepin-community-store/DCSAPP_WEB)


#### 说明

当前服务器线路列表（项目中包含）：

```
http://sucdn.jerrywang.top/
http://store.jerrywang.top/
http://dcstore.spark-app.store/
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
| 图形图像 | image_graphics |
| 游戏娱乐 | games          |
| 办公学习 | office         |
| 阅读翻译 | reading        |
| 编程开发 | development    |
| 系统工具 | tools          |
| 主题美化 | themes         |
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

# 星火应用商店文档

# 目录结构
几个目录结构
```
/
/icons 图标文件夹       
/tags 首页图标      
/tras 多语言翻译        
```

主要的文件分析
```js
spark-store.pro Qt工程配置文件
ssinstall 调用包安装器的脚本
icons.qrc 图标资源文件  
main.cpp 入口文件
widget.h widget.cpp widget.ui 主要窗口控件
downloadlist.h downloadlist.cpp downloadlist.ui 单个软件的下载安装展示控件      
progressload.h progressload.cpp 网页加载显示？ 得在deepin上编译运行才能搞清楚   
workerthreads.h workerthreads.cpp 应用信息加载线程      
image_show.h image_show.cpp 应用页面截图预览控件    
big_image.h big_image.cpp 大图查看控件      
```

# 使用的开源库及第三方工具
* GDebi 一个 Ubuntu 软件中心的轻量级替代品 https://linux.cn/article-4982-1.html
* libnotify 系统通知 https://developer.gnome.org/libnotify/unstable/


# 源码分析
## 应用的组成部分
左侧应用分类菜单
主窗口的下拉菜单
应用列表页面
应用详情页面
应用首页，有几个链接跳转        
商店设置页面
下载列表页面    

## 应用初始化，及主控件加载
初始化 `DApplication` 进入事件循环。        
设置关于我们弹窗 `DAboutDialog`。       
主控件 Widget 根据不同屏幕大小自适应。  
首页打开webview页面，如果传入了`spk://`参数，会打开应用详情页。 
```cpp
// main.cpp
QString arg1=argv[1];
if(arg1.left(6)=="spk://"){
    w.openUrl(QUrl(argv[1]));
}

// widget.cpp
void Widget::openUrl(QUrl u)
{
    QString app=serverUrl + "store"+u.path()+"/app.json";
    ui->webEngineView->setUrl(app); // 会触发 webEngineView 的
}

```

**Widget 初始化**
```cpp
void Widget::initConfig()
{
    ...
    // 读取服务器URL并初始化菜单项的链接
    QSettings readConfig(QDir::homePath()+"/.config/spark-store/config.ini",QSettings::IniFormat);
    if(readConfig.value("server/choose").toString()!=""){
        ui->comboBox_server->setCurrentText(readConfig.value("server/choose").toString());
        appinfoLoadThread.setServer(serverUrl=readConfig.value("server/choose").toString());
    }else {
        appinfoLoadThread.setServer(serverUrl="http://sucdn.jerrywang.top/");  // 默认URL
    }
    configCanSave=true;   //　防止触发保存配置信号
    menuUrl[0]=serverUrl + "store/#/"; // 首页
    // 下面是各个应用分类页面，直接加载的webview的
    // 每个连接对应一个左侧的菜单项，在构造函数用连接到 chooseLeftMenu 槽函数
    menuUrl[1]=serverUrl + "store/#/network";
    ...
    menuUrl[12]=serverUrl + "store/#/others";
    ...
    ui->webfoot->hide();

    //初始化首页
    ui->webEngineView->setUrl(menuUrl[0]);
}
/**
 * 菜单切换逻辑
 * 
 */ 
void Widget::chooseLeftMenu(int index)
{
    nowMenu=index;
    updateUI();
    left_list[index]->setStyleSheet("color:#FFFFFF;background-color:"+main_color.name()+";border-radius:8;border:0px");
    // index <=12 加载某个分类的应用列表的webviejw
    // index == 13 加载下载列表页面
    if(index<=12){
        if(themeIsDark){
            darkurl = 夜间模式的URL
            ui->webEngineView->setUrl(darkurl);
        }else {
            ui->webEngineView->setUrl(menuUrl[index]);
        }
        ui->stackedWidget->setCurrentIndex(0);
    }else if (index==13) {
        ui->stackedWidget->setCurrentIndex(1);
    }
}
```

## 应用下载安装卸载分析
**应用详情页面加载**
```cpp
/**
 * 加载单个应用的信息
 */ 
void Widget::on_webEngineView_urlChanged(const QUrl &arg1)
{
    //分析出服务器中的分类名称
    ...
    //如果是app.json就打开详情页
    if(arg1.path().right(8)=="app.json"){
        ...
        // 读取相应的应用信息
        appinfoLoadThread.requestInterruption();
        appinfoLoadThread.wait(100);
        appinfoLoadThread.setUrl(arg1);
        appinfoLoadThread.start();
    }
}
// 设置详情页的APP信息 
SpkAppInfoLoaderThread::requestSetAppInformation() -> Widget::sltAppinfoDetails()
// 设置详情页的APP图标
SpkAppInfoLoaderThread::finishedIconLoad() -> Widget::sltAppinfoIcon()
// 设置详情页的APP截图
SpkAppInfoLoaderThread::finishedScreenshotLoad() -> Widget::sltAppinfoScreenshot()

// 下载APP详情信息线程
void SpkAppInfoLoaderThread::run()
{
    QProcess get_json;
    get_json.start("curl -o app.json " + targetUrl.toString());
    QFile app_json("app.json");
    读取 app.json 里的信息，提取应用名、描述、图标、截图  
    处理完毕后发射相应的信号    
}
```


**应用下载**		
Widget::on_pushButton_download_clicked() 是点击下载的安装方法。     
最终使用的是 `QNetwrokAccessManager` 进行GET请求获取数据写入文件。             
```cpp
void Widget::on_pushButton_download_clicked()
{
    if(!isBusy){
        file = new QFile(fileName);
        ...
        nowDownload+=1;
        startRequest(urList.at(nowDownload-1)); // 进行链接请求
    }
}
void Widget::startRequest(QUrl url)
{
    reply = manager->get(QNetworkRequest(url));
    // 请求响应完成，关闭文件，清理下载队列
    connect(reply,SIGNAL(finished()),this,SLOT(httpFinished())); 
    // 接收应用下载数据
    connect(reply,SIGNAL(readyRead()),this,SLOT(httpReadyRead())); 
    // 更新应用下载进度
    connect(reply,SIGNAL(downloadProgress(qint64,qint64)),this,SLOT(updateDataReadProgress(qint64,qint64)));
}
```

使用 QSettings 来读取配置，更换服务源
```cpp
void Widget::on_comboBox_server_currentIndexChanged(const QString &arg1)
{
    appinfoLoadThread.setServer(arg1); // 服务器信息更新
    if(configCanSave){
        ui->label_setting1->show();
        QSettings *setConfig=new QSettings(QDir::homePath()+"/.config/spark-store/config.ini",QSettings::IniFormat);
        setConfig->setValue("server/choose",arg1);
    }
}
```
使用 `QProcess` 来调用各种小文件下载、包安装卸载的命令。    

**应用安装**        
```cpp
void Widget::httpFinished() // 完成下载
{
    ...清理资源
    download_list[nowDownload-1].readyInstall();
    download_list[nowDownload-1].free=true;
    if(nowDownload<allDownload){    // 如果有排队则下载下一个
        ...队列的下一个下载请求
    }
}
void downloadlist::readyInstall()
{
    ...将安装按钮设置为允许点击
    ui->pushButton_install->setEnabled(true);
    ui->pushButton_install->show();
    ui->pushButton_2->hide();
    Widget::sendNotification(tr("Finished downloading %1, awaiting to install").arg(ui->label->text()), 5000,
                                    "/tmp/spark-store/icon_"+QString::number(num).toUtf8()+".png");
}
void downloadlist::on_pushButton_install_clicked()
{
    //弹出菜单
    menu_install->exec(cursor().pos());
}
在 downloadlist 构造函数里将三种安装方式的按钮按条件放入了 menu_install 菜单里  
用户点击时，downloadlist::install() 方法
三种安装方式为： gdebi, dpkg, deepin-deb-installer  
void downloadlist::install(int t)
{
    QtConcurrent::run([=](){
        QProcess installer;
        installer.start("pkexec gdebi -n /tmp/spark-store/"+ui->label_filename->text().toUtf8());
        installer.start("pkexec ssinstall /tmp/spark-store/"+ui->label_filename->text().toUtf8());
        installer.start("deepin-deb-installer /tmp/spark-store/"+ui->label_filename->text().toUtf8());
    });
}
```

**应用卸载**
```cpp
void Widget::on_pushButton_uninstall_clicked()
{
    QtConcurrent::run([=](){
        uninstall.start("pkexec apt purge -y "+pkgName);
    });
}
```

**仓库源更新**      
```cpp
// 更新源列表
void Widget::on_pushButton_updateServer_clicked()
{
    QtConcurrent::run([=](){
        ...
        QFile::remove(QDir::homePath().toUtf8()+"/.config/spark-store/server.list");
        system("curl -o "+QDir::homePath().toUtf8()+"/.config/spark-store/server.list http://dcstore.shenmo.tech/store/server.list");
        server.open(QDir::homePath().toUtf8()+"/.config/spark-store/server.list",std::ios::in);
        ...
        while (getline(server,lineTmp)) {
            ui->comboBox_server->addItem(QString::fromStdString(lineTmp));
        }
    });
}
// 更新星火商店apt源    
void Widget::on_pushButton_updateApt_clicked()
{
    QtConcurrent::run([=](){
        读取 comboBox_server 的内容，写入 /tmp/spark-store/sparkstore.list 文件
        创建bash脚本，内容为将 sparkstore.list 移动到  /etc/apt/sources.list.d/ 目录下
        使用QProcess 执行命令 pkexec update.sh
    }):
}
```

## 发送系统通知     
```cpp
#include <libnotify/notify.h>

static NotifyNotification *_notify = nullptr; // 初始化
notify_init(tr("Spark\\ Store").toLocal8Bit()); // 构造函数初始化
notify_uninit(); // 析构函数调用 

void Widget::sendNotification(const QString &message, const int msTimeout, const QString &icon)
{
    if(_notify == nullptr)
    {
        _notify = notify_notification_new(tr("Spark\\ Store").toLocal8Bit(), message.toLocal8Bit(), icon.toLocal8Bit());
        notify_notification_set_timeout(_notify, msTimeout);
    }
    else
        notify_notification_update(_notify, tr("Spark\\ Store").toLocal8Bit(), message.toLocal8Bit(), icon.toLocal8Bit());

    notify_notification_show(_notify, nullptr);
}
```




