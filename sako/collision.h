#ifndef COLLISION_H_   /* Include guard */
#define COLLISION_H_
#include <stdbool.h>
#include "grid.h"

#define WALKING_ANIMATION_FRAMES  2
//int foo(int x);  /* An example function declaration */

struct Entity {
    float x;
    float y;
    float w;
    float h;
    float dx;
    float dy;
    int health;
    int reload;
    //vita2d_texture *image[WALKING_ANIMATION_FRAMES];
    //Entity *next;
};
struct Entity player;
struct Entity box;
struct Entity box2;
struct Entity targe;
struct Entity target2;
struct Entity lvl3target3;
struct Entity collider;
struct Entity goal;
struct Entity gSpriteClips[WALKING_ANIMATION_FRAMES];
struct Entity tile;
struct Entity columns;
struct Entity lvl3Columns[100];
struct Entity lvl3Boxes[15];
struct Entity touchCollider;
struct Entity playerCollider;
struct Entity lvl3BoxCollider;
struct Entity lvl3TargetCollider[6];


struct Rect {
    float x;
    float y;
    float w;
    float h;
    float dx;
    float dy;

    //vita2d_texture *image[WALKING_ANIMATION_FRAMES];
    //Entity *next;
};
//struct Rect pRect;


bool check_collision( struct Entity A, struct Entity B );
//void checkPlayerColumnCollision();
void checkBoxCollision();
void checkTileCollision();





bool check_collision( struct Entity A, struct Entity B )
{
//The sides of the rectangles
int leftA, leftB;
int rightA, rightB;
int topA, topB;
int bottomA, bottomB;

//Calculate the sides of rect A
leftA = A.x;//A.x
rightA = A.x + A.w;
topA = A.y;
bottomA = A.y + A.h;

//Calculate the sides of rect B
leftB = B.x;
rightB = B.x + B.w;//+ B.w
topB = B.y;
bottomB = B.y + B.h;

//If any of the sides from A are outside of B
if( bottomA <= topB )
{
    return false;
}

if( topA >= bottomB )
{
    return false;
}

if( rightA <= leftB ) //right <= left
{
  //  player.x -= player.dx;
	return false;
}

if( leftA >= rightB )//left >= right
{
    return false;//false
}

//If none of the sides from A are outside B
return true;
}
checkTileCollision()
{
            if(check_collision(player,lvl3Columns[26]))
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
			 	}

}

#endif
