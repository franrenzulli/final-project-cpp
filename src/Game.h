#pragma once

#include <SFML/Graphics.hpp>
#include "Scene.h"

using namespace sf;

class Game {
public:
    Game(Scene *s);
    
    // starts main loop
    void Run();
    void ProcessEvents();
    void Update();
    void Draw();
    void SetScene(Scene *next_scene);
    void Exit();
private:
    RenderWindow m_window;
    Scene *m_scene;
    Scene *m_next_scene = nullptr;
};
