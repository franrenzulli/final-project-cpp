#include "Object.h"

// Metodo para inicializar texturas a los objetos
Object::Object(std::string fname) {
	m_texture.loadFromFile(fname);
	m_sprite.setTexture(m_texture);
}

// Metodo para cambiar texturas a los objetos, y actualizar los sprites de los jugadores
void Object::ChangeTexture(std::string fname){
	m_texture.loadFromFile(fname);
	m_sprite.setTexture(m_texture);
}

// Dibuja los objetos en la escena
void Object::Draw(RenderWindow &window) {
	window.draw(m_sprite);	
}

// Maneja colisiones de objetos
bool Object::CollideWith(const Object &o) {
	auto r1 = this->m_sprite.getGlobalBounds();
	auto r2 = o.m_sprite.getGlobalBounds();
	return r1.intersects(r2);
}
