#include "Square.h"
#include "cocostudio/CocoStudio.h"

SweetType getRandomSweet()
{
	int n = rand() % 6;
	switch (n)
	{
	case 1:
		return BLUE;
		break;
	case 2:
		return GREEN;
		break;
	case 3:
		return RED;
		break;
	case 4:
		return YELLOW;
		break;
	case 5:
		return PINK;
	default:
		return EMPTY;
	}
}

Square::Square(cocos2d::Node* Parent)
{
	if (!Parent)
	{
		return;
	}

	type = EMPTY;

	rootNode = cocos2d::CSLoader::createNode("res/Sequare/Sequare.csb");
	rootNode->setAnchorPoint(cocos2d::Vec2(0, 0));
	Parent->addChild(rootNode);

	auto bg = rootNode->getChildByName("ImgBg");
	auto size = bg->getContentSize();

	sprite = cocos2d::Sprite::create();
	sprite->setPosition(cocos2d::Vec2(size.width / 2, size.height / 2));
	bg->addChild(sprite);
}

Square::~Square()
{
	if (rootNode)
	{
		rootNode->removeFromParent();
		rootNode = nullptr;
	}
}

void Square::setRootNodePos(cocos2d::Vec2 pos)
{
	rootNode->setPosition(pos);
}

void Square::setSweetType(SweetType type)
{
	this->type = type;
	setSweet();
}

void Square::setSweet()
{	
	std::string str;
	switch (type)
	{
	case EMPTY:
		str = "res/Sequare/empty.png";
		break;
	case BLUE:
		str = "res/Sequare/Blue.png";
		break;
	}

	sprite->setTexture(str);
}

