#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>

#include "boxObj.h"
#include "player.h"
#include "block.h"
#include "Enemy.h"

sf::Vector2f GetMousePos(sf::RenderWindow &window){
	// get the current mouse position in the window
	sf::Vector2i pixelPos = sf::Mouse::getPosition(window);

	// convert it to world coordinates
	return window.mapPixelToCoords(pixelPos);

}

int main(){
	sf::RenderWindow window(sf::VideoMode(800,600), "Box Collision");
	window.setFramerateLimit(60);
	sf::View view = window.getView();
	view.setCenter(0, 0);
	window.setView(view);

	sf::Clock clock;

	std::list<boxObj*> boxes;
	std::list<sf::Vector2f> bPos;
	bPos.push_back(sf::Vector2f(0,200));
	bPos.push_back(sf::Vector2f(50,200));
	bPos.push_back(sf::Vector2f(100,150));
	bPos.push_back(sf::Vector2f(-50,150));
	bPos.push_back(sf::Vector2f(50,50));


	for (std::list<sf::Vector2f>::iterator it = bPos.begin(); it != bPos.end(); it++){
		boxObj *bp = new block(window, boxes, *it);
		boxes.push_back(bp);
	}

	player player(window, boxes, sf::Vector2f(0,0), sf::Vector2f(50,50));
	player.setKinematic(true);
	player.setColor(sf::Color::Blue);
	player.setGravity(true);
	boxObj *pb = &player;
	boxes.push_back(pb);


	while(window.isOpen()){

		sf::Time time = clock.restart();
		sf::Event event;

		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed){
				window.close();
			}
			if(event.type == sf::Event::Resized){
				sf::View view = window.getView();
				view.setSize(event.size.width, event.size.height);
				window.setView(view);
			}
		}
		float dt = time.asMilliseconds() / 10;

		window.clear();

		if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
			sf::Vector2f mouse = GetMousePos(window);
			for(std::list<boxObj*>::iterator it = boxes.begin(); it != boxes.end(); it++){
				boxObj *b = *it;

				sf::FloatRect bounds = b->sprite.getGlobalBounds();

				if (b->tag == "block" &&
						mouse.x > bounds.left &&
						mouse.x < bounds.left + bounds.width &&
						mouse.y > bounds.top &&
						mouse.y < bounds.top + bounds.height){
					boxes.erase(it);
				}
			}
		}
		if(sf::Mouse::isButtonPressed(sf::Mouse::Right)){
			bool overBlock = false;
			sf::Vector2f mouse = GetMousePos(window);
			for(std::list<boxObj*>::iterator it = boxes.begin(); it != boxes.end(); it++){
				boxObj *b = *it;

				sf::FloatRect bounds = b->sprite.getGlobalBounds();

				if (b->tag == "block" &&
						mouse.x >= bounds.left &&
						mouse.x <= bounds.left + bounds.width &&
						mouse.y >= bounds.top &&
						mouse.y <= bounds.top + bounds.height){

					overBlock = true;
					break;
				}
			}
			if(!overBlock){
				sf::Vector2f blockPos(round(mouse.x / 50) * 50, round(mouse.y / 50) * 50);
				block *b = new block(window, boxes, blockPos);
				boxes.push_back(b);
			}
		}

		for (std::list<boxObj*>::iterator it = boxes.begin(); it != boxes.end(); ++it){
			boxObj *b = *it;
			b->onUpdate(dt);
		}
		sf::View view = window.getView();
		view.setCenter(player.sprite.getPosition());
		window.setView(view);
		clock.restart().asMilliseconds();
		window.display();
	}
	return 0;
}
