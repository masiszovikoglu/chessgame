#include <stdio.h>
#include "chess.h"
#include <stdlib.h>

void impossible()
{
    printf("!! IMPOSSİBLE MOVE !!\n");
}
/*----------------------------------------------------------------------------*/



void printBoard(char *board)
{
    int i,j;
    for(j=0;j<8;j++){
        printf("%d", 8-j);
    for(i=0;i<8;i++)
    {
        printf("| %c ",board[8*j+i]);
    }
    printf("|\n |---|---|---|---|---|---|---|---|\n");
    }
    printf("   a   b   c   d   e   f   g   h");
    printf("\n\n\n");
    
}

int move(char *board,int i,int f)
{
    /* resrtrictions for pawn */
    if((board[i]=='p'||board[i]=='P') && (i-f)%8!=0)
    {
    impossible();
    printf("pawn can only move straight\n");
    return 0;    
    }
    
    if(((board[i]=='p'||board[i]=='P') && (i-f)%8==0) && board[f]!='0')
    {
    impossible();
    printf("pawn can not capture a piece by moving straigh\n");
    return 0;    
    }
    
    if(((board[i]=='p'||board[i]=='P') && (!((i-1)/8)==6||((i-1)/8)==1)) && abs(i-f)>8)
    {
        impossible();
        printf("pawn can not move more than 1 square unless on first move\n");
        return 0;
        
    }
    
    if((board[i]=='p'||board[i]=='P') && (i/8==6||i/8==1) ){
        if(abs(f-i)>16)
    
    {
        impossible();
        printf("pawn can not move more than 2 square on first move\n");
        return 0;
    }}
/*----------------------------------------------------------------------------*/

    /* restrictions for rook*/
    if((board[i]=='r'||board[i]=='R') && ((i-f)%8!=0 && i/8!=f/8))
    {
        impossible();
        printf("Rook can only move laterally and vertically\n");
        return 0;
    }
    
    if((board[i]=='r'||board[i]=='R'))
    {
        if((i==0&&board[8]!='0')||(i==7&&board[15]!='0')||(i==56&&board[48]!='0')||((i==63)&&(board[55]!='0')))
        {
            impossible();
            printf("Rook can not jump over a piece\n");
            return 0;
        }
        
    }
/*----------------------------------------------------------------------------*/    
    
    /* resrtrictions for bishop*/
    if(!((board[i]=='b'||board[i]=='B') && ((i-f)%7==0)) ||((board[i]=='b'||board[i]=='B')&& ((i-f)%9==0))) 
    {
        impossible();
        printf("Bishop can only move in cross direction\n");
        return 0;
    }
    
    if(!(board[i]=='b'||board[i]=='B'))
    {
        if((i==2&&board[9]!='0')||(i==2&&board[11]!='0')||(i==5&&board[12]!='0')||(i==5&&board[14]!='0')||(i==58&&board[49]!='0')||(i==58&&board[51]!='0')||(i==61&&board[52]!='0')||(i==61&&board[54]!='0'))
        {
            impossible();
            printf("Bishop can not jump  over a piece\n");
            return 0;
        }
    }
    
/*----------------------------------------------------------------------------*/    
    
    /* resrtrictions for Knight*/
    if(((board[i]=='k'||board[i]=='K') && (!(abs(i-f)==17||abs(i-f)==15||abs(i-f)==10||abs(i-f)==4||abs(i-f)==6))))
    {
        impossible();
        printf("Knight can only move in shape of L\n");
        return 0;
    }
/*----------------------------------------------------------------------------*/


    /* restrictions for king */
    if((board[i]=='a'||board[i]=='A') && (!(abs(i-f)==1||abs(i-f)==7||abs(i-f)==8||abs(i-f)==9)))
    {
        impossible();
        printf("King can only move by 1 square\n");
        return 0;
    }
    
    if(board[i]=='a'||board[i]=='A'){
        
        if(board[f+1]=='R'||board[f+1]=='r'||board[f-1]=='r'||board[f-1]=='R'||board[f-8]=='R'||board[f-8]=='r'||board[f+8]=='R'||board[f+8]=='r')
        {
            impossible();
            printf("King can not move near a Rook\n");
            return 0;
        }
        
        
    }
/*----------------------------------------------------------------------------*/


    if(board[f]!='0')
    printf("%c takes %c\n", board[i],board[f]);
    if(board[f]=='a'||board[f]=='A')
    {
        printf("!! CHECKMATE!!!\n");
        return 2;
    }
    board[f]=board[i];
    board[i]='0';
    return 1;
    
    
}