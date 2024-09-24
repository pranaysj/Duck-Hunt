#pragma once
#include"../../Header/Graphics/GraphicsService.h"
#include"../../Header/Event/EventsService.h"
#include"../../Header/Time/TimeService.h"
#include"../../Header/Enemy/EnemyService.h"

namespace Global {

    class ServiceLocator {
    private:

        Graphics::GraphicService* graphicsService;
        Event::EventsService* eventService;
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
        Event::EventsService* GetEventService();
        Time::TimeService* GetTimeService();
        Enemy::EnemyService* GetEnemyService();
    };
}
