#pragma once
#include <SFML/Graphics.hpp>

class ColorBox : public sf::Drawable {
private:
    sf::RectangleShape shape;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        target.draw(shape, states);
    }

public:
    ColorBox(const sf::Vector2f& pos, const sf::Vector2f& size, const sf::Color& color) {
        shape.setPosition(pos);
        shape.setSize(size);
        shape.setFillColor(color);
        shape.setOutlineColor(sf::Color::Black);
        shape.setOutlineThickness(1);
    }

    void setColor(const sf::Color& color) {
        shape.setFillColor(color);
    }
};