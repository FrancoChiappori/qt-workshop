#include <QtTest/QTest>
#include <QtTest/QSignalSpy>

#include <messenger/controller.h>

#include "controller_test.h"

void ControllerTest::invoke_send_message_sends_signal_send_message()
{
    // arrange
    IM::Controller testee;
    QSignalSpy signal_spy(&testee, SIGNAL(send_message(QString const &, QString const &)));

    QString const expected_nickname = "Name";
    QString const expected_message = "Hello world.";

    testee.set_nickname(expected_nickname);

    // act
    testee.invoke_send_message(expected_message);

    // assert
    QCOMPARE(signal_spy.count(), 1);

    const auto arguments = signal_spy.takeFirst();
    QCOMPARE(arguments.size(), 2);
    QCOMPARE(arguments.at(0).toString(), expected_nickname);
    QCOMPARE(arguments.at(1).toString(), expected_message);
}

void ControllerTest::invoke_send_keepalive_sends_signal_send_keeplive()
{
    // arrange
    IM::Controller testee;
    QSignalSpy signal_spy(&testee, SIGNAL(send_keepalive(QString const &)));

    QString const expected_nickname = "Name";

    testee.set_nickname(expected_nickname);

    // act
    testee.invoke_send_keepalive();

    // assert
    QCOMPARE(signal_spy.count(), 1);
    const auto arguments = signal_spy.takeFirst();
    QCOMPARE(arguments.size(), 1);
    QCOMPARE(arguments.at(0).toString(), expected_nickname);
}
