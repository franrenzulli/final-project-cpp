// En el archivo Fireball.h
#ifndef FIREBALL_H
#define FIREBALL_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Fireball {
public:
	Fireball(float x, float y, float speed);
	
	// Actualizar la posición y otros atributos de la bola de fuego
	void Update(float deltaTime);
	
	// Dibujar la bola de fuego en la ventana
	void Draw(sf::RenderWindow& window) const;
	
	// Obtener los límites de la bola de fuego para detección de colisiones
	sf::FloatRect GetBounds() const;
	
private:
	float m_speed;
	Sprite m_sprite;
	Texture m_texture;
	Vector2f m_velocity;
};

#endif
