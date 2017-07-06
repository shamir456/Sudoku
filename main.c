#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_native_dialog.h>
#include <allegro5\allegro_primitives.h>
//#include "easy.txt"
//#include "medium.txt"
//#include "hard.txt"

void loadingscreen(ALLEGRO_DISPLAY *display);
int maintext(ALLEGRO_DISPLAY *display);
int levelselection( ALLEGRO_DISPLAY *display);
void helppage(ALLEGRO_DISPLAY *display);

int main()
{

    ALLEGRO_DISPLAY *display = NULL;
    bool window=false;

    al_init();   //Allegro initialization
    al_init_image_addon();  //Image addon initialization
    al_init_font_addon(); // Font initialization
    al_init_ttf_addon();    //TTF initialization
    al_install_mouse(); //Mouse initialization
    al_init_primitives_addon(); //ALLEGRO primitives initialization

    if(!al_init())  //Shows a dialog box incase if ALLEGRO doesn't initializes
    {
        al_show_native_message_box(display,"Oops!!","ERROR!","Failed to Initialize Allegro!",NULL,ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }
    display=al_create_display(640,480); // Creates a display window
    if(!display) // Shows a dialog box incase if window doesn't initializes
    {
        al_show_native_message_box(display,"Oops!!","ERROR!","Failed to Build Display",NULL,ALLEGRO_MESSAGEBOX_ERROR);
    }


    loadingscreen(display); //Function calling for Loading Screen
    while(window == false)  //While loop so that it can work continuously until user works with any events
    {
        int choice= maintext(display);      //Choice variable to store a choice that user chooses in the main menu

        switch(choice)  //Switch statement that works according to user choice
        {
        case 1:
        {
            int levelchoice= levelselection(display);   //Stores user choice for level selection
            switch(levelchoice)
            {
            case 1:
            {
                easy();     //Loads the easy Sudoku board
                break;
            }
            case 2:
            {
                medium();      //Loads the medium Sudoku Board
                break;
            }
            case 3:
            {
                hard(); //Loads the hard Sudoku board
                break;
            }
            }
            break;
        }

        case 2:
        {
            display=al_create_display(600,400); //Creates a display for help page
            helppage(display);  // Displays help page
            break;
        }
        case 3:
        {
            window=true;    //changes window to true to stop the while loop
            break;
        }
        default:
        {
            window=true;    //Default condition
            break;
        }
        }
    }
    return 0;
}

void loadingscreen(ALLEGRO_DISPLAY *display)
{
    ALLEGRO_BITMAP *loading=NULL;   //Initialization
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

    int playx=150;
    int playy=150;
    int helpx=150;
    int helpy=250;
    int exitx=150;
    int exity=350;

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
    al_draw_bitmap(play,playx,playy,0);
    al_draw_bitmap(help,helpx,helpy,0);
    al_draw_bitmap(exit,exitx,exity,0);
    al_flip_display();

    while(check == false)
    {
        al_wait_for_event(queue,&events);
        if( events.type == ALLEGRO_EVENT_MOUSE_AXES)
        {
            if ((events.mouse.x >= playx) && (events.mouse.x <= playx+152) && (events.mouse.y >= playy) && (events.mouse.y <= playy+84))
            {
                mousebuttonplay=true;
            }
            else if ((events.mouse.x >= helpx) && (events.mouse.x <= helpx+152) && (events.mouse.y >=helpy) && (events.mouse.y <=helpy+84))
            {
                mousebuttonhelp=true;
            }
            else if ((events.mouse.x >= exitx) && (events.mouse.x <= exitx+152) && (events.mouse.y >=exity) && (events.mouse.y <=exity+84))
            {
                mousebuttonexit=true;
            }
            else
            {
                mousebuttonplay=false;
                mousebuttonhelp=false;
                mousebuttonexit=false;
            }
        }
        if(events.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
        {
            if(mousebuttonplay==true)
            {
                al_destroy_display(display);
                return 1;
            }
            else if(mousebuttonhelp==true)
            {
                return 2;
            }
            else if(mousebuttonexit==true)
            {
                return 3;
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

    int easyx=240;
    int easyy=150;
    int mediumx=240;
    int mediumy=250;
    int hardx=240;
    int hardy=350;

    ALLEGRO_BITMAP *easy=NULL;
    ALLEGRO_BITMAP *medium=NULL;
    ALLEGRO_BITMAP *hard=NULL;
    ALLEGRO_BITMAP *title=NULL;

    ALLEGRO_EVENT_QUEUE *queue;
    ALLEGRO_EVENT events;

    easy=al_load_bitmap("easy.png");
    medium=al_load_bitmap("medium.png");
    hard=al_load_bitmap("hard.png");
    title=al_load_bitmap("levelselect.png");

    al_draw_bitmap(title,250,10,0);
    al_draw_bitmap(easy,easyx,easyy,0);
    al_draw_bitmap(medium,mediumx,mediumy,0);
    al_draw_bitmap(hard,hardx,hardy,0);

    queue=al_create_event_queue();
    al_register_event_source(queue,al_get_display_event_source(display));
    al_register_event_source(queue,al_get_mouse_event_source());

    al_flip_display();

    while(check== false)
    {
        al_wait_for_event(queue,&events);

        if( events.type == ALLEGRO_EVENT_MOUSE_AXES)
        {
            if((events.mouse.x>=easyx) && (events.mouse.x<=easyx+152) && (events.mouse.y >=easyy) && (events.mouse.y <= easyy+84))
            {
                easybutton=true;
            }
            else if ((events.mouse.x>= mediumx) && (events.mouse.x <= mediumx+152) && (events.mouse.y>=mediumy) && (events.mouse.y<=mediumy+84))
            {
                mediumbutton=true;
            }
            else if ((events.mouse.x>= hardx) && (events.mouse.x <= hardx+152) && (events.mouse.y >=hardy) && (events.mouse.y<=hardy+84))
            {
                hardbutton=true;
            }
            else
            {
                easybutton=false;
                mediumbutton=false;
                hardbutton=false;
            }
        }
        if(events.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
        {
            if(easybutton==true)
            {
                al_destroy_display(display);
                return 1;
            }
            else if(mediumbutton==true)
            {
                al_destroy_display(display);
                return 2;
            }
            else if(hardbutton==true)
            {
                al_destroy_display(display);
                return 3;
            }
        }
        if(events.type== ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            check=true;
        }
    }
    return 0;
}
void helppage(ALLEGRO_DISPLAY *display)
{

    ALLEGRO_BITMAP *helptitle=NULL;
    ALLEGRO_BITMAP *rules=NULL;
    ALLEGRO_EVENT_QUEUE *queue;
    ALLEGRO_EVENT events;
    bool check=false;
    queue=al_create_event_queue();
    al_register_event_source(queue,al_get_display_event_source(display));

    rules=al_load_bitmap("rules.png");
    helptitle=al_load_bitmap("help.png");
    al_draw_bitmap(helptitle,200,10,0);
    al_draw_bitmap(rules,20,100,0);
    al_flip_display();


    while(check==false)
    {
        al_wait_for_event(queue,&events);

        if(events.type== ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            check=true;
            al_destroy_display(display);
            break;
        }
    }

}
