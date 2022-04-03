#include "PlayerLifeText.h"
#include <string>

PlayerLifeText::PlayerLifeText()
{
	std::string text = "..";
	nextpos = sf::Vector2f((float)(myfont.CellWidth() * 6), 0.0f); // to the right of score

	for (size_t i = 0; i < text.length(); i++)
	{
		symbols.push_back(myfont.GetGlyph(text.at(i), nextpos));
		// we must update the next position ourselves
		nextpos.x += myfont.CellWidth();
	}
}

void PlayerLifeText::Draw()
{
	std::list<Glyph>::iterator it;
	for (it = symbols.begin(); it != symbols.end(); it++)
		it->Draw();
}

void PlayerLifeText::UpdateLife(int life)
{
	// converts score to string
	std::string text(".", life);
	symbols.clear();
	nextpos = sf::Vector2f((float)(myfont.CellWidth() * 6), 0.0f);
	for (size_t i = 0; i < text.length(); i++)
	{
		symbols.push_back(myfont.GetGlyph(text.at(i), nextpos));
		// we must update the next position ourselves
		nextpos.x += myfont.CellWidth();
	}
}