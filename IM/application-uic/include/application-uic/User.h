#ifndef USER_H
#define USER_H

#include <QString>

namespace IM {

class User
{
public:
    User(const QString &);

    void keep_alive();

private:
    QString nickname;
};


}

#endif // USER_H
