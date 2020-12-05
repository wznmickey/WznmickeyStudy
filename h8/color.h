/***********************************
    Written by WANGZINING
    blog: https://wznmickey.com
***********************************/
#ifndef COLOR_mickey_H
#define COLOR_mickey_H

class Color
{
public:
    Color( )
    {
        this->red   = 0;
        this->green = 0;
        this->blue  = 0;
        this->alpha = 1;
        return;
    }
    ~Color( )
    {
        return;
    }
    Color( float r, float g, float b )
    {
        this->red   = r;
        this->green = g;
        this->blue  = b;
        this->alpha = 1;
        return;
    }
    Color( float r, float g, float b, float a )
    {
        this->red   = r;
        this->green = g;
        this->blue  = b;
        this->alpha = a;
        return;
    }
    float getr( )
    {
        return red;
    }
    float getg( )
    {
        return green;
    }
    float getb( )
    {
        return blue;
    }
    float geta( )
    {
        return alpha;
    }
    void changer( float r )
    {
        this->red = r;
        return;
    }
    void changeg( float g )
    {
        this->green = g;
        return;
    }
    void changeb( float b )
    {
        this->blue = b;
        return;
    }
    void changea( float a )
    {
        this->alpha = a;
        return;
    }
    void set( );

private:
    float red, green, blue, alpha;
};
#endif