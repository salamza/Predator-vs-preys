#ifndef CREATURE_H_INCLUDED
#define CREATURE_H_INCLUDED
#include <math.h>
struct Rectangle
{
    int x ,y, w, h;
};

class Creature
{
protected:
    int x;
    int y;
    int tempx;
    int tempy;
    int moveCounter;
    //int moveCounter2;
    int dead;
    BITMAP *buffer;
    BITMAP *bg;
//    virtual void breed()=0;
public:
    int getx()
    {
        return x;
    }
    int gety()
    {
        return y;
    }
  /*  int getcounter2()
    {
        return moveCounter2;
    }*/
    Creature()
    {
        x=0;
        y=0;
        tempx=x;
        tempy=y;
        buffer=create_bitmap(800,600);
        bg = load_bitmap("grass4.bmp",NULL);
        draw_sprite( buffer, bg, x, y);
        moveCounter=0;
       // moveCounter2=0;
        dead=0;
    }
    void setdead(int x)
    {
        dead=x;
    }
    int getdead()
    {
        return dead;
    }
    int generate_x()
    {
        return ((int)rand() % 14 + 1) * 50 ;
    }
    int generate_y()
    {
        return ((int)rand() % 10 + 1) * 50;
    }
    int generate_random()
    {
        return rand()%4+1;
    }
    bool check(GameSystem &g , int a , int b , char c )
    {

        if (c == 'A')
        {
            if ((g.get(a,b)=='W')||(g.get(a,b)=='S')||(g.get(a,b)=='X')||(g.get(a,b)=='B')||(g.get(a,b)=='A'))
            {
                return 0;
            }
            else
            {
                return 1;
            }

        }
        else  if (c == 'B')
        {
            if ((g.get(a,b)=='W')||(g.get(a,b)=='S')||(g.get(a,b)=='X')||(g.get(a,b)=='B')||(g.get(a,b)=='A'))
            {
                return 0;
            }
            else
            {
                return 1;
            }

        }
        else  if (c == 'W')
        {
            if ((g.get(a,b)=='W')||(g.get(a,b)=='S')||(g.get(a,b)=='X')||(g.get(a,b)=='B')||(g.get(a,b)=='A'))
            {
                return 0;
            }
            else
            {
                return 1;
            }

        }
        else if (c== 'X')
        {
            if ((g.get(a,b)=='W')||(g.get(a,b)=='S')||(g.get(a,b)=='X'))
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }
        else if (c == 'S')
        {
            if ((g.get(a,b)=='X')||(g.get(a,b)=='A')||(g.get(a,b)=='S'))
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }
        else
        {
            return 1 ;
        }
    }

    void show()
    {
        acquire_screen();
        blit(buffer,screen,tempx,tempy,tempx,tempy,50,50);
        blit(buffer,screen,x,y,x,y,50,50);
        release_screen();
    }

    Rectangle RegionCoordinates()
    {
        Rectangle temp;
        temp.x = 50 + x;
        temp.w = 50;
        temp.y = 50 + y;
        temp.h = 50;
        return temp;
    }
    bool IsCollision( Rectangle A, Rectangle B )
    {
        if (  A.x  < B.x + B.w  &&
                A.x + A.w  >  B.x  &&
                A.y < B.y + B.h  &&
                A.y + A.h > B.y )
        {
            return true;
        }
        return false;
    }


};

#endif // CREATURE_H_INCLUDED
