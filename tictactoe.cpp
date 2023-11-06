#include "tictactoe.h"
#include <iostream>
using namespace std;

// Constructor
TicTacToe::TicTacToe(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            T[i][j]=0;
        }
    }
}

// afficher le jeu
void TicTacToe::Affichage(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<T[i][j]<<" ";
        }
        cout<<endl;
    }
}

// jeu de l'ordinateur
int TicTacToe::jeuOrdi(int & bestMove){
    int score = -2;
    int bestScore = -2;
    int bestI = -1;
    int bestJ = -1;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(T[i][j]==0){
                T[i][j]=1;
                score = arbitre();
                if(score>bestScore){
                    bestScore = score;
                    bestI = i;
                    bestJ = j;
                }
                T[i][j]=0;
            }
        }
    }
    bestMove = bestI*3+bestJ;
    return bestScore;
}

// jeu de l'humain
int TicTacToe::jeuHumain(int & bestMove){
    cout << "Entrez le numéro de la case que vous voulez jouer : ";
    cin >> bestMove;
    return this->preArbitre(bestMove, -1); // on retourne l'état du jeu après avoir joué
}

// arbitrer le jeu
int TicTacToe::arbitre(){
    int score = 0;
    for(int i=0;i<3;i++){
        if(T[i][0]==T[i][1] && T[i][1]==T[i][2]){
            if(T[i][0]==1){
                return 1;
            }else if(T[i][0]==-1){
                return -1;
            }
        }
    }
    for(int j=0;j<3;j++){
        if(T[0][j]==T[1][j] && T[1][j]==T[2][j]){
            if(T[0][j]==1){
                return 1;
            }else if(T[0][j]==-1){
                return -1;
            }
        }
    }
    if(T[0][0]==T[1][1] && T[1][1]==T[2][2]){
        if(T[0][0]==1){
            return 1;
        }else if(T[0][0]==-1){
            return -1;
        }
    }
    if(T[0][2]==T[1][1] && T[1][1]==T[2][0]){
        if(T[0][2]==1){
            return 1;
        }else if(T[0][2]==-1){
            return -1;
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(T[i][j]==0){
                score = -2;
            }
        }
    }
    return score;
}

// jouer
void TicTacToe::play(int bestMove, bool joueur){
    int i = bestMove/3;
    int j = bestMove%3;
    if(joueur){
        T[i][j]=-1;
    }else{
        T[i][j]=1;
    }
}