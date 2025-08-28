#include <Button.h>

    Button::Button(const sf::Vector2f& pos, const sf::Vector2f& size, const std::string& text, const sf::Font& font) {
        shape.setPosition(pos);
        shape.setSize(size);
        shape.setFillColor(sf::Color(0, 0, 0));
        shape.setOutlineColor(sf::Color::White);
        shape.setOutlineThickness(2);

        label.setFont(font);
        label.setString(text);
        label.setCharacterSize(20);
        label.setFillColor(sf::Color::White);

        //center text
        sf::FloatRect textBounds = label.getLocalBounds();
        label.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
        label.setPosition(pos.x + size.x / 2.0f, pos.y + size.y / 2.0f);
    }


    bool Button::contains(const sf::Vector2f& point) const {
        return shape.getGlobalBounds().contains(point);
    }


    void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        target.draw(shape, states);
        target.draw(label, states);
    }


    void Button::handleEvent(const sf::Event& event, const sf::RenderWindow& window) {
        sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

        if (contains(mousePos)) {
            if (!hovered) {
                hovered = true;
                shape.setFillColor(sf::Color(100, 100, 100)); // hover effect
            }

            if (event.type == sf::Event::MouseButtonPressed &&
                event.mouseButton.button == sf::Mouse::Left) 
            {
                if (onClick) onClick();
            }
        } else {
            if (hovered) {
                hovered = false;
                shape.setFillColor(sf::Color(0, 0, 0)); // reset after hover
            }
        }
    }
