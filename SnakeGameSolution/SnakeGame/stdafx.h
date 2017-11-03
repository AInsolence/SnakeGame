// stdafx.h: включаемый файл для стандартных системных включаемых файлов
// или включаемых файлов для конкретного проекта, которые часто используются, но
// не часто изменяются
//

#pragma once

#include "targetver.h"
#include "SFML/Graphics.hpp"
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <conio.h>

using int32 = int;
using FPair = std::pair<int32, int32>;
using FVector = std::vector<char>;
using FField = std::vector< std::vector<char> >;
using FString = std::string;

// Size of game screen costants
// TODO replace this variables  into GAME class
constexpr int32 MAIN_WINDOW_WIDTH = 1302;
constexpr int32 MAIN_WINDOW_HIGHT = 672;

// TODO: Установите здесь ссылки на дополнительные заголовки, требующиеся для программы
