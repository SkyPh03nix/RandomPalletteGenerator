#include "PaletteGenerator.h"
#include "ColorBox.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <ctime>
#include <cstdlib>

std::vector<sf::Color> PaletteGenerator::generateRandomPalette(int count) {
    std::vector<sf::Color> palette;
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    for (int i = 0; i < count; ++i) 
        palette.emplace_back(rand() % 256, rand() % 256, rand() % 256);
    return palette;
}

std::vector<sf::Color> PaletteGenerator::generateAnalogousPalette(int count) {
    std::vector<sf::Color> colors;
    int baseHue = rand() % 360;
    //TODO: Implement analogous color generation
    return colors;
}

std::vector<sf::Color> PaletteGenerator::generateMonochromePalette(int count) {}

std::vector<sf::Color> PaletteGenerator::generateTriadPalette(int count) {}

std::vector<sf::Color> PaletteGenerator::generateComplementaryPalette(int count) {}

void PaletteGenerator::savePalette(const std::vector<ColorBox>& boxes, const std::string& filename) {
    if (boxes.empty()) return;
}