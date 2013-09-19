#include <QtWidgets/QWidget>

#include <messenger/controller.h>
#include <messenger/communication.h>
#include <messenger/udp_socket.h>

#include "ui_im_form.h"

#include "application-uic/gui.h"
#include "application-uic/application-uic.h"

namespace IM {

Application::Application()
{
}

int Application::execute(int argc, char * argv[])
{
    QApplication application(argc, argv);

    Controller controller;

    // communication

    UdpSocket udpSocket;
    Communication communication(udpSocket);
    communication.connect(&controller, SIGNAL(send_message(const QString &, const QString &)), SLOT(handle_send_message(const QString &, const QString &)));

    // gui

    Ui::ImForm im_form;
    Gui gui(im_form);

    controller.connect(&gui, SIGNAL(send_message(QString const &)), SLOT(invoke_send_message(QString const &)));

    // run

    gui.show();
    return application.exec();
}

} // IM

