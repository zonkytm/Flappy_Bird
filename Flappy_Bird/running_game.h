#pragma once
#include <SFML/Graphics.hpp>
#include "UI.h"
#include "player.h"
#include "pipes.h"
#include "vector"
using namespace sf;


RenderWindow window(sf::VideoMode(512, 512), "FLappy Bird");


bool game_process() {

	player bird(Vector2f(200, 200));

	Background background;
	Clock game_clock;
	float time_to_spawn_pipe=0, timer=0;
	const int size = 3;
	pipes pipe[size];
	int score = 0;
	for (size_t i = 0; i < size; i++)
	{
		pipe[i].set_position(Vector2f(512 + pipe[i].get_pipe_up().getGlobalBounds().width / 2+ 250*i, rand() % 200 + 190));
		
	}
	
	Game_texts score_text(75,to_string(score));
	score_text.setFillColor(Color::Yellow);


	while (window.isOpen())
	{
		Event event;
		 float time = game_clock.getElapsedTime().asMicroseconds();
		 time = time / 1000;
		 timer += game_clock.getElapsedTime().asSeconds();
		 game_clock.restart();
		while (window.pollEvent(event))
		{
			if (event.type==Event::Closed)
			{


				window.close();
			}

			if (bird.get_state()==dead)
			{
				if (event.type==Event::MouseButtonPressed)
				{
					if (event.key.code==Mouse::Left)
					{
						return 1;
					}
				}
			}
		}
		if (bird.get_state() != dead)
		{
			for (int i = 0; i < size; i++)
			{
				pipe[i].moving(0.2, time,score);
				cout<<pipe[i].get_pipe_up().getPosition().y << endl;
			}
			
			collisions(bird, pipe, size );
		}
		bird.moving(time);
		bird.ban_exit();
		bird.update(time);
		
		window.clear();
		window.draw(background.get_sprite());
		for (int i = 0; i < size; i++)
		{
			window.draw(pipe[i].get_pipe_up());
			window.draw(pipe[i].get_pipe_down());
		}
		window.draw(bird.get_sprite());
		score_text.set_string(to_string(score));
		window.draw(score_text.get_game_text());
		window.display();



	}



}






void game() {

	if (game_process())
	{
		return game();
	}
}

