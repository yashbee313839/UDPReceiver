#ifndef WIDGET_H
#define WIDGET_H
#include <QWidget>
#include <QtGui>

class QUdpSocket;
class QLineEdit;

class Widget : public QWidget
{
Q_OBJECT

public:
Widget(QWidget *parent = 0);
~Widget();

private:
QUdpSocket *socket;
QLineEdit *message;

public slots:
void datagramSend();
void datagramSent();
};

#endif // WIDGET_H
