#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "extensions\cocos-ext.h"
#include "ui\CocosGUI.h"
#include "editor-support\cocostudio\CocoStudio.h"
#include "editor-support\cocostudio\CCSGUIReader.h"

#include "GameScene.h"

using namespace cocos2d::extension;
using namespace cocostudio;
using namespace cocos2d::ui;

class HelloWorld : public cocos2d::Layer
{
private:
	Button* newgameBtn, *loadgameBtn, *aboutBtn, *quitBtn;
	
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

	void onClick(Ref*, TouchEventType type);
	void newGame(Ref*, TouchEventType type);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
