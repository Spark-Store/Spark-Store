#ifndef PROGRESSLOAD_H
#define PROGRESSLOAD_H

#include <QWidget>
#include <QTimer>
class ProgressLoad : public QWidget
{
    Q_OBJECT
public:
    explicit ProgressLoad(QWidget *parent = nullptr);
    void setValue(int v);
    void setTheme(bool dark,QColor color);
signals:

public slots:
private:
    QWidget *m_progess;
    int value;
    QTimer *timer;
};

#endif // PROGRESSLOAD_H
