#ifndef PADDLE_H
#define PADDLE_H
#include"Entity.h"

class Paddle : public moving_entity
{

	static sf::Texture texture;
public:

	Paddle(float x, float y);

	 void update() override ;
	 void draw(sf::RenderWindow& windows) override;

	 void move_up() noexcept {}
	 void move_left() noexcept {
		 velocity.x = -4.0f;
	 }
	 void move_right() noexcept {
		 velocity.x = 4.0f;
	 }
	 void move_down() noexcept {

	 }
	


};



#endif
