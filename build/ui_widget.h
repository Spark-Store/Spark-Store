/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWebKitWidgets/QWebView>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout_2;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_4;
    QWebView *webView;
    QWidget *page_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QListWidget *listWidget;
    QWidget *page_3;
    QVBoxLayout *verticalLayout_16;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_17;
    QWidget *widget_3;
    QGridLayout *gridLayout;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_appname;
    QLabel *label_appicon;
    QLabel *label_info;
    QSpacerItem *verticalSpacer_3;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_18;
    QLabel *label_9;
    QScrollArea *scrollArea_appicture;
    QWidget *scrollAreaWidgetContents_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *screen_1;
    QLabel *screen_2;
    QLabel *screen_3;
    QLabel *screen_4;
    QLabel *screen_5;
    QWidget *widget_5;
    QVBoxLayout *verticalLayout_19;
    QLabel *label_10;
    QLabel *label_more;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QWidget *menu_bg_main;
    QVBoxLayout *verticalLayout_2;
    QToolButton *menu_btn_main;
    QWidget *menu_bg_network;
    QVBoxLayout *verticalLayout_3;
    QToolButton *menu_btn_network;
    QWidget *menu_bg_chat;
    QVBoxLayout *verticalLayout_6;
    QToolButton *menu_btn_chat;
    QWidget *menu_bg_music;
    QVBoxLayout *verticalLayout_7;
    QToolButton *menu_btn_music;
    QWidget *menu_bg_video;
    QVBoxLayout *verticalLayout_8;
    QToolButton *menu_btn_video;
    QWidget *menu_bg_photo;
    QVBoxLayout *verticalLayout_9;
    QToolButton *menu_btn_photo;
    QWidget *menu_bg_game;
    QVBoxLayout *verticalLayout_10;
    QToolButton *menu_btn_game;
    QWidget *menu_bg_office;
    QVBoxLayout *verticalLayout_11;
    QToolButton *menu_btn_office;
    QWidget *menu_bg_read;
    QVBoxLayout *verticalLayout_12;
    QToolButton *menu_btn_read;
    QWidget *menu_bg_dev;
    QVBoxLayout *verticalLayout_13;
    QToolButton *menu_btn_dev;
    QWidget *menu_bg_system;
    QVBoxLayout *verticalLayout_14;
    QToolButton *menu_btn_system;
    QWidget *menu_bg_theme;
    QVBoxLayout *verticalLayout_20;
    QToolButton *menu_btn_theme;
    QWidget *menu_bg_other;
    QVBoxLayout *verticalLayout_15;
    QToolButton *menu_btn_other;
    QWidget *widget_2;
    QWidget *menu_bg_download;
    QVBoxLayout *verticalLayout_5;
    QToolButton *menu_btn_download;
    QSpacerItem *verticalSpacer;
    QLabel *label_show;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(943, 640);
        gridLayout_2 = new QGridLayout(Widget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(Widget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setStyleSheet(QStringLiteral(""));
        stackedWidget->setLineWidth(0);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        verticalLayout_4 = new QVBoxLayout(page);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        webView = new QWebView(page);
        webView->setObjectName(QStringLiteral("webView"));
        webView->setUrl(QUrl(QStringLiteral("https://bbs.deepin.org/")));

        verticalLayout_4->addWidget(webView);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        horizontalLayout_2 = new QHBoxLayout(page_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(page_2);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("background-color:#FFFFFF"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label);

        listWidget = new QListWidget(page_2);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setLineWidth(0);

        horizontalLayout_2->addWidget(listWidget);

        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        verticalLayout_16 = new QVBoxLayout(page_3);
        verticalLayout_16->setObjectName(QStringLiteral("verticalLayout_16"));
        verticalLayout_16->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(page_3);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setStyleSheet(QStringLiteral("c"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 786, 945));
        verticalLayout_17 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_17->setObjectName(QStringLiteral("verticalLayout_17"));
        widget_3 = new QWidget(scrollAreaWidgetContents);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setMaximumSize(QSize(16777215, 300));
        gridLayout = new QGridLayout(widget_3);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton_2 = new QPushButton(widget_3);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMaximumSize(QSize(40, 16777215));

        gridLayout->addWidget(pushButton_2, 0, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(60, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(70, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        pushButton = new QPushButton(widget_3);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 3, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 4, 1, 2, 1);

        label_appname = new QLabel(widget_3);
        label_appname->setObjectName(QStringLiteral("label_appname"));
        QFont font1;
        font1.setFamily(QStringLiteral("Bitstream Charter"));
        font1.setPointSize(22);
        label_appname->setFont(font1);

        gridLayout->addWidget(label_appname, 0, 3, 1, 1);

        label_appicon = new QLabel(widget_3);
        label_appicon->setObjectName(QStringLiteral("label_appicon"));
        label_appicon->setMinimumSize(QSize(128, 128));
        label_appicon->setMaximumSize(QSize(128, 128));
        label_appicon->setStyleSheet(QStringLiteral("border-radius:10px;"));
        label_appicon->setScaledContents(true);
        label_appicon->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_appicon, 1, 1, 1, 1);

        label_info = new QLabel(widget_3);
        label_info->setObjectName(QStringLiteral("label_info"));
        label_info->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_info->setWordWrap(true);

        gridLayout->addWidget(label_info, 1, 3, 4, 1);

        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_3, 2, 1, 1, 1);


        verticalLayout_17->addWidget(widget_3);

        widget_4 = new QWidget(scrollAreaWidgetContents);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setMinimumSize(QSize(0, 370));
        widget_4->setMaximumSize(QSize(16777215, 370));
        verticalLayout_18 = new QVBoxLayout(widget_4);
        verticalLayout_18->setObjectName(QStringLiteral("verticalLayout_18"));
        verticalLayout_18->setContentsMargins(-1, -1, -1, 0);
        label_9 = new QLabel(widget_4);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font);

        verticalLayout_18->addWidget(label_9);

        scrollArea_appicture = new QScrollArea(widget_4);
        scrollArea_appicture->setObjectName(QStringLiteral("scrollArea_appicture"));
        scrollArea_appicture->setLineWidth(0);
        scrollArea_appicture->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 752, 325));
        horizontalLayout_4 = new QHBoxLayout(scrollAreaWidgetContents_2);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        screen_1 = new QLabel(scrollAreaWidgetContents_2);
        screen_1->setObjectName(QStringLiteral("screen_1"));
        screen_1->setMinimumSize(QSize(0, 0));
        screen_1->setMaximumSize(QSize(400, 300));

        horizontalLayout_4->addWidget(screen_1);

        screen_2 = new QLabel(scrollAreaWidgetContents_2);
        screen_2->setObjectName(QStringLiteral("screen_2"));
        screen_2->setMinimumSize(QSize(0, 0));
        screen_2->setMaximumSize(QSize(400, 300));

        horizontalLayout_4->addWidget(screen_2);

        screen_3 = new QLabel(scrollAreaWidgetContents_2);
        screen_3->setObjectName(QStringLiteral("screen_3"));
        screen_3->setMinimumSize(QSize(0, 0));
        screen_3->setMaximumSize(QSize(400, 300));

        horizontalLayout_4->addWidget(screen_3);

        screen_4 = new QLabel(scrollAreaWidgetContents_2);
        screen_4->setObjectName(QStringLiteral("screen_4"));
        screen_4->setMinimumSize(QSize(0, 0));
        screen_4->setMaximumSize(QSize(400, 300));

        horizontalLayout_4->addWidget(screen_4);

        screen_5 = new QLabel(scrollAreaWidgetContents_2);
        screen_5->setObjectName(QStringLiteral("screen_5"));
        screen_5->setMinimumSize(QSize(0, 0));
        screen_5->setMaximumSize(QSize(400, 300));

        horizontalLayout_4->addWidget(screen_5);

        scrollArea_appicture->setWidget(scrollAreaWidgetContents_2);

        verticalLayout_18->addWidget(scrollArea_appicture);


        verticalLayout_17->addWidget(widget_4);

        widget_5 = new QWidget(scrollAreaWidgetContents);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        verticalLayout_19 = new QVBoxLayout(widget_5);
        verticalLayout_19->setObjectName(QStringLiteral("verticalLayout_19"));
        label_10 = new QLabel(widget_5);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font);

        verticalLayout_19->addWidget(label_10);

        label_more = new QLabel(widget_5);
        label_more->setObjectName(QStringLiteral("label_more"));
        label_more->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_more->setWordWrap(true);

        verticalLayout_19->addWidget(label_more);


        verticalLayout_17->addWidget(widget_5);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_16->addWidget(scrollArea);

        stackedWidget->addWidget(page_3);

        gridLayout_2->addWidget(stackedWidget, 0, 1, 1, 1);

        widget = new QWidget(Widget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(150, 0));
        widget->setMaximumSize(QSize(150, 16777215));
        QFont font2;
        font2.setPointSize(11);
        widget->setFont(font2);
        widget->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        menu_bg_main = new QWidget(widget);
        menu_bg_main->setObjectName(QStringLiteral("menu_bg_main"));
        menu_bg_main->setMinimumSize(QSize(0, 30));
        menu_bg_main->setMaximumSize(QSize(16777215, 30));
        menu_bg_main->setStyleSheet(QStringLiteral("background-color:#0081FF;border-radius:8"));
        verticalLayout_2 = new QVBoxLayout(menu_bg_main);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        menu_btn_main = new QToolButton(menu_bg_main);
        menu_btn_main->setObjectName(QStringLiteral("menu_btn_main"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(menu_btn_main->sizePolicy().hasHeightForWidth());
        menu_btn_main->setSizePolicy(sizePolicy);
        menu_btn_main->setStyleSheet(QStringLiteral("color:#FFFFFF"));

        verticalLayout_2->addWidget(menu_btn_main);


        verticalLayout->addWidget(menu_bg_main);

        menu_bg_network = new QWidget(widget);
        menu_bg_network->setObjectName(QStringLiteral("menu_bg_network"));
        menu_bg_network->setMinimumSize(QSize(0, 30));
        menu_bg_network->setMaximumSize(QSize(16777215, 30));
        verticalLayout_3 = new QVBoxLayout(menu_bg_network);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        menu_btn_network = new QToolButton(menu_bg_network);
        menu_btn_network->setObjectName(QStringLiteral("menu_btn_network"));
        sizePolicy.setHeightForWidth(menu_btn_network->sizePolicy().hasHeightForWidth());
        menu_btn_network->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(menu_btn_network);


        verticalLayout->addWidget(menu_bg_network);

        menu_bg_chat = new QWidget(widget);
        menu_bg_chat->setObjectName(QStringLiteral("menu_bg_chat"));
        menu_bg_chat->setMinimumSize(QSize(0, 30));
        menu_bg_chat->setMaximumSize(QSize(16777215, 30));
        verticalLayout_6 = new QVBoxLayout(menu_bg_chat);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        menu_btn_chat = new QToolButton(menu_bg_chat);
        menu_btn_chat->setObjectName(QStringLiteral("menu_btn_chat"));
        sizePolicy.setHeightForWidth(menu_btn_chat->sizePolicy().hasHeightForWidth());
        menu_btn_chat->setSizePolicy(sizePolicy);

        verticalLayout_6->addWidget(menu_btn_chat);


        verticalLayout->addWidget(menu_bg_chat);

        menu_bg_music = new QWidget(widget);
        menu_bg_music->setObjectName(QStringLiteral("menu_bg_music"));
        menu_bg_music->setMinimumSize(QSize(0, 30));
        menu_bg_music->setMaximumSize(QSize(16777215, 30));
        verticalLayout_7 = new QVBoxLayout(menu_bg_music);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        menu_btn_music = new QToolButton(menu_bg_music);
        menu_btn_music->setObjectName(QStringLiteral("menu_btn_music"));
        sizePolicy.setHeightForWidth(menu_btn_music->sizePolicy().hasHeightForWidth());
        menu_btn_music->setSizePolicy(sizePolicy);

        verticalLayout_7->addWidget(menu_btn_music);


        verticalLayout->addWidget(menu_bg_music);

        menu_bg_video = new QWidget(widget);
        menu_bg_video->setObjectName(QStringLiteral("menu_bg_video"));
        menu_bg_video->setMinimumSize(QSize(0, 30));
        menu_bg_video->setMaximumSize(QSize(16777215, 30));
        verticalLayout_8 = new QVBoxLayout(menu_bg_video);
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        menu_btn_video = new QToolButton(menu_bg_video);
        menu_btn_video->setObjectName(QStringLiteral("menu_btn_video"));
        sizePolicy.setHeightForWidth(menu_btn_video->sizePolicy().hasHeightForWidth());
        menu_btn_video->setSizePolicy(sizePolicy);

        verticalLayout_8->addWidget(menu_btn_video);


        verticalLayout->addWidget(menu_bg_video);

        menu_bg_photo = new QWidget(widget);
        menu_bg_photo->setObjectName(QStringLiteral("menu_bg_photo"));
        menu_bg_photo->setMinimumSize(QSize(0, 30));
        menu_bg_photo->setMaximumSize(QSize(16777215, 30));
        verticalLayout_9 = new QVBoxLayout(menu_bg_photo);
        verticalLayout_9->setSpacing(0);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        menu_btn_photo = new QToolButton(menu_bg_photo);
        menu_btn_photo->setObjectName(QStringLiteral("menu_btn_photo"));
        sizePolicy.setHeightForWidth(menu_btn_photo->sizePolicy().hasHeightForWidth());
        menu_btn_photo->setSizePolicy(sizePolicy);

        verticalLayout_9->addWidget(menu_btn_photo);


        verticalLayout->addWidget(menu_bg_photo);

        menu_bg_game = new QWidget(widget);
        menu_bg_game->setObjectName(QStringLiteral("menu_bg_game"));
        menu_bg_game->setMinimumSize(QSize(0, 30));
        menu_bg_game->setMaximumSize(QSize(16777215, 30));
        verticalLayout_10 = new QVBoxLayout(menu_bg_game);
        verticalLayout_10->setSpacing(0);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        menu_btn_game = new QToolButton(menu_bg_game);
        menu_btn_game->setObjectName(QStringLiteral("menu_btn_game"));
        sizePolicy.setHeightForWidth(menu_btn_game->sizePolicy().hasHeightForWidth());
        menu_btn_game->setSizePolicy(sizePolicy);

        verticalLayout_10->addWidget(menu_btn_game);


        verticalLayout->addWidget(menu_bg_game);

        menu_bg_office = new QWidget(widget);
        menu_bg_office->setObjectName(QStringLiteral("menu_bg_office"));
        menu_bg_office->setMinimumSize(QSize(0, 30));
        menu_bg_office->setMaximumSize(QSize(16777215, 30));
        verticalLayout_11 = new QVBoxLayout(menu_bg_office);
        verticalLayout_11->setSpacing(0);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        verticalLayout_11->setContentsMargins(0, 0, 0, 0);
        menu_btn_office = new QToolButton(menu_bg_office);
        menu_btn_office->setObjectName(QStringLiteral("menu_btn_office"));
        sizePolicy.setHeightForWidth(menu_btn_office->sizePolicy().hasHeightForWidth());
        menu_btn_office->setSizePolicy(sizePolicy);

        verticalLayout_11->addWidget(menu_btn_office);


        verticalLayout->addWidget(menu_bg_office);

        menu_bg_read = new QWidget(widget);
        menu_bg_read->setObjectName(QStringLiteral("menu_bg_read"));
        menu_bg_read->setMinimumSize(QSize(0, 30));
        menu_bg_read->setMaximumSize(QSize(16777215, 30));
        verticalLayout_12 = new QVBoxLayout(menu_bg_read);
        verticalLayout_12->setSpacing(0);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        verticalLayout_12->setContentsMargins(0, 0, 0, 0);
        menu_btn_read = new QToolButton(menu_bg_read);
        menu_btn_read->setObjectName(QStringLiteral("menu_btn_read"));
        sizePolicy.setHeightForWidth(menu_btn_read->sizePolicy().hasHeightForWidth());
        menu_btn_read->setSizePolicy(sizePolicy);

        verticalLayout_12->addWidget(menu_btn_read);


        verticalLayout->addWidget(menu_bg_read);

        menu_bg_dev = new QWidget(widget);
        menu_bg_dev->setObjectName(QStringLiteral("menu_bg_dev"));
        menu_bg_dev->setMinimumSize(QSize(0, 30));
        menu_bg_dev->setMaximumSize(QSize(16777215, 30));
        verticalLayout_13 = new QVBoxLayout(menu_bg_dev);
        verticalLayout_13->setSpacing(0);
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        verticalLayout_13->setContentsMargins(0, 0, 0, 0);
        menu_btn_dev = new QToolButton(menu_bg_dev);
        menu_btn_dev->setObjectName(QStringLiteral("menu_btn_dev"));
        sizePolicy.setHeightForWidth(menu_btn_dev->sizePolicy().hasHeightForWidth());
        menu_btn_dev->setSizePolicy(sizePolicy);

        verticalLayout_13->addWidget(menu_btn_dev);


        verticalLayout->addWidget(menu_bg_dev);

        menu_bg_system = new QWidget(widget);
        menu_bg_system->setObjectName(QStringLiteral("menu_bg_system"));
        menu_bg_system->setMinimumSize(QSize(0, 30));
        menu_bg_system->setMaximumSize(QSize(16777215, 30));
        verticalLayout_14 = new QVBoxLayout(menu_bg_system);
        verticalLayout_14->setSpacing(0);
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        verticalLayout_14->setContentsMargins(0, 0, 0, 0);
        menu_btn_system = new QToolButton(menu_bg_system);
        menu_btn_system->setObjectName(QStringLiteral("menu_btn_system"));
        sizePolicy.setHeightForWidth(menu_btn_system->sizePolicy().hasHeightForWidth());
        menu_btn_system->setSizePolicy(sizePolicy);

        verticalLayout_14->addWidget(menu_btn_system);


        verticalLayout->addWidget(menu_bg_system);

        menu_bg_theme = new QWidget(widget);
        menu_bg_theme->setObjectName(QStringLiteral("menu_bg_theme"));
        menu_bg_theme->setMinimumSize(QSize(0, 30));
        menu_bg_theme->setMaximumSize(QSize(16777215, 30));
        verticalLayout_20 = new QVBoxLayout(menu_bg_theme);
        verticalLayout_20->setSpacing(0);
        verticalLayout_20->setObjectName(QStringLiteral("verticalLayout_20"));
        verticalLayout_20->setContentsMargins(0, 0, 0, 0);
        menu_btn_theme = new QToolButton(menu_bg_theme);
        menu_btn_theme->setObjectName(QStringLiteral("menu_btn_theme"));
        sizePolicy.setHeightForWidth(menu_btn_theme->sizePolicy().hasHeightForWidth());
        menu_btn_theme->setSizePolicy(sizePolicy);

        verticalLayout_20->addWidget(menu_btn_theme);


        verticalLayout->addWidget(menu_bg_theme);

        menu_bg_other = new QWidget(widget);
        menu_bg_other->setObjectName(QStringLiteral("menu_bg_other"));
        menu_bg_other->setMinimumSize(QSize(0, 30));
        menu_bg_other->setMaximumSize(QSize(16777215, 30));
        verticalLayout_15 = new QVBoxLayout(menu_bg_other);
        verticalLayout_15->setSpacing(0);
        verticalLayout_15->setObjectName(QStringLiteral("verticalLayout_15"));
        verticalLayout_15->setContentsMargins(0, 0, 0, 0);
        menu_btn_other = new QToolButton(menu_bg_other);
        menu_btn_other->setObjectName(QStringLiteral("menu_btn_other"));
        sizePolicy.setHeightForWidth(menu_btn_other->sizePolicy().hasHeightForWidth());
        menu_btn_other->setSizePolicy(sizePolicy);

        verticalLayout_15->addWidget(menu_btn_other);


        verticalLayout->addWidget(menu_bg_other);

        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMinimumSize(QSize(0, 1));
        widget_2->setMaximumSize(QSize(16777215, 1));
        widget_2->setStyleSheet(QStringLiteral("background-color:#E0E0E1"));

        verticalLayout->addWidget(widget_2);

        menu_bg_download = new QWidget(widget);
        menu_bg_download->setObjectName(QStringLiteral("menu_bg_download"));
        menu_bg_download->setMinimumSize(QSize(0, 30));
        menu_bg_download->setMaximumSize(QSize(16777215, 30));
        verticalLayout_5 = new QVBoxLayout(menu_bg_download);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        menu_btn_download = new QToolButton(menu_bg_download);
        menu_btn_download->setObjectName(QStringLiteral("menu_btn_download"));
        sizePolicy.setHeightForWidth(menu_btn_download->sizePolicy().hasHeightForWidth());
        menu_btn_download->setSizePolicy(sizePolicy);

        verticalLayout_5->addWidget(menu_btn_download);


        verticalLayout->addWidget(menu_bg_download);

        verticalSpacer = new QSpacerItem(20, 219, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout_2->addWidget(widget, 0, 0, 2, 1);

        label_show = new QLabel(Widget);
        label_show->setObjectName(QStringLiteral("label_show"));
        label_show->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_show, 1, 1, 1, 1);


        retranslateUi(Widget);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("Widget", "\345\275\223\345\211\215\344\270\213\350\275\275\345\210\227\350\241\250\344\270\272\347\251\272", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Widget", "<", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Widget", "\345\256\211\350\243\205", Q_NULLPTR));
        label_appname->setText(QApplication::translate("Widget", "\350\275\257\344\273\266\345\220\215", Q_NULLPTR));
        label_appicon->setText(QApplication::translate("Widget", "\345\233\276\346\240\207", Q_NULLPTR));
        label_info->setText(QApplication::translate("Widget", "<html><head/><body><p><br/></p></body></html>", Q_NULLPTR));
        label_9->setText(QApplication::translate("Widget", "\350\275\257\344\273\266\346\210\252\345\233\276", Q_NULLPTR));
        screen_1->setText(QApplication::translate("Widget", "TextLabel", Q_NULLPTR));
        screen_2->setText(QApplication::translate("Widget", "TextLabel", Q_NULLPTR));
        screen_3->setText(QApplication::translate("Widget", "TextLabel", Q_NULLPTR));
        screen_4->setText(QApplication::translate("Widget", "TextLabel", Q_NULLPTR));
        screen_5->setText(QApplication::translate("Widget", "TextLabel", Q_NULLPTR));
        label_10->setText(QApplication::translate("Widget", "\350\257\246\347\273\206\344\273\213\347\273\215", Q_NULLPTR));
        label_more->setText(QApplication::translate("Widget", "<html><head/><body><p>\350\257\246\347\273\206\344\273\213\347\273\215</p><p>\347\224\261\347\244\276\345\214\272\347\210\261\345\245\275\350\200\205\345\274\200\345\217\221\347\232\204\350\275\257\344\273\266\345\225\206\345\272\227</p><p>1212121</p><p>12121212</p><p>121212</p><p>121212</p></body></html>", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        widget->setAccessibleDescription(QApplication::translate("Widget", "background-color:#FFFFFF", Q_NULLPTR));
#endif // QT_NO_ACCESSIBILITY
        menu_btn_main->setText(QApplication::translate("Widget", "\351\246\226\351\241\265\347\262\276\351\200\211", Q_NULLPTR));
        menu_btn_network->setText(QApplication::translate("Widget", "\347\275\221\347\273\234\345\272\224\347\224\250", Q_NULLPTR));
        menu_btn_chat->setText(QApplication::translate("Widget", "\347\244\276\344\272\244\346\262\237\351\200\232", Q_NULLPTR));
        menu_btn_music->setText(QApplication::translate("Widget", "\351\237\263\344\271\220\346\254\243\350\265\217", Q_NULLPTR));
        menu_btn_video->setText(QApplication::translate("Widget", "\350\247\206\351\242\221\346\222\255\346\224\276", Q_NULLPTR));
        menu_btn_photo->setText(QApplication::translate("Widget", "\345\233\276\345\275\242\345\233\276\345\203\217", Q_NULLPTR));
        menu_btn_game->setText(QApplication::translate("Widget", "\346\270\270\346\210\217\345\250\261\344\271\220", Q_NULLPTR));
        menu_btn_office->setText(QApplication::translate("Widget", "\345\212\236\345\205\254\345\255\246\344\271\240", Q_NULLPTR));
        menu_btn_read->setText(QApplication::translate("Widget", "\351\230\205\350\257\273\347\277\273\350\257\221", Q_NULLPTR));
        menu_btn_dev->setText(QApplication::translate("Widget", "\347\274\226\347\250\213\345\274\200\345\217\221", Q_NULLPTR));
        menu_btn_system->setText(QApplication::translate("Widget", "\347\263\273\347\273\237\347\256\241\347\220\206", Q_NULLPTR));
        menu_btn_theme->setText(QApplication::translate("Widget", "\344\270\273\351\242\230\347\276\216\345\214\226", Q_NULLPTR));
        menu_btn_other->setText(QApplication::translate("Widget", "\345\205\266\344\273\226\345\272\224\347\224\250", Q_NULLPTR));
        menu_btn_download->setText(QApplication::translate("Widget", "\344\270\213\350\275\275\345\210\227\350\241\250", Q_NULLPTR));
        label_show->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
