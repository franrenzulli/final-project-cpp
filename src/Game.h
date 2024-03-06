#pragma once

#include <SFML/Graphics.hpp>
#include "Scene.h"

using namespace sf;

class Game {
public:
    Game(Scene *s);
    
    void Run(); // Empieza el loop
	
    void ProcessEvents(); // Procesa los eventos (clicks, teclas presionadas, soltadas, etc.)
    void Update(); // Actualiza
    void Draw(); // Dibuja
    void SetScene(Scene *next_scene); // Metodo para cambiar de escena
    void Exit();
	
	const RenderWindow &GetWindow();
private:
    RenderWindow m_window;
    Scene *m_scene; // escena actual
    Scene *m_next_scene = nullptr; // escena siguiente
};
