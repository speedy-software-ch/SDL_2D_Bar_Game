
void pic_construct(void)
{
		personrect.x=PersonPlaceX;
        personlabelrect.x=randomnr*250+50;  
        SDL_BlitSurface(Background, NULL, screen, 0);
        SDL_SetColorKey(Moni, SDL_SRCCOLORKEY, SDL_MapRGB(Moni->format, 255, 0, 0));
        SDL_BlitSurface(Moni,NULL,screen,&monirect);
        SDL_SetColorKey(Person, SDL_SRCCOLORKEY, 
                           SDL_MapRGB(Person->format, 0, 0 , 255));
        SDL_BlitSurface(Person,NULL,screen,&personrect);
        SDL_SetColorKey(Christian, SDL_SRCCOLORKEY,
                           SDL_MapRGB(Christian->format, 0, 0 , 255));
        SDL_BlitSurface(Christian,NULL,screen,&personlabelrect);

return;
}