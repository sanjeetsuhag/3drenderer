#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include <SDL.h>

#include "display.h"

bool is_running = false;

void setup(void) {

	color_buffer = (uint32_t*)malloc(sizeof(uint32_t) * window_width * window_height);
	color_buffer_texture = SDL_CreateTexture(
		renderer,
		SDL_PIXELFORMAT_ARGB8888,
		SDL_TEXTUREACCESS_STREAMING,
		window_width,
		window_height
	);
	SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
}
void update(void) {}
void render(void) {
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderClear(renderer);

	draw_grid();
	draw_pixel(20, 20, 0xFFFFFF00);
	draw_rect(40, 90, 400, 800, 0xFFFF0000);


	render_color_buffer();
	clear_color_buffer(0xFFFFFF00);

	SDL_RenderPresent(renderer);
}

void process_input(void) {
	
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type) {
	case SDL_QUIT:
		is_running = false;
		break;
	case SDL_KEYDOWN:
		if (event.key.keysym.sym == SDLK_ESCAPE) {
			is_running = false;
		}
		break;
	}

}

int main(int argc, char* argv[]) {

	is_running = initialize_window();

	setup();

	while (is_running) {
		process_input();
		update();
		render();
	}

	return 0;
}
