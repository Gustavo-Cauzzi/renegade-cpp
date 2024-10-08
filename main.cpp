#define SDL_MAIN_HANDLED
#include<SDL2/SDL.h>
#include<stdio.h>

#include<Color.h>
#include<Point.h>
#include<Polygon.h>
#include<Renegade.h>
#include<Line.h>
#include<vector>
using namespace std;


// SDL stuff
SDL_Window* pWindow = 0;
SDL_Renderer* pRenderer = 0;
SDL_Surface * window_surface;

int height = 480, width = 640;

Renegade renegade;
Line ground;
Utils utils;

void setup(){
    renegade = Renegade(window_surface, pRenderer, Color(window_surface, 255, 0, 0));
    ground = Line( // TODO rotate this line using math
         window_surface,
         pRenderer,
         Point(renegade.firstPoint.getX(), renegade.firstPoint.getY()),
         Point(renegade.firstPoint.getX() + 900, renegade.firstPoint.getY()),
         //Point(0, 0),
         //Point(900, 0),
         Color(window_surface, 0, 0, 0)
    );
    ground.rotate(-30);
    ground.translate(-200, 317);
    utils = Utils();
}

void display()
{
    renegade.draw();
    renegade.update();
    ground.draw();
    /*utils.floodFill(
        window_surface,
        pRenderer,
        width - 10,
        height - 10,
        Color(window_surface, 0, 0, 0),
        Color(window_surface, 255, 255, 255)
    );*/
}

// Driver code
int main(int argc, char* args[])
{

	SDL_Event event;

	// initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) >= 0)
	{
		// if succeeded create our window
		pWindow = SDL_CreateWindow("Atoleide",
					SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
														width, height,
												SDL_WINDOW_SHOWN);

		// if the window creation succeeded create our renderer
		if (pWindow != 0) {
			pRenderer = SDL_CreateRenderer(pWindow, -1, 0);
			window_surface = SDL_GetWindowSurface(pWindow);
        }

	}
	else
		return 1; // sdl could not initialize

    setup();
	while (1)
	{
		if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
			break;

		// Sets background color to white
		SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);
		SDL_RenderClear(pRenderer);

        display();

		// show the window
		SDL_RenderPresent(pRenderer);
	}

	// clean up SDL
	SDL_Quit();
	return 0;
}
