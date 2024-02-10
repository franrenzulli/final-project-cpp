#include "Menu.h"

Menu::Menu() {}
Menu::~Menu() {}


void Menu::ProcessEvents(Game &game, Event &event) {}
void Menu::Update(Game &game) {}

void Menu::Draw(RenderWindow &window) {
    window.clear({0,0,0});
    window.display();
}