#include "application-uic/UserListModel.h"

namespace IM {

UserListModel::UserListModel(QObject * parent)
    : QAbstractListModel(parent)
{}

int UserListModel::rowCount(const QModelIndex & parent) const
{
    return 0; // TODO: implementation
}

QVariant UserListModel::data(const QModelIndex & index, int role) const
{
    return QVariant(); // TODO: implementation
}

}
