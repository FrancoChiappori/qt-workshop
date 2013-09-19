#ifndef USER_TEST_H
#define USER_TEST_H

#include <QtCore/QObject>

class UserTest : public QObject
{
    Q_OBJECT

private slots:
    void setting_nickname();
    void timeout();
};

#endif
