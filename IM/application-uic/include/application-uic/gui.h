#ifndef GUI_H
#define GUI_H

#include <QtWidgets/QWidget>

namespace Ui { class ImForm; }

namespace IM {

class Gui : public QWidget {
    Q_OBJECT

public:
    Gui(Ui::ImForm & form);

public slots:
    void on_addChatItem(const QString & nickname, QString const & message);

private slots:
    void on_SendMessage_clicked();
    void on_MessageInput_returnPressed();

    void on_Nickname_returnPressed();

    void on_EventInput_returnPressed();
    void on_AddEvent_clicked();

signals:
    void send_message(QString const & message);
    void notify_nickname(QString const & nickname);
    void send_event(QString const & event);

private:
    Ui::ImForm & _im_form;
    QString m_nickname;
};

} // IM

#endif // GUI_H
