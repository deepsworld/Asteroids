#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    auto screenWidth = sf::VideoMode::getDesktopMode().width;
    auto screenHeight = sf::VideoMode::getDesktopMode().height;
    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Asteroids");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}