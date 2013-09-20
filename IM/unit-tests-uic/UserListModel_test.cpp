#include <QtTest/QTest>

#include <application-uic/UserListModel.h>

#include "UserListModel_test.h"


namespace IM_test {

// This class is needed to provide access to private methods of the base class
class UserListModelTestee : public ::IM::UserListModel
{
public:
    UserListModelTestee()
        : UserListModel(nullptr)
    {}

    virtual void add_new_user(const QString & nickname)
    {
        UserListModel::add_new_user(nickname);
    }

    virtual int get_insert_row() const
    {
        return UserListModel::get_insert_row();
    }
};

}

void UserListModelTest::insertion_row_with_empty_list()
{
    ::IM_test::UserListModelTestee model;

    QCOMPARE(model.get_insert_row(), 0);
}

void UserListModelTest::insertion_row_with_one_entry()
{
    ::IM_test::UserListModelTestee model;

    model.add_new_user("test");

    QCOMPARE(model.get_insert_row(), 0);
}

void UserListModelTest::insertion_row_with_many_entries()
{
    ::IM_test::UserListModelTestee model;

    model.add_new_user("test0");
    model.add_new_user("test1");
    model.add_new_user("test2");
    model.add_new_user("test3");

    QCOMPARE(model.get_insert_row(), 3);
}
