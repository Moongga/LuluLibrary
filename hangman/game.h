#pragma once
#pragma warning(disable  : 4996)
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <windows.h>
#include "files.h"
#include <string>
using namespace sf;
using namespace std;

/// <summary>
/// method that makes necessary textures for second screen(game scene)
/// In this method we load game scene background and buttons into window. Also we check mouse position and change uncursored button images to cursored
/// </summary>
/// <param name="window"></param>
void game(RenderWindow& window)
{
	// Текстуры букв
	const int letters_count = 26;
	Texture ts[letters_count];

	for (int i = 0; i < letters_count; i++)
	{
		string path = "images/keyboard/english/uncursored/" + to_string(i) + ".png";
		ts[i].loadFromFile(path); // по очереди это будут все 33 буквы
	}

	// устанавливаем текстуры на спрайты
	// каждому спрайту необходимо задать текстуру
	sf::Sprite sprites[letters_count];

	// Координаты картинок с буквами
	int y = 277;
	int y_distanc_cf = 57;
	COORD positions[letters_count] = {
		{668, y}, // 0 a
		{723, y}, // 1 b
		{778, y}, // 2 c 
		{833, y}, // 3 d
		{888, y}, // 4 e
		{943, y}, // 5 f

		{668, y += y_distanc_cf}, // 6 g
		{723, y}, // 7 h
		{778, y}, // 8 i
		{833, y}, // 9 j
		{888, y}, // 10 k
		{943, y}, // 11 l

		{668, y += y_distanc_cf}, // 12 m
		{723, y}, // 13 n
		{778, y}, // 14 o
		{833, y}, // 15 p
		{888, y}, // 16 q
		{943, y}, // 17 r

		{668, y += y_distanc_cf}, // 18 s
		{723, y}, // 19 t
		{778, y}, // 20 u
		{833, y}, // 21 v
		{888, y}, // 22 w
		{943, y}, // 23 x

		{778, y += y_distanc_cf}, // 24 y
		{833, y}, // 25 z
	};

	for (int i = 0; i < letters_count; i++)
	{
		sprites[i].setTexture(ts[i]);
		sprites[i].setPosition(positions[i].X, positions[i].Y);
	}

	// Текстура фона игры
	Texture tx_game_scene;
	tx_game_scene.loadFromFile("images/clear_game-scene.png");
	Sprite Backgr(tx_game_scene);
	Backgr.setPosition(0, 0);

	// шрифт
	sf::Font font;
	font.loadFromFile("font/dejavu.ttf");

	sf::Text text;
	text.setPosition(758, 200);
	text.setFont(font);
	text.setCharacterSize(40);
	text.setFillColor(sf::Color(78, 60, 33)); 
	text.setString(GetWord());

	int cursor_enter = 0;

	while (window.isOpen())
	{
		// Создание ивента для работы с кнопками
		sf::Event event;

		while (window.pollEvent(event))
		{
			// Нажатие кнопок
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				// Проверка реагирования нажатия на 33 буквы
				for (int i = 0; i < 33; i++)
				{
					if (IntRect(positions[i].X, positions[i].Y, 30, 30).contains(Mouse::getPosition(window)))
					{
						window.close();
					}
				}
			}
		}

		window.clear();
		window.draw(Backgr);
		// Цикл для отображение картинок букв
		for (int i = 0; i < letters_count; i++)
		{
			window.draw(sprites[i]);
		}
		window.draw(text);
		window.display();
	}
}