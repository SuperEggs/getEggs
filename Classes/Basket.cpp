#include "Basket.h"


Basket::Basket()
{
}


Basket::~Basket()
{
}

Basket::Basket(Size size)
{
	s = size;
	x = s.width / 2;
	y = s.height / 5 * 3;
	speed = rand() % 5;
	hasEgg = false;
}

Basket * Basket::basket(Size size){
	Basket * basket = new Basket(size);
	if (basket && basket->init()){
		basket->autorelease();
		return basket;
	}
	CC_SAFE_DELETE(basket);
	return NULL;
}

bool Basket::init(){
	bool init_judge = false;
	do{
		pSprite = Sprite::create("MainMenu/basket.png");
		b_x = pSprite->getContentSize().width / 2;
		this->addChild(pSprite);
		init_judge = true;
	} while (0);
	return init_judge;
	
}

void Basket::update(){
	x += speed;
	if (x <= (b_x + 100) || x >= (s.width - b_x - 100)){
		speed = -speed;
	}
	pSprite->setPosition(ccp(x,y));

}



