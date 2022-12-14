#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
//#include <SFML/Audio.hpp>
#include <iostream>
#include <windows.h>
#include "game.h"
using namespace sf;

void menu(RenderWindow& window)
{
    sf::Texture StartT, QuitT, BackgroundT;
    StartT.loadFromFile("images/main_menu/Start_uncursored.png");
    QuitT.loadFromFile("images/main_menu/Quit_uncursored.png");
    BackgroundT.loadFromFile("images/main_menu/menu_whithout_buttons.png");
    sf::Sprite Start(StartT), Quit(QuitT), Bg(BackgroundT);
    Bg.setPosition(0, 0);

    Start.setPosition(390, 420);
    Quit.setPosition(390, 520);

    //Music main_theme;
    //main_theme.openFromFile("music/harry.ogg");
    //main_theme.setLoop(true);
    //main_theme.setVolume(30);
    //main_theme.play();

	/*Music click;
	click.openFromFile("music/click.ogg");
	click.setLoop(false);
	click.setVolume(100);
	click.setPlayingOffset(sf::milliseconds(250));*/

    while (window.isOpen())
    {
        // создание ивента для работы с 
        sf::Event event;

        while (window.pollEvent(event))
        {
            // Подгружаем изображения кнопок
            StartT.loadFromFile("images/main_menu/Start_uncursored.png");
            QuitT.loadFromFile("images/main_menu/Quit_uncursored.png");

            // Помещаем их на нужные координаты
            Start.setPosition(390, 420);
            Quit.setPosition(390, 520);

            // Нажатие кнопок. При "Начать играть" переходит на игру, а на "Выход" - выходим
            if (Mouse::isButtonPressed(Mouse::Left))
            {
                if (IntRect(390, 420, 240, 60).contains(Mouse::getPosition(window)))
                {
                    game(window);
                }
                if (IntRect(390, 520, 240, 60).contains(Mouse::getPosition(window)))
                {
                    window.close();
                }
            }

            // Проверка на то, попадает ли курсор мышки в область кнопок для того, чтобы сделать эффект наведения
			if (IntRect(390, 421, 240, 65).contains(Mouse::getPosition(window)))
			{
				StartT.loadFromFile("images/main_menu/Start_cursored.png");
			}
			if (IntRect(390, 521, 240, 65).contains(Mouse::getPosition(window)))
			{
				QuitT.loadFromFile("images/main_menu/Quit_cursored.png");
			}
        }

        window.clear();
        window.draw(Bg);
        window.draw(Start);
        window.draw(Quit);
        window.display();
    }
}
