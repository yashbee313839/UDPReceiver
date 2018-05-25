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
setWindowTitle("UDP Receiver");

socket=new QUdpSocket(this);
socket->bind(QHostAddress::Any, 5000);
connect(socket, SIGNAL(readyRead()), this, SLOT(datagramRecv()));

QVBoxLayout *layout=new QVBoxLayout(this);

trace=new QTextEdit(this);
trace->setReadOnly(true);
trace->append("UDP Trace:");
layout->addWidget(trace);

}

Widget::~Widget(){}

void Widget::datagramRecv(){
QByteArray data;
QHostAddress host;
quint16 port;

while(socket->hasPendingDatagrams()){
    data.resize(socket->pendingDatagramSize());
    socket->readDatagram(data.data(), data.size(), &host, &port);

    QString portStr;
    portStr.setNum(ulong(port));
    trace->append(QString("%1:%2 -> %3").arg(host.toString(), portStr, data));
}

}
