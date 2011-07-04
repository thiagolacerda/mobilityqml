#include "accelerometerreader.h"

AccelerometerReader::AccelerometerReader(QObject *parent) :
    QObject(parent), m_xMovement(0), m_yMovement(0)
{
    accelerometer = new QAccelerometer(this);
    accelerometer->start();
    if (!accelerometer->isActive()) {
        qWarning("Accelerometer didn't start!");
    }
    connect(accelerometer, SIGNAL(readingChanged()), this, SLOT(accelerometerDataUpdated()));
}

void AccelerometerReader::accelerometerDataUpdated()
{
    QAccelerometerReading *reading = accelerometer->reading();
    setXMovement(reading->x());
    setYMovement(reading->y());
}

qreal AccelerometerReader::xMovement()
{
    return m_xMovement;
}

void AccelerometerReader::setXMovement(qreal newX)
{
    if (newX != m_xMovement) {
        m_xMovement = newX;
        emit xMovementChanged();
    }
}

qreal AccelerometerReader::yMovement()
{
    return m_yMovement;
}

void AccelerometerReader::setYMovement(qreal newY)
{
    if (newY != m_yMovement) {
        m_yMovement = newY;
        emit yMovementChanged();
    }
}
