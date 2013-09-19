#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <QtCore/QObject>

class QHostAddress;

namespace IM {

class IUdpSocket;

class Command {
public:
    static quint32 const KeepAlive;
    static quint32 const Message;
    static quint32 const HostEvent;
};

class Communication : public QObject
{
    Q_OBJECT
public:
    Communication(IUdpSocket & udp_socket);

public slots:
    void handle_send_keep_alive(const QString & nickname);
    void handle_send_message(const QString & nickname, const QString & message);
    void handle_send_host_event(const QString & nickname, const QString & event);

    void receive_incoming_datagram();

signals:
    void received_keep_alive(const QString & nickname);
    void received_message(const QString & nickname, const QString  & message);
    void received_host_event(const QString & nickname, QString const & event, const QHostAddress & host);

private:
    void setup_datagram(QDataStream & stream, quint32 command, const QString & nickname);

    IUdpSocket & _udp_socket;
    quint16 _port;
};

} // IM

#endif // COMMUNICATION_H
