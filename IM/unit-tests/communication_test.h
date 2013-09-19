#ifndef COMMUNICATION_TEST_H
#define COMMUNICATION_TEST_H

#include <QObject>

class CommunicationTest : public QObject
{
    Q_OBJECT

private slots:
    void handle_send_keep_alive_broadcasts_the_message_over_udp();
    void handle_send_message_broadcasts_the_message_over_udp();
    void receiving_keep_alive_on_udp_emits_proper_signal();
};

#endif // COMMUNICATION_TEST_H
