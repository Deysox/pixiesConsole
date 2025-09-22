//
// Created by barnab on 22/09/2025.
//

#include <string>
#include "joueur.h"

string Joueur::getNom() const {
    return nom;
}

int Joueur::getScore() const {
    return score;
}

void Joueur::setNom(string n) {
    nom = n;
}

void Joueur::setScore(int s) {
    if (score < 0)
        throw;
    score = s;
}



