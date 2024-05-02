#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <array>
using namespace sf;
using namespace std;


RectangleShape * genKrest(float x, float y) {
    static RectangleShape  r[2];
    RectangleShape line1(Vector2f(150, 3));
    line1.setPosition(-75.f / sqrt(2) + x, -75.f / sqrt(2) + y);
    line1.rotate(45);
    RectangleShape line2(Vector2f(150, 3));
    line2.setPosition(-75.f / sqrt(2) + x, 75.f / sqrt(2) + y);
    line2.rotate(-45);
    r[0] = line1;
    r[1] = line2;
    return r;
}

CircleShape genCircle(float x, float y) {
    CircleShape circle;
    circle.setRadius(60);
    circle.setFillColor(Color::Blue);
    circle.setPosition(x, y);
    return circle;
}

RectangleShape * genPole(){
    static RectangleShape  r[4];
    RectangleShape line1(Vector2f(400, 1));
    line1.setPosition(133, 0);
    line1.rotate(90);
    RectangleShape line2(Vector2f(400, 1));
    line2.setPosition(266, 0);
    line2.rotate(90);
    RectangleShape line3(Vector2f(400, 1));
    line3.setPosition(0, 133);
    RectangleShape line4(Vector2f(400, 1));
    line4.setPosition(0, 266);
    r[0] = line1;
    r[1] = line2;
    r[2] = line3;
    r[3] = line4;
    return r;
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!");


    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        Vector2<int> localPosition = Mouse::getPosition(window);

        if (Mouse::isButtonPressed(Mouse::Left))
        {
            window.draw(genKrest(localPosition.x, 50.f)[0]);
            window.draw(genKrest(localPosition.x, 50.f)[1]);

            window.draw(genKrest(200.f, 50.f)[0]);
            window.draw(genKrest(200.f, 50.f)[1]);

            window.draw(genKrest(350.f, 50.f)[0]);
            window.draw(genKrest(350.f, 50.f)[1]);

            window.draw(genCircle(200.f-60, 200.f-60));
        }





        window.draw(genPole()[0]);
        window.draw(genPole()[1]);
        window.draw(genPole()[2]);
        window.draw(genPole()[3]);

//        window.draw(genKrest(50.f, 50.f)[0]);
//        window.draw(genKrest(50.f, 50.f)[1]);
//
//        window.draw(genKrest(200.f, 50.f)[0]);
//        window.draw(genKrest(200.f, 50.f)[1]);
//
//        window.draw(genKrest(350.f, 50.f)[0]);
//        window.draw(genKrest(350.f, 50.f)[1]);

//        CircleShape circ1(60);
//        circ1.setPosition(Vector2f(0, 0));
//        window.draw(circ1);
//
//        CircleShape circ2(60);
//        circ2.setPosition(Vector2f(140, 0));
//        window.draw(circ2);
//
//        CircleShape circ3(60);
//        circ3.setPosition(Vector2f(280, 0));
//        window.draw(circ3);
//
//
//        window.draw(genKrest(50.f, 200.f)[0]);
//        window.draw(genKrest(50.f, 200.f)[1]);
//
//        window.draw(genKrest(200.f, 200.f)[0]);
//        window.draw(genKrest(200.f, 200.f)[1]);
//
//        window.draw(genKrest(350.f, 200.f)[0]);
//        window.draw(genKrest(350.f, 200.f)[1]);
//
//
//
//
//        window.draw(genKrest(50.f, 350.f)[0]);
//        window.draw(genKrest(50.f, 350.f)[1]);
//
//        window.draw(genKrest(200.f, 350.f)[0]);
//        window.draw(genKrest(200.f, 350.f)[1]);
//
//        window.draw(genKrest(350.f, 350.f)[0]);
//        window.draw(genKrest(350.f, 350.f)[1]);
        window.display();
    }

    return 0;
}

