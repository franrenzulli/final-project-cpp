#include <SFML/Graphics/RenderWindow.hpp>
#include "Menu.h"
#include "Utils.h"

Menu::Menu() {
    m_pacfont.loadFromFile("assets/fonts/pacfont.ttf");
    m_namco_font.loadFromFile("assets/fonts/namco.ttf");

    m_title.setFont(m_pacfont);
    m_title.setString("PACMAN");
    auto bounds = m_title.getLocalBounds();
    m_title.setPosition(640 - (bounds.left+bounds.width/2), 50);
    m_title.setFillColor({255,255,0});
    m_title.setOutlineColor({0,0,255});
    m_title.setCharacterSize(120);

    m_circ.setPosition(m_title.getPosition());
    m_circ.setRadius(5);
    m_circ.setFillColor({0,255,0});

    m_opts.AddEntry("start");
    m_opts.AddEntry("highscores");
    m_opts.AddEntry("exit");
    m_opts.setFont(m_namco_font);
    m_opts.setFontSize(25);
    Color fColor(200,200,50), olColor(255,255,255);
    m_opts.setFillColor(fColor);
    m_opts.updateAll();
    
    /*
    m_start.setFont(m_namco_font);
    m_start.setString("start");
    m_start.setFillColor({200,255,50});
    m_start.setOrigin(Center(m_start));
    m_start.setPosition({700, 500});
    m_start.setCharacterSize(25);
    */
}


Menu::~Menu() {}

void Menu::ProcessEvents(Game &game, Event &event) {
    if (event.type == Event::KeyPressed && event.key.code == Keyboard::Enter) {
        // aca se implementa el entrypoint para la partida 
        // game.SetScene(...);
    }
}

void Menu::Update(Game &game) {}

void Menu::Draw(RenderWindow &window) {
    window.clear({0,0,0});

    window.draw(m_title);
    window.draw(m_circ);
    for (auto e : m_opts.getEntries()) {
        window.draw(e);
    }
    window.display();
}