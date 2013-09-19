#include <QtTest/QTest>
#include <QtTest/QSignalSpy>

#include <messenger/communication.h>

#include "mocks/qudpsocket_mock.h"
#include "communication_test.h"

void CommunicationTest::handle_send_keep_alive_broadcasts_the_message_over_udp()
{
    // arrange
    qRegisterMetaType<QHostAddress>("QHostAddress");
    QUdpSocketMock udp_socket;
    QSignalSpy writeDatagram(&udp_socket, SIGNAL(called_writeDatagram(QByteArray const &, QHostAddress const &, quint16)));

    // act
    IM::Communication testee(udp_socket);
    const QString expected_nickname = "Travis";
    testee.handle_send_keep_alive(expected_nickname);

    // assert
    QCOMPARE(writeDatagram.count(), 1);

    const auto arguments = writeDatagram.takeFirst();
    QDataStream data(arguments.at(0).toByteArray());

    quint32 command;
    QString nickname;
    data >> command >> nickname;

    const quint32 expected_command = IM::Command::KeepAlive;
    QCOMPARE(command, expected_command);
    QCOMPARE(nickname, expected_nickname);

    const QHostAddress expected_address = QHostAddress::Broadcast;
    QCOMPARE(qvariant_cast<QHostAddress>(arguments.at(1)), expected_address);

    const quint32 expected_port = 41000;
    QCOMPARE(arguments.at(2).toUInt(), expected_port);
}

void CommunicationTest::handle_send_message_broadcasts_the_message_over_udp()
{
    // arrange
    qRegisterMetaType<QHostAddress>("QHostAddress");
    QUdpSocketMock udp_socket;
    QSignalSpy writeDatagram(&udp_socket, SIGNAL(called_writeDatagram(QByteArray const &, QHostAddress const &, quint16)));

    // act
    IM::Communication testee(udp_socket);
    const QString expected_nickname = "Name";
    const QString expected_message = "Hello world.";
    testee.handle_send_message(expected_nickname, expected_message);

    // assert
    QCOMPARE(writeDatagram.count(), 1);

    const auto arguments = writeDatagram.takeFirst();
    QDataStream data(arguments.at(0).toByteArray());

    quint32 command;
    QString nickname;
    QString message;
    data >> command >> nickname >> message;

    const quint32 expected_command = IM::Command::Message;
    QCOMPARE(command, expected_command);
    QCOMPARE(nickname, expected_nickname);
    QCOMPARE(message, expected_message);

    const QHostAddress expected_address = QHostAddress::Broadcast;
    QCOMPARE(qvariant_cast<QHostAddress>(arguments.at(1)), expected_address);

    const quint32 expected_port = 41000;
    QCOMPARE(arguments.at(2).toUInt(), expected_port);
}

void CommunicationTest::receiving_keep_alive_on_udp_emits_proper_signal()
{
    // arrange
    QUdpSocketMock udp_socket;
    IM::Communication testee(udp_socket);
    const QString expected_nickname = "Legolas";

    QByteArray data;
    QDataStream stream(&data, QIODevice::WriteOnly);
    stream.setVersion(QDataStream::Qt_5_0);
    stream << IM::Command::KeepAlive;
    stream << expected_nickname;
    udp_socket.setDataToReceive(data);

    QSignalSpy receiveKeepAlive(&testee, SIGNAL(received_keep_alive(const QString &)));

    // act
    testee.receive_incoming_datagram();

    // assert
    QCOMPARE(receiveKeepAlive.count(), 1);
    const auto arguments = receiveKeepAlive.takeFirst();
    QString nickname = arguments.at(0).toString();
    QCOMPARE(nickname, expected_nickname);
}

void CommunicationTest::receiving_message_on_udp_emits_proper_signal()
{
    // arrange
    QUdpSocketMock udp_socket;
    IM::Communication testee(udp_socket);
    const QString expected_nickname = "Legolas";
    const QString expected_message = "To the sea!";

    QByteArray data;
    QDataStream stream(&data, QIODevice::WriteOnly);
    stream.setVersion(QDataStream::Qt_5_0);
    stream << IM::Command::Message;
    stream << expected_nickname;
    stream << expected_message;
    udp_socket.setDataToReceive(data);

    QSignalSpy receiveMessage(&testee, SIGNAL(received_message(const QString &, QString const &)));

    // act
    testee.receive_incoming_datagram();

    // assert
    QCOMPARE(receiveMessage.count(), 1);
    const auto arguments = receiveMessage.takeFirst();
    QString nickname = arguments.at(0).toString();
    QString message = arguments.at(1).toString();
    QCOMPARE(nickname, expected_nickname);
    QCOMPARE(message, expected_message);
}
