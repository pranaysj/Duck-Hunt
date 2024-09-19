#pragma once

namespace Enemy {
	class EnemyController;

	class EnemyService {
	private:

		EnemyController* enemyController;

		const float spawnInterval = 2.0f;
		float spwanTimer;

		void UpdateSpawnTimer();
		void ProcessEnemySpawn();

		EnemyController* CreateEnemy();

		void Destory();
	public:
		EnemyService();
		~EnemyService();

		void Initialize();
		void Update();
		void Render();

		void Reset();

		EnemyController* SpawnEnemy();
	};
}