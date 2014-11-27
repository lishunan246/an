#include "GameScene.h"

GameScene::GameScene()
{
}

GameScene::~GameScene()
{
}

bool GameScene::init()
{
	if (!Layer::init())
		return false;

	TMXTiledMap* map = TMXTiledMap::create("map00.tmx");

	this->addChild(map);

	auto UI = cocostudio::GUIReader::getInstance()->widgetFromJsonFile("GameUI_1.ExportJson");

	UI->setPosition(Point(0, 0));

	this->addChild(UI);

	newWarriorBtn = (Button*)Helper::seekWidgetByName(UI, "newWarriorBtn");
	newWarriorBtn->addTouchEventListener(this, toucheventselector(GameScene::newWarrior));

	exitToMenuBtn = (Button*)Helper::seekWidgetByName(UI, "exitToMenuBtn");
	exitToMenuBtn->addTouchEventListener(this, toucheventselector(GameScene::exitToMenu));

	return true;
}

Scene* GameScene::createScene()
{
	auto scene = Scene::create();
	auto layer = GameScene::create();
	scene->addChild(layer);
	return scene;
}

void GameScene::exitToMenu(Ref*, TouchEventType type)
{
	Director::getInstance()->replaceScene(HelloWorld::createScene());
}

void GameScene::newWarrior(Ref*, TouchEventType type)
{
	Sprite* sprite = Sprite::create("warrior.png");
	sprite->setPosition(0.5 * 32, 0.5 * 32);

	this->addChild(sprite,1);
}
