// En el archivo Fireball.h
#ifndef FIREBALL_H
#define FIREBALL_H
#include "Object.h"

class Player;

class Fireball : public Object {
public:
	Fireball(Texture &tex, float x, float y, float speed);
	
	// Actualizar la posici�n y otros atributos de la bola de fuego
	void Update(float deltaTime);
	
	// Obtener los l�mites de la bola de fuego para detecci�n de colisiones
	FloatRect GetBounds() const;
	
private:
	float m_speed;
	Vector2f m_velocity;
};

#endif
