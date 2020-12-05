#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
node_t *Initialize( char ch )
{
    node_t *head;
    head = ( node_t * ) calloc( 1, sizeof( node_t ) );
    if ( head == NULL )
    {
        fprintf( stderr, "Failed to assign memory!\n" );
        exit( -1 );
    }
    head->next = NULL;
    head->ch   = ch;
    return head;
}
void PrintList( node_t *head )
{
    node_t *temp = head;
    printf( "***Print Linked List***\n" );
    while ( temp != NULL )
    {
        printf( "%c ", temp->ch );
        temp = temp->next;
    }
    printf( "\n****Print Finished****\n\n" );
}
void FreeList( node_t **head )
{
    node_t *tmp   = NULL;
    node_t *pHead = *head;
    while ( pHead->next != NULL )
    {
        tmp   = pHead;
        pHead = pHead->next;
        free( tmp );
    }
    free( pHead );
}
bool IsEmptyList( node_t *head )
{
    if ( ( head != NULL ) && ( ( head )->ch != ' ' ) ) return false;
    return true;
}
void InsertFirstList( node_t **head, char insert_char )
{
    if ( IsEmptyList( *head ) == true )
    {
        ( *head )->ch = insert_char;
        return;
    }
    node_t *temp;
    temp       = ( node_t * ) calloc( 1, sizeof( node_t ) );
    temp->next = ( *head );
    temp->ch   = insert_char;
    *head      = temp;
    return;
}
void InsertLastList( node_t **head, char insert_char )
{
    if ( IsEmptyList( *head ) == true )
    {
        ( *head )->ch = insert_char;
        return;
    }
    node_t *temp = *head;
    while ( ( temp->next ) != NULL ) { temp = temp->next; }
    node_t *new    = ( node_t * ) calloc( 1, sizeof( node_t ) );
    new->ch        = insert_char;
    new->next      = NULL;
    ( temp->next ) = new;
    return;
}
void DeleteFirstList( node_t **head )
{
    if ( SizeList( *head ) == 1 )
    {
        ( *head )->ch = ' ';
        return;
    }
    node_t *temp = *head;
    *head        = ( *head )->next;
    free( temp );
    return;
}
void DeleteLastList( node_t **head )
{
    if ( SizeList( *head ) == 1 )
    {
        ( *head )->ch = ' ';
        return;
    }
    node_t *temp = *head;
    while ( ( ( ( temp->next ) != NULL ) ) && ( ( temp->next->next ) != NULL ) ) { temp = temp->next; }
    free( temp->next );
    temp->next = NULL;
    return;
}
int SizeList( node_t *head )
{
    if ( IsEmptyList( head ) == true ) return 0;
    int     ans  = 1;
    node_t *temp = head;
    while ( ( temp->next ) != NULL )
    {
        temp = temp->next;
        ans++;
    }
    return ans;
}
int SearchList( node_t **head, char target )
{
    int     ans  = 0;
    node_t *temp = *head;
    if ( IsEmptyList( *head ) == true ) return ans;
    if ( ( *head )->ch == target ) ans++;
    while ( ( temp->next ) != NULL )
    {
        temp = temp->next;
        if ( temp->ch == target ) ans++;
    }
    return ans;
}
void SplitList( node_t **head, node_t **tail, int pos )
{
    if ( pos == 0 )
    {
        if ( *tail == NULL ) *tail = Initialize( ' ' );
        ( *tail )->ch   = ( *head )->ch;
        ( *tail )->next = ( *head )->next;
        ( *head )->ch   = ' ';
        ( *head )->next = NULL;
        return;
    }
    int     ans  = 0;
    node_t *temp = *head;
    if ( temp == NULL ) { return; }
    if ( pos == 1 )
    {
        if ( ( ( temp ) != NULL ) )
        {
            ( *tail )  = ( temp->next );
            temp->next = NULL;
        }
        else
        {
            *tail = Initialize( ' ' );
        }
        return;
    }
    while ( ( temp->next ) != NULL )
    {

        temp = temp->next;
        ans++;
        if ( ans == pos - 1 ) { break; }
    }
    if ( ( ( temp ) != NULL ) )
    {
        ( *tail )  = ( temp->next );
        temp->next = NULL;
    }
    else
    {
        *tail = Initialize( ' ' );
    }
    return;
}
void MergeList( node_t **head1, node_t **head2 )
{

    if ( IsEmptyList( *head1 ) == true )
    {
        if ( IsEmptyList( *head2 ) == true )
        {
            free( *head2 );
            ( *head1 )->ch   = ' ';
            ( *head1 )->next = NULL;
            *head2           = NULL;
            return;
        }
        else
        {
            free( *head1 );
            *head1 = *head2;
            *head2 = NULL;
            return;
        }
    }
    if ( IsEmptyList( *head2 ) == true )
    {
        {
            *head2 = NULL;
            return;
        }
    }
    node_t *temp = *head1;
    while ( temp->next != NULL ) { temp = temp->next; }
    temp->next = *head2;
    *head2     = NULL;
    return;
}
