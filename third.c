#include "allegro5/allegro.h"
#include <allegro5/allegro_native_dialog.h>
#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_primitives.h>
#include<allegro5/allegro_font.h>
#include<allegro5/bitmap.h>
#include<allegro5/bitmap_draw.h>
#include<allegro5/allegro_ttf.h>
#include<allegro5/allegro.h>
#include<allegro5/allegro5.h>

int cre(){
     al_init();
   int width=980;
    int height=520;
 bool done=false;
 int pos_x=width/2-65;
	int pos_y=height/2-50;

    al_init_font_addon();
    al_init_ttf_addon();
    al_install_keyboard();
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    ALLEGRO_DISPLAY *dis = al_create_display(width, height);


    event_queue = al_create_event_queue();
    al_register_event_source(event_queue,al_get_keyboard_event_source());
   // ALLEGRO_BITMAP *title = al_load_bitmap("SUDOKU.bmp");
       al_set_window_title(dis, "SUDOKU");

     ALLEGRO_FONT *font24 =al_load_font("E:/Sudoku/Sudoku/arial.ttf",32,0);
      ALLEGRO_FONT *font25 =al_load_font("E:/Sudoku/Sudoku/arial.ttf",55,0);
    al_init_font_addon();
    // assert(font24);
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_init_ttf_addon();


          al_clear_to_color(al_map_rgb(0,0,0));
     al_init_primitives_addon();
	al_install_keyboard();
	event_queue = al_create_event_queue();

	al_register_event_source(event_queue,al_get_keyboard_event_source());

	while(!done)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue,&ev);



		if(ev.keyboard.keycode)
		{
			switch(ev.keyboard.keycode)
			{
            case ALLEGRO_KEY_UP:
                if(pos_y>=20)
                pos_y-= 10;
            break;
            case ALLEGRO_KEY_DOWN:
                if(pos_y<=320)
                pos_y+= 10;
            break;
            case ALLEGRO_KEY_ENTER:
                if(pos_y>=90 && pos_y<=110)
                {
                    medium();
                }
                else if(pos_y>=162 && pos_y<=210)
                {
                    easy();

                    //game2();
                }
                else if(pos_y>=250 && pos_y<=300)
                {
                    hard();

                    //game3();
                }
            case ALLEGRO_KEY_ESCAPE:

                done=true;
                al_flip_display();

            break;
			}




        }

        if(pos_x>=400 && pos_x<=500 && pos_y>=10 && pos_y<=330)
        {
            al_draw_rectangle(pos_x-50,pos_y,pos_x+250,pos_y+80,al_map_rgb(135,45,25),5 );

            al_draw_textf(font25,al_map_rgb(244,0,123),980/2,520/2-150,ALLEGRO_ALIGN_CENTER,"EASY");

            al_draw_textf(font25,al_map_rgb(244,0,123),980/2,520/2-50,ALLEGRO_ALIGN_CENTER,"MEDIUM");
            al_draw_textf(font25,al_map_rgb(244,0,123),980/2,520/2+50,ALLEGRO_ALIGN_CENTER,"HARD");


        }
        al_flip_display();
        al_clear_to_color(al_map_rgb(0,0,0));



   //  al_clear_to_color(al_map_rgb(0,0,0));




    }
    // al_get_display_format(dis);
  // al_flip_display();
   // al_destroy_display(dis);
}

