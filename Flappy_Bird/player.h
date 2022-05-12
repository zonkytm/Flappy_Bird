#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "pipes.h"
using namespace sf;

using namespace std;

enum Statement {
	dead,
	jump,


};


class player
{
	Statement state;
	Texture player_texture;
	Sprite player_sprite;
	float CurrenFrame, boostfall, velocity,speed;
	bool space_pressed;
	bool isSpace;
public:

	player(Vector2f position)
	{
		player_texture.loadFromFile("img/player.png");
		player_sprite.setTexture(player_texture);
		player_sprite.setOrigin(player_sprite.getGlobalBounds().width / 2, player_sprite.getGlobalBounds().height / 2);
		player_sprite.setTextureRect(IntRect(0, 0, 16, 16));
		player_sprite.setScale(2, 2);
		state = jump;
		player_sprite.setPosition(position);
		CurrenFrame = 0;
		space_pressed=0;
		boostfall = 0.0025;
		velocity = 0.6;
		speed = 0;
		isSpace = 0;
	}



	Sprite get_sprite() {
		return player_sprite;
	}

	void update(float time);


	void ban_exit();

	void moving(float time);

	Statement get_state() {
		return state;
	}

	void set_state(Statement state) {
		this->state = state;
	}


};



void collisions(player& player_, pipes* pipe, int size); 


void score_counting(player& player_, pipes* pipe, int size, int& score);