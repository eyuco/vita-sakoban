#ifndef GMENU_H_   
#define GMENU_H_

#include <stdbool.h>
#include <vita2d.h>

/*
look at 170

*/

extern unsigned char _binary_menuBG_png_start;
extern unsigned char _binary_icon_png_start;
extern unsigned char _binary_levelcursor_png_start;
extern unsigned char _binary_cursor_png_start;
#define NUM_OPTIONS 3
#define NUM_LEVELS 3
#define WALKING_ANIMATION_FRAMES  2
int GREEN = 255;
int BLUE  = 255;
bool menuState;
bool levelSelectState;
int currentIndex = 0;
vita2d_texture *cursor;
vita2d_texture *menu_BG;
vita2d_texture *level_Select;
vita2d_texture *icon;
vita2d_texture *level_Cursor;
vita2d_pgf *pgf;
vita2d_pgf *level_List;

struct Entity {
    float x;
    float y;
    float w;
    float h;
    float dx;
    float dy;
    int health;
    int reload;
    vita2d_texture *image[WALKING_ANIMATION_FRAMES];
    //Entity *next;
};
typedef struct
{
    int x;
    int y;
    char label[10];
} Option;
Option options[NUM_OPTIONS] = {
    {400, 300, "START"},
    {400, 316, "OPTIONS"},
    {400, 330, "EXIT"},
};
Option levelList[NUM_LEVELS] = {
    {133, 163, "TUTORIAL"},
    {234, 163, "Level 1"},
    {337, 163, "Level 2"},
};

struct Entity menu_Bg;
struct Entity icons;
struct Entity level_Bg;
struct Entity level_cursor;

struct Entity gfx_Cursor;

void cursorUp();
void cursorDown();
void menuLoop();
void levelSelectLoop();
void Select(int Option);
void Select_Level(int Level);
void drawMenu();
void pickStart();
void pickOptions();
void pickExit();
void hideText();
void selectorMoveRight();
void selectorMoveLeft();
void menuLoop()
{
   // int i = 0;
  //if(levelSelectState == true)
  //{
    //hideText();
     

  //}
  //paused = TRUE;
  int i = 0;

for(int i; i < NUM_LEVELS; i++){
    Option o = levelList[i];
    //VDP_drawText(o.label,o.x,o.y);             255     255
    vita2d_pgf_draw_text(level_List, o.x, o.y, RGBA8(0, 255, 0, 255), 1.0f, o.label);//700,30
    
    }
for(i; i < NUM_OPTIONS; i++){
    Option o = options[i];
    //VDP_drawText(o.label,o.x,o.y);             255     255
    vita2d_pgf_draw_text(pgf, o.x, o.y, RGBA8(0, GREEN, 0, BLUE), 1.0f, o.label);//700,30
    
    }
   
}
void levelSelectLoop()
{
  
}
void hideText(vita2d_pgf *pgf)
{
    GREEN = 0;
    BLUE = 0;
    
}
void pickStart(){
    vita2d_start_drawing();
   vita2d_clear_screen();
//vita2d_draw_texture(level_Select, 100, 0);
//minimize level select

}
void Select(int Option){
    switch (Option)
    {
    case 0:{
        //start game loop
        //currentState = STATE_PLAY;
        pickStart();
        break;
    }
    case 1:{
        //pickOptions();
        break;
    }
    case 2:{
        //pickExit();
        break;
    }
    
    default:
        break;
    }
}
void Select_Level(int Level)
{
   switch (Level)
    {
    case 0:{
        //start game loop
        //currentState = STATE_PLAY;
        //draw level 1

        break;
    }
    case 1:{
        //pickOptions();
        break;
    }
    case 2:{
        //pickExit();
        break;
    }
    
    default:
        break;
    }

}

void drawMenu()
{   //make this like menu bg
     
    //vita2d_draw_texture(level_Select, 0, 0);
    vita2d_draw_texture_part(level_Select, 0, 0, 0.0f, 0.0f, level_Bg.w,level_Bg.h);
   // vita2d_draw_texture(level_Cursor, level_cursor.x, level_cursor.y);
    vita2d_draw_texture_part(level_Cursor, level_cursor.x, level_cursor.y, 0.0f, 0.0f, level_cursor.w,level_cursor.h);
    //draw each level item and part it
    vita2d_draw_texture_part(menu_BG, 100, 0, 0.0f, 0.0f, menu_Bg.w,menu_Bg.h);
      //vita2d_draw_texture(menu_BG,100, 0);
        //vita2d_draw_texture(cursor,gfx_Cursor.x, gfx_Cursor.y);
      vita2d_draw_texture_part(cursor, gfx_Cursor.x, gfx_Cursor.y, 0.0f, 0.0f, gfx_Cursor.w,gfx_Cursor.h);
      menuLoop();

}

void selectorMoveRight()
{
  if(currentIndex < NUM_LEVELS-1){
        currentIndex++;
        level_cursor.x = levelList[currentIndex].x;
        //updateCursorPosition();
    }

}
void selectorMoveLeft()
{
  if(currentIndex < NUM_LEVELS+1){
        currentIndex--;
        level_cursor.x = levelList[currentIndex].x;
        //updateCursorPosition();
    }

}
void cursorUp()
{     
     if(currentIndex > 0){
        currentIndex--;
        gfx_Cursor.y = options[currentIndex].y-10;
        //updateCursorPosition();
    }
}

void cursorDown(){
    
    if(currentIndex < NUM_OPTIONS-1){
        currentIndex++;
       gfx_Cursor.y = options[currentIndex].y-10;
        //updateCursorPosition();
    }
}


#endif

