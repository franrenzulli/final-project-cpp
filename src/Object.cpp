#include "Object.h"

Object::Object(string filename) {
	m_texture.loadFromFile(filename);
	m_sprite.setTexture(m_texture);
}

void Object::Draw(RenderWindow &window) {
	window.draw(m_sprite);
}



