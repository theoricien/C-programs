#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <windows.h>

char *get_nth_line (FILE *file, int n)
{
    char line[1024];
    int curr_line = 0;
    while (fgets(line,1024,file) != NULL)
    {
        strtok(line,"\n");
        if (curr_line == n)
        {
            char *l = line;
            return l;
        }
        else
            curr_line++;
    }
    return NULL;
}


int main (int argc, char** argv)
{
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    FILE *file = fopen("text","r");
    SDL_Color police_color = {255, 255, 255};
    unsigned int i = 0;
    unsigned int my_bool = 0;

    SDL_Surface* screen = SDL_SetVideoMode(1280,720, 16, SDL_HWSURFACE|SDL_DOUBLEBUF);
    TTF_Font *police = TTF_OpenFont("verdana.ttf", 48);
    TTF_SetFontStyle(police, TTF_STYLE_BOLD);
    SDL_Surface *text = NULL;

    SDL_Rect dstrect;
    while (!my_bool)
    {
        char *line = get_nth_line(file,i);
        fseek(file, 0, SEEK_SET);
        text = TTF_RenderText_Blended(police, line, police_color);
        dstrect.x = (screen->w - text->w) / 2;
        dstrect.y = (screen->h - text->h) / 2;
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                    my_bool = 1;
                    break;
                case SDL_KEYDOWN:
                    if (event.key.keysym.sym == SDLK_ESCAPE)
                    {
                        my_bool = 1;
                        break;
                    }
                    if (event.key.keysym.sym == SDLK_SPACE)
                    {
                        i++;
                        break;
                    }
            }
        }

        SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 0, 0, 0));
        SDL_BlitSurface(text, 0, screen, &dstrect);
        SDL_Flip(screen);
        Sleep(1000/30);
    }
    TTF_CloseFont(police);
    SDL_FreeSurface(text);
    TTF_Quit();
    return 0;
}
