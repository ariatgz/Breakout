#include"Game.h"
#include"Interactions.h"


Game::Game() {
	for (int i = 0;i < constants::brick_coloumns;i++) {
		for (int j = 0;j < constants::brick_rows;j++) {

			float x = constants::brick_offset + (1 + i) * constants::brick_width;
			float y = constants::brick_height * (1 + j);

			//c++11 feature to create the objects in the array to save memory.
			bricks.emplace_back(x, y);


		}
	}
	//This line makes a windows which you can draw content in.


	game_windows.setFramerateLimit(60); // limits the fps to 60.

}

void Game::run() {

	bool pause_key_active{ false };

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

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R)) {
			reinitialize();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P)) {
			if (!pause_key_active) {

				if (state == game_state::running) {
					state = game_state::paused;
				}
				else {
					state = game_state::running;
				}
				pause_key_active = true;
			}
		}
		else {
			pause_key_active = false;
		}

		if (state != game_state::paused) {
			the_background.update();
			the_ball.update();
			the_paddle.update();
			for (auto& b : bricks) {
				b.update();
			}
			handle_collision(the_ball, the_paddle);

			for (auto& b : bricks) {
				handle_collision(the_ball, b);
			}

			bricks.erase(std::remove_if(std::begin(bricks), std::end(bricks),
				[](const brick& b) { return b.isIT_destroyed();}), std::end(bricks));
		}

		

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
void Game::reinitialize() {
	for (int i = 0;i < constants::brick_coloumns;i++) {
		for (int j = 0;j < constants::brick_rows;j++) {

			float x = constants::brick_offset + (1 + i) * constants::brick_width;
			float y = constants::brick_height * (1 + j);

			//c++11 feature to create the objects in the array to save memory.
			bricks.emplace_back(x, y);


		}
	}

}