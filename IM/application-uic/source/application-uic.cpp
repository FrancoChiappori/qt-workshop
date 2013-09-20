#include <QtWidgets/QWidget>

#include <messenger/controller.h>
#include <messenger/communication.h>
#include <messenger/udp_socket.h>

#include "ui_im_form.h"

#include "application-uic/gui.h"
#include "application-uic/application-uic.h"
#include "application-uic/UserListModel.h"

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
    communication.connect(&controller, SIGNAL(send_keepalive(QString const &)), SLOT(handle_send_keep_alive(QString const &)));
    communication.connect(&controller, SIGNAL(send_event(const QString &, const QString &)), SLOT(handle_send_host_event(const QString &, const QString &)));

    // gui

    Ui::ImForm im_form;
    Gui gui(im_form);
    controller.connect(&gui, SIGNAL(send_message(QString const &)), SLOT(invoke_send_message(QString const &)));
    controller.connect(&gui, SIGNAL(send_event(QString const &)), SLOT(invoke_send_event(QString const &)));
    controller.connect(&gui, SIGNAL(notify_nickname(QString const &)), SLOT(set_nickname(QString const &)));
    gui.connect(&communication, SIGNAL(received_message(QString const &, QString const &)), SLOT(on_addChatItem(QString const &, QString const &)));

    // model

    UserListModel model(&gui);
    model.connect(&communication, SIGNAL(received_keep_alive(const QString &)), SLOT(received_keep_alive(const QString &)));
    im_form.Participants->setModel(&model);
    im_form.EventTree->setModel(&model);
    // run
    gui.show();
    return application.exec();
}

} // IM

