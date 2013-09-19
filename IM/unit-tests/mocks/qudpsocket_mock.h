#ifndef QUDPSOCKET_MOCK_H
#define QUDPSOCKET_MOCK_H

#include <QtCore/QObject>
#include <QtNetwork/QHostAddress>

#include "messenger/iudp_socket.h"

class QUdpSocketMock : public QObject, public IM::IUdpSocket
{
    Q_OBJECT

public:
    virtual bool bind(quint16, QAbstractSocket::BindMode) {return false;}

    qint64 writeDatagram(QByteArray const & datagram, QHostAddress const & host, quint16 port);
    virtual qint64 readDatagram(QByteArray &) {return 0;}

    virtual QAbstractSocket const * get_QSocket() {return 0;}

signals:
    void called_writeDatagram(QByteArray const & datagram, QHostAddress const & host, quint16 port);
};

Q_DECLARE_METATYPE(QHostAddress);

#endif // QUDPSOCKET_MOCK_H
