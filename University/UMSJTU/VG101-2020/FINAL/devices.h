#ifndef DEVICES_mickey_H
#define DEVICES_mickey_H
#include <bits/stdc++.h>
class device
{
public:
    device();
    ~device( )
    {
        return;
    }

protected:
    void press( char button )
    {
        std::cout << "Press button " << button << " (x = " << x << ")" << std::endl;
        return;
    }
    void dis1( )
    {
        std::cout << "Outcome: 1" << std::endl;
        times++;
        return;
    }
    void dis0( )
    {
        std::cout << "Outcome: 0" << std::endl;
        return;
    }
    virtual void start( ) = 0;
    virtual void A( )     = 0;
    virtual void B( )     = 0;
    virtual void C( )     = 0;
    void         D( )
    {
        press( 'D' );
        if ( ( x % 3 ) != 1 ) dis0( );
        else
            dis1( );
        return;
    }
    void result( );
    int  x, times, input [ 10 ];
};
class American : public device
{
private:
    void A( )
    {
        press( 'A' );
        x = ( 2 * x ) % 5;
        C( );
        return;
    }
    void B( )
    {
        press( 'B' );
        if ( x >= 10 ) A( );
        else
            D( );
        return;
    }
    void C( )
    {
        press( 'C' );
        x += 6;
        B( );
        return;
    }
    void start( );
};
class Australian : public device
{
private:
    void A( )
    {
        press( 'A' );
        x = ( 3 * x ) % 7;
        C( );
        return;
    }
    void B( )
    {
        press( 'B' );
        if ( x >= 5 ) A( );
        else
            D( );
        return;
    }
    void C( )
    {
        press( 'C' );
        x += 2;
        B( );
        return;
    }
    void start( );
};
class Asian : public device
{
private:
    void A( )
    {
        press( 'A' );
        x = ( 3 * x ) % 5;
        C( );
        return;
    }
    void B( )
    {
        press( 'B' );
        if ( x >= 8 ) A( );
        else
            D( );
        return;
    }
    void C( )
    {
        press( 'C' );
        x += 7;
        B( );
        return;
    }
    void start( );
};
class European : public device
{
private:
    void A( )
    {
        press( 'A' );
        x = x % 11;
        C( );
        return;
    }
    void B( )
    {
        press( 'B' );
        if ( x >= 7 ) A( );
        else
            D( );
        return;
    }
    void C( )
    {
        press( 'C' );
        x *= 2;
        B( );
        return;
    }
    void start( );
};
#endif