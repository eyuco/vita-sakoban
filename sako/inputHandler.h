#ifndef INPUTHANDLER_H_   /* Include guard */
#define INPUTHANDLER_H_
#include <psp2/ctrl.h>
#include "collision.h"
#include "grid.h"

SceCtrlData pad;

bool isFacingUp = false;
bool isFacingRight = false;
bool isFacingLeft = false;
bool isFacingDown = false;

void handleInput()
{
    if (pad.buttons & SCE_CTRL_RIGHT)
		{
          player.x += grid_cell_size;
        }
    if (pad.buttons & SCE_CTRL_LEFT)
		{
          player.x -= grid_cell_size;

          checkTileCollision();
          /* if(check_collision(player,lvl3Columns[26]))
			 	{
			 		player.x += grid_cell_size;
                    //player.x -= lvl3Columns[13].x;
			 	}

           if(check_collision(player,lvl3Columns[25]))
			 	{
			 		player.x += grid_cell_size;
                    //player.x -= lvl3Columns[13].x;
			 	}


           if(check_collision(player,lvl3Columns[24]))
			 	{
			 		player.x += grid_cell_size;
                    //player.x -= lvl3Columns[13].x;
			 	}



           if(check_collision(player,lvl3Columns[23]))
			 	{
			 		player.x += grid_cell_size;
                    //player.x -= lvl3Columns[13].x;
			 	}

           if(check_collision(player,lvl3Columns[22]))
			 	{
			 		player.x += grid_cell_size;
                    //player.x -= lvl3Columns[13].x;
			 	}

           if(check_collision(player,lvl3Columns[21]))
			 	{
			 		player.x += grid_cell_size;
                    //player.x -= lvl3Columns[13].x;
			 	}

            if(check_collision(player,lvl3Columns[20]))
			 	{
			 		player.x += grid_cell_size;
                    //player.x -= lvl3Columns[13].x;
			 	}


            if(check_collision(player,lvl3Columns[19]))
			 	{
			 		player.x += grid_cell_size;
                    //player.x -= lvl3Columns[13].x;
			 	}

			if(check_collision(player,lvl3Columns[18]))
			 	{
			 		player.x += grid_cell_size;
                    //player.x -= lvl3Columns[13].x;
			 	}
           if(check_collision(player,lvl3Columns[17]))
			 	{
			 		player.x += grid_cell_size;
                    //player.x -= lvl3Columns[13].x;
			 	}
			 	  if(check_collision(player,lvl3Columns[14]))
			 	{
			 		player.x += grid_cell_size;
                    //player.x -= lvl3Columns[13].x;
			 	}*/
                
        }
    if (pad.buttons & SCE_CTRL_UP)
		{
          player.y -= grid_cell_size;
        }
    if (pad.buttons & SCE_CTRL_DOWN)
		{
          player.y += grid_cell_size;
        }
}
#endif