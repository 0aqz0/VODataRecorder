import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.4
import Z 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("VO Data Recorder")
    color: "#f5f5f5"
    UDPReceiver{
        id: udpReceiver
    }

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
    Text {
        id: time
        anchors.top: rocket.bottom
        anchors.horizontalCenter: rocket.horizontalCenter
        text: udpReceiver.time()
        font.pixelSize: 30
    }
    Text {
        id: recording
        anchors.top: time.bottom
        anchors.topMargin: 15
        anchors.horizontalCenter: time.horizontalCenter
        text: "RECORD STOPPED!!!"
        font.pixelSize: 20
    }

    Timer {
        interval: 20
        running: true
        repeat: true
        onTriggered: {
            time.text = udpReceiver.time()
            if(udpReceiver.isRecording()){
                recording.text = "RECORDING"
                recording.color = "#87ceeb"
            }
            else
                recording.text = "RECORD STOPPED!!!"
                recording.color = "#ff0000"
        }
    }
}
