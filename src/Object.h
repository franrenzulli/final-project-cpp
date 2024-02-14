#pragma once

#include <SFML/Graphics/Texture.hpp>


class Object {
public:
	Object(std::string filename);
	void Draw(RenderWindow &window);
private:
	Texture m_texture;
	Sprite m_sprite;
};

#endif

