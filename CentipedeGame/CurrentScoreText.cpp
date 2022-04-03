#include "CurrentScoreText.h"
#include <string>

CurrentScoreText::CurrentScoreText()
{
	std::string text = "00";
	nextpos = sf::Vector2f((float)(myfont.CellWidth() * 5), 0.0f); // space for 6 digits

	for (size_t i = text.length(); i > 0; i--)
	{
		symbols.push_back(myfont.GetGlyph(text.at(i - 1), nextpos));
		// we must update the next position ourselves
		nextpos.x -= myfont.CellWidth();
	}
}

void CurrentScoreText::Draw()
{
	std::list<Glyph>::iterator it;
	for (it = symbols.begin(); it != symbols.end(); it++)
		it->Draw();
}

void CurrentScoreText::UpdateScore(int val)
{
	// converst score to string
	std::string text = std::to_string(val);
	if (val < 10)
		text.insert(0, "0"); // makes it 01 instead of 1, for example
	symbols.clear();
	nextpos = sf::Vector2f((float)(myfont.CellWidth() * 5), 0.0f);
	for (size_t i = text.length(); i > 0; i--)
	{
		symbols.push_back(myfont.GetGlyph(text.at(i - 1), nextpos));
		// we must update the next position ourselves
		nextpos.x -= myfont.CellWidth();
	}
}