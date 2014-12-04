#ifndef PREDATORS_H_INCLUDED
#define PREDATORS_H_INCLUDED
class Scorpion:public Predator
{
private:
    BITMAP *imag;
    char X;
public:
    Scorpion()
    {
        imag= load_bitmap("scorp.bmp",NULL);
        X='X';
    }
    void putrand(GameSystem &g)
    {
        x = generate_x();
        y = generate_y();
        if (check(g,x/50,y/50,'X')&&y>50&&x>50&&y<500&&x<700)
        {
            g.set(x/50,y/50,'X');
        }
        else
        {
            putrand(g);
        }
    }
    void putxy(GameSystem &g,int x,int y)
    {
        if (check(g,x/50,y/50,'X')&&y>50&&x>50&&y<500&&x<700)
        {
            g.set(x/50,y/50,'X');
        }
        else
        {
            putrand(g);
        }
    }
    void movep(GameSystem &g)
    {
        clear_keybuf();
        tempx=x;
        tempy=y;
        blit(bg,buffer,x,y,x,y,50,50);
        readkey();
        if (key[KEY_UP]&&y>50)
        {
            y-=50;
            moveCounter++;
       //     moveCounter2++;
        }
        else if (key[KEY_DOWN]&&y<500)
        {
            y+=50;    //y+50<550
            moveCounter++;
         //   moveCounter2++;
        }

        else if (key[KEY_RIGHT]&&x<700)
        {
            x+=50;    //x+50<750
            moveCounter++;
        //    moveCounter2++;
        }

        else if (key[KEY_LEFT]&&x>50)
        {
            x-=50;
            moveCounter++;
         //   moveCounter2++;
        }
        rest(50);
        if (check(g,x/50,y/50,X))
        {
            g.set(tempx/50,tempy/50,'f');
            g.set(x/50,y/50,'X');
            masked_blit(imag ,buffer , 0, 0,x,y,50,50);
        }
        else
        {
            x=tempx;
            y=tempy;
            masked_blit(imag ,buffer , 0, 0,x,y,50,50);
        }
    }
    void moveRand(GameSystem &g)
    {
        tempx=x;
        tempy=y;
        blit(bg,buffer,x,y,x,y,50,50);
        int random=generate_random();
        if (random==1&&y>50)
        {
            y-=50;
            moveCounter++;
         //   moveCounter2++;
        }

        else if (random==2&&y<500)
        {
            y+=50;    //y+50<550
            moveCounter++;
          //  moveCounter2++;
        }

        else if (random==3&&x<700)
        {
            x+=50;    //x+50<750
            moveCounter++;
         //   moveCounter2++;
        }

        else if (random==4&&x>50)
        {
            x-=50;
            moveCounter++;
          //  moveCounter2++;
        }

        rest(80);
        if (check(g,x/50,y/50,X))
        {
            g.set(tempx/50,tempy/50,'f');
            g.set(x/50,y/50,'X');
            masked_blit(imag ,buffer , 0, 0,x,y,50,50);
        }
        else
        {
            x=tempx;
            y=tempy;
            masked_blit(imag ,buffer , 0, 0,tempx,tempy,50,50);
        }


    }


   /* Scorpion* Breed(GameSystem& g)
    {
        tempx=x;
        tempy=y;
        int random=generate_random();
        if (random==1&&y>50)
        {
            y-=50;
        }

        else if (random==2&&y<500)
        {
            y+=50;    //y+50<550
        }

        else if (random==3&&x<700)
        {
            x+=50;    //x+50<750
        }

        else if (random==4&&x>50)
        {
            x-=50;
        }
        if (check(g,x/50,y/50,X))
        {
            if (moveCounter2%5==0&&moveCounter2!=0)
            {
                Scorpion *p = new Scorpion;
                p->putxy(g,x,y);
                return p;
            }
        }
        else
        {
            x=tempx;
            y=tempy;
            masked_blit(imag ,buffer , 0, 0,tempx,tempy,50,50);
        }
    }*/


