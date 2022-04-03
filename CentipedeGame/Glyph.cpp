#include "Glyph.h"
#include "SpriteSheet.h"
#include "TEAL\ResourceManager.h"

Glyph::Glyph()
{
	sheet = nullptr;
	cellIndex = 0;
	position = sf::Vector2f(0, 0);
}

Glyph::Glyph(SpriteSheet* thisSheet, int cellInd, sf::Vector2f pos)
{
	sheet = thisSheet;
	position = pos;
	cellIndex = cellInd;
}

void Glyph::Draw()
{
	sheet->Draw(cellIndex, position);
}
