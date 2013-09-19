#include "application-uic/UserListModel.h"

namespace IM {

UserListModel::UserListModel(QObject * parent)
    : QAbstractListModel(parent)
{}

int UserListModel::rowCount(const QModelIndex & parent) const
{
    Q_UNUSED(parent);

    return users.size();
}

QVariant UserListModel::data(const QModelIndex & index, int role) const
{
    Q_UNUSED(index);
    Q_UNUSED(role);

    return QVariant(); // TODO: implementation
}

void UserListModel::received_keep_alive(const QString & nickname)
{
    Q_UNUSED(nickname);

    // TODO: implementation
}

}
