#include<allegro5/allegro.h>
#include<allegro5/keyboard.h>
#include<allegro5/keycodes.h>
#include<allegro5/allegro_primitives.h>
#include<stdio.h>
#include<allegro5/allegro_font.h>
int score=100,current_score=0;
ALLEGRO_BITMAP *k1=NULL;  //bit map pointer declaration
   ALLEGRO_BITMAP *k2=NULL;
   ALLEGRO_BITMAP *k3=NULL;
   ALLEGRO_BITMAP *k4=NULL;
   ALLEGRO_BITMAP *k5=NULL;
   ALLEGRO_BITMAP *k6=NULL;
   ALLEGRO_BITMAP *k7=NULL;
   ALLEGRO_BITMAP *k8=NULL;
   ALLEGRO_BITMAP *k9=NULL;

int sc(int arr[][9],int a[][9])//fucntion to check if or not sudoku
{
    int s=0,i,j;
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            if(arr[i][j]==a[i][j])
        {

            s++;
        }

        }

    }
    return s;

}
void show_medium()
{
    k1=al_load_bitmap("1.png");// for displaying the sudoku numbers for help
    al_draw_bitmap(k1,120,0,0);
  //  al_save_bitmap(k1,"1.png");
    al_draw_bitmap(k1,0,60,0);
    al_draw_bitmap(k1,180,210,0);

    k2=al_load_bitmap("2.png");
    al_draw_bitmap(k2,60,30,0);
    al_draw_bitmap(k2,210,120,0);
    al_draw_bitmap(k2,0,150,0);
    al_draw_bitmap(k2,240,240,0);
    k3=al_load_bitmap("3.png");
    al_draw_bitmap(k3,120,60,0);
    al_draw_bitmap(k3,240,90,0);
    al_draw_bitmap(k3,150,180,0);
    al_draw_bitmap(k3,210,210,0);


    k4=al_load_bitmap("4.png");
    al_draw_bitmap(k4,210,0,0);
    al_draw_bitmap(k4,30,60,0);
    al_draw_bitmap(k4,150,30,0);
    al_draw_bitmap(k4,120,180,0);
    al_draw_bitmap(k4,90,90,0);
    k5=al_load_bitmap("5.png");
    al_draw_bitmap(k5,90,150,0);
    k6=al_load_bitmap("6.png");
    al_draw_bitmap(k6,180,240,0);
    al_draw_bitmap(k6,90,210,0);
    k7=al_load_bitmap("7.png");
    al_draw_bitmap(k7,150,90,0);
    al_draw_bitmap(k7,240,30,0);
    al_draw_bitmap(k7,90,60,0);
    al_draw_bitmap(k7,0,210,0);
    al_draw_bitmap(k7,30,120,0);
    al_draw_bitmap(k7,120,240,0);
    al_draw_bitmap(k7,60,0,0);
    k8=al_load_bitmap("8.png");
    al_draw_bitmap(k8,30,30,0);
    al_draw_bitmap(k8,240,180,0);
    k9=al_load_bitmap("9.png");
    al_draw_bitmap(k9,30,240,0);
    al_draw_bitmap(k9,210,180,0);
    al_draw_bitmap(k9,0,0,0);
    al_draw_bitmap(k9,150,150,0);

}
void show_easy()
{
    k1=al_load_bitmap("1.png");// for displaying the sudoku numbers for help
    al_draw_bitmap(k1,0,0,0);
    al_draw_bitmap(k1,150,60,0);
    al_draw_bitmap(k1,90,90,0);
    al_draw_bitmap(k1,60,120,0);
    al_draw_bitmap(k1,210,150,0);
    al_draw_bitmap(k1,30,180,0);
    al_draw_bitmap(k1,120,240,0);


    k2=al_load_bitmap("2.png");
    al_draw_bitmap(k2,180,60,0);
    al_draw_bitmap(k2,120,90,0);
    al_draw_bitmap(k2,30,210,0);
    al_draw_bitmap(k2,150,240,0);
    k3=al_load_bitmap("3.png");
    al_draw_bitmap(k3,30,30,0);
    al_draw_bitmap(k3,0,90,0);
    al_draw_bitmap(k3,150,120,0);
    al_draw_bitmap(k3,210,210,0);
    al_draw_bitmap(k3,60,240,0);


    k4=al_load_bitmap("4.png");
    al_draw_bitmap(k4,90,0,0);
    al_draw_bitmap(k4,210,30,0);
    al_draw_bitmap(k4,0,60,0);
    al_draw_bitmap(k4,30,150,0);
    al_draw_bitmap(k4,60,180,0);
    al_draw_bitmap(k4,120,210,0);
    al_draw_bitmap(k4,240,240,0);
    k5=al_load_bitmap("5.png");
    al_draw_bitmap(k5,120,30,0);
    al_draw_bitmap(k5,240,60,0);
    al_draw_bitmap(k5,0,120,0);
    al_draw_bitmap(k5,150,150,0);
    al_draw_bitmap(k5,90,240,0);
    k6=al_load_bitmap("6.png");
    al_draw_bitmap(k6,240,0,0);
    al_draw_bitmap(k6,30,60,0);
    al_draw_bitmap(k6,180,90,0);
    al_draw_bitmap(k6,60,150,0);
    al_draw_bitmap(k6,90,180,0);
    k7=al_load_bitmap("7.png");
    al_draw_bitmap(k7,0,30,0);
    al_draw_bitmap(k7,60,90,0);
    al_draw_bitmap(k7,90,120,0);
    al_draw_bitmap(k7,180,150,0);
    al_draw_bitmap(k7,240,210,0);
    k8=al_load_bitmap("8.png");
    al_draw_bitmap(k8,120,0,0);
    al_draw_bitmap(k8,30,90,0);
    al_draw_bitmap(k8,240,120,0);
    al_draw_bitmap(k8,210,180,0);
    al_draw_bitmap(k8,0,240,0);
    k9=al_load_bitmap("9.png");
    al_draw_bitmap(k9,150,0,0);
    al_draw_bitmap(k9,210,60,0);
    al_draw_bitmap(k9,120,150,0);
    al_draw_bitmap(k9,0,180,0);


}
void show_hard()
{
        k2=al_load_bitmap("2.png");//for displaying sudoku numbers for help
    al_draw_bitmap(k2,240,120,0);
    al_draw_bitmap(k2,30,240,0);
    k3=al_load_bitmap("3.png");
    al_draw_bitmap(k3,150,30,0);
    al_draw_bitmap(k3,0,60,0);
    al_draw_bitmap(k3,60,120,0);
    al_draw_bitmap(k3,210,150,0);
    al_draw_bitmap(k3,180,180,0);


    k4=al_load_bitmap("4.png");
    al_draw_bitmap(k4,210,60,0);
    al_draw_bitmap(k4,0,90,0);
    //al_draw_bitmap(k4,120,180,0);
    k5=al_load_bitmap("5.png");
    al_draw_bitmap(k5,240,60,0);
    al_draw_bitmap(k5,120,120,0);
    k6=al_load_bitmap("6.png");
    al_draw_bitmap(k6,180,0,0);
    al_draw_bitmap(k6,240,150,0);
    al_draw_bitmap(k6,30,180,0);
    al_draw_bitmap(k6,90,210,0);
    k7=al_load_bitmap("7.png");
    al_draw_bitmap(k7,120,30,0);
    al_draw_bitmap(k7,0,210,0);

    k8=al_load_bitmap("8.png");
    al_draw_bitmap(k8,210,0,0);
    al_draw_bitmap(k8,240,180,0);
     al_draw_bitmap(k8,120,210,0);
     al_draw_bitmap(k8,0,120,0);

     al_draw_bitmap(k8,60,240,0);
    k9=al_load_bitmap("9.png");
    al_draw_bitmap(k9,240,30,0);
    al_draw_bitmap(k9,60,60,0);
    al_draw_bitmap(k9,30,90,0);
    al_draw_bitmap(k9,180,120,0);
    al_draw_bitmap(k9,0,180,0);

}
void  medium()
{
    int life=0;
	int width=500;//sizing display
	int height=400;

	bool done = false;
	int pos_x=0;//for positioning
	int pos_y=0;
    int x=0,y=0;//to be used in logic
	int medium_solution[9][9]= {
						{9,3,7,8,1,2,5,4,6},
						{6,8,2,9,5,4,3,1,7},
						{1,4,5,7,3,6,2,8,9},
						{8,5,1,4,2,7,9,6,3},
						{4,7,9,3,6,1,8,2,5},
						{2,6,3,5,8,9,4,7,1},
						{5,1,6,2,4,3,7,9,8},
						{7,2,8,6,9,5,1,3,4},
						{3,9,4,1,7,8,6,5,2},
							   };

	int medium_l[9][9]= {
						{9,0,7,0,1,0,0,4,0},
						{0,8,2,0,0,4,0,0,7},
						{1,4,0,7,3,0,0,0,0},
						{0,0,0,4,0,7,0,0,3},
						{0,7,0,0,0,0,0,2,0},
						{2,0,0,5,0,9,0,0,0},
						{0,0,0,0,4,3,0,9,8},
						{7,0,0,6,0,0,1,3,0},
						{0,9,0,0,7,0,6,0,2},
							   };

   ALLEGRO_BITMAP *k1=NULL;
   ALLEGRO_BITMAP *k2=NULL;
   ALLEGRO_BITMAP *k3=NULL;
   ALLEGRO_BITMAP *k4=NULL;
   ALLEGRO_BITMAP *k5=NULL;
   ALLEGRO_BITMAP *k6=NULL;
   ALLEGRO_BITMAP *k7=NULL;
   ALLEGRO_BITMAP *k8=NULL;
   ALLEGRO_BITMAP *k9=NULL;
  // ALLEGRO_BITMAP k[9]=NULL;

	ALLEGRO_DISPLAY *dis= NULL;//display pointer declaration
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;//list of events to be used
	ALLEGRO_FONT *font24 =al_load_font("E:/Sudoku/Sudoku/arial.ttf",16,0);
	 al_init_font_addon();
    al_set_window_title(dis, "SUDOKU");
	if(!al_init())
	return -1;

	dis= al_create_display(width,height);
	if(!dis)
	return -1;

	al_init_primitives_addon();
	al_install_keyboard();//installing
	event_queue = al_create_event_queue();

	al_register_event_source(event_queue,al_get_keyboard_event_source());
	al_register_event_source(event_queue,al_get_display_event_source(dis));

   // al_flip_display();
    int k=0,check=10;
   show_medium();
//al_clear_to_color(al_map_rgb(0,0,0));
  al_draw_textf(font24,al_map_rgb(255,255,255),width-50,10,ALLEGRO_ALIGN_RIGHT,"Score:%d",current_score);
  al_draw_textf(font24,al_map_rgb(255,255,255),width-50,height-50,ALLEGRO_ALIGN_RIGHT,"Checks left : %d",check);
	while(!done)
	{
	     ALLEGRO_EVENT ev;

		 al_wait_for_event(event_queue,&ev);








		if(ev.type==ALLEGRO_EVENT_KEY_DOWN)
		{
		            switch(ev.keyboard.keycode)
                    {
                    case ALLEGRO_KEY_UP:
                        if(pos_y>0 )
                        pos_y-= 30;
                        y=pos_y/30;
                        //y--;
                    break;
                    case ALLEGRO_KEY_DOWN:
                        if( pos_y<240)
                        pos_y+= 30;
                        y=pos_y/30;
                        //y--;
                    break;
                    case ALLEGRO_KEY_LEFT:
                        if(pos_x>0)
                        pos_x-=30;
                        x=pos_x/30;
                        //x--;
                    break;
                    case ALLEGRO_KEY_RIGHT:
                        if(pos_x<240)
                        pos_x+= 30;
                        x=pos_x/30;
                        //x--;

                    break;
                    case ALLEGRO_KEY_ENTER:


                        if(life<=10 && check>0)
                        {
                            k=sc(medium_l,medium_solution);
                            life++;
                            check--;
                            if(k==81)
                            {

                                al_clear_to_color(al_map_rgb(0,0,0));
                                al_flip_display();
                                current_score=score-(life*10);
                                if(current_score==90)
                                {

                                    current_score+=10;
                                }
                                al_draw_textf(font24,al_map_rgb(255,255,255),height/2,height/2,ALLEGRO_ALIGN_CENTER,"YOU WON");
                                al_draw_textf(font24,al_map_rgb(255,255,255),width/2+100,height/2+100,ALLEGRO_ALIGN_CENTER,"Score:%d",current_score);
                                //al_flip_display();
                                al_rest(3);
                              done=true;

                            }
                            else
                            if(check==0)
                            {
                                al_clear_to_color(al_map_rgb(0,0,0));
                                 al_flip_display();
                                al_draw_textf(font24,al_map_rgb(255,255,255),width/2,height/2,ALLEGRO_ALIGN_CENTER,"YOU LOST");
                                al_draw_textf(font24,al_map_rgb(255,255,255),width/2,height/2+100,ALLEGRO_ALIGN_CENTER,"Score:%d",0);

                                al_flip_display();
                                al_rest(3);

                                done=true;



                            }
                            else
                            {
                                 al_clear_to_color(al_map_rgb(0,0,0));


                                current_score=score-(life*10);
                                //check--;
                                show_medium();
                                al_draw_textf(font24,al_map_rgb(255,255,255),width-50,10,ALLEGRO_ALIGN_RIGHT,"Score:%d",current_score);
                                al_draw_textf(font24,al_map_rgb(255,255,255),width-50,height-50,ALLEGRO_ALIGN_RIGHT,"Check : %d",check);
                                al_flip_display();

                            }

                        }
                        break;

                    case ALLEGRO_KEY_1:

                         k1=al_load_bitmap("1.png");
                         //x--;
                         //y--;
                         medium_l[y][x]=1;
                         al_draw_bitmap(k1,pos_x,pos_y,0);
                        break;
                        case ALLEGRO_KEY_2:

                        k2=al_load_bitmap("2.png");

                        medium_l[y][x]=2;
                         al_draw_bitmap(k2,pos_x,pos_y,0);


                        break;




                    case ALLEGRO_KEY_3:
                        k3=al_load_bitmap("3.png");

                        medium_l[y][x]=3;

                         al_draw_bitmap(k3,pos_x,pos_y,0);

                        break;
                    case ALLEGRO_KEY_4:
                        k4=al_load_bitmap("4.png");

                        medium_l[y][x]=4;
                         al_draw_bitmap(k4,pos_x,pos_y,0);

                        break;
                    case ALLEGRO_KEY_5:
                        k5=al_load_bitmap("5.png");

                        medium_l[y][x]=5;
                         al_draw_bitmap(k5,pos_x,pos_y,0);

                        break;
                    case ALLEGRO_KEY_6:

                        k6=al_load_bitmap("6.png");


                        medium_l[y][x]=6;
                         al_draw_bitmap(k6,pos_x,pos_y,0);

                        break;
                    case ALLEGRO_KEY_7:
                        k7=al_load_bitmap("7.png");


                        medium_l[y][x]=7;
                         al_draw_bitmap(k7,pos_x,pos_y,0);

                        break;
                    case ALLEGRO_KEY_8:
                        k8=al_load_bitmap("8.png");

                        medium_l[y][x]=8;
                         al_draw_bitmap(k8,pos_x,pos_y,0);

                        break;
                    case ALLEGRO_KEY_9:
                        k9=al_load_bitmap("9.png");

                        medium_l[y][x]=9;
                         al_draw_bitmap(k9,pos_x,pos_y,0);

                        break;

                    }

		}


		else if(ev.type==ALLEGRO_EVENT_DISPLAY_CLOSE)
        {

            done=true;
        }



      if(!done)
      {
           al_draw_rectangle(pos_x,pos_y,pos_x+30,pos_y+30,al_map_rgb(255,255,255),3 );

      }



        al_flip_display();


		}



         al_rest(3);






	al_destroy_display(dis);
}

