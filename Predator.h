#ifndef PREDATOR_H_INCLUDED
#define PREDATOR_H_INCLUDED

class Predator:public Creature
{
protected:
    SAMPLE *EAT ;
public:
    Predator()
    {
        EAT= load_sample("EAT.wav");
    }
    void alive(GameSystem &g,char c)
    {
        if (moveCounter%12==0&&moveCounter!=0)
        {
            allegro_message("Predator Died\n");
            blit(bg,screen,x,y,x,y,50,50);
            g.set(x/50,y/50,'f');
            dead=1;
            moveCounter=0;
        }
    }

    void resetCounter()
    {
        moveCounter=0;
    }


    void eat(Prey &b,GameSystem &g)
    {
        if (!b.getdead())
        {
            if (IsCollision(RegionCoordinates(), b.RegionCoordinates()))
            {
                b.setdead(1);
                g.updatescore();
                g.set(x/50,y/50,'f');
                resetCounter();
                play_sample(EAT, 255, 128,1000, 0);
            }
            else
            {
                b.moveRand(g);
                b.show();
                /*   if(b.getcounter2()%12==0&&b.getcounter2()!=0)
                   {
                   Prey *p = new Prey;
                   p->putxy(g,p->getx(),p->gety());
                   p->moveRand(g);
                   p->show();
                   }*/
            }
        }
    }

};

#endif // PREDATOR_H_INCLUDED
