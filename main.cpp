#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <flightdataproxy.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    // flight logic
    FlightDataProxy flightData;

    QQmlApplicationEngine engine;

    // Fondamentale: iniettiamo l'oggetto C++ nel contesto QML
    // "flightData" sarà il nome usato dentro il file Main.qml
    engine.rootContext()->setContextProperty("flightData", &flightData);

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("Avionics_PFD_System", "Main");

    return app.exec();
}
