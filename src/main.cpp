#include <iostream>
#include <SFML/Graphics.hpp>

#include <asteroids.hpp>

int main()
{
    // globally enable antialiasing, make the edges of shapes smoother
    // (if supported by the grahpics card)
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    // get desktop width and height
    auto screenWidth = sf::VideoMode::getDesktopMode().width;
    auto screenHeight = sf::VideoMode::getDesktopMode().height;

    // init window
    sf::RenderWindow window(
        sf::VideoMode(screenWidth, screenHeight),
        "Asteroids",
        sf::Style::Default,
        settings);

    sf::CircleShape spaceship(0.02f * screenWidth, 3);
    spaceship.setFillColor(sf::Color::Green);
    spaceship.setOrigin(sf::Vector2f(spaceship.getRadius(), spaceship.getRadius()));
    spaceship.setPosition(sf::Vector2f(screenWidth / 2.0f - spaceship.getRadius(), screenHeight / 2.0f - spaceship.getRadius()));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);
        window.draw(spaceship);
        window.display();
    }

    return EXIT_SUCCESS;
}