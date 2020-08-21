#include "GameStart.h"
#include "cocoStudio/CocoStudio.h"

USING_NS_CC;

Scene* GameStart::createScene()
{
	auto scene = Scene::create();
	auto game = GameStart::create();
	scene->addChild(game);
	return scene;
}

GameStart* GameStart::create()
{
	GameStart* pRet = new GameStart();
	if (pRet && pRet->init())
	{
		pRet->autorelease();
	}
	else
	{
		pRet = nullptr;
	}

	return pRet;
}

bool GameStart::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();

	auto root = CSLoader::createNode("res/GameBackGround/GameLayer.csb");
	root->setAnchorPoint(Vec2(0.5, 0.5));
	root->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(root);

	auto bg = root->getChildByName("Panel_Ground")->getChildByName("Panel_GeZi");

	// Ìí¼Ó·½¿é
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j ++)
		{
			sqList[i][j] = new Square(bg);
			sqList[i][j]->setRootNodePos(Vec2(i* 75, j * 75));
			sqList[i][j]->setSweetType(getRandomSweet());
		}
	}
	return true;
}


