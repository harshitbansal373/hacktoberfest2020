#include "header.h"
void createmap(SDL_Surface* screen,char comp[20][12]) //plots the map from database
{
    int i,j,k;
    char  ch;

    FILE *fp;
    if ((fp=fopen("temp.lvl","r"))==NULL) return;



    SDL_Rect left_top,right_top,left_bottom,right_bottom,horizontal,vertical;
    SDL_Rect plotter;  //stores cursor to where pic to be loaded
    left_top.x=0;left_top.y=0;left_top.w=24;left_top.h=24;
    right_top.x=24;right_top.y=0;right_top.w=24;right_top.h=24;
    left_bottom.x=48;left_bottom.y=0;left_bottom.w=24;left_bottom.h=24;
    right_bottom.x=72;right_bottom.y=0;right_bottom.w=24;right_bottom.h=24;
    horizontal.x=96;horizontal.y=0;horizontal.w=24;horizontal.h=24;
    vertical.x=120;vertical.y=0;vertical.w=24;vertical.h=24;


    SDL_Surface* border_pic;
    border_pic=load_image("borders.gif");


   //while (1)
    for (k=0;k<240;k++)
    {
        fscanf(fp,"%d %d %c ",&i,&j,&ch);
       // if (i==-1 && j==-1 && ch=='z') break;
        comp[i][j]=ch;




    }


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


fclose(fp);
}


void build_map(SDL_Surface* screen) // map maker...it saves the map to database
{


    extern int quit;
    int what_key;
    char comp[20][12]   ,   ch;
    int i,j;
  /*for (i=0;i<20;i++)
    {
             ch='*' ;
             for (j=0;j<12;j++)
        {
            comp[i][j]=ch ;
        }
    }
*/




    SDL_Rect left_top,right_top,left_bottom,right_bottom,horizontal,vertical;
    SDL_Rect plotter={10,11};  //stores cursor to where pic to be loaded
    left_top.x=0;left_top.y=0;left_top.w=24;left_top.h=24;
    right_top.x=24;right_top.y=0;right_top.w=24;right_top.h=24;
    left_bottom.x=48;left_bottom.y=0;left_bottom.w=24;left_bottom.h=24;
    right_bottom.x=72;right_bottom.y=0;right_bottom.w=24;right_bottom.h=24;
    horizontal.x=96;horizontal.y=0;horizontal.w=24;horizontal.h=24;
    vertical.x=120;vertical.y=0;vertical.w=24;vertical.h=24;


    SDL_Surface* border_pic;
    border_pic=load_image("borders.gif");
    SDL_Surface* tick_mark;
    tick_mark=load_image("tick_mark.gif");

    SDL_Rect tick_up, tick_over,tick_location;
    tick_up.x=0;tick_up.y=0; tick_up.w=50;tick_up.h=30;
    tick_over.x=50;tick_over.y=0; tick_over.w=50;tick_over.h=30;
    tick_location.x=445; tick_location.y=315;

    SDL_BlitSurface(tick_mark,&tick_up,screen,&tick_location);



    SDL_Event key_pressed;
    while (quit==no)
    {
           while(SDL_PollEvent(&key_pressed))
           {

                if(key_pressed.type==SDL_QUIT) quit=yes;
                if (key_pressed.type==SDL_KEYDOWN) what_key=key_pressed.key.keysym.sym;
                if (key_pressed.type==SDL_MOUSEMOTION)
                {
                    if (key_pressed.motion.x >= tick_location.x && key_pressed.motion.x <= tick_location.x+50 && key_pressed.motion.y >= tick_location.y && key_pressed.motion.y <= tick_location.y+30)
                                SDL_BlitSurface(tick_mark,&tick_over,screen,&tick_location);
                    else SDL_BlitSurface(tick_mark,&tick_up,screen,&tick_location);

                }
                 if (key_pressed.type== SDL_MOUSEBUTTONDOWN)
                 {
                     if (key_pressed.button.button==SDL_BUTTON_LEFT && key_pressed.button.x>=tick_location.x && key_pressed.button.x<=tick_location.x+50 && key_pressed.button.y>=tick_location.y && key_pressed.button.y<=tick_location.y+30)
                            { writetofile(comp);   }
                 }


            }


            switch (what_key)
                {
                    case SDLK_UP:
                    plotter.y-=24;

                    break;
                    case SDLK_DOWN:
                    plotter.y+=24;

                    break;
                    case SDLK_RIGHT:
                    plotter.x+=24;

                    break;
                    case SDLK_LEFT:
                    plotter.x-=24;

                    break;
                    case SDLK_a:
                                    comp[(plotter.x-10)/24][(plotter.y-11)/24]='a';
                    break;

                    case SDLK_b:
                                        comp[(plotter.x-10)/24][(plotter.y-11)/24]='b';
                    break;

                    case SDLK_c:
                                        comp[(plotter.x-10)/24][(plotter.y-11)/24]='c';
                    break;

                    case SDLK_d:
                                        comp[(plotter.x-10)/24][(plotter.y-11)/24]='d';
                    break;

                    case SDLK_e:
                                        comp[(plotter.x-10)/24][(plotter.y-11)/24]='e';
                    break;

                    case SDLK_f:
                                        comp[(plotter.x-10)/24][(plotter.y-11)/24]='f';
                    break;

                    default:
                    SDL_BlitSurface(load_image("builder_cursor.gif"),NULL,screen,&plotter);
                    SDL_Flip(screen);
                    SDL_Delay(50);
                    SDL_BlitSurface(load_image("builder_cursor_follow.gif"),NULL,screen,&plotter);

                    break;

                }

//limits editor_cursor upto editor portion only
                if (plotter.x<10) plotter.x=466;
                if (plotter.x>466) plotter.x=10;
                if (plotter.y<11) plotter.y=275;
                if (plotter.y>275) plotter.y=11;
//end of limit

            SDL_Flip(screen);
            what_key=(int)NULL;
            load_array(comp,screen);
            SDL_Flip(screen);

    }
    SDL_FreeSurface(border_pic);

return;
}

