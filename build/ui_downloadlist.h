/********************************************************************************
** Form generated from reading UI file 'downloadlist.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOWNLOADLIST_H
#define UI_DOWNLOADLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <dspinner.h>

QT_BEGIN_NAMESPACE

class Ui_downloadlist
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer;
    QLabel *label_filename;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QProgressBar *progressBar;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_3;
    DSpinner *widget_spinner;
    QPushButton *pushButton_install;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QWidget *downloadlist)
    {
        if (downloadlist->objectName().isEmpty())
            downloadlist->setObjectName(QStringLiteral("downloadlist"));
        downloadlist->resize(666, 54);
        downloadlist->setMaximumSize(QSize(16777215, 54));
        downloadlist->setStyleSheet(QStringLiteral(""));
        horizontalLayout = new QHBoxLayout(downloadlist);
        horizontalLayout->setSpacing(2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(4, 4, 4, 4);
        label_3 = new QLabel(downloadlist);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMaximumSize(QSize(48, 16777215));
        label_3->setScaledContents(true);

        horizontalLayout->addWidget(label_3);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_filename = new QLabel(downloadlist);
        label_filename->setObjectName(QStringLiteral("label_filename"));
        label_filename->setMaximumSize(QSize(0, 16777215));

        horizontalLayout->addWidget(label_filename);

        label = new QLabel(downloadlist);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(80, 0));
        label->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setPointSize(13);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        widget = new QWidget(downloadlist);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(280, 0));
        widget->setMaximumSize(QSize(500, 16777215));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, -1, 0, 0);
        progressBar = new QProgressBar(widget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(progressBar->sizePolicy().hasHeightForWidth());
        progressBar->setSizePolicy(sizePolicy);
        progressBar->setMinimumSize(QSize(300, 0));
        progressBar->setMaximumSize(QSize(500, 10));
        progressBar->setValue(24);
        progressBar->setTextVisible(false);

        verticalLayout->addWidget(progressBar);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font1;
        font1.setPointSize(9);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_2);


        horizontalLayout->addWidget(widget);

        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        widget_spinner = new DSpinner(downloadlist);
        widget_spinner->setObjectName(QStringLiteral("widget_spinner"));
        widget_spinner->setMinimumSize(QSize(30, 0));

        horizontalLayout->addWidget(widget_spinner);

        pushButton_install = new QPushButton(downloadlist);
        pushButton_install->setObjectName(QStringLiteral("pushButton_install"));
        pushButton_install->setMinimumSize(QSize(60, 0));
        pushButton_install->setMaximumSize(QSize(60, 16777215));

        horizontalLayout->addWidget(pushButton_install);

        pushButton_2 = new QPushButton(downloadlist);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(60, 0));
        pushButton_2->setMaximumSize(QSize(60, 16777215));

        horizontalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(downloadlist);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(60, 0));
        pushButton_3->setMaximumSize(QSize(60, 16777215));

        horizontalLayout->addWidget(pushButton_3);


        retranslateUi(downloadlist);

        QMetaObject::connectSlotsByName(downloadlist);
    } // setupUi

    void retranslateUi(QWidget *downloadlist)
    {
        downloadlist->setWindowTitle(QApplication::translate("downloadlist", "Form", nullptr));
        label_3->setText(QApplication::translate("downloadlist", "icon", nullptr));
        label_filename->setText(QApplication::translate("downloadlist", "TextLabel", nullptr));
        label->setText(QApplication::translate("downloadlist", "Name", nullptr));
        label_2->setText(QApplication::translate("downloadlist", "Waiting to download", nullptr));
        pushButton_install->setText(QApplication::translate("downloadlist", "Install", nullptr));
        pushButton_2->setText(QApplication::translate("downloadlist", "Cancel", nullptr));
        pushButton_3->setText(QApplication::translate("downloadlist", "Info", nullptr));
    } // retranslateUi

};

namespace Ui {
    class downloadlist: public Ui_downloadlist {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOWNLOADLIST_H
