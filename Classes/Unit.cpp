#include "Unit.h"

Unit::Unit()
{
}

Unit::~Unit()
{
}

Sprite* Unit::getSprite()
{
	return m_sprite;
}

Point Unit::getTagPosition()
{
	return getPosition();
}

void Unit::setTagPosition(int x, int y)
{
	setPosition(Point(x, y));
}

void Unit::bindSprite(Sprite* sprite)
{
	this->m_sprite = sprite;
	this->addChild(m_sprite);

	Size size = m_sprite->getContentSize();
	//m_sprite->setPosition(size.width / 2.0f, size.height / 2.0f);
	this->setContentSize(size);
}
