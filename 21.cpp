#include <iostream>
#include <time.h>
#include <ctime>
#include "SDL.h"
#include "Header.h"
#include "windows.h"

using namespace std;


int main(int argc, char* argv[])
{
	srand(time(NULL));
	r=rand();
	if (SDL_Init(SDL_INIT_VIDEO) < 0) { SDL_Quit(); return 0; }
	else
	{
		//структкра значений
		snowfalls snowfall;
	
		cout << u8"введи ширину окна\n";
		cin >> snowfall.WIDTH;
		cout << u8"введи высоту окна\n";
		cin >> snowfall.HEIGHT;
		cout << "введи кол-во снежинок\n";
		cin >> snowfall.kol;
		//создание массива структур  снежинок
		snowflakes* snowflake = new snowflakes[snowfall.kol];
	

		if (SDL_CreateWindowAndRenderer(snowfall.WIDTH, snowfall.HEIGHT, SDL_WINDOW_SHOWN, &snowfall.win, &snowfall.rend) != 0)
		{
			cout << "error\tcan't create Window And Renderer" << endl;
			return 1;
		}
		else
		{
			
			//SDL_Surface *img = SDL_LoadBMP("backstage.bmp");
			//if (img == NULL) { cout << "error\timage surface doesn't created"; return 0; }
			
			SDL_Event event;
			bool quit = false;
			
			
			//начальное положение
			for (int i = 0; i < snowfall.kol; i++)
			{
				r=rand();
				snowflake[i].x = rand() % (snowfall.WIDTH + 1);
				r=rand();
				
				snowflake[i].y = -1 * (rand() % (snowfall.HEIGHT + 1));
				r=rand();
				snowflake[i].size = rand() % 40 + 20;
				r = rand();
				snowflake[i].speed = (rand() % 3)+1;
				
			};

			for (int i = 0; i < snowfall.kol; i++)
			{

				cout << "snowflake[" << i << "].x= " << snowflake[i].x << endl;
				Sleep(50);
				cout << "snowflake[" << i << "].y= " << snowflake[i].y << endl << endl;
				Sleep(50);
			};

			while (!quit)
			{
				SDL_PollEvent(&event);
				if (event.type == SDL_QUIT) 	quit = true;
				
				SDL_SetRenderDrawColor(snowfall.rend, 255, 255, 255, 1);
				SDL_RenderClear(snowfall.rend);
				for (int i = 0; i < snowfall.kol; i++)
				{
					
					drawing(snowfall,snowflake, i);
					
					falling(snowfall,snowflake, i);
					//Sleep(5);
				
				};
				SDL_Delay(15);
				SDL_RenderPresent(snowfall.rend);
			};	
			
			
		};
		delete[]snowflake;
		SDL_DestroyRenderer(snowfall.rend);
		SDL_DestroyWindow(snowfall.win);
	};
	SDL_Quit();
	return 0;
};


