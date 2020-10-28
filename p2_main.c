#include"p2_ass.h"
int main(int argc,char *argv[])
{
    options input_option=get_info(argc,argv);
    return 0;
}
struct exchange_info play_card(player_info player,card_info card)
{
    printf("Player %d plays: %s %s",player.no,card.kind,card.rank);
    struct exchange_info ex;
    card.have=0;
    ex.player=player;
    ex.card[0]=card;
    return ex;
}
struct exchange_info draw_card(player_info player,card_info card1,card_info card2,card_info card3,card_info card4,int n)
{
    printf("Player %d draws: %s %s",player.no,card1.kind,card1.rank);
    if (n>=2) printf(", %s %s",card2.kind,card2.rank);
    if (n>=3) printf(", %s %s",card3.kind,card3.rank);
    if (n>=4) printf(", %s %s",card4.kind,card4.rank);
    struct exchange_info ex;
    card1.have=player.no;card1.to_have=false;
    card2.have=player.no;card2.to_have=false;
    card3.have=player.no;card3.to_have=false;
    card4.have=player.no;card4.to_have=false;
    ex.card[0]=card1;ex.card[1]=card2;ex.card[2]=card3;ex.card[3]=card4;ex.player=player;
    return ex;
}
options option_init()
{
    options temp={false,false,4,5,2,1};
    strcpy(temp.filename,"onecard.log");
    return temp;
}
options get_info(int argc,char *argv[])
{   
    int get_index; 
    int option_index=0;
    options input_option=option_init();
    struct option long_options[8]=
    {
        {"auto",0,NULL,'a'},{"help",0,NULL,'h'},{"log",1,NULL,'l'},
        {"player-number",1,NULL,'n'},{"initial-cards",1,NULL,'c'},
        {"decks",1,NULL,'d'},{"rounds",1,NULL,'r'},{0,0,0,0},
    };
    while((get_index=getopt_long(argc,argv,"ahn:c:d:r:",long_options,&option_index))!=-1) 
    {
        switch(get_index) 
        {
            case 'a':
                printf("auto mode\n");input_option.auto_run=true;break;
            case 'h':
                printf("help mode\n");input_option.help=true;break;
            case 'l':
                printf("file name=%s\n",optarg);strcpy(input_option.filename,optarg);break;
            case 'n': 
                input_option.n=atol(optarg);printf("number=%d\n",input_option.n);break;
            case 'c': 
                input_option.c=atol(optarg);printf("cards=%d\n",input_option.c);break;
            case 'd': 
                input_option.d=atol(optarg);printf("decks=%d\n",input_option.d);break;
            case 'r': 
                input_option.r=atol(optarg);printf("rounds=%d\n",input_option.r);break;
            default:
                printf("no such option \n");
        }
    }
    return input_option;
}