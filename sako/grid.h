#ifndef GRID_H_   /* Include guard */
#define GRID_H_

#include <vita2d.h>

float rad = 0.0f;
int grid_cell_size = 36;
    int grid_width = 960;
    int grid_height = 544;

struct grid_cursor {
      int  x ;
       int y ;
       int w;
       int h;
    };

    int column[30];
struct grid_cursor grid;

         //struct grid_cursor grid;
#endif