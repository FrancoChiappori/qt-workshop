#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QtCore/QObject>

class QTimer;

namespace IM {

class Controller : public QObject
{
    Q_OBJECT
public:
    Controller();

    void set_nickname(const QString & nickname);

public slots:
    void invoke_send_message(const QString & message);
    void invoke_send_keepalive();

signals:
    void send_message(const QString & nickname, QString const & message);
    void send_keepalive(QString const &);

private:
    void setupTimer();

    QString _nickname;
    QTimer * timerKeepAlive;
};

} // IM

#endif // CONTROLLER_H
