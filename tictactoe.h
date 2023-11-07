/************************************************************************/
/* Auteur : G. Quentin							*/
/* TP :  Morpion (Tic Tac Toe)	*/
/************************************************************************/

class TicTacToe{
    int T[3][3];	// Tableau destiné à représenter le jeu.
    public :
        TicTacToe(); // Constructeur de la partie initialisant le tableau à 0.
        void Affichage(); // Affichage du jeu.
        int jeuOrdi(int & bestMove); //contenant les instructions permettant d’évaluer les coups de l’ordinateur. Elle affecte à “bestMove” le meilleur coup de l’ordinateur, et renvoie la valeur de l’état du jeu correspondant à ce coup. Attention la méthode ne réalise pas le coup. La réalisation effective est faite en dehors de celle-ci.
        int jeuHumain(int & bestMove); //contenant les instructions permettant d’évaluer les coups de l’humain. Elle affecte à “bestMove” le meilleur coup de l’humain, et renvoie la valeur de l'état du jeu correspondant à ce coup
        int arbitre(); // méthode arbitrant l’état du jeu. Elle renvoie 1 si l’ordinateur a gagné, −1 si c est l’humain, 0 si le match est nul, et −2 si la partie n’est pas encore finie.
        bool play(int bestMove, bool joueur); // méthode permettant de réaliser le coup “bestMove” pour, si joueur = true, le joueur, et si joueur = 0 pour l'odinateur.
        void unplay(int bestMove); // méthode permettant d’annuler le coup “bestMove”.
        bool plein(); // méthode renvoyant true si le jeu est vide, false sinon.
};