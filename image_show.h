#ifndef IMAGE_SHOW_H
#define IMAGE_SHOW_H

#include <QWidget>
#include <QMouseEvent>
#include <QLabel>
#include <QPixmap>
#include <DDialog>
#include <DBlurEffectWidget>
#include <big_image.h>
DWIDGET_USE_NAMESPACE
class image_show : public QWidget
{
    Q_OBJECT
public:
    explicit image_show(QWidget *parent = nullptr);

    void setImage(QPixmap);
    int desktop_w;
    int desktop_h;
private:
    QLabel *m_label=new QLabel;
    QPixmap m_image;
    QLabel image;
    big_image *m_dialog=new big_image;
    void mousePressEvent(QMouseEvent *event);
signals:

public slots:
};

#endif // IMAGE_SHOW_H
