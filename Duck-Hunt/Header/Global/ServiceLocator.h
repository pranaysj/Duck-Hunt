#pragma once
#include"../../Header/Graphics/GraphicsService.h"

namespace Global {

    class ServiceLocator {
    private:

        Graphics::GraphicService* graphicsService;

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
    };
}
