#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

namespace Event {

    class EventService {
    private:

        sf::Event gameEvent;
        sf::RenderWindow* gameWindow;

        bool IsGameWindowOpen();
        bool HasQuitGame();
        bool GameWindowWasClosed();

    public:
        EventService();
        ~EventService();

        void Initialize();
        void Update();
        void Render();
        void ProcessEvent();

    };

}
