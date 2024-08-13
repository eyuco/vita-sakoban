#include "textureManager.h"


bool load(char fileName[],char id[])
{
    
    vita2d_texture *pTempSurface;
    pTempSurface = vita2d_load_PNG_buffer(&fileName);
    if(pTempSurface == NULL)
    {
         return false;
    }
    createTextureFromSurface(pTempSurface);
}
//display texture
void createTextureFromSurface(vita2d_texture *texture)
{
        vita2d_draw_texture_part(texture, 940/2, 544/2, 0,0,0,0);
}