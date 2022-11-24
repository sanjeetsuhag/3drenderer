#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <SDL.h>

#define FPS  144
#define FRAME_TARGET_TIME (1000 /  FPS)

enum cull_method {
	CULL_NONE,
	CULL_BACKFACE
} cull_method;

enum render_method {
	RENDER_WIRE,
	RENDER_WIRE_VERTEX,
	RENDER_FILL_TRIANGLE,
	RENDER_FILL_TRIANGLE_WIRE,
	RENDER_TEXTURED,
	RENDER_TEXTURED_WIRE
} render_method;

extern uint32_t window_width;
extern uint32_t window_height;

extern SDL_Window* window;
extern SDL_Renderer* renderer;

extern uint32_t* color_buffer;
extern SDL_Texture* color_buffer_texture;


bool initialize_window(void);
void draw_grid(void);
void draw_rect(int x, int y, int width, int height, uint32_t color);
void draw_pixel(int x, int y, uint32_t color);
void draw_line(int x0, int y0, int x1, int y1, uint32_t color);
void draw_triangle(int x0, int y0, int x1, int y1, int x2, int y2, uint32_t color);
void render_color_buffer();
void clear_color_buffer(uint32_t color);
void destroy_window(void);
uint32_t light_apply_intensity(uint32_t original_color, float percentage_factor);

#endif