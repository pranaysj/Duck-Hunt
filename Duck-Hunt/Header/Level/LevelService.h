#pragma once

namespace Level {
	class EnemyService;

	class LevelService {
	private:
		int levels;
		int rounds;
		int wave;
		int ducks;
		int bullets;
		int score;

	public:
		LevelService();
		~LevelService();

		void Initialize();
		void Update();
		void Render();

		void SetLevel(int _level);
		int GetLevel();

		void SetRound(int _round);
		int GetRound();

		void SetDuck(int _duck);
		int GetDuck();

		void SetBullet(int _bullet);
		int GetBullet();

		void SetScore(int _duck);
		int GetScore();

		void SetWave(int _wave);
		int GetWave();
	};
}