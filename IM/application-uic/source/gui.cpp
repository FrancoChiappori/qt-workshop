#include "ui_im_form.h"

#include "application-uic/gui.h"

namespace IM {

Gui::Gui(Ui::ImForm & im_form) :
    QWidget(nullptr),
    _im_form(im_form)
{
    _im_form.setupUi(this);
    _im_form.Chat->setAutoScroll(true);
}

void Gui::on_SendMessage_clicked()
{
    if(!_im_form.MessageInput->text().isEmpty() && !m_nickname.isEmpty())
    {
        emit send_message(_im_form.MessageInput->text());
        _im_form.MessageInput->clear();
    }
}

void Gui::on_Nickname_returnPressed()
{
    m_nickname =_im_form.Nickname->text();
    emit notify_nickname(m_nickname);
}

void Gui::on_MessageInput_returnPressed()
{
  on_SendMessage_clicked();
}

void Gui::on_addChatItem(const QString & nickname, QString const & message)
{
  _im_form.Chat->addItem(nickname + ": " + message);
}


} // IM

