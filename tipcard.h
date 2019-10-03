#ifndef TIPBOXCARD_H
#define TIPBOXCARD_H

#include <QObject>
#include <QWidget>
#include <QString>
#include <QLabel>
#include <QPushButton>
#include <QPropertyAnimation>
#include <QTimer>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPixmap>
#include <QIcon>
#include <QPaintEvent>
#include <QPainter>
#include <QPainterPath>
#include <QPropertyAnimation>
#include <QDebug>
#include "threedimenbutton.h"

class TipBox;

class TipCard : public ThreeDimenButton
{
    Q_OBJECT
    friend class TipBox;
public:
    TipCard(QWidget *parent, QString k, QString t, QString c);
    TipCard(QWidget *parent, QString k, QString t, QString c, QString b);
    TipCard(QWidget *parent, QString k, QString t, QString c, QString b1, QString b2);

    QSize getSize();
    void startWaitingLeave();
    void pauseWaitingLeave();

protected:
    void paintEvent(QPaintEvent* event) override;
    void enterEvent(QEvent*event) override;
    void leaveEvent(QEvent*event) override;

private:
    void initCard();

signals:
    void signalClosed(TipCard* card);
    void signalButton1Clicked(QString key);
    void signalButton2Clicked(QString key);


public slots:
    void slotClosed();

private:
    QString key;
    QString title;
    QString content;
    QString btn1_title, btn2_title;
    QString str1, str2, str3;

    QLabel* title_label;
    QLabel* content_label;
    InteractiveButtonBase* operator1_button;
    InteractiveButtonBase* operator2_button;
    InteractiveButtonBase* close_button;
    QTimer* close_timer;

    QPropertyAnimation* animation;
    QSize my_size; // 自己固定的大小，以后都不能变！（直到删除）

    bool is_closing;
    bool has_leaved;
};

#endif // TIPBOXCARD_H
