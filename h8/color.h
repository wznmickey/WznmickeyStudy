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
        this->r = 0;
        this->g = 0;
        this->b = 0;
        this->a = 0;
        return;
    }
    ~Color( )
    {
        return;
    }
    Color( float r, float g, float b )
    {
        this->r = r;
        this->g = g;
        this->b = b;
        this->a = 0;
        return;
    }
    Color( float r, float g, float b, float a )
    {
        this->r = r;
        this->g = g;
        this->b = b;
        this->a = a;
        return;
    }
    float getr( )
    {
        return r;
    }
    float getg( )
    {
        return g;
    }
    float getb( )
    {
        return b;
    }
    float geta( )
    {
        return a;
    }
    void changer( float r )
    {
        this->r = r;
        return;
    }
    void changeg( float g )
    {
        this->g = g;
        return;
    }
    void changeb( float b )
    {
        this->b = b;
        return;
    }
    void changea( float a )
    {
        this->a = a;
        return;
    }

private:
    float r, g, b, a;
};
#endif