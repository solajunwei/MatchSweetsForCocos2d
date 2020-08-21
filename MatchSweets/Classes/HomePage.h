
#ifndef __HOMEPAGE_H__
#define __HOMEPAGE_H__


#include "cocos2d.h"
#include "ui/UIWidget.h"
//USING_NS_CC;

class HomePage : public cocos2d::Layer
{
public:

	static cocos2d::Scene* createScene();

	static HomePage* create();

	bool init();

	void exit(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType type);

	void startGame(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType type);

};

#endif