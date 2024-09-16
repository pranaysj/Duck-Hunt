#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Global/ServiceLocator.h"

namespace Main {

    enum class GameState {
        GAMEPLAY,
    };

    class GameService {
    private:
        static GameState currentState;

        Global::ServiceLocator* serviceLocator;
        //sf::RenderWindow* gameWindow;

        void Initialize();
        void InitializeVariable();
        //void ShowSplashScreen();
        void Destory();

    public:
        GameService();
        virtual ~GameService();

        void Ignite();
        void Update();
        void Render();
        bool IsRunning();

        static void SetGameState(GameState _state);
        static GameState GetGameState();
    };
}
