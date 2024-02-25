#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Scene.h"

using namespace std;

class Leaderboard : public Scene { // Creamos la escena Leaderboard
public:
	Leaderboard(int winnerPoints);
	~Leaderboard();
	
	void ProcessEvents(Game &game, Event &event) override;
	void Update(Game &game) override;
	void Draw(RenderWindow &window) override;
	void SaveDataToFile(const string &filename, const string &name, int points);
	void ShowLeaderboard(const string &filename);
private:
	Font m_f1;
	Text m_t1;
	Text m_t2; // Texto donde se escribira el nombre 
	Text m_t3;
	Text m_t4;
	Text m_t5; // Texto donde se escribiran los puntos
	string currentInput;
	Texture m_tex_background;
	Sprite m_spr_background;
};
