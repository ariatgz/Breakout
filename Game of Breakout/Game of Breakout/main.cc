#include<SFML/Graphics.hpp>

#include"Game.h"
using namespace std;
using namespace std::literals;

/*class creature
{
	static mt19937 mt;
	static bernoulli_distribution bd;


	float vx{ 2.0f };
	float vy{ 2.0f };
	sf::Vector2f velocity;

	sf::CircleShape circle;

public:

	creature(float x, float y) {

		velocity = { vx,vy };
		circle.setPosition(x, y);

		circle.setRadius(6.0f);
		circle.setFillColor(sf::Color::Red);



	}

	void draw(sf::RenderWindow& w) {

		w.draw(circle);
	}

	void update() {

		vx = bd(mt) ? vx : -vx;
		vy = bd(mt) ? vy : -vy;

		circle.move({ vx,vy });

	}


};*/




int main() {

	Game g;

	g.run();

	






	
}