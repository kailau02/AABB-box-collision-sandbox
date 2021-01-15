/*
 * boxObj.cpp
 *
 *  Created on: Aug 27, 2020
 *      Author: kailau
 */

#include "boxObj.h"

boxObj::boxObj(sf::RenderWindow &window, std::list<boxObj*> &boxes, sf::Vector2f pos, sf::Vector2f size){

	this->window = &window;
	this->boxes = &boxes;

	collisions['u'] = false;
	collisions['d'] = false;
	collisions['l'] = false;
	collisions['r'] = false;
	usingGravity = false;
	isTrigger = false;
	isKinematic = false;

	tag = "";

	sprite.setPosition(pos);
	sprite.setSize(size);
	sprite.setOrigin(sprite.getLocalBounds().width/2, sprite.getLocalBounds().height/2);

}

boxObj::~boxObj(){

}

sf::Vector2f collisionOffset(sf::RectangleShape sprite, boxObj *box){
	sf::Vector2f off;
	sf::Vector2f posA = sprite.getPosition();
	sf::Vector2f halfA(sprite.getLocalBounds().width/2, sprite.getLocalBounds().height/2);
	sf::Vector2f posB = box->sprite.getPosition();
	sf::Vector2f halfB(box->sprite.getLocalBounds().width/2, box->sprite.getLocalBounds().height/2);

	float l1 = posA.x - halfA.x;
	float r1 = posA.x + halfA.x;
	float u1 = posA.y - halfA.y;
	float d1 = posA.y + halfA.y;

	float l2 = posB.x - halfB.x;
	float r2 = posB.x + halfB.x;
	float u2 = posB.y - halfB.y;
	float d2 = posB.y + halfB.y;

	if(l1 <= r2 &&
			r1 >= l2 &&
			u1 <= d2 &&
			d1 >= u2)
	{
		int side = 0;

		// moveUp
		if(u1 < u2){
			side += 1;
			off.y -= d1 - u2;
		}
		// moveRight
		if(r1 > r2){
			side += 2;
			off.x += r2 - l1;
		}
		// moveDown
		if(d1 > d2){
			side += 4;
			off.y += d2 - u1;
		}
		// moveLeft
		if(l1 < l2){
			side += 8;
			off.x -= r1 - l2;
		}

		if(side % 5 == 0){
			// origin offset
		}
		else if (side != 1 && side != 2 && side != 4 && side != 8){

			if (abs(off.x) < abs(off.y)){
				off.y = 0;
			}
			else{
				off.x = 0;
			}
		}
	}
	return off;
}

void boxObj::getCollisions(){

	collisions['u'] = false;
	collisions['d'] = false;
	collisions['l'] = false;
	collisions['r'] = false;

	for (std::list<boxObj*>::iterator it = boxes->begin(); it != boxes->end(); ++it){

		boxObj *box = *it;
		if (box->isKinematic){
			// Collision with kinetic object
			sf::Vector2f off = collisionOffset(sprite, box);

			sprite.move(off.x/2, off.y/2);
			box->sprite.move(-off.x/2, -off.y/2);
		}
		else{
			// Collision with static object
			sf::Vector2f off = collisionOffset(sprite, box);

			sprite.move(off);

			if(off.y > 0) collisions['u'] = true;
			if(off.y < 0) collisions['d'] = true;
			if(off.x < 0) collisions['l'] = true;
			if(off.x > 0) collisions['r'] = true;

		}

	}
}

void boxObj::setGravity(bool b){
	usingGravity = b;
}

void boxObj::setKinematic(bool b){

	isKinematic = b;
}

void boxObj::setTrigger(bool b){
	isTrigger = b;
}

void boxObj::onUpdate(float dt){

	if (isKinematic){

		if (usingGravity){
			velocity.y += 0.3f;
		}
		sprite.move(velocity.x * dt, velocity.y * dt);

		getCollisions();
	}

	if(collisions['d'] && velocity.y > 0){
		velocity.y = 0;
		velocity.x = 0;
	}

	window->draw(sprite);

}

