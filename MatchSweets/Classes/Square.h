
#ifndef __SQUARE_H__
#define __SQUARE_H__

#include "cocos2d.h"

enum SweetType
{
	EMPTY = 0,
	BLUE = 1,
	GREEN = 2,
	RED = 3,
	YELLOW = 4,
	PINK = 5
};

SweetType getRandomSweet();

class Square
{
public:
	Square(cocos2d::Node* Parent);
	~Square();

	void setRootNodePos(cocos2d::Vec2 pos);
	void setSweetType(SweetType type);

private:
	void setSweet();

private:
	cocos2d::Node* rootNode;
	SweetType type;
	cocos2d::Sprite* sprite;
};

#endif
