#include <stdio.h>
#include "chess.h"
#include <math.h>
#include <string.h>
#include <ctype.h>

char board[64]=
{'r','k','b','a','q','b','k','r',
 'p','p','p','p','p','p','p','p',
 '0','0','0','0','0','0','0','0',
 '0','0','0','0','0','0','0','0',
 '0','0','0','0','0','0','0','0',
 '0','0','0','0','0','0','0','0',
 'P','P','P','P','P','P','P','P',
 'R','K','B','A','Q','B','K','R'
 
};





int main()
{
    
 
 
 char c;
 int source;
 int destination;
 int s;
 int d;
 int i=0;
 
 printf("Welcome to Chess Game\nYou should enter the position of a piece as a number \nex:for a8->1, c8->3, b7->10, e2->53\n");
 printf("You should first enter the position of the piece you want to move then the position in which you want to move it \n");
 printf("Sample entry to move a piece from d5 to e5 is: 36 37 // from e6 to d5: 45 36\n");
 printf("Pieces are represented as letters, upercase for white and lowercase for black\n");
 printf("P:Prawn\nR:Rook\nK:Knight\nB:Bishop\nA:King\nQ:Queen\n");
 printBoard(board);

int a;
while(1){
    
 if(i%2==0) 
 printf("White's Turn:\n");
 else
 printf("Black's Turn:\n");
 printf("Enter your move\n");
 scanf("%d %d",&source,&destination);
 s=source-1;
 d=destination-1;
 
 if(islower(board[s] && i%2==1))
 printf("It's white's turn");
 
 a= move(board,s,d);
 printBoard(board);
 if(a==1)
 i++;
 if(a==2)
 {
    if(i%2==0)
    printf("White wins\n");
    else
    printf("Black wins\n");
    break;
 
 }
 

   
}
}