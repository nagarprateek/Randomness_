// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include<cstdlib>

int t=0;

//vector<int> v;

struct Move 
{ 
    int row, col; 
};


using namespace std;

Move Getter(char board[3][3]){
    Move bestMove; 
    bestMove.row = -1; 
    bestMove.col = -1;
    
    if(board[0][0]==board[0][1] && board[0][0]=='0' && board[0][2]=='_'){
        bestMove.row = 0; 
        bestMove.col = 2;
    }
    else if(board[0][0]==board[0][2] && board[0][0]=='0' && board[0][1]=='_'){
        bestMove.row = 0; 
        bestMove.col = 1;
    }
    else if(board[0][1]==board[0][2] && board[0][0]=='0' && board[0][0]=='_'){
        bestMove.row = 0; 
        bestMove.col = 0;
    }
    else if(board[1][0]==board[1][1] && board[1][0]=='0' && board[1][2]=='_'){
        bestMove.row = 1; 
        bestMove.col = 2;
    }
    
    else if(board[1][0]==board[1][2] && board[1][0]=='0' && board[1][1]=='_'){
        bestMove.row = 1; 
        bestMove.col = 1;
    }
    else if(board[1][1]==board[1][2] && board[1][1]=='0' && board[1][0]=='_'){
        bestMove.row = 1; 
        bestMove.col = 0;
    }
    else if(board[2][0]==board[2][1] && board[2][0]=='0' && board[2][2]=='_'){
        bestMove.row = 2; 
        bestMove.col = 2;
    }
    else if(board[2][0]==board[2][2] && board[2][0]=='0' && board[2][1]=='_'){
        bestMove.row = 2; 
        bestMove.col = 1;
    }
    else if(board[2][1]==board[2][2] && board[2][1]=='0' && board[2][0]=='_'){
        bestMove.row = 2; 
        bestMove.col = 0;
    }
    else if(board[0][0]==board[1][1] && board[0][0]=='0' && board[2][2]=='_'){
        bestMove.row = 2; 
        bestMove.col = 2;
    }
    else if(board[0][0]==board[2][2] && board[0][0]=='0' && board[1][1]=='_'){
        bestMove.row = 1; 
        bestMove.col = 1;
    }
    else if(board[1][1]==board[2][2] && board[1][1]=='0' && board[0][0]=='_'){
        bestMove.row = 0; 
        bestMove.col = 0;
    }
    else if(board[1][1]==board[0][2] && board[1][1]=='0' && board[2][0]=='_'){
        bestMove.row = 2; 
        bestMove.col = 0;
    }
    else if(board[0][2]==board[2][0] && board[2][0]=='0' && board[1][1]=='_'){
        bestMove.row = 1; 
        bestMove.col = 1;
    }
    else if(board[2][0]==board[1][1] && board[1][1]=='0' && board[0][2]=='_'){
        bestMove.row = 0; 
        bestMove.col = 2;
    }
    
    return bestMove;
  
    
    
}


Move Obstacle(char board[3][3]){
    Move bestMove; 
    bestMove.row = -1; 
    bestMove.col = -1;
    
    if(board[0][0]==board[0][1] && board[0][0]=='X' && board[0][2]=='_'){
        bestMove.row = 0; 
        bestMove.col = 2;
    }
    else if(board[0][0]==board[0][2] && board[0][0]=='X' && board[0][1]=='_'){
        bestMove.row = 0; 
        bestMove.col = 1;
    }
    else if(board[0][1]==board[0][2] && board[0][0]=='X' && board[0][0]=='_'){
        bestMove.row = 0; 
        bestMove.col = 0;
    }
    else if(board[1][0]==board[1][1] && board[1][0]=='X' && board[1][2]=='_'){
        bestMove.row = 1; 
        bestMove.col = 2;
    }
    
    else if(board[1][0]==board[1][2] && board[1][0]=='X' && board[1][1]=='_'){
        bestMove.row = 1; 
        bestMove.col = 1;
    }
    else if(board[1][1]==board[1][2] && board[1][1]=='X' && board[1][0]=='_'){
        bestMove.row = 1; 
        bestMove.col = 0;
    }
    else if(board[2][0]==board[2][1] && board[2][0]=='X' && board[2][2]=='_'){
        bestMove.row = 2; 
        bestMove.col = 2;
    }
    else if(board[2][0]==board[2][2] && board[2][0]=='X' && board[2][1]=='_'){
        bestMove.row = 2; 
        bestMove.col = 1;
    }
    else if(board[2][1]==board[2][2] && board[2][1]=='X' && board[2][0]=='_'){
        bestMove.row = 2; 
        bestMove.col = 0;
    }
    else if(board[0][0]==board[1][1] && board[0][0]=='X' && board[2][2]=='_'){
        bestMove.row = 2; 
        bestMove.col = 2;
    }
    else if(board[0][0]==board[2][2] && board[0][0]=='X' && board[1][1]=='_'){
        bestMove.row = 1; 
        bestMove.col = 1;
    }
    else if(board[1][1]==board[2][2] && board[1][1]=='X' && board[0][0]=='_'){
        bestMove.row = 0; 
        bestMove.col = 0;
    }
    else if(board[1][1]==board[0][2] && board[1][1]=='X' && board[2][0]=='_'){
        bestMove.row = 2; 
        bestMove.col = 0;
    }
    else if(board[0][2]==board[2][0] && board[2][0]=='X' && board[1][1]=='_'){
        bestMove.row = 1; 
        bestMove.col = 1;
    }
    else if(board[2][0]==board[1][1] && board[1][1]=='X' && board[0][2]=='_'){
        bestMove.row = 0; 
        bestMove.col = 2;
    }
    
    return bestMove;
  
    
    
}

