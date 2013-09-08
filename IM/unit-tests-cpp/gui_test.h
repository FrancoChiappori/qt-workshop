#ifndef GUI_TEST_H
#define GUI_TEST_H

#include <QtCore/QObject>

class GuiTest : public QObject
{
    Q_OBJECT

private slots:
    void clicking_the_send_button_signals_send_message_with_the_message_from_the_input_field();
    void clicking_the_send_button_does_not_signal_send_message_when_the_input_field_is_empty();
    void clicking_the_send_button_clears_the_input_field_is_empty();
};

#endif // GUI_TEST_H
