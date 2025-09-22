#include <string>
#include "grille.h"

#include <iostream>
#include <map>
using namespace std;

// Grille
Carte* Grille::findCarte(int n) const {
    if (n < 1 || n > 9)
        throw;
    return *(grille+n-1);
}

Carte *Grille::getCarte(int n) const {
    return findCarte(n);
}

void Grille::setCarte(int n, Carte* card) {
    if (n < 1 || n > 9)
        throw;
    *(grille+n-1) = card;
}

bool Grille::emplacementEstValide(int emp) const {
    Carte* c = findCarte(emp);
    return c->getStatut() == Statut::valide;
}

bool Grille::emplacementEstVide(int emp) const {
    Carte* c = findCarte(emp);
    return c == nullptr;
}


bool Grille::grillePleine() const {
    for (auto i = 1; i < 10; i++) {
        if (findCarte(i) == nullptr) {
            return false;
        }
    }
    return true;
}

bool Grille::placerCarteVisible(Carte *carte, bool remplacer) {
    int emp = carte->getNombre();
    if (findCarte(emp) == nullptr) {
        setCarte(emp, carte);
        carte->setStatut(Statut::visible);
    } else {
        if (remplacer) {
            setCarte(emp, carte);
        }
        findCarte(emp)->setStatut(Statut::valide);
    }
    return grillePleine();
}

bool Grille::placerCarteCache(Carte *carte, int emp) {
    if (!emplacementEstVide(emp))
        throw;

    carte->setStatut(Statut::cache);
    setCarte(emp, carte);
    return grillePleine();
}

string Grille::findDisplay(int n) const {
    Carte* c = findCarte(n);
    if (c == nullptr) {
        return "     ";
    } else {
        return c->afficher();
    }
}


void Grille::afficher() {
    cout << findDisplay(1) << " " << findDisplay(2) << " " << findDisplay(3) << endl;
    cout << endl;
    cout << findDisplay(4) << " " << findDisplay(5) << " " << findDisplay(6) << endl;
    cout << endl;
    cout << findDisplay(7) << " " << findDisplay(8) << " " << findDisplay(9) << endl;
}

int Grille::score(int manche) {
    int zoneMax = 0;
    int validation = 0;
    int spirales = 0;
    map<Couleur, int> couleurs;

    for (auto i = 1; i < 10; i++)
        if (getCarte(i) != nullptr)
            couleurs[getCarte(i)->getCouleur()]++;


    for (auto i = 1; i < 10; i++) {
        Carte* elem = getCarte(i);
        if (elem != nullptr) {
            Couleur col = elem->getCouleur();
            if (elem->estValide())
                validation += elem->getNombre();

            if (elem->getSpirale().getScaling()) {
                spirales += (couleurs[col] + couleurs[Couleur::multicolore]);
            } else {
                spirales += elem->getSpirale().getValeur();
            }

            int z = 0;
            if (elem->getCouleur() == Couleur::multicolore) {
                int* tab1 = new int[9];
                int z1 = zone(i, tab1, Couleur::rouge);
                delete[] tab1;
                int* tab2 = new int[9];
                int z2 = zone(i, tab2, Couleur::bleu);
                delete[] tab2;
                int* tab3 = new int[9];
                int z3 = zone(i, tab3, Couleur::vert);
                delete[] tab3;
                int* tab4 = new int[9];
                int z4 = zone(i, tab4, Couleur::jaune);
                delete[] tab4;

                z = max(max(z1,z2),max(z3,z4));
            } else {
                int* tab = new int[9];
                z = zone(i, tab, elem->getCouleur());
                delete[] tab;
            }

            if (z >= 2 && z > zoneMax)
                zoneMax = z;
        }
    }

    return validation + spirales + zoneMax*(manche+1);
}

int Grille::zone(int depart, int* tab, Couleur col) {
    int addition = 0;
    *(tab+depart-1) = 1;
    if (depart%3 != 1 && getCarte(depart-1) != nullptr && *(tab+depart-1-1) == 0 && memeCouleur(col,getCarte(depart-1)->getCouleur())) {
        addition += zone(depart-1, tab, col);
    }
    if (depart%3 != 0 && getCarte(depart+1) != nullptr && *(tab+depart) == 0 && memeCouleur(col,getCarte(depart+1)->getCouleur())) {
        addition += zone(depart+1, tab, col);
    }
    if (depart > 3 && getCarte(depart-3) != nullptr && *(tab+depart-4) == 0 && memeCouleur(col,getCarte(depart-3)->getCouleur())) {
        addition += zone(depart-3, tab, col);
    }
    if (depart < 6 && getCarte(depart+3) != nullptr && *(tab+depart+2) == 0 && memeCouleur(col,getCarte(depart+3)->getCouleur())) {
        addition += zone(depart+3, tab, col);
    }
    return 1 + addition;
}







