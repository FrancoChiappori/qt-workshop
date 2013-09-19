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

qint64 QUdpSocketMock::readDatagram(QByteArray & datagram)
{
    datagram = m_dataToReceive; return 0;
}

QAbstractSocket const * QUdpSocketMock::get_QSocket()
{
    return &m_dummySocket;
}

void QUdpSocketMock::setDataToReceive(QByteArray const & datagram)
{
    m_dataToReceive = datagram;
}


