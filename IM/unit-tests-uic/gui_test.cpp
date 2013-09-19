#include <QtTest/QTest>
#include <QtTest/QSignalSpy>

#include <../application-uic/ui_im_form.h>
#include <application-uic/gui.h>

#include "gui_test.h"

void GuiTest::clicking_the_SendMessage_signals_send_message_with_the_message_from_the_input_field()
{
    // arrange
    Ui::ImForm im_form;
    IM::Gui testee(im_form);

    QSignalSpy signal_spy(&testee, SIGNAL(send_message(QString const &)));

    QString const expected_message = "Hello world.";
    im_form.MessageInput->setText(expected_message);
    im_form.Nickname->setText("Nickname");
    QTest::keyPress(im_form.Nickname, Qt::Key_Enter);
    QTest::keyRelease(im_form.Nickname, Qt::Key_Enter);

    // act
    QTest::mouseClick(im_form.SendMessage, Qt::LeftButton);

    // assert
    QCOMPARE(signal_spy.count(), 1);

    const auto arguments = signal_spy.takeFirst();
    QCOMPARE(arguments.size(), 1);
    QCOMPARE(arguments.at(0).toString(), expected_message);
}

void GuiTest::clicking_the_SendMessage_does_not_signal_send_message_when_the_input_field_is_empty()
{
    // arrange
    Ui::ImForm im_form;
    IM::Gui testee(im_form);

    QSignalSpy signal_spy(&testee, SIGNAL(send_message(QString const &)));

    im_form.MessageInput->clear();

    // act
    QTest::mouseClick(im_form.SendMessage, Qt::LeftButton);

    // assert
    QCOMPARE(signal_spy.count(), 0);
}

void GuiTest::clicking_the_SendMessage_clears_the_input_field_is_empty()
{
    // arrange
    Ui::ImForm im_form;
    IM::Gui testee(im_form);

    QSignalSpy signal_spy(&testee, SIGNAL(send_message(QString const &)));

    QString const expected_message = "Hello world.";
    im_form.MessageInput->setText(expected_message);
    im_form.Nickname->setText("Nickname");
    QTest::keyPress(im_form.Nickname, Qt::Key_Enter);
    QTest::keyRelease(im_form.Nickname, Qt::Key_Enter);

    // act
    QTest::mouseClick(im_form.SendMessage, Qt::LeftButton);
    // assert
    QVERIFY(im_form.MessageInput->text().isEmpty());
}
