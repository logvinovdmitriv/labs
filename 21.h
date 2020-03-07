
#pragma once
#include <iostream>
#include "SDL.h"
using namespace std;


struct snowfalls//
{

	SDL_Window* win;
	SDL_Renderer* rend;
	//SDL_HWSURFACE* surf;?????????????????????????????????????????????
	int WIDTH = NULL;//ширина окна
	int HEIGHT = NULL;//высота окна
	int kol = NULL;//кол-во снежинок
};
snowfalls snowfall;
struct snowflakes
{
	int x;
	int y;
	int size;
	int speed;
};
snowflakes snowflake;
int r;
//отрисовка снежинки
void drawing(snowfalls& snowfall, snowflakes *snowflake, int i);

//падение
void falling(snowfalls& snowfall, snowflakes* snowflake, int i);


