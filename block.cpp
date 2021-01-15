/*
 * block.cpp
 *
 *  Created on: Sep 3, 2020
 *      Author: kailau
 */

#include "block.h"

block::block(sf::RenderWindow &window, std::list<boxObj*> &boxes, sf::Vector2f pos)
: block::boxObj(window, boxes, pos, sf::Vector2f(50,50)) {
	sprite.setFillColor(sf::Color(80,20,0));
	tag = "block";
}

void block::onUpdate(float dt){
	boxObj::onUpdate(dt);
}
