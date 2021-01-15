/*
 * block.h
 *
 *  Created on: Sep 3, 2020
 *      Author: kailau
 */

#ifndef BLOCK_H_
#define BLOCK_H_

#include <SFML/Graphics.hpp>
#include <list>
#include "boxObj.h"

class block : public boxObj {
public:
	block(sf::RenderWindow &window, std::list<boxObj*> &boxes, sf::Vector2f pos);
	void onUpdate(float dt);
};

#endif /* BLOCK_H_ */
