#ifndef BRICK_H
#define BRICK_H

#include"Entity.h"

class brick : public entity {
	static sf::Texture texture;

public:
	 brick(float x,float y);
	 void update() override;
	 void draw(sf::RenderWindow& windows) override;

	 bool isIT_destroyed() const { return is_destroyed; }
	 void set_destroyed(bool state) { is_destroyed = state; }

};


#endif
