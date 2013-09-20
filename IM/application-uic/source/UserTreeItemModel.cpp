#include "application-uic/UserTreeItemModel.h"
#include <algorithm>
#include <QTimer>

const int noOfColumns = 1;

namespace IM {

UserTreeItemModel::UserTreeItemModel(QObject * parent)
    : QAbstractItemModel(parent)
    , timer(nullptr)
{
    beginInsertColumns(QModelIndex(), noOfColumns, noOfColumns);
    endInsertColumns();
}


void UserTreeItemModel::setup_timer()
{
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(check_user_timeout()));
    timer->setSingleShot(false);
    timer->setTimerType(Qt::PreciseTimer);
    timer->start(1000);
}

int UserTreeItemModel::rowCount(const QModelIndex & parent) const
{
    Q_UNUSED(parent);

    return users.size();
}

int UserTreeItemModel::columnCount(const QModelIndex & parent) const
{
    Q_UNUSED(parent);

    return noOfColumns;
}

QVariant UserTreeItemModel::data(const QModelIndex & index, int role) const
{
    if (!index.isValid())
        return QVariant();
    if (index.row() < 0)
        return QVariant();

    size_t row = static_cast<size_t>(index.row());

    switch (role) {
        case Qt::DisplayRole:
            if (row < users.size())
                return users.at(row).get_nickname();
            break;

        default:
            break;
    }

    return QVariant();
}

void UserTreeItemModel::received_keep_alive(const QString & nickname)
{
    using namespace std;

    if (nickname.isEmpty())
        return;

    auto i = find_if(begin(users), end(users), [nickname](const User & user)
    {
        return nickname == user.get_nickname();
    });

    if (i == end(users)) {
        beginInsertRows(QModelIndex(), users.size()-1, users.size());
        users.push_back(User(nickname));
        endInsertRows();
    } else {
        i->keep_alive();
    }
}

void UserTreeItemModel::check_user_timeout()
{
    using namespace std;

    QDateTime now = QDateTime::currentDateTime().addSecs(-7);

    for (;;) {
        auto i = find_if(begin(users), end(users), [now](const User & user)
        {
            return user.is_expired(now);
        });
        if (i == end(users))
            return;

        beginRemoveRows(QModelIndex(), i - begin(users), i - begin(users) + 1);
        users.erase(i);
        endRemoveRows();
    }
}

QModelIndex UserTreeItemModel::index(int row, int column, const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    Q_UNUSED(row);
    Q_UNUSED(column);
    QModelIndex index;
    return index;
}

QModelIndex UserTreeItemModel::parent(const QModelIndex &child) const
{
    Q_UNUSED(child);
    QModelIndex index;
    return index;
}


}
