#include "devices.h"
device::device()
{
    this->x = x;
    times   = 0;
    std::cout << "Input 10 integers: " << std::endl;
    srand( time( 0 ) );
    for ( int i = 0; i < 10; i++ ) { std::cin >> input [ i ]; }
    start( );

    result( );
    return;
}
void device::result( )
{
    std::cout << "Result:" << std::endl;
    if ( 10 - times >= 2 ) std::cout << "0: " << 10 - times << " times in total" << std::endl;
    else
        std::cout << "0: " << 10 - times << " time in total" << std::endl;
    if ( times >= 2 ) std::cout << "1: " << times << " times in total" << std::endl;
    else
        std::cout << "1: " << times << " time in total" << std::endl;
    if ( times >= 6 ) std::cout << "The device is infected, immediate destruction required!" << std::endl;
    else
        std::cout << "The device is not infected, keep it safe!" << std::endl;
    return;
}
void American::start( )
{
    for ( int i = 1; i <= 10; i++ )
    {
        std::cout << "* Round " << i << " (x = " << input [ i - 1 ] << std::endl;
        switch ( rand( ) % 4 )
        {
            case 0:
            {
                A( );
                break;
            }
            case 1:
            {
                B( );
                break;
            }
            case 2:
            {
                C( );
                break;
            }
            case 3:
            {
                D( );
                break;
            }
        }
    }
    return;
}
void Australian::start( )
{
    for ( int i = 1; i <= 10; i++ )
    {
        std::cout << "* Round " << i << " (x = " << input [ i - 1 ] << std::endl;
        switch ( rand( ) % 4 )
        {
            case 0:
            {
                A( );
                break;
            }
            case 1:
            {
                B( );
                break;
            }
            case 2:
            {
                C( );
                break;
            }
            case 3:
            {
                D( );
                break;
            }
        }
    }
    return;
}
void Asian::start( )
{
    for ( int i = 1; i <= 10; i++ )
    {
        std::cout << "* Round " << i << " (x = " << input [ i - 1 ] << std::endl;
        switch ( rand( ) % 4 )
        {
            case 0:
            {
                A( );
                break;
            }
            case 1:
            {
                B( );
                break;
            }
            case 2:
            {
                C( );
                break;
            }
            case 3:
            {
                D( );
                break;
            }
        }
    }
    return;
}
void European::start( )
{
    for ( int i = 1; i <= 10; i++ )
    {
        std::cout << "* Round " << i << " (x = " << input [ i - 1 ] << std::endl;
        switch ( rand( ) % 4 )
        {
            case 0:
            {
                A( );
                break;
            }
            case 1:
            {
                B( );
                break;
            }
            case 2:
            {
                C( );
                break;
            }
            case 3:
            {
                D( );
                break;
            }
        }
    }
    return;
}