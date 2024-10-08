#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Main/GameService.h"

int main() {

   Main::GameService *gameService = new Main::GameService();

    gameService->Ignite();

    while (gameService->IsRunning())
    {

        gameService->Update();
        gameService->Render();
    }

    return 0;

}

//#include <SFML/Graphics.hpp>
//
//int main()
//{
//    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
//    sf::CircleShape shape(100.f);
//    shape.setFillColor(sf::Color::Green);
//
//    while (window.isOpen())
//    {
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//
//        window.clear();
//        window.draw(shape);
//        window.display();
//    }
//
//    return 0;
//}
