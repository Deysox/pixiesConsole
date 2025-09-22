//
// Created by barnab on 21/09/2025.
//

#ifndef PIXIES_GRILLE_H
#define PIXIES_GRILLE_H

#include <string>
#include "carte.h"
using namespace std;

class Grille {
    Carte** grille;
    bool complet;
    Carte* findCarte(int n) const;
    string findDisplay(int n) const;
public:
    Grille() : complet(false) { grille = new Carte*[9]; };
    Carte* getCarte(int n) const;
    void setCarte(int n, Carte* card);
    bool emplacementEstValide(int emp) const;
    bool emplacementEstVide(int emp) const;
    bool grillePleine() const;
    bool placerCarteVisible(Carte* carte, bool remplacer);
    bool placerCarteCache(Carte* carte, int emp);
    void afficher();
    int score(int manche);
    int zone(int depart, int* tab, Couleur col);
};



#endif //PIXIES_GRILLE_H