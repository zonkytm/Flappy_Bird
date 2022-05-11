#include "player.h"




void player::update(float time) {


	switch (state)
	{

	case dead:

		break;
	case jump:
		CurrenFrame += 0.01 * time;
		if (CurrenFrame > 3)
		{
			CurrenFrame -= 3;
		}
		player_sprite.setTextureRect(IntRect(16 * (int)CurrenFrame, 0, 16, 16));


		break;

	default:
		break;
	}




}



void player::ban_exit() {
	
	if (player_sprite.getPosition().y + player_sprite.getGlobalBounds().height / 2 > 512) {
		player_sprite.setPosition(Vector2f(player_sprite.getPosition().x, 512 - player_sprite.getGlobalBounds().height / 2));
		state = dead;
	}
	if (player_sprite.getPosition().y - player_sprite.getGlobalBounds().height / 2 < 0) {

		player_sprite.setPosition(Vector2f(player_sprite.getPosition().x, 0 + player_sprite.getGlobalBounds().height / 2));


	}
	if (state != dead)
	{


		if (Keyboard::isKeyPressed(Keyboard::Space) and isSpace != 1) {
			speed = 0;
			speed -= velocity;
			isSpace = 1;
			state = jump;
		}
		else if (!Keyboard::isKeyPressed(Keyboard::Space))
		{
			isSpace = 0;
		}
	}
}



void player::moving(float time) {
	float x = player_sprite.getPosition().x;
	float y = player_sprite.getPosition().y;
	speed += boostfall * time;
	y += speed * time;
	player_sprite.setPosition(x, y);

}

void collisions(player& player_, pipes* pipe, int size) {

	for (int i = 0; i < size; i++)
	{


		if (player_.get_sprite().getGlobalBounds().intersects(pipe[i].get_pipe_down().getGlobalBounds()) or player_.get_sprite().getGlobalBounds().intersects(pipe[i].get_pipe_up().getGlobalBounds()))
		{
			player_.set_state(Statement::dead);
		}
	}



}