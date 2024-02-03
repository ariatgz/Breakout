#ifndef GAME_H
#define GAME_H
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

class Game {

	sf::RenderWindow game_windows{ {constants::window_width, constants::window_height},"Simple breakout game" };

	Background the_background{ 0.0f, 0.0f };

	ball the_ball{ constants::window_width / 2.0f, constants::window_height / 2.0f };


	Paddle the_paddle{ constants::window_width / 2.0f, constants::window_height - constants::paddle_height };
	vector<brick> bricks;

	enum class game_state{paused,running};

	game_state state{ game_state::running };

public:

	Game();

	void run();
	void reinitialize();

};

#endif