import QtQuick 2.0

Rectangle {
    width: 320
    height: 480

    Rectangle {
        id: nick_frame

        anchors.left: parent.left
        anchors.top: parent.top

        anchors.margins: 4

        width: 256
        height: 24

        border { color: "black"; width: 1 }
        color: "lightgrey"

        TextInput {
            anchors.fill: parent

            id: nick_name
            focus: true

            text: ui_controller.nickname
        }
    }


    Rectangle {

        anchors.right: parent.right
        anchors.top: parent.top

        anchors.margins: 4

        width: 52
        height: 24

        border { color: "black"; width: 1 }

        Text {
            anchors.centerIn: parent
            text: "change"
        }

        MouseArea {
            anchors.fill: parent
            onClicked : ui_controller.nickname = nick_name.text;
        }
    }

    Rectangle {
        id: console_frame

        anchors.left: parent.left
        anchors.top: nick_frame.bottom

        anchors.margins: 4

        width: parent.width - 8
        height: 320

        border { color: "black"; width: 1 }

        Text {
            id: text_console
            text: "..."
        }
    }

    Rectangle {

        anchors.left: parent.left
        anchors.top: console_frame.bottom

        anchors.margins: 4

        width: 256
        height: 24


        border { color: "black"; width: 1 }
        color: "lightgrey"

        TextInput {
            anchors.fill: parent

            id: message
            focus: true
        }
    }

    Rectangle {

        anchors.right: parent.right
        anchors.top: console_frame.bottom

        anchors.margins: 4

        width: 52
        height: 24

        border { color: "black"; width: 1 }

        Text {
            anchors.centerIn: parent
            text: "send"
        }
        
        MouseArea {
            anchors.fill: parent
            onClicked: ui_controller.send_message(message.text)
        }
    }

    Rectangle {
        anchors.left: parent.left
        anchors.bottom: parent.bottom

        anchors.margins: 4

        width: parent.width - 8
        height: 24

        border { color: "black"; width: 1 }

        Text {
            anchors.centerIn: parent
            text: "exit"
        }

        MouseArea {
            anchors.fill: parent
            onClicked: Qt.quit()
        }
    }
}

