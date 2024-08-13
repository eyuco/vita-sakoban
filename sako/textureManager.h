#ifndef TEXTUREMANAGER_H_   /* Include guard */
#define TEXTUREMANAGER_H_

#include <vita2d.h>
#include <stdbool.h>

bool load(char fileName[],char id[]);

 void draw(char id[], int x, int y, int width, int  height);

void createTextureFromSurface(vita2d_texture *texture);





#endif