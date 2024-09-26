#pragma once

#include "../../Header/Event/EventsService.h"
#include "../../Header/Level/LevelService.h"

namespace Enemy {
	class EnemyController;
	class LevelService;

	class EnemyService {
	private:
		std::vector<EnemyController*> birdList;

		EnemyController* enemyController;
		Level::LevelService* levelService;

	public:
		EnemyService();
		~EnemyService();

		void Initialize();
		void Update();
		void Render();

		EnemyController* SpawnBird();

	};
}