#ifndef CONTROLLER_TEST_H
#define CONTROLLER_TEST_H

#include <QtCore/QObject>

class ControllerTest : public QObject
{
    Q_OBJECT

private slots:
    void invoke_send_message_sends_signal_send_message();
    void invoke_send_keepalive_sends_signal_send_keeplive();
};

#endif // CONTROLLER_TEST_H
