#ifndef Unit_h__
#define Unit_h__

#include "cocos2d.h"
using namespace cocos2d;

class Unit:public Node
{
public:
	Unit();
	~Unit();
	Sprite* getSprite();
	void bindSprite(Sprite* sprite);
	
	virtual void setTagPosition(int x, int y);
	virtual Point getTagPosition();
protected:
	Sprite* m_sprite;
	
private:

};


#endif // Unit_h__
