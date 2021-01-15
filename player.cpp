/*
 * player.cpp
 *
 *  Created on: Aug 28, 2020
 *      Author: kailau
 */

#include "player.h"

player::player(sf::RenderWindow &window, std::list<boxObj*> &boxes, sf::Vector2f pos, sf::Vector2f size) :
player::boxObj(window, boxes, pos, size)
{
	jumpPressed = false;
	speed = 5;
	grounded = false;
}


void player::onUpdate(float dt){


	if (collisions['d']){
		grounded = true;
	}
	else{
		grounded = false;
	}

	if (collisions['u'] && velocity.y < 0){
		velocity.y = 0;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
		velocity.y += 0.1f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
		if(!jumpPressed && grounded){
		velocity.y = -8;
		}

		jumpPressed = true;
	}
	else{
		jumpPressed = false;
		velocity.y = (velocity.y < 0) ? 0 : velocity.y;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
		velocity.x  = collisions['d'] ? -speed : std::min(velocity.x, -speed/2);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
		velocity.x  = collisions['d'] ? speed : std::max(velocity.x, speed/2);
	}


	boxObj::onUpdate(dt);
}

