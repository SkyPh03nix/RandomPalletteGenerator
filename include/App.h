#pragma once

#include <SFML/Graphics.hpp>
#include "Button.h"
#include "ColorBox.h"
#include <vector>
#include <string>
#include "PaletteGenerator.h"

class App {
private:
    sf::RenderWindow window;
    sf::Font font;
    std::vector<Button> buttons;
    std::vector<ColorBox> colorBoxes;
    std::vector<sf::Color> currentPalette;
    PaletteGenerator generator;

    void layoutColorBoxes(const std::vector<sf::Color>& colors);
    void layoutButtons(const std::vector<std::string>& labels, const std::vector<std::function<void()>>& actions);

public:
    App();
    void run();
};
