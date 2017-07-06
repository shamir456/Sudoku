#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_native_dialog.h>
#include <allegro5\allegro_primitives.h>

void loadingscreen(ALLEGRO_DISPLAY *display);
int maintext(ALLEGRO_DISPLAY *display);
int levelselection( ALLEGRO_DISPLAY *display);

void helppage(ALLEGRO_DISPLAY *display)
{
	al_flip_display();
	al_rest(1);

}

int n()
{

   ALLEGRO_DISPLAY *display = NULL;

   al_init();
   al_init_image_addon();
   al_init_font_addon();
   al_init_ttf_addon();
   al_install_mouse();
   al_init_primitives_addon();

   if(!al_init())
   {
	   al_show_native_message_box(display,"Oops!!","ERROR!","Failed to Initialize Allegro!",NULL,ALLEGRO_MESSAGEBOX_ERROR);
	   return -1;
   }
	display=al_create_display(640,480);
	if(!display)
	   {
		   al_show_native_message_box(display,"Oops!!","ERROR!","Failed to Build Display",NULL,ALLEGRO_MESSAGEBOX_ERROR);
	   }


   loadingscreen(display);
   int choice= maintext(display);

	  switch(choice)
	  {
		case 1:
			{
				//display=al_create_display(640,480);
				int levelchoice= levelselection(display);
				break;
			}

		case 2:
			{
				display=al_create_display(600,400);
				helppage(display);
			}
	  }
	  return 0;
}

void loadingscreen(ALLEGRO_DISPLAY *display)
{
	ALLEGRO_BITMAP *loading=NULL;
	ALLEGRO_BITMAP *loadingtext=NULL;

	loading=al_load_bitmap("loadingresized.png");
	loadingtext=al_load_bitmap("loadingtextresized.png");
	if(!loading)
	{
		al_show_native_message_box(display,"Oops!","Cannot Display the image!",NULL,NULL,ALLEGRO_MESSAGEBOX_ERROR);
	}
	if(!loadingtext)
	{
		al_show_native_message_box(display,"Oops!","Cannot Display the image!",NULL,NULL,ALLEGRO_MESSAGEBOX_ERROR);
	}
	al_draw_bitmap(loadingtext,200,100,0);
	al_draw_bitmap(loading,250,200,0);
	al_flip_display();
	al_rest(1);
	al_flip_display();
	al_destroy_bitmap(loadingtext);
	al_destroy_bitmap(loading);
	al_destroy_display(display);

}
int maintext(ALLEGRO_DISPLAY *display)
{
	bool check=false;
	bool mousebuttonplay=false;
	bool mousebuttonhelp=false;
	bool mousebuttonexit=false;

	display=al_create_display(640,480);
	 ALLEGRO_BITMAP *title=NULL;
	 ALLEGRO_BITMAP *play=NULL;
	 ALLEGRO_BITMAP *help=NULL;
	ALLEGRO_BITMAP *exit=NULL;
	ALLEGRO_EVENT_QUEUE *queue;
	ALLEGRO_EVENT events;

	queue=al_create_event_queue();
	al_register_event_source(queue,al_get_display_event_source(display));
	al_register_event_source(queue,al_get_mouse_event_source());


	exit=al_load_bitmap("exit.png");
	 help=al_load_bitmap("helpme.png");
	 play=al_load_bitmap("playnow.png");
	 title=al_load_bitmap("sudoku.png");
	 al_draw_bitmap(title,20,10,0);
	 al_draw_bitmap(play,200,150,0);
	 al_draw_bitmap(help,200,250,0);
	 al_draw_bitmap(exit,200,350,0);
	 al_flip_display();

	 while(check == false)
	{
		al_wait_for_event(queue,&events);
		if( events.type == ALLEGRO_EVENT_MOUSE_AXES)
		{
			if((events.mouse.x >= 200) && (events.mouse.x <= 200+152) && (events.mouse.y >= 150) && (events.mouse.y <= 150+84))
			{
				mousebuttonplay=true;
			}
			else if ((events.mouse.x >= 200) && (events.mouse.x <= 200+152) && (events.mouse.y >= 150) && (events.mouse.y <=250+84))
			{
				mousebuttonhelp=true;
			}
			else
			{
				mousebuttonplay=false;
			}
		}
		if(events.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			if(mousebuttonplay==true)
			{
				al_destroy_display(display);
				return 1;
			}
			if(mousebuttonhelp==true)
			{
				return 2;
			}
		}
		if(events.type== ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			check=true;
		}
	}
	 al_rest(1);
	 return 0;
}

int levelselection(ALLEGRO_DISPLAY *display)
{
	display=al_create_display(640,480);
	bool check=false;
	bool easybutton=false;
	bool mediumbutton=false;
	bool hardbutton= false;
	bool backbutton=false;

	ALLEGRO_BITMAP *easy=NULL;
	ALLEGRO_BITMAP *medium=NULL;
	ALLEGRO_BITMAP *hard=NULL;
	ALLEGRO_BITMAP *back=NULL;
	ALLEGRO_BITMAP *title=NULL;

	ALLEGRO_EVENT_QUEUE *queue;
	ALLEGRO_EVENT events;

	queue=al_create_event_queue();
	al_register_event_source(queue,al_get_display_event_source(display));
	al_register_event_source(queue,al_get_mouse_event_source());

	al_flip_display();

	while(check== false)
	{
		al_wait_for_event(queue,&events);


		if(events.type== ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			check=true;
		}
	}
	return 0;
}
