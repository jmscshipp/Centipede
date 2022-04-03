#ifndef _Glyph
#define _Glyph

#include "SFML\Graphics.hpp"

// forward declaration
class SpriteSheet; 

class Glyph
{
private:
	SpriteSheet* sheet;
	int cellIndex;
	sf::Vector2f position;

public:
	Glyph();
	Glyph(SpriteSheet* thisSheet, int cellInd, sf::Vector2f pos);
	void Draw();
};


#endif _Glyph