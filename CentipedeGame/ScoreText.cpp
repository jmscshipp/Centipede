#include "ScoreText.h"
#include <string>

ScoreText::ScoreText(sf::Vector2f pos)
{
	location = pos;
	std::string text = "00";
	nextpos = pos;

	for (size_t i = 0; i < text.length(); i++)
	{
		symbols.push_back(myfont.GetGlyph(text.at(i), nextpos));
		// we must update the next position ourselves
		nextpos.x += myfont.CellWidth();
	}
}

void ScoreText::Draw()
{
	std::list<Glyph>::iterator it;
	for (it = symbols.begin(); it != symbols.end(); it++)
		it->Draw();
}

void ScoreText::SetText(int val)
{
	Trace::out("setting new text, val is %d\n", val);
	// converst score to string
	if (val == 0)
		return;
	std::string text = std::to_string(val);

	symbols.clear();
	nextpos = location;
	for (size_t i = text.length(); i > 0; i--)
	{
		symbols.push_back(myfont.GetGlyph(text.at(i - 1), nextpos));
		// we must update the next position ourselves
		nextpos.x -= myfont.CellWidth();
	}
}