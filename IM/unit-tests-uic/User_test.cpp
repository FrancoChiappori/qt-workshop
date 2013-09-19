#include <QtTest/QTest>

#include <application-uic/User.h>

#include "User_test.h"

void UserTest::setting_nickname()
{
    QString expected_nickname = "Foobar";

    IM::User user(expected_nickname);

    // assert
    QCOMPARE(user.get_nickname(), expected_nickname);
}

void UserTest::timeout()
{
    // arrange
    IM::User user("Foobar");
    QDateTime t0 = QDateTime::currentDateTime();
    QDateTime t1 = t0.addSecs(5);
    QDateTime t2 = t0.addSecs(-5);

    // act
    user.keep_alive(t0);

    // assert
    QCOMPARE(user.is_expired(t0), false);
    QCOMPARE(user.is_expired(t1), true);
    QCOMPARE(user.is_expired(t2), false);
}
