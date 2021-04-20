#ifndef PROGRESSLOAD_H
#define PROGRESSLOAD_H

#include <QWidget>
#include <QTimer>
#include <QPalette>

class ProgressLoad : public QWidget
{
    Q_OBJECT

public:
    explicit ProgressLoad(QWidget *parent = nullptr);

    void setValue(int v);
    void setTheme(bool dark, QColor color);

private:
    QWidget *m_progess;
    QTimer *timer;
    int value;
    QPalette plt;

};

#endif // PROGRESSLOAD_H
