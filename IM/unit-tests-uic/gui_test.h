#ifndef GUI_TEST_H
#define GUI_TEST_H

#include <QtCore/QObject>

class GuiTest : public QObject
{
    Q_OBJECT

private slots:
    void clicking_the_SendMessage_signals_send_message_with_the_message_from_the_input_field();
    void clicking_the_SendMessage_does_not_signal_send_message_when_the_input_field_is_empty();
    void clicking_the_SendMessage_clears_the_input_field_is_empty();
    void entering_the_SendMessage_signals_send_message_with_the_message_from_the_input_field();
    void clicking_the_SendMessage_does_not_signal_send_message_when_no_nickname_set();

    void entering_the_Nickname();

    void clicking_the_AddEvent_signals_send_event_with_the_event_from_the_input_field();
    void clicking_the_AddEvent_does_not_signal_send_event_when_the_input_field_is_empty();
    void clicking_the_AddEvent_clears_the_input_field_is_empty();
    void entering_the_AddEvent_signals_send_event_with_the_event_from_the_input_field();
    void clicking_the_AddEvent_does_not_signal_send_event_when_no_nickname_set();
};

#endif // GUI_TEST_H
