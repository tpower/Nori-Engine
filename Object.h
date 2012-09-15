#ifndef OBJECT_H
#define OBJECT_H

#include <SDL/SDL.h>

struct vect
{
    double x;
    double y;
};

class Object
{
    protected:

        vect pos;      // stores the position of the object
        bool state;    // stores whether the object needs to be removed
        int type;      // stores what components it has
        int active;    // stores what components are active
    public:
        Object();
        virtual ~Object();

        vect           getPos()    {return pos;}
        bool           getState()  {return state;}
        int            getType()   {return type;}
        int            getActive() {return active;}

        void           setPos(int, int);

        virtual void toggleActive(bool act) = 0;
};

#endif
