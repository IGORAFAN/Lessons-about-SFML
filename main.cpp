#include<iostream>

#include"Player.h"
#include"LevelMap.h"

using namespace sf;

const float timeOfGame = 800;

int main()
{
	RenderWindow window(VideoMode(1280, 720), "My lessons about SFML");

	Player player("hero.png", 250, 250, 96.0, 96.0);

	LevelMap levelMap;

	Clock clock;

	while (window.isOpen()){

		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / timeOfGame;

		Event event;
		while (window.pollEvent(event)){
			if (event.type == sf::Event::Closed)
				window.close();
		}

		player.animationsByInput(time);
		player.updatePosition(time);

		levelMap.renderLevelMap(window);
		
		window.draw(player.getSprite());
		window.display();
		window.clear();
	}

	return 0;
}
