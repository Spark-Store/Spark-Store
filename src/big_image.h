#ifndef BIG_IMAGE_H
#define BIG_IMAGE_H

#include <QWidget>
#include <DBlurEffectWidget>
#include <QMouseEvent>
#include <QLabel>
DWIDGET_USE_NAMESPACE

class big_image : public DBlurEffectWidget
{
    Q_OBJECT
public:
    explicit big_image(DBlurEffectWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *event);
    QLabel *m_image=new QLabel;
    void setimage(QPixmap);
    void focusOutEvent(QFocusEvent *event);

signals:

public slots:
};

#endif // BIG_IMAGE_H
