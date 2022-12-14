#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <windows.h>
#include "files.h"
#include <string>
#include <sstream>
#include <WinUser.h>
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
	Texture ts_right[letters_count];
	Texture ts_wrong[letters_count];

	// Массив с английским алфавитом
	string eng_alphabet = "abcdefghijklmnopqrstuvwxyz";

	int tries_amount = 6;

	for (int i = 0; i < letters_count; i++)
	{
		string path = "images/keyboard/uncursored/" + to_string(i) + ".png";
		string path_right = "images/keyboard/right/" + to_string(1) + "-" + to_string(i) + ".png";
		string path_wrong = "images/keyboard/wrong/" + to_string(0) + "-" + to_string(i) + ".png";
		ts[i].loadFromFile(path); // загружаем обычные 26 букв
		ts_right[i].loadFromFile(path_right); // загружаем 26 правильных букв
		ts_wrong[i].loadFromFile(path_wrong); // загружаем 26 неправильных букв
	}

	// устанавливаем текстуры на спрайты
	// каждому спрайту необходимо задать текстуру
	sf::Sprite sprites[letters_count];
	sf::Sprite right_sprites[letters_count];
	sf::Sprite wrong_sprites[letters_count];

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
	tx_game_scene.loadFromFile("images/english_game-scene.png");
	Sprite Backgr(tx_game_scene);
	Backgr.setPosition(0, 0);

	// Загружаем плашку с победой
	Texture tx_win_pop_up;
	tx_win_pop_up.loadFromFile("images/victory-or-defeat/victory_pre-finish.png");
	Sprite win_pop_up(tx_win_pop_up);

	// Загружаем плашку с поражением
	Texture tx_defeat_pop_up;
	tx_defeat_pop_up.loadFromFile("images/victory-or-defeat/defeat_pre-finish.png");
	Sprite defeat_pop_up(tx_defeat_pop_up);

	// Загружаем кнопки для победы или поражения
	Texture tx_unc_start_again, tx_curs_start_again, tx_unc_exit, tx_curs_exit;
	tx_unc_start_again.loadFromFile("images/victory-or-defeat/uncursored_start-again.png");
	tx_curs_start_again.loadFromFile("images/victory-or-defeat/cursored_start-again.png");
	tx_unc_exit.loadFromFile("images/victory-or-defeat/uncursored_exit.png");
	tx_curs_exit.loadFromFile("images/victory-or-defeat/cursored_exit.png");
	Sprite unc_start_again(tx_unc_start_again), curs_start_again(tx_curs_start_again), unc_exit(tx_unc_exit), curs_exit(tx_curs_exit);

	/// Работа с загаданным словом
	string random_word = GetWord();
	// переменная для вывода скрытого слова с нижнем подчёркиванием
	string hidden_word;
	int words_amount = random_word.length();
	int words_left = words_amount;

	cout << words_amount << "\n" << random_word << endl;

	for (int i = 0; i < words_amount; i++)
	{
		hidden_word += "_ ";
	}
	hidden_word.pop_back();

	// шрифт, вывод рандомного слова
	sf::Font font;
	font.loadFromFile("font/dejavu.ttf");

	// Текст загаданного слова
	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(40);
	text.setFillColor(sf::Color(78, 60, 33));
	text.setString(hidden_word);
	const int centerPos = 820;
	text.setPosition(centerPos - text.getGlobalBounds().width / 2, 200); // getGlobalBounds().width - измеряет ширину текста

	// Текст попыток
	sf::Text text_tries_amount;
	text_tries_amount.setFont(font);
	text_tries_amount.setCharacterSize(30);
	text_tries_amount.setFillColor(sf::Color(160, 141, 50));
	text_tries_amount.setString(to_string(tries_amount));
	text_tries_amount.setPosition(974 - text_tries_amount.getGlobalBounds().width / 2, 101);

	int index_clicked_letter;

	while (window.isOpen())
	{
		// Создание ивента для работы с кнопками
		sf::Event event;

		while (window.pollEvent(event))
		{
			if ((words_left == 0 && tries_amount > 0) || (tries_amount == 0))
			{
				tx_unc_start_again.loadFromFile("images/victory-or-defeat/uncursored_start-again.png");
				unc_start_again.setPosition(196, 569);

				tx_unc_exit.loadFromFile("images/victory-or-defeat/uncursored_exit.png");
				unc_exit.setPosition(594, 569);
			}

			// Нажатие кнопок
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				if (!(words_left == 0 && tries_amount > 0))
				{
					// Проверка реагирования нажатия на 26 букв
					for (int i = 0; i < letters_count; i++)
					{
						if (IntRect(positions[i].X, positions[i].Y, 30, 30).contains(Mouse::getPosition(window)))
						{
							// Переменная для выявления, отгадал ли пользователь букву, или нет (в таком случае рисуется часть человечка)
							int comparate = words_left;

							index_clicked_letter = i;
							cout << eng_alphabet[index_clicked_letter] << "\n";

							// Проверяем букву пользователя
							for (int a = 0; a < words_amount; a++)
							{
								// Если нажатая буква = переборной букве
								if (eng_alphabet[index_clicked_letter] == random_word[a])
								{
									right_sprites[index_clicked_letter].setTexture(ts_right[index_clicked_letter]);
									right_sprites[index_clicked_letter].setPosition(positions[i].X, positions[i].Y);

									words_left--;
									hidden_word[a * 2] = eng_alphabet[index_clicked_letter];
									text.setString(hidden_word);
									text.setPosition(centerPos - text.getGlobalBounds().width / 2, 200);
								}
							}

							// Если переменные равны, значит входа в цикл не было (и переменная words_left не снижалась), в следствии чего буква не была отгадана
							if (comparate == words_left)
							{
								wrong_sprites[index_clicked_letter].setTexture(ts_wrong[index_clicked_letter]);
								wrong_sprites[index_clicked_letter].setPosition(positions[i].X, positions[i].Y);

								tries_amount--;
								text_tries_amount.setString(to_string(tries_amount));
								text_tries_amount.setPosition(974 - text_tries_amount.getGlobalBounds().width / 2, 101);
							}
							positions[i].X = 9999;
							positions[i].Y = 9999;

							// Если все слова отгаданы, то победа
							if (words_left == 0 && tries_amount > 0)
							{
								win_pop_up.setPosition(0, 0);
								unc_start_again.setPosition(196, 569);
								unc_exit.setPosition(594, 569);
							}

							// Если попытки закончились, то поражение
							if (tries_amount == 0)
							{
								defeat_pop_up.setPosition(0, 0);
								unc_start_again.setPosition(196, 569);
								unc_exit.setPosition(594, 569);
							}
						}
					}
				}
				// Проверка нажатия кнопок для выигрыша
				else
				{
					if (IntRect(196, 569, 240, 60).contains(Mouse::getPosition(window)))
					{
						game(window);
					}
					if (IntRect(594, 569, 240, 60).contains(Mouse::getPosition(window)))
					{
						window.close();
					}
				}

				// Проверка нажатия кнопок для проигрыша
				if (tries_amount == 0)
				{
					if (IntRect(196, 569, 240, 60).contains(Mouse::getPosition(window)))
					{
						game(window);
					}
					if (IntRect(594, 569, 240, 60).contains(Mouse::getPosition(window)))
					{
						window.close();
					}
				}
			}

			// проверки наведённых кнопок для выигрыша/проигрыша
			if ((words_left == 0 && tries_amount > 0) || (tries_amount == 0))
			{
				if (IntRect(196, 569, 240, 60).contains(Mouse::getPosition(window)))
				{
					tx_unc_start_again.loadFromFile("images/victory-or-defeat/cursored_start-again.png"); // наведённая кнопка "начать сначала"
					unc_start_again.setPosition(196, 569);
				}
				if (IntRect(594, 569, 240, 60).contains(Mouse::getPosition(window)))
				{
					tx_unc_exit.loadFromFile("images/victory-or-defeat/cursored_exit.png"); // наведённая кнопка "выход"
					unc_exit.setPosition(594, 569);
				}
			}
		}

		window.draw(Backgr);
		// Цикл для отображение картинок букв
		for (int i = 0; i < letters_count; i++)
		{
			window.draw(sprites[i]);
			window.draw(right_sprites[i]);
			window.draw(wrong_sprites[i]);
		}
		window.draw(text_tries_amount);
		window.draw(text);

		// изображение плашки/кнопки для победы
		if (words_left == 0 && tries_amount > 0)
		{
			window.draw(win_pop_up);
			window.draw(unc_start_again);
			window.draw(unc_exit);
		}

		// изображение плашки/кнопки для поражения
		if (tries_amount == 0)
		{
			window.draw(defeat_pop_up);
			window.draw(unc_start_again);
			window.draw(unc_exit);
		}
		window.display();
	}
}