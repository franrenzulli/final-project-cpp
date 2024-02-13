#pragma once

#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Scene.h"

class Menu : public Scene {
public:
    Menu();
    ~Menu();

    void ProcessEvents(Game &game, Event &event) override;
    void Update(Game &game) override;
    void Draw(RenderWindow &window) override;
private:
	Font m_f1;
	Text m_t1;
	Texture m_tex_background;
	Sprite m_spr_background;
};
