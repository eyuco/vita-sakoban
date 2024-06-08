/*
 * Copyright (c) 2015 Sergi Granell (xerpi)
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
//#include "actors.h"
#include <psp2/ctrl.h>
#include <psp2/kernel/processmgr.h>
#include <psp2/touch.h>
#include <stdbool.h>
#include <vita2d.h>
#include <vorbis/codec.h>
#include <vorbis/vorbisenc.h>
#include "gMenu.h"
#include "grid.h"
#include "level.h"
#include "util.h"
#include "write_read.h"
#include <vorbis/vorbisfile.h>
//#include "vitaAudio/vitaAudio.h"
#include <psp2/audioout.h>
#include <psp2/audiodec.h> 
#include <mad.h>
#include "Audio.h"

#define PLAYER_SPEED          4

#define DATA_LEN        2048
#define SCE_AUDIODEC_MP3_MAX_STREAMS 8
#define MAX(a,b)        ((a) > (b) ? (a) : (b))
#define BUFFER_SIZE   32768


/*
 * Symbol of the image.png file
 * use entity struct
 * box texture:DONE
 * player collision with box:DONE
 * check malloc
 * draw box before target
 * animate sprites:DONE
 * Maybe put blocks in array and draw from the tileset
 * draw grid:DONE fill it with tileset blocks
 * draw level://follow sdl2 book for guidance. iwant to learn more about drawing tilemaps
 * draw collision boxes around level area:DONE
 * draw box in level area:DONE
 * add target boxes: Done
 * draw start menu:DONElook at lazyfoo game states tut
 * organize code:DONE
 *need to center menu text:DONE
 *Draw level select screen:DONE
 *Work on levels:
 */
extern unsigned char _binary_image_png_start;
extern unsigned char _binary_player1_png_start;

extern unsigned char _binary_zombie_png_start;
extern unsigned char _binary_image1_png_start;
extern unsigned char _binary_image2_png_start;
extern unsigned char _binary_target_png_start;
//extern unsigned char _binary_tileset_png_start;
extern unsigned char _binary_bg_png_start;
//extern unsigned char _binary_blocks_png_start;

AudioHandler _audio;
bool isFacingUp = false;
bool isFacingRight = false;
bool isFacingLeft = false;
bool isFacingDown = false;
bool state_Menu = false;
bool state_Game = false;

bool paused;

enum GAME_STATE
{
    STATE_MENU,
    STATE_LEVEL_MENU,
    STATE_PLAY

};
enum GAME_STATE currentState;

void joyEventHandler(int joy, int changed, int state);

void initPlayer();

void updateTexture();
int port,i;
void checkTouch(SceTouchData touch);
bool check_collision( struct Entity A, struct Entity B );
struct Entity player;
struct Entity box;
struct Entity box2;
struct Entity targe;
struct Entity target2;
struct Entity collider;
struct Entity goal;
struct Entity gSpriteClips[WALKING_ANIMATION_FRAMES];
struct Entity tile;
struct Entity columns;
struct Entity touchCollider;



int frame = 0;

float bulPosX;
	float bulPosY;
	vita2d_pgf *pgf;
	char pcmout[4096];
