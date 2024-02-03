#include<SFML/Graphics.hpp>

#include<string>
#include<random>
#include<vector>
#include"constants.h"
#include"Background.h"
#include"ball.h"
#include"Paddle.h"
#include"brick.h"
#include"Interactions.h"

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

	Background the_background(0.0f, 0.0f);

	ball the_ball(constants::window_width/2.0f, constants::window_height/2.0f);

	Paddle the_paddle(constants::window_width / 2.0f, constants::window_height - constants::paddle_height);
	vector<brick> bricks;
	for (int i = 0;i < constants::brick_coloumns;i++) {
		for (int j = 0;j < constants::brick_rows;j++) {

			float x = constants::brick_offset + (1 + i) * constants::brick_width;
			float y = constants::brick_height * (1 + j);

			//c++11 feature to create the objects in the array to save memory.
			bricks.emplace_back(x, y);


		}
	}
	//This line makes a windows which you can draw content in.
	sf::RenderWindow game_windows{ {constants::window_width, constants::window_height},"Simple breakout game" };

	game_windows.setFramerateLimit(60); // limits the fps to 60.






	//Game's loop
	while (game_windows.isOpen())
	{
		game_windows.clear(sf::Color::Black);

		sf::Event event;
		//If an event happened that requested closing, close the window.
		while (game_windows.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				game_windows.close();
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
			game_windows.close();
		}

		the_background.update();
		the_ball.update();
		the_paddle.update();
		for (auto& b : bricks) {
			b.update();
		}
		handle_collision(the_ball, the_paddle);
		
		the_background.draw(game_windows);
		the_ball.draw(game_windows);
		the_paddle.draw(game_windows);
		for (auto b : bricks) {
			b.draw(game_windows);
		}
		//render the changes made to the buffer
		game_windows.display();

	}
}