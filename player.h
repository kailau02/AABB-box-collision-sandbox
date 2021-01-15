/*
 * player.h
 *
 *  Created on: Aug 28, 2020
 *      Author: kailau
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include "boxObj.h"

class player : public boxObj {
private:
	bool grounded;
	bool jumpPressed;
	float speed;
public:
	player(sf::RenderWindow &window, std::list<boxObj*> &boxes, sf::Vector2f pos, sf::Vector2f size);
	void onUpdate(float dt);
};

#endif /* PLAYER_H_ */
