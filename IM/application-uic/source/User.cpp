#include <application-uic/User.h>

namespace IM {

User::User(const QString & nickname)
    : nickname(nickname)
{
    keep_alive();
}

void User::keep_alive(const QDateTime & now)
{
    last_time = now;
}

const QString & User::get_nickname() const
{
    return nickname;
}

bool User::is_expired(const QDateTime & reference_time) const
{
    return last_time < reference_time;
}

}
