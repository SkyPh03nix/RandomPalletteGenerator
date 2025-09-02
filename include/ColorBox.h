#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>

class ColorBox : public sf::Drawable {
private:
    sf::RectangleShape shape;
    sf::Text text;
    std::string hexColor;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        target.draw(shape, states);
        target.draw(text, states);
    }

public:
    ColorBox(const sf::Vector2f& pos, const sf::Vector2f& size, const sf::Color& color, const sf::Font& font) {
        hexColor = colToHex(color);

        shape.setPosition(pos);
        shape.setSize(size);
        shape.setFillColor(color);
        shape.setOutlineColor(sf::Color::Black);
        shape.setOutlineThickness(1);

        text.setFont(font);
        text.setString(hexColor);
        text.setCharacterSize(14);
        text.setFillColor(sf::Color::White); //TODO change text color based on box color brightness

        centerText();
    }

    void setColor(const sf::Color& color) {
        shape.setFillColor(color);
        hexColor = colToHex(color);
        text.setString(hexColor);
        centerText();
    }

    void centerText() {
        sf::FloatRect textBounds = text.getLocalBounds();
        text.setOrigin(textBounds.left + textBounds.width / 2.f, textBounds.top + textBounds.height / 2.f);
        text.setPosition(
        std::floor(shape.getPosition().x + shape.getSize().x / 2.f),
        std::floor(shape.getPosition().y + shape.getSize().y / 2.f)
    );
    }

    std::string colToHex(const sf::Color& color, bool withAlpha=false)  {
        std::ostringstream ss;
        ss << "#" 
        << std::uppercase << std::hex << std::setfill('0')  << std::hex
        << std::setw(2) << (int)color.r
        << std::setw(2) << (int)color.g
        << std::setw(2) << (int)color.b;

        if (withAlpha) {
            ss << std::setw(2) << (int)color.a;
        }

        return ss.str();
    } 
};