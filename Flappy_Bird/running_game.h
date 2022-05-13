#pragma once
#include <SFML/Graphics.hpp>
#include "UI.h"
#include "player.h"
#include "pipes.h"
#include "vector"
using namespace sf;


RenderWindow window(sf::VideoMode(512, 512), "FLappy Bird");

int Best_score = 0;

bool game_process(int &Best_score) {

	player bird(Vector2f(200, 200));

	Background background;
	Clock game_clock;
	float time_to_spawn_pipe=0, timer=0;
	const int size = 3;
	pipes pipe[size];
	int score = 0;
	bool ispause = 0;
	Image button_image;
	button_image.loadFromFile("img/buttons.png");
	Button pause(button_image, Vector2f(10, 10), IntRect(16, 16, 16, 16)),
		retry_button(button_image, Vector2f(512/2, 512/2+100), IntRect(0, 48, 16, 16));
	retry_button.set_scale(5, 5);
	retry_button.set_origin(retry_button.Get_sprite().getLocalBounds().width / 2, retry_button.Get_sprite().getLocalBounds().height / 2);

	for (size_t i = 0; i < size; i++)
	{
		pipe[i].set_position(Vector2f(512 + pipe[i].get_pipe_up().getGlobalBounds().width / 2+ 250*i, rand() % 200 + 190));
		
	}
	
	Game_texts score_text(75,to_string(score), Vector2f(512/2,0)), 
		best_score_text(75, to_string(score), Vector2f(512 / 2-150, retry_button.Get_sprite().getPosition().y - retry_button.Get_sprite().getGlobalBounds().height / 2 - 100)),
		loose_text(75,"Try again!",Vector2f(512/2, best_score_text.get_game_text().getPosition().y- best_score_text.get_game_text().getGlobalBounds().height/2-100));
	best_score_text.setFillColor(Color::Yellow);
	score_text.setFillColor(Color::White);
	loose_text.setFillColor(Color::Red);


	while (window.isOpen())
	{
		Event event;
		Vector2i mouse_position= Mouse::getPosition(window);

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
						if (retry_button.Get_sprite().getGlobalBounds().contains(mouse_position.x, mouse_position.y))
						{
							return 1;
						}
					}
				}
			}

			if (event.type==Event::MouseButtonPressed)
			{
				if (event.key.code==Mouse::Left)
				{
					if (pause.Get_sprite().getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).x))
					{
						
						if (!ispause)
						{
							pause.Set_TextureRect(IntRect(32, 0, 16, 16));
						}
						else
						{
							pause.Set_TextureRect(IntRect(16, 16, 16, 16));
						}

						ispause = !ispause;

					}

				}
			}
		}
		if (!ispause)
		{


			if (bird.get_state() != dead)
			{
				for (int i = 0; i < size; i++)
				{
					pipe[i].moving(0.2, time, score);
					
				}

				collisions(bird, pipe, size);
			}
			bird.moving(time);
			bird.ban_exit();
			bird.update(time);
			score_counting(bird, pipe, size, score);
		}

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
		
		window.draw(pause.Get_sprite());
		if (bird.get_state() == dead)
		{
			if (score>Best_score)
			{
				Best_score = score;
				
			}
			best_score_text.set_string("Best score "+to_string(Best_score));
			window.draw(retry_button.Get_sprite());
			window.draw(loose_text.get_game_text());
			window.draw(best_score_text.get_game_text());
			
		}
		window.display();
		


	}



}






void game() {

	if (game_process(Best_score))
	{
		return game();
	}
	
}

