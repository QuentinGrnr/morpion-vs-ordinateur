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
            if (T[i][j]==0){
                cout<<"- ";
            }else if (T[i][j]==1){
                cout<<"X ";
            }else{
                cout<<"O ";
            }
        }
        cout<<endl;
    }
    cout<<endl;
}

// jeu de l'ordinateur
int TicTacToe::jeuOrdi(int & bestMove){
    int arg;
    if (this->plein()){ // si la partie est finie
        return 0; 
    }
    if (this->arbitre()== 1){ // si l'ordinateur a gagné
        return 1;
    }
    int val = -1;
    for (int i=0;i<9;i++){
        if (T[i/3][i%3]==0){
            play(i, false);
            int res = this->jeuHumain(arg);
            unplay(i);
            if (res > val){
                val = res;
                bestMove = i;
            }
        }
    }
    return val;
}

// jeu de l'humain
int TicTacToe::jeuHumain(int & bestMove){
    int arg = 0;
    if (this->plein()){ // si la partie est finie
        return 0; 
    }
    if (this->arbitre()== -1){ // si l'humain a gagné
        return -1;
    }
    int val = 1;
    int res;
    for (int i=0;i<9;i++){
        if (T[i/3][i%3]==0){
            play(i, true);
            res = this->jeuOrdi(arg);
            unplay(i);
            if (res < val){
                val = res;
                bestMove = i;
            }
        }
    }
    return val;
}

// arbitrer le jeu
int TicTacToe::arbitre(){
    int score = 0;
    for(int i=0;i<3;i++){ // vérifier les lignes
        if(T[i][0]==T[i][1] && T[i][1]==T[i][2]){
            if(T[i][0]==1){
                return 1;
            }else if(T[i][0]==-1){
                return -1;
            }
        }
    }
    for(int j=0;j<3;j++){ // vérifier les colonnes
        if(T[0][j]==T[1][j] && T[1][j]==T[2][j]){
            if(T[0][j]==1){
                return 1;
            }else if(T[0][j]==-1){
                return -1;
            }
        }
    }
    if(T[0][0]==T[1][1] && T[1][1]==T[2][2]){ // vérifier les diagonales
        if(T[0][0]==1){
            return 1;
        }else if(T[0][0]==-1){
            return -1;
        }
    }
    if(T[0][2]==T[1][1] && T[1][1]==T[2][0]){ // vérifier les diagonales
        if(T[0][2]==1){
            return 1;
        }else if(T[0][2]==-1){
            return -1;
        }
    }
    for(int i=0;i<3;i++){ // vérifier si la partie est finie
        for(int j=0;j<3;j++){
            if(T[i][j]==0){
                score = -2;
            }
        }
    }
    return score;
}

// jouer
bool TicTacToe::play(int bestMove, bool joueur){
    int i = bestMove/3;
    int j = bestMove%3;
    if (T[i][j] == 0 && i<3 && j<3){
        if(joueur){
            T[i][j]=-1;
        }else{
            T[i][j]=1;
        }
        return true;
    }
    return false;
}

// annuler le coup
void TicTacToe::unplay(int bestMove){
    int i = bestMove/3;
    int j = bestMove%3;
    T[i][j]=0;
}

bool TicTacToe::plein(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(T[i][j]==0){
                return false;
            }
        }
    }
    return true;
}