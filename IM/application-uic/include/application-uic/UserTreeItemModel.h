#ifndef USERTREEITEMMODEL_H
#define USERTREEITEMMODEL_H

#include <QAbstractItemModel>
#include <vector>
#include <application-uic/User.h>

class QTimer;

namespace IM {

class UserTreeItemModel : public QAbstractItemModel
{
    Q_OBJECT

public:
    UserTreeItemModel(QObject * parent);
    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    int columnCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const;
    QModelIndex parent(const QModelIndex &child) const;

    void setup_timer();

public slots:
    void received_keep_alive(const QString & nickname);
    void check_user_timeout();

private:
    std::vector<User> users;
    QTimer * timer;
};

}

#endif // UserTreeItemModel_H
