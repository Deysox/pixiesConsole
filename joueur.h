//
// Created by barnab on 22/09/2025.
//

#ifndef PIXIES_JOUEUR_H
#define PIXIES_JOUEUR_H

#include "grille.h"
#include <string>

class Joueur {
    string nom;
    Grille* plateau;
    int score;
public:
    Joueur(string n, int s) : nom(n), score(s) { plateau = new Grille; if (score < 0) throw; }
    Joueur(string n) : nom(n), score(0) { plateau = new Grille; }
    Joueur(int s) : nom("Player"), score(s) { plateau = new Grille; if (score < 0) throw; }
    Joueur() : nom("Player"), score(0) { plateau = new Grille; }
    int getScore() const;
    void setScore(int s);
    string getNom() const;
    void setNom(string n);
};

#endif //PIXIES_JOUEUR_H