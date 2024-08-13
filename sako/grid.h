#ifndef GRID_H_   /* Include guard */
#define GRID_H_

#include <vita2d.h>

float rad = 0.0f;
int grid_cell_size = 36;
    int grid_width = 960;
    int grid_height = 544;

   //int window_width = (grid_width * grid_cell_size) + 1;
   // int window_height = (grid_height * grid_cell_size) + 1;

struct grid_cursor {
      int  x ;
       int y ;
       int w;
       int h;
    };

    int column[30];
struct grid_cursor grid;
void build_Grid();


void build_Grid()
{

	         column[0] = 0;
			 column[1] = 0 + grid_cell_size;
			 column[2] = column[1] + grid_cell_size;
			 column[3] = column[2] + grid_cell_size;
			 column[4] = column[3] + grid_cell_size;
			 column[5] = column[4] + grid_cell_size;
			 column[6] = column[5] + grid_cell_size;
			 column[7] = column[6] + grid_cell_size;
			 column[8] = column[7] + grid_cell_size;
			 column[9] = column[8] + grid_cell_size;
			 column[10] = column[9] + grid_cell_size;
			 column[11] =  column[10] +grid_cell_size;
			 column[12] = column[11] + grid_cell_size;
			 column[13] = column[12] + grid_cell_size;
			 column[14] = column[13] + grid_cell_size;
			 column[15] = column[14] + grid_cell_size;
			 column[16] = column[15] + grid_cell_size;
			 column[17] = column[16] + grid_cell_size;
			 column[18] = column[17] + grid_cell_size;
			 column[19] = column[18] + grid_cell_size;
			 column[20] = column[19] + grid_cell_size;
			 column[21] = column[20] + grid_cell_size;
			 column[22] = column[21] + grid_cell_size;
			 column[23] = column[22] + grid_cell_size;
			 column[24] = column[23] + grid_cell_size;
			 column[25] = column[24] + grid_cell_size;
			 column[26] = column[25] + grid_cell_size;

          

        // struct grid_cursor grid;
	  

        // struct grid_cursor grid;
	    grid.x = (grid_width - 1) / 2 * grid_cell_size;
        grid.y = (grid_height - 1) / 2 * grid_cell_size;
        grid.w = grid_cell_size;
        grid.h = grid_cell_size;

}
         //struct grid_cursor grid;
#endif
