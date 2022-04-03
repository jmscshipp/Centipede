#ifndef _CurrentScoreText
#define _CurrentScoreText

#include "TEAL/CommonElements.h"
#include <list>
#include "ArcadeFont.h"

class CurrentScoreText : public GameObject
{
public:
	CurrentScoreText(); // big four
	CurrentScoreText(const CurrentScoreText&) = delete;
	CurrentScoreText& operator=(const CurrentScoreText&) = delete;
	~CurrentScoreText() = default;

	virtual void Draw();

	void UpdateScore(int val); // called by HUDManager

private:
	ArcadeFont myfont;

	std::list<Glyph> symbols;
	sf::Vector2f nextpos;
};


#endif _CurrentScoreText