Move findBestMove(char board[3][3]){
    Move bestMove; 
    bestMove.row = -1; 
    bestMove.col = -1;
    
    if(t==0){
        do{
            bestMove.row=(rand()%3)+1;
            bestMove.col=(rand()%3)+1;
        }while(board[bestMove.row][bestMove.col]=='X');
        t++;
    }
    
    else{
        bestMove=Obstacle(board);
        if(bestMove.row!=-1 || bestMove.col!=-1){
            return bestMove;
        }
        else{
            bestMove=Getter(board);
            if(bestMove.row!=-1 || bestMove.col!=-1){
            return bestMove;
        }
        else{
            do{
            bestMove.row=(rand()%3)+1;
            bestMove.col=(rand()%3)+1;
        }while(board[bestMove.row][bestMove.col]!='_');
        
        }
        }
        
        
        
        
    }
    return bestMove;
    
}



int iswon(char board[3][3]){
    if(board[0][0]==board[0][1] && board[0][0]==board[0][2] && board[0][0]!='_'){
        return 1;
    }
    else if(board[1][0]==board[1][1] && board[1][0]==board[1][2]  && board[1][0]!='_'){
        return 1;
    }
    else if(board[2][0]==board[2][1] && board[2][0]==board[2][2]  && board[2][0]!='_'){
        return 1;
    }
    else if(board[0][0]==board[1][0] && board[0][0]==board[2][0]  && board[0][0]!='_'){
        return 1;
    }
    else if(board[0][1]==board[1][1] && board[0][1]==board[2][1]  && board[0][1]!='_'){
        return 1;
    }
   else if(board[0][2]==board[1][2] && board[0][2]==board[2][2]  && board[0][2]!='_'){
        return 1;
    }
    else if(board[0][0]==board[1][1] && board[0][0]==board[2][2]  && board[0][0]!='_'){
        return 1;
    }
    else if(board[0][2]==board[1][1] && board[2][0]==board[1][1]  && board[0][2]!='_'){
        return 1;
    }
    
    else{
        return 0;
    }
}

int main() {
    int i,j,r,c,n=0;
    char board[3][3] = 
    { 
        { '_', '_', '_' }, 
        { '_', '_', '_' }, 
        { '_', '_', '_' } 
    }; 
    
    while(1){
        if(n==0){
            cout << "Your turn: ";
            cin >> r >> c;
            board[r-1][c-1]='X';
            for(i=0;i<3;i++){
                for(j=0;j<3;j++){
                    cout << board[i][j];
                }
                cout << endl;
            }
            cout << "-----------------" << endl;
            if(iswon(board)==1){
                cout << "You won" << endl;
                break;
            }
            else{
                n=1;
            }
            
        }
        else{
            cout << "Computer turn" << endl;
            
            Move bestMove = findBestMove(board);
            board[bestMove.row][bestMove.col]='0';
            
            for(i=0;i<3;i++){
                for(j=0;j<3;j++){
                    cout << board[i][j];
                }
                cout << endl;
            }
            
            cout << "-----------------" << endl;
            
            if(iswon(board)==1){
                cout << "Computer won" << endl;
                break;
            }
            else{
                n=0;
            }
        }
    }

    return 0;
}