////////////////////////////// By : ////////////////////////////
//////////////Ibrahim Bassiouni Ibrahim Beltagy         #642////
//////////////Sameh Mohammed Mohammed Salama            #959////
////////////////////////////////////////////////////////////////

///////////////////Libraries Included///////////////////
#include <allegro.h>
#include "GameSystem.h"
#include "Creature.h"
#include "Prey.h"
#include "Preys.h"
#include "Predator.h"
#include "Predators.h"
////////////////////////////////////////////////////////
/*void breed(Ant a[],Scorpion &x) test
{

    for (int i=0;i<a[3].getcount();i++)
    {
        if (a[i].getcounter()%12==0&&!a[i].getdead())
        {
                Ant* p=new Ant;
                p->alive();
                  //  p->moveRand(*p);
                 //   p->
                 show();
                x.eat(*p);
        }
    }
}*/

int main()
{
    GameSystem g;
    Scorpion x;
    Snake s;
    Ant a;
    Bug b;
    Worm w;
    Ant a2;
    Bug b2;
    Worm w2;
    Ant a3;
    Bug b3;
    Worm w3;
    s.putrand(g);
    x.putrand(g);
    a.putrand(g);
    a2.putrand(g);
    a3.putrand(g);
    b.putrand(g);
    b2.putrand(g);
    b3.putrand(g);
    w.putrand(g);
    w2.putrand(g);
    w3.putrand(g);

    // Ant q[4];
    short int choice=g.choose();
    if (choice==2)
    {
        while ( !key[KEY_ESC])
        {
            g.WinLose();
            x.alive(g,'X');
            s.alive(g,'S');
            g.showscore();
            g.showturn();
            //   g.cheat(x);
            if (!x.getdead())
            {
                x.movep(g);
                x.show();
                /*  // Scorpion *p=x.Breed(g); breed
                   Scorpion *p = new Scorpion;
                   if(x.getcounter2()%24==0&&x.getcounter2()!=0){
                   {
                   p->putxy(g,p->getx(),p->gety());
                   p->alive(g,'X');*/
                //   }}

            }
            if (!s.getdead())
            {
                s.moveRand(g);
                s.show();
            }
            /*  for (int i=0;i<10;i++)
              {
                  q[i].alive();
                  x.eat(q[i]);
              }*/
            //   q[0].breed();
            // breed(q,x);
            x.eat(a,g);
            x.eat(b,g);
            x.eat(a2,g);
            x.eat(b2,g);
            x.eat(a3,g);
            x.eat(b3,g);
            s.eat(b,g);
            s.eat(w,g);
            s.eat(b2,g);
            s.eat(w2,g);
            s.eat(b3,g);
            s.eat(w3,g);
            //        g.updatescore(x);
            g.updateturn();
        }
    }
    else if (choice==1)
    {
        while ( !key[KEY_ESC])
        {
            g.WinLose();
            s.alive(g,'S');
            x.alive(g,'X');
            g.showscore();
            g.showturn();
            //     g.cheat(s);
            if (!s.getdead())
            {
                s.movep(g);
                s.show();
                /*        Snake *p = new Snake; breed
                        if(x.getcounter2()%24==0&&x.getcounter2()!=0){
                        {
                        p->putxy(g,p->getx(),p->gety());
                        p->alive(g,'X');
                        }}
                        p->moveRand(g);
                        p->show();*/
            }
            if (!x.getdead())
            {
                x.moveRand(g);
                x.show();
            }
            x.eat(a,g);
            x.eat(b,g);
            x.eat(a2,g);
            x.eat(b2,g);
            x.eat(a3,g);
            x.eat(b3,g);
            s.eat(b,g);
            s.eat(w,g);
            s.eat(b2,g);
            s.eat(w2,g);
            s.eat(b3,g);
            s.eat(w3,g);
            g.updateturn();
        }
    }
    return 0;
}
END_OF_MAIN()
