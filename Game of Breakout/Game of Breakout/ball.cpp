#include"ball.h"
#include"constants.h"

sf::Texture ball::texture;

ball::ball(float x, float y) : moving_entity() {

	texture.loadFromFile("ball.png");
	sprite.setTexture(texture);

	sprite.setPosition(x, y);
	sprite.setOrigin(get_center());

	velocity = { constants::ball_speed, constants::ball_speed };



}

void ball::setPosition(float x, float y) {

	sprite.setPosition(x, y);
}


void ball::update(int& lives) {

	sprite.move(velocity);


	if (x() < 0) {

		velocity.x = -velocity.x;

	}

	if (x() > constants::window_width) {
		velocity.x = -velocity.x;
	}

	if (y() < 0) {
		velocity.y = -velocity.y;

	}

	if (y() > constants::window_height) {

		--lives;
		set_destroyed(true);
	}
}

bool ball::is_destroyed() const noexcept {
	return destroyed;
}

void ball::set_destroyed(bool b) noexcept {

	destroyed = b;

}

void ball::move_up() noexcept {

	velocity.y = -constants::ball_speed;

}
void ball::move_left() noexcept {
	velocity.x = -constants::ball_speed;
}
void ball::move_right() noexcept {
	velocity.x = constants::ball_speed;
}

void ball::move_down() noexcept  {
	velocity.y = constants::ball_speed;
}

void ball::draw(sf::RenderWindow& window) {

	window.draw(sprite);
	
}