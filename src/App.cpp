#include "App.h"
#include <cstdlib>
#include <ctime>
#include "PaletteGenerator.h"

App::App() : window(sf::VideoMode(800,600), "Random Color Palette") {
    if (!font.loadFromFile("assets/arial.ttf")) {
        throw std::runtime_error("Font konnte nicht geladen werden!");
    }

    // Test-Buttons
    std::vector<std::string> labels = {
        "Random", "Analogous", "Monochrome","Oposites", "Save"
    };
    std::vector<std::function<void()>> actions = {
        [this]() {auto colors = generator.generateRandomPalette(8); layoutColorBoxes(colors);},
        [this]() {auto colors = generator.generateAnalogousPalette(8); layoutColorBoxes(colors);},
        [this]() {auto colors = generator.generateMonochromePalette(8); layoutColorBoxes(colors);},
        [this]() {auto colors = generator.generateOpositePalette(8); layoutColorBoxes(colors);}, 
    };

    layoutButtons(labels, actions);

    // random palette on app start
    std::vector<sf::Color> colors;
    colors = generator.generateRandomPalette(8);
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

        colorBoxes.emplace_back(pos, size, colors[i], font);
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
