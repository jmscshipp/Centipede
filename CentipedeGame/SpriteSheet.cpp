#include "SpriteSheet.h"
#include "TEAL\WindowManager.h" 

SpriteSheet::SpriteSheet(sf::Texture& tex, int xCellCount, int yCellCount)
{
	mainSprite = sf::Sprite(tex);

	// Rectangle dimension corresponding to a single cell of the sprite sheet
	cellWidth = tex.getSize().x / xCellCount;
	cellHeight = tex.getSize().y / yCellCount;

	cells.resize(xCellCount * yCellCount);

	// Determine the rectangle for each cell
	int left;
	int top;
	for (int j = 0; j < yCellCount; j++)
	{
		top = j * cellHeight;
		for (int i = 0; i < xCellCount; i++)
		{
			left = i * cellWidth;
			cells[j * xCellCount + i] = sf::IntRect(left, top, cellWidth, cellHeight);
		}
	}
}

int SpriteSheet::CellWidth() {
	return cellWidth;
}

int SpriteSheet::CellHeight() {
	return cellHeight;
}

Glyph SpriteSheet::GetGlyph(char c, sf::Vector2f pos)
{
	return Glyph(this, CharToIndex(c), pos);	// as an extra efficiency, we should add a glyph recycling factory to use here
}

void SpriteSheet::Draw(int i, sf::Vector2f pos)
{
	mainSprite.setTextureRect(cells[i]);		// These two operations are fast to perform
	mainSprite.setPosition(pos);

	WindowManager::Window().draw(mainSprite);
}