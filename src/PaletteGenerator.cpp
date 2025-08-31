#include "PaletteGenerator.h"
#include "ColorBox.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <random>

std::vector<sf::Color> PaletteGenerator::generateRandomPalette(int count) {
    std::vector<sf::Color> palette;
    palette.reserve(count);

    //random function independent of time
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dis(0, 255);

    for (int i = 0; i < count; ++i) 
        palette.emplace_back(dis(gen), dis(gen), dis(gen));
    return palette;
}

//HSV → RGB (0 <= h < 360, 0 <= s,v <= 1)
sf::Color PaletteGenerator::hsvToRgb(int h, float s, float v) {
    //c = chroma for color intensity
    float c = v * s;
    float x = c * (1 - std::fabs(fmod(h / 60.0f, 2) - 1));
    float m = v - c;

    // calculate 60-degree sector of the color wheel
    float r = 0, g = 0, b = 0;
    if (h < 60)      { r = c; g = x; b = 0; } // red to yellow
    else if (h < 120){ r = x; g = c; b = 0; } // yellow to green
    else if (h < 180){ r = 0; g = c; b = x; } // green to cyan
    else if (h < 240){ r = 0; g = x; b = c; } // cyan to blue
    else if (h < 300){ r = x; g = 0; b = c; } // blue to magenta
    else             { r = c; g = 0; b = x; } // magenta to red

    return sf::Color(
        static_cast<sf::Uint8>((r + m) * 255),
        static_cast<sf::Uint8>((g + m) * 255),
        static_cast<sf::Uint8>((b + m) * 255)
    );
}

std::vector<sf::Color> PaletteGenerator::generateAnalogousPalette(int count) {
    std::vector<sf::Color> colors;

    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> hueDis(0, 359);
    static std::uniform_int_distribution<> stepDist(15, 30);

    int baseHue = hueDis(gen);
    int step = stepDist(gen);

    for (int i = 0; i < count; ++i) {
        int hue = (baseHue + i * step) % 360;
        colors.push_back(hsvToRgb(hue, 0.7f, 0.9f));
    }

    return colors;
}

std::vector<sf::Color> PaletteGenerator::generateMonochromePalette(int count) {
    std::vector<sf::Color> colors;

    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> hueDis(0, 359);
    static std::uniform_real_distribution<float> valDis(0.1f, 0.3f);
    static std::uniform_real_distribution<float> satDis(0.1f, 0.3f);

    int baseHue = hueDis(gen);

    float saturation = 1.0f;
    float value = 1.0f;

    for (int i = 0; i < count; ++i) {
        colors.push_back(hsvToRgb(baseHue, saturation, value));

        saturation -= satDis(gen);
        if(saturation < 0.1f) saturation = 0.1f;

        value -= valDis(gen);
        if (value < 0.1f) value = 0.1f;
    }
    return colors;
}

std::vector<sf::Color> PaletteGenerator::generateTriadPalette(int count) {}

std::vector<sf::Color> PaletteGenerator::generateComplementaryPalette(int count) {}

void PaletteGenerator::savePalette(const std::vector<ColorBox>& boxes, const std::string& filename) {
    if (boxes.empty()) return;
}