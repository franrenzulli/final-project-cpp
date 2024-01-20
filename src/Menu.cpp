#include <SFML/Graphics/RenderWindow.hpp>
#include "Menu.h"
#include "Utils.h"
#include <iostream>
Menu::Menu() {
    m_pacfont.loadFromFile("assets/fonts/pacfont.ttf");
    m_namco_font.loadFromFile("assets/fonts/namco.ttf");

    m_title.setFont(m_pacfont);
    m_title.setString("PACMAN");
    m_title.setPosition(325, 50);
    m_title.setFillColor({255,255,0});
    m_title.setCharacterSize(120);

    m_opts.AddEntry("start");
    m_opts.AddEntry("highscores");
    m_opts.AddEntry("exit");
    m_opts.setFont(m_namco_font);
    m_opts.setFontSize(25);
    Color fColor(200,200,50), olColor(255,255,255);
    m_opts.setFillColor(fColor);

    m_footer.setFont(m_namco_font);
    m_footer.setCharacterSize(20);
    m_footer.setFillColor({150,150,150});
    m_footer.setPosition(100, 900);
    m_footer.setString("use keys to navigate the menu.");
}


Menu::~Menu() {}

void Menu::ProcessEvents(Game &game, Event &event) {
    if (event.type == Event::KeyPressed && event.key.code == Keyboard::Enter && m_opts.getSelected() == 0) {
        // aca se implementa el entrypoint para la partida 
        // game.SetScene(...);
    }

    if (event.type == Event::KeyPressed && event.key.code == Keyboard::Enter && m_opts.getSelected() == 1) {
        // aca se implementa la escena de los highscores 
        // game.SetScene(...);
    }
    
    if (event.type == Event::KeyPressed && event.key.code == Keyboard::Enter && m_opts.getSelected() == 2) {
        game.Exit();
    }

    if (event.type == Event::KeyPressed && event.key.code == Keyboard::Down) {
        m_opts.moveCursorDown();
    }
    if (event.type == Event::KeyPressed && event.key.code == Keyboard::Up) {
        m_opts.moveCursorUp();
    }
}

void Menu::Update(Game &game) {
    m_opts.updateAll();
}

void Menu::Draw(RenderWindow &window) {
    window.clear({0,0,0});
    window.draw(m_title);
    for (auto e : m_opts.getEntries()) {
        window.draw(e);
    }
    window.draw(m_footer);
    window.display();
}