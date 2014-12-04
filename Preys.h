#ifndef PREYS_H_INCLUDED
#define PREYS_H_INCLUDED

class Ant:public Prey
{
public:
    Ant()
    {
        imag= load_bitmap("ant.bmp",NULL);
        c='A';
    }
    void putxy(GameSystem &g,int x,int y)
    {
        if (check(g,x/50,y/50,'A')&&y>50&&x>50&&y<500&&x<700)
        {
            g.set(x/50,y/50,'A');
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
        if (check(g,x,y,'A')&&y>50&&x>50&&y<500&&x<700)
        {
            g.set(x/50,y/50,'A');
        }
        else
        {
            putrand(g);
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
     //       moveCounter2++;
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
         //   moveCounter2++;
        }

        else if (random==4&&x>50)
        {
            x-=50;
            moveCounter++;
      //      moveCounter2++;
        }

        rest(80);
        if (check(g,x/50,y/50,c))
        {
            g.set(tempx/50,tempy/50,'f');
            g.set(x/50,y/50,'A');
            masked_blit(imag ,buffer , 0, 0,x,y,50,50);
        }
        else
        {
            x=tempx;
            y=tempy;
            masked_blit(imag ,buffer , 0, 0,tempx,tempy,50,50);
        }


    }
    /*void Breed(GameSystem& g)
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
        if (check(g,x/50,y/50,c))
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
    /* void breed()
    {
    for (int i=0;i<countprey;i++)
    {
     if (moveCounter%12==0&&!dead)
     {
             Ant* p=new Ant;
             alive();
             p->moveRand(*p);
             p->show();
     }
    }
    }*/
    virtual ~Ant()
    {
        destroy_bitmap(imag);
    }
};

class Worm:public Prey
{

public:
    Worm()
    {
        imag= load_bitmap("worm.bmp",NULL);
        c='W';
    }
    void putxy(GameSystem &g,int x,int y)
    {
        if (check(g,x/50,y/50,'W')&&y>50&&x>50&&y<500&&x<700)
        {
            g.set(x/50,y/50,'W');
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
        if (check(g,x/50,y/50,c)&&y>50&&x>50&&y<500&&x<700)
        {
            g.set(x/50,y/50,'W');
        }
        else
        {
            putrand(g);
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
     //       moveCounter2++;
        }

        else if (random==2&&y<500)
        {
            y+=50;    //y+50<550
            moveCounter++;
       //     moveCounter2++;
        }

        else if (random==3&&x<700)
        {
            x+=50;    //x+50<750
            moveCounter++;
       //     moveCounter2++;
        }

        else if (random==4&&x>50)
        {
            x-=50;
            moveCounter++;
         //   moveCounter2++;
        }

        rest(80);
        if (check(g,x/50,y/50,c))
        {
            g.set(tempx/50,tempy/50,'f');
            g.set(x/50,y/50,'W');
            masked_blit(imag ,buffer , 0, 0,x,y,50,50);
        }
        else
        {
            x=tempx;
            y=tempy;
            masked_blit(imag ,buffer , 0, 0,tempx,tempy,50,50);
        }


    }

    /*void Breed(GameSystem& g)
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
        if (check(g,x/50,y/50,c))
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

    virtual ~Worm()
    {
        destroy_bitmap(imag);
    }
};

class Bug:public Prey
{

public:
    Bug()
    {

        imag= load_bitmap("bug.bmp",NULL);
        c='B';
    }
    void putxy(GameSystem &g,int x,int y)
    {
        if (check(g,x/50,y/50,'B')&&y>50&&x>50&&y<500&&x<700)
        {
            g.set(x/50,y/50,'B');
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
        if (check(g,x/50,y/50,c)&&y>50&&x>50&&y<500&&x<700)
        {
            g.set(x/50,y/50,'B');
        }
        else
        {
            putrand(g);
        }
    }
    void moveRand(GameSystem &g)
    {
        tempx=x;
        tempy=y;
        blit(bg,buffer,x,y,x,y,50,50);
        if (generate_random()==1&&y>50)
        {
            y-=50;
            moveCounter++;
      //      moveCounter2++;
        }

        else if (generate_random()==2&&y<500)
        {
            y+=50;    //y+50<550
            moveCounter++;
           // moveCounter2++;
        }

        else if (generate_random()==3&&x<700)
        {
            x+=50;    //x+50<750
            moveCounter++;
          //  moveCounter2++;
        }

        else if (generate_random()==4&&x>50)
        {
            x-=50;
            moveCounter++;
        //    moveCounter2++;
        }

        rest(80);
        if (check(g,x/50,y/50,c))
        {
            g.set(tempx/50,tempy/50,'f');
            g.set(x/50,y/50,'B');
            masked_blit(imag ,buffer , 0, 0,x,y,50,50);
        }
        else
        {
            x=tempx;
            y=tempy;
            masked_blit(imag ,buffer , 0, 0,tempx,tempy,50,50);
        }


    }

    /*void Breed(GameSystem& g)
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
        if (check(g,x/50,y/50,c))
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

    virtual ~Bug()
    {
        destroy_bitmap(imag);
    }
};

#endif // PREYS_H_INCLUDED
