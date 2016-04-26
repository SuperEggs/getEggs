#include "GameScene.h"
USING_NS_CC;

Scene* GameLayer::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = GameLayer::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

bool GameLayer::init(){
	//ÉèÖÃ±³¾°Í¼Æ¬
	auto ui_background = Sprite::create("MainMenu/back1.jpg");
	ui_background->setAnchorPoint(Point(0.0f, 0.0f));
	ui_background->setPosition(Point(0.0f, 0.0f));
	addChild(ui_background, 0.0f);

	auto egg = Sprite::create("MainMenu/startUI.png");
	egg->setPosition(Point(100,100));
	addChild(egg, 1);

	auto basket = Sprite::create("MainMenu/basket.png");
	basket->setPosition(Point(400, 100));
	addChild(basket, 2);

	return true;
}
