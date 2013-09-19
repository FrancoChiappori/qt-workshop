#ifndef IUDP_SOCKET_H
#define IUDP_SOCKET_H

#include <QtCore/QtGlobal>

class QHostAddress;
class QByteArray;
class Communication;

namespace IM {

class IUdpSocket
{
public:
    ~IUdpSocket() {}

    virtual bool bind(quint16 port, QAbstractSocket::BindMode mode) = 0;

    virtual qint64 writeDatagram(QByteArray const & datagram, QHostAddress const & host, quint16 port) = 0;
    virtual qint64 readDatagram(QByteArray & datagram) = 0;

    virtual QAbstractSocket const * get_QSocket() = 0;
};

} // IM

#endif // IUDP_SOCKET_H
