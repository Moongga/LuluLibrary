#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <windows.h>
#include "menu.h"
#include "game.h"
using namespace sf;

bool Menu()
{
    RenderWindow window(VideoMode(1024, 768), "Lulu Library");
    menu(window);
    return 0;
}

/// <summary>
/// int main() starts all other methods in main.cpp, game.h, menu.h
/// </summary>
/// <returns></returns>
int main()
{
    LoadMainTheme();
    LoadClick();
    Menu();
}
