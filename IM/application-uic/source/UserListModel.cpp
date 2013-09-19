#include "application-uic/UserListModel.h"
#include <algorithm>

namespace IM {

UserListModel::UserListModel(QObject * parent)
    : QAbstractListModel(parent)
{}

int UserListModel::rowCount(const QModelIndex & parent) const
{
    Q_UNUSED(parent);

    return users.size() + 1;
}

QVariant UserListModel::data(const QModelIndex & index, int role) const
{
    if (!index.isValid())
        return QVariant();
    if (index.row() < 0)
        return QVariant();

    size_t row = static_cast<size_t>(index.row());

    switch (role) {
        case Qt::DisplayRole:
            if (row < users.size()) {
                return users.at(row)->getNickname();
            } else if (row == users.size()) {
                return "Me";
            }
            break;

        default:
            break;
    }

    return QVariant();
}

void UserListModel::received_keep_alive(const QString & nickname)
{
    using namespace std;

    Q_UNUSED(nickname);

    auto i = find_if(begin(users), end(users), [nickname](const User * user)
    {
        return nickname == user->getNickname();
    });

    if (i == end(users)) {
        add_new_user(nickname);
    } else {
        (*i)->keep_alive();
    }
}

void UserListModel::add_new_user(const QString & nickname)
{
    Q_UNUSED(nickname);

    // TODO: implementation
}


}
