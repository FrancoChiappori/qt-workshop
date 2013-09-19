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

signals:
    void send_message(const QString & nickname, QString const & message);

private:
    void setupTimer();

    QString _nickname;
    QTimer * timerKeepAlive;

private slots:
    void timeoutKeepAlive();
};

} // IM

#endif // CONTROLLER_H
