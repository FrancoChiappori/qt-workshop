#include <QtWidgets/QApplication>
#include <QtTest/QTest>

#include "gui_test.h"
#include "User_test.h"

template<typename Test>
void execute_test(int & exit_code, int argc, char * argv[])
{
    Test test;
    if(0 != QTest::qExec(&test, argc, argv)) {
        exit_code++;
    }
}

int main(int argc, char * argv[])
{
    QApplication application(argc, argv);

    int exit_code = 0;

    execute_test<GuiTest>(exit_code, argc, argv);
    execute_test<UserTest>(exit_code, argc, argv);

    return exit_code;
}


