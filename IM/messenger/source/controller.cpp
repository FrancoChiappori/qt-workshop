#include "messenger/controller.h"

#include <QTimer>

namespace IM {

Controller::Controller()
    : _nickname("")
    , timerKeepAlive(nullptr)
{
    timerKeepAlive = new QTimer(this);
    connect(timerKeepAlive, SIGNAL(timeout()), this, SLOT(timeoutKeepAlive()));
    timerKeepAlive->setSingleShot(false);
    timerKeepAlive->setTimerType(Qt::PreciseTimer);
    timerKeepAlive->start(5000);
}

void Controller::setupTimer()
{}

void Controller::invoke_send_message(const QString & message)
{
    emit send_message(_nickname, message);
}

void Controller::set_nickname(const QString & nickname)
{
    _nickname = nickname;
}

void Controller::timeoutKeepAlive()
{
    // TODO: implementation of timer timeouts
}

} // IM

