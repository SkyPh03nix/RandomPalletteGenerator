#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Button : public sf::Drawable {
private:
    sf::RectangleShape shape;
    sf::Text label;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        target.draw(shape, states);
        target.draw(label, states);
    }

public:
    Button(const sf::Vector2f& pos, const sf::Vector2f& size,
           const std::string& text, const sf::Font& font) 
    {
        shape.setPosition(pos);
        shape.setSize(size);
        shape.setFillColor(sf::Color(0, 0, 0));
        shape.setOutlineColor(sf::Color::White);
        shape.setOutlineThickness(2);

        label.setFont(font);
        label.setString(text);
        label.setCharacterSize(20);
        label.setFillColor(sf::Color::White);

        // Text zentrieren
        sf::FloatRect textBounds = label.getLocalBounds();
        label.setOrigin(textBounds.left + textBounds.width / 2.0f,
                        textBounds.top + textBounds.height / 2.0f);
        label.setPosition(pos.x + size.x / 2.0f, pos.y + size.y / 2.0f);
    }

    bool contains(const sf::Vector2f& point) const {
        return shape.getGlobalBounds().contains(point);
    }

    void setFillColor(const sf::Color& color) {
        shape.setFillColor(color);
    }
};