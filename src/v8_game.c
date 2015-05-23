#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL_image.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 600
#define BPP
#define DEPTH 32



int LastRandomPersonX;
int PersonName;
int Catch=0;
int randomnr;

    SDL_Surface *screen;
    SDL_Surface *Background;
    SDL_Surface *Moni;
    SDL_Surface *Person;
    SDL_Surface *GetraenkKommt;
    SDL_Surface *GetraenkKommt2;
    SDL_Surface *Christian;
	SDL_Surface *Isai;
	SDL_Surface *Fredi;
	SDL_Surface *Moser;
    SDL_Rect getraenkkommt;
    SDL_Rect monirect;
    SDL_Rect personrect;
    SDL_Rect personlabelrect;
    SDL_Event event;

int main(int argc, char* argv[])
{
    monirect.x = 50;
    monirect.y = 225;
    personrect.x=0;
    personrect.y= 300;
    getraenkkommt.y= 0;
    personlabelrect.x=50;
    personlabelrect.y=500;
    Background= SDL_LoadBMP("Bar.bmp");
    Moni= SDL_LoadBMP("Moni.bmp");
    Person=SDL_LoadBMP("Person.bmp");
    GetraenkKommt=SDL_LoadBMP("GetränkKommt.bmp");
    GetraenkKommt2=SDL_LoadBMP("GetränkKommt2.bmp");
    Christian=SDL_LoadBMP("Christian.bmp");
	Isai=SDL_LoadBMP("Isai.bmp");
	Fredi=SDL_LoadBMP("Fredi.bmp");
	Moser=SDL_LoadBMP("Moser.bmp");
    int keypress = 0;
    if (SDL_Init(SDL_INIT_VIDEO) < 0 ) return 1;
   atexit(SDL_Quit);
    if (!(screen = SDL_SetVideoMode(WIDTH, HEIGHT, DEPTH, SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_FULLSCREEN)))
    {
        SDL_Quit();
        return 1;
    }
    SDL_ShowCursor(0);
    while(!keypress) 
    {
	if(Catch==0)
		{
		srand ( time(NULL) );
  		randomnr = rand() % 3;
		}
		else
		{
		if(monirect.x<51)
             {
                  getraenkkommt.x=monirect.x+100;
                  SDL_SetColorKey(GetraenkKommt2, SDL_SRCCOLORKEY, 
                           SDL_MapRGB(GetraenkKommt2->format, 255, 0, 0));
        SDL_BlitSurface(GetraenkKommt2,NULL,screen,&getraenkkommt);
              }
              else
              {
                  getraenkkommt.x=monirect.x-250;
                  SDL_SetColorKey(GetraenkKommt, SDL_SRCCOLORKEY, 
                           SDL_MapRGB(GetraenkKommt->format, 255, 0, 0));
        SDL_BlitSurface(GetraenkKommt,NULL,screen,&getraenkkommt);
               }
		}
        int PersonPlaceX=randomnr*250;
		personrect.x=PersonPlaceX;
        personlabelrect.x=randomnr*250+50;  
if(Catch==0)
		{
		SDL_BlitSurface(Background, NULL, screen, 0);
        SDL_SetColorKey(Moni, SDL_SRCCOLORKEY, SDL_MapRGB(Moni->format, 255, 0, 0));
        SDL_BlitSurface(Moni,NULL,screen,&monirect);
		}
        SDL_SetColorKey(Person, SDL_SRCCOLORKEY, 
                           SDL_MapRGB(Person->format, 0, 0 , 255));
        SDL_BlitSurface(Person,NULL,screen,&personrect);
        if(PersonPlaceX==LastRandomPersonX)
        {
			if(PersonName==0)
			{
			SDL_SetColorKey(Christian, SDL_SRCCOLORKEY,
                           SDL_MapRGB(Christian->format, 0, 0 , 255));
        SDL_BlitSurface(Christian,NULL,screen,&personlabelrect);
			}
			if(PersonName==1)
			{
			SDL_SetColorKey(Isai, SDL_SRCCOLORKEY,
                           SDL_MapRGB(Isai->format, 0, 0 , 255));
				SDL_BlitSurface(Isai,NULL,screen,&personlabelrect);
			}
			if(PersonName==2)
			{
				SDL_SetColorKey(Fredi, SDL_SRCCOLORKEY,
                           SDL_MapRGB(Fredi->format, 0, 0 , 255));
				SDL_BlitSurface(Fredi,NULL,screen,&personlabelrect);
			}
			if(PersonName==3)
			{
				SDL_SetColorKey(Moser, SDL_SRCCOLORKEY,
                           SDL_MapRGB(Moser->format, 0, 0 , 255));
				SDL_BlitSurface(Moser,NULL,screen,&personlabelrect);
			}
			if(PersonName==4)
			{
				SDL_SetColorKey(Christian, SDL_SRCCOLORKEY,
                           SDL_MapRGB(Christian->format, 0, 0 , 255));
				SDL_BlitSurface(Christian,NULL,screen,&personlabelrect);
			}
        }
        else
        {
        LastRandomPersonX=PersonPlaceX;
        PersonName = rand() % 4;
			if(PersonName==0)
			{
			SDL_SetColorKey(Christian, SDL_SRCCOLORKEY,
                           SDL_MapRGB(Christian->format, 0, 0 , 255));
        SDL_BlitSurface(Christian,NULL,screen,&personlabelrect);
			}
			if(PersonName==1)
			{
			SDL_SetColorKey(Christian, SDL_SRCCOLORKEY,
                           SDL_MapRGB(Christian->format, 0, 0 , 255));
				SDL_BlitSurface(Christian,NULL,screen,&personlabelrect);
			}
			if(PersonName==2)
			{
				SDL_SetColorKey(Christian, SDL_SRCCOLORKEY,
                           SDL_MapRGB(Christian->format, 0, 0 , 255));
				SDL_BlitSurface(Christian,NULL,screen,&personlabelrect);
			}
			if(PersonName==3)
			{
				SDL_SetColorKey(Christian, SDL_SRCCOLORKEY,
                           SDL_MapRGB(Christian->format, 0, 0 , 255));
				SDL_BlitSurface(Christian,NULL,screen,&personlabelrect);
			}
			if(PersonName==4)
			{
				SDL_SetColorKey(Christian, SDL_SRCCOLORKEY,
                           SDL_MapRGB(Christian->format, 0, 0 , 255));
				SDL_BlitSurface(Christian,NULL,screen,&personlabelrect);
			}
        }
         while(SDL_PollEvent(&event)) 
         {      
              switch (event.type) 
              {
                  case SDL_QUIT:
	              keypress = 1;
	              break;
                  case SDL_KEYDOWN:
                  if ( event.key.keysym.sym == SDLK_ESCAPE ) { keypress= 1; }
                  if( event.key.keysym.sym == SDLK_RIGHT &&Catch==0) {if(monirect.x<549){monirect.x=monirect.x+250;}}
                  if( event.key.keysym.sym == SDLK_LEFT && Catch==0) {if(monirect.x>50){monirect.x=monirect.x-250;}}
                  if( event.key.keysym.sym == SDLK_RETURN ) {if(randomnr==(monirect.x-50)/250){ Catch=1;}}
                       break;
              }
         }
         SDL_Flip(screen);
    }

    SDL_Quit();
  
    return 0;
}