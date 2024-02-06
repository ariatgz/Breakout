#ifndef BRICK_H
#define BRICK_H

#include"Entity.h"
#include"constants.h"

class brick : public entity {
	static sf::Texture texture;
	int strength{ constants::brick_strengths };

public:
	 brick(float x,float y);
	 void update() override;
	 void draw(sf::RenderWindow& windows) override;

	 void set_strength(int b) noexcept;
	 void weaken() noexcept;
	 bool is_too_weak() const noexcept;

	 bool isIT_destroyed() const { return is_destroyed; }
	 void set_destroyed(bool state) { is_destroyed = state; }

};


#endif
