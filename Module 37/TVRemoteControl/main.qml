import QtQuick
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Layouts

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("TV Remote Control")

    Rectangle {
        id: rectangel_window
        width: Window.width
        height: Window.height
        border.color: "black"
        GridLayout {
            id: grid_win
            Layout.fillWidth: true
            rows: 5
            GridLayout {
                id: grid_window
                columns: 3
                rows: 4
                Button {
                    id: button_one
                    text: "1"
                    font.pixelSize: 20
                    leftPadding: 10
                    implicitHeight: 50
                    Layout.preferredWidth: rectangel_window.width / grid_window.columns
                    onClicked: _mainwindow.setButtonClicckedNumChannel(text)
                }
                Button {
                    id: button_two
                    text: "2"
                    font.pixelSize: 20
                    implicitHeight: 50
                    Layout.preferredWidth: rectangel_window.width / grid_window.columns
                    onClicked: _mainwindow.setButtonClicckedNumChannel(text)
                }
                Button {
                    id: button_tree
                    text: "3"
                    font.pixelSize: 20
                    implicitHeight: 50
                    Layout.preferredWidth: rectangel_window.width / grid_window.columns
                    onClicked: _mainwindow.setButtonClicckedNumChannel(text)
                }
                Button {
                    id: button_four
                    text: "4"
                    font.pixelSize: 20
                    implicitHeight: 50
                    Layout.preferredWidth: rectangel_window.width / grid_window.columns
                    onClicked: _mainwindow.setButtonClicckedNumChannel(text)
                }
                Button {
                    id: button_five
                    text: "5"
                    font.pixelSize: 20
                    implicitHeight: 50
                    Layout.preferredWidth: rectangel_window.width / grid_window.columns
                    onClicked: _mainwindow.setButtonClicckedNumChannel(text)
                }
                Button {
                    id: button_six
                    text: "6"
                    font.pixelSize: 20
                    implicitHeight: 50
                    Layout.preferredWidth: rectangel_window.width / grid_window.columns
                    onClicked: _mainwindow.setButtonClicckedNumChannel(text)
                }
                Button {
                    id: button_seven
                    text: "7"
                    font.pixelSize: 20
                    implicitHeight: 50
                    Layout.preferredWidth: rectangel_window.width / grid_window.columns
                    onClicked: _mainwindow.setButtonClicckedNumChannel(text)
                }
                Button {
                    id: button_eight
                    text: "8"
                    font.pixelSize: 20
                    implicitHeight: 50
                    Layout.preferredWidth: rectangel_window.width / grid_window.columns
                    onClicked: _mainwindow.setButtonClicckedNumChannel(text)
                }
                Button {
                    id: button_nine
                    text: "9"
                    font.pixelSize: 20
                    implicitHeight: 50
                    Layout.preferredWidth: rectangel_window.width / grid_window.columns
                    onClicked: _mainwindow.setButtonClicckedNumChannel(text)
                }
                Button {
                    id: button_zero
                    text: "0"
                    Layout.column: 1
                    Layout.row: 4
                    font.pixelSize: 20
                    implicitHeight: 50
                    Layout.preferredWidth: rectangel_window.width / grid_window.columns
                    onClicked: _mainwindow.setButtonClicckedNumChannel(text)
                }
            }
            RowLayout {
                id: row_volPrew
                spacing: 5
                Layout.row: 2
                Button {
                    id: button_plus
                    text: "+"
                    font.pixelSize: 20
                    implicitHeight: 50
                    Layout.preferredWidth: rectangel_window.width / 2
                    onClicked: _mainwindow.setButtonClicckedChannel(text)
                }
                Button {
                    id: button_plusVol
                    text: "+"
                    font.pixelSize: 20
                    implicitHeight: 50
                    Layout.preferredWidth: rectangel_window.width / 2
                    onClicked: _mainwindow.setButtonClicckedVolume(text)
                }
            }
            RowLayout {
                spacing: 5
                Layout.row: 3
                Text {
                    text:"Volume"
                    font.pixelSize: 20
                    height: 50
                    horizontalAlignment: Text.AlignHCenter
                    Layout.preferredWidth: rectangel_window.width / 2
                }
                Text {
                    text: "Channel"
                    font.pixelSize: 20
                    height: 50
                    horizontalAlignment: Text.AlignHCenter
                    Layout.preferredWidth: rectangel_window.width / 2
                }
            }
            RowLayout {
                spacing: 5
                Layout.row: 4
                Button {
                    id: button_minus
                    text: "-"
                    font.pixelSize: 20
                    implicitHeight: 50
                    Layout.preferredWidth: rectangel_window.width / 2
                    onClicked: _mainwindow.setButtonClicckedChannel(text)
                }
                Button {
                    id: button_minusVol
                    text: "-"
                    font.pixelSize: 20
                    implicitHeight: 50
                    Layout.preferredWidth: rectangel_window.width / 2
                    onClicked: _mainwindow.setButtonClicckedVolume(text)
                }
            }

            TextField {
                text: _mainwindow.text_field_status
                activeFocusOnPress: false
                Layout.row: 5
                Layout.leftMargin: 5
                font.pixelSize: 30
                implicitHeight: 50
                Layout.preferredWidth: rectangel_window.width - 10
            }
        }
    }
}
