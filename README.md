# Avionics_PFD_System
Künstlicher Horizont (Artificial Horizon) developed with Qt 6 and QML.

Simulationssystem für un **Primary Flight Display (PFD)**, inspiriert von modernen Garmin G1000 Systemen.

## Technische Merkmale
- **Künstlicher Horizont:** Echtzeitberechnung von Längs- (Pitch) und Querneigung (Roll) mittels affiner Transformationen.
- **Geschwindigkeits- und Höhenbänder:** Dynamische Skalen basierend auf `Repeater`-Komponenten für Airspeed und Altitude.
- **Kursanzeiger (Heading):** Horizontaler Magnetkompass mit Anzeige der Himmelsrichtungen.
- **Glättung (Smoothing):** Implementierung von `Behavior` in QML für flüssige Flugdatenbewegungen.

## Zukünftige Entwicklungen
- Integration der C++ Logik zur Berechnung der Flugdynamik.
- Hinzufügung eines Variometers (Vertical Speed Indicator - VSI).
- Implementierung von Warnsystemen (Stall, Overspeed).
