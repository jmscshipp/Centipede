#ifndef _ScoreText
#define _ScoreText

#include "TEAL/CommonElements.h"
#include <list>
#include "ArcadeFont.h"

class ScoreText : public GameObject
{
public:
	ScoreText() = delete; // big four
	ScoreText(sf::Vector2f pos);
	ScoreText(const ScoreText&) = delete;
	ScoreText& operator=(const ScoreText&) = delete;
	~ScoreText() = default;

	virtual void Draw();

	void SetText(int val); // called by HUDManager

private:
	ArcadeFont myfont;
	sf::Vector2f location;
	std::list<Glyph> symbols;
	sf::Vector2f nextpos;
};


#endif _ScoreText