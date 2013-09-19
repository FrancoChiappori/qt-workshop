#include <QtCore/QDataStream>
#include <QtNetwork/QHostAddress>
#include <QtNetwork/QUdpSocket>

#include "messenger/iudp_socket.h"
#include "messenger/communication.h"

namespace IM {

quint32 const Command::KeepAlive = 0;
quint32 const Command::Message = 1;
quint32 const Command::HostEvent = 2;

Communication::Communication(IUdpSocket & udp_socket) :
    _udp_socket(udp_socket),
    _port(41000)
{
    _udp_socket.bind(_port, QUdpSocket::ShareAddress);
    connect(_udp_socket.get_QSocket(), SIGNAL(readyRead()),
            this, SLOT(receive_incoming_datagram()));
}

void Communication::handle_send_keep_alive(const QString & nickname)
{
    QByteArray data;
    QDataStream stream(&data, QIODevice::WriteOnly);

    setup_datagram(stream, Command::KeepAlive, nickname);

    _udp_socket.writeDatagram(data, QHostAddress::Broadcast, _port);
}

void Communication::handle_send_message(const QString & nickname, const QString & message)
{
    QByteArray data;
    QDataStream stream(&data, QIODevice::WriteOnly);

    setup_datagram(stream, Command::Message, nickname);
    stream << message;

    _udp_socket.writeDatagram(data, QHostAddress::Broadcast, _port);
}

void Communication::handle_send_host_event(const QString & nickname, const QString & event)
{
    QByteArray data;
    QDataStream stream(&data, QIODevice::WriteOnly);

    setup_datagram(stream, Command::HostEvent, nickname);
    stream << event;

    _udp_socket.writeDatagram(data, QHostAddress::Broadcast, _port);
}

void Communication::receive_incoming_datagram()
{
    QByteArray data;
    QHostAddress sender;
    _udp_socket.readDatagram(data, &sender);
    QDataStream stream(data);

    quint32 command;
    QString nickname;
    stream >> command >> nickname;

    switch(command) {
    case Command::KeepAlive:
        emit received_keep_alive(nickname);
        break;
    case Command::Message: {
        QString message;
        stream >> message;
        emit received_message(nickname, message);
        break;
    }
    case Command::HostEvent: {
        QString event;
        stream >> event;
        emit received_host_event(nickname, event, sender);
        break;
    }
    }
}

void Communication::setup_datagram(QDataStream & stream, quint32 command, const QString & nickname)
{
    stream.setVersion(QDataStream::Qt_5_0);

    stream << command;
    stream << nickname;
}

} // IM

