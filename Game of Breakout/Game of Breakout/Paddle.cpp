#include"Paddle.h"
#include"constants.h"
sf::Texture Paddle::texture;

Paddle::Paddle(float x, float y) :  moving_entity() {


	texture.loadFromFile("paddle.png");
	sprite.setTexture(texture);

	sprite.setPosition(x, y);
	sprite.setOrigin(get_center());
	velocity = { 0.0f,0.0f };
}

void Paddle::update()  {

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
		
		if (x() >= 0 ) {
			velocity.x = -7.0f;
		}
		else {
			velocity.x = 0.0f;
		}

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
		
		if (x() <= constants::window_width-constants::Paddle_width) {
			velocity.x = 7.0f;
		}
		else {
			velocity.x = 0.0f;
		}

	}
	else {
		velocity.x = 0.0f;
	}

	sprite.move(velocity);
	

}
void Paddle::draw(sf::RenderWindow& windows)  {

	windows.draw(sprite);
}

