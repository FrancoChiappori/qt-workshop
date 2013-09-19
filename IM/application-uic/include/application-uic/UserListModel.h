#ifndef USERLISTMODEL_H
#define USERLISTMODEL_H

#include <QAbstractListModel>
#include <vector>
#include <application-uic/User.h>

namespace IM {

class UserListModel : public QAbstractListModel
{
    Q_OBJECT

public:
    UserListModel(QObject * parent);
    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

public slots:
    void received_keep_alive(const QString & nickname);

private:
    void add_new_user(const QString &);

    std::vector<User *> users;
};

}

#endif // USERLISTMODEL_H
