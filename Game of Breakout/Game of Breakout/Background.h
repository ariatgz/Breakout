#ifndef BACKGROUND_H
#define BACKGROUND_H

#include"Entity.h"

class Background : public entity
{
	static sf::Texture texture;
public:

	Background(float x, float y);

	void update() override;
	void draw(sf::RenderWindow& window) override;
	


};



#endif
