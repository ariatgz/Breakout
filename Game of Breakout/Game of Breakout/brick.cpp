#include"brick.h"

const sf::Color brick_color_hit1{ 0,255,0,80 }; //dull green
const sf::Color brick_color_hit2{ 0,255,0,170 }; //mid green
const sf::Color brick_color_hit3{ 0,255,0,255 }; //full green

sf::Texture brick::texture;

brick::brick(float x, float y) {

	texture.loadFromFile("brick.png");
	sprite.setTexture(texture);


	sprite.setPosition(x, y);

	sprite.setOrigin(get_center());



}
void brick::update() {

	if (strength == 1) {
		sprite.setColor(brick_color_hit1);
	}
	else if (strength == 2) {
		sprite.setColor(brick_color_hit2);
	} 
	else if (strength == 3) {
		sprite.setColor(brick_color_hit3);
	}


}
void brick::draw(sf::RenderWindow& windows) {
	windows.draw(sprite);
}




void brick::set_strength(int b) noexcept {
	strength = b;
}
void brick::weaken() noexcept {
	--strength;
}
bool brick::is_too_weak() const noexcept {
	return strength <= 0;
}