#ifndef COLLISION_H_   /* Include guard */
#define COLLISION_H_
#include <stdbool.h>

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
void checkPlayerColumnCollision();
void checkBoxCollision();
#endif
