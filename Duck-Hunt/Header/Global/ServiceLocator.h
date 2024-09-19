#pragma once
#include"../../Header/Graphics/GraphicsService.h"
#include"../../Header/Event/EventService.h"
#include"../../Header/Time/TimeService.h"
#include"../../Header/Enemy/EnemyService.h"

namespace Global {

    class ServiceLocator {
    private:

        Graphics::GraphicService* graphicsService;
        Event::EventService* eventService;
        Time::TimeService* timeService;
        Enemy::EnemyService* enemySevice;

        ServiceLocator();
        ~ServiceLocator();

        void CreateService();
        void ClearAllService();

    public:
        static ServiceLocator* GetInstance();

        void Initialize();
        void Update();
        void Render();

        Graphics::GraphicService* GetGraphicsService();
        Event::EventService* GetEventService();
        Time::TimeService* GetTimeService();
        Enemy::EnemyService* GetEnemyService();
    };
}
