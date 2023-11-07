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
        cout << "C'est à l'ordinateur de jouer ! (symbole : X)" << endl;
        if (partie.arbitre() == -2) {
            partie.jeuOrdi(bestMove);
            partie.play(bestMove, false);
            partie.Affichage();
            piece = 1; // Passe au tour du joueur
        }
    } else {
        if (partie.arbitre() == -2) {
            cout << "C'est à vous de jouer ! (symbole : O)" << endl;
            cout << "Entrez le numero de la case que vous voulez jouer : ";
            cin >> move;
            while (!partie.play(move, true)){
                cout << "Entrez un numero de case valide : ";
                cin >> move;
            }
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