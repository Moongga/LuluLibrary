#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <windows.h>
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
	const int letters_count = 33;
	Texture ts[letters_count];

	for (int i = 0; i < letters_count; i++)
	{
		string path = "images/keyboard/uncursored_numbers/" + to_string(i) + ".png";
		ts[i].loadFromFile(path); // по очереди это будут все 33 буквы
	}

	// устанавливаем текстуры на спрайты
	// каждому спрайту необходимо задать текстуру
	sf::Sprite sprites[letters_count];

	// Координаты картинок с буквами
	int y = 277;
	int y_distanc_cf = 57;
	COORD positions[letters_count] = {
		{668, y}, // 0 а
		{723, y}, // 1 б
		{778, y}, // 2 в 
		{833, y}, // 3 г
		{888, y}, // 4 д
		{943, y}, // 5 е

		{668, y += y_distanc_cf}, // 6 ё
		{723, y}, // 7 ж
		{778, y}, // 8 з
		{833, y}, // 9 и
		{888, y}, // 10 й
		{943, y}, // 11 к

		{668, y += y_distanc_cf}, // 12 л
		{723, y}, // 13 м
		{778, y}, // 14 н
		{833, y}, // 15 о
		{888, y}, // 16 п
		{943, y}, // 17 р

		{668, y += y_distanc_cf}, // 18 с
		{723, y}, // 19 т
		{778, y}, // 20 у
		{833, y}, // 21 ф
		{888, y}, // 22 х
		{943, y}, // 23 ц

		{668, y += y_distanc_cf}, // 24 ч
		{723, y}, // 25 ш
		{778, y}, // 26 щ
		{833, y}, // 27 ъ
		{888, y}, // 28 ы
		{943, y}, // 29 ь

		{753, y += 50}, // 30 э
		{808, y}, // 31 ю
		{863, y}, // 32 я
	};

	for (int i = 0; i < 33; i++)
	{
		sprites[i].setTexture(ts[i]);
		sprites[i].setPosition(positions[i].X, positions[i].Y);
	}

	// Текстура фона игры
	Texture tx_game_scene;
	tx_game_scene.loadFromFile("images/game-scene_without-buttons.png");
	Sprite Backgr(tx_game_scene);
	Backgr.setPosition(0, 0);

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
		for (int i = 0; i < 33; i++)
		{
			window.draw(sprites[i]);
		}
		window.display();
	}
}