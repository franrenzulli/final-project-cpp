#pragma once

#include "Scene.h"

class Menu : public Scene {
public:
    Menu();
    void Update(Game &game);
    void Draw(RenderWindow &window);
private:
};