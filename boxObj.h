/*
 * boxObj.h
 *
 *  Created on: Aug 27, 2020
 *      Author: kailau
 */

#ifndef BOXOBJ_H_
#define BOXOBJ_H_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <list>
#include <string>

class boxObj {
private:
	sf::RenderWindow *window;
	std::list<boxObj*> *boxes;
protected:
	sf::Vector2f velocity;
	bool usingGravity;
	bool isKinematic;
	bool isTrigger;
	std::map<char, float> collisions;
public:

	std::string tag;

	sf::RectangleShape sprite;

	boxObj(sf::RenderWindow &window, std::list<boxObj*> &boxes, sf::Vector2f pos, sf::Vector2f size);

	virtual ~boxObj();

	void getCollisions();

	void setGravity(bool b);

	void setKinematic(bool b);

	void setTrigger(bool b);

	virtual void onUpdate(float dt);

	void setColor(sf::Color color){
		sprite.setFillColor(color);
	}
};

#endif /* BOXOBJ_H_ */
