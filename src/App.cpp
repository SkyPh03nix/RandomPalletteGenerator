#include "App.h"
#include <cstdlib>
#include <ctime>
#include "PaletteGenerator.h"

App::App() : window(sf::VideoMode(800,600), "Random Color Palette") {
    font.loadFromFile("assets/arial.ttf");

    // Test-Buttons
    std::vector<std::string> labels = {
        "Random", "Analogous", "Monochrome",
        "Oposites", "Save"
    };
    std::vector<std::function<void()>> actions = {
        [this]() {auto colors = generator.generateRandomPalette(8); layoutColorBoxes(colors);}, //TODO change functions to fit button labels
        [this]() {auto colors = generator.generateAnalogousPalette(8); layoutColorBoxes(colors);},
        [this]() {auto colors = generator.generateMonochromePalette(8); layoutColorBoxes(colors);},
        [this]() {auto colors = generator.generateTriadPalette(8); layoutColorBoxes(colors);},
        [this]() {auto colors = generator.generateRandomPalette(); layoutColorBoxes(colors);}
    };

    layoutButtons(labels, actions);

    // Test-Palette (random colors)
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    std::vector<sf::Color> colors;
    for (int i = 0; i < 5; i++) {
        colors.push_back(sf::Color(rand()%256, rand()%256, rand()%256));
    }
    layoutColorBoxes(colors);
}

void App::layoutColorBoxes(const std::vector<sf::Color>& colors) {
    colorBoxes.clear();

    float winWidth  = window.getSize().x;
    float winHeight = window.getSize().y;

    float colorAreaHeight = winHeight * (5.0f / 6.0f); // obere 5/6 für Farben
    float boxWidth  = winWidth / static_cast<float>(colors.size());
    
    for (size_t i = 0; i < colors.size(); ++i) {
        sf::Vector2f pos(i * boxWidth, 0);
        sf::Vector2f size(boxWidth, colorAreaHeight);

        colorBoxes.emplace_back(pos, size, colors[i]);
    }
}

void App::layoutButtons(const std::vector<std::string>& labels, const std::vector<std::function<void()>>& actions) {
    buttons.clear();

    float winWidth  = window.getSize().x;
    float winHeight = window.getSize().y;

    float buttonAreaY = winHeight * (5.0f / 6.0f);
    float buttonHeight = winHeight / 6.0f;
    float buttonWidth = winWidth / static_cast<float>(labels.size());

    for (size_t i = 0; i < labels.size(); ++i) {
        sf::Vector2f pos(i * buttonWidth, buttonAreaY);
        sf::Vector2f size(buttonWidth, buttonHeight);

        buttons.emplace_back(pos, size, labels[i], font);

        if (i < actions.size()) {
            buttons.back().setOnClick(actions[i]);
        }
    }
}

void App::run() {
    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                window.close();
            else if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();

            // Buttons Events
            for (auto& btn : buttons)
                btn.handleEvent(event, window);
        }

        window.clear(sf::Color::Black);

        // draw color boxes
        for (auto& box : colorBoxes)
            window.draw(box);

        // draw buttons
        for (auto& btn : buttons)
            window.draw(btn);

        window.display();
    }
}
