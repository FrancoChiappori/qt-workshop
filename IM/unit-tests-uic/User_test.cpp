#include <QtTest/QTest>

#include <application-uic/User.h>

#include "User_test.h"

void UserTest::setting_nickname()
{
    QString expected_nickname = "Foobar";

    IM::User user(expected_nickname);

    // assert
    QCOMPARE(user.getNickname(), expected_nickname);
}
