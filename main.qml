import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.4

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("VO Data Recorder")
    color: "#f5f5f5"
    Image {
        id: rocket
        anchors.centerIn: parent
        width: 200
        height: 200
        source: "rocket.png"
        fillMode: Image.PreserveAspectFit

        MouseArea {
            anchors.fill: parent
            onClicked: {
                console.log("rocket launch!!!")
            }
        }
    }
}
