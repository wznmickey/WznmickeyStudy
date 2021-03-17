/***********************************
    Written by WANGZINING
    blog: https://wznmickey.com
***********************************/
#ifndef SHAPE_mickey_H
#define SHAPE_mickey_H

class Shape
{
public:
    ~Shape( )
    {
        return;
    }
    virtual void  move( float dx, float dy ) = 0;
    virtual void  zoom( float x )            = 0;
    virtual float area( )                    = 0;
    virtual void  draw( )                    = 0;
};

#endif