#include "HomePage.h"

#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"


#include "string"
#include <map>
#include "GameStart.h"

using namespace std;
using namespace cocos2d::ui;

USING_NS_CC;
USING_NS_CC::ui;

// 初始化CSB
map<string, Node*>* initCSB(Node* node, map<string, Node*>* temp)
{
	string name;
	name = node->getName();

	if (name.compare("Layer") == 0)
	{
		name = "rootNode";
	}

	(*temp)[name] = node;

	Vector<Node*>& child = node->getChildren();
	for each (auto var in child)
	{
		if (var->getChildrenCount() > 0)
		{
			initCSB(var, temp);
		}
		else
		{
			name = var->getName();
			(*temp)[name] = var;
		}
	}

	return temp;
}

Scene* HomePage::createScene()
{
	auto scene = Scene::create();

	auto layer = HomePage::create();

	scene->addChild(layer);
	return scene;
}

HomePage* HomePage::create()
{
	HomePage* pRet = new HomePage();
	if (pRet && pRet->init())
	{
		pRet->autorelease();
		return pRet;
	}
	else
	{
		pRet = nullptr;
		return nullptr;
	}
}

bool HomePage::init()
{
	// 父类的init方法是否调用了
	if (!Layer::init())
	{
		return false;
	}

	// 获取当前layer的坐标
	auto origin = Director::getInstance()->getVisibleOrigin();

	// 获取当前的layer大小
	auto visibleSize = Director::getInstance()->getVisibleSize();

	auto root = CSLoader::createNode("res/Start/StartLayer.csb");
	root->setAnchorPoint(Vec2(0.5, 0.5));
	root->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(root);

	map<string, Node*> temp;
	initCSB(root, &temp);

	// 退出游戏
	ImageView* imgBack = (ImageView*)temp["ImgBack"];
	imgBack->setTouchEnabled(true);
	imgBack->addTouchEventListener(CC_CALLBACK_2(HomePage::exit, this));

	// 开始游戏
	Button* btnGameStart = (Button*)temp["btnStart"];
	btnGameStart->setTouchEnabled(true);
	btnGameStart->addTouchEventListener(CC_CALLBACK_2(HomePage::startGame, this));

	return true;
}

void HomePage::exit(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType type)
{
	if (type == Widget::TouchEventType::ENDED)
	{
		Director::getInstance()->end();
	}
}


void HomePage::startGame(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType type)
{
	if (type == Widget::TouchEventType::ENDED)
	{
		Director::getInstance()->replaceScene(GameStart::createScene());
	}
}