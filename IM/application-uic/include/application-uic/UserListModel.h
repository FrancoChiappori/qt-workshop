#ifndef USERLISTMODEL_H
#define USERLISTMODEL_H

#include <QAbstractListModel>

namespace IM {

class UserListModel : QAbstractListModel
{
    Q_OBJECT

public:
    UserListModel(QObject * parent);
    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
};

}

#endif // USERLISTMODEL_H
