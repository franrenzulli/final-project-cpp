#include <cmath>
#include "Utils.h"

Vector2f round(const sf::Vector2f vector) {
    return sf::Vector2f{ std::round(vector.x), std::round(vector.y) };
}

void setCenter(Text &tt) {
    auto bounds = tt.getLocalBounds(); 
    tt.setOrigin(bounds.left + bounds.width/2.f, bounds.top + bounds.height/2.f);
}