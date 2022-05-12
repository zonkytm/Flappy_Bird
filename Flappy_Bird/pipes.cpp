#include "pipes.h"



void pipes::moving(float speed,float time,int& score) {

	if (pipes_sprite_up.getPosition().x + pipes_sprite_up.getGlobalBounds().width / 2 > 0)
	{
		pipes_sprite_up.move(-speed * time, 0);
		pipes_sprite_down.move(-speed * time, 0);
		
	}
	else {
		ischecked = 0;
		pipes_sprite_up.setPosition(700 + pipes_sprite_up.getGlobalBounds().width / 2, rand() % 300+1);
		pipes_sprite_down.setPosition(700 + pipes_sprite_up.getGlobalBounds().width / 2, pipes_sprite_up.getPosition().y+150);
	}
	
	


}



void pipes::set_position(Vector2f position) {
	pipes_sprite_up.setPosition(position.x, position.y);
	pipes_sprite_down.setPosition(pipes_sprite_up.getPosition().x, pipes_sprite_up.getPosition().y + 150);

}