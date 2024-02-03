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

void ball::update() {

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

		velocity.y = -velocity.y;
	}
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

void ball::draw(sf::RenderWindow& window) {

	window.draw(sprite);
	
}