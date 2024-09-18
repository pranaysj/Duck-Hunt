#pragma once
#include "../../Header/Global/ServiceLocator.h"

namespace Global {
	ServiceLocator::ServiceLocator()
	{
		graphicsService = nullptr;
	}

	void ServiceLocator::CreateService()
	{
		graphicsService = new Graphics::GraphicService();
	}

	ServiceLocator::~ServiceLocator()
	{
	}

	ServiceLocator* ServiceLocator::GetInstance()
	{
		static ServiceLocator instance;
		return &instance;
	}

	void ServiceLocator::ClearAllService()
	{
	}

	void ServiceLocator::Initialize()
	{
		graphicsService->Initialize();
	}

	void ServiceLocator::Update()
	{
		graphicsService->Update();
	}

	void ServiceLocator::Render()
	{
	}

	Graphics::GraphicService* ServiceLocator::GetGraphicsService()
	{
		return graphicsService;
	}
}
