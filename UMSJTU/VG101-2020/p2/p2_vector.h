#ifndef P2_VECTOR
#define P2_VECTOR
#include "p2_ass.h"
#define INITSETSIZE 52 // Initial memory allocated for the set
/* elem: list of elments; card: cardinal of the set; type: data type (CHAR INT or DOUBLE) */
typedef struct card_vector
{
    scard *elem;
    int    card;
} cv;
/* Initialize an empty set of given type and allocate the initial memory: INITSETSIZE*type */
void newSet( cv **set, int x);
void deletSet( cv **set );
void addElem( scard *elem, cv *set );
void remElem( scard *elem, cv *set );
int   check( scard *x, cv *set );
#endif // P2_VECTOR
