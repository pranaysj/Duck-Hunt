#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>

#include "../../Header/Main/GameService.h"
using namespace Main;
int main() {

    GameService *gameService = new GameService();

    //gameService->Ignite();

    //while (gameService->IsRunning())
    //{

    //    gameService->Update();
    //    gameService->Render();
    //}*/

    std::cout << "dvfyucjedw";

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