//отрисовка снежинки
void drawing(snowfalls& snowfall, snowflakes *snowflake,int i)
{//снежинка 40*40
		SDL_SetRenderDrawColor(snowfall.rend, 152, 34, 88, 1);
		SDL_RenderDrawLine(snowfall.rend,snowflake[i].x, snowflake[i].y, snowflake[i].x, snowflake[i].y + snowflake[i].size);
		SDL_RenderDrawLine(snowfall.rend, snowflake[i].x - snowflake[i].size/2, snowflake[i].y + snowflake[i].size / 2, snowflake[i].x + snowflake[i].size / 2, snowflake[i].y+ snowflake[i].size / 2);
		SDL_RenderDrawLine(snowfall.rend, snowflake[i].x - snowflake[i].size / 2, snowflake[i].y + snowflake[i].size, snowflake[i].x + snowflake[i].size / 2, snowflake[i].y);
		SDL_RenderDrawLine(snowfall.rend, snowflake[i].x + snowflake[i].size / 2, snowflake[i].y + snowflake[i].size, snowflake[i].x - snowflake[i].size / 2, snowflake[i].y);
		
		SDL_RenderDrawLine(snowfall.rend, snowflake[i].x - snowflake[i].size / 2, snowflake[i].y + snowflake[i].size / 5, snowflake[i].x - snowflake[i].size * 0.3, snowflake[i].y+ snowflake[i].size / 5);
		SDL_RenderDrawLine(snowfall.rend, snowflake[i].x + snowflake[i].size*0.3, snowflake[i].y + snowflake[i].size/5, snowflake[i].x + snowflake[i].size / 2, snowflake[i].y + snowflake[i].size / 5);

		SDL_RenderDrawLine(snowfall.rend, snowflake[i].x - snowflake[i].size / 2, snowflake[i].y + snowflake[i].size * 0.8, snowflake[i].x - snowflake[i].size * 0.3, snowflake[i].y + snowflake[i].size * 0.8);
		SDL_RenderDrawLine(snowfall.rend, snowflake[i].x + snowflake[i].size * 0.3, snowflake[i].y + snowflake[i].size * 0.8, snowflake[i].x + snowflake[i].size / 2, snowflake[i].y + snowflake[i].size * 0.8);

		SDL_RenderDrawLine(snowfall.rend, snowflake[i].x - snowflake[i].size * 0.3, snowflake[i].y , snowflake[i].x - snowflake[i].size * 0.3, snowflake[i].y + snowflake[i].size / 5);
		SDL_RenderDrawLine(snowfall.rend, snowflake[i].x - snowflake[i].size * 0.3, snowflake[i].y + snowflake[i].size * 0.8, snowflake[i].x - snowflake[i].size*0.3, snowflake[i].y + snowflake[i].size);

		SDL_RenderDrawLine(snowfall.rend, snowflake[i].x + snowflake[i].size * 0.3, snowflake[i].y, snowflake[i].x + snowflake[i].size * 0.3, snowflake[i].y + snowflake[i].size / 5);
		SDL_RenderDrawLine(snowfall.rend, snowflake[i].x + snowflake[i].size * 0.3, snowflake[i].y + snowflake[i].size * 0.8, snowflake[i].x  + snowflake[i].size * 0.3, snowflake[i].y + snowflake[i].size);

		SDL_RenderDrawLine(snowfall.rend, snowflake[i].x + snowflake[i].size / 2, snowflake[i].y+ snowflake[i].size * 0.3, snowflake[i].x + snowflake[i].size / 4, snowflake[i].y + snowflake[i].size / 2);
		SDL_RenderDrawLine(snowfall.rend, snowflake[i].x + snowflake[i].size / 2, snowflake[i].y + snowflake[i].size * 0.7, snowflake[i].x + snowflake[i].size/4, snowflake[i].y + snowflake[i].size / 2);

		SDL_RenderDrawLine(snowfall.rend, snowflake[i].x - snowflake[i].size / 2, snowflake[i].y + snowflake[i].size * 0.3, snowflake[i].x - snowflake[i].size / 4, snowflake[i].y + snowflake[i].size / 2);
		SDL_RenderDrawLine(snowfall.rend, snowflake[i].x - snowflake[i].size / 2, snowflake[i].y + snowflake[i].size * 0.7, snowflake[i].x - snowflake[i].size / 4, snowflake[i].y + snowflake[i].size / 2);

		SDL_RenderDrawLine(snowfall.rend, snowflake[i].x - snowflake[i].size / 5, snowflake[i].y , snowflake[i].x , snowflake[i].y + snowflake[i].size / 4);
		SDL_RenderDrawLine(snowfall.rend, snowflake[i].x + snowflake[i].size / 5, snowflake[i].y , snowflake[i].x , snowflake[i].y + snowflake[i].size / 4);

		SDL_RenderDrawLine(snowfall.rend, snowflake[i].x - snowflake[i].size / 5, snowflake[i].y+ snowflake[i].size, snowflake[i].x, snowflake[i].y + snowflake[i].size * 0.75);
		SDL_RenderDrawLine(snowfall.rend, snowflake[i].x + snowflake[i].size / 5, snowflake[i].y+ snowflake[i].size, snowflake[i].x, snowflake[i].y + snowflake[i].size * 0.75);






};


//падение
void falling(snowfalls& snowfall,snowflakes *snowflake, int i)
{
	
		if (snowflake[i].y >= snowfall.HEIGHT)
		{	
			r=rand();
			snowflake[i].x = rand() % (snowfall.WIDTH+1);
			
			r=rand();
			snowflake[i].y =   -1*(rand() % snowfall.HEIGHT+1);
			r=rand();

			
		};
		r=rand();
		
		snowflake[i].y += snowflake[i].speed;
		rand();
		snowflake[i].x += rand()%20 * sin(snowflake[i].y*3.14/180+(snowfall.WIDTH/50));
		//SDL_Delay(y);
};


