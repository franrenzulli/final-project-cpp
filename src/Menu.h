#pragma once

#include <SFML/Graphics.hpp>
#include "Scene.h"
#include "TextList.h"

class Menu : public Scene {
public:
    Menu();
    ~Menu();
    void ProcessEvents(Game &game, Event &event) override;
    void Update(Game &game) override;
    void Draw(RenderWindow &window) override;
private:
    Font m_pacfont, m_namco_font;
    Text m_title;
    TextList m_opts = TextList({300,500}, {0,50});
};