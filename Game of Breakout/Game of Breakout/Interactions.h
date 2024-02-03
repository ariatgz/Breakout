#ifndef INTERACTIONS_H
#define INTERACTIONS_H

#include"ball.h"
#include"Paddle.h"


bool is_interacting(const entity& e1, const entity& e2);

void handle_collision(ball& b, const Paddle& p);

#endif

