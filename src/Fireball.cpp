// En el archivo Fireball.cpp
#include "Fireball.h"
using namespace sf;

Fireball::Fireball(float x, float y, float speed) : m_speed(speed), m_sprite(), m_texture() {
	// Cargar la textura de la bola de fuego
	m_texture.loadFromFile("../assets/images/fireball.png");
	
	// Configurar el sprite
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(x, y);
	m_sprite.setScale(0.5f, 0.5f);
	m_velocity.x = speed;
}


void Fireball::Update(float deltaTime) {
	// Actualizar la posici�n de la bola de fuego en funci�n de la velocidad y el tiempo
	// Mueve la bola de fuego horizontalmente
	float movement = m_speed * deltaTime;
	m_sprite.move(movement, 0);
}

void Fireball::Draw(RenderWindow& window) const {
	// Dibujar la bola de fuego en la ventana
	window.draw(m_sprite);
}

FloatRect Fireball::GetBounds() const {
	// Obtener los l�mites de la bola de fuego para detecci�n de colisiones
	return m_sprite.getGlobalBounds();
}
