#include "application-uic/UserListModel.h"
#include <algorithm>
#include <QTimer>

namespace IM {

UserListModel::UserListModel(QObject * parent)
    : QAbstractListModel(parent)
    , timer(nullptr)
{}

UserListModel::~UserListModel()
{}

void UserListModel::setup_timer()
{
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(check_user_timeout()));
    timer->setSingleShot(false);
    timer->setTimerType(Qt::PreciseTimer);
    timer->start(1000);
}

int UserListModel::rowCount(const QModelIndex & parent) const
{
    Q_UNUSED(parent);

    return users.size();
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
            if (row < users.size())
                return users.at(row).get_nickname();
            break;

        default:
            break;
    }

    return QVariant();
}

int UserListModel::get_user_count() const
{
    return static_cast<int>(users.size());
}

void UserListModel::received_keep_alive(const QString & nickname)
{
    using namespace std;

    if (nickname.isEmpty())
        return;

    auto i = find_if(begin(users), end(users), [nickname](const User & user)
    {
        return nickname == user.get_nickname();
    });

    if (i == end(users)) {
        add_new_user(nickname);
    } else {
        i->keep_alive();
    }
}

void UserListModel::add_new_user(const QString & nickname)
{
    int start = get_insert_row();
    beginInsertRows(QModelIndex(), start, start + 1);
    users.push_back(User(nickname));
    endInsertRows();
}

int UserListModel::get_insert_row() const
{
    return users.empty()
        ? 0
        : get_user_count() - 1;
}

void UserListModel::check_user_timeout_specified(const QDateTime & now)
{
    using namespace std;

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

void UserListModel::check_user_timeout()
{
    check_user_timeout_specified(QDateTime::currentDateTime().addSecs(-7));
}

}
