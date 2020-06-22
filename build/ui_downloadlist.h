/********************************************************************************
** Form generated from reading UI file 'downloadlist.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOWNLOADLIST_H
#define UI_DOWNLOADLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_downloadlist
{
public:
    QGridLayout *gridLayout;
    QProgressBar *progressBar;
    QPushButton *pushButton;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QLabel *label_filename;

    void setupUi(QWidget *downloadlist)
    {
        if (downloadlist->objectName().isEmpty())
            downloadlist->setObjectName(QStringLiteral("downloadlist"));
        downloadlist->resize(636, 52);
        downloadlist->setStyleSheet(QStringLiteral(""));
        gridLayout = new QGridLayout(downloadlist);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        progressBar = new QProgressBar(downloadlist);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(progressBar->sizePolicy().hasHeightForWidth());
        progressBar->setSizePolicy(sizePolicy);
        progressBar->setMinimumSize(QSize(350, 0));
        progressBar->setMaximumSize(QSize(500, 10));
        progressBar->setValue(24);
        progressBar->setTextVisible(false);

        gridLayout->addWidget(progressBar, 0, 3, 1, 1);

        pushButton = new QPushButton(downloadlist);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(80, 0));
        pushButton->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(pushButton, 0, 5, 1, 1);

        label = new QLabel(downloadlist);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(150, 0));
        label->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setPointSize(13);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 4, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);

        label_filename = new QLabel(downloadlist);
        label_filename->setObjectName(QStringLiteral("label_filename"));

        gridLayout->addWidget(label_filename, 0, 0, 1, 1);


        retranslateUi(downloadlist);

        QMetaObject::connectSlotsByName(downloadlist);
    } // setupUi

    void retranslateUi(QWidget *downloadlist)
    {
        downloadlist->setWindowTitle(QApplication::translate("downloadlist", "Form", Q_NULLPTR));
        pushButton->setText(QApplication::translate("downloadlist", "\345\256\211\350\243\205", Q_NULLPTR));
        label->setText(QApplication::translate("downloadlist", "\345\220\215\347\247\260", Q_NULLPTR));
        label_filename->setText(QApplication::translate("downloadlist", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class downloadlist: public Ui_downloadlist {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOWNLOADLIST_H
