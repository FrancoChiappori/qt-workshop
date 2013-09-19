#include <QtCore/QByteArray>

#include "qudpsocket_mock.h"

bool QUdpSocketMock::bind(quint16, QAbstractSocket::BindMode)
{
    return true;
}

qint64 QUdpSocketMock::writeDatagram(QByteArray const & datagram, QHostAddress const & host, quint16 port)
{
    emit called_writeDatagram(datagram, host, port);
    return datagram.size();
}

qint64 QUdpSocketMock::readDatagram(QByteArray & datagram, QHostAddress *address)
{
    datagram = m_dataToReceive;
    if (address) {
        *address = m_receivedFrom;
    }
    return 0;
}

QAbstractSocket const * QUdpSocketMock::get_QSocket()
{
    return &m_dummySocket;
}

void QUdpSocketMock::setDataToReceive(QByteArray const & datagram, const QHostAddress * address)
{
    m_dataToReceive = datagram;
    if (address) {
        m_receivedFrom = *address;
    }
}


