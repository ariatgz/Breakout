#include"brick.h"


sf::Texture brick::texture;

brick::brick(float x, float y) {

	texture.loadFromFile("brick.png");
	sprite.setTexture(texture);


	sprite.setPosition(x, y);

	sprite.setOrigin(get_center());



}
void brick::update() {

}
void brick::draw(sf::RenderWindow& windows) {
	windows.draw(sprite);
}