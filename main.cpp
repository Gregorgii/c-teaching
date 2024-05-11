#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>
#include <iostream>
using namespace sf;
using namespace std;
//set krestick

RectangleShape * getKrest(float x,float y){
    static RectangleShape krest[2];
    RectangleShape rectang(Vector2f(120, 4));
    rectang.setFillColor(Color::Red);
    rectang.setPosition(x, y);
    rectang.rotate(45);
    RectangleShape rectang2(Vector2f(120, 4));
    rectang2.setFillColor(Color::Red);
    rectang2.setPosition(x, y+85);
    rectang2.rotate(-45);
    krest[0] = rectang;
    krest[1] = rectang2;
    return krest;
    // 0
}
CircleShape genCircle(float x, float y) {
    CircleShape circle;
    circle.setRadius(60);
    circle.setFillColor(Color::Blue);
    circle.setPosition(x, y);
    return circle;
}
void win(int a[3][3][3]){
    if(a[0][0][0]==a[1][1][0] && a[1][1][0]==a[2][2][0] && a[0][0][0]!=-1 ){
        cout<<"Game over"<<endl;
    }else if(a[0][2][0]==a[1][1][0] && a[1][1][0]==a[2][0][0] && a[1][1][0]!=-1){
        cout<<"Game over"<<endl;
    }
    for(int i=0;i<3;i++){
        if(a[0][i][0]==a[1][i][0]&& a[1][i][0]==a[2][i][0] && a[1][i][0]!=-1 ){
            cout<<"Game over"<<endl;
        }
    }
    for(int i=0;i<3;i++){
        if(a[i][0][0]==a[i][1][0]&& a[i][1][0]==a[i][2][0] && a[i][1][0]!=-1 ){
            cout<<"Game over"<<endl;
        }
    }
}




int main() {

    RenderWindow window(VideoMode(600, 600), "");
    Texture texture;
    Sprite sprite;

    RectangleShape rectang2(Vector2f(120, 4));
    rectang2.setFillColor(Color::Red);
    rectang2.setPosition(350, 435);
    rectang2.rotate(-45);

    RectangleShape recteng3(Vector2f(120, 4));
    recteng3.setFillColor(Color::Red);
    recteng3.setPosition(250, 425);
    recteng3.rotate(-50);
    RectangleShape rectang4(Vector2f(120, 4));
    rectang4.setFillColor(Color::Red);
    rectang4.setPosition(250, 325);
    rectang4.rotate(50);
// eto daska//

    RectangleShape rectangnew1(Vector2f(600,4));
    rectangnew1.setFillColor(Color::Red);
    rectangnew1.setPosition(0,200);

    RectangleShape rectangnew2(Vector2f(600,4));
    rectangnew2.setFillColor(Color::Red);
    rectangnew2.setPosition(0,400);

    RectangleShape rectangnew3(Vector2f(600,4));
    rectangnew3.setFillColor(Color::Red);
    rectangnew3.setPosition(200,0);
    rectangnew3.rotate(90);

    RectangleShape rectangnew4(Vector2f(600,4));
    rectangnew4.setFillColor(Color::Red);
    rectangnew4.setPosition(400,0);
    rectangnew4.rotate(90);






    // setup, здесь пишем то что ывполняетчя один раз при запуске программы
    window.setTitle("privet sasha");
    window.setPosition(Vector2i (1, 1));
    window.setFramerateLimit(60);

    int a[3][3][3]
            {
                    {{-1, 0, 0},{-1, 0, 0},{-1, 0, 0}},
                    {{-1, 0, 0},{-1, 0, 0},{-1, 0, 0}},
                    {{-1, 0, 0},{-1, 0, 0},{-1, 0, 0}}
            };



    int xod = 0;
    while (window.isOpen()){
        Event event;
        while (window.pollEvent(event)){
            if (event.type == Event::Closed){
                window.close();
            }
        }
        // луп, здесь пишем то, что выполняется пока программа запущена

        window.clear(Color::Black);

        Vector2<int> position =  Mouse::getPosition(window);
        if(Mouse::isButtonPressed(Mouse::Left)) {
            if (Mouse::isButtonPressed(Mouse::Left)) {
                if (0 < position.x && position.x < 200 && 0 < position.y && position.y < 200) {
                    a[0][0][0] = xod % 2;
                    xod++;
                    a[0][0][1] = 50;
                    a[0][0][2] = 50;
                    this_thread::sleep_for(std::chrono::milliseconds(500));
                } else if (200 < position.x && position.x < 400 && 0 < position.y && position.y < 200) {
                    a[0][1][0] = xod % 2;
                    xod++;
                    a[0][1][1] = 250;
                    a[0][1][2] = 50;
                    this_thread::sleep_for(std::chrono::milliseconds(500));
                } else if (400 < position.x && position.x < 600 && 0 < position.y && position.y < 200) {
                    a[0][2][0] = xod % 2;
                    xod++;
                    a[0][2][1] = 450;
                    a[0][2][2] = 50;
                    this_thread::sleep_for(std::chrono::milliseconds(500));
                } else if (0 < position.x && position.x < 200 && 200 < position.y && position.y <400){
                    a[1][0][0] = xod % 2;
                    xod++;
                    a[1][0][1] = 50;
                    a[1][0][2] = 250;
                    this_thread::sleep_for(std::chrono::milliseconds(500));
                }else if (200 < position.x && position.x < 400 && 200 < position.y && position.y <400){
                    a[1][1][0] = xod % 2;
                    xod++;
                    a[1][1][1] = 250;
                    a[1][1][2] = 250;
                    this_thread::sleep_for(std::chrono::milliseconds(500));
                }else if (400 < position.x && position.x < 600 && 200 < position.y && position.y <400){
                    a[1][2][0] = xod % 2;
                    xod++;
                    a[1][2][1] = 450;
                    a[1][2][2] = 250;
                    this_thread::sleep_for(std::chrono::milliseconds(500));
                }else if (0 < position.x && position.x < 200 && 400 < position.y && position.y <600){
                    a[2][0][0] = xod % 2;
                    xod++;
                    a[2][0][1] = 50;
                    a[2][0][2] = 450;
                    this_thread::sleep_for(std::chrono::milliseconds(500));
                }else if (200 < position.x && position.x < 400 && 400 < position.y && position.y <600){
                    a[2][1][0] = xod % 2;
                    xod++;
                    a[2][1][1] = 250;
                    a[2][1][2] = 450;
                    this_thread::sleep_for(std::chrono::milliseconds(500));
                }else if (400 < position.x && position.x < 600 && 400 < position.y && position.y <600){
                    a[2][2][0] = xod % 2;
                    xod++;
                    a[2][2][1] = 450;
                    a[2][2][2] = 450;
                    this_thread::sleep_for(std::chrono::milliseconds(500));
                }
            }
        }




        for(int i=0;i<3;i++ ){
            for(int j=0;j<3;j++){
                if(a[i][j][0]==0){
                    window.draw(genCircle(a[i][j][1],a[i][j][2]));
                }else if(a[i][j][0]==1){
                    window.draw(getKrest(a[i][j][1],a[i][j][2])[0]);
                    window.draw(getKrest(a[i][j][1],a[i][j][2])[1]);
                }
            }
        }




        //window.draw(recteng3);
        //window.draw(rectang4);

        window.draw(rectangnew1);
        window.draw(rectangnew2);
        window.draw(rectangnew3);
        window.draw(rectangnew4);

        win(a);



        window.display();
    }

    return 0;
}