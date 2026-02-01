# Avionics_PFD_System
Künstlicher Horizont (Artificial Horizon) developed with Qt 6 and QML.

Simulationssystem für un **Primary Flight Display (PFD)**, inspiriert von modernen Garmin G1000 Systemen.

## Technische Merkmale
- **Künstlicher Horizont:** Echtzeit-Visualisierung von Pitch und Roll durch optimierte QML-Transformationen.
- **Geschwindigkeits- und Höhenbänder:** Dynamische Skalen basierend auf `Repeater`-Komponenten für Airspeed und Altitude.
- **Kursanzeiger (Heading):** Horizontaler Magnetkompass mit Anzeige der Himmelsrichtungen.
- **Inertiale Glättung (Smoothing):** Implementierung von `Behavior` in QML für flüssige Flugdatenbewegungen.
- **C++ Backend Integration:** Berechnung der Flugdynamik in C++ zur Gewährleistung von Performance und Determinismus, entkoppelt von der GUI-Logik.
- **Data Binding:** Effiziente Kommunikation zwischen C++ Kern und QML-Frontend über das Qt-Property-System (Signal/Slot-Mechanismus).

# Software-Architektur
In Übereinstimmung mit DO-178C Prinzipien ist das System in zwei Hauptebenen unterteilt:
- **Application Layer (QML/Qt Quick):** Verantwortlich für das Rendering der Instrumente und die Benutzerinteraktion.
- **Logic Layer (C++):** Beinhaltet das FlightDataProxy-Modell. Hier findet die Datenverarbeitung statt, was eine isolierte Testbarkeit (Unit Testing) der Flugphysik ermöglicht.

## Zukünftige Entwicklungen
- Separation of Concerns: Vollständige Kapselung der Aerodynamik-Gleichungen in eine reine C++ Bibliothek (ohne Qt-Abhängigkeit) für formale Verifizierung.
- VSI & Heading: Erweiterung des Backends um vertikale Geschwindigkeit und magnetischen Kurs.
- DO-178C Compliance: Einführung von Traceability-Matrix-Kommentaren und automatisierten Test-Suiten.
