#ifndef USERLISTMODEL_TEST_H
#define USERLISTMODEL_TEST_H

#include <QtCore/QObject>

class UserListModelTest : public QObject
{
    Q_OBJECT

private slots:
    void insertion_row_with_empty_list();
    void insertion_row_with_one_entry();
    void insertion_row_with_many_entries();
    void received_keepalive_with_empty_nickname();
    void received_keepalive_with_new_nickname();
    void received_keepalive_with_existing_nickname();
};

#endif
