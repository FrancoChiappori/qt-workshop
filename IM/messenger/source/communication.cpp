#include <QtCore/QDataStream>
#include <QtNetwork/QHostAddress>
#include <QtNetwork/QUdpSocket>

#include "messenger/iudp_socket.h"
#include "messenger/communication.h"

namespace IM {

quint32 const Command::KeepAlive = 0;
quint32 const Command::Message = 1;

Communication::Communication(IUdpSocket & udp_socket) :
    _udp_socket(udp_socket),
    _port(41000)
{
    _udp_socket.bind(_port, QUdpSocket::ShareAddress);
    connect(_udp_socket.get_QSocket(), SIGNAL(readyRead()),
            this, SLOT(receive_incoming_datagram()));
}

void Communication::handle_send_keep_alive(QString const & nickname)
{
    QByteArray data;
    QDataStream stream(&data, QIODevice::WriteOnly);
    stream.setVersion(QDataStream::Qt_5_0);

    stream << Command::KeepAlive;
    stream << nickname;

    _udp_socket.writeDatagram(data, QHostAddress::Broadcast, _port);
}

void Communication::handle_send_message(const QString & nickname, const QString & message)
{
    QByteArray data;
    QDataStream stream(&data, QIODevice::WriteOnly);
    stream.setVersion(QDataStream::Qt_5_0);

    stream << Command::Message;
    stream << nickname;
    stream << message;

    _udp_socket.writeDatagram(data, QHostAddress::Broadcast, _port);
}

void Communication::receive_incoming_datagram()
{
    QByteArray data;
    _udp_socket.readDatagram(data);
    QDataStream stream(data);

    quint32 command;
    QString nickname;
    stream >> command >> nickname;

    switch(command) {
        case Command::KeepAlive:
            emit received_keep_alive(nickname);
            break;
        case Command::Message:
            // TODO read out message and emit signal.
            break;
        }
    }

} // IM

