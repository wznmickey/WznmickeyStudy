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
    Color( double r, double g, double b )
    {
        this->red   = ( float ) r;
        this->green = ( float ) g;
        this->blue  = ( float ) b;
        this->alpha = ( float ) 1;
        return;
    }
    Color( double r, double g, double b, double a )
    {
        this->red   = ( float ) r;
        this->green = ( float ) g;
        this->blue  = ( float ) b;
        this->alpha = ( float ) a;
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