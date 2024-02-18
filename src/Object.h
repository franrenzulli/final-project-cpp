#ifndef OBJECT_H
#define OBJECT_H
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <string>
#include <SFML/Graphics/RenderWindow.hpp>
using namespace sf;

class Object { // Clase que se encarga de cargar las imagenes de cada sprite y pintarlas en pantalla
public:
	Object(std::string fname);
	void Draw(RenderWindow &window) const;
	bool CheckCollision(const Object& other) const;
	void ChangeTexture(std::string fname); // Cambia textura de los sprites
protected:
	Texture m_texture;
	Sprite m_sprite;
};

#endif
