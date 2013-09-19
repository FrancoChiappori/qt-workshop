#ifndef QUDPSOCKET_MOCK_H
#define QUDPSOCKET_MOCK_H

#include <QtCore/QObject>
#include <QtNetwork/QHostAddress>
#include <QtNetwork/QUdpSocket>

#include "messenger/iudp_socket.h"

class QUdpSocketMock : public QObject, public IM::IUdpSocket
{
    Q_OBJECT

public:
    virtual bool bind(quint16, QAbstractSocket::BindMode) {return false;}

    virtual qint64 writeDatagram(QByteArray const & datagram, QHostAddress const & host, quint16 port);
    virtual qint64 readDatagram(QByteArray & datagram) { datagram = m_dataToReceive; return 0; }

    virtual QAbstractSocket const * get_QSocket() {return &m_dummySocket;}

    void setDataToReceive(QByteArray const & datagram) { m_dataToReceive = datagram; }

signals:
    void called_writeDatagram(QByteArray const & datagram, QHostAddress const & host, quint16 port);

private:
    QByteArray m_dataToReceive;
    // Just used as target to connect signal.
    QUdpSocket m_dummySocket;
};

Q_DECLARE_METATYPE(QHostAddress);

#endif // QUDPSOCKET_MOCK_H
