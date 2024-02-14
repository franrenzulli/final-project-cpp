#include "Object.h"

Object::Object(std::string fname) {
	m_texture.loadFromFile(fname);
	m_sprite.setTexture(m_texture);
}
