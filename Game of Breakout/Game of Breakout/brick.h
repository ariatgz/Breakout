#ifndef BRICK_H
#define BRICK_H

#include"Entity.h"

class brick : public entity {
	static sf::Texture texture;

public:
	 brick(float x,float y);
	 void update() override;
	 void draw(sf::RenderWindow& windows) override;

};


#endif