void easy()
{
    int width=500;
	int height=400;
int life=0;

	bool done = false;
	int pos_x=0;
	int pos_y=0;
    int x=0,y=0;
	int easy_solution[9][9]= {
						{1,5,2,4,8,9,3,7,6},
						{7,3,9,2,5,6,8,4,1},
						{4,6,8,3,7,1,2,9,5},
						{3,8,7,1,2,4,6,5,9},
						{5,9,1,7,6,3,4,2,8},
						{2,4,6,8,9,5,7,1,3},
						{9,1,4,6,3,7,5,8,2},
						{6,2,5,9,4,8,1,3,7},
						{8,7,3,5,1,2,9,6,4},
							   };

	int easy_l[9][9]= {
						{1,0,0,4,8,9,0,0,6},
						{7,3,0,0,5,0,0,4,0},
						{4,6,0,0,0,1,2,9,5},
						{3,8,7,1,2,0,6,0,0},
						{5,0,1,7,0,3,0,0,8},
						{0,4,6,0,9,5,7,1,0},
						{9,1,4,6,0,0,0,8,0},
						{0,2,0,0,4,0,0,3,7},
						{8,0,3,5,1,2,0,0,4},
							   };


	ALLEGRO_DISPLAY *dis= NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;//list of events
	ALLEGRO_FONT *font24 =al_load_font("E:/Sudoku/Sudoku/arial.ttf",16,0);//font use
	 al_init_font_addon();//declaring that font header file will be used
    al_set_window_title(dis, "SUDOKU");//setting header bar's name
	if(!al_init())
	return -1;

	dis= al_create_display(width,height);//creating display screen
	if(!dis)
	return -1;

	al_init_primitives_addon();//to control images ,drawings etc
	al_install_keyboard();//installing keyboard
	event_queue = al_create_event_queue();//creating events

	al_register_event_source(event_queue,al_get_keyboard_event_source());
	al_register_event_source(event_queue,al_get_display_event_source(dis));

    int k=0,check=10;
    show_easy();
    al_draw_textf(font24,al_map_rgb(255,255,255),width-50,10,ALLEGRO_ALIGN_RIGHT,"Score:%d",current_score);
    al_draw_textf(font24,al_map_rgb(255,255,255),width-50,height-50,ALLEGRO_ALIGN_RIGHT,"Check : %d",check);


	while(!done)
	{
	     ALLEGRO_EVENT ev;

		 al_wait_for_event(event_queue,&ev);//taking input








		if(ev.type==ALLEGRO_EVENT_KEY_DOWN)
		{
		            switch(ev.keyboard.keycode)
                    {
                    case ALLEGRO_KEY_UP:
                        if(pos_y>0 )
                        pos_y-= 30;
                        y=pos_y/30;
                        //y--;
                    break;
                    case ALLEGRO_KEY_DOWN:
                        if( pos_y<240)
                        pos_y+= 30;
                        y=pos_y/30;
                        //y--;
                    break;
                    case ALLEGRO_KEY_LEFT:
                        if(pos_x>0)
                        pos_x-=30;
                        x=pos_x/30;
                        //x--;
                    break;
                    case ALLEGRO_KEY_RIGHT:
                        if(pos_x<240)
                        pos_x+= 30;
                        x=pos_x/30;
                        //x--;

                    break;
                    case ALLEGRO_KEY_ENTER:

                         if(life<=10 && check>0)
                        {
                            k=sc(easy_l,easy_solution);
                            life++;
                            check--;
                            if(k==81)
                            {
                                al_clear_to_color(al_map_rgb(0,0,0));
                                al_flip_display();
                                current_score=score-(life*10);
                                //current_score=score-(life*10);
                                if(current_score==90)
                                {

                                    current_score+=10;
                                }


                                al_draw_textf(font24,al_map_rgb(255,255,255),width/2,height/2,ALLEGRO_ALIGN_CENTER,"YOU WON");
                                al_draw_textf(font24,al_map_rgb(255,255,255),width/2,height/2+100,ALLEGRO_ALIGN_CENTER,"Score:%d",current_score);
                                //al_clear_to_color(al_map_rgb(0,0,0));
                                 al_rest(4);
                                done=true;

                            }
                            else
                            if(check==0)
                            {
                                al_clear_to_color(al_map_rgb(0,0,0));
                                al_flip_display();
                                al_draw_textf(font24,al_map_rgb(255,255,255),width/2,height/2,ALLEGRO_ALIGN_CENTER,"YOU LOST");
                                al_draw_textf(font24,al_map_rgb(255,255,255),width/2,height/2+100,ALLEGRO_ALIGN_CENTER,"Score:%d",0);

                                done=true;



                            }
                            else
                            {
                                 al_clear_to_color(al_map_rgb(0,0,0));


                                current_score=score-(life*10);
                                //check--;
                                show_easy();
                                al_draw_textf(font24,al_map_rgb(255,255,255),width-50,10,ALLEGRO_ALIGN_RIGHT,"Score:%d",current_score);
                                al_draw_textf(font24,al_map_rgb(255,255,255),width-50,height-50,ALLEGRO_ALIGN_RIGHT,"Check : %d",check);
                                al_flip_display();



                            }

                        }
                        break;

                    case ALLEGRO_KEY_1:

                         k1=al_load_bitmap("1.png");
                         //x--;
                         //y--;
                         easy_l[y][x]=1;
                         al_draw_bitmap(k1,pos_x,pos_y,0);
                        break;
                        case ALLEGRO_KEY_2:

                        k2=al_load_bitmap("2.png");

                        easy_l[y][x]=2;
                         al_draw_bitmap(k2,pos_x,pos_y,0);


                        break;




                    case ALLEGRO_KEY_3:
                        k3=al_load_bitmap("3.png");

                        easy_l[y][x]=3;

                         al_draw_bitmap(k3,pos_x,pos_y,0);

                        break;
                    case ALLEGRO_KEY_4:
                        k4=al_load_bitmap("4.png");

                        easy_l[y][x]=4;
                         al_draw_bitmap(k4,pos_x,pos_y,0);

                        break;
                    case ALLEGRO_KEY_5:
                        k5=al_load_bitmap("5.png");

                        easy_l[y][x]=5;
                         al_draw_bitmap(k5,pos_x,pos_y,0);

                        break;
                    case ALLEGRO_KEY_6:

                        k6=al_load_bitmap("6.png");


                        easy_l[y][x]=6;
                         al_draw_bitmap(k6,pos_x,pos_y,0);

                        break;
                    case ALLEGRO_KEY_7:
                        k7=al_load_bitmap("7.png");


                        easy_l[y][x]=7;
                         al_draw_bitmap(k7,pos_x,pos_y,0);

                        break;
                    case ALLEGRO_KEY_8:
                        k8=al_load_bitmap("8.png");

                       easy_l[y][x]=8;
                         al_draw_bitmap(k8,pos_x,pos_y,0);

                        break;
                    case ALLEGRO_KEY_9:
                        k9=al_load_bitmap("9.png");

                        easy_l[y][x]=9;
                         al_draw_bitmap(k9,pos_x,pos_y,0);

                        break;

                    }

         }


		else if(ev.type==ALLEGRO_EVENT_DISPLAY_CLOSE)
        {

            done=true;
        }




      if(!done)
      {
          al_draw_rectangle(pos_x,pos_y,pos_x+30,pos_y+30,al_map_rgb(255,255,255),3 );

      }

        al_flip_display();


	}
	al_rest(3);
	al_destroy_display(dis);


}
void hard()
{
    int width=500;
	int height=400;

	bool done = false;
	int pos_x=0;
	int pos_y=0;
    int x=0,y=0;
int hard_solution[9][9]= {
						{1,7,2,5,4,9,6,8,3},
						{6,4,5,8,7,3,2,1,9},
						{3,8,9,2,6,1,7,4,5},
						{4,9,6,3,2,7,8,5,1},
						{8,1,3,4,5,6,9,7,2},
						{2,5,7,1,9,8,4,3,6},
						{9,6,4,7,1,5,3,2,8},
						{7,3,1,6,8,2,5,9,4},
						{5,2,8,9,3,4,1,6,7},
							   };

	int hard_l[9][9]= {
						{0,0,0,0,0,0,6,8,0},
						{0,0,0,0,7,3,0,0,9},
						{3,0,9,0,0,0,0,4,5},
						{4,9,0,0,0,0,0,0,0},
						{8,0,3,0,5,0,9,0,2},
						{0,0,0,0,0,0,0,3,6},
						{9,6,0,0,0,0,3,0,8},
						{7,0,0,6,8,0,0,0,0},
						{0,2,8,0,0,0,0,0,0},
							   };



	ALLEGRO_DISPLAY *dis= NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_FONT *font24 =al_load_font("E:/Sudoku/Sudoku/arial.ttf",16,0);
    al_init_font_addon();
    al_set_window_title(dis, "SUDOKU");
	if(!al_init())
	return -1;

	dis= al_create_display(width,height);
	if(!dis)
	return -1;

	al_init_primitives_addon();
	al_install_keyboard();//installing
	event_queue = al_create_event_queue();

	al_register_event_source(event_queue,al_get_keyboard_event_source());
	al_register_event_source(event_queue,al_get_display_event_source(dis));

    show_hard();

    int k=0,check=10,life=0;

    al_draw_textf(font24,al_map_rgb(255,255,255),width-50,10,ALLEGRO_ALIGN_RIGHT,"Score:%d",current_score);
    al_draw_textf(font24,al_map_rgb(255,255,255),width-50,height-50,ALLEGRO_ALIGN_RIGHT,"Check : %d",check);


	while(!done)
	{
	     ALLEGRO_EVENT ev;

		 al_wait_for_event(event_queue,&ev);

		if(ev.type==ALLEGRO_EVENT_KEY_DOWN)
		{
		            switch(ev.keyboard.keycode)
                    {
                    case ALLEGRO_KEY_UP:
                        if(pos_y>0 )
                        pos_y-= 30;
                        y=pos_y/30;
                        //y--;
                    break;
                    case ALLEGRO_KEY_DOWN:
                        if( pos_y<240)
                        pos_y+= 30;
                        y=pos_y/30;
                        //y--;
                    break;
                    case ALLEGRO_KEY_LEFT:
                        if(pos_x>0)
                        pos_x-=30;
                        x=pos_x/30;
                        //x--;
                    break;
                    case ALLEGRO_KEY_RIGHT:
                        if(pos_x<240)
                        pos_x+= 30;
                        x=pos_x/30;
                        //x--;

                    break;
                    case ALLEGRO_KEY_ENTER:

                      if(life<=10 && check>0)
                        {
                            k=sc(hard_l,hard_solution);
                            life++;
                            check--;
                            if(k==81)
                            {
                                al_clear_to_color(al_map_rgb(0,0,0));
                                 al_flip_display();
                                //al_rest(1.5);
                                 current_score=score-(life*10);
                                 if(current_score==90)
                                {

                                    current_score+=10;
                                }

                                al_draw_textf(font24,al_map_rgb(255,255,255),pos_y,pos_x,ALLEGRO_ALIGN_CENTER,"YOU WON");
                                al_draw_textf(font24,al_map_rgb(255,255,255),width/2,height/2+100,ALLEGRO_ALIGN_CENTER,"Score:%d",current_score);
                                 //al_flip_display();
                                al_rest(3);
                                done=true;


                            }
                            else
                            if(check==0)
                            {
                                al_clear_to_color(al_map_rgb(0,0,0));
                                al_flip_display();
                                al_draw_textf(font24,al_map_rgb(255,255,255),width/2,height/2,ALLEGRO_ALIGN_CENTER,"YOU LOST");
                                al_draw_textf(font24,al_map_rgb(255,255,255),width/2,height/2+100,ALLEGRO_ALIGN_CENTER,"Score:%d",0);


                                done=true;



                            }
                            else
                            {
                                 al_clear_to_color(al_map_rgb(0,0,0));


                                current_score=score-(life*10);
                                //check--;
                                show_hard();
                                al_draw_textf(font24,al_map_rgb(255,255,255),width-50,10,ALLEGRO_ALIGN_RIGHT,"Score:%d",current_score);
                                al_draw_textf(font24,al_map_rgb(255,255,255),width-50,height-50,ALLEGRO_ALIGN_RIGHT,"Check : %d",check);
                                al_flip_display();



                            }

                        }
                        break;
                    case ALLEGRO_KEY_1:

                         k1=al_load_bitmap("1.png");
                        hard_l[y][x]=1;
                         al_draw_bitmap(k1,pos_x,pos_y,0);
                        break;
                        case ALLEGRO_KEY_2:

                        k2=al_load_bitmap("2.png");

                        hard_l[y][x]=2;
                         al_draw_bitmap(k2,pos_x,pos_y,0);


                        break;




                    case ALLEGRO_KEY_3:
                        k3=al_load_bitmap("3.png");

                        hard_l[y][x]=3;

                         al_draw_bitmap(k3,pos_x,pos_y,0);

                        break;
                    case ALLEGRO_KEY_4:
                        k4=al_load_bitmap("4.png");

                        hard_l[y][x]=4;
                         al_draw_bitmap(k4,pos_x,pos_y,0);

                        break;
                    case ALLEGRO_KEY_5:
                        k5=al_load_bitmap("5.png");

                        hard_l[y][x]=5;
                         al_draw_bitmap(k5,pos_x,pos_y,0);

                        break;
                    case ALLEGRO_KEY_6:

                        k6=al_load_bitmap("6.png");


                        hard_l[y][x]=6;
                         al_draw_bitmap(k6,pos_x,pos_y,0);

                        break;
                    case ALLEGRO_KEY_7:
                        k7=al_load_bitmap("7.png");


                        hard_l[y][x]=7;
                         al_draw_bitmap(k7,pos_x,pos_y,0);

                        break;
                    case ALLEGRO_KEY_8:
                        k8=al_load_bitmap("8.png");

                        hard_l[y][x]=8;
                         al_draw_bitmap(k8,pos_x,pos_y,0);

                        break;
                    case ALLEGRO_KEY_9:
                        k9=al_load_bitmap("9.png");

                        hard_l[y][x]=9;
                         al_draw_bitmap(k9,pos_x,pos_y,0);

                        break;

                    }

		}


		else if(ev.type==ALLEGRO_EVENT_DISPLAY_CLOSE)
        {

            done=true;
        }
        if(!done)
        {
            al_draw_rectangle(pos_x,pos_y,pos_x+30,pos_y+30,al_map_rgb(255,255,255),3 );


        }



        al_flip_display();


		}
		al_rest(3);

		al_destroy_display(dis);

}
