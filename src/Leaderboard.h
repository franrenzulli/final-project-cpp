#pragma once

#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Scene.h"

using namespace std;


// Struct utilizado para lectura/escritura de los datos a un archivo binario
struct PlayerData {
	char name[12]; 
	int score;
	int totalWins;
};

bool operator<(const PlayerData &uno, const PlayerData &otro);

class Leaderboard : public Scene { // Creamos la escena Leaderboard
public:
	Leaderboard(string fname, int winnerPoints, bool allowSaving);
	~Leaderboard();
	
	void ProcessEvents(Game &game, Event &event) override;
	void Update(Game &game) override;
	void Draw(RenderWindow &window) override;
	void SaveDataToFile(const string &filename);
	void LoadDataFromFile(const string &filename);
private:
	Font m_f1;
	Text m_t1;
	Text m_t2; // Texto donde se escribira el nombre 
	Text m_t3;
	Text m_t4;
	Text m_t5; // Texto donde se escribiran los puntos
	Text m_t6;
	Text m_name, m_points, m_totalWins;
	RectangleShape button1;
	string currentInput;
	Texture m_tex_background;
	Sprite m_spr_background;	
	int m_winnerPoints;
	vector<PlayerData> m_leaders; // almacena los jugadores con sus puntajes, etc.
	string m_filename;
	bool m_scoreSaved;
	bool allowSaving;
};


