#ifndef HEADER_H
#define HEADER_H
#include <stdio.h>
#include "SDL/sdl.h"
#include "sdl/sdl_image.h"
//#include <windows.h>


#define speed 10
#define no 1
#define yes 0





SDL_Surface *load_image( char filename[] );


void pacman_sprites(SDL_Rect location,int direction,SDL_Surface* screen,char comp[20][12]);
void moveit(int key_press);
void createmap(SDL_Surface* screen,char comp[20][12]); //plots the map from database
void build_map(SDL_Surface* screen); // map maker...it saves the map to database
int legibility(char comp[20][12],int *direction);
void gameplay(SDL_Surface* screen); //game playing time


void load_array(char comp[20][12],SDL_Surface* screen);
int writetofile(char comp[20][12]);// editor-->write to file
void what_is_around(char a[],char comp[20][12]); //it looks around the pacman
#endif // HEADER_H_INCLUDED
