#pragma once
#include <SFML/Audio.hpp>
using namespace sf;

Music main_theme;
Music click;

void LoadMainTheme() {
    main_theme.openFromFile("music/harry.ogg");
    main_theme.setLoop(true);
    main_theme.setVolume(4);
    main_theme.play();
}

void LoadClick()
{
    click.openFromFile("music/click.ogg");
    click.setLoop(false);
    click.setVolume(20);
}