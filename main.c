#include "stdio.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_image.h>

#define START_X		0
#define START_Y		0
#define PIXEL_WIDTH 1
#define SPEED 500

int main()
{
    al_init();
	al_install_keyboard();

    FILE *diffs = fopen("diffs.bin", "rb");

    al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW);
    ALLEGRO_DISPLAY *display = al_create_display(1000, 1000);
    al_clear_to_color(al_map_rgb(255, 255, 255));
    al_flip_display();
    al_wait_for_vsync();


    int width, height;
    width = al_get_display_width(display);
    height = al_get_display_height(display);
    int range_end_x, range_end_y;
    range_end_x = START_X + width / PIXEL_WIDTH + 1;
    range_end_y = START_Y + height / PIXEL_WIDTH + 1;

    printf("Screen width: %d, height: %d\n", width, height);
    printf("Max pixels x: %d, y: %d\n", range_end_x - START_X, range_end_y - START_Y);

    ALLEGRO_COLOR colors[] = {
        al_map_rgb(255,255,255),
        al_map_rgb(228,228,228),
        al_map_rgb(136,136,136),
        al_map_rgb(34,34,34),
        al_map_rgb(255,167,209),
        al_map_rgb(229,0,0),
        al_map_rgb(229,149,0),
        al_map_rgb(160,106,66),
        al_map_rgb(229,217,0),
        al_map_rgb(148,224,68),
        al_map_rgb(2,190,1),
        al_map_rgb(0,211,221),
        al_map_rgb(0,131,199),
        al_map_rgb(0,0,234),
        al_map_rgb(207,110,228),
        al_map_rgb(130,0,128)
    };

    int i = 0, j, k, f = 0;
    int a, b, c, d;
    while(fread(&a, sizeof(int), 1, diffs)){
        fread(&b, sizeof(int), 1, diffs);
        fread(&c, sizeof(int), 1, diffs);
        fread(&d, sizeof(int), 1, diffs);
		i++;

        if(b < START_X || c < START_Y || b > range_end_x || c > range_end_y)
            continue;

        for(j = 0; j < PIXEL_WIDTH; j++){
            for(k = 0; k < PIXEL_WIDTH; k++){
                al_draw_pixel((b - START_X) * PIXEL_WIDTH + j, (c - START_Y) * PIXEL_WIDTH + k, colors[d]);
            }
        }
        if(i % SPEED == 0){
            al_flip_display();
            al_wait_for_vsync();
			ALLEGRO_KEYBOARD_STATE state;
			al_get_keyboard_state(&state);
			if(al_key_down(&state, ALLEGRO_KEY_SPACE)){
				while(1){
					al_get_keyboard_state(&state);
					if(al_key_down(&state, ALLEGRO_KEY_C)){
						break;
					}	

				}
			}
        }
    }

    fclose(diffs);
    while(1){

    }

    return 0;
}
