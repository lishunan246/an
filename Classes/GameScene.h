#ifndef GameScene_h__
#define GameScene_h__

#include "cocos2d.h"

#include "extensions\cocos-ext.h"
#include "ui\CocosGUI.h"
#include "editor-support\cocostudio\CocoStudio.h"
#include "editor-support\cocostudio\CCSGUIReader.h"

#include "HelloWorldScene.h"

using namespace cocos2d::extension;
using namespace cocostudio;
using namespace cocos2d::ui;
using namespace cocos2d;

class GameScene:public Layer
{
public:
	GameScene();
	~GameScene();
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(GameScene);
	void exitToMenu(Ref*, TouchEventType type);
	void newWarrior(Ref*, TouchEventType type);
private:
	Button* exitToMenuBtn, *newWarriorBtn;
};


#endif // GameScene_h__
