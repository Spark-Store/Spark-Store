#ifndef IMAGE_SHOW_H
#define IMAGE_SHOW_H

#include <QWidget>
#include <QMouseEvent>
#include <QLabel>
#include <QPixmap>
#include <DDialog>

DWIDGET_USE_NAMESPACE
class image_show : public QWidget
{
    Q_OBJECT
public:
    explicit image_show(QWidget *parent = nullptr);

    void setImage(QPixmap);
private:
    QLabel *m_label=new QLabel;
    QPixmap m_image;
    QLabel image;
    DDialog *m_dialog=new DDialog;
    void mousePressEvent(QMouseEvent *event);
signals:

public slots:
};

#endif // IMAGE_SHOW_H
