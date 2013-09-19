#ifndef USERLISTMODEL_H
#define USERLISTMODEL_H

#include <QAbstractListModel>
#include <vector>
#include <application-uic/User.h>

class QTimer;

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
    void check_user_timeout();

private:
    std::vector<User> users;
    QTimer * timer;
};

}

#endif // USERLISTMODEL_H
