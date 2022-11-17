#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
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

    StartT.loadFromFile("images/main_menu/Start_uncursored.png");
    QuitT.loadFromFile("images/main_menu/Quit_uncursored.png");

    Start.setPosition(390, 420);
    Quit.setPosition(390, 520);
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
                    //while (!Keyboard::isKeyPressed(Keyboard::Escape));
                }
                if (IntRect(390, 520, 240, 60).contains(Mouse::getPosition(window)))
                {
                    window.close();
                    //isMenu = false;
                }
            }

            // Проверка на то, попадает ли курсор мышки в область кнопок для того, чтобы сделать эффект наведения
			if (IntRect(390, 420, 240, 60).contains(Mouse::getPosition(window)))
			{
				StartT.loadFromFile("images/main_menu/Start_cursored.png");
			}
			if (IntRect(390, 520, 240, 60).contains(Mouse::getPosition(window)))
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
