#include "window.h"

WIN_Viewport WIN_CreateViewport(char *name) {
    WIN_Viewport viewport;
    viewport.window = SDL_CreateWindow(
	name,
    	SDL_WINDOWPOS_CENTERED,
    	SDL_WINDOWPOS_CENTERED,
    	WIN_WIDTH,
	WIN_HEIGHT,
	0
    );
    viewport.renderer = SDL_CreateRenderer(
	viewport.window, -1, 0
    );	
    return(viewport);
}

bool WIN_CheckQuit() {
    SDL_Event event;
    while(SDL_PollEvent(&event)) {
        switch(event.type) {
            case SDL_QUIT:
                return(0);
        }
    }
    return(1);
}