import QtQuick 1.0

Rectangle {
    id: topLevel
    anchors.fill: parent
    color: "grey"
    x: 0
    y: 0

    Rectangle {
        id: ball
        height: 50
        width: 50
        color: "red"
        radius: 100
    }

    Connections {
        target: accelerometerReader
        onXMovementChanged: {
            if (ball.x != accelerometerReader.xMovement) {
                var temp = ball.x + (accelerometerReader.xMovement)*(-1)
                if (temp < 0)
                    temp = 0;
                else if ((temp + ball.width) > topLevel.width)
                    temp = topLevel.width - ball.width
                ball.x = temp
            }
        }

        onYMovementChanged: {
            if (ball.y != accelerometerReader.yMovement) {
                var temp = ball.y + accelerometerReader.yMovement
                if (temp < 0)
                    temp = 0;
                else if ((temp + ball.height) > topLevel.height)
                    temp = topLevel.height - ball.height
                ball.y = temp
            }
        }
    }
}
