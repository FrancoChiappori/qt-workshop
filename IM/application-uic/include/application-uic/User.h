#ifndef USER_H
#define USER_H

#include <QString>

class QTimer;

namespace IM {

class User
{
public:
    User(const QString &, QTimer * = nullptr);

    void keep_alive();
    const QString & getNickname() const;

private:
    QString nickname;
    QTimer * timer;
};


}

#endif // USER_H
