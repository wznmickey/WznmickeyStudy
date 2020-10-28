#ifndef P2_ASS
#define P2_ASS
#define true 1
#define false 0
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<getopt.h>

struct _card
{
	char rank[10];
	char kind[10];  
	int no;
//ordinary kinds
	_Bool spades,hearts,diamonds,clubs;
//special effects
	_Bool draw_2,draw_3,defense,queen,jack;
//player related infomation
    long long have;  // 0 means no owner
    _Bool to_have,escaped; 
// to use flexible char array	
	 
};
struct _player
{
	int no;
	long long score;
	_Bool first;
	_Bool draw;
	_Bool play;
}; 
struct _options
{
	_Bool auto_run,help;
	long long n,c,d,r;
	char filename[FILENAME_MAX+10];
};

typedef struct _card card_info;
typedef struct _player player_info;
typedef struct _options options;
struct exchange_info{
	card_info card[5];
	player_info player;
};
options get_info(int argc, char *argv[]);
options option_init();
#endif