    BITMAP* getimag()
    {
        return imag;
    }
    ~Scorpion()
    {
        destroy_bitmap(imag);
    }
};
class Snake:public Predator
{
private:
    BITMAP *imag;
    char S;
public:
    Snake()
    {
        imag= load_bitmap("snake.bmp",NULL);
        S='S';
    }
    void putxy(GameSystem &g,int x,int y)
    {
        if (check(g,x/50,y/50,'S')&&y>50&&x>50&&y<500&&x<700)
        {
            g.set(x/50,y/50,'S');
        }
        else
        {
            putrand(g);
        }
    }
    void putrand(GameSystem &g)
    {
        x = generate_x();
        y = generate_y();
        if (check(g,x/50,y/50,S)&&y>50&&x>50&&y<500&&x<700)
        {
            g.set(x/50,y/50,'S');
        }
        else
        {
            putrand(g);
        }
    }
    void movep(GameSystem &g)
    {
        clear_keybuf();
        tempx=x;
        tempy=y;
        blit(bg,buffer,x,y,x,y,50,50);
        readkey();
        if (key[KEY_UP]&&y>50)
        {
            y-=50;
            moveCounter++;
         //  moveCounter2++;
        }
        else if (key[KEY_DOWN]&&y<500)
        {
            y+=50;    //y+50<550
            moveCounter++;
          //  moveCounter2++;
        }

        else if (key[KEY_RIGHT]&&x<700)
        {
            x+=50;    //x+50<750
            moveCounter++;
          //  moveCounter2++;
        }

        else if (key[KEY_LEFT]&&x>50)
        {
            x-=50;
            moveCounter++;
     //       moveCounter2++;
        }
        rest(50);
        if (check(g,x/50,y/50,S))
        {
            g.set(tempx/50,tempy/50,'f');
            g.set(x/50,y/50,'S');
            masked_blit(imag ,buffer , 0, 0,x,y,50,50);
        }
        else
        {
            x=tempx;
            y=tempy;
            masked_blit(imag ,buffer , 0, 0,x,y,50,50);
        }
    }

    void moveRand(GameSystem &g)
    {
        tempx=x;
        tempy=y;
        blit(bg,buffer,x,y,x,y,50,50);
        int random=generate_random();
        if (random==1&&y>50)
        {
            y-=50;
            moveCounter++;
         //   moveCounter2++;
        }

        else if (random==2&&y<500)
        {
            y+=50;    //y+50<550
            moveCounter++;
         //   moveCounter2++;
        }

        else if (random==3&&x<700)
        {
            x+=50;    //x+50<750
            moveCounter++;
          //  moveCounter2++;
        }

        else if (random==4&&x>50)
        {
            x-=50;
            moveCounter++;
          //  moveCounter2++;
        }

        rest(80);
        if (check(g,x/50,y/50,S))
        {
            g.set(tempx/50,tempy/50,'f');
            g.set(x/50,y/50,'S');
            masked_blit(imag ,buffer , 0, 0,x,y,50,50);
        }
        else
        {
            x=tempx;
            y=tempy;
            masked_blit(imag ,buffer , 0, 0,tempx,tempy,50,50);
        }


    }

    /* void Breed(GameSystem& g)
     {
         tempx=x;
         tempy=y;
         if (generate_random()==1&&y>50)
         {
             y-=50;
         }

         else if (generate_random()==2&&y<500)
         {
             y+=50;    //y+50<550
         }

         else if (generate_random()==3&&x<700)
         {
             x+=50;    //x+50<750
         }

         else if (generate_random()==4&&x>50)
         {
             x-=50;
         }
         if (check(g,x,y,'S'))
         {
             //creat new object.....please
             //delete_coordinates(g,tempx,tempy,c);
             //g.setx(x);
             //g.sety(y);
             //masked_blit(imag ,buffer , 0, 0,x,y,50,50);
         }
         else
         {
             x=tempx;
             y=tempy;
             masked_blit(imag ,buffer , 0, 0,tempx,tempy,50,50);
         }

     }*/

    BITMAP* getimag()
    {
        return imag;
    }
    ~Snake()
    {
        destroy_bitmap(imag);
    }
};


#endif // PREDATORS_H_INCLUDED
