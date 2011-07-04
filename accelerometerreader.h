#ifndef ACCELEROMETERREADER_H
#define ACCELEROMETERREADER_H

#include <QObject>
#include <qaccelerometer.h>

QTM_USE_NAMESPACE

class AccelerometerReader : public QObject
{
    Q_OBJECT
public:
    explicit AccelerometerReader(QObject *parent = 0);

    Q_PROPERTY(qreal xMovement READ xMovement WRITE setXMovement NOTIFY xMovementChanged FINAL)
    Q_PROPERTY(qreal yMovement READ yMovement WRITE setYMovement NOTIFY yMovementChanged FINAL)

    qreal xMovement();
    void setXMovement(qreal newX);

    qreal yMovement();
    void setYMovement(qreal newY);

Q_SIGNALS:
    void xMovementChanged();
    void yMovementChanged();

public slots:
    void accelerometerDataUpdated();

private:
    QAccelerometer *accelerometer;
    qreal m_xMovement;
    qreal m_yMovement;
};

#endif // ACCELEROMETERREADER_H
