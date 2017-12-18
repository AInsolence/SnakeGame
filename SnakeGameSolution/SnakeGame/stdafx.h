// stdafx.h: включаемый файл для стандартных системных включаемых файлов
// или включаемых файлов для конкретного проекта, которые часто используются, но
// не часто изменяются
//

#pragma once

#include "targetver.h"
// SFML Headers
#include "SFML/Graphics.hpp"
#include <SFML/Audio.hpp>
// STD headers
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <conio.h>
#include<memory>

/*
	Size of game screen costants division by BASE_SPRITE_SIZE must be even to avoid
	unexpected collisions
*/
constexpr int MAIN_WINDOW_WIDTH = 1344;
constexpr int MAIN_WINDOW_HIGHT = 756;

const sf::Color Black = sf::Color::Black;
