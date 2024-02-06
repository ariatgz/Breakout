#ifndef CONSTANTS_H
#define CONSTANTS_H


struct constants
{
	static constexpr int window_width{ 520 };
	static constexpr int window_height{ 450 };
	static constexpr float ball_speed{ 5.0f };
	static constexpr float Paddle_width{ 60.0f };
	static constexpr float paddle_height{ 20.0f };
	static constexpr float brick_width{ 43.0f };
	static constexpr float brick_height{ 20.0f };
	static constexpr float brick_offset{ brick_width/2.0f };
	static constexpr int brick_coloumns{ 10 };
	static constexpr int brick_rows{ 4 };
	static constexpr int brick_strengths{ 3 };
	static constexpr int lives{ 3 };

};


#endif
