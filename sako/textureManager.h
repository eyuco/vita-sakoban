#ifndef TEXTUREMANAGER_H_   /* Include guard */
#define TEXTUREMANAGER_H_

#include <vita2d.h>
#include <stdbool.h>

extern unsigned char _binary_image_png_start;
extern unsigned char _binary_player1_png_start;

extern unsigned char _binary_zombie_png_start;
extern unsigned char _binary_image1_png_start;
extern unsigned char _binary_image2_png_start;
extern unsigned char _binary_target_png_start;
extern unsigned char _binary_bg_png_start;


struct surface_data{

};
bool load(char fileName,char id);

 void draw(char id[], int x, int y, int width, int  height);

void createTextureFromSurface(vita2d_texture *texture);





#endif