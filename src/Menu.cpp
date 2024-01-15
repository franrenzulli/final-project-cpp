#include <SFML/Graphics/RenderWindow.hpp>
#include "Menu.h"

Menu::Menu() {}

void Menu::Update(Game &game) {}

void Menu::Draw(RenderWindow &window) { 
    window.clear({0,0,0});
    window.display();
}