#include <iostream>
#include<stdlib.h>
using namespace std;
char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char turn ='X';
int r,c,ch;
bool draw = false;
bool gameover();
void display_board();
void player_turn();
int main()
{
    while(!gameover()){
        display_board();
        player_turn();
        gameover();
    }
}
void display_board()
{
    system("cls");
   cout<<"\n\n  T i c k   C r o s s   G a m e   \n\n";
   cout<<"\t Player1[X] \n\t Player2[0]\n"<<endl;
   cout<<"\t\t   |   |   "<<endl;
   cout<<"\t\t "<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<endl;
   cout<<"\t\t___|___|___"<<endl;
   cout<<"\t\t   |   |   "<<endl;
   cout<<"\t\t "<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<endl;
   cout<<"\t\t___|___|___"<<endl;
   cout<<"\t\t   |   |   "<<endl;
   cout<<"\t\t "<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<endl;
   cout<<"\t\t   |   |   "<<endl;
}
void player_turn()
{
    if(turn=='X'){
        cout<<"Player [X] TURN:"<<endl;
    }else{
        cout<<"Player [0] TURN:"<<endl;
    }
    cin>>ch;
    switch(ch)
    {
    case 1: r=0,c=0;break;
    case 2: r=0,c=1;break;
    case 3: r=0,c=2;break;
    case 4: r=1,c=0;break;
    case 5: r=1,c=1;break;
    case 6: r=1,c=2;break;
    case 7: r=2,c=0;break;
    case 8: r=2,c=1;break;
    case 9: r=2,c=2;break;
    default: cout<<"Invialed input!!"<<endl;
    }
    if(turn=='X')
    {
        board[r][c]='X';
        turn='0';
    }else{
        board[r][c]='0';
        turn='X';
    }
    display_board();
}
bool gameover()
{
    int a=0;
    for(int i=0;i<3;i++)
    {
        if(((board[i][0]==board[i][1])&&(board[i][0]==board[i][2]))||((board[0][i]==board[1][i])&&(board[0][i]==board[2][i]))||((board[0][0]==board[1][1])&&(board[0][0]==board[2][2]))||((board[2][0]==board[1][1])&&(board[2][0]==board[0][2])))
        {
            if(turn=='X'){
                cout<<"\n\t\tPlayer[0] is WON"<<endl;
            }else{
                cout<<"\n\t\tPlayer[X] is WON"<<endl;
            }
            exit(0);
        }else{
            for(int j=0;j<3;j++)
            {
                if((board[i][j]=='X')||(board[i][j]=='0')){
                    a++;
                }
                if(a==9){
                    cout<<"Game is DRAW!"<<endl;
                    exit(0);
                }
            }
        }
    }
return false;
}
