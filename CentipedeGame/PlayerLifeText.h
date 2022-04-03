#ifndef _PlayerLifeText
#define _PlayerLifeText

#include "TEAL/CommonElements.h"
#include <list>
#include "ArcadeFont.h"

class PlayerLifeText : public GameObject
{
public:
	PlayerLifeText(); // big four
	PlayerLifeText(const PlayerLifeText&) = delete;
	PlayerLifeText& operator=(const PlayerLifeText&) = delete;
	~PlayerLifeText() = default;

	virtual void Draw();

	void UpdateLife(int life); // called by HUDManager

private:
	ArcadeFont myfont;

	std::list<Glyph> symbols;
	sf::Vector2f nextpos;
};


#endif _PlayerLifeText