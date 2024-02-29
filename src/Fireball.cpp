// En el archivo Fireball.cpp
#include "Fireball.h"
using namespace sf;

Fireball::Fireball(Texture &tex, float x, float y, float speed) : Object(tex), m_speed(speed) {
	// Configurar el sprite
	m_sprite.setPosition(x, y);
	m_sprite.setScale(0.5, 0.5);
	m_velocity.x = speed;
}

void Fireball::Update(float deltaTime) {
	// Actualizar la posición de la bola de fuego en función de la velocidad y el tiempo
	// Mueve la bola de fuego horizontalmente
	float movement = m_speed * deltaTime;
	m_sprite.move(movement, 0);
	
	if(movement > 0){
		m_sprite.setScale(-0.5, 0.5);
	}
}

FloatRect Fireball::GetBounds() const {
	// Obtener los límites de la bola de fuego para detección de colisiones
	return m_sprite.getGlobalBounds();
}
