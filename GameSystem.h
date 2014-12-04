#ifndef GAMESYSTEM_H_INCLUDED
#define GAMESYSTEM_H_INCLUDED
#include <iostream>
using namespace std;

class GameSystem
{
private:
    int score;
    int turn;
    SAMPLE *Song;
    char map[14][9];
public:
    void set
    (int x,int y,char c)
    {
        map[x][y]=c;
    }
    char get(int indexx,int indexy)
    {
        return map[indexx][indexy];
    }

    GameSystem()
    {
        allegro_init();
        install_keyboard();
        set_color_depth(24);
        set_gfx_mode( GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0);
        install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, 0);
        srand(time(NULL));
        menuinit();
        Song = load_sample("BGM.wav");
        play_sample(Song, 50, 128,1000, true);
        turn=0;
        score=0;
        for (int i=0;i<9;i++)
        {
            for (int j=0;j<14;j++)
            {
                set(i,j,'f');
            }
        }

    }
    void menuinit()
    {
        BITMAP *menu = load_bitmap("menu.bmp",NULL);
        stretch_blit(menu, screen, 0, 0, 800, 600,0, 0, SCREEN_W, SCREEN_H);
        int x=readkey();
        destroy_bitmap(menu);
        if (x==9777||x==7217)
        {
            bginit();
        }
        else if (x==10034||x==7474)
        {
           aboutit();
        }
        else if (x==10291||x==7731)
        {
            exit(0);
        }
        else menuinit();
    }
    void aboutit()
    {
        BITMAP *about = load_bitmap("about.bmp",NULL);
        stretch_blit(about, screen, 0, 0, 800, 600,0, 0, SCREEN_W, SCREEN_H);
        int x=readkey();
        destroy_bitmap(about);
        if (x==610||x==578)
        {
         menuinit();
        }
        else aboutit();
    }
    void bginit()
    {
        BITMAP *bg = load_bitmap("grass4.bmp",NULL);
        stretch_blit(bg, screen, 0, 0, 800, 600,0, 0, SCREEN_W, SCREEN_H);
        rectfill( screen, 0, 0, 800, 30, makecol( 0, 0, 0));
        destroy_bitmap(bg);
    }
    void showscore()
    {
        textprintf_ex(screen, font,10, 10, makecol(255, 100, 200),
                      1, "Score: %i", score);
    }
    void updatescore()
    {
        score++;
    }
    void showturn()
    {
        textprintf_ex(screen, font,300, 10, makecol(255, 100, 200),
                      1, "Turn: %i", turn);
    }
    void updateturn()
    {
        turn++;
    }
    int choose()
    {
        BITMAP *bg = load_bitmap("grass4.bmp",NULL);
        BITMAP *scorp = load_bitmap("scorp.bmp",NULL);
        BITMAP *snake = load_bitmap("snake.bmp",NULL);
        textout_ex(screen,font,"Choose Your Predator",300,200,makecol(255,0,0),makecol(-1,-1,-1));
        textout_ex(screen,font,"1-",350,300,makecol(255,0,0),makecol(-1,-1,-1));
        masked_blit(snake ,screen , 0, 0,375,275,50,50);
        textout_ex(screen,font,"2-",350,375,makecol(255,0,0),makecol(-1,-1,-1));
        masked_blit(scorp ,screen , 0, 0,375,350,50,50);
        int x=readkey();
        if (x==9777||x==7217)
        {
            blit(bg,screen,300,200,300,200,160,250);
            destroy_bitmap(bg);
            destroy_bitmap(scorp);
            destroy_bitmap(snake);
            return 1;
        }
        else if (x==10034||x==7474)
        {
            blit(bg,screen,300,200,300,200,160,250);
            destroy_bitmap(bg);
            destroy_bitmap(scorp);
            destroy_bitmap(snake);
            return 2;
        }
        else if (key[KEY_ESC])
        {
            exit(0);
        }
        else
        {
            allegro_message("Please Choose Your Predator\n");
            return choose();
        }

    }
    void WinLose()
    {
        if (score==6)
        {
            allegro_message("You Win !!!\n");
            exit(0);
        }
        else if (turn==50)
        {
            allegro_message("Game Over!!!\n");
            exit(0);
        }
    }
    /*    void cheat(Predator a){
             if (key[KEY_C])
                {
                    allegro_message("Cheat Mode Activated \nPress A to reset Your Predator move counter\nPress B to add 10 points to score");
                    readkey();
                    int x=readkey();
                    if (x==353) a.resetCounter();
                    else if (x==610) score+=10;
                }

            }*/

    ~GameSystem()
    {
        allegro_exit();
    }
};

#endif // GAMESYSTEM_H_INCLUDED
