#ifndef _ArcadeFont
#define _ArcadeFont

#include "SpriteSheet.h"

class ArcadeFont : public SpriteSheet
{
public:
	ArcadeFont();
	ArcadeFont(const ArcadeFont&) = delete;
	ArcadeFont& operator=(const ArcadeFont&) = delete;
	virtual ~ArcadeFont() = default;

private:
	virtual int CharToIndex(char& c);
};


#endif _ArcadeFont