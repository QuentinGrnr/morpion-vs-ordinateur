#include "tictactoe.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main () {

    TicTacToe partie;
    // Génération d'un nombre aléatoire entre 0 et 1
    srand(time(NULL));
    int piece = rand() % 2;
    int bestMove = 0;
    int move = 0;
    partie.Affichage();
    while (partie.arbitre() == -2) {
    if (piece == 0) {
        cout << "C'est à l'ordinateur de jouer !" << endl;
        partie.jeuOrdi(bestMove);
        cout << "L'ordinateur joue la case " << bestMove << endl;
        if (partie.arbitre() == -2) {
            partie.play(bestMove, false);
            partie.Affichage();
            piece = 1; // Passe au tour du joueur
        }
    } else {
        cout << "C'est à vous de jouer !" << endl;
        cout << "Entrez le numero de la case que vous voulez jouer : ";
        cin >> move;
        partie.play(move, true);
        if (partie.arbitre() == -2) {
            partie.play(bestMove, true);
            partie.Affichage();
            piece = 0; // Passe au tour de l'ordinateur
        }
    }
}

        if (partie.arbitre() == 1){
            cout << "L'ordinateur a gagné !" << endl;
            partie.Affichage();
        } else if (partie.arbitre() == -1) {
            cout << "Vous avez gagné !" << endl;
            partie.Affichage();
        } else if (partie.arbitre() == 0) {
            cout << "Match nul !" << endl;
            partie.Affichage();
        }
    return 0;
}