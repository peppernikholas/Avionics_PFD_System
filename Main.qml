import QtQuick
import QtQuick.Controls

Window {
    width: 800
    height: 600
    visible: true
    title: "Avionics Cockpit Test"
    color: "black"

    // Il tuo codice inizia qui
    Rectangle {
        id: root
        anchors.centerIn: parent // Centra il rettangolo nella finestra
        width: 600
        height: 600
        color: "black"
        clip: true

        property double pitch_angle: flightData.pitch
        property double roll_angle:flightData.roll

        Item {
            id: horizonContainer
            width: parent.width * 2
            height: parent.height * 2
            anchors.centerIn: parent

            transform: Rotation {
                origin.x: horizonContainer.width / 2
                origin.y: horizonContainer.height / 2
                angle: -root.roll_angle
            }

            Rectangle {
                width: parent.width
                height: parent.height / 2
                color: "#0072bc"
                anchors.top: parent.top
            }

            Rectangle {
                width: parent.width
                height: parent.height / 2
                color: "#7a3e02"
                anchors.bottom: parent.bottom
            }

            // --- Pitch Ladder migliorata ---
            Item {
                id: pitchLadder
                anchors.centerIn: parent
                width: parent.width
                height: parent.height

                Repeater {
                    model: 13 // Da -30 a +30 gradi ogni 5
                    delegate: Item {
                        width: parent.width
                        height: 2
                        y: (parent.height / 2) - (degree * 8) // Fattore di scala 8 pixel/grado
                        property int degree: (index - 6) * -5
                        visible: degree !== 0

                        Rectangle {
                            width: Math.abs(degree) % 10 === 0 ? 120 : 60
                            height: 2
                            color: "white"
                            anchors.horizontalCenter: parent.horizontalCenter
                        }

                        Text {
                            text: Math.abs(degree)
                            color: "white"
                            font.pixelSize: 14
                            anchors.left: parent.horizontalCenter
                            anchors.leftMargin: Math.abs(degree) % 10 === 0 ? 70 : 40
                            anchors.verticalCenter: parent.verticalCenter
                        }
                    }
                }
            }

            y: (root.pitch_angle * 5) - (height / 4)
        }

        Rectangle {
            id: aircraftSymbol
            width: 200
            height: 4
            color: "yellow"
            anchors.centerIn: parent
        }

        Column {
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            spacing: 10
            padding: 20

            Text { text: "Pitch (Längs): " + Math.round(root.pitch_angle); color: "white" }
            Slider {
                from: -45; to: 45; //value: 0
                //onMoved: root.pitch_angle = value // Nota: onMoved è meglio di onValueChanged per gli slider
                value: root.pitch_angle
                onMoved: flightData.setPitch(value)
            }

            Text { text: "Roll (Quer): " + Math.round(root.roll_angle); color: "white" }
            Slider {
                from: -90; to: 90; //value: 0
                //onMoved: root.roll_angle = value
                value: root.roll_angle
                onMoved: flightData.setRoll(value)
            }
        }
    }
}
