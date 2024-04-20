#include <SFML/Graphics.hpp>
#include <cmath>
using namespace sf;
int main()
{
    sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!");
    RectangleShape line1(Vector2f(150, 3));
    line1.setPosition(-75.f/sqrt(2) + 200, -75.f/sqrt(2) + 200);
    line1.rotate(45);
    RectangleShape line2(Vector2f(150, 3));
    line2.setPosition( -75.f/sqrt(2) + 200,  75.f/sqrt(2) + 200);
    line2.rotate(-45);

    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(line1);
        window.draw(line2);
        window.display();
    }

    return 0;
}