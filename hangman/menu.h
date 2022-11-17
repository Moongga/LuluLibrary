#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <windows.h>
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
    while (isMenu)
    {
        StartT.loadFromFile("images/main_menu/Start_uncursored.png");
        QuitT.loadFromFile("images/main_menu/Quit_uncursored.png");

        Start.setPosition(390, 420);
        Quit.setPosition(390, 520);
        menuNum = 0;
        if (IntRect(390, 420, 240, 60).contains(Mouse::getPosition(window)))
        {
            StartT.loadFromFile("images/main_menu/Start_cursored.png");
            menuNum = 1;
        }
        if (IntRect(390, 520, 240, 60).contains(Mouse::getPosition(window)))
        {
            QuitT.loadFromFile("images/main_menu/Quit_cursored.png");
            menuNum = 2;
        }
        if (Mouse::isButtonPressed(Mouse::Left))
        {
            if (menuNum == 1)
            {
                window.display();
                while (!Keyboard::isKeyPressed(Keyboard::Escape));
            }
            if (menuNum == 2)
            {
                window.close();
                isMenu = false;
            }
        }
        window.draw(Bg);
        window.draw(Start);
        window.draw(Quit);
        window.display();
    }
}
