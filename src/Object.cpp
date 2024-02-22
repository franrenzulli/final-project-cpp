#include "Object.h"

// Metodo para inicializar texturas a los objetos
Object::Object(std::string fname) {
	m_texture.loadFromFile(fname);
	m_sprite.setTexture(m_texture);
}

// Metodo para cambiar texturas a los objetos, y actualizar los sprites de los jugadores
void Object::ChangeTexture(std::string fname){
	m_texture.loadFromFile(fname);
	m_sprite.setTexture(m_texture, true); // true parar
	m_sprite.setOrigin(m_sprite.getLocalBounds().width / 2, 0);
}

// Dibuja los objetos en la escena
void Object::Draw(RenderWindow &window) const{
	window.draw(m_sprite);	
}

// Maneja colisiones de objetos
bool Object::CheckCollision(const Object& other) const {
	return m_sprite.getGlobalBounds().intersects(other.m_sprite.getGlobalBounds());
}
