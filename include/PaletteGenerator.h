#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

class PaletteGenerator {
public:
    // Farbpaletten-Methoden
    std::vector<sf::Color> generateRandomPalette(int count = 5);
    std::vector<sf::Color> generateAnalogousPalette(int count = 5);
    std::vector<sf::Color> generateMonochromePalette(int count = 5);
    std::vector<sf::Color> generateTriadPalette(int count = 5);
    std::vector<sf::Color> generateComplementaryPalette(int count = 5);

    // Palette speichern
    void savePalette(const std::vector<class ColorBox>& boxes, const std::string& filename = "palette.png");

private:
    static sf::Color hsvToRgb(int h, float s, float v);
};