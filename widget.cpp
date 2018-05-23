#include "widget.h"

#include <QtNetwork>
#include <QtGui>
#if QT_VERSION >= 0x050000
#include <QtWidgets>
#endif
#include <QDebug>

Widget::Widget(QWidget *parent)
: QWidget(parent)
{
setWindowTitle("UDP Sender");

socket=new QUdpSocket(this);
connect(socket, SIGNAL(bytesWritten(qint64)), this, SLOT(datagramSent()));

QVBoxLayout *layout=new QVBoxLayout(this);

message=new QLineEdit(this);
layout->addWidget(message);

QPushButton *send=new QPushButton("&Send", this);
connect(send, SIGNAL(clicked()), this, SLOT(datagramSend()));
layout->addWidget(send);
}

Widget::~Widget(){}

void Widget::datagramSend(){
socket->writeDatagram(message->text().toAscii(), QHostAddress::Any, 5000);
}

void Widget::datagramSent(){
qDebug() << "Datagram Sent";
}
