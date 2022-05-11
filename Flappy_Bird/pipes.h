#pragma once

#include <SFML/Graphics.hpp>
#include "UI.h"
#include <iostream>
using namespace sf;
using namespace std;

class pipes
{

	Texture pipes_texture;
	Sprite pipes_sprite_up, pipes_sprite_down;
public:
	pipes()
	{

		pipes_texture.loadFromFile("img/collisions.png");
		pipes_sprite_up.setTexture(pipes_texture);
		pipes_sprite_down.setTexture(pipes_texture);
		pipes_sprite_down.setTextureRect(IntRect(0, 16, 32, 48));
		pipes_sprite_up.setTextureRect(IntRect(0, 16, 32, 48));
		pipes_sprite_up.setOrigin(pipes_sprite_up.getGlobalBounds().width / 2, pipes_sprite_down.getGlobalBounds().height);
		pipes_sprite_down.setOrigin(pipes_sprite_down.getGlobalBounds().width / 2, 0);
		pipes_sprite_down.setScale(3,10);
		pipes_sprite_up.setScale(3, 10);

		
		
		
	}



	void set_position(Vector2f position) {
		pipes_sprite_up.setPosition(position.x,position.y);
		pipes_sprite_down.setPosition(pipes_sprite_up.getPosition().x,pipes_sprite_up.getPosition().y+150);
		
	}

	void moving(float speed,float time,int& score);

	Sprite get_pipe_up() {
		return pipes_sprite_up;
	}	
	Sprite get_pipe_down() {
		return pipes_sprite_down;
	}



};

