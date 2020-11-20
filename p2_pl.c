#include "p2_ass.h"
#include "p2_linked_list.h"
pl *Initialize( )
{
    pl *head;
    head = ( pl * ) calloc( 1, sizeof( pl ) );
    if ( head == NULL )
    {
        fprintf( stderr, "Failed to assign memory!\n" );
        exit( -1 );
    }
    head->next          = NULL;
    head->previous      = NULL;
    head->info.num_card = 0;
    return head;
}
void FreeList( pl **head )
{
    pl *tmp   = NULL;
    pl *pHead = *head;
    while ( pHead->next != NULL )
    {
        tmp   = pHead;
        pHead = pHead->next;
        free( tmp );
    }
    free( pHead );
}
bool IsEmptyList( pl *head )
{
    if ( ( head != NULL ) && ( ( head )->info.num_card!=0 )) return false;
    return true;
}
void InsertFirstList( pl **head )
{
    if ( IsEmptyList( *head ) == true )
    {
        ( *head )->info.num_card = 0;
        return;
    }
    pl *temp;
    temp                 = ( pl * ) calloc( 1, sizeof( pl ) );
    temp->next           = ( *head );
    temp->info.num_card  = 0;
    temp->previous       = ( *head )->previous;
    temp->previous->next = temp;
    temp->next->previous = temp;
    *head                = temp;
    return;
}
/*
int SizeList( pl *head )
{
    if ( IsEmptyList( head ) == true ) return 0;
    int ans  = 1;
    pl *temp = head;
    while ( ( temp->next ) != NULL )
    {
        temp = temp->next;
        ans++;
        if (temp==next) break;
    }
    return ans;
}

int SearchList( pl **head, char target )
{
    int ans  = 0;
    pl *temp = *head;
    if ( IsEmptyList( *head ) == true ) return ans;
    if ( ( *head )->ch == target ) ans++;
    while ( ( temp->next ) != NULL )
    {
        temp = temp->next;
        if ( temp->ch == target ) ans++;
    }
    return ans;
}
*/