int main(int argc, char** argv)
{
	SceCtrlData pad;
	//vita2d_pgf *pgf;
	vita2d_pvf *pvf;
	vita2d_texture *image;
	
	vita2d_texture *zombie[10];
	vita2d_texture *target[10];
   // vita2d_texture *tileset[27];
	vita2d_texture *bg;
	//vita2d_texture *blocks[10];
	//vita2d_texture *cursor;
  //test
#define OGG_IMPL
#define VORBIS_IMPL

//test
	menuState = true;
	currentState = STATE_MENU;

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





	//test
	 int window_width = (grid_width * grid_cell_size) + 1;
    int window_height = (grid_height * grid_cell_size) + 1;

        // struct grid_cursor grid;
	    grid.x = (grid_width - 1) / 2 * grid_cell_size;
        grid.y = (grid_height - 1) / 2 * grid_cell_size;
        grid.w = grid_cell_size;
        grid.h = grid_cell_size;
		
      
	player.dx = 5;//45
     player.x = column[15];//935/2 + grid_cell_size;//940
	 player.y = column[9];//540/2 + grid_cell_size;
	 player.w = 27.0f;
	 player.h = 33.0f;
	 box.y = 500; //+ grid_cell_size;//920/2;
	 box.x = 900;// + grid_cell_size;//544/2;
	 //box.x = column[17];
	 //box.y = column[7];
     box.w = 46;
	 box.h = 45;
	 gfx_Cursor.x = options[currentIndex].x-15;
     gfx_Cursor.y = options[currentIndex].y-10;
     gfx_Cursor.w = 8.0f;
     gfx_Cursor.h = 8.0f;
    menu_Bg.w = 740.0f;
    menu_Bg.h = 740.0f;
    icons.x = 134;
    icons.y = 164;
    icons.w = 91;
    icons.h = 94;
    level_Bg.w = 740.f;
    level_Bg.h = 740.f;
    level_cursor.x = levelList[currentIndex].x;
    level_cursor.y = levelList[currentIndex].y;//15
    level_cursor.w = 91;
    level_cursor.h = 94;
    

     //boxes
	 goal.x = column[13];//940/2 + grid_cell_size;
	 goal.y = column[7];//444/2 + grid_cell_size;
	 goal.w = 27.0f;
	 goal.h = 33.0f;//45

     box2.x = column[15];//940/2 + grid_cell_size;
	 box2.y = column[7];//444/2 + grid_cell_size;
	 box2.w = 27.0f;
	 box2.h = 33.0f;//45
     
     targe.x = column[14];//940/2 + grid_cell_size;
	 targe.y = column[9];//444/2 + grid_cell_size;
	 targe.w = 27.0f;
	 targe.h = 33.0f;//45

     target2.x = column[15];//940/2 + grid_cell_size;
	 target2.y = column[9];//444/2 + grid_cell_size;
	 target2.w = 27.0f;
	 target2.h = 33.0f;

	 tile.x = 1.0f;
	 tile.y = 0.0f;
	 tile.w = 35.0f;
	 tile.h = 37.0f;

	
	 columns.w = 35.0f;
	 columns.h = 37.0f;



	 /*
	 gSpriteClips[0].x = 0.0f;
	 gSpriteClips[0].y = 0.0f;
	 gSpriteClips[0].w = 27.0f;
	 gSpriteClips[0].h = 33.0f;
*/

     //replace this with isFacingDown = true;
     /*gSpriteClips[0].x = 35.0f;//1
	 gSpriteClips[0].y = 0.0f;
	 gSpriteClips[0].w = 27.0f;
	 gSpriteClips[0].h = 33.0f;

	 gSpriteClips[1].x = 66.0f;//2
	 gSpriteClips[1].y = 0.0f;
	 gSpriteClips[1].w = 27.0f;
	 gSpriteClips[1].h = 33.0f;
*/
	 isFacingDown = true;
struct Entity currentClip = gSpriteClips[frame/4];
struct Entity currentTile = tile;
    float speed = 10.3f;


	vita2d_init();

    

	vita2d_set_clear_color(RGBA8(0x40, 0x40, 0x40, 0xFF));

	InitializeAudio(&_audio);
 
  LoadWav(&_audio, "Sounds/music.wav", AUDIO_OUT_MAIN,0);


	pgf = vita2d_load_default_pgf();
	pvf = vita2d_load_default_pvf();
 bulPosX = 940/2;
 bulPosY = 544/2;
float enemyPosX = 950/2;
float enemyPosY = 544/2;


	/*
	 * Load the statically compiled image.png file.
	 */
	//image = vita2d_load_PNG_buffer(&_binary_image_png_start);
	zombie[0] = vita2d_load_PNG_buffer(&_binary_zombie_png_start);
	zombie[1] = vita2d_load_PNG_buffer(&_binary_zombie_png_start);
	
   player.image[0] = vita2d_load_PNG_buffer(&_binary_image_png_start);
   player.image[1] = vita2d_load_PNG_buffer(&_binary_image1_png_start);
   player.image[2] = vita2d_load_PNG_buffer(&_binary_image2_png_start);
   target[0] = vita2d_load_PNG_buffer(&_binary_target_png_start);
   target[1] = vita2d_load_PNG_buffer(&_binary_target_png_start);
   //blocks = vita2d_load_PNG_buffer(&_binary_blocks_png_start);
   
   
   loadTileBuffers();
   
menu_BG = vita2d_load_PNG_buffer(&_binary_menuBG_png_start);
cursor = vita2d_load_PNG_buffer(&_binary_cursor_png_start);
level_Select = vita2d_load_PNG_buffer(&_binary_bg_png_start);
level_Cursor = vita2d_load_PNG_buffer(&_binary_levelcursor_png_start);
sceTouchSetSamplingState(SCE_TOUCH_PORT_FRONT, 1);
	sceTouchEnableTouchForce(SCE_TOUCH_PORT_FRONT);
SceTouchData touch_old[SCE_TOUCH_PORT_MAX_NUM];
	SceTouchData touch[SCE_TOUCH_PORT_MAX_NUM];
	//int port,i;
//test
touchCollider.w = 35.0f;
	 touchCollider.h = 37.0f;


	memset(&pad, 0, sizeof(pad));
unsigned char buf[4096];
	while (1) {
		sceCtrlPeekBufferPositive(0, &pad, 1);
        memcpy(touch_old, touch, sizeof(touch_old));
        sceCtrlPeekBufferPositive(0, &touch, 1);
     //int port,i;
     //test


//test
        switch(currentState){
            case STATE_MENU:{
               // menuLoop();
                int i = 0;
                //processStateMenu();
                break;
            }
             case STATE_LEVEL_MENU:{
               // menuLoop();
                int i = 0;
                //levelSelectLoop();
                hideText(pgf);
                //levelSelectLoop();
                //processStateMenu();
                break;
            }
            case STATE_PLAY:{
                //processStatePlay();
                //pickStart();
                break;
            }
        }




	   if(isFacingUp == true)
	   {
		   gSpriteClips[0].x = 35.0f;//1
	       gSpriteClips[0].y = 34.0f;
	       gSpriteClips[0].w = 27.0f;
	       gSpriteClips[0].h = 33.0f;

	       gSpriteClips[1].x = 66.0f;//2
	       gSpriteClips[1].y = 34.0f;
	       gSpriteClips[1].w = 27.0f;
	       gSpriteClips[1].h = 33.0f;

	   }
	   if(isFacingDown == true)
	   {
		   gSpriteClips[0].x = 35.0f;//1
	       gSpriteClips[0].y = 0.0f;
	       gSpriteClips[0].w = 27.0f;
	       gSpriteClips[0].h = 33.0f;

	       gSpriteClips[1].x = 66.0f;//2
	       gSpriteClips[1].y = 0.0f;
	       gSpriteClips[1].w = 27.0f;
	       gSpriteClips[1].h = 33.0f;


	   }
	   if(isFacingRight == true)
	   {
		   gSpriteClips[0].x = 35.0f;//1
	       gSpriteClips[0].y = 66.0f;
	       gSpriteClips[0].w = 27.0f;
	       gSpriteClips[0].h = 33.0f;

	       gSpriteClips[1].x = 65.0f;//2
	       gSpriteClips[1].y = 66.0f;
	       gSpriteClips[1].w = 27.0f;
	       gSpriteClips[1].h = 33.0f;


	   }
      if(isFacingLeft == true)
	   {
		   gSpriteClips[0].x = 35.0f;//1
	       gSpriteClips[0].y = 98.0f;
	       gSpriteClips[0].w = 27.0f;
	       gSpriteClips[0].h = 33.0f;

	       gSpriteClips[1].x = 65.0f;//2
	       gSpriteClips[1].y = 98.0f;
	       gSpriteClips[1].w = 27.0f;
	       gSpriteClips[1].h = 33.0f;


	   }



        //  //box meets target
        if(check_collision(box,goal) )//player.x < 0 || player.x > 944
       {
          break;
        }

		if (pad.buttons & SCE_CTRL_RIGHT)
		{
            isFacingRight = true;
			isFacingUp = false;
			isFacingLeft = false;
			isFacingDown = false;
			player.x += grid_cell_size;
			bulPosX += 5;
			columns.x = column[16];
			selectorMoveRight();
			 //level_cursor.x += 100;
			if(check_collision(player,goal))
       {

			goal.x += grid_cell_size;
        }
       if(check_collision(player,box2))
       {

			box2.x += grid_cell_size;
        }


			//vita2d_draw_texture_rotate(image, 940/2, 544/2, rad);
			//break;
		}
		if (pad.buttons & SCE_CTRL_LEFT)
		{
            isFacingLeft = true;
			isFacingDown = false;
			isFacingRight = false;
			isFacingUp = false;

			player.x -= grid_cell_size;//-=
			bulPosX -= 5;
			columns.x = column[7];
			//run moving sprite
			selectorMoveLeft();
			if(check_collision(player,goal) )//player.x < 0 || player.x > 944
       {
        
			goal.x -= grid_cell_size;
        }
         if(check_collision(player,box2) )//player.x < 0 || player.x > 944
       {
        
			box2.x -= grid_cell_size;
        }

			//vita2d_draw_texture_rotate(image, 940/2, 544/2, rad);
			//break;
		}
		if (pad.buttons & SCE_CTRL_UP)
		{
			isFacingUp = true;
			isFacingRight = false;
			isFacingLeft = false;
			isFacingDown = false;
            player.y -= grid_cell_size;//5;
			columns.y = column[3];
            cursorUp();
			//bulPosY -= 10;
			bulPosY = player.y;
			if(check_collision(player,goal) )//player.x < 0 || player.x > 944
       {
       
			goal.y -= grid_cell_size/1;
        }
         if(check_collision(player,box2) )//player.x < 0 || player.x > 944
       {
       
			box2.y -= grid_cell_size/1;
        }

			//vita2d_draw_texture_rotate(image, 940/2, 544/2, rad);
			//break;
		}
		if (pad.buttons & SCE_CTRL_DOWN)
		{
            isFacingDown = true;
			isFacingLeft = false;
			isFacingRight = false;
			isFacingUp = false;


			player.y += grid_cell_size;
			columns.y = column[10];
			//bulPosY += 10;
			bulPosY = player.y;
            cursorDown();

			if(check_collision(player,goal) )//player.x < 0 || player.x > 944
       {
        
			goal.y += grid_cell_size;
        }
         if(check_collision(player,box2) )//player.x < 0 || player.x > 944
       {
        
			box2.y += grid_cell_size;
        }


		}
        if (pad.buttons & SCE_CTRL_CROSS)
		{
            
			//vaudio_play_music_ogg( snd_mysound, "resources/sokoban.ogg" );
			PlayAudio(&_audio);
			//start leve
			level_Bg.w = 0;
            level_Bg.h = 0;
            level_cursor.w = 0;
            level_cursor.h = 0;
			Select_Level(currentIndex);
			currentState = STATE_PLAY;
			//vita2d_draw_texture_rotate(image, 940/2, 544/2, rad);
			//break;}
		}
       

		if (pad.buttons & SCE_CTRL_START)
		{  // pos.x += 10;
			//break;
			//vita2d_clear_screen();
			//vita2d_draw_texture_tint(menu_BG, 100, 0, RGBA8(0, 0, 0, 0));
			//currentState == STATE_PLAY;
           Select(currentIndex);
             menu_Bg.w = 0.0f;
             menu_Bg.h = 0.0f;
             gfx_Cursor.w = 0.0f;
             gfx_Cursor.h = 0.0f;
             levelSelectState = true;
             currentState = STATE_LEVEL_MENU;

			//vita2d_free_texture(menu_BG);
		}
		//test
        sceKernelDelayThread(120000);
		vita2d_start_drawing();
		vita2d_clear_screen();

        

			/* column[0] = 0;
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
             */
            
         //draw the grid 
        
         for (int x = 0; x < 1 + grid_width * grid_cell_size;
             x += grid_cell_size) {
         
			 //adjust these tiles for level layout like add something to x
			 //level 1 should be an easy level
           
			 vita2d_draw_texture(tileset[0], x, column[4]); //+x 4

             //with this i can draw the collision boxes anywhere on the level area
			 vita2d_draw_texture(tileset[1], x, column[5]);
			 vita2d_draw_texture(tileset[2], x, column[6]);
			 vita2d_draw_texture(tileset[3], x, column[7]);
			 vita2d_draw_texture(tileset[4], x, column[8]);
			 vita2d_draw_texture(tileset[5], x, column[9]);//point
			
			 vita2d_draw_texture(blocks[0], x, column[10]);//10
			 vita2d_draw_texture(blocks[0], x, column[3]);//3
             //vita2d_draw_texture(blocks[1], 2 + grid_cell_size, column[11]);
			 columns.x = x; //+ grid_cell_size;
             
			 if(isFacingUp){
            //test this
			 	columns.y = column[2];//2
            if(check_collision(goal,columns))
            {
            	goal.y += grid_cell_size;
               if(check_collision(player,goal))
				 {

                 player.y += grid_cell_size;
				}

            }
            if(check_collision(goal,box2))
            {
            	goal.y += grid_cell_size;
            	if(check_collision(player,goal))
				 {

                 player.y += grid_cell_size;
				}

            }
			 //box2
             if(check_collision(box2,columns))
            {
            	box2.y += grid_cell_size;
               if(check_collision(player,box2))
				 {

                 player.y += grid_cell_size;
				}

            }

            //box2
			 if(check_collision(player,columns))
				 {

                 player.y += grid_cell_size;
				}
			 }


             if(isFacingDown){

             /*if(check_collision(player,box)){
             	player.y -= grid_cell_size;
             }*/
             	columns.y = column[10];
              if(check_collision(goal,columns))
            {
            	goal.y -= grid_cell_size;
               if(check_collision(player,goal))
				 {

                 player.y -= grid_cell_size;
				}

            }
            //box2
            if(check_collision(box2,columns))
            {
            	box2.y -= grid_cell_size;
               if(check_collision(player,box2))
				 {

                 player.y -= grid_cell_size;
				}

            }
            if(check_collision(goal,box2))
            {
            	goal.y -= grid_cell_size;
            	if(check_collision(player,goal))
				 {

                 player.y -= grid_cell_size;
				}

            }


            //box2
			 if(check_collision(player,columns))
				 {

                 player.y -= grid_cell_size;
				}
			 }

			 //vita2d_draw_texture(zombie, box.x, box.y);
			  vita2d_draw_texture_part(player.image[0], player.x , player.y , gSpriteClips[frame].x, gSpriteClips[frame].y, gSpriteClips[frame].w,gSpriteClips[frame].h);

		 ++frame;
             //sceKernelDelayThread(100000);//delay for one second 100000

                //Cycle animation need to slow it down
                if( frame / 1 >= WALKING_ANIMATION_FRAMES )
                {

					frame = 0;//0
                }

			 vita2d_draw_line(x, 0, x, window_height, RGBA8(255, 0, 255, 255));


        }

           //test            //1
        for (int y = 0; y < 1 + grid_height * grid_cell_size;
             y += grid_cell_size) {
            //SDL_RenderDrawLine(renderer, 0, y, window_width, y);

          //vita2d_draw_texture(tileset, 0, y);//y
			//need to figure out draw second y column
					vita2d_draw_texture(blocks[1], column[7], y);//0 + grid_cell_size
					//columns.y = y;
					
          		vita2d_draw_texture(blocks[1], column[16], y);//16
                    columns.y = y;

					 if(isFacingLeft){
                      columns.x = column[7];//8

			 if(check_collision(goal,columns))
            {
            	goal.x += grid_cell_size;
               if(check_collision(player,goal))
				 {

                 player.y += grid_cell_size;
				}

            }
            if(check_collision(goal,box2))
            {
            	goal.x += grid_cell_size;
            	if(check_collision(player,goal))
				 {

                 player.y += grid_cell_size;
				}

            }

            //box2
            if(check_collision(box2,columns))
            {
            	box2.x += grid_cell_size;
               if(check_collision(player,box2))
				 {

                 player.y += grid_cell_size;
				}

            }

           //box2
			 if(check_collision(player,columns))
				 {

                 player.x += grid_cell_size;

				}
			 }

             if(isFacingRight){
                //make this equal to all columns
                
                columns.x = column[16];//15
              
             if(check_collision(goal,columns))
            {
            	goal.x -= grid_cell_size;
               if(check_collision(player,goal))
				 {

                 player.x -= grid_cell_size;
				}

            }
           if(check_collision(goal,box2))
            {
            	goal.x -= grid_cell_size;
            	if(check_collision(player,goal))
				 {

                 player.y += grid_cell_size;
				}

            }

                 //box2
              if(check_collision(box2,columns))
            {
            	box2.x -= grid_cell_size;
               if(check_collision(player,box2))
				 {

                 player.y += grid_cell_size;
				}

            }

			 //box2 
			 if(check_collision(player,columns))
				 {

                 player.x -= grid_cell_size;//-=
				}
			 }


          vita2d_draw_line(0, y, window_width, y, RGBA8(255, 0, 255, 255));
		}
         
        if(check_collision(goal,targe) && check_collision(box2,target2))
        {
        	//vita2d_pgf_draw_text(level_List, 0, 0, RGBA8(0, 255, 0, 255), 1.0f, "LEVEL COMPLETE!");//700,30
            break;
        }



        for(port = 0; port < SCE_TOUCH_PORT_MAX_NUM; port++){
			sceTouchPeek(port, &touch[port], 1);
			printf("%s",((const char*[]){"FRONT","BACK "})[port]);
			/* print every touch coordinates on that surface */
			for(i = 0; i < SCE_TOUCH_MAX_REPORT; i++)
				printf("\e[9%im%4i:%-4i ", (i < touch[port].reportNum)? 7:0,
				       touch[port].report[i].x,touch[port].report[i].y);
			    
			printf("\n");
           touchCollider.x = touch[SCE_TOUCH_PORT_FRONT].report[i].x; //touch[port].report[i].x;
           touchCollider.y = touch[SCE_TOUCH_PORT_FRONT].report[i].y;//touch[port].report[i].y;
           


         //vita2d_pgf_draw_text(pgf, touch[port].report[i].x, touch[port].report[i].y + 50, RGBA8(0, 255, 0, 255), 1.0f,"HELLO");

		}
		/*if(touch[SCE_TOUCH_PORT_FRONT].report[0].x  <= column[15] && touch[SCE_TOUCH_PORT_FRONT].report[0].y <= column[20])
		{
            break;
			

		}*/
		//touchCollider.x = touch[SCE_TOUCH_PORT_FRONT].report[0].x
          // touchCollider.y = touch[SCE_TOUCH_PORT_FRONT].report[0].y
        

         if ( touch[SCE_TOUCH_PORT_FRONT].reportNum == 1)
         {
         	                                 //change this to icon
         	if(check_collision(touchCollider, icons))
         	{
              vita2d_pgf_draw_text(pgf, 20, 20, RGBA8(0, 255, 0, 255), 1.0f,"HELLO");
         	}
         	
           //vita2d_pgf_draw_text(pgf, 20, 20, RGBA8(0, 255, 0, 255), 1.0f,"HELLO");
           
         }
		/*if ( (touch[SCE_TOUCH_PORT_FRONT].reportNum == 1)
		  && (touch_old[SCE_TOUCH_PORT_FRONT].reportNum == 1)
		  && (touch[SCE_TOUCH_PORT_FRONT].report[0].y >= 1000)
		  && (touch_old[SCE_TOUCH_PORT_FRONT].report[0].y < 1000)){

		}*/

        //topA
		//vita2d_draw_texture(blocks[1], column[15], column[9]);
        vita2d_draw_texture(target[0], targe.x,targe.y);//box.x, box.y
        vita2d_draw_texture(target[1], target2.x, target2.y);
		

        

        vita2d_draw_texture(zombie[0], goal.x, goal.y);//column[14], box.y
        vita2d_draw_texture(zombie[1], box2.x, box2.y);


        
         //vita2d_draw_texture(target[0], column[14], column[9]);//box.x, box.y
        //vita2d_draw_texture(target[1], column[15], column[9]);
		

         drawMenu();
  
       // vita2d_clear_screen();
		vita2d_end_drawing();
		vita2d_swap_buffers();
        //sceKernelDelayThread(100000);//delay for one second 100000
		//rad += 0.1f;

	}

	
	StopAudio(&_audio);
	TerminateAudio(&_audio);

	vita2d_fini();
	vita2d_free_texture(player.image[0]);
	
	vita2d_free_texture(zombie);
	vita2d_free_texture(tileset[0]);
	vita2d_free_pgf(pgf);
	vita2d_free_pvf(pvf);
    //sceAudioOutReleasePort(port);
	sceKernelExitProcess(0);
	return 0;
}
void initPlayer(){
	                                 
	vita2d_draw_texture_part(player.image[0], player.x, player.y, 0.0f, 0.0f, player.w,player.h);//27.0f 33.0f

}



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




