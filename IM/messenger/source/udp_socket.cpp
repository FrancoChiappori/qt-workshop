#include "messenger/udp_socket.h"

namespace IM {

UdpSocket::UdpSocket() :
    _udp_socket()
{
}

bool UdpSocket::bind(quint16 port, QAbstractSocket::BindMode mode)
{
    return _udp_socket.bind(port, mode);
}

qint64 UdpSocket::readDatagram(QByteArray & datagram, QHostAddress *address)
{
    datagram.resize(_udp_socket.pendingDatagramSize());
    return _udp_socket.readDatagram(datagram.data(), datagram.size(), address);
}


qint64 UdpSocket::writeDatagram(const QByteArray & datagram, const QHostAddress & host, quint16 port)
{
    return _udp_socket.writeDatagram(datagram, host, port);
}

QAbstractSocket const * UdpSocket::get_QSocket()
{
    return &_udp_socket;
}

} // IM

