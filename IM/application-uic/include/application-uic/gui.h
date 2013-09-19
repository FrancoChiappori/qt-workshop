#ifndef GUI_H
#define GUI_H

#include <QtWidgets/QWidget>

namespace Ui { class ImForm; }

namespace IM {

class Gui : public QWidget {
    Q_OBJECT

public:
    Gui(Ui::ImForm & form);

    QString getNickname();
private slots:
    void on_SendMessage_clicked();
    void on_Nickname_returnPressed();

signals:
    void send_message(QString const & message);

private:
    Ui::ImForm & _im_form;

    QString m_nickname;
};

} // IM

#endif // GUI_H
