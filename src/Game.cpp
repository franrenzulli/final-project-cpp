#include <SFML/Graphics.hpp>
#include "Game.h"

// chequear resolucion
Game::Game(Scene *s) : m_window(VideoMode(1280, 1024), "Final Project Game"), m_scene(s) {
    m_window.setFramerateLimit(60);
}

void Game::Run() {
    while (m_window.isOpen()) {
        ProcessEvents();
        Update();
        Draw();

        if (m_next_scene) {
            delete m_scene;
            m_scene = m_next_scene;
            m_next_scene = nullptr;
        }
    }
}

void Game::ProcessEvents() {
    Event e;
    while (m_window.pollEvent(e)) {
        if (e.type == Event::Closed)
            m_window.close();
    }
}

void Game::Update() {
    m_scene->Update(*this);

}

void Game::Draw() {
    m_scene->Draw(m_window);
}

void Game::SetScene(Scene *next_scene) {
    m_next_scene = next_scene;
}
