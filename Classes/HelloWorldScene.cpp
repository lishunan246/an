#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
	auto UI = cocostudio::GUIReader::getInstance()->widgetFromJsonFile("Welcome_1.ExportJson");

	UI->setPosition(Point(0,0));

	this->addChild(UI);
	log("start");

	newgameBtn = (Button*)Helper::seekWidgetByName(UI, "newgameBtn");
	newgameBtn->addTouchEventListener(this, toucheventselector(HelloWorld::newGame));


	quitBtn = (Button*)Helper::seekWidgetByName(UI, "quitBtn");
	quitBtn->addTouchEventListener(this, toucheventselector(HelloWorld::onClick));
    
    return true;
}

void HelloWorld::onClick(Ref*, TouchEventType type)
{
	Director::getInstance()->end();
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void HelloWorld::newGame(Ref*, TouchEventType type)
{
	Director::getInstance()->replaceScene(GameScene::createScene());
}
