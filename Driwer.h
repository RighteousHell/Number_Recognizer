#pragma once
#include <SFML/Graphics.hpp>

class Driwer
{
private:

protected:
	sf::RenderWindow main_window = { sf::VideoMode(800, 600), L"Number_recognizer. Press C to clear screen", sf::Style::Default };
	sf::RenderWindow gues_window = { sf::VideoMode(250, 600), L"Guesses of programms", sf::Style::Default };

	sf::RenderTexture canvas;

	sf::Sprite sprite;

	sf::Color color = { 255, 255, 255 }; // black

	sf::RectangleShape brush;

	sf::Vector2f lastPos;

	sf::Font gen_font;

	sf::Text text_gues_inform;
	sf::Text text_gues_attempt;

	bool isDrawing = false;
	const float brush_size = 15;



public:
	Driwer() = default;
	int8_t preconfiguration_driwer();
	int8_t driwing_windows();
};

