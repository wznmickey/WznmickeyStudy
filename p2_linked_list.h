#include "p2_ass.h"
#ifndef LINKED_LIST
#define LINKED_LIST
typedef struct player_list
{
    splayer      info;
    struct player_list *next;
    struct player_list *previous;
} pl; // player list
pl * Initialize();
void FreeList( pl **head );
bool IsEmptyList( pl *head );                        // Return true if the list is empty, false otherwise
void InsertFirstList( pl **head ); // Prepend a node
int  SizeList( pl *head );                           // Return the size of the list
int  SearchList( pl **head, char target );           // Count how many times target appears
#endif
