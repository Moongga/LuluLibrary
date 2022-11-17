#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <windows.h>
#include "game.h"
using namespace sf;

void menu(RenderWindow& window)
{
    Texture StartT, QuitT, BackgroundT;
    StartT.loadFromFile("images/main_menu/Start_uncursored.png");
    QuitT.loadFromFile("images/main_menu/Quit_uncursored.png");
    BackgroundT.loadFromFile("images/main_menu/menu_whithout_buttons.png");
    Sprite Start(StartT), Quit(QuitT), Bg(BackgroundT);
    bool isMenu = 1;
    int menuNum = 0;
    Bg.setPosition(0, 0);

    StartT.loadFromFile("images/main_menu/Start_uncursored.png");
    QuitT.loadFromFile("images/main_menu/Quit_uncursored.png");

    Start.setPosition(390, 420);
    Quit.setPosition(390, 520);
    menuNum = 0;
    while (window.isOpen())
    {
        // �������� ������ ��� ������ � 
        sf::Event event;

        while (window.pollEvent(event))
        {
            // ���������� ����������� ������
            StartT.loadFromFile("images/main_menu/Start_uncursored.png");
            QuitT.loadFromFile("images/main_menu/Quit_uncursored.png");

            // �������� �� �� ������ ����������
            Start.setPosition(390, 420);
            Quit.setPosition(390, 520);

            // ������� ������. ��� "������ ������" ��������� �� ����, � �� "�����" - �������
            if (Mouse::isButtonPressed(Mouse::Left))
            {
                if (IntRect(390, 420, 240, 60).contains(Mouse::getPosition(window)))
                {
                    game(window);
                    while (!Keyboard::isKeyPressed(Keyboard::Escape));
                }
                if (IntRect(390, 520, 240, 60).contains(Mouse::getPosition(window)))
                {
                    window.close();
                    isMenu = false;
                }
            }

            // �������� �� ��, �������� �� ������ ����� � ������� ������ ��� ����, ����� ������� ������ ���������
			if (IntRect(390, 420, 240, 60).contains(Mouse::getPosition(window)))
			{
				StartT.loadFromFile("images/main_menu/Start_cursored.png");
			}
			if (IntRect(390, 520, 240, 60).contains(Mouse::getPosition(window)))
			{
				QuitT.loadFromFile("images/main_menu/Quit_cursored.png");
			}
        }

        //if (IntRect(390, 420, 240, 60).contains(Mouse::getPosition(window)))
        //{
        //    StartT.loadFromFile("images/main_menu/Start_cursored.png");
        //    menuNum = 1;
        //}
        //if (IntRect(390, 520, 240, 60).contains(Mouse::getPosition(window)))
        //{
        //    QuitT.loadFromFile("images/main_menu/Quit_cursored.png");
        //    menuNum = 2;
        //}


        window.draw(Bg);
        window.draw(Start);
        window.draw(Quit);
        window.display();

    }
}
