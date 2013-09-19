#include "messenger/controller.h"

#include <QTimer>

namespace IM {

Controller::Controller()
    : _nickname("")
    , timerKeepAlive(nullptr)
{
    timerKeepAlive = new QTimer(this);
    connect(timerKeepAlive, SIGNAL(timeout()), this, SLOT(invoke_send_keepalive()));
    timerKeepAlive->setSingleShot(false);
    timerKeepAlive->setTimerType(Qt::PreciseTimer);
    timerKeepAlive->setInterval(5000);
}

void Controller::setupTimer()
{}

void Controller::invoke_send_message(const QString & message)
{
    emit send_message(_nickname, message);
}

void Controller::invoke_send_keepalive()
{
    if (!_nickname.isEmpty())
        emit send_keepalive(_nickname);
}

void Controller::set_nickname(const QString & nickname)
{
    _nickname = nickname;
    timerKeepAlive->start();
    invoke_send_keepalive();
}

} // IM

