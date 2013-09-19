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
    virtual bool bind(quint16 port, QAbstractSocket::BindMode mode);

    virtual qint64 writeDatagram(QByteArray const & datagram, QHostAddress const & host, quint16 port);
    virtual qint64 readDatagram(QByteArray & datagram, QHostAddress * address);

    virtual QAbstractSocket const * get_QSocket();

    void setDataToReceive(QByteArray const & datagram, const QHostAddress * address =0);

signals:
    void called_writeDatagram(QByteArray const & datagram, QHostAddress const & host, quint16 port);

private:
    QByteArray m_dataToReceive;
    QHostAddress m_receivedFrom;
    // Just used as target to connect signal.
    QUdpSocket m_dummySocket;
};

Q_DECLARE_METATYPE(QHostAddress);

#endif // QUDPSOCKET_MOCK_H
