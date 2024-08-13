#include "textureManager.h"



bool load(char fileName,char id)
{
    
    vita2d_texture *pTempSurface;
    pTempSurface = vita2d_load_PNG_buffer(&fileName);
   /* if(pTempSurface == NULL)
    {
         return false;
    }*/
     vita2d_draw_texture(pTempSurface, 0.0f,0.0f);
    return true;
}
//display texture
void createTextureFromSurface(vita2d_texture *texture)
{
        vita2d_draw_texture(texture, 0.0f,0.0f);
}