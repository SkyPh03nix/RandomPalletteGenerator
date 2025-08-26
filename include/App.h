#pragma once

#include <SFML/Graphics.hpp>
#include "Button.h"
#include "Dropdown.h"
#include "ColorBox.h"
#include "PaletteGenerator.h"
#include <vector>

class App {
private:
    sf::RenderWindow window;
    sf::Font font;
    std::vector<Button> buttons;
    Dropdown dropdown;
    std::vector<ColorBox> colorBoxes;
    std::vector<sf::Color> currentPalette;

    void layoutColorBoxes();
    void handleMouseClick(const sf::Vector2f& mousePos);
public:
    App() : window(sf::VideoMode(800,600), "Random Color Palette") {
        font.loadFromFile("assets/arial.ttf");
    }
    void run() {
        while(window.isOpen()) {
            sf::Event event;
            while(window.pollEvent(event)) {
                if(event.type == sf::Event::Closed)
                    window.close();
                else if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                    window.close();
            }
            window.clear(sf::Color::Black);
            window.display();
        }
    }
};