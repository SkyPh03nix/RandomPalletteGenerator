# Random Color Palette Generator

Ein einfacher **Random Color Palette Generator** in **C++** mit **SFML**.  
Das Programm erzeugt Farbfelder basierend auf verschiedenen Farbmodi (z.B. Random, Komplementär, Analog) und zeigt deren Hex-Codes an. Ein Klick auf ein Farbfeld kopiert den Hex-Code in die Zwischenablage.

---

## Features

- Erzeugung von Farbpaletten in unterschiedlichen Modi:
  - Random (zufällige Farben)
  - Komplementär
  - Analog
  - Triade
  - Tetrade
  - Monochrom
- Farbfelder werden dynamisch angezeigt, basierend auf der gewählten Anzahl (1–10 Farben)
- Hex-Code-Anzeige für jede Farbe
- Klick auf Farbfeld kopiert Hex-Code in die Zwischenablage
- Minimalistisches GUI mit SFML

---

## Projektstruktur

RandomColorPalette/
│
├── include/ 
│ ├── App.hpp
│ ├── Button.hpp
│ ├── Dropdown.hpp
│ ├── ColorBox.hpp
│ └── PaletteGenerator.hpp
│
├── src/ 
│ ├── main.cpp
│ ├── App.cpp
│ ├── Button.cpp
│ ├── Dropdown.cpp
│ ├── ColorBox.cpp
│ └── PaletteGenerator.cpp
│
├── assets/ 
│ └── font.ttf
├── build/ 
├── Makefile
└── .gitignore