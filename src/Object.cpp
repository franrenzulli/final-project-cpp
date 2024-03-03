#include "Object.h"

// Constructor
Object::Object(Texture &tex) {
	m_sprite.setTexture(tex);
}

// Metodo para cambiar texturas a los objetos, y actualizar los sprites de los jugadores
void Object::ChangeTexture(Texture &texture){
	m_sprite.setTexture(texture, true); // true parar
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
