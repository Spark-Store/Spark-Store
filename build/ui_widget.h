/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <dtitlebar.h>
#include <image_show.h>
#include <progressload.h>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout_2;
    QWidget *widget_menuList;
    QGridLayout *gridLayout_5;
    QPushButton *menu_video;
    QPushButton *menu_download;
    QPushButton *menu_system;
    QPushButton *menu_theme;
    QPushButton *menu_music;
    QLabel *icon;
    QSpacerItem *verticalSpacer_7;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *menu_dev;
    QPushButton *menu_office;
    QPushButton *pushButton_return;
    QSpacerItem *verticalSpacer;
    QPushButton *menu_read;
    QPushButton *menu_other;
    QPushButton *menu_main;
    QPushButton *menu_photo;
    QPushButton *menu_game;
    QPushButton *menu_chat;
    QPushButton *menu_network;
    QWidget *line1_widget;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *pushButton_refresh;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_4;
    QWebEngineView *webEngineView;
    QWidget *webfoot;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QListWidget *listWidget;
    QPushButton *btn_openDir;
    QWidget *page_3;
    QVBoxLayout *verticalLayout_16;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_17;
    QWidget *widget_3;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_download;
    QLabel *label_appname;
    QLabel *label_info;
    QLabel *label_appicon;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_3;
    QPushButton *pushButton_uninstall;
    QPushButton *pushButton_website;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *pushButton;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *tag_community;
    QLabel *tag_ubuntu;
    QLabel *tag_deepin;
    QLabel *tag_uos;
    QLabel *tag_dtk5;
    QLabel *tag_dwine2;
    QLabel *tag_dwine5;
    QLabel *tag_a2d;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *pushButton_translate;
    QWidget *widget_5;
    QVBoxLayout *verticalLayout_19;
    QLabel *label_10;
    QLabel *label_more;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_18;
    QLabel *label_9;
    QScrollArea *scrollArea_appicture;
    QWidget *scrollAreaWidgetContents_2;
    QHBoxLayout *horizontalLayout_4;
    image_show *screen_0;
    image_show *screen_1;
    image_show *screen_2;
    image_show *screen_3;
    image_show *screen_4;
    QSpacerItem *verticalSpacer_5;
    QLabel *label_show;
    QWidget *page_4;
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_3;
    QVBoxLayout *verticalLayout_23;
    QWidget *widget_6;
    QVBoxLayout *verticalLayout_22;
    QLabel *label_2;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QComboBox *comboBox_server;
    QPushButton *pushButton_updateServer;
    QLabel *label_setting1;
    QSpacerItem *horizontalSpacer_3;
    QWidget *widget_8;
    QGridLayout *gridLayout_3;
    QLabel *label_7;
    QPushButton *pushButton_updateApt;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_aptserver;
    QWidget *widget_9;
    QVBoxLayout *verticalLayout_26;
    QLabel *label_8;
    QWidget *widget_10;
    QGridLayout *gridLayout_4;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton_clear;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *tmp_size_ui;
    QLabel *label_11;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_25;
    QLabel *label_4;
    QLabel *label_5;
    QSpacerItem *verticalSpacer_4;
    DTitlebar *titlebar;
    ProgressLoad *progressload;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(1053, 674);
        gridLayout_2 = new QGridLayout(Widget);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        widget_menuList = new QWidget(Widget);
        widget_menuList->setObjectName(QStringLiteral("widget_menuList"));
        widget_menuList->setMinimumSize(QSize(150, 0));
        widget_menuList->setMaximumSize(QSize(150, 16777215));
        QFont font;
        font.setPointSize(11);
        widget_menuList->setFont(font);
        widget_menuList->setStyleSheet(QStringLiteral(""));
        gridLayout_5 = new QGridLayout(widget_menuList);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setContentsMargins(5, -1, 5, -1);
        menu_video = new QPushButton(widget_menuList);
        menu_video->setObjectName(QStringLiteral("menu_video"));

        gridLayout_5->addWidget(menu_video, 6, 0, 1, 6);

        menu_download = new QPushButton(widget_menuList);
        menu_download->setObjectName(QStringLiteral("menu_download"));

        gridLayout_5->addWidget(menu_download, 16, 0, 1, 6);

        menu_system = new QPushButton(widget_menuList);
        menu_system->setObjectName(QStringLiteral("menu_system"));

        gridLayout_5->addWidget(menu_system, 12, 0, 1, 6);

        menu_theme = new QPushButton(widget_menuList);
        menu_theme->setObjectName(QStringLiteral("menu_theme"));

        gridLayout_5->addWidget(menu_theme, 13, 0, 1, 6);

        menu_music = new QPushButton(widget_menuList);
        menu_music->setObjectName(QStringLiteral("menu_music"));

        gridLayout_5->addWidget(menu_music, 5, 0, 1, 6);

        icon = new QLabel(widget_menuList);
        icon->setObjectName(QStringLiteral("icon"));
        icon->setMinimumSize(QSize(0, 36));
        icon->setMaximumSize(QSize(16777215, 36));

        gridLayout_5->addWidget(icon, 0, 0, 1, 2);

        verticalSpacer_7 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_5->addItem(verticalSpacer_7, 1, 0, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(3, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_8, 0, 5, 1, 1);

        menu_dev = new QPushButton(widget_menuList);
        menu_dev->setObjectName(QStringLiteral("menu_dev"));

        gridLayout_5->addWidget(menu_dev, 11, 0, 1, 6);

        menu_office = new QPushButton(widget_menuList);
        menu_office->setObjectName(QStringLiteral("menu_office"));

        gridLayout_5->addWidget(menu_office, 9, 0, 1, 6);

        pushButton_return = new QPushButton(widget_menuList);
        pushButton_return->setObjectName(QStringLiteral("pushButton_return"));
        pushButton_return->setMaximumSize(QSize(40, 16777215));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/icons/category_active.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_return->setIcon(icon1);

        gridLayout_5->addWidget(pushButton_return, 0, 4, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer, 17, 0, 1, 1);

        menu_read = new QPushButton(widget_menuList);
        menu_read->setObjectName(QStringLiteral("menu_read"));

        gridLayout_5->addWidget(menu_read, 10, 0, 1, 6);

        menu_other = new QPushButton(widget_menuList);
        menu_other->setObjectName(QStringLiteral("menu_other"));

        gridLayout_5->addWidget(menu_other, 14, 0, 1, 6);

        menu_main = new QPushButton(widget_menuList);
        menu_main->setObjectName(QStringLiteral("menu_main"));
        menu_main->setStyleSheet(QStringLiteral(""));
        menu_main->setFlat(false);

        gridLayout_5->addWidget(menu_main, 2, 0, 1, 6);

        menu_photo = new QPushButton(widget_menuList);
        menu_photo->setObjectName(QStringLiteral("menu_photo"));

        gridLayout_5->addWidget(menu_photo, 7, 0, 1, 6);

        menu_game = new QPushButton(widget_menuList);
        menu_game->setObjectName(QStringLiteral("menu_game"));

        gridLayout_5->addWidget(menu_game, 8, 0, 1, 6);

        menu_chat = new QPushButton(widget_menuList);
        menu_chat->setObjectName(QStringLiteral("menu_chat"));

        gridLayout_5->addWidget(menu_chat, 4, 0, 1, 6);

        menu_network = new QPushButton(widget_menuList);
        menu_network->setObjectName(QStringLiteral("menu_network"));

        gridLayout_5->addWidget(menu_network, 3, 0, 1, 6);

        line1_widget = new QWidget(widget_menuList);
        line1_widget->setObjectName(QStringLiteral("line1_widget"));
        line1_widget->setMinimumSize(QSize(0, 1));
        line1_widget->setMaximumSize(QSize(16777215, 4));
        line1_widget->setStyleSheet(QStringLiteral("background-color:#808080"));

        gridLayout_5->addWidget(line1_widget, 15, 0, 1, 6);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_9, 0, 2, 1, 1);

        pushButton_refresh = new QPushButton(widget_menuList);
        pushButton_refresh->setObjectName(QStringLiteral("pushButton_refresh"));
        pushButton_refresh->setMaximumSize(QSize(40, 16777215));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icons/icons/refresh-page.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_refresh->setIcon(icon2);

        gridLayout_5->addWidget(pushButton_refresh, 0, 3, 1, 1);


        gridLayout_2->addWidget(widget_menuList, 0, 0, 4, 1);

        stackedWidget = new QStackedWidget(Widget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setStyleSheet(QStringLiteral(""));
        stackedWidget->setLineWidth(0);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        verticalLayout_4 = new QVBoxLayout(page);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        webEngineView = new QWebEngineView(page);
        webEngineView->setObjectName(QStringLiteral("webEngineView"));
        webEngineView->setContextMenuPolicy(Qt::DefaultContextMenu);
        webEngineView->setUrl(QUrl(QStringLiteral("about:blank")));

        verticalLayout_4->addWidget(webEngineView);

        webfoot = new QWidget(page);
        webfoot->setObjectName(QStringLiteral("webfoot"));

        verticalLayout_4->addWidget(webfoot);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        verticalLayout_2 = new QVBoxLayout(page_2);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(page_2);
        label->setObjectName(QStringLiteral("label"));
        QFont font1;
        font1.setPointSize(14);
        label->setFont(font1);
        label->setStyleSheet(QStringLiteral(""));
        label->setLineWidth(0);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);

        listWidget = new QListWidget(page_2);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setFrameShape(QFrame::NoFrame);
        listWidget->setFrameShadow(QFrame::Sunken);
        listWidget->setLineWidth(0);

        verticalLayout_2->addWidget(listWidget);

        btn_openDir = new QPushButton(page_2);
        btn_openDir->setObjectName(QStringLiteral("btn_openDir"));
        btn_openDir->setMaximumSize(QSize(16777215, 30));
        btn_openDir->setFocusPolicy(Qt::NoFocus);

        verticalLayout_2->addWidget(btn_openDir);

        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        verticalLayout_16 = new QVBoxLayout(page_3);
        verticalLayout_16->setSpacing(0);
        verticalLayout_16->setObjectName(QStringLiteral("verticalLayout_16"));
        verticalLayout_16->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(page_3);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setStyleSheet(QStringLiteral(""));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setFrameShadow(QFrame::Raised);
        scrollArea->setLineWidth(0);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 903, 849));
        verticalLayout_17 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_17->setSpacing(0);
        verticalLayout_17->setObjectName(QStringLiteral("verticalLayout_17"));
        widget_3 = new QWidget(scrollAreaWidgetContents);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setMaximumSize(QSize(16777215, 350));
        widget_3->setAutoFillBackground(true);
        gridLayout = new QGridLayout(widget_3);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacer = new QSpacerItem(70, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 3, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(60, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 3, 2, 1, 1);

        pushButton_download = new QPushButton(widget_3);
        pushButton_download->setObjectName(QStringLiteral("pushButton_download"));

        gridLayout->addWidget(pushButton_download, 5, 1, 1, 1);

        label_appname = new QLabel(widget_3);
        label_appname->setObjectName(QStringLiteral("label_appname"));
        QFont font2;
        font2.setFamily(QStringLiteral("Bitstream Charter"));
        font2.setPointSize(22);
        label_appname->setFont(font2);

        gridLayout->addWidget(label_appname, 0, 3, 1, 2);

        label_info = new QLabel(widget_3);
        label_info->setObjectName(QStringLiteral("label_info"));
        QFont font3;
        font3.setKerning(true);
        label_info->setFont(font3);
        label_info->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_info->setWordWrap(true);

        gridLayout->addWidget(label_info, 3, 3, 5, 8);

        label_appicon = new QLabel(widget_3);
        label_appicon->setObjectName(QStringLiteral("label_appicon"));
        label_appicon->setMinimumSize(QSize(128, 128));
        label_appicon->setMaximumSize(QSize(128, 128));
        label_appicon->setStyleSheet(QStringLiteral("border-radius:10px;"));
        label_appicon->setScaledContents(true);
        label_appicon->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_appicon, 3, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 0, 10, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 7, 1, 2, 1);

        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_3, 4, 1, 1, 1);

        pushButton_uninstall = new QPushButton(widget_3);
        pushButton_uninstall->setObjectName(QStringLiteral("pushButton_uninstall"));

        gridLayout->addWidget(pushButton_uninstall, 6, 1, 1, 1);

        pushButton_website = new QPushButton(widget_3);
        pushButton_website->setObjectName(QStringLiteral("pushButton_website"));
        pushButton_website->setMaximumSize(QSize(70, 16777215));
        pushButton_website->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(pushButton_website, 0, 6, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_6, 2, 3, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_7, 0, 5, 1, 1);

        pushButton = new QPushButton(widget_3);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 0, 8, 1, 1);

        widget = new QWidget(widget_3);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(0, 30));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        tag_community = new QLabel(widget);
        tag_community->setObjectName(QStringLiteral("tag_community"));
        tag_community->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_2->addWidget(tag_community);

        tag_ubuntu = new QLabel(widget);
        tag_ubuntu->setObjectName(QStringLiteral("tag_ubuntu"));
        tag_ubuntu->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_2->addWidget(tag_ubuntu);

        tag_deepin = new QLabel(widget);
        tag_deepin->setObjectName(QStringLiteral("tag_deepin"));
        tag_deepin->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_2->addWidget(tag_deepin);

        tag_uos = new QLabel(widget);
        tag_uos->setObjectName(QStringLiteral("tag_uos"));
        tag_uos->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_2->addWidget(tag_uos);

        tag_dtk5 = new QLabel(widget);
        tag_dtk5->setObjectName(QStringLiteral("tag_dtk5"));
        tag_dtk5->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_2->addWidget(tag_dtk5);

        tag_dwine2 = new QLabel(widget);
        tag_dwine2->setObjectName(QStringLiteral("tag_dwine2"));
        tag_dwine2->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_2->addWidget(tag_dwine2);

        tag_dwine5 = new QLabel(widget);
        tag_dwine5->setObjectName(QStringLiteral("tag_dwine5"));
        tag_dwine5->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_2->addWidget(tag_dwine5);

        tag_a2d = new QLabel(widget);
        tag_a2d->setObjectName(QStringLiteral("tag_a2d"));
        tag_a2d->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_2->addWidget(tag_a2d);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_10);


        gridLayout->addWidget(widget, 1, 3, 1, 8);

        pushButton_translate = new QPushButton(widget_3);
        pushButton_translate->setObjectName(QStringLiteral("pushButton_translate"));

        gridLayout->addWidget(pushButton_translate, 0, 9, 1, 1);


        verticalLayout_17->addWidget(widget_3);

        widget_5 = new QWidget(scrollAreaWidgetContents);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        verticalLayout_19 = new QVBoxLayout(widget_5);
        verticalLayout_19->setObjectName(QStringLiteral("verticalLayout_19"));
        label_10 = new QLabel(widget_5);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font1);

        verticalLayout_19->addWidget(label_10);

        label_more = new QLabel(widget_5);
        label_more->setObjectName(QStringLiteral("label_more"));
        label_more->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_more->setWordWrap(true);

        verticalLayout_19->addWidget(label_more);


        verticalLayout_17->addWidget(widget_5);

        widget_4 = new QWidget(scrollAreaWidgetContents);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setMinimumSize(QSize(0, 370));
        widget_4->setMaximumSize(QSize(16777215, 370));
        verticalLayout_18 = new QVBoxLayout(widget_4);
        verticalLayout_18->setObjectName(QStringLiteral("verticalLayout_18"));
        verticalLayout_18->setContentsMargins(-1, -1, -1, 0);
        label_9 = new QLabel(widget_4);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font1);

        verticalLayout_18->addWidget(label_9);

        scrollArea_appicture = new QScrollArea(widget_4);
        scrollArea_appicture->setObjectName(QStringLiteral("scrollArea_appicture"));
        scrollArea_appicture->setLineWidth(0);
        scrollArea_appicture->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 869, 325));
        horizontalLayout_4 = new QHBoxLayout(scrollAreaWidgetContents_2);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        screen_0 = new image_show(scrollAreaWidgetContents_2);
        screen_0->setObjectName(QStringLiteral("screen_0"));
        screen_0->setMinimumSize(QSize(0, 0));
        screen_0->setMaximumSize(QSize(400, 16777215));

        horizontalLayout_4->addWidget(screen_0);

        screen_1 = new image_show(scrollAreaWidgetContents_2);
        screen_1->setObjectName(QStringLiteral("screen_1"));
        screen_1->setMaximumSize(QSize(400, 16777215));

        horizontalLayout_4->addWidget(screen_1);

        screen_2 = new image_show(scrollAreaWidgetContents_2);
        screen_2->setObjectName(QStringLiteral("screen_2"));
        screen_2->setMaximumSize(QSize(400, 16777215));

        horizontalLayout_4->addWidget(screen_2);

        screen_3 = new image_show(scrollAreaWidgetContents_2);
        screen_3->setObjectName(QStringLiteral("screen_3"));
        screen_3->setMaximumSize(QSize(400, 16777215));

        horizontalLayout_4->addWidget(screen_3);

        screen_4 = new image_show(scrollAreaWidgetContents_2);
        screen_4->setObjectName(QStringLiteral("screen_4"));
        screen_4->setMaximumSize(QSize(400, 16777215));

        horizontalLayout_4->addWidget(screen_4);

        scrollArea_appicture->setWidget(scrollAreaWidgetContents_2);

        verticalLayout_18->addWidget(scrollArea_appicture);


        verticalLayout_17->addWidget(widget_4);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_17->addItem(verticalSpacer_5);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_16->addWidget(scrollArea);

        label_show = new QLabel(page_3);
        label_show->setObjectName(QStringLiteral("label_show"));
        label_show->setAlignment(Qt::AlignCenter);

        verticalLayout_16->addWidget(label_show);

        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        verticalLayout = new QVBoxLayout(page_4);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea_2 = new QScrollArea(page_4);
        scrollArea_2->setObjectName(QStringLiteral("scrollArea_2"));
        scrollArea_2->setStyleSheet(QStringLiteral(""));
        scrollArea_2->setFrameShape(QFrame::NoFrame);
        scrollArea_2->setLineWidth(0);
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QStringLiteral("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 738, 896));
        verticalLayout_23 = new QVBoxLayout(scrollAreaWidgetContents_3);
        verticalLayout_23->setObjectName(QStringLiteral("verticalLayout_23"));
        widget_6 = new QWidget(scrollAreaWidgetContents_3);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        verticalLayout_22 = new QVBoxLayout(widget_6);
        verticalLayout_22->setObjectName(QStringLiteral("verticalLayout_22"));
        label_2 = new QLabel(widget_6);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font4;
        font4.setPointSize(18);
        label_2->setFont(font4);

        verticalLayout_22->addWidget(label_2);

        widget_7 = new QWidget(widget_6);
        widget_7->setObjectName(QStringLiteral("widget_7"));
        horizontalLayout = new QHBoxLayout(widget_7);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_3 = new QLabel(widget_7);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMaximumSize(QSize(100, 16777215));

        horizontalLayout->addWidget(label_3);

        comboBox_server = new QComboBox(widget_7);
        comboBox_server->setObjectName(QStringLiteral("comboBox_server"));
        comboBox_server->setMinimumSize(QSize(300, 0));
        comboBox_server->setMaximumSize(QSize(300, 16777215));

        horizontalLayout->addWidget(comboBox_server);

        pushButton_updateServer = new QPushButton(widget_7);
        pushButton_updateServer->setObjectName(QStringLiteral("pushButton_updateServer"));

        horizontalLayout->addWidget(pushButton_updateServer);

        label_setting1 = new QLabel(widget_7);
        label_setting1->setObjectName(QStringLiteral("label_setting1"));
        label_setting1->setMaximumSize(QSize(160, 16777215));

        horizontalLayout->addWidget(label_setting1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout_22->addWidget(widget_7);

        widget_8 = new QWidget(widget_6);
        widget_8->setObjectName(QStringLiteral("widget_8"));
        gridLayout_3 = new QGridLayout(widget_8);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_7 = new QLabel(widget_8);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setStyleSheet(QStringLiteral("color:#808080"));
        label_7->setWordWrap(true);

        gridLayout_3->addWidget(label_7, 1, 0, 1, 4);

        pushButton_updateApt = new QPushButton(widget_8);
        pushButton_updateApt->setObjectName(QStringLiteral("pushButton_updateApt"));

        gridLayout_3->addWidget(pushButton_updateApt, 0, 2, 1, 1);

        label_6 = new QLabel(widget_8);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_3->addWidget(label_6, 0, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_4, 0, 3, 1, 1);

        label_aptserver = new QLabel(widget_8);
        label_aptserver->setObjectName(QStringLiteral("label_aptserver"));

        gridLayout_3->addWidget(label_aptserver, 0, 1, 1, 1);


        verticalLayout_22->addWidget(widget_8);


        verticalLayout_23->addWidget(widget_6);

        widget_9 = new QWidget(scrollAreaWidgetContents_3);
        widget_9->setObjectName(QStringLiteral("widget_9"));
        verticalLayout_26 = new QVBoxLayout(widget_9);
        verticalLayout_26->setObjectName(QStringLiteral("verticalLayout_26"));
        label_8 = new QLabel(widget_9);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font4);

        verticalLayout_26->addWidget(label_8);

        widget_10 = new QWidget(widget_9);
        widget_10->setObjectName(QStringLiteral("widget_10"));
        gridLayout_4 = new QGridLayout(widget_10);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_5, 0, 3, 1, 1);

        pushButton_clear = new QPushButton(widget_10);
        pushButton_clear->setObjectName(QStringLiteral("pushButton_clear"));

        gridLayout_4->addWidget(pushButton_clear, 0, 2, 1, 1);

        label_12 = new QLabel(widget_10);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setStyleSheet(QStringLiteral("color:#808080"));

        gridLayout_4->addWidget(label_12, 2, 0, 1, 4);

        label_13 = new QLabel(widget_10);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setMaximumSize(QSize(80, 16777215));

        gridLayout_4->addWidget(label_13, 1, 0, 1, 1);

        tmp_size_ui = new QLabel(widget_10);
        tmp_size_ui->setObjectName(QStringLiteral("tmp_size_ui"));

        gridLayout_4->addWidget(tmp_size_ui, 1, 1, 1, 1);

        label_11 = new QLabel(widget_10);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_4->addWidget(label_11, 0, 0, 1, 2);


        verticalLayout_26->addWidget(widget_10);


        verticalLayout_23->addWidget(widget_9);

        widget_2 = new QWidget(scrollAreaWidgetContents_3);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        verticalLayout_25 = new QVBoxLayout(widget_2);
        verticalLayout_25->setObjectName(QStringLiteral("verticalLayout_25"));
        label_4 = new QLabel(widget_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font4);

        verticalLayout_25->addWidget(label_4);

        label_5 = new QLabel(widget_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setWordWrap(true);

        verticalLayout_25->addWidget(label_5);


        verticalLayout_23->addWidget(widget_2);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_23->addItem(verticalSpacer_4);

        scrollArea_2->setWidget(scrollAreaWidgetContents_3);

        verticalLayout->addWidget(scrollArea_2);

        stackedWidget->addWidget(page_4);

        gridLayout_2->addWidget(stackedWidget, 2, 1, 1, 1);

        titlebar = new DTitlebar(Widget);
        titlebar->setObjectName(QStringLiteral("titlebar"));
        titlebar->setMinimumSize(QSize(0, 20));

        gridLayout_2->addWidget(titlebar, 0, 1, 1, 1);

        progressload = new ProgressLoad(Widget);
        progressload->setObjectName(QStringLiteral("progressload"));
        progressload->setMinimumSize(QSize(0, 3));
        progressload->setMaximumSize(QSize(16777215, 3));
        progressload->setToolTipDuration(-1);
        progressload->setStyleSheet(QStringLiteral(""));

        gridLayout_2->addWidget(progressload, 1, 1, 1, 1);


        retranslateUi(Widget);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Form", nullptr));
#ifndef QT_NO_ACCESSIBILITY
        widget_menuList->setAccessibleDescription(QApplication::translate("Widget", "background-color:#FFFFFF", nullptr));
#endif // QT_NO_ACCESSIBILITY
        menu_video->setText(QApplication::translate("Widget", "Videos", nullptr));
        menu_download->setText(QApplication::translate("Widget", "Download List", nullptr));
        menu_system->setText(QApplication::translate("Widget", "Tools", nullptr));
        menu_theme->setText(QApplication::translate("Widget", "Beautify", nullptr));
        menu_music->setText(QApplication::translate("Widget", "Music", nullptr));
        icon->setText(QApplication::translate("Widget", "icon", nullptr));
        menu_dev->setText(QApplication::translate("Widget", "Development", nullptr));
        menu_office->setText(QApplication::translate("Widget", "Office", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_return->setToolTip(QApplication::translate("Widget", "Back to category", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_return->setText(QString());
        menu_read->setText(QApplication::translate("Widget", "Translate", nullptr));
        menu_other->setText(QApplication::translate("Widget", "Others", nullptr));
        menu_main->setText(QApplication::translate("Widget", "Home  ", nullptr));
        menu_photo->setText(QApplication::translate("Widget", "Graphics", nullptr));
        menu_game->setText(QApplication::translate("Widget", "Games", nullptr));
        menu_chat->setText(QApplication::translate("Widget", "Communication", nullptr));
        menu_network->setText(QApplication::translate("Widget", "Network", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_refresh->setToolTip(QApplication::translate("Widget", "Reload", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_refresh->setText(QString());
        label->setText(QApplication::translate("Widget", "The list is currently empty. Go and download some softwares!", nullptr));
        btn_openDir->setText(QApplication::translate("Widget", "Open download directory", nullptr));
        pushButton_download->setText(QApplication::translate("Widget", "Install", nullptr));
        label_appname->setText(QApplication::translate("Widget", "Name", nullptr));
        label_info->setText(QApplication::translate("Widget", "<html><head/><body><p><br/></p></body></html>", nullptr));
        label_appicon->setText(QApplication::translate("Widget", "ICON", nullptr));
        pushButton_uninstall->setText(QApplication::translate("Widget", "Uninstall", nullptr));
        pushButton_website->setText(QApplication::translate("Widget", "Site", nullptr));
        pushButton->setText(QApplication::translate("Widget", "Share", nullptr));
#ifndef QT_NO_TOOLTIP
        tag_community->setToolTip(QApplication::translate("Widget", "<html><head/><body><p>This app is developed by community user,we give this tag to honor those who contribute to the Linux Ecology</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        tag_community->setWhatsThis(QApplication::translate("Widget", "<html><head/><body><p>This app is developed by community user,we give this tag to honor those who contribute to the Linux Ecology</p></body></html>", nullptr));
#endif // QT_NO_WHATSTHIS
        tag_community->setText(QApplication::translate("Widget", "<html><head/><body><p><img src=\":/tags/community-small.png\"/></p></body></html>", nullptr));
#ifndef QT_NO_TOOLTIP
        tag_ubuntu->setToolTip(QApplication::translate("Widget", "<html><head/><body><p>Capable to Ubuntu 20.04</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        tag_ubuntu->setWhatsThis(QApplication::translate("Widget", "<html><head/><body><p>Capable to Ubuntu 20.04</p></body></html>", nullptr));
#endif // QT_NO_WHATSTHIS
        tag_ubuntu->setText(QApplication::translate("Widget", "<html><head/><body><p><img src=\":/tags/ubuntu-small.png\"/></p></body></html>", nullptr));
#ifndef QT_NO_TOOLTIP
        tag_deepin->setToolTip(QApplication::translate("Widget", "<html><head/><body><p>Capable to deepin 20</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        tag_deepin->setWhatsThis(QApplication::translate("Widget", "<html><head/><body><p>Capable to deepin 20</p></body></html>", nullptr));
#endif // QT_NO_WHATSTHIS
        tag_deepin->setText(QApplication::translate("Widget", "<html><head/><body><p><img src=\":/tags/deepin-small.png\"/></p></body></html>", nullptr));
#ifndef QT_NO_TOOLTIP
        tag_uos->setToolTip(QApplication::translate("Widget", "<html><head/><body><p>Capable to UOS home 20</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        tag_uos->setWhatsThis(QApplication::translate("Widget", "<html><head/><body><p>Capable to UOS home 20</p></body></html>", nullptr));
#endif // QT_NO_WHATSTHIS
        tag_uos->setText(QApplication::translate("Widget", "<html><head/><body><p><img src=\":/tags/uos-small.png\"/></p></body></html>", nullptr));
#ifndef QT_NO_TOOLTIP
        tag_dtk5->setToolTip(QApplication::translate("Widget", "<html><head/><body><p>This is a  DTK5 app,which means it would have better effect on Deepin Desktop Environment</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        tag_dtk5->setWhatsThis(QApplication::translate("Widget", "<html><head/><body><p>This is a  DTK5 app,which means it would have better effect on Deepin Desktop Environment</p></body></html>", nullptr));
#endif // QT_NO_WHATSTHIS
        tag_dtk5->setText(QApplication::translate("Widget", "<html><head/><body><p><img src=\":/tags/dtk-small.png\"/></p></body></html>", nullptr));
#ifndef QT_NO_TOOLTIP
        tag_dwine2->setToolTip(QApplication::translate("Widget", "<html><head/><body><p>A deepin-wine2 app.If you are using ubuntu or other non-deepin distro,you should deploy deepin-wine2 by your self.</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        tag_dwine2->setWhatsThis(QApplication::translate("Widget", "<html><head/><body><p>A deepin-wine2 app.If you are using ubuntu or other non-deepin distro,you should deploy deepin-wine2 by your self.</p></body></html>", nullptr));
#endif // QT_NO_WHATSTHIS
        tag_dwine2->setText(QApplication::translate("Widget", "<html><head/><body><p><img src=\":/tags/dwine2-small.png\"/></p></body></html>", nullptr));
#ifndef QT_NO_TOOLTIP
        tag_dwine5->setToolTip(QApplication::translate("Widget", "<html><head/><body><p>A deepin-wine5 app.If you are using ubuntu or other non-deepin distro,you should deploy deepin-wine5 by your self.</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        tag_dwine5->setWhatsThis(QApplication::translate("Widget", "<html><head/><body><p>A deepin-wine5 app.If you are using ubuntu or other non-deepin distro,you should deploy deepin-wine5 by your self.</p></body></html>", nullptr));
#endif // QT_NO_WHATSTHIS
        tag_dwine5->setText(QApplication::translate("Widget", "<html><head/><body><p><img src=\":/tags/dwine5-small.png\"/></p></body></html>", nullptr));
#ifndef QT_NO_TOOLTIP
        tag_a2d->setToolTip(QApplication::translate("Widget", "<html><head/><body><p>An Appimage to deb app.</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        tag_a2d->setWhatsThis(QApplication::translate("Widget", "<html><head/><body><p>An Appimage to deb app.</p></body></html>", nullptr));
#endif // QT_NO_WHATSTHIS
        tag_a2d->setText(QApplication::translate("Widget", "<html><head/><body><p><img src=\":/tags/a2d-small.png\"/></p></body></html>", nullptr));
        pushButton_translate->setText(QApplication::translate("Widget", "Contribute translation", nullptr));
        label_10->setText(QApplication::translate("Widget", "Info", nullptr));
        label_more->setText(QApplication::translate("Widget", "<html><head/><body><p>An app store developed by community enthusiasts</p></body></html>", nullptr));
        label_9->setText(QApplication::translate("Widget", "Screenshots", nullptr));
        label_show->setText(QString());
        label_2->setText(QApplication::translate("Widget", "Line Settings", nullptr));
        label_3->setText(QApplication::translate("Widget", "Choose Line:", nullptr));
        pushButton_updateServer->setText(QApplication::translate("Widget", "Refresh", nullptr));
        label_setting1->setText(QApplication::translate("Widget", "Take effect when restart ", nullptr));
        label_7->setText(QApplication::translate("Widget", "<html><head/><body><p>The role of the source server is to ensure that the software is updated, and supports the use of the apt tool to get the software. We usually prefer that you use the first line as the update source, which is generally the most stable. </p></body></html>", nullptr));
        pushButton_updateApt->setText(QApplication::translate("Widget", "Update", nullptr));
        label_6->setText(QApplication::translate("Widget", "Source Server", nullptr));
        label_aptserver->setText(QApplication::translate("Widget", "Server", nullptr));
        label_8->setText(QApplication::translate("Widget", "Temp", nullptr));
        pushButton_clear->setText(QApplication::translate("Widget", "Clean", nullptr));
        label_12->setText(QApplication::translate("Widget", "Since the dictionary is at /tmp,It would be cleaned automatically when  system reboot.", nullptr));
        label_13->setText(QApplication::translate("Widget", "Size:", nullptr));
        tmp_size_ui->setText(QApplication::translate("Widget", "0B", nullptr));
        label_11->setText(QApplication::translate("Widget", "Location\357\274\232/tmp/spark-store", nullptr));
        label_4->setText(QApplication::translate("Widget", "About us", nullptr));
        label_5->setText(QApplication::translate("Widget", "<html><head/><body><p>We are <span style=\" font-weight:600;\">NOT</span> the official team, just like you, we are just one of the many Linux/deepin system enthusiasts and users, we develop and run the &quot;Spark Store&quot;! &quot;, is to bring the community together to share useful software, or to participate in development together, so that we all use the latest and greatest software. </p><p>We don't make a profit from this, all developers and maintainers don't get paid, and we rely on the community's donations to us for most of our expenses, which we are grateful for and which allow us not to spend too much energy worrying about funding. </p><p>Our service and software are free for everyone to use, communicate, and learn, but you must comply with local laws and regulations in the process of your use, otherwise any problems have nothing to do with us. </p><p>If any part of the store infringes your rights, please tell us &lt;jifengshenmo@outlook.com&gt; we will remove the infringing content as soon as possi"
                        "ble. </p><p>If you'd like to get involved with us too, whether you're involved in development, design, pitching or submitting work, we welcome you to join us. </p><p>QQ group:872690351<br/></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
