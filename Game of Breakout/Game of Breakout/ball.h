#ifndef BALL_H
#define BALL_H

#include"Entity.h"


class ball : public moving_entity {

	static sf::Texture texture;

public:

	ball(float x, float y);

	void update() override;
	void draw(sf::RenderWindow& window) override;

	 void move_up() noexcept override;
	 void move_left() noexcept override;
	 void move_right() noexcept override;
	 void move_down() noexcept override;



};



#endif
