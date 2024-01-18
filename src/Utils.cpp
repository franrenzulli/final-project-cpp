#include <cmath>
#include "Utils.h"

Vector2f round(const sf::Vector2f vector) {
    return sf::Vector2f{ std::round(vector.x), std::round(vector.y) };
}

Vector2f Center(Text &tt) {
    auto center = tt.getGlobalBounds().getSize() / 2.f;
    auto localBounds = tt.getLocalBounds().getSize();
    Vector2f pos = { localBounds.x + center.x, localBounds.y + center.y};
    auto rounded = round(pos);

    return rounded;

}