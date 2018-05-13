#include"stdafx.h"
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using std::cout;
using std::endl;
using std::cin;

sf::Mutex mutex;


void checkKeyPressed(sf::Event event, sf::Window* window) {
	switch (event.key.code) {
	case sf::Keyboard::Down:
		window->setTitle("Key Arrow down wurde gedrueckt");
		break;
	case sf::Keyboard::D:
		cout << "This isnt wokring just yet. Hold on" << endl;
		break;
	}
	
}

int main(){
	sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
	window.setFramerateLimit(60);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::GainedFocus:
				cout << "Window now gained Focus" << endl;
				break;
			case sf::Event::Resized:
				cout << "Window is being resized. New Width: " << event.size.height << " neue Hoehe: " << event.size.height << endl;
				break;
			case sf::Event::KeyPressed:
				checkKeyPressed(event, &window);
			case sf::Event::LostFocus:
				cout << "Window now lost Focus" << endl;
			}
		}
		//cout << "I am atleast getting to thist point rn" << endl;
		sf::Sprite sprite;
		sf::Texture texture;
		texture.create(200,200);
		sf::Image Image1;
		Image1.create(200,200,sf::Color::Yellow);

		texture.update(Image1);

		sprite.setTexture(texture);
		sprite.setColor(sf::Color::Cyan);
		sprite.setPosition(sf::Vector2f(10, 10));

		window.clear(sf::Color::Black);
		window.draw(sprite);
		window.display();
	}


	cout << "Window closed succesfully. Ending the program rn" << endl;
	return 0;
}
