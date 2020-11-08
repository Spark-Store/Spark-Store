#**********************************************************
#Author: Qt君
#微信公众号: Qt君(文章首发)
#Website: qtbig.com(后续更新)
#Email:  2088201923@qq.com
#QQ交流群: 732271126
#LISCENSE: MIT
#**********************************************************
INCLUDEPATH += $$PWD/ 

QT += network

!CONFIG(QT_APP_MODE) {
    LIBS += -L$$OUT_PWD/Lib -lQtNetworkService
}
