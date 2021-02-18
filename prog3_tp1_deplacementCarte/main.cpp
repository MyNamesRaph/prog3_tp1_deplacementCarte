#include "constantes.h"
#include "Point2D.h"
#include "Niveau.h"
#include <iostream>


int main()
{
    // Initialisation
    bool jouer{ true };

    int carte[constantes::dimension * constantes::dimension]
    {
        1,1,1,1,1,
        1,0,0,0,1,
        1,0,0,0,1,
        1,0,0,0,1,
        1,1,1,1,1
    };

    Niveau niveau(carte, "Gaston", { 2, 2 });

    // Boucle de jeu
    while (jouer)
    {
        // Affichage
        std::system("CLS");
        for (int i = 0; i < 5; ++i)
        {
            for (int j = 0; j < 5; ++j)
            {
                int index = j + i * constantes::dimension;
                if (niveau.getCarte()[index] == 1)
                {
                    std::cout << "#";
                }
                if (niveau.getCarte()[index] == 0)
                {
                    std::cout << " ";
                }
                if (niveau.getCarte()[index] == -1)
                {
                    std::cout << niveau.getNomCreature().front();
                }
            }
            std::cout << "\n";
        }
        std::cout << "Choisir une direction : \n";
        bool tabDeplacementsPossibles[4]{};
        niveau.getDeplacementPossible(tabDeplacementsPossibles);
        if (tabDeplacementsPossibles[0]) std::cout << "g \t gauche \n";
        if (tabDeplacementsPossibles[1]) std::cout << "d \t droite \n";
        if (tabDeplacementsPossibles[2]) std::cout << "h \t haut \n";
        if (tabDeplacementsPossibles[3]) std::cout << "b \t bas \n";
        std::cout << "q \t quitter \n";

        // Saisie
        char actionChoisie{ 'q' };
        std::cin >> actionChoisie;

        // Résolution du déplacement
        if (actionChoisie == 'g' && tabDeplacementsPossibles[0]) niveau.deplacerCreature(constantes::gauche);
        if (actionChoisie == 'd' && tabDeplacementsPossibles[1]) niveau.deplacerCreature(constantes::droite);
        if (actionChoisie == 'h' && tabDeplacementsPossibles[2]) niveau.deplacerCreature(constantes::haut);
        if (actionChoisie == 'b' && tabDeplacementsPossibles[3]) niveau.deplacerCreature(constantes::bas);
        if (actionChoisie == 'q') jouer = false;
    }

}
