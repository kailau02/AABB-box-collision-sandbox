/*
 * Enemy.h
 *
 *  Created on: Aug 29, 2020
 *      Author: kailau
 */

#ifndef ENEMY_H_
#define ENEMY_H_

#include "boxObj.h"

class Enemy : public boxObj {
public:
	Enemy(sf::RenderWindow &window, std::list<boxObj*> &boxes, sf::Vector2f pos, sf::Vector2f size);
	void onUpdate(float dt);
};

#endif /* ENEMY_H_ */
