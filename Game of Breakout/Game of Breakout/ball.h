#ifndef BALL_H
#define BALL_H

#include"Entity.h"


class ball : public moving_entity {

	static sf::Texture texture;

	bool destroyed{false};
public:

	ball(float x, float y);

	void setPosition(float x, float y);

	void update(int& lives) ;
	void draw(sf::RenderWindow& window) override;

	 void move_up() noexcept override;
	 bool is_destroyed() const noexcept;
	 void set_destroyed(bool b) noexcept;
	 void move_left() noexcept override;
	 void move_right() noexcept override;
	 void move_down() noexcept override;



};



#endif
