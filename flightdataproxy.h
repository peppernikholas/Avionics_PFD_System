#ifndef FLIGHTDATAPROXY_H
#define FLIGHTDATAPROXY_H

#include <QObject>
#include <QTimer>

class FlightDataProxy : public QObject
{
    Q_OBJECT
    // properties to make data visible to QML
    Q_PROPERTY(double pitch READ pitch NOTIFY pitchChanged)
    Q_PROPERTY(double roll READ roll NOTIFY rollChanged)
public:
    explicit FlightDataProxy(QObject *parent = nullptr);

    double pitch() const { return m_pitch; }
    double roll() const { return m_roll; }

public slots:
    void setPitch(double v);
    void setRoll(double v);
    void updateDynamics(); // simulation of loop calculation

signals:
    void pitchChanged();
    void rollChanged();

private:
    double m_pitch = 0.0; // actual value (real)
    double m_roll = 0.0;
    double m_targetPitch = 0.0; // desidered value (pilot's input)
    double m_targetRoll = 0.0;
    QTimer *m_timer;
};

#endif // FLIGHTDATAPROXY_H
