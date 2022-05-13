#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;



class Background {
protected:
	Texture Background_texture;
	Sprite Background_srite;
public:

	Background() {

		Background_texture.loadFromFile("img/background.png");
		Background_srite.setTexture(Background_texture);
		Background_srite.setTextureRect(IntRect(0, 0, 256, 256));
		Background_srite.setScale(2, 2);
	}

	Sprite get_sprite() {
		return Background_srite;
	}
};







class Game_texts {
	Font font;
	Text game_text;
public:
	Game_texts(int font_size, string text, Vector2f position) {
		font.loadFromFile("font/Flappy-Bird.ttf");
		game_text.setString(text);
		game_text.setCharacterSize(font_size);
		game_text.setStyle(Text::Bold);
		game_text.setFont(font);
		game_text.setOrigin(game_text.getGlobalBounds().width / 2, game_text.getGlobalBounds().height / 2);
		game_text.setPosition(position);
		game_text.setOutlineThickness(1);
		game_text.setOutlineColor(Color::Black);
	}

	void setFillColor(Color color) {
		game_text.setFillColor(color);
	}

	void set_string(string text) {
		game_text.setString(text);
	}
	Text get_game_text() {
		return game_text;
	}

};





class Button {
	Texture texture;
	Sprite sprite;
public:

	Button(Image& image, Vector2f bPosition, IntRect bSprite) {
		image.createMaskFromColor(Color(255, 255, 255));
		this->texture.loadFromImage(image);
		sprite.setTexture(texture);
		sprite.setTextureRect(bSprite);

		sprite.setPosition(bPosition);
		sprite.setScale(2, 2);

	}
	void set_scale(float x, float y) {
		sprite.setScale(x, y);
	}
	void set_origin(int x, int y) {
		sprite.setOrigin(x, y);
	}

	void Set_TextureRect(IntRect rect) {

		sprite.setTextureRect(rect);
	}
	void Set_position(Vector2f position) {
		sprite.setPosition(position);
	}

	Sprite Get_sprite() {
		return sprite;
	}
	void Set_color(Color color) {
		sprite.setColor(color);
	}
};