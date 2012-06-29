#ifndef OBJECT_H
#define OBJECT_H

struct Geometry
{
    int x;
    int y;
};

class Object
{
    protected:
        Geometry* pos; // stores the position of the object
        bool state;    // stores whether the object needs to be removed
        int type;      // stores what components it has
        int active;    // stores what components are active
    public:
        Object();
        virtual ~Object();

        Geometry*   getPos()    {return pos;}
        bool        getState()  {return state;}
        int         getType()   {return type;}
        int         getActive() {return active;}

        virtual void toggleActive(bool act) = 0;
};

#endif
