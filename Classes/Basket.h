
#ifndef __Basket_H__
#define __Basket_H__
#include "cocos2d.h"
using namespace cocos2d;
class Basket :public Node
{
public:
	Basket();
	Basket(Size);
	~Basket();
	static Basket *basket(Size size);
	bool init();
	void update();
	CREATE_FUNC(Basket);
public:
	float x, y;
	float b_x;
	float speed;
	bool hasEgg;
	Sprite *pSprite;
	Size s;
};
#endif