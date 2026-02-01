#include "flightdataproxy.h"
#include <QtMath>

FlightDataProxy::FlightDataProxy(QObject *parent) : QObject(parent) {
    // Timer per simulare il loop di aggiornamento avionico (es. 50Hz = 20ms)
    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, this, &FlightDataProxy::updateDynamics);
    m_timer->start(20);
}

void FlightDataProxy::setPitch(double v) {
    if (m_pitch == v) return;
    //m_pitch = v;
    m_targetPitch = v;
    emit pitchChanged();
}

void FlightDataProxy::setRoll(double v) {
    if (m_roll == v) return;
    //m_roll = v;
    m_targetRoll = v;
    emit rollChanged();
}

void FlightDataProxy::updateDynamics() {
    // Esempio: facciamo oscillare il pitch lentamente per testare il PFD
    // In futuro, qui chiamerai le tue equazioni differenziali di volo
/*
    static double time = 0;
    time += 0.02;

    m_pitch = 10.0 * qSin(time); // Oscilla tra -10 e +10 gradi
    m_roll = 15.0 * qCos(time);  // Oscilla tra -15 e +15 gradi
*/
    // Delta Time (20ms come definito nel timer)
    const double dt = 0.02;

    // Parametro di "reattività" (in un sistema reale verrebbe dai requisiti)
    const double responsiveness = 2.0;

    // Simulazione di un filtro passa-basso (inerzia)
    // L'aereo "insegue" il valore impostato dallo slider (target)
    // m_pitch è il valore attuale, m_targetPitch è quello dello slider

    double pitch_error = m_targetPitch - m_pitch;
    m_pitch += pitch_error * responsiveness * dt;

    double roll_error = m_targetRoll - m_roll;
    m_roll += roll_error * responsiveness * dt;

    // Notifichiamo il QML che i valori sono cambiati
    emit pitchChanged();
    emit rollChanged();
}
