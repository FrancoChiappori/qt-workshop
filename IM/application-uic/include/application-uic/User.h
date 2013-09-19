#ifndef USER_H
#define USER_H

#include <QString>
#include <QDateTime>

namespace IM {

class User
{
public:
    User(const QString &);

    void keep_alive(const QDateTime & now = QDateTime::currentDateTime());
    const QString & get_nickname() const;
    bool is_expired(const QDateTime &) const;

private:
    QString nickname;
    QDateTime last_time;
};

}

#endif // USER_H
