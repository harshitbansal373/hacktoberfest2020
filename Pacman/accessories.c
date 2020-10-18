#include "header.h"

int writetofile(char comp[20][12])
{
    FILE* temp;
    int i,j;
    char ch;
    if ((temp=fopen("temp.lvl","w"))==NULL) return no;

    for (i=0;i<20;i++)
     {
        for (j=0;j<12;j++)
        {
            //CH
             if ((ch=='a' || ch=='b' || ch=='c' || ch=='d' || ch=='e' || ch=='f' )) ch=comp[i][j];
        }
    }

    for (i=0;i<20;i++)
     {
        for (j=0;j<12;j++)
        {
            ch='#';
           if ((ch=='a' || ch=='b' || ch=='c' || ch=='d' || ch=='e' || ch=='f' )) ch=comp[i][j];
                   fprintf(temp,"%d %d %c ",i,j,ch);


        }
     }
        //fprintf(temp,"%d %d %c",-1,-1,'z');
    fclose(temp);
    //fflush(stdin);
    return yes;
}


void load_array(char comp[20][12],SDL_Surface* screen)
{
    int i,j;

    SDL_Surface* border_pic=load_image("borders.gif");
    SDL_Rect left_top,right_top,left_bottom,right_bottom,horizontal,vertical;
    SDL_Rect plotter;  //stores cursor to where pic to be loaded
    left_top.x=0;left_top.y=0;left_top.w=24;left_top.h=24;
    right_top.x=24;right_top.y=0;right_top.w=24;right_top.h=24;
    left_bottom.x=48;left_bottom.y=0;left_bottom.w=24;left_bottom.h=24;
    right_bottom.x=72;right_bottom.y=0;right_bottom.w=24;right_bottom.h=24;
    horizontal.x=96;horizontal.y=0;horizontal.w=24;horizontal.h=24;
    vertical.x=120;vertical.y=0;vertical.w=24;vertical.h=24;


    for (i=0;i<20;i++)
        for (j=0;j<12;j++)
        {
            plotter.x=10+i*24;
            plotter.y=11+j*24;
            if (comp[i][j]=='a')  SDL_BlitSurface(border_pic,&left_top,screen,&plotter);
            else if (comp[i][j]=='b')  SDL_BlitSurface(border_pic,&right_top,screen,&plotter);
            else if (comp[i][j]=='c')  SDL_BlitSurface(border_pic,&left_bottom,screen,&plotter);
            else if (comp[i][j]=='d')  SDL_BlitSurface(border_pic,&right_bottom,screen,&plotter);
            else if (comp[i][j]=='e')  SDL_BlitSurface(border_pic,&horizontal,screen,&plotter);
            else if (comp[i][j]=='f')  SDL_BlitSurface(border_pic,&vertical,screen,&plotter);


        }
}


