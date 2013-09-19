#include <application-uic/User.h>
#include <QTimer>

namespace IM {

User::User(const QString & nickname, QTimer * timer)
    : nickname(nickname)
    , timer(timer)
{}

void User::keep_alive()
{
    if (timer)
        timer->start();
}

const QString & User::getNickname() const
{
    return nickname;
}

}
