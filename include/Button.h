#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <functional>
#include <iostream>

class Button : public sf::Drawable {
private:
    sf::RectangleShape shape;
    sf::Text label;
    std::function<void()> onClick;
    bool hovered = false;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

public:
    Button(const sf::Vector2f& pos, const sf::Vector2f& size, const std::string& text, const sf::Font& font);

    bool contains(const sf::Vector2f& point) const;
    void setFillColor(const sf::Color& color) {shape.setFillColor(color);}
    void setOnClick(const std::function<void()>& callback) {onClick = std::move(callback); std::cout<<__PRETTY_FUNCTION__;}
    void handleEvent(const sf::Event& event, const sf::RenderWindow& window);
};