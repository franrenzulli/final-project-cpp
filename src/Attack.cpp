#include "Attack.h"
#include <SFML/Graphics/Texture.hpp>

Attack::Attack(std::string texFilename, float damage, int scores) : m_texFilename(texFilename), m_damage(damage), m_scoresIfSuccessful(scores) {}
