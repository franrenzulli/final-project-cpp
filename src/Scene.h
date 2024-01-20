#pragma once

#include <SFML/Graphics.hpp>
#include <filesystem>

using namespace sf;

class Game;

class Scene {
public:
    Scene();
    virtual void ProcessEvents(Game &game, Event &event);
    virtual void Update(Game &game) =0;
    virtual void Draw(RenderWindow &window) =0;
private:
};