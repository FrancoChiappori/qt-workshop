#include <QtCore/QCoreApplication>
#include <QtTest/QTest>

#include "controller_test.h"
#include "communication_test.h"

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
    QCoreApplication application(argc, argv);

    int exit_code = 0;

    execute_test<ControllerTest>(exit_code, argc, argv);
    execute_test<CommunicationTest>(exit_code, argc, argv);

    return exit_code;
}


