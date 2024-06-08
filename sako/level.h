#ifndef LEVEL_H_   /* Include guard */
#define LEVEL_H_

#include "vec.h"
#include "grid.h"

extern unsigned char _binary_tileset_png_start;
extern unsigned char _binary_blocks_png_start;

vita2d_texture *tileset[27];
vita2d_texture *blocks[10];
void tileObjs();
void setTileParam();
void loadTileBuffers();
void loadLevel();
void loadColumns();
//might need to make grid and draw the columns that way
vector getTilesets();
void levelRender();
//tilesset width and height will be same as grid width and height
struct Tileset{
  int firstGridID;
int tileWidth;
int tileHeight;
int spacing;
int margin;
int width;
int height;
int numColumns;
char name[];
};
struct Layer{

};
struct Level{

   
};
struct Tileset tileObj;


void tileObjs(){
    struct Tileset* m_tilesets = vector_create();
    struct Layer* m_layers = vector_create();
    
}
vector getTilesets()
{

}
void loadTileBuffers()
{
tileset[0] = vita2d_load_PNG_buffer(&_binary_tileset_png_start);
   tileset[1] = vita2d_load_PNG_buffer(&_binary_tileset_png_start);
   tileset[2] = vita2d_load_PNG_buffer(&_binary_tileset_png_start);
   tileset[3] = vita2d_load_PNG_buffer(&_binary_tileset_png_start);
   tileset[4] = vita2d_load_PNG_buffer(&_binary_tileset_png_start);
   tileset[5] = vita2d_load_PNG_buffer(&_binary_tileset_png_start);
   tileset[6] = vita2d_load_PNG_buffer(&_binary_tileset_png_start);
   tileset[7] = vita2d_load_PNG_buffer(&_binary_tileset_png_start);
   tileset[8] = vita2d_load_PNG_buffer(&_binary_tileset_png_start);
   tileset[9] = vita2d_load_PNG_buffer(&_binary_tileset_png_start);
   tileset[10] = vita2d_load_PNG_buffer(&_binary_tileset_png_start);

   blocks[0] = vita2d_load_PNG_buffer(&_binary_blocks_png_start);
   blocks[1] = vita2d_load_PNG_buffer(&_binary_blocks_png_start);
   blocks[2] = vita2d_load_PNG_buffer(&_binary_blocks_png_start);
   blocks[3] = vita2d_load_PNG_buffer(&_binary_blocks_png_start);
   blocks[4] = vita2d_load_PNG_buffer(&_binary_blocks_png_start);
   blocks[5] = vita2d_load_PNG_buffer(&_binary_blocks_png_start);
   blocks[6] = vita2d_load_PNG_buffer(&_binary_blocks_png_start);

}
void setTileParam()
{
  tileObj.tileWidth = grid_cell_size;
  tileObj.tileHeight = grid_cell_size;
}
void levelRender()
{
   //level consists of background and tile sprites

}
#endif
