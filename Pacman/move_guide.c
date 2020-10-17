
#include "header.h"

int legibility(char comp[20][12],int *direction)
{
    int x,y;// equivalent of cor to array-no
    char around[4];   // stores the values around pacman
    static int prev_direction;
    SDL_Rect cordinate;
    extern SDL_Rect cor;
    if (cor.x>500) cor.x=0;
    if (cor.y>350) cor.y=0;
    if (cor.x<0) cor.x=500;
    if (cor.y<0) cor.y=350;

    cordinate.x=cor.x+10;
    cordinate.y=cor.y+10;
    x=(cor.x-10-1)/24;
    y=(cor.x-11-1)/24;




    what_is_around(around,comp);

     switch(*direction)
    {
        case SDLK_UP:
                if ((around[0]=='a') || (around[0]=='e') || (around[1]=='b'))
                {
                    *direction=prev_direction;
                }

        break;
        case SDLK_DOWN:
                /*if ((around[7]=='e' && around[7]=='a' && around[7]=='b'))
                {
                    *direction=prev_direction;
                }*/

         break;
        case SDLK_RIGHT:

        break;
        case SDLK_LEFT:

        break;
    }

    prev_direction=*direction;
    return yes;


}


void moveit(int key_press)
{
    extern SDL_Rect cor;
    int i;
//    static int prev_key;
 //   if (prev_key==key_press)   {
            switch (key_press)
            {
            case SDLK_UP:               cor.y-=speed; break;
            case SDLK_DOWN:            cor.y+=speed; break;
            case SDLK_RIGHT:            cor.x+=speed; break;
            case SDLK_LEFT:            cor.x-=speed; break;
            }
   /* }
    else
    {
        switch (key_press)
            {
            case SDLK_UP:
            if ((cor.x+10)%24==0 && (cor.y+11)%24==0)   cor.y-=speed;
            else
            {
                for (i=cor.y+10;(cor.y+10)%24!=0;i++)   cor.y++;
            }



             break;
            case SDLK_DOWN:            cor.y+=speed; break;
            case SDLK_RIGHT:            cor.x+=speed; break;
            case SDLK_LEFT:            cor.x-=speed; break;
            }
    }



    prev_key=key_press;         */
}



void what_is_around(char a[],char comp[20][12])
{
    extern SDL_Rect cor;
    char ch;
    SDL_Rect box;
    box.x=(cor.x-10+10-1)/24;
    box.y=(cor.y-11+10-1)/24;


    ch=comp[box.x-1][box.y-1];
    if ((ch=='a' || ch=='b' || ch=='c' || ch=='d' || ch=='e' || ch=='f' )) a[0]=ch;
    else a[0]='$';


    ch=comp[box.x+1][box.y-1];
    if ((ch=='a' || ch=='b' || ch=='c' || ch=='d' || ch=='e' || ch=='f' )) a[1]=ch;
    else a[1]='$';


    ch=comp[box.x-1][box.y+1];
    if ((ch=='a' || ch=='b' || ch=='c' || ch=='d' || ch=='e' || ch=='f' )) a[3]=ch;
    else a[2]='$';


    ch=comp[box.x+1][box.y+1];
    if ((ch=='a' || ch=='b' || ch=='c' || ch=='d' || ch=='e' || ch=='f' )) a[5]=ch;
    else a[3]='$';







}
