#ifndef PREY_H_INCLUDED
#define PREY_H_INCLUDED
class Prey:public Creature
{
protected:
//   int countprey;
    BITMAP* imag;
    char c;
public:
    char getchar()
    {
        return c;
    }
    virtual void putxy(GameSystem &g,int x,int y){}
    virtual void moveRand(GameSystem &g){};
    BITMAP* getimag()
    {
        return imag;
    }

};



#endif // PREY_H_INCLUDED
