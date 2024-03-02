#ifndef PLAYERPICKER_H
#define PLAYERPICKER_H

#include "Scene.h"

class PlayerPicker: public Scene {
public:
	PlayerPicker();
	void ProcessEvents(Game &game, Event &event) override;
	void Update(Game &game) override;
	void Draw(RenderWindow &window) override;
private:
	Texture m_text_background;
	Sprite m_spr_background;
};

#endif

