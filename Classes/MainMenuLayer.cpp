#include "MainMenuLayer.h"
#include "GameScene.h"

USING_NS_CC;

Scene* MainMenuLayer::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = MainMenuLayer::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

bool MainMenuLayer::init(){
	//获得窗口大小
	auto winSize = Director::getInstance()->getWinSize();

	//设置背景图片
	auto ui_background = Sprite::create("MainMenu/back1.jpg");
	ui_background->setAnchorPoint(Point(0.0f, 0.0f));
	ui_background->setPosition(Point(0.0f, 0.0f));
	addChild(ui_background, 0.0f);

	//加载纹理到精灵帧缓存
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("MainMenu/buttons.plist");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("MainMenu/UI_GameMenuText_cn-hd.plist");

	//创建“开始游戏”按钮
	//auto startGameBtn = Sprite::createWithSpriteFrameName("MainMenu/btn1.png");//按钮初始状态
	//auto startGameBtnSelected = Sprite::createWithSpriteFrameName("MainMenu/btn1.png");//按钮初始状态
	auto startGameBtn = Sprite::create("MainMenu/start.png");
	auto startGameBtnSelected = Sprite::create("MainMenu/start.png");
	startGameBtnSelected->setScale(0.9f);
	//startGameBtnSelected->setColor(RGB3B(123,213,111));
	//startGameBtnSelected->setAnchorPoint(Point(0.5, 0.5));
	
	//创建菜单
	auto startGameMenuItem = MenuItemSprite::create(startGameBtn, startGameBtnSelected,
		CC_CALLBACK_1(MainMenuLayer::startGameEvent, this));

	//startGameBtn->setPosition(Point(winSize.width / 2.0f, winSize.height / 2.0f));
	auto startGameMenu = Menu::create(startGameMenuItem, NULL);
	//设置菜单的位置

	startGameMenu->setPosition(Point(winSize.width / 2.0f, winSize.height / 2.0f));


	addChild(startGameMenu, 2);

	return true;
}

void MainMenuLayer::startGameEvent(Ref* sender){
	//Create the scene of FishingScene with a transtionFadeBL effect
	auto replaceScene = TransitionSplitRows::create(1.5, GameLayer::createScene());

	//Replace the scene with the trasition effect scene
	Director::getInstance()->replaceScene(replaceScene);
}