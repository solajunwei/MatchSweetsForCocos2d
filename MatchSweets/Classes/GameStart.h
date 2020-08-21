
#ifndef __GAMESTART_H__
#define __GAMESTART_H__

#include "cocos2d.h"
#include "Square.h"

class GameStart : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	static GameStart* create();
	bool init();



private:
	Square* sqList[10][10];
};

#endif