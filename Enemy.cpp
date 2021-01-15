/*
 * Enemy.cpp
 *
 *  Created on: Aug 29, 2020
 *      Author: kailau
 */

#include "Enemy.h"

Enemy::Enemy(sf::RenderWindow &window, std::list<boxObj*> &boxes, sf::Vector2f pos, sf::Vector2f size) :
Enemy::boxObj(window, boxes, pos, size){

}

void Enemy::onUpdate(float dt){

	boxObj::onUpdate(dt);
}

