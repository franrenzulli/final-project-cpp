#pragma once

#include "Scene.h"

class Menu : public Scene {
public:
    Menu();
    ~Menu();

    void ProcessEvents(Game &game, Event &event) override;
    void Update(Game &game) override;
    void Draw(RenderWindow &window) override;
private:
};