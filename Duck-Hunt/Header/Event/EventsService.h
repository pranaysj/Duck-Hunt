#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

namespace Event {

    enum class ButtonState
    {
        PRESSED,
        HELD,
        RELEASED,
    };

    class EventsService {
    private:

        ButtonState leftMouseButtonState;

        sf::Event gameEvent;
        sf::RenderWindow* gameWindow;

        bool IsGameWindowOpen();
        bool HasQuitGame();
        bool GameWindowWasClosed();

        void UpdateMouseButtonState(ButtonState &_currentButtonState, sf::Mouse::Button _mouseButton);

    public:
        EventsService();
        ~EventsService();

        void Initialize();
        void Update();
        void Render();

        void ProcessEvent();
        bool PressedLeftMouseButton();


    };

}
